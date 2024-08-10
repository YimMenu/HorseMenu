#include "Players.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/frontend/widgets/imgui_colors.h"
#include "game/backend/PlayerData.hpp"
#include "game/backend/PlayerDatabase.hpp"
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
#include "game/rdr/Network.hpp"
#include "game/rdr/Packet.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/Scripts.hpp"

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
	struct Tag
	{
		std::string Name;
		ImVec4 Color;
	};

	static std::vector<Tag> GetPlayerTags(YimMenu::Player player)
	{
		std::vector<Tag> tags;

		if (player.IsHost())
			tags.push_back({"HOST", ImGui::Colors::DeepSkyBlue});

		if (player.IsModder())
			tags.push_back({"MOD", ImGui::Colors::DeepPink});

		if (player.GetPed() && player.GetPed().IsInvincible())
			tags.push_back({"GOD", ImGui::Colors::Crimson});

		if (player.GetPed() && !player.GetPed().IsVisible())
			tags.push_back({"INVIS", ImGui::Colors::MediumPurple});

		return tags;
	}

	static void DrawPlayerList(bool external, float offset = 15.0f)
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

		std::multimap<uint8_t, Player, ComparePlayerNames> sortedPlayers(YimMenu::Players::GetPlayers().begin(),
		    YimMenu::Players::GetPlayers().end());

		if (external)
		{
			ImGui::SetNextWindowPos(
			    ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x + offset, ImGui::GetWindowPos().y));
			ImGui::SetNextWindowSize(ImVec2(215, ImGui::GetWindowSize().y));
			ImGui::Begin("Player List", nullptr, ImGuiWindowFlags_NoDecoration);

			ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
			for (auto& [id, player] : sortedPlayers)
			{
				std::string display_name = player.GetName();
				if (ImGui::Selectable(display_name.c_str(), (YimMenu::Players::GetSelected() == player)))
				{
					YimMenu::Players::SetSelected(id);
				}

				if (player.IsModder() && ImGui::IsItemHovered())
				{
					ImGui::BeginTooltip();
					for (auto detection : player.GetData().m_Detections)
						ImGui::BulletText("%s", g_PlayerDatabase->ConvertDetectionToDescription(detection).c_str());
					ImGui::EndTooltip();
				}

				auto tags = GetPlayerTags(player);

				auto old_item_spacing = ImGui::GetStyle().ItemSpacing.x;

				for (auto& tag : tags)
				{
					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Text, tag.Color);
					ImGui::Text(("[" + tag.Name + "]").c_str());
					ImGui::PopStyleColor();
					ImGui::GetStyle().ItemSpacing.x = 1;
				}

				ImGui::GetStyle().ItemSpacing.x = old_item_spacing;
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
				DrawPlayerList(true);
			}));

			playerOptionsGroup->AddItem(std::make_shared<ImGuiItem>([] {
				if (YimMenu::Players::GetSelected().IsValid())
				{
					ImGui::Text(YimMenu::Players::GetSelected().GetName());
					ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
					ImGui::Checkbox("Block Explosions", &YimMenu::Players::GetSelected().GetData().m_BlockExplosions);
					ImGui::Checkbox("Block Particles", &YimMenu::Players::GetSelected().GetData().m_BlockParticles);
					if (ImGui::Checkbox("Ghost Mode", &YimMenu::Players::GetSelected().GetData().m_GhostMode))
					{
						if (YimMenu::Players::GetSelected().GetData().m_GhostMode)
						{
							FiberPool::Push([] {
								if (YimMenu::Players::GetSelected().IsValid())
								{
									Network::ForceRemoveNetworkEntity(Self::GetPed().GetNetworkObject(), false, YimMenu::Players::GetSelected());
								}
							});
						}
					}

					ImGui::Text("Rank: %s", std::to_string(YimMenu::Players::GetSelected().GetRank()));

					if (YimMenu::Players::GetSelected().GetPed())
					{
						auto health    = YimMenu::Players::GetSelected().GetPed().GetHealth();
						auto maxHealth = YimMenu::Players::GetSelected().GetPed().GetMaxHealth();
						std::string healthStr = std::format("HP: {}/{} ({:.2f}%)", health, maxHealth, (float)health / maxHealth * 100.0f);
						ImGui::Text("%s", healthStr.c_str());

						auto coords = YimMenu::Players::GetSelected().GetPed().GetPosition();
						ImGui::Text("Coords: %.2f, %.2f, %.2f", coords.x, coords.y, coords.z);

						auto distance =
						    YimMenu::Players::GetSelected().GetPed().GetPosition().GetDistance(Self::GetPed().GetPosition());
						ImGui::Text("Distance: %.2f", distance);
					}
					else
					{
						ImGui::Text("Ped missing or deleted");
					}

					auto rid        = YimMenu::Players::GetSelected().GetGamerInfo()->m_GamerHandle.m_RockstarId;
					auto rid1       = YimMenu::Players::GetSelected().GetRID();
					bool spoofedRid = (rid != rid1);

					if (!spoofedRid)
					{
						std::string ridStr = std::to_string(rid1);

						ImGui::Text("RID:");
						ImGui::SameLine();
						if (ImGui::Button(std::to_string(rid1).c_str()))
						{
							ImGui::SetClipboardText(std::to_string(rid1).c_str());
						}
					}
					else
					{
						std::string spoofedRidStr = std::to_string(rid);
						std::string ridStr        = std::to_string(rid1);

						ImGui::Text("Spoofed RID:");
						ImGui::SameLine();
						if (ImGui::Button(spoofedRidStr.c_str()))
						{
							ImGui::SetClipboardText(spoofedRidStr.c_str());
						}

						ImGui::Text("Real RID:");
						ImGui::SameLine();
						if (ImGui::Button(ridStr.c_str()))
						{
							ImGui::SetClipboardText(ridStr.c_str());
						}
					}

					auto ip        = YimMenu::Players::GetSelected().GetExternalAddress();
					auto ip1       = YimMenu::Players::GetSelected().GetGamerInfo()->m_ExternalAddress;
					bool spoofedIp = (ip.m_packed != ip1.m_packed);

					if (!spoofedIp)
					{
						auto ipStr = std::string(std::to_string(ip.m_field1))
						                 .append("." + std::to_string(ip.m_field2))
						                 .append("." + std::to_string(ip.m_field3))
						                 .append("." + std::to_string(ip.m_field4));

						ImGui::Text("IP Address:");
						ImGui::SameLine();
						if (ImGui::Button(ipStr.c_str()))
						{
							ImGui::SetClipboardText(ipStr.c_str());
						}
					}
					else
					{
						auto spoofedIpStr = std::string(std::to_string(ip1.m_field1))
						                        .append("." + std::to_string(ip1.m_field2))
						                        .append("." + std::to_string(ip1.m_field3))
						                        .append("." + std::to_string(ip1.m_field4));

						auto realIpStr = std::string(std::to_string(ip.m_field1))
						                     .append("." + std::to_string(ip.m_field2))
						                     .append("." + std::to_string(ip.m_field3))
						                     .append("." + std::to_string(ip.m_field4));

						ImGui::Text("Spoofed IP Address:");
						ImGui::SameLine();
						if (ImGui::Button(spoofedIpStr.c_str()))
						{
							ImGui::SetClipboardText(spoofedIpStr.c_str());
						}

						ImGui::Text("Real IP Address:");
						ImGui::SameLine();
						if (ImGui::Button(realIpStr.c_str()))
						{
							ImGui::SetClipboardText(realIpStr.c_str());
						}
					}

					if (ImGui::Button("View SC Profile"))
						FiberPool::Push([] {
							uint64_t handle[18];
							NETWORK::NETWORK_HANDLE_FROM_PLAYER(YimMenu::Players::GetSelected().GetId(), (Any*)&handle);
							NETWORK::NETWORK_SHOW_PROFILE_UI((Any*)&handle);
						});
					ImGui::SameLine();
					if (ImGui::Button("Add Friend"))
						FiberPool::Push([] {
							uint64_t handle[18];
							NETWORK::NETWORK_HANDLE_FROM_PLAYER(YimMenu::Players::GetSelected().GetId(), (Any*)&handle);
							NETWORK::NETWORK_ADD_FRIEND((Any*)&handle, "");
						});
					ImGui::SameLine();
					if (ImGui::Button("Add to Database"))
					{
						auto plyr = YimMenu::Players::GetSelected();
						g_PlayerDatabase->AddPlayer(plyr.GetRID(), plyr.GetName());
					}

					if (ImGui::Button("More Info"))
						ImGui::OpenPopup("More Info");

					ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
					if (ImGui::BeginPopupModal("More Info", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_Modal | ImGuiWindowFlags_AlwaysAutoResize))
					{
						ImGui::Text("Language: %s", g_LanguageMap[YimMenu::Players::GetSelected().GetLanguage()].c_str());

						auto honor = YimMenu::Players::GetSelected().GetHonor();
						std::string honorLevel;

						if (honor >= 0 && honor <= 7)
						{
							honorLevel = "Low";
						}
						else if (honor > 7 && honor <= 10)
						{
							honorLevel = "Moderate";
						}
						else if (honor > 10 && honor <= 15)
						{
							honorLevel = "High";
						}
						else
						{
							honorLevel = "Invalid";
						}

						honorLevel += " (" + std::to_string(honor) + "/15)";
						ImGui::Text("Honor: %s", honorLevel.c_str());

						ImGui::Text("Model: %s", YimMenu::Players::GetSelected().GetPed().GetModel());

						ImGui::Text("District: %s", g_DistrictMap[YimMenu::Players::GetSelected().GetDistrict()].c_str());

						ImGui::Text("Region: %s", g_RegionMap[YimMenu::Players::GetSelected().GetRegion()].c_str());

						auto internalIp = YimMenu::Players::GetSelected().GetInternalAddress();
						ImGui::Text("Internal IP: %s",
						    std::format("{}.{}.{}.{}:{}",
						        static_cast<int>(internalIp.m_field1),
						        static_cast<int>(internalIp.m_field2),
						        static_cast<int>(internalIp.m_field3),
						        static_cast<int>(internalIp.m_field4),
						        YimMenu::Players::GetSelected().GetInternalPort())
						        .c_str());

						auto relayIp = YimMenu::Players::GetSelected().GetRelayAddress();
						ImGui::Text("Relay IP: %s",
						    std::format("{}.{}.{}.{}:{}",
						        static_cast<int>(relayIp.m_field1),
						        static_cast<int>(relayIp.m_field2),
						        static_cast<int>(relayIp.m_field3),
						        static_cast<int>(relayIp.m_field4),
						        YimMenu::Players::GetSelected().GetRelayPort())
						        .c_str());


						ImGui::Text("Relay State: %u", YimMenu::Players::GetSelected().GetRelayState());

						ImGui::Text("Average Latency: %.2f", YimMenu::Players::GetSelected().GetAverageLatency());
						ImGui::Text("Packet Loss: %.2f", YimMenu::Players::GetSelected().GetAveragePacketLoss());

						ImGui::Spacing();

						if (ImGui::Button("Close") || ((!ImGui::IsWindowHovered() && !ImGui::IsAnyItemHovered()) && ImGui::IsMouseClicked(ImGuiMouseButton_Left)))
							ImGui::CloseCurrentPopup();

						ImGui::EndPopup();
					}
				}
				else
				{
					YimMenu::Players::SetSelected(Self::GetPlayer());
					ImGui::Text("No players yet!");
				}
			}));

			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tptoplayer"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tptoplayercamp"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpbehindplayer"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpintovehicle"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("bring"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpplayertowaypoint"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpplayertomadamnazar"_J));
			teleportGroup->AddItem(std::make_shared<PlayerCommandItem>("tpplayertojail"_J));

			main->AddItem(playerOptionsGroup);
			main->AddItem(teleportGroup);
			AddCategory(std::move(main));
		}

		{
			auto helpful = std::make_shared<Category>("Helpful");

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				DrawPlayerList(!Features::_PopPlayerList.GetState());
			}));

			helpful->AddItem(std::make_shared<PlayerCommandItem>("spawngoldchest"_J));
			helpful->AddItem(std::make_shared<PlayerCommandItem>("deletegoldchests"_J));

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				if (ImGui::Button("Spawn Bounty Wagon for Player"))
				{
					FiberPool::Push([] {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(YimMenu::Players::GetSelected().GetPed().GetHandle(), true, true);
						float rot = ENTITY::GET_ENTITY_ROTATION(YimMenu::Players::GetSelected().GetPed().GetHandle(), 0).z;
						Vehicle::Create("wagonarmoured01x"_J, coords, rot);
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

						Vehicle::Create("huntercart01"_J,
						    Vector3{pos.x + (dir.x * offset), pos.y + (dir.y * offset), pos.z},
						    ENTITY::GET_ENTITY_ROTATION(ped, 0).z);
						Notifications::Show("Spawned Wagon", "Spawned Hunting Wagon for Player", NotificationType::Success);
					});
				}
			}));

			AddCategory(std::move(helpful));
		}

		{
			auto trolling = std::make_shared<Category>("Trolling");

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				DrawPlayerList(!Features::_PopPlayerList.GetState());
			}));

			trolling->AddItem(std::make_shared<PlayerCommandItem>("cageplayersmall"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("cageplayerlarge"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("circus"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("spank"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("rideonshoulders"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("touchplayer"_J));
			trolling->AddItem(std::make_shared<PlayerCommandItem>("slap"_J));

			AddCategory(std::move(trolling));
		}

		{
			auto toxic = std::make_shared<Category>("Toxic");

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				DrawPlayerList(true);
			}));

			auto general = std::make_shared<Group>("General");
			general->AddItem(std::make_shared<PlayerCommandItem>("kill"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("explode"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("lightning"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("defensive"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("offensive"_J));
			general->AddItem(std::make_shared<PlayerCommandItem>("remotebolas"_J));

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
			mount->AddItem(std::make_shared<PlayerCommandItem>("deletehorse"_J));

			auto vehicle = std::make_shared<Group>("Vehicle");
		    vehicle->AddItem(std::make_shared<PlayerCommandItem>("deletevehicle"_J));

			toxic->AddItem(general);
			toxic->AddItem(events);
			toxic->AddItem(mount);
			toxic->AddItem(vehicle);

			AddCategory(std::move(toxic));
		}

		{
			auto kick = std::make_shared<Category>("Kick");

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				DrawPlayerList(true);
			}));

			kick->AddItem(std::make_shared<PlayerCommandItem>("splitkick"_J));
			kick->AddItem(std::make_shared<PlayerCommandItem>("popkick"_J));

			AddCategory(std::move(kick));
		}
	}
}