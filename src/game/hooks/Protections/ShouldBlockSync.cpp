#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/misc/RateLimiter.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/PlayerData.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Protections.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Network.hpp"
#include "game/rdr/Nodes.hpp"
#include "game/rdr/data/PedModels.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkScSession.hpp>
#include <network/netObject.hpp>
#include <network/rlGamerInfo.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <network/sync/animal/CAnimalCreationData.hpp>
#include <network/sync/animscene/CAnimSceneCreationData.hpp>
#include <network/sync/animscene/CAnimSceneInfrequentData.hpp>
#include <network/sync/object/CObjectCreationData.hpp>
#include <network/sync/ped/CPedAttachData.hpp>
#include <network/sync/ped/CPedCreationData.hpp>
#include <network/sync/ped/CPedTaskTreeData.hpp>
#include <network/sync/physical/CPhysicalAttachData.hpp>
#include <network/sync/pickup/CPickupCreationData.hpp>
#include <network/sync/player/CPlayerAppearanceData.hpp>
#include <network/sync/player/CPlayerCreationData.hpp>
#include <network/sync/player/CPlayerGameStateUncommonData.hpp>
#include <network/sync/projectile/CProjectileCreationData.hpp>
#include <network/sync/propset/CPropSetCreationData.hpp>
#include <network/sync/vehicle/CVehicleCreationData.hpp>
#include <network/sync/vehicle/CVehicleGadgetData.hpp>
#include <network/sync/vehicle/CVehicleProximityMigrationData.hpp>
#include <ped/CPed.hpp>
#include <rage/vector.hpp>
#include <unordered_set>
#include <network/CNetworkScSession.hpp>
#include <train/CTrainConfig.hpp>

#define BLOCK_CRASHES 1

namespace YimMenu::Features
{
	BoolCommand _LogClones("logclones", "Log Incoming Clones", "Log clone creates and clone syncs");
	BoolCommand _AllowRemoteTPs("allowremotetp", "Allow Remote Teleports", "Allow trusted players to remote teleport you!");

	BoolCommand _BlockSpectate("blockspectate", "Block Spectate", "Attempts to prevent modders from spectating you", true);
	BoolCommand _BlockSpectateSession("blockspectatesession", "Block Spectate for Session", "Attempts to prevent modders from spectating anyone", false);
	BoolCommand _BlockAttachments("blockattach", "Block Attachments", "Prevents modders from attaching objects and peds to you", true);
	BoolCommand _BlockVehicleFlooding("blockvehflood", "Block Vehicle Flooding", "Prevents modders from creating too many vehicles", true);

	BoolCommand _BlockGhostPeds("blockghostpeds", "Block Ghost Peds", "Blocks creation of ghost peds that are seemingly created due to a game bug", true);
}

namespace
{
	using namespace YimMenu;

	static const std::unordered_set<uint32_t> g_CrashObjects = {0xD1641E60, 0x6927D266};
	static const std::unordered_set<uint32_t> g_FishModels   = {
        "A_C_Crawfish_01"_J,
        "A_C_FishBluegil_01_ms"_J,
        "A_C_FishBluegil_01_sm"_J,
        "A_C_FishBullHeadCat_01_ms"_J,
        "A_C_FishBullHeadCat_01_sm"_J,
        "A_C_FishChainPickerel_01_ms"_J,
        "A_C_FishChainPickerel_01_sm"_J,
        "A_C_FishChannelCatfish_01_lg"_J,
        "A_C_FishChannelCatfish_01_XL"_J,
        "A_C_FishLakeSturgeon_01_lg"_J,
        "A_C_FishLargeMouthBass_01_lg"_J,
        "A_C_FishLargeMouthBass_01_ms"_J,
        "A_C_FishLongNoseGar_01_lg"_J,
        "A_C_FishMuskie_01_lg"_J,
        "A_C_FishNorthernPike_01_lg"_J,
        "A_C_FishPerch_01_ms"_J,
        "A_C_FishPerch_01_sm"_J,
        "A_C_FishRainbowTrout_01_lg"_J,
        "A_C_FishRainbowTrout_01_ms"_J,
        "A_C_FishRedfinPickerel_01_ms"_J,
        "A_C_FishRedfinPickerel_01_sm"_J,
        "A_C_FishRockBass_01_ms"_J,
        "A_C_FishRockBass_01_sm"_J,
        "A_C_FishSalmonSockeye_01_lg"_J,
        "A_C_FishSalmonSockeye_01_ml"_J,
        "A_C_FishSalmonSockeye_01_ms"_J,
        "A_C_FishSmallMouthBass_01_lg"_J,
        "A_C_FishSmallMouthBass_01_ms"_J,
    };

