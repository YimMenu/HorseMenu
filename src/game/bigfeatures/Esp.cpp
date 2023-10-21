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
	static ImColor Green            = ImColor(0.29f, 0.69f, 0.34f, 1.f);
	static ImColor Orange           = ImColor(0.69f, 0.49f, 0.29f, 1.f);
	static ImColor Red              = ImColor(0.69f, 0.29f, 0.29f, 1.f);

	static auto boneToScreen = [=](Vector3 bone) -> ImVec2 {
		float screen_x, screen_y;
		float boneCoords[3] = {bone.x, bone.y, bone.z};

		Pointers.WorldToScreen(boneCoords, &screen_x, &screen_y);

		return ImVec2(screen_x * Pointers.ScreenResX, screen_y * Pointers.ScreenResY);
	};

	void DrawSkeleton(Player& plyr, ImDrawList* drawList, ImColor color)
	{
		const auto plyrBones = plyr.GetBoneCoords();

		drawList->AddLine(boneToScreen(plyrBones.Head), boneToScreen(plyrBones.Neck), color);

		drawList->AddLine(boneToScreen(plyrBones.Neck), boneToScreen(plyrBones.LeftElbow), color);
		drawList->AddLine(boneToScreen(plyrBones.LeftElbow), boneToScreen(plyrBones.LeftHand), color);

		drawList->AddLine(boneToScreen(plyrBones.Neck), boneToScreen(plyrBones.RightElbow), color);
		drawList->AddLine(boneToScreen(plyrBones.RightElbow), boneToScreen(plyrBones.RightHand), color);

		drawList->AddLine(boneToScreen(plyrBones.Neck), boneToScreen(plyrBones.Torso), color);

		drawList->AddLine(boneToScreen(plyrBones.Torso), boneToScreen(plyrBones.LeftKnee), color);
		drawList->AddLine(boneToScreen(plyrBones.LeftKnee), boneToScreen(plyrBones.LeftFoot), color);

		drawList->AddLine(boneToScreen(plyrBones.Torso), boneToScreen(plyrBones.RightKnee), color);
		drawList->AddLine(boneToScreen(plyrBones.RightKnee), boneToScreen(plyrBones.RightFoot), color);
	}

	//TODO : Very bare bones currently, expand and possibly refactor
	void Esp::DrawPlayer(Player& plyr, ImDrawList* drawList)
	{
		if (!plyr.IsValid() || plyr.GetId() == Self::Id || plyr.GetBoneCoords().Torso.x == 0)
			return;

		const auto plyrBones   = plyr.GetBoneCoords();
		float distanceToPlayer = Math::DistanceBetweenVectors(Self::Pos, plyrBones.Torso);
		ImColor colorBasedOnDistance = Red;

		if (distanceToPlayer < 100.f)
			colorBasedOnDistance = Green, colorBasedOnDistance.Value.w = 255;
		else if(distanceToPlayer > 100.f && distanceToPlayer < 300.f)
			colorBasedOnDistance = Orange, colorBasedOnDistance.Value.w = 125;
		else if (distanceToPlayer > 300.f)
			colorBasedOnDistance = Red, colorBasedOnDistance.Value.w = 50;

		const auto originalFontSize = ImGui::GetFont()->Scale;
		auto* currentFont = ImGui::GetFont();
		currentFont->Scale *= 1.2;
		ImGui::PushFont(ImGui::GetFont());
		//Name
		drawList->AddText(boneToScreen(plyrBones.Head), ImColor(255, 255, 255, 255), plyr.GetName());
		//Distance
		drawList->AddText({boneToScreen(plyrBones.Head).x, boneToScreen(plyrBones.Head).y + 20},
		    colorBasedOnDistance,
		    std::to_string((int)Math::DistanceBetweenVectors(Self::Pos, plyrBones.Torso)).data());

		currentFont->Scale = originalFontSize;
		ImGui::PopFont();

		//TODO Boxes, Distance colors, Friendlies, Tracers

		//Make this a setting
		DrawSkeleton(plyr, drawList, ImColor(255, 255, 255, 255));
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