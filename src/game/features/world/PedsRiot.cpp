#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Pools.hpp"
#include "game/rdr/data/WeaponTypes.hpp"

namespace Terminus::Features
{
	static BoolCommand _PlayersFriendly{"pedsriotfriendly", "Friendly", "Makes peds treat players as respected", false};
	static BoolCommand _UseWeapons{"pedsriotweapons", "Weapons", "Give all peds a random weapon", false};
	static BoolCommand _UseGodmode{"pedsriotgodmode", "Godmode", "Makes all peds invincible", false};
	static BoolCommand _TargetOnlyAnimals{"pedsriotonlyanimals", "Only Animals Riot", "Makes only Animals riot, ignoring pedestrians", false};
	static BoolCommand _TargetOnlyPeds{"pedsriotonlypeds", "Only Peds Riot", "Makes only Peds riot, ignoring animals", false};

	static const char* GetRandomNonMPWeapon()
	{
		static std::vector<const char*> validWeapons;

		if (validWeapons.empty()) // Build the list once
		{
			for (int i = 0; i < Data::g_WeaponTypesCount; i++)
			{
				const char* weapon = Data::g_WeaponTypes[i];
				std::string weaponStr(weapon);

				// Exclude _MP weapons AND non-combat items
				if (weaponStr.find("_MP") == std::string::npos && weaponStr.find("KIT_") == std::string::npos && // Binoculars, Camera, Detectors
				    weaponStr.find("FISHINGROD") == std::string::npos && // Fishing Rod
				    weaponStr.find("LANTERN") == std::string::npos &&    // Lanterns
				    weaponStr.find("TORCH") == std::string::npos &&      // Torches
				    weaponStr.find("DETECTOR") == std::string::npos &&   // Metal Detector
				    weaponStr.find("BINOCULARS") == std::string::npos && // Binoculars
				    weaponStr.find("CAMERA") == std::string::npos)
				{
					validWeapons.push_back(weapon);
				}
			}
		}

		// Return a random weapon from the valid list
		if (!validWeapons.empty())
		{
			int randomIndex = rand() % validWeapons.size();
			return validWeapons[randomIndex];
		}

		// Fallback weapon (should never happen)
		return "WEAPON_THROWN_DYNAMITE";
	}

	static void ApplyCombatAttributes(int ped)
	{
		PED::SET_PED_COMBAT_ATTRIBUTES(ped, 5, 1);
		PED::SET_PED_COMBAT_ATTRIBUTES(ped, 17, 0);
		PED::SET_PED_COMBAT_ATTRIBUTES(ped, 50, 1);
		PED::SET_PED_COMBAT_ATTRIBUTES(ped, 114, 1);
		PED::SET_PED_COMBAT_ATTRIBUTES(ped, 58, 1);
		PED::SET_PED_COMBAT_MOVEMENT(ped, 3);
		PED::SET_PED_COMBAT_ABILITY(ped, 3);
		PED::SET_PED_COMBAT_RANGE(ped, 100000);
		PED::SET_PED_CONFIG_FLAG(ped, 24, 0);
		PED::SET_PED_CONFIG_FLAG(ped, 8, 1);
		PED::SET_PED_CONFIG_FLAG(ped, 40, 1);
		PED::SET_PED_CONFIG_FLAG(ped, 569, 1);
		PED::SET_PED_ACCURACY(ped, 100);
		WEAPON::SET_PED_DROPS_WEAPONS_WHEN_DEAD(ped, 0);
	}

	static void RegisterHatedTargets(int ped)
	{
		PED::_REGISTER_HATED_TARGETS_IN_AREA(ped, 0.0f, 0.0f, 0.0f, 100000.0f);
		PED::REGISTER_HATED_TARGETS_AROUND_PED(ped, 100000.0f);
	}

	static void RemovePedWeapons(int ped)
	{
		WEAPON::REMOVE_ALL_PED_WEAPONS(ped, 1, 0);
		Hash currentPedWeapon = WEAPON::_GET_PED_CURRENT_HELD_WEAPON(ped);
		WEAPON::REMOVE_WEAPON_FROM_PED(ped, currentPedWeapon, 1, "REMOVE_REASON_DROPPED"_J);
	}

	class PedsRiot : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			for (auto npcs : Pools::GetPeds())
			{
				// Check if ped is an animal or player
				int pedType = PED::_GET_META_PED_TYPE(npcs.GetHandle());
				bool isAnimal = (pedType == 3) || (pedType == 4); // MPT_ANIMAL = 3, MPT_NONE = 4
				bool isPedestrian = (pedType == 0) || (pedType == 1) || (pedType == 2); // MPT_MALE = 0, MPT_FEMALE = 1, MPT_TEEN = 2

