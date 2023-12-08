#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	// This is *not* noreturn
	void Misc::ThrowFatalError(int code, int fileHash, int fileLine)
	{
		//Make an exception to log the stack.
		int* nullPointer = 0;
		*nullPointer      = 69;

		//Spams the log with no actual information, eventually crashes the game
		//LOG(FATAL) << "RECEIVED FATAL ERROR | Code = " << HEX((uint32_t)code) << " | FileHash = " << HEX((uint32_t)fileHash) << " | FileLine = " << (uint32_t)fileLine << " | ReturnAddress = " << HEX((__int64)_ReturnAddress() - (__int64)GetModuleHandle(0));
	}
}