#pragma once
#include <cstdint>

namespace YimMenu
{
	inline constexpr std::uint8_t StrToHex(const char& ch) noexcept
	{
		if (ch >= '0' && ch <= '9')
			return ch - '0';

		if (ch >= 'A' && ch <= 'F')
			return ch - 'A' + 10;

		return ch - 'a' + 10;
	}

	inline std::string BytesToHexStr(unsigned char* data, int len)
	{
		std::stringstream ss;
		ss << std::hex;
		for (int i = 0; i < len; ++i)
			ss << std::setw(2) << std::setfill('0') << (int)data[i];
		return ss.str();
	}
}