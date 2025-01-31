#pragma once
#include "game/rdr/Enums.hpp"

// TODO: way too much code duplication in this component
namespace YimMenu
{
	class MapControl
	{
	public:
		enum class Subsystem
		{
			MAIN,
			CAMERA,
			SELECTION,
			UI
		};

	private:
		NativeInputs m_ControlIndex;
		std::optional<Subsystem> m_ExclusiveSubsystem = std::nullopt;
		std::optional<Subsystem> m_PendingExclusiveSubsystem = std::nullopt;
		bool m_IsPressed = false;
		bool m_JustPressed = false;
		bool m_JustReleased = false;

	public:
		MapControl(NativeInputs control);

		void BeginFrame();
		void EndFrame();

		NativeInputs GetControlIndex();

		void SetExclusive(Subsystem subsystem);
		bool HasControl(Subsystem subsystem);
		bool IsPressed(Subsystem subsystem);
		bool IsJustPressed(Subsystem subsystem);
		bool IsJustReleased(Subsystem subsystem);
	};

	class MapControls
	{
		MapControl m_MoveForward{NativeInputs::INPUT_MOVE_UP_ONLY};
		MapControl m_MoveBackward{NativeInputs::INPUT_MOVE_DOWN_ONLY};
		MapControl m_MoveLeft{NativeInputs::INPUT_MOVE_LEFT_ONLY};
		MapControl m_MoveRight{NativeInputs::INPUT_MOVE_RIGHT_ONLY};
		MapControl m_ZoomIn{NativeInputs::INPUT_CREATOR_RT};
		MapControl m_ZoomOut{NativeInputs::INPUT_CREATOR_LT};
		MapControl m_RotateLeft{NativeInputs::INPUT_FRONTEND_LB};
		MapControl m_RotateRight{NativeInputs::INPUT_FRONTEND_RB};
		MapControl m_SpeedUp{NativeInputs::INPUT_FRONTEND_Y};

		MapControl m_DpadUp{NativeInputs::INPUT_GAME_MENU_UP};
		MapControl m_DpadDown{NativeInputs::INPUT_GAME_MENU_DOWN};
		MapControl m_DpadLeft{NativeInputs::INPUT_GAME_MENU_LEFT};
		MapControl m_DpadRight{NativeInputs::INPUT_GAME_MENU_RIGHT};
		MapControl m_DpadAccept{NativeInputs::INPUT_GAME_MENU_ACCEPT};
		MapControl m_DpadCancel{NativeInputs::INPUT_GAME_MENU_CANCEL};
		MapControl m_DpadDelete{NativeInputs::INPUT_FRONTEND_DELETE};

	public:
		// (camera) movement
		MapControl& GetMoveForward() { return m_MoveForward; };
		MapControl& GetMoveBackward() { return m_MoveBackward; };
		MapControl& GetMoveLeft() { return m_MoveLeft; };
		MapControl& GetMoveRight() { return m_MoveRight; };
		MapControl& GetZoomIn() { return m_ZoomIn; };
		MapControl& GetZoomOut() { return m_ZoomOut; };
		MapControl& GetRotateLeft() { return m_RotateLeft; };
		MapControl& GetRotateRight() { return m_RotateRight; };
		MapControl& GetSpeedUp(){ return m_SpeedUp; }

		// dpad controls
		MapControl& GetDpadUp() { return m_DpadUp; };
		MapControl& GetDpadDown() { return m_DpadDown; };
		MapControl& GetDpadLeft() { return m_DpadLeft; };
		MapControl& GetDpadRight() { return m_DpadRight; };
		MapControl& GetDpadAccept() { return m_DpadAccept; };
		MapControl& GetDpadCancel() { return m_DpadCancel; };
		MapControl& GetDpadDelete() { return m_DpadDelete; };

		void BeginFrame();
		void EndFrame();
	};
}