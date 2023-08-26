#pragma once
#include "util/Joaat.hpp"

namespace rage
{
	class scrThread;
}

namespace YimMenu::Scripts
{
	rage::scrThread* FindScriptThread(joaat_t hash);
	void RunAsScript(rage::scrThread* thread, std::function<void()> callback);
}