	static const std::unordered_set<uint32_t> g_BirdModels = {
	    "a_c_prairiechicken_01"_J,
	    "a_c_cormorant_01"_J,
	    "a_c_crow_01"_J,
	    "a_c_duck_01"_J,
	    "a_c_eagle_01"_J,
	    "a_c_goosecanada_01"_J,
	    "a_c_hawk_01"_J,
	    "a_c_owl_01"_J,
	    "a_c_pelican_01"_J,
	    "a_c_pigeon"_J,
	    "a_c_raven_01"_J,
	    "a_c_cardinal_01"_J,
	    "a_c_seagull_01"_J,
	    "a_c_songbird_01"_J,
	    "a_c_turkeywild_01"_J,
	    "a_c_turkey_01"_J,
	    "a_c_turkey_02"_J,
	    "a_c_vulture_01"_J,
	    "a_c_bluejay_01"_J,
	    "a_c_cedarwaxwing_01"_J,
	    "a_c_rooster_01"_J,
	    "mp_a_c_chicken_01"_J,
	    "a_c_chicken_01"_J,
	    "a_c_californiacondor_01"_J,
	    "a_c_cranewhooping_01"_J,
	    "a_c_egret_01"_J,
	    "a_c_heron_01"_J,
	    "a_c_loon_01"_J,
	    "a_c_oriole_01"_J,
	    "a_c_carolinaparakeet_01"_J,
	    "a_c_parrot_01"_J,
	    "a_c_pelican_01"_J,
	    "a_c_pheasant_01"_J,
	    "a_c_pigeon"_J,
	    "a_c_quail_01"_J,
	    "a_c_redfootedbooby_01"_J,
	    "a_c_robin_01"_J,
	    "a_c_roseatespoonbill_01"_J,
	    "a_c_seagull_01"_J,
	    "a_c_sparrow_01"_J,
	    "a_c_vulture_01"_J,
	    "a_c_woodpecker_01"_J,
	    "a_c_woodpecker_02"_J,
	};

	static const std::unordered_set<uint32_t> g_CageModels        = {0x99C0CFCF, 0xF3D580D3, 0xEE8254F6, 0xC2D200FE};
	static const std::unordered_set<uint32_t> g_ValidPlayerModels = {"mp_male"_J, "mp_female"_J};
	
	static const std::unordered_set<uint32_t> g_BlacklistedAnimScenes = {"script@beat@town@peepingtom@spankscene"_J, "script@story@sal1@ig@sal1_18_lenny_on_lenny@sal1_18_lenny_on_lenny"_J, "script@vignette@dutch_33@player_karen@dance"_J, "script@vignette@beecher@abigail_6@action_enter"_J};

	inline bool IsValidPlayerModel(rage::joaat_t model)
	{
		return g_ValidPlayerModels.contains(model);
	}

	inline void CheckPlayerModel(YimMenu::Player player, uint32_t model)
	{
		if (!player)
			return;

		if (!IsValidPlayerModel(model))
			player.AddDetection(Detection::INVALID_PLAYER_MODEL);
	}

	inline YimMenu::Player GetObjectCreator(rage::netObject* object)
	{
		if (!object)
			return nullptr;

		for (auto& [idx, player] : Players::GetPlayers())
		{
			if ((*Pointers.ScSession)->m_SessionMultiplayer->GetPlayerByIndex(idx)->m_SessionPeer->m_Identifier.m_AccountId == object->m_Guid.GetAccountId())
			{
				return player;
			}
		}

		return nullptr;
	}

