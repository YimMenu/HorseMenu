#include "Players.hpp"

#include "core/commands/Commands.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "util/teleport.hpp"

// remove after testing
#include "game/rdr/Natives.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/Scripts.hpp"
#include <script/scrThread.hpp>
#include "game/rdr/Entity.hpp"

namespace YimMenu::Submenus
{
	bool popPlayerList = true; //TODO make optional
	void drawPlayerList(bool external, float offset = 15.0f)
	{
		if (external)
		{
			ImGui::SetNextWindowPos(
			    ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x + offset, ImGui::GetWindowPos().y));
			ImGui::SetNextWindowSize(ImVec2(150, ImGui::GetWindowSize().y));
			ImGui::Begin("Player List", nullptr, ImGuiWindowFlags_NoDecoration);
			for (auto& [id, player] : YimMenu::Players::GetPlayers())
			{
				if (ImGui::Selectable(player.GetName(), (YimMenu::Players::GetSelected() == player)))
				{
					YimMenu::Players::SetSelected(id);
				}
			}
			ImGui::End();
		}
		else
		{
			for (auto& [id, player] : YimMenu::Players::GetPlayers())
			{
				if (ImGui::Selectable(player.GetName(), (YimMenu::Players::GetSelected() == player)))
				{
					YimMenu::Players::SetSelected(id);
				}
			}
		}
	}

	Players::Players() :
	    Submenu::Submenu("Players")
	{
		{
			auto main   = std::make_shared<Category>("Main");
			auto column = std::make_shared<Column>(2);

			auto playersListGroup = std::make_shared<Group>("Players");

			playersListGroup->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(false);
			}));

			auto playerOptionsGroup = std::make_shared<Group>("Info");

			playerOptionsGroup->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
				ImGui::Separator();

				ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
				//Button Widget crashes the game, idk why. Changed to regular for now.
				if(ImGui::Button("Teleport To"))
				{
					// TODO: convert into a command
					FiberPool::Push([]{
						auto playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(YimMenu::Players::GetSelected().GetId()), true, true);
						Teleport::TeleportEntity(Self::PlayerPed, playerCoords);
					});
				}
			}));

			column->AddColumnOffset(1, 160);
			column->AddItem(playersListGroup);
			column->AddNextColumn();
			column->AddItem(playerOptionsGroup);

			main->AddItem(column);
			AddCategory(std::move(main));
		}

		{
			auto helpful = std::make_shared<Category>("Helpful");

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(popPlayerList);
			}));

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(helpful));
		}

		{
			auto trolling = std::make_shared<Category>("Trolling");

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(popPlayerList);
			}));

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));


			AddCategory(std::move(trolling));
		}

		{
			auto toxic = std::make_shared<Category>("Toxic");

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			toxic->AddItem(std::make_shared<PlayerCommandItem>("explode"_J));
			toxic->AddItem(std::make_shared<PlayerCommandItem>("defensive"_J));
			toxic->AddItem(std::make_shared<PlayerCommandItem>("offensive"_J));
			toxic->AddItem(std::make_shared<PlayerCommandItem>("maxhonor"_J));
			toxic->AddItem(std::make_shared<PlayerCommandItem>("minhonor"_J));

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				if (ImGui::Button("Test"))
				{
					FiberPool::Push([] {
						using Scf = void(*)(void* ent, int flg, bool val, bool net);
						Scf scf  = (Scf)((__int64)GetModuleHandleA(0) + 0x1d0e898);
						for (int i = 0; i < 0x7F; i++)
						{
							if (!(i % 12))
								ScriptMgr::Yield();
							scf(YimMenu::Players::GetSelected().GetPed().GetPointer<void*>(), i, true, true);
						}
					});
				}

				if (ImGui::Button("Test 2"))
				{
					FiberPool::Push([] {
						using Pd = void (*)(__int16 net);
						Pd pd    = (Pd)((__int64)GetModuleHandleA(0) + 0x23f4eb8);
						pd(YimMenu::Players::GetSelected().GetPed().GetNetworkObjectId());
					});
				}

				if (ImGui::Button("Test 3"))
				{
					FiberPool::Push([] {
						float test = 2345.0f;
						PED::_0x09E378C52B1433B5(YimMenu::Players::GetSelected().GetPed().GetHandle(), *(int*)&test, *(int*)&test, *(int*)&test, *(int*)&test);
					});
				}

				if (ImGui::Button("Test 4"))
				{
					FiberPool::Push([] {
						using GE = void (*)(__int16 net, bool ghost);
						GE ge    = (GE)((__int64)GetModuleHandleA(0) + 0x23f43f0);
						ge(YimMenu::Players::GetSelected().GetPed().GetNetworkObjectId(), true);
					});
				}

				if (ImGui::Button("Test 10"))
				{
					FiberPool::Push([] {
						MISC::SET_CHEAT_ACTIVE(4);
					});
				}

				
				if (ImGui::Button("Test 11"))
				{
					FiberPool::Push([] {
						using LP = void (*)(void* looter, void*, bool, bool);
						LP lp    = (LP)((__int64)GetModuleHandleA(0) + 0x23f3324);
						lp(YimMenu::Players::GetSelected().GetPed().GetPointer<void*>(), Pointers.GetLocalPed(), true, true);
					});
				}

				if (ImGui::Button("Test 12"))
				{
					FiberPool::Push([] {
						using GM = void*(*)(void*);
						using SM = void (*)(void*, int, float, void*, bool); // PED::_SET_PED_MOTIVATION
						GM gm    = (GM)((__int64)GetModuleHandleA(0) + 0xcb8ee8);
						SM sm    = (SM)((__int64)GetModuleHandleA(0) + 0x9a2ab0);
						sm(gm(YimMenu::Players::GetSelected().GetPed().GetPointer<void*>()), 10, 999.0f, nullptr, true);
					});
				}

				if (ImGui::Button("Test 13"))
				{
					FiberPool::Push([] {
						using CS = void (*)(void*, void*, float);
						CS cs    = (CS)((__int64)GetModuleHandleA(0) + 0x23f64d0);
						cs(YimMenu::Players::GetSelected().GetPed().GetPointer<void*>(),
						    YimMenu::Players::GetSelected().GetPed().GetPointer<void*>(), -9999.0f); // positive to add
					});
				}

				if (ImGui::Button("Test 15"))
				{
					FiberPool::Push([] {
						struct Struct1
						{
							SCR_INT Time;
							SCR_INT Pad[12];
						};

						struct Struct2
						{
							SCR_INT Pad;
							const char* VarString;
							SCR_INT Pad2[2];
						};

						Struct1 s1{};
						Struct2 s2{};

						s1.Time = 3000;

						auto text = MISC::VAR_STRING(10, "LITERAL_STRING"s.data(), "~b~Player~s~ left."s.data());
						s2.VarString = text;

						UIFEED::_UI_FEED_POST_FEED_TICKER(&s1, &s2, false);
					});
				}
			}));

			AddCategory(std::move(toxic));
		}

		{
			auto kick = std::make_shared<Category>("Kick"); // would we ever find one?

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(kick));
		}
	}
}