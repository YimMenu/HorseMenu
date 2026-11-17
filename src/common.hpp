#pragma once

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
#include <iostream>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <stack>
#include <string_view>
#include <thread>
#include <vector>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>

using namespace al;
#include "core/logger/LogHelper.hpp"

#undef Yield

namespace Terminus
{
	const inline auto SYNC      = std::make_shared<al::LogStream>("SYNC");
	const inline auto NET_EVENT = std::make_shared<al::LogStream>("NET_EVENT");
	const inline auto NETWORK   = std::make_shared<al::LogStream>("NETWORK");
	const inline auto GAME      = std::make_shared<al::LogStream>("GAME");
	const inline auto MENU      = std::make_shared<al::LogStream>("MENU");

	using namespace std::chrono_literals;
	using namespace std::string_literals;
	using namespace std::string_view_literals;

	namespace fs = std::filesystem;

	extern std::atomic<bool> g_Running;
	extern HINSTANCE g_DllInstance;
	extern HANDLE g_MainThread;
	extern DWORD g_MainThreadId;
}