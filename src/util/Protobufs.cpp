#include "Protobufs.hpp"
#include "StrToHex.hpp"

namespace YimMenu
{
#pragma pack(push, 1)
	struct pb_element
	{
		std::uint32_t field_idx; // 0
		std::uint8_t field_type; // 4
		std::uint8_t unk_0;      // 5
		char pad[0x12];          // 6
		pb_element* sub_structure;
		const char* debug_name;
		void* unk_1;
		void* unk_2;
		void* unk_3;
	};
	static_assert(sizeof(pb_element) == 0x40);
#pragma pack(pop)

	enum class FieldType
	{
		BOOL               = 0,
		VARINT             = 1,
		UVARINT            = 2,
		SVARINT            = 3,
		FIXED32            = 4,
		FIXED64            = 5,
		BYTES              = 6,
		STRING             = 7,
		SUBMESSAGE         = 8,
		SUBMESSAGE_W_CB    = 9,
		EXTENSION          = 10,
		FIXED_LENGTH_BYTES = 11,
		INVALID            = -1
	};

	enum class TagType
	{
		VARINT = 0,
		I64 = 1,
		LEN = 2,
		SGROUP = 3,
		EGROUP = 4,
		I32 = 5
	};

	// reader only for now
	class ProtobufStream
	{
		std::uint8_t* m_Data;
		std::size_t m_Size;
		std::size_t m_Position;

	public:
		ProtobufStream(void* data, std::size_t size) :
		    m_Data(reinterpret_cast<std::uint8_t*>(data)),
		    m_Size(size),
		    m_Position(0)
		{
		}

		bool IsEof() const
		{
			return m_Position >= m_Size;
		}

		std::uint8_t ReadByte()
		{
			if (IsEof())
				return 0;

			return m_Data[m_Position++];
		}

		std::uint64_t ReadVarInt()
		{
			std::uint8_t byte;
			std::uint_fast8_t bitpos = 0;
			std::uint64_t result     = 0;

			do
			{
				if (bitpos >= 64)
					return 0;

				byte = ReadByte();

				result |= (std::uint64_t)(byte & 0x7F) << bitpos;
				bitpos = (std::uint_fast8_t)(bitpos + 7);
			} while (byte & 0x80);

			return result;
		}

		std::uint64_t ReadUInt64()
		{
			if (IsEof())
				return 0;

			auto res = *reinterpret_cast<std::uint64_t*>(&m_Data[m_Position]);
			m_Position += 8;
			return res;
		}

		std::uint64_t ReadUInt32()
		{
			if (IsEof())
				return 0;

			auto res = *reinterpret_cast<std::uint32_t*>(&m_Data[m_Position]);
			m_Position += 4;
			return res;
		}

		ProtobufStream ExtractSubMessage(std::size_t size)
		{
			ProtobufStream stream(&m_Data[m_Position], size);
			m_Position += size;
			return stream;
		}

		std::string ReadString(std::size_t len)
		{
			if (IsEof())
				return "";

			std::string str(reinterpret_cast<char*>(&m_Data[m_Position]), len);
			m_Position += len;
			return str;
		}

		std::vector<std::uint8_t> ReadBytes(std::size_t len)
		{
			if (IsEof())
				return {};

			std::vector<std::uint8_t> out;
			out.reserve(len);

			for (int i = 0; i < len; i++)
				out.push_back(ReadByte());

			return out;
		}

		void Seek(int len)
		{
			m_Position += len;
		}
	};

	class ProtobufStructure
	{
		pb_element* m_Fields;

		pb_element* GetFieldAtIndex(int idx)
		{
			if (m_Fields == nullptr)
				return nullptr;

			for (auto cur = m_Fields; cur->field_idx != 0; cur++)
			{
				if (cur->field_idx == idx)
					return cur;
			}

			return nullptr;
		}

	public:
		ProtobufStructure(pb_element* fields) :
		    m_Fields(fields)
		{
		}

		bool HasField(int index)
		{
			return GetFieldAtIndex(index) != nullptr;
		}

		FieldType GetFieldType(int index)
		{
			auto field = GetFieldAtIndex(index);

			if (!field)
				return FieldType::INVALID;

			return FieldType(field->field_type & 0x0F);
		}

		std::string GetFieldName(int index)
		{
			auto field = GetFieldAtIndex(index);

			if (!field)
				return "invalid_" + std::to_string(index);

			if (!field->debug_name || !*field->debug_name)
				return "field_" + std::to_string(index);

			return field->debug_name;
		}

		ProtobufStructure GetSubField(int index)
		{
			auto field = GetFieldAtIndex(index);

			if (!field)
				return nullptr;

			return field->sub_structure;
		}
	};

	static std::int64_t ConvertSignedInteger(std::uint64_t i)
	{
		if (i & 1)
			return ~(i >> 1);
		else
			return i >> 1;
	}

	static float TransmuteToFloat(std::uint64_t i)
	{
		int value = i;
		return *(float*)&value;
	}

	static int GetFieldNumber(std::uint64_t tag)
	{
		return tag >> 3;
	}

	static TagType GetTagType(std::uint64_t tag)
	{
		return TagType(tag & 0b111);
	}

