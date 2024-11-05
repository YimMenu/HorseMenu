#include "Esp.hpp"

#include "common.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/commands/ColorCommand.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Pools.hpp"
#include "game/rdr/Scripts.hpp"
#include "util/Math.hpp"

#include "game/rdr/data/PedModels.hpp"

#include "game/rdr/invoker/Invoker.hpp"

namespace
{
	// Human
	constexpr int headBone          = 21030;
	constexpr int neckBone          = 14283;
	constexpr int torsoBone         = 14410;
	constexpr int leftHandBone      = 34606;
	constexpr int rightHandBone     = 22798;
	constexpr int leftFootBone      = 45454;
	constexpr int rightFootBone     = 33646;
	constexpr int leftElbowBone     = 22711;
	constexpr int rightElbowBone    = 2992;
	constexpr int leftKneeBone      = 22173;
	constexpr int rightKneeBone     = 63133;
	constexpr int leftShoulderBone  = 44903;
	constexpr int rightShoulderBone = 4312;

	// Horse
	constexpr int horseHeadBone   = 21030;
	constexpr int horseNeckBone0  = 14283;
	constexpr int horseNeckBone1  = 14284;
	constexpr int horseNeckBone2  = 14285;
	constexpr int horseNeckBone3  = 14286;
	constexpr int horseNeckBone4  = 14287;
	constexpr int horseNeckBone5  = 14288;
	constexpr int horseTorsoBone  = 14410;
	constexpr int horsePelvisBone = 56200;
	constexpr int horseTailBone   = 30992;

	// Front left leg
	constexpr int horseFrontLeftUpperArmBone = 37873;
	constexpr int horseFrontLeftForearmBone  = 53675;
	constexpr int horseFrontLeftHandBone     = 34606;
	constexpr int horseFrontLeftFingerBone0  = 41403;
	constexpr int horseFrontLeftFingerBone1  = 41404;

	// Front right leg
	constexpr int horseFrontRightUpperArmBone = 46065;
	constexpr int horseFrontRightForearmBone  = 54187;
	constexpr int horseFrontRightHandBone     = 22798;
	constexpr int horseFrontRightFingerBone0  = 16827;
	constexpr int horseFrontRightFingerBone1  = 16828;

	// Rear left leg
	constexpr int horseRearLeftThighBone = 65478;
	constexpr int horseRearLeftCalfBone  = 55120;
	constexpr int horseRearLeftFootBone  = 45454;
	constexpr int horseRearLeftToeBone0  = 53081;
	constexpr int horseRearLeftToeBone1  = 53082;

	// Rear right leg
	constexpr int horseRearRightThighBone = 6884;
	constexpr int horseRearRightCalfBone  = 43312;
	constexpr int horseRearRightFootBone  = 33646;
	constexpr int horseRearRightToeBone0  = 41273;
	constexpr int horseRearRightToeBone1  = 41274;
}

namespace YimMenu::Features
{
	// Players
	BoolCommand _ESPDrawPlayers("espdrawplayers", "Draw Players", "Should the ESP draw players?");
	BoolCommand _ESPDrawDeadPlayers("espdrawdeadplayers", "Draw Dead Players", "Should the ESP draw dead players?");

	BoolCommand _ESPName("espnameplayers", "Show Player Name", "Should the ESP draw player names?");
	BoolCommand _ESPDistance("espdistanceplayers", "Show Player Distance", "Should the ESP draw player distance?");
	BoolCommand _ESPSkeleton("espskeletonplayers", "Show Player Skeleton", "Should the ESP draw player skeletons?");

	ColorCommand _NameColorPlayers("namecolorplayers", "Player Name Color", "Changes the color of the name ESP for players", ImVec4{});
	ColorCommand _DistanceColorPlayers("distancecolorplayers", "Player Distance Color", "Changes the color of the distance ESP for players", ImVec4{});
	ColorCommand _SkeletonColorPlayers("skeletoncolorplayers", "Player Skeleton Color", "Changes the color of the skeleton ESP for players", ImVec4{});

	// Peds
	BoolCommand _ESPDrawPeds("espdrawpeds", "Draw Peds", "Should the ESP draw peds?");
	BoolCommand _ESPDrawDeadPeds("espdrawdeadpeds", "Draw Dead Peds", "Should the ESP draw dead peds?");

