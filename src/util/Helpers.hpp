#pragma once

#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Ped.hpp"
#include "game/rdr/Vehicle.hpp"
#include <rage/datBitBuffer.hpp>


// TODO: remove this file
namespace Terminus::Helpers
{
	inline bool WriteArray(void* array, int size, rage::datBitBuffer* buffer)
	{
		return Pointers.WriteBitBufferArray(buffer, array, size, 0);
	}

	inline bool ReadArray(PVOID array, int size, rage::datBitBuffer* buffer)
	{
		return Pointers.ReadBitBufferArray(buffer, array, size, 0);
	}

	inline void WriteBufferString(const char* str, int max_len, rage::datBitBuffer* buffer)
	{
		auto len      = std::min(max_len, (int)strlen(str) + 1);
		bool extended = len > 127;
		buffer->Write<bool>(extended, 1);
		buffer->Write<int>(len, extended ? 15 : 7);
		WriteArray((void*)str, 8 * len, buffer);
	}

	inline bool ReadString(char* str, int bits, rage::datBitBuffer* buffer)
	{
		return Pointers.ReadBitBufferString(buffer, str, bits);
	}
}