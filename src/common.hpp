#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS

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
	const inline auto SYNC = std::make_shared<al::LogStream>("SYNC");
	const inline auto NET_EVENT = std::make_shared<al::LogStream>("NET_EVENT");
	const inline auto NETWORK = std::make_shared<al::LogStream>("NETWORK");
	const inline auto GAME = std::make_shared<al::LogStream>("GAME");
	const inline auto MENU = std::make_shared<al::LogStream>("MENU");

	using namespace std::chrono_literals;
	using namespace std::string_literals;
	using namespace std::string_view_literals;

	extern std::atomic<bool> g_Running;
	extern HINSTANCE g_DllInstance;
	extern HANDLE g_MainThread;
	extern DWORD g_MainThreadId;
}