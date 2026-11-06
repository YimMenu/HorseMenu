#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/rdr/Entity.hpp"
#include "game/rdr/Ped.hpp"
#include "game/rdr/Vehicle.hpp"
#include "game/rdr/Player.hpp"
#include <script/globals/PlayerStatusSyncData.hpp>


namespace Terminus::LuaJIT
{
	class LuaEntitiyLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.class Entity
			* description
				A class representing a game entity.

			* constructor __call
			* param handle<integer> The RAGE script handle of the entity.
			
			* method IsValid
			* return boolean
			
			* method IsDead
			* return boolean
			
			* method IsPed
			* return boolean
			
			* method IsVehicle
			* return boolean
			
			* method IsObject
			* return boolean
			
			* method IsPlayer
			* return boolean
			
			* method IsAnimal
			* return boolean
			
			* method IsMissionEntity
			* return boolean
			
			* method IsNetworked
			* return boolean
			
			* method IsVisible
			* return boolean
			
			* method IsInvincible
			* return boolean
			
			* method HasInterior
			* return boolean
			
			* method GetHandle
			* return integer handle RAGE script handle
			
			* method GetAlpha
			* return integer alpha Current transparency value (0-255)
			
			* method SetAlpha
			* param alpha<integer> Transparency value (0-255)
			
			* method ResetAlpha Restores the entity's default alpha value.
			*
			
			* method GetPosition
			* return Vector3 pos the entity's current coordinates.
			
			* method SetPosition
			* param pos<Vector3>
			
			* method GetRotation
			* param order<integer?> The order of rotation (0 = XYZ, 1 = XZY, 2 = YXZ, 3 = YZX, 4 = ZXY, 5 = ZYX). Defaults to 2
			* return Vector3 rot the entity's current rotation vector.
			
			* method SetRotation
			* param rot<Vector3>
			* param order<integer?> The order of rotation (0 = XYZ, 1 = XZY, 2 = YXZ, 3 = YZX, 4 = ZXY, 5 = ZYX). Defaults to 2
			
			* method GetVelocity
			* return Vector3 velocity
			
			* method SetVelocity
			* param vel<Vector3>
			
			* method GetModel
			* return integer hash Entity model hash.
			
			* method GetMaxHealth
			* return number maxHp
			
			* method GetHealth
			* return number hp
			
			* method SetHealth **WARNING:** Do not use this method on other players.
			* param hp<number>
			
			* method SetCollision **WARNING:** Do not use this method on other players.
			* param enabled<boolean>
			
			* method SetFrozen **WARNING:** Do not use this method on other players.
			* param enabled<boolean>
			
			* method SetInvincible **WARNING:** Do not use this method on other players.
			* param enabled<boolean>
			
			* method Kill **WARNING:** Do not use this method on players.
			*
			
			* method Delete **WARNING:** Do not use this method on players.
			*
			@*/
			auto entity = L.new_usertype<Entity>("Entity", 
				sol::call_constructor, sol::constructors<Entity(int)>(),

				sol::meta_function::equal_to, &Entity::operator==,

			    sol::meta_function::to_string, [](Entity& self) {
				    return std::to_string(self.GetHandle());
			    },

				// clang-format off
				"IsValid",         &Entity::IsValid,
			    "IsDead",          &Entity::IsDead,
				"IsPed",           &Entity::IsPed,
				"IsVehicle",       &Entity::IsVehicle,
				"IsObject",        &Entity::IsObject,
				"IsPlayer",        &Entity::IsPlayer,
				"IsAnimal",        &Entity::IsAnimal,
				"IsMissionEntity", &Entity::IsMissionEntity,
				"IsNetworked",     &Entity::IsNetworked,
				"IsVisible",       &Entity::IsVisible,
				"IsInvincible",    &Entity::IsInvincible,

				"HasInterior",   &Entity::HasInterior,

				"GetHandle",     &Entity::GetHandle,

				"GetAlpha",      &Entity::GetAlpha,
				"SetAlpha",      &Entity::SetAlpha,
				"ResetAlpha",    &Entity::ResetAlpha,

				"GetModel",      &Entity::GetModel,

				"GetMaxHealth",  &Entity::GetMaxHealth,
				"GetHealth",     &Entity::GetHealth,
				"SetHealth",     &Entity::SetHealth,

				"SetCollision",  &Entity::SetCollision,
				"SetFrozen",     &Entity::SetFrozen,
				"SetInvincible", &Entity::SetInvincible,

				"Kill",          &Entity::Kill,
				"Delete",        &Entity::Delete
				// clag-format on
			);

			entity["GetVelocity"] = [](Entity& self) {
				return Vector3(self.GetVelocity());
			};

			entity["SetVelocity"] = [](Entity& self, Vector3& vel) {
				self.SetVelocity(vel);
			};

			entity["GetPosition"] = [](Entity& self) {
				return Vector3(self.GetPosition());
			};

			entity["SetPosition"] = [](Entity& self, Vector3& pos) {
				self.SetPosition(pos);
			};

			entity["GetRotation"] = [](Entity& self, sol::optional<int> order) {
				return Vector3(self.GetRotation(order.value_or(2)));
			};

			entity["SetRotation"] = [](Entity& self, Vector3& rot, sol::optional<int> order) {
				return self.SetRotation(rot, order.value_or(2));
			};

