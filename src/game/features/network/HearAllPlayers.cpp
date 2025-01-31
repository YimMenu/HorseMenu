#include "core/commands/LoopedCommand.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Features
{
	void _0x58125B691F6827D5(rage::scrNativeCallContext* ctx);
	void _0x08797A8C03868CB8(rage::scrNativeCallContext* ctx);

	class HearAllPlayers : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		ScriptGlobal HudGlobal = ScriptGlobal(1072759).At(21353).At(1);

		virtual void OnEnable()
		{
			static auto run_once = ([]() {
				NativeHooks::AddHook("net_main_offline"_J, NativeIndex::_0x58125B691F6827D5, _0x58125B691F6827D5);
				NativeHooks::AddHook("net_main_offline"_J, NativeIndex::_0x08797A8C03868CB8, _0x08797A8C03868CB8);
				return true;
			})();
		}

		virtual void OnTick() override
		{
			VOICE::_0x58125B691F6827D5(999999.0f);
			VOICE::_0x08797A8C03868CB8(999999.0f);
			if (HudGlobal.CanAccess(true))
			{
				*HudGlobal.At(Self::GetPlayer().GetId(), 8).At(7).As<int*>() |= 262144;
				*HudGlobal.At(Self::GetPlayer().GetId(), 8).At(7).As<int*>() |= 524288;
			}
		}

		virtual void OnDisable() override
		{
			if (HudGlobal.CanAccess(true))
			{
				*HudGlobal.At(Self::GetPlayer().GetId(), 8).At(7).As<int*>() &= ~262144;
				*HudGlobal.At(Self::GetPlayer().GetId(), 8).At(7).As<int*>() &= ~524288;
			}
		}
	};

	static HearAllPlayers _HearAllPlayers{"hearall", "Hear All Players", "Hear the voice chat of every player on the map regardless of distance. This also makes everyone hear your voice chat"};

	// _SET_VOICE_CHAT_CUSTOM_TALKER_PROXIMITY
	void _0x58125B691F6827D5(rage::scrNativeCallContext* ctx)
	{
		float proximity = ctx->GetArg<int>(2);
		if (_HearAllPlayers.GetState())
			proximity = 999999.0f;

		VOICE::_0x58125B691F6827D5(proximity);
	}

	// _SET_VOICE_CHAT_FADE_START_THRESHOLD
	void _0x08797A8C03868CB8(rage::scrNativeCallContext* ctx)
	{
		float threshold = ctx->GetArg<int>(2);
		if (_HearAllPlayers.GetState())
			threshold = 999999.0f;

		VOICE::_0x08797A8C03868CB8(threshold);
	}
}