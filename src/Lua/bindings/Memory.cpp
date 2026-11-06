#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/memory/Pattern.hpp"
#include "core/memory/PatternScanner.hpp"
#include "core/memory/PointerCalculator.hpp"
#include "game/pointers/Pointers.hpp"
#include <util/Joaat.hpp>


namespace Terminus::LuaJIT
{
	class LuaMemLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	private:
		bool isnullptr(const PointerCalculator& ptr) const
		{
			return !static_cast<bool>(ptr);
		}

		void nullguard(sol::state& L, const PointerCalculator& ptr)
		{
			if (isnullptr(ptr))
				throw sol::error("Attempt to access a null pointer!");
		}

		PointerCalculator retnull()
		{
			return PointerCalculator(uintptr_t());
		}

		PointerCalculator deref(sol::state& L, const PointerCalculator& ptr)
		{
			nullguard(L, ptr);
			return PointerCalculator(*ptr.As<uintptr_t*>());
		}

		// https://github.com/YimMenu/YimMenuV2/blob/enhanced/src/core/scripting/libraries/Memory.cpp#L14
		class RuntimePattern : public IPattern
		{
			std::string m_Name;
			std::vector<std::optional<std::uint8_t>> m_Bytes;
			PatternHash m_Hash;

		public:
			~RuntimePattern() noexcept override
			{
			}

			RuntimePattern(std::string_view name, SimplePattern&& parsed) :
			    m_Name(name),
			    m_Bytes(std::move(parsed.m_Bytes))
			{
				for (const auto& b : m_Bytes)
					m_Hash = m_Hash.Update(b.has_value() ? static_cast<char>(*b) : '?');
				m_Hash = m_Hash.Update(m_Bytes.size());
			}

			const std::string_view Name() const override
			{
				return m_Name;
			}

			std::span<const std::optional<std::uint8_t>> Signature() const override
			{
				return m_Bytes;
			}

			const PatternHash Hash() const override
			{
				return m_Hash;
			}
		};

