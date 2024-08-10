#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "unordered_set"

#include <rage/rlJson.hpp>
#include <rage/rlMetric.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogMetrics("logmetrics", "Log Metrics", "Log game telemetry");
	BoolCommand _BlockAllTelemetry("blockalltelemetry", "Block All Telemetry", "Block all game telemetry");
}

namespace YimMenu::Hooks
{
	bool Anticheat::SendMetric(void* manager, rage::rlMetric* metric)
	{
		static auto bad_metrics = std::unordered_set<std::string_view>({"PCSETTINGS", "CHEAT", "WEATHER", "FIRST_VEH", "HARDWARE_OS", "HARDWARE_CPU", "HARDWARE_GPU", "HARDWARE_MOBO", "HARDWARE_MEM", "CASH_CREATED", "PELLETDROPS", "GAMESERVER_TXN_CLAIMLOOT"});
		char buffer[256]{};
		rage::rlJson serializer(buffer, sizeof(buffer));

		metric->Serialize(&serializer);
		auto metric_name = metric->GetName();
		if (bad_metrics.contains(metric_name))
		{
			LOG(INFO) << "BAD METRIC: " << metric_name << "; DATA: " << serializer.GetBuffer();
			return false;
		}

		if (Features::_LogMetrics.GetState())
			LOG(INFO) << "METRIC: " << metric_name << "; DATA: " << serializer.GetBuffer();

		if (Features::_BlockAllTelemetry.GetState())
		{
			return true;
		}

		return BaseHook::Get<Anticheat::SendMetric, DetourHook<decltype(&Anticheat::SendMetric)>>()->Original()(manager, metric);
	}
}