	static void PrintMessage(std::string msg, int indent_level)
	{
		std::ostringstream tabs;
		for (int i = 0; i < indent_level; i++)
			tabs << '\t';

		LOG(VERBOSE) << tabs.str() << msg;
	}

	static inline void PrintIntegerValue(ProtobufStructure structure, int field, std::uint64_t value, int indent_level)
	{
		if (!structure.HasField(field))
		{
			PrintMessage(std::format("{} (no entry): {} (signed={}) (0x{:X})", structure.GetFieldName(field), value, ConvertSignedInteger(value), value), indent_level);
			return;
		}

		auto type = structure.GetFieldType(field);

		switch (type)
		{
		case FieldType::BOOL:
			PrintMessage(std::format("{}: {}", structure.GetFieldName(field), value ? "TRUE" : "FALSE"), indent_level);
			return;
		case FieldType::FIXED32:
			// very likely a float
			PrintMessage(std::format("{}: {}", structure.GetFieldName(field), TransmuteToFloat(value)), indent_level);
			return;
		case FieldType::FIXED64:
			// Rockstar doesn't use doubles so likely an uint64
			PrintMessage(std::format("{}: {} (0x{:X})", structure.GetFieldName(field), value, value), indent_level);
			return;
		case FieldType::SVARINT:
			// signed varint (zigzag encoding)
			PrintMessage(std::format("{}: {}", structure.GetFieldName(field), ConvertSignedInteger(value)), indent_level);
			return;
		case FieldType::UVARINT:
			if (value > 2000)
				PrintMessage(std::format("{}: {} (0x{:X})", structure.GetFieldName(field), value, value), indent_level);
			else
				PrintMessage(std::format("{}: {}", structure.GetFieldName(field), value, value), indent_level);
			return;
		case FieldType::VARINT:
			// signed varint (normal encoding)
			PrintMessage(std::format("{}: {}", structure.GetFieldName(field), static_cast<std::int64_t>(value)), indent_level);
			return;
		default:
			PrintMessage(std::format("{} (unk type {}): {} (signed={}) (0x{:X})", structure.GetFieldName(field), static_cast<int>(type), value, ConvertSignedInteger(value), value), indent_level);
			return;
		}
	}

	static void PrintBufferInternal(ProtobufStructure structure, ProtobufStream stream, int indent_level = 0)
	{
		while (!stream.IsEof())
		{
			auto tag = stream.ReadVarInt();

			if (!tag)
			{
				PrintMessage("error: empty tag", indent_level);
				break;
			}

			auto field = GetFieldNumber(tag);
			auto type  = GetTagType(tag);

			switch (type)
			{
			case TagType::VARINT:
			{
				auto ival = stream.ReadVarInt();
				PrintIntegerValue(structure, field, ival, indent_level);
				break;
			}
			case TagType::I64:
			{
				auto ival = stream.ReadUInt64();
				PrintIntegerValue(structure, field, ival, indent_level);
				break;
			}
			case TagType::LEN:
			{
				auto len = stream.ReadVarInt();

				if (!structure.HasField(field))
				{
					PrintMessage(std::format("{} (no entry): LEN field of size {}", structure.GetFieldName(field), len), indent_level);
					stream.Seek(len);
					// can't handle this
					break;
				}

				auto f_type = structure.GetFieldType(field);
				switch (f_type)
				{
				case FieldType::STRING:
				{
					PrintMessage(std::format("{}: \"{}\"", structure.GetFieldName(field), stream.ReadString(len)), indent_level);
					break;
				}
				case FieldType::BYTES:
				case FieldType::FIXED_LENGTH_BYTES:
				{
					auto bytes = stream.ReadBytes(len);
					PrintMessage(std::format("{}: b\"{}\"", structure.GetFieldName(field), BytesToHexStr(bytes.data(), bytes.size())), indent_level);
					break;
				}
				case FieldType::SUBMESSAGE:
				case FieldType::SUBMESSAGE_W_CB:
				{
					PrintMessage(std::format("{}:", structure.GetFieldName(field)), indent_level);
					PrintBufferInternal(structure.GetSubField(field), stream.ExtractSubMessage(len), indent_level + 1);
					break;
				}
				default:
				{
					PrintMessage(std::format("{} (unk type {}): LEN field of size {}", structure.GetFieldName(field), static_cast<int>(f_type), len), indent_level);
					stream.Seek(len);
					break;
				}
				}
				break;
			}
			case TagType::SGROUP:
			{
				PrintMessage("error: SGROUP tags are unsupported", indent_level);
				break;
			}
			case TagType::EGROUP:
			{
				PrintMessage("error: EGROUP tags are unsupported", indent_level);
				break;
			}
			case TagType::I32:
			{
				auto ival = stream.ReadUInt32();
				PrintIntegerValue(structure, field, ival, indent_level);
				break;
			}
			}
		}
	}

	void PrintProtoBuffer(void* buffer, int size, void* def)
	{
		ProtobufStructure structure(reinterpret_cast<pb_element*>(def));
		ProtobufStream stream(buffer, size);

		PrintBufferInternal(structure, stream);
	}
}