	public:
		void Register(sol::state& L) override
		{	
			/* @terminus.class BytePatch
			
			* method Apply Applies the patch bytes
			* 
			
			* method Restore Restores the patch bytes
			* 
			
			* method IsApplied
			* return boolean
			@*/
			L.new_usertype<BytePatch>("BytePatch", sol::no_constructor,
				//clang-format off
			    "Apply",     &BytePatch::Apply,
			    "Restore",   &BytePatch::Restore,
			    "IsApplied", [](BytePatch& self) { return static_cast<bool>(self); }
				//clang-format on
			);


			/* @terminus.class Pointer
			* description
				Provides memory read/write functions.

			* constructor __call
			* param address<integer>

			* operator add
			* param offset<integer>
			* return Pointer

			* operator sub
			* param offset<integer>
			* return Pointer

			* operator bnot
			* return Pointer

			* method Add
			* param offset<integer> The offset to add
			* return Pointer ptr A new pointer at the new address.

			* method Sub
			* param offset<integer> The offset to subtract.
			* return Pointer ptr A new pointer at the new address.

			* method Rip
			* return Pointer ptr A new pointer at the resolved RIP-relative address.

			* method Deref Returns a new pointer at the referenced address.
			* return Pointer ptr

			* method GetAddress
			* return integer address The pointer's memory address.

			* method IsNull
			* return boolean

			* method IsValid
			* return boolean
			
			* method ReadBytes Reads up to `n` number of bytes
			* param numOfBytes<integer> Number of bytes to read.
			* return table<integer,integer> byteArray An array of bytes

			* method ReadString
			* return string

			* method ReadInt Reads an integer
			* return integer int value

			* method ReadInt8 Reads a signed 8bit integer
			* return integer s8 value

			* method ReadUint8 Reads an unsigned 8bit integer
			* return integer u8 value

			* method ReadInt16 Reads a signed 16bit integer
			* return integer s16 value

			* method ReadUint16 Reads an unsigned 16bit integer
			* return integer u16 value

			* method ReadInt32 Reads a signed 32bit integer
			* return integer s32 value

			* method ReadUint32 Reads an unsigned 32bit integer
			* return integer u32 value

			* method ReadInt64 Reads a signed 64bit integer
			* return integer s64 value

			* method ReadUint64 Reads an unsigned 64bit integer
			* return integer u64 value

			* method ReadFloat Reads a float
			* return number

			* method WriteBytes
			* param byteArray<{[integer]: integer}> An array of bytes. This **MUST** be a contiguous int array, otherwise the method will thorw.

			* method WriteString
			* param str<string>

			* method WriteInt
			* param value<integer>

			* method WriteInt8
			* param s8<integer>
			
			* method WriteUint8
			* param u8<integer>

			* method WriteInt16
			* param s16<integer>

			* method WriteUint16
			* param u16<integer>

			* method WriteInt32
			* param s32<integer>

			* method WriteUint32
			* param u32<integer>

			* method WriteInt64
			* param s64<integer>

			* method WriteUint64
			* param u64<integer>

			* method WriteFloat
			* param v<number>
			
			* method AddBytePatch Adds a `BytePatch` object and returns it.
			* param byteArray<{ [integer]: integer }> An array of bytes. Example: `{ 0x90, 0x90, 0x90 }`. This **MUST** be a contiguous int array, otherwise the method will thorw.
			* return BytePatch? patch A `BytePatch` object or nil 
			@*/
			auto ptrUt = L.new_usertype<PointerCalculator>("Pointer",
				//clang-format off
			    sol::call_constructor, sol::constructors<PointerCalculator(uint64_t)>(),

				sol::meta_function::addition, [](const PointerCalculator& self, int offset) {
				    return self.Add(offset);
			    },

				sol::meta_function::subtraction, [](const PointerCalculator& self, int offset) {
				    return self.Sub(offset);
			    },

				sol::meta_function::equal_to, [](PointerCalculator& self, PointerCalculator& other) {
				    return self == other;
			    },

				sol::meta_function::to_string, [](PointerCalculator& self) {
				    return std::format("Pointer @ 0x{:X}", self.As<uintptr_t>());
			    },

			    "Rip", &PointerCalculator::Rip
			    //clang-format on
			);

			ptrUt["IsValid"] = [](const PointerCalculator& self) {
				return static_cast<bool>(self);
			};

			ptrUt["IsNull"] = [](const PointerCalculator& self) {
				return !static_cast<bool>(self);
			};

			ptrUt["GetAddress"] = [](const PointerCalculator& self) {
				return self.As<uintptr_t>();
			};

			ptrUt["SetAddress"] = [](const PointerCalculator& self, uintptr_t addr) {
				*self.As<uintptr_t*>() = addr;
			};

			ptrUt["Add"] = [](const PointerCalculator& self, int offset) {
				return self.Add(offset);
			};

			ptrUt["Sub"] = [&](const PointerCalculator& self, int offset) {
				nullguard(L, self);
				return self.Sub(offset);
			};

			ptrUt["Rip"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return self.Rip();
			};

			ptrUt["Deref"] = [&](const PointerCalculator& self) {
				return deref(L, self);
			};

			ptrUt["ReadInt"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<int*>();
			};

			ptrUt["ReadBytes"] = [&](const PointerCalculator& self, size_t count) {
				nullguard(L, self);

				std::vector<uint8_t> out(count);
				memcpy(out.data(), self.As<const void*>(), count);
				return out;
			};

			ptrUt["ReadInt8"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<int8_t*>();
			};

			ptrUt["ReadUint8"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<uint8_t*>();
			};

			ptrUt["ReadInt16"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<int16_t*>();
			};

			ptrUt["ReadUint16"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<uint16_t*>();
			};

			ptrUt["ReadInt32"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<int32_t*>();
			};

			ptrUt["ReadUint32"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<uint32_t*>();
			};

			ptrUt["ReadInt64"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<int64_t*>();
			};

			ptrUt["ReadUint64"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<uint64_t*>();
			};

			ptrUt["ReadFloat"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return *self.As<float*>();
			};

			ptrUt["ReadString"] = [&](const PointerCalculator& self) {
				nullguard(L, self);
				return std::string(self.As<char*>());
			};

			ptrUt["WriteBytes"] = [&](const PointerCalculator& self, sol::table t) {
				nullguard(L, self);

				std::vector<uint8_t> bytes;
				for (auto&& [_, v] : t)
				{
					if (!v.is<int>())
						throw sol::error("Invalid table value!");

					const int value = v.as<int>();
					if (value < 0 || value > 255)
						throw sol::error("Byte value out of range!");

					bytes.push_back(static_cast<uint8_t>(value));
				}

				if (!bytes.empty())
					memcpy(self.As<void*>(), bytes.data(), bytes.size());
			};

			ptrUt["WriteInt"] = [&](const PointerCalculator& self, int arg) {
				nullguard(L, self);
				*self.As<int*>() = arg;
			};

			ptrUt["WriteInt8"] = [&](const PointerCalculator& self, int8_t arg) {
				nullguard(L, self);
				*self.As<int8_t*>() = arg;
			};

			ptrUt["WriteUint8"] = [&](const PointerCalculator& self, uint8_t arg) {
				nullguard(L, self);
				*self.As<uint8_t*>() = arg;
			};

			ptrUt["WriteInt16"] = [&](const PointerCalculator& self, int16_t arg) {
				nullguard(L, self);
				*self.As<int16_t*>() = arg;
			};

			ptrUt["WriteUint16"] = [&](const PointerCalculator& self, uint16_t arg) {
				nullguard(L, self);
				*self.As<uint16_t*>() = arg;
			};

			ptrUt["WriteInt32"] = [&](const PointerCalculator& self, int32_t arg) {
				nullguard(L, self);
				*self.As<int32_t*>() = arg;
			};

			ptrUt["WriteUint32"] = [&](const PointerCalculator& self, uint32_t arg) {
				nullguard(L, self);
				*self.As<uint32_t*>() = arg;
			};

			ptrUt["WriteInt64"] = [&](const PointerCalculator& self, int64_t arg) {
				nullguard(L, self);
				*self.As<int64_t*>() = arg;
			};

			ptrUt["WriteUint64"] = [&](const PointerCalculator& self, uint64_t arg) {
				nullguard(L, self);
				*self.As<uint64_t*>() = arg;
			};

			ptrUt["WriteFloat"] = [&](const PointerCalculator& self, float arg) {
				nullguard(L, self);
				*self.As<float*>() = arg;
			};

			ptrUt["WriteString"] = [&](const PointerCalculator& self, std::string_view arg) {
				nullguard(L, self);
				size_t len = std::strlen(arg.data());
				std::memcpy(self.As<char*>(), arg.data(), len);
				self.As<char*>()[len] = '\0';
			};

			ptrUt["AddBytePatch"] = [&](const PointerCalculator& self, sol::table values) {
				nullguard(L, self);
				auto module = GetModuleFromLuaState(L);
				if (!module)
				{
					LOG(FATAL) << "Failed to add patch! Owner module is null";
					return sol::make_object(L, sol::nil);
				}

				std::vector<uint8_t> bytes;
				for (auto&& [_, v] : values)
				{
					if (!v.is<int>())
						throw sol::error("Invalid table value!");

					const int value = v.as<int>();
					if (value < 0 || value > 255)
						throw sol::error("Byte value out of range!");

					bytes.push_back(static_cast<uint8_t>(value));
				}

				auto patch = std::make_shared<BytePatch>(self.As<void*>(), std::span<uint8_t>(bytes));
				module->m_BytePatches.push_back(patch);
				return sol::make_object(L, patch);
			};

			/*@terminus.table Memory
			* description
				Provides memory utilities.
			
			* function ScanPattern Scans a byte signature and returns a Pointer object. The function is synchronous so it's best to run it in a fiber.
			* param sig<string> IDA-style byte signature. Example: `"8B 88 C0 ? ? ? 89 8F"`
			* param name<string?> Optional name of the pattern to scan. Purely for logging purposes.
			* return Pointer ptr A pointer at the found address or a null pointer if the scan fails. This is guaranteed to always return a Pointer object.
			
			* function HandleToPointer
			* param handle<integer> RAGE entity handle
			* return Pointer
			
			* function PointerToHandle
			* param ptr<Pointer> entity pointer
			* return integer handle
			
			* function Allocate Allocates a memory block and returns a Pointer to the allocated memory address.
			* param size<integer> size in bytes
			* return Pointer ptr Pointer to the allocated memory address.
			
			* function Free Frees an allocated memory block.
			* param ptr<Pointer>
			@*/
			auto memlib = L["Memory"].get_or_create<sol::table>();
			memlib["ScanPattern"] = [&](const std::string& sig, std::optional<std::string> name) {
				const auto rdr2 = ModuleMgr.Get(Joaat("RDR2.exe"));
				if (!rdr2)
				{
					LOG(FATAL) << "Could not find RDR2.exe, is this RDR2?";
					return retnull();
				}

				RuntimePattern pattern(name.value_or("UNK"), SimplePattern(sig));
				std::optional<PointerCalculator> found;
				PatternScanner scanner(rdr2);

				scanner.Add(pattern, [&](PointerCalculator pc) {
					found.emplace(pc);
				});
				scanner.Scan();

				return found ? found.value() : retnull();
			};

			memlib["HandleToPointer"] = [](int handle) {
				auto ptr = Pointers.HandleToPtr ? Pointers.HandleToPtr(handle) : nullptr;
				return PointerCalculator(ptr);
			};

			memlib["PointerToHandle"] = [](const PointerCalculator& ptr) {
				if (!ptr)
					return 0;

				return Pointers.PtrToHandle ? Pointers.PtrToHandle(ptr.As<void*>()) : 0;
			};

			memlib["Allocate"] = [&](int size) {
				if (size <= 0)
					throw sol::error("Invalid argument into Memory.Allocate! size must be greater than zero.");

				auto mod = GetModuleFromLuaState(L, "Failed to allocate memory! Owner module is null");
				if (!mod)
					return retnull();

				void* mem = new uint8_t[size]();
				mod->m_MemAllocs.push_back(mem);
				return PointerCalculator(mem);
			};

			memlib["Free"] = [&](const PointerCalculator& ptr) {
				auto mod = GetModuleFromLuaState(L, "Failed to free memory! Owner module is null");
				if (!mod)
					return;

				void* mem = ptr.As<void*>();
				auto it   = std::find(mod->m_MemAllocs.begin(), mod->m_MemAllocs.end(), mem);
				if (it == mod->m_MemAllocs.end())
					throw sol::error("An attempt to release memory not owned by this Lua module was rejected.");

				delete[] static_cast<uint8_t*>(*it);
				mod->m_MemAllocs.erase(it);
			};
		}
	};

	LuaMemLib _LuaMemLib;
}
