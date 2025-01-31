#include "MapControls.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	MapControl::MapControl(NativeInputs control) :
	    m_ControlIndex(control)
	{

	}

	void MapControl::BeginFrame()
	{
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(m_ControlIndex), true);
		m_IsPressed = PAD::IS_DISABLED_CONTROL_PRESSED(0, static_cast<Hash>(m_ControlIndex));
		m_JustPressed = PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, static_cast<Hash>(m_ControlIndex));
		m_JustReleased = PAD::IS_CONTROL_RELEASED(0, static_cast<Hash>(m_ControlIndex));
	}

	void MapControl::EndFrame()
	{
		if (m_PendingExclusiveSubsystem.has_value())
		{
			m_ExclusiveSubsystem = m_PendingExclusiveSubsystem;
			m_PendingExclusiveSubsystem = std::nullopt;
		}
		else
		{
			m_ExclusiveSubsystem = std::nullopt;
		}
	}

	NativeInputs MapControl::GetControlIndex()
	{
		return m_ControlIndex;
	}

	void MapControl::SetExclusive(Subsystem subsystem)
	{
		if (!m_PendingExclusiveSubsystem.has_value())
			m_PendingExclusiveSubsystem = subsystem;
	}

	bool MapControl::HasControl(Subsystem subsystem)
	{
		return !m_ExclusiveSubsystem.has_value() || m_ExclusiveSubsystem.value() == subsystem;
	}

	bool MapControl::IsPressed(Subsystem subsystem)
	{
		return HasControl(subsystem) && m_IsPressed;
	}

	bool MapControl::IsJustPressed(Subsystem subsystem)
	{
		return HasControl(subsystem) && m_JustPressed;
	}

	bool MapControl::IsJustReleased(Subsystem subsystem)
	{
		return HasControl(subsystem) && m_JustReleased;
	}

	void MapControls::BeginFrame()
	{
		// disable misc control actions
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_AIM), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_AIM_IN_AIR), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_SELECT_NEXT_WEAPON), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_PREV_WEAPON), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_ATTACK), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_ATTACK2), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INSPECT), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_ANIMAL), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_LOCKON), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_LOCKON_A), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_LOCKON_NEG), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_LOCKON_POS), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_LOCKON_ROB), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_LOCKON_Y), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_OPTION1), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACT_OPTION2), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_COVER), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_PICKUP), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_SPRINT), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_PICKUP_CARRIABLE), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_OPEN_JOURNAL), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_OPEN_SATCHEL_MENU), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_OPEN_CRAFTING_MENU), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_OPEN_EMOTE_WHEEL), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_OPEN_EMOTE_WHEEL_HORSE), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_MULTIPLAYER_INFO), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_MULTIPLAYER_INFO_PLAYERS), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_INTERACTION_MENU), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_PLAYER_MENU), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_WEAPON_SPECIAL), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_LOOT), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_LOOT2), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_LOOT3), true);
		PAD::DISABLE_CONTROL_ACTION(0, static_cast<Hash>(NativeInputs::INPUT_SELECT_RADAR_MODE), true);

		m_MoveForward.BeginFrame();
		m_MoveBackward.BeginFrame();
		m_MoveLeft.BeginFrame();
		m_MoveRight.BeginFrame();
		m_ZoomIn.BeginFrame();
		m_ZoomOut.BeginFrame();
		m_RotateLeft.BeginFrame();
		m_RotateRight.BeginFrame();
		m_SpeedUp.BeginFrame();
		m_DpadUp.BeginFrame();
		m_DpadDown.BeginFrame();
		m_DpadLeft.BeginFrame();
		m_DpadRight.BeginFrame();
		m_DpadAccept.BeginFrame();
		m_DpadCancel.BeginFrame();
		m_DpadDelete.BeginFrame();
	}

	void MapControls::EndFrame()
	{
		m_MoveForward.EndFrame();
		m_MoveBackward.EndFrame();
		m_MoveLeft.EndFrame();
		m_MoveRight.EndFrame();
		m_ZoomIn.EndFrame();
		m_ZoomOut.EndFrame();
		m_RotateLeft.EndFrame();
		m_RotateRight.EndFrame();
		m_SpeedUp.EndFrame();
		m_DpadUp.EndFrame();
		m_DpadDown.EndFrame();
		m_DpadLeft.EndFrame();
		m_DpadRight.EndFrame();
		m_DpadAccept.EndFrame();
		m_DpadCancel.EndFrame();
		m_DpadDelete.EndFrame();
	}
}