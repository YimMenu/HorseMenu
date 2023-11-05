#include "ContextMenu.hpp"

#include "ContextMenus.hpp"
#include "game/backend/Players.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/backend/FiberPool.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"

namespace YimMenu::Features
{
	BoolCommand _ContextMenu("ctxmenu", "Context Menu", "Enables a context menu that allows you to perform actions on nearby entities and players");
}

namespace YimMenu
{
	inline double CumulativeDistanceToMiddleOfScreen(rage::fvector2 screenPos)
	{
		return std::abs(screenPos.x - 0.5) + std::abs(screenPos.y - 0.5);
	}

	inline int GetEntityHandleClosestToMiddleOfScreen(bool includePlayers, bool includePeds = false, bool includeVehicles = false, bool includeObjects = false)
	{
		int closestHandle{};
		float distance = 1;

		auto updateClosestEntity = [&distance, &closestHandle](int handle) -> void {
			auto worldCoords = ENTITY::GET_ENTITY_COORDS(handle, false, true);
			rage::fvector2 screenPos{};
			float worldCoords_[3] = {worldCoords.x, worldCoords.y, worldCoords.z};
			Pointers.WorldToScreen(worldCoords_, &screenPos.x, &screenPos.y);
			if (CumulativeDistanceToMiddleOfScreen(screenPos) < distance && handle != Self::PlayerPed)
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

		return closestHandle;
	}

	void ContextMenu::GameTickImpl()
	{
		if (Features::_ContextMenu.GetState())
		{
			PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_SWITCH_SHOULDER, true);
			if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (Hash)eNativeInputs::INPUT_SWITCH_SHOULDER))
				m_Enabled = !m_Enabled;

			if (m_Enabled)
			{
				auto handle = GetEntityHandleClosestToMiddleOfScreen(true);

				static auto switchToMenu = [&](ContextOperationsMenu menu) -> void {
					if (m_CurrentOperationsMenu != menu)
					{
						m_CurrentOperationsMenu = menu;
					}
				};

				if (handle && ENTITY::DOES_ENTITY_EXIST(handle))
				{
					m_Entity = handle;

					if (m_Entity.IsPed())
					{
						if (m_Entity.IsPlayer())
							switchToMenu(ContextMenuPlayers);
						else
							switchToMenu(ContextMenuDefault); // TODO: Create Ped menu
					}
					else if (m_Entity.IsVehicle())
					{
						switchToMenu(ContextMenuDefault); // TODO: Create Vehicle menu
					}
					else if (m_Entity.IsObject())
					{
						switchToMenu(ContextMenuDefault); // TODO: Create Object menu
					}

					if (m_CurrentOperationsMenu.m_SelectedOperation.m_Name.empty())
						m_CurrentOperationsMenu.m_SelectedOperation = m_CurrentOperationsMenu.m_Operations.front();

					auto entPos           = m_Entity.GetPosition();
					float worldCoords_[3] = {entPos.x, entPos.y, entPos.z};
					Pointers.WorldToScreen(worldCoords_, &m_ScreenPos.x, &m_ScreenPos.y);
					m_ScreenPos.x *= Pointers.ScreenResX;
					m_ScreenPos.y *= Pointers.ScreenResY;

					PAD::DISABLE_CONTROL_ACTION(0, (int)eNativeInputs::INPUT_NEXT_WEAPON, true);
					PAD::DISABLE_CONTROL_ACTION(0, (int)eNativeInputs::INPUT_PREV_WEAPON, true);
					PAD::DISABLE_CONTROL_ACTION(0, (int)eNativeInputs::INPUT_ATTACK, true);

					if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (int)eNativeInputs::INPUT_PREV_WEAPON))
						m_CurrentOperationsMenu.SelectPrevious();

					if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (int)eNativeInputs::INPUT_NEXT_WEAPON))
						m_CurrentOperationsMenu.SelectNext();

					if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, (int)eNativeInputs::INPUT_ATTACK))
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