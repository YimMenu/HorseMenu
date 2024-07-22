#include "Players.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/PlayerData.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "util/teleport.hpp"

#include <string>


// remove after testing
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Entity.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Packet.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/Scripts.hpp"
#include "util/VehicleSpawner.hpp"

#include <network/CNetworkScSession.hpp>
#include <network/CNetworkScSessionPlayer.hpp>
#include <network/netPeerAddress.hpp>
#include <network/rlGamerInfo.hpp>
#include <network/rlScPeerConnection.hpp>
#include <script/scrThread.hpp>


namespace YimMenu::Features
{
	BoolCommand _PopPlayerList{"popplayerlist", "Pop Player List", "Removes the player list in certain GUI interactions"};
}


namespace YimMenu::Submenus
{
	//bool popPlayerList = Features::_PopPlayerList.GetState();
	void drawPlayerList(bool external, float offset = 15.0f)
	{
		struct ComparePlayerNames
		{
			bool operator()(YimMenu::Player a, YimMenu::Player b) const
			{
				std::string nameA = a.GetName();
				std::string nameB = b.GetName();
				return nameA < nameB;
			}
		};

		std::map<uint8_t, Player, ComparePlayerNames> sortedPlayers(YimMenu::Players::GetPlayers().begin(),
		    YimMenu::Players::GetPlayers().end());

		if (external)
		{
			ImGui::SetNextWindowPos(
			    ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x + offset, ImGui::GetWindowPos().y));
			ImGui::SetNextWindowSize(ImVec2(150, ImGui::GetWindowSize().y));
			ImGui::Begin("Player List", nullptr, ImGuiWindowFlags_NoDecoration);

			ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
			for (auto& [id, player] : sortedPlayers)
			{
				std::string display_name = player.GetName();
				if (player.IsHost())
				{
					display_name.append(" - Host");
				}
				if (ImGui::Selectable(display_name.c_str(), (YimMenu::Players::GetSelected() == player)))
				{
					YimMenu::Players::SetSelected(id);
				}
			}
			ImGui::End();
		}
		else
		{
			if (ImGui::BeginCombo("Players", YimMenu::Players::GetSelected().GetName()))
			{
				for (auto& [id, player] : sortedPlayers)
				{
					if (ImGui::Selectable(player.GetName(), (YimMenu::Players::GetSelected() == player)))
					{
						YimMenu::Players::SetSelected(id);
					}
				}
				ImGui::EndCombo();
			}
		}
	}

	Players::Players() :
	    Submenu::Submenu("Players")
	{
		{
			auto main               = std::make_shared<Category>("Main");
			auto teleportGroup      = std::make_shared<Group>("Teleport");
			auto playerOptionsGroup = std::make_shared<Group>("Info");

			main->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			playerOptionsGroup->AddItem(std::make_shared<ImGuiItem>([] {
				if (YimMenu::Players::GetSelected().IsValid())
				{
					ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
					ImGui::Text(YimMenu::Players::GetSelected().GetName());

					auto health    = YimMenu::Players::GetSelected().GetPed().GetHealth();
					auto maxHealth = YimMenu::Players::GetSelected().GetPed().GetMaxHealth();
					std::string healthStr = std::format("HP: {}/{} ({:.2f}%)", health, maxHealth, (float)health / maxHealth * 100.0f);
					ImGui::Text("%s", healthStr.c_str());

					auto coords = YimMenu::Players::GetSelected().GetPed().GetPosition();
					ImGui::Text("Coords: %.2f, %.2f, %.2f", coords.x, coords.y, coords.z);

					auto distance = YimMenu::Players::GetSelected().GetPed().GetPosition().GetDistance(Self::GetPed().GetPosition());
					ImGui::Text("Distance: %.2f", distance);

					auto ridStr = std::to_string(YimMenu::Players::GetSelected().GetRID());
					ImGui::Text("RID:");
					ImGui::SameLine();
					if (ImGui::Button(ridStr.c_str()))
					{
						ImGui::SetClipboardText(ridStr.c_str());
					}

					auto ip = YimMenu::Players::GetSelected().GetExternalIpAddress();
					ImGui::Text("IP Address:");
					ImGui::SameLine();
					auto ipStr = std::string(std::to_string(ip.m_field1))
					                 .append("." + std::to_string(ip.m_field2))
					                 .append("." + std::to_string(ip.m_field3))
					                 .append("." + std::to_string(ip.m_field4));
					if (ImGui::Button(ipStr.c_str()))
					{
						ImGui::SetClipboardText(ipStr.c_str());
					}

					if (ImGui::Button("View SC Profile"))
						FiberPool::Push([] {
							uint64_t handle[18];
							NETWORK::NETWORK_HANDLE_FROM_PLAYER(YimMenu::Players::GetSelected().GetId(), (Any*)&handle);
							NETWORK::NETWORK_SHOW_PROFILE_UI((Any*)&handle);
						});

					if (ImGui::Button("Add Friend"))
						FiberPool::Push([] {
							uint64_t handle[18];
							NETWORK::NETWORK_HANDLE_FROM_PLAYER(YimMenu::Players::GetSelected().GetId(), (Any*)&handle);
							NETWORK::NETWORK_ADD_FRIEND((Any*)&handle, "");
						});
					if (ImGui::Button("Add to Player Database"))
					{
						auto plyr = YimMenu::Players::GetSelected();
						g_PlayerDatabase->AddPlayer(plyr.GetRID(), plyr.GetName());
					}
				}
				else
				{
					YimMenu::Players::SetSelected(Self::GetPlayer());
					ImGui::Text("No players yet!");
				}
			}));

			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tptoplayer"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpbehindplayer"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpintovehicle"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("bring"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpplayertowaypoint"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpplayertojail"_J));

			main->AddItem(playerOptionsGroup);
			main->AddItem(teleportGroup);
			AddCategory(std::move(main));
		}

		{
			auto helpful = std::make_shared<Category>("Helpful");

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(!Features::_PopPlayerList.GetState());
			}));

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				if (ImGui::Button("Spawn Bounty Wagon for Player"))
				{
					FiberPool::Push([] {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(YimMenu::Players::GetSelected().GetPed().GetHandle(), true, true);
						float rot = ENTITY::GET_ENTITY_ROTATION(YimMenu::Players::GetSelected().GetPed().GetHandle(), 0).z;
						SpawnVehicle("wagonarmoured01x", coords, rot);
						Notifications::Show("Spawned Wagon", "Spawned Bounty Wagon for Player", NotificationType::Success);
					});
				};

				if (ImGui::Button("Spawn Hunting Wagon for Player"))
				{
					FiberPool::Push([] {
						int id   = YimMenu::Players::GetSelected().GetId();
						auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id);
						Vector3 dim1, dim2;
						MISC::GET_MODEL_DIMENSIONS(MISC::GET_HASH_KEY("huntercart01"), &dim1, &dim2);
						float offset = dim2.y * 1.6;

						Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(ped);
						float rot   = (ENTITY::GET_ENTITY_ROTATION(ped, 0)).z;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(ped, true, true);

						int handle = SpawnVehicle("huntercart01",
						    Vector3{pos.x + (dir.x * offset), pos.y + (dir.y * offset), pos.z},
						    ENTITY::GET_ENTITY_ROTATION(ped, 0).z);
						PLAYER::_SET_PLAYER_HUNTING_WAGON(id, handle);
						Notifications::Show("Spawned Wagon", "Spawned Hunting Wagon for Player", NotificationType::Success);
					});
				}
			}));

			AddCategory(std::move(helpful));
		}

		{
			auto trolling = std::make_shared<Category>("Trolling");

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(!Features::_PopPlayerList.GetState());
			}));

			trolling->AddItem(std::make_shared<PlayerCommandItem>("cageplayersmall"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("cageplayerlarge"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("circus"_J));

			AddCategory(std::move(trolling));
		}

		{
			auto toxic = std::make_shared<Category>("Toxic");

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			auto general = std::make_shared<Group>("General");			
			general->AddItem(std::make_shared<PlayerCommandItem>("kill"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("explode"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("lightning"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("defensive"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("offensive"_J));
			
			auto events = std::make_shared<Group>("Events");
			events->AddItem(std::make_shared<PlayerCommandItem>("maxhonor"_J));
			events->AddItem(std::make_shared<PlayerCommandItem>("minhonor"_J));
			events->AddItem(std::make_shared<PlayerCommandItem>("startparlay"_J));
			events->AddItem(std::make_shared<PlayerCommandItem>("endparlay"_J));
			events->AddItem(std::make_shared<PlayerCommandItem>("increasebounty"_J));
			events->AddItem(std::make_shared<PlayerCommandItem>("sendticker"_J));
			events->AddItem(std::make_shared<ListCommandItem>("tickermessage"_J, "Message"));
			events->AddItem(std::make_shared<PlayerCommandItem>("sendstablemountevent"_J));
			events->AddItem(std::make_shared<ListCommandItem>("mountinstance"_J, "Instance"));	
			events->AddItem(std::make_shared<ListCommandItem>("stablemountevent"_J, "Event"));

			auto mount = std::make_shared<Group>("Mount");
			mount->AddItem(std::make_shared<PlayerCommandItem>("kickhorse"_J));

			toxic->AddItem(general);
			toxic->AddItem(events);
			toxic->AddItem(mount);

			AddCategory(std::move(toxic));
		}

		{
			auto kick = std::make_shared<Category>("Kick");

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			kick->AddItem(std::make_shared<PlayerCommandItem>("splitkick"_J));
			kick->AddItem(std::make_shared<PlayerCommandItem>("popkick"_J));

			AddCategory(std::move(kick));
		}
	}
}