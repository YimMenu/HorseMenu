#include "ContextMenu.hpp"

#include "ContextMenus.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Pools.hpp"

namespace YimMenu::Features
{
	BoolCommand _ContextMenu("ctxmenu", "Context Menu", "Enables a context menu that allows you to perform actions on nearby entities and players");
	BoolCommand _ContextPlayers("ctxmenuplayers", "Show Players", "Should the context menu show players?");
	BoolCommand _ContextPeds("ctxmenupeds", "Show Peds", "Should the context menu show peds?");
	BoolCommand _ContextVehicles("ctxmenuvehicles", "Show Vehicles", "Should the context menu show vehicles?");
	BoolCommand _ContextObjects("ctxmenuobjects", "Show Objects", "Should the context menu show objects?");
}

namespace YimMenu
{
	inline double CumulativeDistanceToMiddleOfScreen(rage::fvector2 screenPos)
	{
		return std::abs(screenPos.x - 0.5) + std::abs(screenPos.y - 0.5);
	}

	inline int GetEntityHandleClosestToMiddleOfScreen(bool includePlayers, bool includePeds, bool includeVehicles, bool includeObjects)
	{
		int closestHandle{};
		float distance = 1;

		auto updateClosestEntity = [&distance, &closestHandle](int handle) -> void {
			auto worldCoords = ENTITY::GET_ENTITY_COORDS(handle, false, true);
			rage::fvector2 screenPos{};
			float worldCoords_[3] = {worldCoords.x, worldCoords.y, worldCoords.z};
			Pointers.WorldToScreen(worldCoords_, &screenPos.x, &screenPos.y);
			if (CumulativeDistanceToMiddleOfScreen(screenPos) < distance && handle != Self::GetPed().GetHandle())
			{
				closestHandle = handle;
				distance      = CumulativeDistanceToMiddleOfScreen(screenPos);
			}
		};

		if (includePlayers && *Pointers.IsSessionStarted)
		{
			for (auto& [id, plyr] : YimMenu::Players::GetPlayers())
			{
				if (plyr.IsValid() || plyr.GetPed().GetPointer<void*>())
					updateClosestEntity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id));
			}
		}

		if (includePeds)
		{
			for (Ped ped : Pools::GetPeds())
			{
				if (ped.IsValid() || ped.GetPointer<void*>())
					updateClosestEntity(ped.GetHandle());
			}
		}

		if (includeVehicles)
		{
			for (Entity veh : Pools::GetVehicles())
			{
				if (veh.IsValid() || veh.GetPointer<void*>())
					updateClosestEntity(veh.GetHandle());
			}
		}

		if (includeObjects)
		{
			for (Entity obj : Pools::GetObjects())
			{
				if (obj.IsValid() || obj.GetPointer<void*>())
					updateClosestEntity(obj.GetHandle());
			}
		}

		return closestHandle;
	}

	void ContextMenu::GameTickImpl()
	{
		if (Features::_ContextMenu.GetState())
		{
			PAD::DISABLE_CONTROL_ACTION(0, (Hash)NativeInputs::INPUT_SWITCH_SHOULDER, true);
			if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (Hash)NativeInputs::INPUT_SWITCH_SHOULDER))
				m_Enabled = !m_Enabled;

			if (m_Enabled)
			{
				auto handle = GetEntityHandleClosestToMiddleOfScreen(Features::_ContextPlayers.GetState(),
				    Features::_ContextPeds.GetState(),
				    Features::_ContextVehicles.GetState(),
				    Features::_ContextObjects.GetState());

				static auto switchToMenu = [&](ContextOperationsMenu menu) -> void {
					if (m_CurrentOperationsMenu != menu)
					{
						m_CurrentOperationsMenu = menu;
					}
				};

				if (handle && ENTITY::DOES_ENTITY_EXIST(handle) && ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(Self::GetPed().GetHandle(), handle, 17))
				{
					m_Entity = handle;

					if (m_Entity.IsPed())
					{
						if (m_Entity.IsPlayer())
							switchToMenu(ContextMenuPlayers);
						else
							switchToMenu(ContextMenuPeds);
					}
					else if (m_Entity.IsVehicle())
					{
						switchToMenu(ContextMenuVehicles); // TODO: Improve Vehicle menu
					}
					else if (m_Entity.IsObject())
					{
						switchToMenu(ContextMenuObjects); // TODO: Improve Objects Menu
					}

					if (m_CurrentOperationsMenu.m_SelectedOperation.m_Name.empty())
						m_CurrentOperationsMenu.m_SelectedOperation = m_CurrentOperationsMenu.m_Operations.front();

					auto entPos           = m_Entity.GetPosition();
					float worldCoords_[3] = {entPos.x, entPos.y, entPos.z};
					Pointers.WorldToScreen(worldCoords_, &m_ScreenPos.x, &m_ScreenPos.y);
					m_ScreenPos.x *= *Pointers.ScreenResX;
					m_ScreenPos.y *= *Pointers.ScreenResY;

					PAD::DISABLE_CONTROL_ACTION(0, (int)NativeInputs::INPUT_NEXT_WEAPON, true);
					PAD::DISABLE_CONTROL_ACTION(0, (int)NativeInputs::INPUT_PREV_WEAPON, true);
					PAD::DISABLE_CONTROL_ACTION(0, (int)NativeInputs::INPUT_ATTACK, true);

					if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (int)NativeInputs::INPUT_PREV_WEAPON))
						m_CurrentOperationsMenu.SelectPrevious();

					if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (int)NativeInputs::INPUT_NEXT_WEAPON))
						m_CurrentOperationsMenu.SelectNext();

					if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (int)NativeInputs::INPUT_ATTACK))
						FiberPool::Push([=] {
							m_CurrentOperationsMenu.m_SelectedOperation.m_Operation(m_Entity);
						});
				}
				else
				{
					m_Entity = nullptr;
				}
			}
		}
	}

	inline void DrawOperation(const ContextMenuOperation& operation, rage::fvector2 screenPos, bool selected, int position, ImDrawList* drawList)
	{
		// Make compatible with ESP
		static auto esp = Commands::GetCommand<BoolCommand>("esp"_J);
		if (esp->GetState())
			screenPos.y += 20;

		if (position > 0)
			screenPos.y += (m_OperationCardY * position) + 2 /* Margin between operation cards */;

		auto cardColor = selected ? ImGui::ColorConvertFloat4ToU32(ImVec4(1, 0, 0, 0.5)) : ImGui::ColorConvertFloat4ToU32(ImVec4(1, 0, 0, 0.2));

		ImVec2 endPos = ImVec2(screenPos.x + m_OperationCardX, screenPos.y + m_OperationCardY);
		drawList->AddRectFilled(ImVec2(screenPos.x, screenPos.y), endPos, cardColor, 3.f);

		drawList->AddText(ImVec2(screenPos.x, screenPos.y),
		    ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)),
		    operation.m_Name.data());
	}

	void ContextMenu::DrawContextMenuImpl()
	{
		if (m_Entity.IsValid() && m_Enabled && Features::_ContextMenu.GetState())
		{
			if (const auto drawList = ImGui::GetBackgroundDrawList())
			{
				int position = 0;
				for (const auto& operation : m_CurrentOperationsMenu.m_Operations)
				{
					DrawOperation(operation, m_ScreenPos, operation == m_CurrentOperationsMenu.m_SelectedOperation, position, drawList);
					position++;
				}
			}
		}
	}
}