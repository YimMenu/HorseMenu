#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepHorseCoresFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto mount = Self::GetMount();
			if (!mount || mount.IsDead())
				return;

			auto health_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(mount.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_HEALTH);
			auto stamina_care = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(mount.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_STAMINA);

			if (health_core < 100)
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(mount.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
			if (stamina_care < 100)
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(mount.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
		}
	};

	static KeepHorseCoresFilled _KeepHorseCoresFilled{"keephorsecoresfilled", "Keep Horse Cores Filled", "Keeps your horse's Health, Stamina and Deadeye cores filled"};
}