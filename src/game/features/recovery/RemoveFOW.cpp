#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::Features
{
	class RemoveFOW : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			// Removes the Maps fog of war, allowing you to see the entire map without having to explore it.
			MAP::SET_MINIMAP_HIDE_FOW(true);
		}

		virtual void OnDisable() override
		{
			// Doing nothing defaults this after a game restart, if we set it false it will likely hide the map entirely.
		}
	};

	static RemoveFOW _removeFOW{"removefow", "Remove FOW", "Removes the Fog of War from the map entirely."};
}