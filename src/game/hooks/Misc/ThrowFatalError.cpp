#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	void Misc::ThrowFatalError(int code, int fileHash, int fileLine)
	{
		LOG(FATAL) << "RECEIVED FATAL ERROR | Code = " << HEX((uint32_t)code) << " | FileHash = " << HEX((uint32_t)fileHash) << " | FileLine = " << (uint32_t)fileLine << " | ReturnAddress = " << HEX((__int64)_ReturnAddress() - (__int64)GetModuleHandle(0));
		return;
	}
}