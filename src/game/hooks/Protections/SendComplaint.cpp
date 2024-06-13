#include "core/hooking/DetourHook.hpp"
#include "game/backend/Players.hpp"
#include "game/hooks/Hooks.hpp"


namespace YimMenu::Hooks
{
	bool Protections::SendComplaint(uint64_t a1, int message_id, int* a3)
	{
		auto target = Player(Players::GetKickTarget());
		if (Players::GetKickTarget() != -1 && target.IsValid())
		{
			if (message_id == target.GetMessageId())
			{
				LOG(VERBOSE) << "Sending Complaint Kick to " << target.GetName();
				*a3 = 5;
				return true;
			}
		}
		return BaseHook::Get<Protections::SendComplaint, DetourHook<decltype(&Protections::SendComplaint)>>()->Original()(a1, message_id, a3);
	}
}