	BoolCommand _ESPModelPeds("espmodelspeds", "Show Ped Model", "Should the ESP draw ped models?");
	BoolCommand _ESPNetworkInfoPeds("espnetinfopeds", "Show Ped Network Info", "Should the ESP draw network info?");
	BoolCommand _ESPScriptInfoPeds("espscriptinfopeds", "Show Ped Script Info", "Should the ESP draw script info?");
	BoolCommand _ESPDistancePeds("espdistancepeds", "Show Ped Distance", "Should the ESP draw distance?");
	BoolCommand _ESPSkeletonPeds("espskeletonpeds", "Show Ped Skeleton", "Should the ESP draw the skeleton?");
	BoolCommand _ESPSkeletonHorse("espskeletonhorse", "Show Horse Skeleton", "Should the ESP draw horse skeletons?");

	ColorCommand _HashColorPeds("hashcolorpeds", "Ped Hash Color", "Changes the color of the hash ESP for peds", ImVec4{});
	ColorCommand _DistanceColorPeds("distancecolorpeds", "Ped Distance Color", "Changes the color of the distance ESP for peds", ImVec4{});
	ColorCommand _SkeletonColorPeds("skeletoncolorpeds", "Ped Skeleton Color", "Changes the color of the skeleton ESP for peds", ImVec4{});
	ColorCommand _SkeletonColorHorse("skeletoncolorhorse", "Horse Skeleton Color", "Changes the color of the skeleton ESP for horses", ImVec4{});

}

namespace YimMenu
{
	static ImVec4 death_bg         = ImVec4(0.117f, 0.113f, 0.172f, .75f);
	static ImVec4 armor_blue_bg    = ImVec4(0.36f, 0.71f, 0.89f, .75f);
	static ImVec4 armor_blue       = ImVec4(0.36f, 0.71f, 0.89f, 1.f);
	static ImVec4 health_green_bg  = ImVec4(0.29f, 0.69f, 0.34f, .75f);
	static ImVec4 health_green     = ImVec4(0.29f, 0.69f, 0.34f, 1.f);
	static ImVec4 health_yellow_bg = ImVec4(0.69f, 0.49f, 0.29f, .75f);
	static ImVec4 health_yellow    = ImVec4(0.69f, 0.49f, 0.29f, 1.f);
	static ImVec4 health_red_bg    = ImVec4(0.69f, 0.29f, 0.29f, .75f);
	static ImVec4 health_red       = ImVec4(0.69f, 0.29f, 0.29f, 1.f);
	static ImVec4 Green            = ImVec4(0.29f, 0.69f, 0.34f, 1.f);
	static ImVec4 Orange           = ImVec4(0.69f, 0.49f, 0.29f, 1.f);
	static ImVec4 Red              = ImVec4(0.69f, 0.29f, 0.29f, 1.f);
	static ImVec4 Blue             = ImVec4(0.36f, 0.71f, 0.89f, 1.f);

	static auto boneToScreen = [=](rage::fvector3 bone) -> ImVec2 {
		float screen_x, screen_y;
		float boneCoords[3] = {bone.x, bone.y, bone.z};

		Pointers.WorldToScreen(boneCoords, &screen_x, &screen_y);

		return ImVec2(screen_x * (*Pointers.ScreenResX), screen_y * (*Pointers.ScreenResY));
	};

