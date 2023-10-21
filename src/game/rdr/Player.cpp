#include "Player.hpp"

#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <player/CPlayerInfo.hpp>

namespace YimMenu
{
	bool Player::IsValid()
	{
		if (m_NetPlayer && m_NetPlayer->IsValid())
			m_Handle = m_NetPlayer->m_ActiveIndex;
		else
			return false;

		return true;
	}

	int Player::GetId()
	{
		if (!IsValid())
			return 255;

		return m_NetPlayer->m_PlayerIndex;
	}

	const char* Player::GetName()
	{
		if (!IsValid())
			return "Null Player!";

		return m_NetPlayer->GetName();
	}

	CNetGamePlayer* Player::GetHandle()
	{
		return Pointers.GetNetPlayerFromPid(m_Handle);
	}

	rage::rlGamerInfo* Player::GetGamerInfo()
	{
		if (!IsValid())
			return nullptr;

		return m_NetPlayer->GetGamerInfo();
	}

	Entity Player::GetPed()
	{
		if (!IsValid() || !m_NetPlayer->m_PlayerInfo)
			return nullptr;

		return m_NetPlayer->m_PlayerInfo->m_Ped;
	}

	bool Player::operator==(Player other)
	{
		return m_NetPlayer == other.m_NetPlayer;
	}

	BoneCoords Player::GetBoneCoords()
	{
		if (!IsValid())
			return BoneCoords();

		return m_BoneCoords;
	}

	void Player::UpdateBoneCoords()
	{
		if (!IsValid() || !m_NetPlayer || !m_NetPlayer->m_PlayerInfo)
			return;

		auto ped = m_NetPlayer->m_PlayerInfo->m_Ped;

		if (!ped || !ENTITY::DOES_ENTITY_EXIST(GetPed().GetHandle()))
			return;
			
		//TODO possibly fetch info from CPed class directly
		m_BoneCoords.Head      = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 21030, 0, 0, 0);
		m_BoneCoords.Neck      = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 14283, 0, 0, 0);
		m_BoneCoords.Torso     = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 14410, 0, 0, 0);
		m_BoneCoords.LeftHand  = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 34606, 0, 0, 0);
		m_BoneCoords.RightHand = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 22798, 0, 0, 0);
		m_BoneCoords.LeftFoot  = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 45454, 0, 0, 0);
		m_BoneCoords.RightFoot = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 33646, 0, 0, 0);
		m_BoneCoords.LeftElbow = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 22711, 0, 0, 0);
		m_BoneCoords.RightElbow = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 2992, 0, 0, 0);
		m_BoneCoords.LeftKnee   = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 22173, 0, 0, 0);
		m_BoneCoords.RightKnee  = PED::GET_PED_BONE_COORDS(GetPed().GetHandle(), 63133, 0, 0, 0);
	}
}