#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/backend/Voice.hpp"

#include <network/rlGamerHandle.hpp>

namespace YimMenu::Hooks
{
	bool Voice::WriteVoiceInfoData(rage::datBitBuffer* buffer, __int64 data)
	{
		auto handle = (rage::rlGamerHandle*)(data + 0x10);

		if (auto player = YimMenu::Voice::GetSpoofingPlayer())
			handle->m_RockstarId = player.GetRID();

		return BaseHook::Get<Voice::WriteVoiceInfoData, DetourHook<decltype(&Voice::WriteVoiceInfoData)>>()->Original()(buffer, data);
	}
}