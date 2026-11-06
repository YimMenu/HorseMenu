#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaMenuEvent.hpp"
#include "../LuaModule.hpp"


namespace Terminus::LuaJIT
{
	class LuaMenuLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			// clang-format off


			/*@terminus.enum eMenuEvent
			* field ScriptsReloaded<0> Event that triggers when all Lua scripts are reloaded.
			* field HwndProc<1> Event that triggers when a window procedure is called. Refer to [WNDPROC Win32 Apps](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nc-winuser-wndproc) for more information.
			* field PlayerJoin<2> Event that triggers when a player joins the session.
			* field PlayerLeave<3> Event that triggers when a player leaves the session.
			* field ScriptedGameEventReceived<4> Event that triggers when we receive a scripted game event over the network.
			* field ChatMessageReceived<5> Event that triggers when we receive a chat message over the network.
			* field MenuUnloaded<6> Event that triggers when the menu is unloaded.
			@*/
			L.new_enum("eMenuEvent",
				"ScriptsReloaded", eMenuEvent::ScriptsReloaded,
				"HwndProc", eMenuEvent::HwndProc,
				"PlayerJoin", eMenuEvent::PlayerJoin,
				"PlayerLeave", eMenuEvent::PlayerLeave,
				"ScriptedGameEventReceived", eMenuEvent::ScriptedGameEventReceived,
				"ChatMessageReceived", eMenuEvent::ChatMessageReceived,
				"MenuUnloaded", eMenuEvent::MenuUnloaded
			);


			/*@terminus.table Menu
			* description
				The main bridge between Lua and the menu.

				Exposes functions to register menu events, UI tabs and callbacks, commands, etc.
			@*/
			auto menu = L["Menu"].get_or_create<sol::table>();

			/*@terminus.function Menu.RegisterEventHandler
			* param event<eMenuEvent> The event to handle.
			* param callback<function> The function to execute.		
			@*/

			/*@terminus.function Menu.RegisterEventHandler
			* param event<eMenuEvent.HwndProc> The event to handle.
			* param callback<fun(hWnd: integer, uMsg: integer, wParam: integer, lParam: integer)> The function to execute.		
			@*/

			/*@terminus.function Menu.RegisterEventHandler
			* param event<eMenuEvent.PlayerJoin> The event to handle.
			* param callback<fun(playerName: string, playerId: integer)> The function to execute.		
			@*/

			/*@terminus.function Menu.RegisterEventHandler
			* param event<eMenuEvent.PlayerLeave> The event to handle.
			* param callback<fun(playerName: string)> The function to execute.		
			@*/

			/*@terminus.function Menu.RegisterEventHandler
			* param event<eMenuEvent.ScriptedGameEventReceived> The event to handle.
			* param callback<fun(playerId: integer, eventArgs: { [integer]: integer }): boolean> The function to execute.		
			@*/

			/*@terminus.function Menu.RegisterEventHandler
			* param event<eMenuEvent.ChatMessageReceived> The event to handle.
			* param callback<fun(playerId: integer, chatMsg: string)> The function to execute.		
			@*/
			menu["RegisterEventHandler"] = [&](int evnt, sol::protected_function fun) {
				if (auto mod = GetModuleFromLuaState(L))
					mod->m_MenuEventCallbacks[static_cast<eMenuEvent>(evnt)].push_back(fun);
			};

			/*@terminus.function Menu.RegisterImGui Registers an ImGui function to be drawn in the menu.~~NOTE: This is currently a work in progress and each script is only allowed one callback registration.
			* param callback<function>
			@*/
			menu["RegisterImGui"] = [&](sol::protected_function func) {
				auto mod = GetModuleFromLuaState(L);
				if (!mod)
					return;

				if (mod->m_GuiCallback.valid())
				{
					LOGF(WARNING, "Module '{}' already has an ImGui callback!", mod->GetName());
					return;
				}

				mod->m_GuiCallback = std::move(func);
			};

			/*@terminus.function Menu.UnloadThisModule Unloads the caller script.
			* 
			@*/
			menu["UnloadThisModule"] = [&]() {
				if (auto mod = GetModuleFromLuaState(L))
					mod->m_UnloadFromCode = true;
			};
		}
	};

	LuaMenuLib _LuaMenuLib;
}
