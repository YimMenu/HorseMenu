#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
    class NeverWanted : public LoopedCommand
    {
        using LoopedCommand::LoopedCommand;

        virtual void OnTick() override
        {
            // Set the wanted level multiplier to 0 (Never Wanted)
            PLAYER::SET_WANTED_LEVEL_MULTIPLIER(0.0f);
        }

        virtual void OnDisable() override
        {
            // Reset the wanted level multiplier to 1.0f (normal behavior)
            PLAYER::SET_WANTED_LEVEL_MULTIPLIER(1.0f);
        }
    };

    static NeverWanted _NeverWanted{"neverwanted", "Never Wanted", "Toggle Never Wanted mode"};
}
