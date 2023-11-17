#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <AsyncLogger/Logger.hpp>
#include <MinHook.h>
#include <Windows.h>
#include <array>
#include <atomic>
#include <chrono>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <functional>
#include <future>
#include <imgui.h>
#include <iostream>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <stack>
#include <string_view>
#include <thread>
#include <vector>

using namespace al;
#include "core/logger/LogHelper.hpp"

#undef Yield

namespace YimMenu
{
	using namespace std::chrono_literals;
	using namespace std::string_literals;

	extern std::atomic<bool> g_Running;
	extern HINSTANCE g_DllInstance;
	extern HANDLE g_MainThread;
	extern DWORD g_MainThreadId;
}