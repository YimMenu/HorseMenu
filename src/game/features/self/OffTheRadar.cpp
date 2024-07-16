#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/NativeHooks.hpp"

namespace YimMenu::Features
{
	void DECOR_SET_INT(rage::scrNativeCallContext* ctx);

	class OffTheRadar : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnEnable()
		{
			static auto run_once = ([]() {
				NativeHooks::AddHook("net_main_offline"_J, NativeIndex::DECOR_SET_INT, DECOR_SET_INT);
				return true;
			})();
		}

		virtual void OnTick() override
		{
			DECORATOR::DECOR_SET_INT(Self::GetPed().GetHandle(), "MP_HUD_Hide_My_Blip_FOR_TEAMS", -1);
		}

		virtual void OnDisable() override
		{
			DECORATOR::DECOR_REMOVE(Self::GetPed().GetHandle(), "MP_HUD_Hide_My_Blip_FOR_TEAMS");
		}
	};

	static OffTheRadar _OffTheRadar{"offtheradar", "Off The Radar", "You won't show up on the maps of other players"};

	// TODO: maybe add support for removing native hooks dynamically?
	void DECOR_SET_INT(rage::scrNativeCallContext* ctx)
	{
		int flags = ctx->GetArg<int>(2);
		if (Joaat(ctx->GetArg<char*>(1)) == "MP_HUD_Bits"_J)
		{
			if (_OffTheRadar.GetState())
				flags |= 64;
		}
		DECORATOR::DECOR_SET_INT(ctx->GetArg<ScrHandle>(0), ctx->GetArg<const char*>(1), flags);
	}
}