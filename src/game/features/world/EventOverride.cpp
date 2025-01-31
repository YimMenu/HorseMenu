#include "core/commands/LoopedCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"


namespace YimMenu
{
	static std::vector<std::pair<int, const char*>> g_EventOverrides = {
	    {0, "None"},
	    {1788394582, "Christmas"},
	    {"HALLOWEEN"_J, "Halloween"},
	};

	static ListCommand _OverrideEvent{"eventoverride", "Override Event", "The event to force", g_EventOverrides, 0};

	class OverrideEventEnabled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto eventHash  = ScriptGlobal(1901671).At(45).At(2);
		static constexpr auto eventStart = ScriptGlobal(1901671).At(45).At(3);
		static constexpr auto eventEnd   = ScriptGlobal(1901671).At(45).At(4);
		static constexpr auto eventFlags = ScriptGlobal(1901671).At(45).At(5);

		virtual void OnTick() override
		{
			if (eventStart.CanAccess(true))
			{
				*eventHash.As<int*>() = _OverrideEvent.GetState();
				*eventStart.As<int*>() = INT_MIN;
				*eventEnd.As<int*>()   = INT_MAX;
				*eventFlags.As<int*>()  = -1;
			}
		}

		virtual void OnDisable() override
		{
			if (eventStart.CanAccess(true))
			{
				*eventHash.As<int*>()  = NETWORK::NETWORK_TRY_ACCESS_TUNABLE_INT_HASH("BACKGROUND_SCRIPT"_J, "bgs_specialevent"_J, 0);
				*eventStart.As<int*>() = NETWORK::NETWORK_TRY_ACCESS_TUNABLE_INT_HASH("BACKGROUND_SCRIPT"_J, "bgs_posix_specialeventstart"_J, 0);
				*eventEnd.As<int*>() = NETWORK::NETWORK_TRY_ACCESS_TUNABLE_INT_HASH("BACKGROUND_SCRIPT"_J, "bgs_posix_specialeventend"_J, 0);
				*eventFlags.As<int*>() = NETWORK::NETWORK_TRY_ACCESS_TUNABLE_INT_HASH("BACKGROUND_SCRIPT"_J, "bgs_specialeventbitset"_J, 0);
			}
		}
	};

	static OverrideEventEnabled _OverrideEventEnabled{"eventoverrideenabled", "Event Override", "You may have to change sessions for the option to apply"};
}