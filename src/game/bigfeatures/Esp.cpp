#include "Esp.hpp"

#include "common.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "util/Math.hpp"

namespace YimMenu
{
	static ImColor death_bg         = ImColor(0.117f, 0.113f, 0.172f, .75f);
	static ImColor armor_blue_bg    = ImColor(0.36f, 0.71f, 0.89f, .75f);
	static ImColor armor_blue       = ImColor(0.36f, 0.71f, 0.89f, 1.f);
	static ImColor health_green_bg  = ImColor(0.29f, 0.69f, 0.34f, .75f);
	static ImColor health_green     = ImColor(0.29f, 0.69f, 0.34f, 1.f);
	static ImColor health_yellow_bg = ImColor(0.69f, 0.49f, 0.29f, .75f);
	static ImColor health_yellow    = ImColor(0.69f, 0.49f, 0.29f, 1.f);
	static ImColor health_red_bg    = ImColor(0.69f, 0.29f, 0.29f, .75f);
	static ImColor health_red       = ImColor(0.69f, 0.29f, 0.29f, 1.f);

	//TODO : Very bare bones currently, expand and possibly refactor
	void Esp::DrawPlayer(Player& plyr, ImDrawList* draw_list)
	{
		if (!plyr.IsValid() || plyr.GetId() == Self::Id || plyr.GetBoneCoords().Torso.x == 0)
			return;

		auto boneToTrack = plyr.GetBoneCoords().Torso;

		float screen_x, screen_y;
		float boneCoords[3] = {boneToTrack.x, boneToTrack.y, boneToTrack.z};

		Pointers.WorldToScreen(boneCoords, &screen_x, &screen_y);

		ImVec2 distanceIndicatorScreenPos = ImVec2(screen_x * Pointers.ScreenResX, (screen_y + 0.015f) * Pointers.ScreenResY);

		//Name
		draw_list->AddText(ImVec2(screen_x * Pointers.ScreenResX, screen_y * Pointers.ScreenResY), ImColor(255, 255, 255, 255), plyr.GetName());
		//Distance
		draw_list->AddText(distanceIndicatorScreenPos,
		    ImColor(255, 255, 255, 255),
		    std::to_string((int)Math::DistanceBetweenVectors(Self::Pos, boneToTrack)).data());
	}

	void Esp::Draw()
	{
		if (!g_Esp)
			return;

		if (const auto drawList = ImGui::GetBackgroundDrawList())
		{
			for (auto& [id, player] : Players::GetPlayers())
			{
				DrawPlayer(player, drawList);
			}
		}
	}

}