#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "core/commands/BoolCommand.hpp"
#include <rage/rlMetric.hpp>
#include <rage/rlJson.hpp>

namespace YimMenu::Features
{
	BoolCommand _LogMetrics("logmetrics", "Log Metrics", "Log game telemetry");
}

namespace YimMenu::Hooks
{
	bool Anticheat::SendMetric(void* manager, rage::rlMetric* metric)
	{
		char buffer[256]{};
		rage::rlJson serializer(buffer, sizeof(buffer));

		metric->Serialize(&serializer);

		if (Features::_LogMetrics.GetState())
			LOG(INFO) << "METRIC: " << metric->GetName() << "; DATA: " << serializer.GetBuffer();
		return true;
	}
}