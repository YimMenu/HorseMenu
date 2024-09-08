#pragma once
#include "game/rdr/Player.hpp"

namespace YimMenu
{
	class ESP
	{
	public:
		static void Draw();
		static void DrawPlayer(Player& plyr, ImDrawList* const draw_list);
		static void DrawPeds(Ped plyr, ImDrawList* drawList);
	};
}