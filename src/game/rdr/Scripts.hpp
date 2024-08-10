#pragma once
#include "util/Joaat.hpp"

namespace rage
{
	class scrThread;
	class scrProgram;
}

namespace YimMenu::Scripts
{
	extern rage::scrThread* FindScriptThread(joaat_t hash);
	extern rage::scrProgram* FindScriptProgram(joaat_t hash);
	extern void RunAsScript(rage::scrThread* thread, std::function<void()> callback);
	extern void SendScriptEvent(uint64_t* data, int count, int metadataIndex, int bits);
	extern const char* GetScriptName(joaat_t hash);
	extern void ForceScriptHost(rage::scrThread* thread);
	extern bool RequestScript(joaat_t script);
	extern bool UsingMPScripts();
}