			/*@terminus.class Vehicle : Entity
			* description
				A class representing a game vehicle.

			* constructor __call
			* param handle<integer> The RAGE script handle of the vehicle.
			
			* method IsDraft
			* return boolean isDraft Whether this vehicle is a draft animal vehicle.
			
			* method GetNumDraftAnimals
			* return integer numDrafts Number of draft animals attached to this vehicle.
			
			* method GetPedInHarness
			* param slot<integer> The harness slot index (0-5).
			* return Ped ped The ped in the specified harness slot, if any.
			@*/
			L.new_usertype<Vehicle>("Vehicle",
				// clag-format off
				sol::call_constructor, sol::constructors<Vehicle(int)>(),
				sol::base_classes,     sol::bases<Entity>(),

				"IsDraft",            &Vehicle::IsDraft,
				"GetNumDraftAnimals", &Vehicle::GetNumDraftAnimals,
				"GetPedInHarness",    &Vehicle::GetPedInHarness
			);

			/*@terminus.class Ped : Entity
			* description
				A class representing a game ped.

			* constructor __call
			* param handle<integer> The RAGE script handle of the ped.
			
			* method IsEnemy
			* return boolean
			
			* method GetMount
			* return Ped mount The ped's current mount, if any.
			
			* method GetLastMount
			* return Ped mount The ped's last mount, if any.
			
			* method GetVehicle
			* return Vehicle vehicle The ped's current vehicle, if any.
			
			* method GetMaxStamina
			* return number
			
			* method GetStamina
			* return number
			
			* method SetStamina
			* param value<number>
			
			* method GetRagdoll
			* return boolean
			
			* method SetRagdoll
			* param enabled<boolean>
			
			* method GetBonePosition
			* param bone<integer> The bone index.
			* return Vector3 bonePos The world position of the specified bone.
			@*/
			L.new_usertype<Ped>("Ped",
				// clag-format off
				sol::call_constructor, sol::constructors<Ped(int)>(),
				sol::base_classes,     sol::bases<Entity>(),

				"IsEnemy", &Ped::IsEnemy,

				"GetMount",      &Ped::GetMount,
				"GetLastMount",  &Ped::GetLastMount,
				"GetVehicle",    &Ped::GetVehicle,

				"GetMaxStamina", &Ped::GetMaxStamina,
				"GetStamina",    &Ped::GetStamina,
				"SetStamina",    &Ped::SetStamina,

				"GetRagdoll",    &Ped::GetRagdoll,
				"SetRagdoll",    &Ped::SetRagdoll,

				"GetBonePosition", [](Ped& self, const int& bone) {
					return Vector3(self.GetBonePosition(bone));
				}
				// clag-format on
			);

			/*@terminus.class Player
			* description
				A class representing a network player.

			* constructor __call
			* param pid<integer> The player's ID (0-31).
			
			* method IsValid
			* return boolean
			
			* method IsModder
			* return boolean
			
			* method IsHost
			* return boolean
			
			* method IsFriend
			* return boolean
			
			* method GetName
			* return string
			
			* method GetId
			* return integer pid The player's ID (0-31).
			
			* method GetRID
			* return integer rid The player's Rockstar ID.
			
			* method GetPed
			* return Ped ped The player's [Ped](lua://Ped) class instance.
			
			* method GetRank
			* return integer ped The player's current rank.
			
			* method GetHonor
			* return integer ped The player's current honor.
			
			* method GetRegionIndex
			* return integer region The player's current region number.
			
			* method GetRegionName
			* return string region The player's current region name.
			
			* method GetDistrictIndex
			* return integer district The player's camp location index.
			
			* method GetDistrictName
			* return string district The player's camp location name.
			
			* method GetLanguageIndex
			* return integer lang The player's current language index.
			
			* method GetLanguageName
			* return string lang The player's current language name.
			@*/
			auto player = L.new_usertype<Player>("Player",
				// clag-format off
				sol::call_constructor, sol::constructors<Player(int)>(),

				"IsValid",  &Player::IsValid,
				"IsModder", &Player::IsModder,
				"IsHost",   &Player::IsHost,
				"IsFriend", &Player::IsFriend,

				"GetName",  &Player::GetName,
				"GetId",    &Player::GetId,
				"GetRID",   &Player::GetRID,
				"GetPed",   &Player::GetPed,
				"GetRank",  &Player::GetRank,
				"GetHonor", &Player::GetHonor
			);

			player["GetRegionIndex"] = [](Player& self) {
				return static_cast<int>(self.GetRegion());
			};

			player["GetRegionName"] = [](Player& self) {
				auto region = self.GetRegion();
				if (auto it = g_RegionMap.find(region); it != g_RegionMap.end())
					return it->second;

				return std::string("Unknown");
			};

			player["GetDistrictIndex"] = [](Player& self) {
				return static_cast<int>(self.GetDistrict());
			};

			player["GetDistrictName"] = [](Player& self) {
				auto district = self.GetDistrict();
				if (auto it = g_DistrictMap.find(district); it != g_DistrictMap.end())
					return it->second;

				return std::string("Unknown");
			};

			player["GetLanguageIndex"] = [](Player& self) {
				return static_cast<int>(self.GetLanguage());
			};

			player["GetLanguageName"] = [](Player& self) {
				auto idx = self.GetLanguage();
				if (auto it = g_LanguageMap.find(idx); it != g_LanguageMap.end())
					return it->second;

				return std::string("Unknown");
			};
		}
	};

	LuaEntitiyLib _LuaEntitiyLib;
}
