#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include <rage/rlMetric.hpp>
#include <rage/rlJson.hpp>

namespace YimMenu::Hooks
{
	bool Anticheat::SendMetric(void* manager, rage::rlMetric* metric)
	{
		char buffer[256]{};
		rage::rlJson serializer(buffer, sizeof(buffer));

		metric->Serialize(&serializer);

		LOG(INFO) << "METRIC: " << metric->GetName() << "; DATA: " << serializer.GetBuffer();
		return true;
	}
}