	void DrawSkeleton(Ped ped, ImDrawList* drawList, ImColor color)
	{
		drawList->AddLine(boneToScreen(ped.GetBonePosition(headBone)), boneToScreen(ped.GetBonePosition(neckBone)), color, 1.5f);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(neckBone)), boneToScreen(ped.GetBonePosition(leftShoulderBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(leftShoulderBone)), boneToScreen(ped.GetBonePosition(leftElbowBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(leftElbowBone)), boneToScreen(ped.GetBonePosition(leftHandBone)), color, 1.5f);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(neckBone)), boneToScreen(ped.GetBonePosition(rightShoulderBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(rightShoulderBone)), boneToScreen(ped.GetBonePosition(rightElbowBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(rightElbowBone)), boneToScreen(ped.GetBonePosition(rightHandBone)), color, 1.5f);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(neckBone)), boneToScreen(ped.GetBonePosition(torsoBone)), color, 1.5f);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(torsoBone)), boneToScreen(ped.GetBonePosition(leftKneeBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(leftKneeBone)), boneToScreen(ped.GetBonePosition(leftFootBone)), color, 1.5f);

		drawList->AddLine(boneToScreen(ped.GetBonePosition(torsoBone)), boneToScreen(ped.GetBonePosition(rightKneeBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(ped.GetBonePosition(rightKneeBone)), boneToScreen(ped.GetBonePosition(rightFootBone)), color, 1.5f);
	}

	void DrawHorseSkeleton(Ped horse, ImDrawList* drawList, ImColor color)
	{
		// Head and neck
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseHeadBone)), boneToScreen(horse.GetBonePosition(horseNeckBone0)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseNeckBone0)), boneToScreen(horse.GetBonePosition(horseTorsoBone)), color, 1.5f);

		// Torso and pelvis
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseTorsoBone)), boneToScreen(horse.GetBonePosition(horsePelvisBone)), color, 1.5f);

		// Front left leg
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseNeckBone0)), boneToScreen(horse.GetBonePosition(horseFrontLeftUpperArmBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontLeftUpperArmBone)), boneToScreen(horse.GetBonePosition(horseFrontLeftForearmBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontLeftForearmBone)), boneToScreen(horse.GetBonePosition(horseFrontLeftHandBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontLeftHandBone)), boneToScreen(horse.GetBonePosition(horseFrontLeftFingerBone0)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontLeftFingerBone0)), boneToScreen(horse.GetBonePosition(horseFrontLeftFingerBone1)), color, 1.5f);

		// Front right leg
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseNeckBone0)), boneToScreen(horse.GetBonePosition(horseFrontRightUpperArmBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontRightUpperArmBone)), boneToScreen(horse.GetBonePosition(horseFrontRightForearmBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontRightForearmBone)), boneToScreen(horse.GetBonePosition(horseFrontRightHandBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontRightHandBone)), boneToScreen(horse.GetBonePosition(horseFrontRightFingerBone0)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseFrontRightFingerBone0)), boneToScreen(horse.GetBonePosition(horseFrontRightFingerBone1)), color, 1.5f);

		// Rear left leg
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horsePelvisBone)), boneToScreen(horse.GetBonePosition(horseRearLeftThighBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearLeftThighBone)), boneToScreen(horse.GetBonePosition(horseRearLeftCalfBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearLeftCalfBone)), boneToScreen(horse.GetBonePosition(horseRearLeftFootBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearLeftFootBone)), boneToScreen(horse.GetBonePosition(horseRearLeftToeBone0)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearLeftToeBone0)), boneToScreen(horse.GetBonePosition(horseRearLeftToeBone1)), color, 1.5f);

		// Rear right leg
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horsePelvisBone)), boneToScreen(horse.GetBonePosition(horseRearRightThighBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearRightThighBone)), boneToScreen(horse.GetBonePosition(horseRearRightCalfBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearRightCalfBone)), boneToScreen(horse.GetBonePosition(horseRearRightFootBone)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearRightFootBone)), boneToScreen(horse.GetBonePosition(horseRearRightToeBone0)), color, 1.5f);
		drawList->AddLine(boneToScreen(horse.GetBonePosition(horseRearRightToeBone0)), boneToScreen(horse.GetBonePosition(horseRearRightToeBone1)), color, 1.5f);
	}
	
	//TODO : Very bare bones currently, expand and possibly refactor
	void ESP::DrawPlayer(Player& plyr, ImDrawList* drawList)
	{
		if (!plyr.IsValid() || !plyr.GetPed().IsValid() || plyr == Self::GetPlayer()
		    || boneToScreen(plyr.GetPed().GetBonePosition(torsoBone)).x == 0
		    || (plyr.GetPed().IsDead() && !Features::_ESPDrawDeadPlayers.GetState()))
			return;

		float distanceToPlayer   = Self::GetPed().GetPosition().GetDistance(plyr.GetPed().GetBonePosition(torsoBone));
		int alphaBasedOnDistance = 255;
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

		if (Features::_ESPName.GetState())
		{
			drawList->AddText(boneToScreen(plyr.GetPed().GetBonePosition(headBone)),
			    plyr == Players::GetSelected() ? ImGui::ColorConvertFloat4ToU32(Blue) : ImGui::ColorConvertFloat4ToU32(Features::_NameColorPlayers.GetState()),
			    plyr.GetName());
		}

		if (Features::_ESPDistance.GetState())
		{
			std::string distanceStr = std::to_string((int)Self::GetPed().GetPosition().GetDistance(plyr.GetPed().GetBonePosition(torsoBone))) + "m";
			drawList->AddText({boneToScreen(plyr.GetPed().GetBonePosition(headBone)).x,
			                      boneToScreen(plyr.GetPed().GetBonePosition(headBone)).y + 20},
			    colorBasedOnDistance,
			    distanceStr.c_str());
		}

		currentFont->Scale = originalFontSize;
		ImGui::PopFont();

		//TODO Boxes, Distance colors, Friendlies, Tracers, Health bars

		if (Features::_ESPSkeleton.GetState() && !plyr.GetPed().IsAnimal()) // yes, this is neccesary.
		{
			if (distanceToPlayer < 250.f)
			{
				DrawSkeleton(plyr.GetPed(), drawList, ImGui::ColorConvertFloat4ToU32(Features::_SkeletonColorPlayers.GetState()));
			}
		}
	}

	void ESP::DrawPeds(Ped ped, ImDrawList* drawList)
	{
		if (!ped.IsValid() || ped.IsPlayer() || ped == Self::GetPlayer().GetPed() || boneToScreen(ped.GetBonePosition(torsoBone)).x == 0 || (ped.IsDead() && !Features::_ESPDrawDeadPeds.GetState()))
			return;

		float distanceToPed = 0.0f;
		
		if (auto local = Self::GetPed())
			distanceToPed = local.GetPosition().GetDistance(ped.GetBonePosition(torsoBone));
		
		int alphaBasedOnDistance     = 255;
		ImColor colorBasedOnDistance = Red;

		if (distanceToPed < 100.f)
			colorBasedOnDistance = Green, alphaBasedOnDistance = 255;
		else if (distanceToPed > 100.f && distanceToPed < 300.f)
			colorBasedOnDistance = Orange, alphaBasedOnDistance = 200;
		else if (distanceToPed > 300.f)
			colorBasedOnDistance = Red, alphaBasedOnDistance = 125;

		const auto originalFontSize = ImGui::GetFont()->Scale;
		auto* currentFont           = ImGui::GetFont();
		currentFont->Scale *= 1.2;
		ImGui::PushFont(ImGui::GetFont());

		std::string info = "";

		if (Features::_ESPModelPeds.GetState())
		{
			if (auto it = Data::g_PedModels.find(ped.GetModel()); it != Data::g_PedModels.end())
				info += std::format("{} ", it->second);
			else
				info += std::format("0x{:08X} ", (joaat_t)ped.GetModel());
		}

		if (Features::_ESPNetworkInfoPeds.GetState() && ped.IsNetworked())
		{
			auto owner = Player(ped.GetOwner());
			auto id = ped.GetNetworkObjectId();

			info += std::format("{} {} ", id, owner.GetName());
		}

		if (Features::_ESPScriptInfoPeds.GetState())
		{
			if (auto script = ENTITY::_GET_ENTITY_SCRIPT(ped.GetHandle(), nullptr))
			{
				if (auto name = Scripts::GetScriptName(script))
				{
					info += std::format("{} ", name);
				}
			}
		}

		if (!info.empty())
			drawList->AddText(boneToScreen(ped.GetBonePosition(headBone)),
				ImGui::ColorConvertFloat4ToU32(Features::_HashColorPeds.GetState()),
				info.c_str());

		if (Features::_ESPDistancePeds.GetState())
		{
			std::string distanceStr = std::to_string((int)distanceToPed) + "m";
			drawList->AddText(
			    {boneToScreen(ped.GetBonePosition(headBone)).x, boneToScreen(ped.GetBonePosition(headBone)).y + 20},
			    colorBasedOnDistance,
			    distanceStr.c_str());
		}

		currentFont->Scale = originalFontSize;
		ImGui::PopFont();

		//TODO Boxes, Distance colors, Tracers, Health bars	

		if (Features::_ESPSkeletonPeds.GetState() && !ped.IsAnimal())
		{
			if (distanceToPed < 250.f)
			{
				DrawSkeleton(ped, drawList, ImGui::ColorConvertFloat4ToU32(Features::_SkeletonColorPeds.GetState()));
			}
		}

		if (Features::_ESPSkeletonHorse.GetState() && PED::_IS_THIS_MODEL_A_HORSE(ped.GetModel()))
		{
			if (distanceToPed < 250.f)
			{
				DrawHorseSkeleton(ped, drawList, ImGui::ColorConvertFloat4ToU32(Features::_SkeletonColorHorse.GetState()));
			}
		}
	}

	void ESP::Draw()
	{
		if (!NativeInvoker::AreHandlersCached() || CAM::IS_SCREEN_FADED_OUT())
			return;

		if (const auto drawList = ImGui::GetBackgroundDrawList())
		{
			if (Features::_ESPDrawPlayers.GetState())
			{
				for (auto& [id, player] : Players::GetPlayers())
				{
					DrawPlayer(player, drawList);
				}
			}
			if (Features::_ESPDrawPeds.GetState() && GetPedPool())
			{
				for (Ped ped : Pools::GetPeds())
				{
					if (ped.IsValid() || ped.GetPointer<void*>())
						DrawPeds(ped, drawList);
				}
			}
		}
	}

}