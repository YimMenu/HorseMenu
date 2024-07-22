#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{

	class TpToTrainTrack : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			auto pos = Self::GetPed().GetPosition();
			rage::fvector3 track = VEHICLE::_GET_NEAREST_TRAIN_TRACK_POSITION(pos.x, pos.y, pos.z);
			Teleport::TeleportEntity(Self::GetPed().GetHandle(), track, false);
		}
	};

	static TpToTrainTrack _TpToTrainTrack{"tptotraintrack", "Teleport To Train Track", "Teleport to the nearest train track"};
}