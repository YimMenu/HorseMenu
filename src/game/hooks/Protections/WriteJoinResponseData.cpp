#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"

namespace rage
{
	class CJoinRequestContext;
	class CMsgJoinResponse;
}


namespace YimMenu::Hooks
{
	bool Protections::WriteJoinResponseData(rage::CMsgJoinResponse* response, void* data, int size, uint32_t* size_used)
	{
		return BaseHook::Get<Protections::WriteJoinResponseData, DetourHook<decltype(&Protections::WriteJoinResponseData)>>()
		    ->Original()(response, data, size, size_used);
	}
}