	inline void SyncBlocked(std::string crash, YimMenu::Player source = Protections::GetSyncingPlayer())
	{
		if (source)
		{
			LOGF(WARNING, "Blocked {} from {}", crash, source.GetName());
			auto name = source.GetName();
			Notifications::Show("Protections", std::format("Blocked {} from {}", crash, name), NotificationType::Warning);
		}
	}

	inline void DeleteSyncObject(std::uint16_t object)
	{
		if (object == -1)
			return;

		Network::ForceRemoveNetworkEntity(object, -1, false);
	}

	inline void DeleteSyncObjectLater(std::uint16_t object)
	{
		FiberPool::Push([object] {
			if (object == -1)
				return;

			Network::ForceRemoveNetworkEntity(object, -1, true);
		});
	}

	// note that object can be nullptr here if it hasn't been created yet (i.e. in the creation queue)
	bool ShouldBlockNode(CProjectBaseSyncDataNode* node, SyncNodeId id, NetObjType type, rage::netObject* object)
	{
		switch (id)
		{
		case "CPedCreationNode"_J:
		{
			auto& data = node->GetData<CPedCreationData>();
			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_PED(data.m_ModelHash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid ped creation model 0x{:X} from {}", data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("mismatched ped model crash");
				data.m_ModelHash = "MP_MALE"_J;
				data.m_BannedPed = true; // blocking this seems difficult
				return true;
			}
			break;
		}
		case "CAnimalCreationNode"_J:
		{
			auto& data = node->GetData<CAnimalCreationData>();
			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_PED(data.m_ModelHash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid animal creation model 0x{:X} from {}", data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("mismatched animal model crash");
				data.m_ModelHash = "MP_MALE"_J;
				data.m_BannedPed = true; // blocking this seems difficult
				return true;
			}
			if (data.m_PopulationType == 10 && Features::_BlockGhostPeds.GetState())
			{
				// block ghost peds
				if (object)
					DeleteSyncObject(object->m_ObjectId);
				return true;
			}
			break;
		}
		case "CObjectCreationNode"_J:
		{
			auto& data = node->GetData<CObjectCreationData>();
			if (g_CrashObjects.count(data.m_ModelHash))
			{
				LOGF(SYNC, WARNING, "Blocking crash object creation model 0x{:X} from {}", data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("invalid object crash");
				return true;
			}
			if (data.m_ModelHash && !STREAMING::_IS_MODEL_AN_OBJECT(data.m_ModelHash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid object creation model 0x{:X} from {}", data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("mismatched object model crash");
				return true;
			}
			if (g_CageModels.count(data.m_ModelHash))
			{
				if (object)
					DeleteSyncObject(object->m_ObjectId);
				SyncBlocked("cage spawn", GetObjectCreator(object));
				return true;
			}

			break;
		}
		case "CPlayerAppearanceNode"_J:
		{
			auto& data = node->GetData<CPlayerAppearanceData>();
			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_PED(data.m_ModelHash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid player appearance model 0x{:X} from {}", data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("mismatched player model crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER); // false positives very unlikely
				data.m_ModelHash = "MP_MALE"_J;
			}

			if (data.m_ModelHash && (g_FishModels.count(data.m_ModelHash) || g_BirdModels.count(data.m_ModelHash)))
			{
				// TODO
				LOGF(SYNC, WARNING, "Prevented {} from using animal model 0x{:X} to prevent potential task crashes", Protections::GetSyncingPlayer().GetName(), data.m_ModelHash);
				// data.m_ModelHash = "MP_MALE"_J;
			}

			CheckPlayerModel(Protections::GetSyncingPlayer().GetHandle(), data.m_ModelHash);

			break;
		}
		case "CVehicleCreationNode"_J:
		{
			auto& data = node->GetData<CVehicleCreationData>();
			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_VEHICLE(data.m_ModelHash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid vehicle creation model 0x{:X} from {}", data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("mismatched vehicle model crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
				return true;
			}

			if (data.m_PopulationType == 8 && data.m_ModelHash == "SHIP_GUAMA02"_J && Protections::GetSyncingPlayer().GetData().m_LargeVehicleFloodLimit.Process() && Features::_BlockVehicleFlooding.GetState())
			{
				SyncBlocked("large vehicle flood");
				return true;
			}

			if (data.m_PopulationType == 8 && Protections::GetSyncingPlayer().GetData().m_VehicleFloodLimit.Process() && Features::_BlockVehicleFlooding.GetState())
			{
				SyncBlocked("vehicle flood");
				return true;
			}

			break;
		}
		case "CPhysicalAttachNode"_J:
		{
			auto& data = node->GetData<CPhysicalAttachData>();
			if (auto local = Pointers.GetLocalPed(); local && local->m_NetObject)
			{
				if (data.m_IsAttached && data.m_AttachObjectId == local->m_NetObject->m_ObjectId && Features::_BlockAttachments.GetState())
				{
					SyncBlocked("attachment", GetObjectCreator(object));
					Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_ATTACH);
					DeleteSyncObject(object->m_ObjectId);
					return true;
				}

				if (data.m_IsAttached && object && object->m_ObjectType == (uint16_t)NetObjType::Trailer)
				{
					SyncBlocked("physical trailer attachment crash");
					Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
					return true;
				}
			}
			break;
		}
		case "CVehicleProximityMigrationNode"_J:
		{
			auto& data = node->GetData<CVehicleProximityMigrationData>();
			if (auto local = Pointers.GetLocalPed(); local && local->m_NetObject)
			{
				bool allowRemoteTp = Features::_AllowRemoteTPs.GetState();
				for (int i = 0; i < 17; i++)
				{
					if (data.m_PassengersActive[i] && data.m_PassengerObjectIds[i] == local->m_NetObject->m_ObjectId && !allowRemoteTp)
					{
						LOGF(SYNC, WARNING, "Blocking vehicle migration that's spuriously added us to the passenger list (seat={}) by {}", i, Protections::GetSyncingPlayer().GetName());
						SyncBlocked("remote teleport");
						Protections::GetSyncingPlayer().AddDetection(Detection::REMOTE_TELEPORT);
						DeleteSyncObject(object->m_ObjectId);
						return true;
					}
				}
			}
			break;
		}
		case "CPedTaskTreeNode"_J:
		{
			auto& data = node->GetData<CPedTaskTreeData>();

			for (int i = 0; i < data.GetNumTaskTrees(); i++)
			{
				for (int j = 0; j < data.m_Trees[i].m_NumTasks; j++)
				{
					if (data.m_Trees[i].m_Tasks[j].m_TaskType == -1)
					{
						LOGF(SYNC, WARNING, "Blocking null task type (tree={}, task={}) from {}", i, j, Protections::GetSyncingPlayer().GetName());
						SyncBlocked("task fuzzer crash");
						// TODO fix node corruption bug
						// Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER); // no false positives possible
						return true;
					}

					// TODO: better heuristics
					if (data.m_Trees[i].m_Tasks[j].m_TaskTreeType == 31)
					{
						LOGF(SYNC, WARNING, "Blocking invalid task tree type (tree={}, task={}) from {}", i, j, Protections::GetSyncingPlayer().GetName());
						SyncBlocked("task fuzzer crash");
						// Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER); // no false positives possible
						return true;
					}
				}
			}
			break;
		}
		case "CPedAttachNode"_J:
		{
			auto& data = node->GetData<CPedAttachData>();
			if (auto local = Pointers.GetLocalPed(); local && local->m_NetObject)
			{
				if (data.m_IsAttached && data.m_AttachObjectId == local->m_NetObject->m_ObjectId && Features::_BlockAttachments.GetState())
				{
					SyncBlocked("ped attachment");
					Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_ATTACH);
					if (object->m_ObjectType != (int)NetObjType::Player)
					{
						LOGF(SYNC, WARNING, "Deleting ped object {} attached to our ped", object->m_ObjectId);
						DeleteSyncObject(object->m_ObjectId);
						return true;
					}
					else
					{
						LOGF(SYNC, WARNING, "Player {} has attached themselves to us. Pretending to delete our ped to force detach ourselves on their end", Protections::GetSyncingPlayer().GetName());
						// delete us on their end
						Network::ForceRemoveNetworkEntity(Self::GetPed().GetNetworkObjectId(), -1, false, Protections::GetSyncingPlayer());
						data.m_IsAttached = false;
					}
				}

				// TODO: the check looks off
				if (data.m_IsAttached && object && object->m_ObjectType == (uint16_t)NetObjType::Trailer)
				{
					SyncBlocked("ped trailer attachment crash");
					Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
					return true;
				}
			}
			break;
		}
		case "CPropSetCreationNode"_J:
		{
			auto& data = node->GetData<CPropSetCreationData>();
			if (data.m_Hash == "pg_veh_privatedining01x_med"_J || data.m_Hash == 0x3701844F || data.m_Type == -1 || STREAMING::IS_MODEL_A_PED(data.m_Hash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid propset model 0x{:X} from {}", data.m_Hash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("invalid propset crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
				return true;
			}
			break;
		}
		case "CPlayerCreationNode"_J:
		{
			auto& data = node->GetData<CPlayerCreationData>();
			if (!STREAMING::IS_MODEL_A_PED(data.m_Hash))
			{
				LOGF(SYNC, WARNING, "Blocking invalid player creation model 0x{:X} from {}", data.m_Hash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("invalid player creation crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
				// fix the crash instead of rejecting sync
				data.m_Hash = "MP_MALE"_J;
			}
			break;
		}
		case "CProjectileCreationNode"_J:
		{
			auto& data = node->GetData<CProjectileCreationData>();
			if (!WEAPON::IS_WEAPON_VALID(data.m_WeaponHash))
			{
				LOGF(SYNC, WARNING, "Blocking projectile with invalid weapon hash 0x{:X} from {}", data.m_WeaponHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("invalid projectile weapon crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
				return true;
			}
			if (!WEAPON::_IS_AMMO_VALID(data.m_AmmoHash))
			{
				LOGF(SYNC, WARNING, "Blocking projectile with invalid ammo hash 0x{:X} from {}", data.m_AmmoHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("invalid projectile ammo crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
				return true;
			}
			break;
		}
		case "CPlayerGameStateUncommonNode"_J:
		{
			auto& data = node->GetData<CPlayerGameStateUncommonData>();
			if (data.m_IsSpectating && !data.m_IsSpectatingStaticPos)
			{
				auto object = Pointers.GetNetObjectById(data.m_SpectatorId);
				if (object && ((NetObjType)object->m_ObjectType) == NetObjType::Player)
				{
					if (Protections::GetSyncingPlayer())
					{
						auto old_spectator = Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer;
						Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer = object->m_OwnerId;

						if (old_spectator != Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer)
						{
							bool spectating_local = Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer == Self::GetPlayer();
							if (spectating_local)
							{
								Notifications::Show("Protections",
								    std::format("{} is spectating you", Protections::GetSyncingPlayer().GetName()),
								    NotificationType::Warning);
							}

							if (Features::_BlockSpectate.GetState()
							    && (spectating_local || Features::_BlockSpectateSession.GetState())
							    && Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer != Protections::GetSyncingPlayer())
							{
								Network::ForceRemoveNetworkEntity(
								    Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer.GetPed().GetNetworkObjectId(),
								    -1,
								    false,
								    Protections::GetSyncingPlayer());
							}
						}

						Protections::GetSyncingPlayer().AddDetection(Detection::USED_SPECTATE);
					}
				}
				else
				{
					if (Protections::GetSyncingPlayer())
						Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer = nullptr;
				}
			}
			else
			{
				if (Protections::GetSyncingPlayer())
					Protections::GetSyncingPlayer().GetData().m_SpectatingPlayer = nullptr;
			}
			break;
		}
		case "CPickupCreationNode"_J:
		{
			auto& data = node->GetData<CPickupCreationData>();
			if (!OBJECT::_IS_PICKUP_TYPE_VALID(data.m_PickupHash) && !(data.m_PickupHash == 0xFFFFFFFF && data.m_ModelHash == 0) && (data.m_ModelHash != 0 && STREAMING::_IS_MODEL_AN_OBJECT(data.m_ModelHash)))
			{
				LOGF(SYNC, WARNING, "Blocking pickup with invalid hashes (m_PickupHash = 0x{}, m_ModelHash = 0x{}) from {}", data.m_PickupHash, data.m_ModelHash, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("invalid pickup type crash");
				Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
				return true;
			}
			break;
		}
		case "Node_14359d660"_J:
		{
			auto data = (std::uint64_t)&node->GetData<char>();
			for (int i = 0; i < *(int*)(data + 36); i++)
			{
				if (*(int*)(data + 36ULL * i + 72ULL) < *(int*)(data + 36ULL * i + 64ULL))
				{
					LOGF(SYNC, WARNING, "Blocking wanted data array out of bounds range ({} < {}) from ", *(int*)(data + 36ULL * i + 72ULL), *(int*)(data + 36ULL * i + 64ULL), Protections::GetSyncingPlayer().GetName());
					Protections::GetSyncingPlayer().AddDetection(Detection::TRIED_CRASH_PLAYER);
					return true;
				}
			}
			break;
		}
		case "CTrainGameStateUncommonNode"_J:
		{
			auto data = (std::uint64_t)&node->GetData<char>();
			if (*(unsigned char*)(data + 12) >= Pointers.TrainConfigs->m_TrainConfigs.size())
			{
				LOGF(SYNC, WARNING, "Blocking CTrainGameStateUncommonNode out of bounds train config ({} >= {}) from {}", *(unsigned char*)(data + 12), Pointers.TrainConfigs->m_TrainConfigs.size(), Protections::GetSyncingPlayer().GetName());
				SyncBlocked("out of bounds train config index crash");
				DeleteSyncObjectLater(object->m_ObjectId); // delete bad train just in case
				return true;
			}
			break;
		}
		case "CAnimSceneCreationNode"_J:
		{
			auto& data = node->GetData<CAnimSceneCreationData>();
			if (g_BlacklistedAnimScenes.contains(data.m_AnimDict))
			{
				LOGF(SYNC, WARNING, "Blocking animscene 0x{:X} from {} since it's in the blacklist", data.m_AnimDict, Protections::GetSyncingPlayer().GetName());
				SyncBlocked("bad anim scene", GetObjectCreator(object));
				DeleteSyncObject(object->m_ObjectId);
				return true;
			}
			break;
		}
		}

		return false;
	}

	bool SyncNodeVisitor(CProjectBaseSyncDataNode* node, NetObjType type, rage::netObject* object)
	{
		if (node->IsParentNode())
		{
			for (auto child = node->m_FirstChild; child; child = child->m_NextSibling)
			{
				if (SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(child), type, object))
					return true;
			}
		}
		else if (node->IsDataNode())
		{
			if (!node->IsActive())
				return false;

			if (YimMenu::Features::_LogClones.GetState())
				YimMenu::Hooks::Protections::LogSyncNode(node, Nodes::Find((uint64_t)node), type, object, Protections::GetSyncingPlayer());
			return ShouldBlockNode(node, Nodes::Find((uint64_t)node), type, object);
		}

		return false;
	}
}

namespace YimMenu::Hooks::Protections
{
	bool ShouldBlockSync(rage::netSyncTree* tree, NetObjType type, rage::netObject* object)
	{
		Nodes::Init();

		if (g_Running && SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(tree->m_NextSyncNode), type, object))
		{
			return true;
		}

		return false;
	}
}