				bool isPlayer = npcs.IsPlayer();
				Hash playerGroup = "REL_NO_RELATIONSHIP"_J;
				if (isPlayer)
				{
					playerGroup = PED::GET_PED_RELATIONSHIP_GROUP_HASH(npcs.GetHandle());
				}
				else
				{
					// For non-player peds, get the local player's group
					auto localPed = Self::GetPed();
					if (localPed)
						playerGroup = PED::GET_PED_RELATIONSHIP_GROUP_HASH(localPed.GetHandle());
				}

				Hash hasWeapon = WEAPON::_GET_PED_CURRENT_HELD_WEAPON(npcs.GetHandle());
				bool isUnarmed = (hasWeapon == 0 || hasWeapon == Joaat("WEAPON_UNARMED"));

				const char* randomWeapon = GetRandomNonMPWeapon();
				Hash riotGroup = "REL_CRIMINALS"_J;
				Hash defaultGroup = PED::GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(npcs.GetHandle());

				if (isPlayer)
					continue;

				npcs.ForceControl();

				bool isPedDeadOrDying = PED::IS_PED_DEAD_OR_DYING(npcs.GetHandle(), false);
				bool isPedInjured = PED::IS_PED_INJURED(npcs.GetHandle());
				bool isPedInWrithe = TASK::IS_PED_IN_WRITHE(npcs.GetHandle());
				bool isPedHolstering = WEAPON::_IS_WEAPON_HOLSTER_STATE_CHANGING(npcs.GetHandle());

				if (_TargetOnlyAnimals.GetState() && _TargetOnlyPeds.GetState())
				{
					_TargetOnlyAnimals.SetState(false);
					_TargetOnlyPeds.SetState(false); // No need to clutter the loop with whats already default
				}

				if (_TargetOnlyAnimals.GetState() && !isAnimal)
					continue;
				if (_TargetOnlyPeds.GetState() && !isPedestrian)
					continue;

				PED::SET_PED_RELATIONSHIP_GROUP_HASH(npcs.GetHandle(), riotGroup);

				if (_PlayersFriendly.GetState())
				{
					// Friendly mode: Peds respect players but attack each other
					PED::SET_RELATIONSHIP_BETWEEN_GROUPS(1, riotGroup, playerGroup);
					PED::SET_RELATIONSHIP_BETWEEN_GROUPS(6, riotGroup, riotGroup);
				}
				else
				{
					// Aggressive mode: Peds hate everyone
					PED::SET_RELATIONSHIP_BETWEEN_GROUPS(6, riotGroup, riotGroup);
					PED::SET_RELATIONSHIP_BETWEEN_GROUPS(6, riotGroup, playerGroup);
					PED::_SET_PED_INTERACTION_PERSONALITY(npcs.GetHandle(), "AGGRESSIVE"_J);
					PED::_SET_PED_PERSONALITY(npcs.GetHandle(), "BOUNTY_HUNTER"_J);
				}

				ApplyCombatAttributes(npcs.GetHandle());
				RegisterHatedTargets(npcs.GetHandle());

				// Godmode toggle
				if (!isPlayer)
				{
					ENTITY::SET_ENTITY_INVINCIBLE(npcs.GetHandle(), _UseGodmode.GetState() ? 1 : 0);
				}

				// Weapon logic
				bool isCop = (defaultGroup == "REL_COP"_J || defaultGroup == "REL_PINKERTONS"_J || defaultGroup == "REL_GUAMA_LAW"_J);

				if (_UseWeapons.GetState() && isUnarmed && !isPedHolstering && !isCop && !isPedDeadOrDying && !isPedInjured && !isPedInWrithe)
				{
					WEAPON::GIVE_WEAPON_TO_PED(npcs.GetHandle(),
					    Joaat(randomWeapon),
					    9999, // Ammo
					    1,    // Equip immediately
					    0,
					    0,
					    1,
					    0,
					    0,
					    0,
					    0,
					    0,
					    0);
					WEAPON::SET_PED_DROPS_WEAPONS_WHEN_DEAD(npcs.GetHandle(), false);
				}
				else if (_UseWeapons.GetState() && (isPedDeadOrDying || isPedInjured || isPedInWrithe))
				{
					// Remove weapons from dead/dying/injured peds
					RemovePedWeapons(npcs.GetHandle());
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(npcs.GetModel());
				}
				else if (!_UseWeapons.GetState() && !isCop)
				{
					// Remove weapons when toggle is off (except cops)
					RemovePedWeapons(npcs.GetHandle());
				}
			}
		}
	};

	static PedsRiot _PedsRiot{"pedsriot", "Peds Riot", "Make peds/animals riot with various options"};
}