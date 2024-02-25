#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "unordered_set"

#include <rage/rlJson.hpp>
#include <rage/rlMetric.hpp>

namespace YimMenu::Features
{
	BoolCommand _LogMetrics("logmetrics", "Log Metrics", "Log game telemetry");
}

namespace YimMenu::Hooks
{
	bool Anticheat::SendMetric(void* manager, rage::rlMetric* metric)
	{
		const auto bad_metrics = std::unordered_set<std::string_view>({"PCSETTINGS", "CHEAT", "WEATHER", "FIRST_VEH", "HARDWARE_OS", "HARDWARE_CPU", "HARDWARE_GPU", "HARDWARE_MOBO", "HARDWARE_MEM", "CASH_CREATED"});
		char buffer[256]{};
		rage::rlJson serializer(buffer, sizeof(buffer));

		metric->Serialize(&serializer);
		if (bad_metrics.contains(metric->GetName()))
		{
			LOG(INFO) << "BAD METRIC: " << metric->GetName() << "; DATA: " << serializer.GetBuffer();
			return false;
		}

		if (Features::_LogMetrics.GetState())
			LOG(INFO) << "METRIC: " << metric->GetName() << "; DATA: " << serializer.GetBuffer();
		return true;
	}
}