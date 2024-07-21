#include "Esp.hpp"

#include "common.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "util/Math.hpp"
#include "core/commands/BoolCommand.hpp"

namespace
{
	constexpr int headBone       = 21030;
	constexpr int neckBone       = 14283;
	constexpr int torsoBone      = 14410;
	constexpr int leftHandBone   = 34606;
	constexpr int rightHandBone  = 22798;
	constexpr int leftFootBone   = 45454;
	constexpr int rightFootBone  = 33646;
	constexpr int leftElbowBone  = 22711;
	constexpr int rightElbowBone = 2992;
	constexpr int leftKneeBone   = 22173;
	constexpr int rightKneeBone  = 63133;
}

namespace YimMenu::Features
{
	BoolCommand _ESP("esp", "ESP", "Draws lines to nearby players and shows their skeleton");
}

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
	static ImColor Green            = ImColor(0.29f, 0.69f, 0.34f, 1.f);
	static ImColor Orange           = ImColor(0.69f, 0.49f, 0.29f, 1.f);
	static ImColor Red              = ImColor(0.69f, 0.29f, 0.29f, 1.f);
	static ImColor Blue             = ImColor(0.36f, 0.71f, 0.89f, 1.f);

	static auto boneToScreen = [=](rage::fvector3 bone) -> ImVec2 {
		float screen_x, screen_y;
		float boneCoords[3] = {bone.x, bone.y, bone.z};

		Pointers.WorldToScreen(boneCoords, &screen_x, &screen_y);

		return ImVec2(screen_x * Pointers.ScreenResX, screen_y * Pointers.ScreenResY);
	};

	void DrawSkeleton(Player& plyr, ImDrawList* drawList, ImColor color)
	{
		auto ped = plyr.GetPed();

		drawList->AddLine(boneToScreen(ped.GetBonePosition(headBone)), boneToScreen(ped.GetBonePosition(neckBone)), color);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(neckBone)), boneToScreen(ped.GetBonePosition(leftElbowBone)), color);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(leftElbowBone)), boneToScreen(ped.GetBonePosition(leftHandBone)), color);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(neckBone)), boneToScreen(ped.GetBonePosition(rightElbowBone)), color);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(rightElbowBone)), boneToScreen(ped.GetBonePosition(rightHandBone)), color);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(neckBone)), boneToScreen(ped.GetBonePosition(torsoBone)), color);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(torsoBone)), boneToScreen(ped.GetBonePosition(leftKneeBone)), color);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(leftKneeBone)), boneToScreen(ped.GetBonePosition(leftFootBone)), color);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(torsoBone)), boneToScreen(ped.GetBonePosition(rightKneeBone)), color);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(rightKneeBone)), boneToScreen(ped.GetBonePosition(rightFootBone)), color);
	}

	//TODO : Very bare bones currently, expand and possibly refactor
	void ESP::DrawPlayer(Player& plyr, ImDrawList* drawList)
	{
		if (!plyr.IsValid() || !plyr.GetPed().IsValid() || plyr == Self::GetPlayer() || boneToScreen(plyr.GetPed().GetBonePosition(torsoBone)).x == 0)
			return;

		float distanceToPlayer = Self::GetPed().GetPosition().GetDistance(plyr.GetPed().GetBonePosition(torsoBone));
		int alphaBasedOnDistance     = 255;
		ImColor colorBasedOnDistance = Red;

		if (distanceToPlayer < 100.f)
			colorBasedOnDistance = Green, alphaBasedOnDistance = 255;
		else if (distanceToPlayer > 100.f && distanceToPlayer < 300.f)
			colorBasedOnDistance = Orange, alphaBasedOnDistance = 200;
		else if (distanceToPlayer > 300.f)
			colorBasedOnDistance = Red, alphaBasedOnDistance = 125;

		const auto originalFontSize = ImGui::GetFont()->Scale;
		auto* currentFont           = ImGui::GetFont();
		currentFont->Scale *= 1.2;
		ImGui::PushFont(ImGui::GetFont());
		//Name
		drawList->AddText(boneToScreen(plyr.GetPed().GetBonePosition(headBone)), plyr == Players::GetSelected() ? Blue : ImColor(255, 255, 255, alphaBasedOnDistance), plyr.GetName());
		//Distance
		drawList->AddText({boneToScreen(plyr.GetPed().GetBonePosition(headBone)).x,
		                      boneToScreen(plyr.GetPed().GetBonePosition(headBone)).y + 20},
		    colorBasedOnDistance,
		    std::to_string((int)Self::GetPed().GetPosition().GetDistance(plyr.GetPed().GetBonePosition(torsoBone)))
		        .data());

		currentFont->Scale = originalFontSize;
		ImGui::PopFont();

		//TODO Boxes, Distance colors, Friendlies, Tracers, Health bars

		//TODO Make this a setting
		if (distanceToPlayer < 100.f)
			DrawSkeleton(plyr, drawList, ImColor(255, 255, 255, 255));
	}

	void ESP::Draw()
	{
		if (!Features::_ESP.GetState())
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