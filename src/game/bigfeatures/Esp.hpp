#pragma once
#include "game/rdr/Player.hpp"

namespace YimMenu
{
	class Esp
	{
	public:
		static void Draw();
		static void DrawPlayer(Player& plyr, ImDrawList* const draw_list);
	};
}