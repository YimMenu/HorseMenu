#include "ContextMenu.hpp"

#include "ContextMenus.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/backend/FiberPool.hpp"

namespace YimMenu
{
	void ContextMenu::SetEntityImpl(int handle, void* pointer)
	{
		m_EntityHandle  = handle;
		m_EntityPointer = pointer;
	}

	double ContextMenu::CumulativeDistanceToMiddleOfScreenImpl(rage::fvector2 screenPos)
	{
		double cumDist{};

		if (screenPos.x > 0.5)
			cumDist += screenPos.x - 0.5;
		else
			cumDist += 0.5 - screenPos.x;

		if (screenPos.y > 0.5)
			cumDist += screenPos.y - 0.5;
		else
			cumDist += 0.5 - screenPos.y;

		return cumDist;
	}

	int ContextMenu::GetEntityHandleClosestToMiddleOfScreenImpl(bool includePlayers, bool includePeds = false, bool includeVehicles = false, bool includeObjects = false)
	{
		int closestHandle{};
		float distance = 1;

		auto updateClosestEntity = [&](int handle) -> void {
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

		if (includePlayers)
		{
			for (auto [id, plyr] : YimMenu::Players::GetPlayers())
			{
				if (plyr.IsValid() || plyr.GetPed().GetPointer<void*>())
					updateClosestEntity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id));
			}
		}

		return closestHandle;
	}

	void ContextMenu::HandleEntityAndMenuImpl()
	{
		if (m_Enabled && g_ContextMenu)
		{
			auto handle   = GetEntityHandleClosestToMiddleOfScreenImpl(true);
			auto menuType = ContextMenuEntityType::Player;

			static auto switchToMenu = [&](ContextOperationsMenu menu) -> void {
				if (m_CurrentOperationsMenu != menu)
				{
					m_CurrentOperationsMenu = menu;
				}
			};

			if (handle && ENTITY::DOES_ENTITY_EXIST(handle))
			{
				m_EntityHandle = handle;

				if (ENTITY::IS_ENTITY_A_PED(m_EntityHandle))
				{
					if (PED::IS_PED_A_PLAYER(m_EntityHandle))
						menuType = ContextMenuEntityType::Player, switchToMenu(ContextMenuPlayers);
					else
						menuType = ContextMenuEntityType::Ped, switchToMenu(ContextMenuDefault); //TODO Create Ped menu
				}
				else if (ENTITY::IS_ENTITY_A_VEHICLE(m_EntityHandle))
				{
					menuType = ContextMenuEntityType::Vehicle, switchToMenu(ContextMenuDefault); //TODO Create Vehicle menu
				}
				else if (ENTITY::IS_ENTITY_AN_OBJECT(m_EntityHandle))
				{
					menuType = ContextMenuEntityType::Object, switchToMenu(ContextMenuDefault); //TODO Create Object menu
				}

				if (m_CurrentOperationsMenu.m_SelectedOperation.m_Name.empty())
					m_CurrentOperationsMenu.m_SelectedOperation = m_CurrentOperationsMenu.m_Operations.front();

				auto entPos           = ENTITY::GET_ENTITY_COORDS(handle, false, true);
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
						m_CurrentOperationsMenu.m_SelectedOperation.m_Operation();
					});
					
				m_MenuIsInitialized = true;
			}
			else
			{
				m_EntityHandle      = 0;
				m_MenuIsInitialized = false;
			}
		}
	}

	void DrawOperation(ContextMenuOperation operation, bool selected, int position, ImDrawList* drawList)
	{
		auto screenPos = ContextMenu::GetScreenPos();

		//Make compatible with ESP
		if (g_Esp)
			screenPos.y += 20;

		if (position > 0)
			screenPos.y += (m_OperationCardY * position) + 2 /*Margin between operation cards*/;

		auto cardColor = selected ? ImGui::ColorConvertFloat4ToU32(ImVec4(1, 0, 0, 0.5)) : ImGui::ColorConvertFloat4ToU32(ImVec4(1, 0, 0, 0.2));

		ImVec2 endPos = ImVec2(screenPos.x + m_OperationCardX, screenPos.y + m_OperationCardY);
		drawList->AddRectFilled(ImVec2(screenPos.x, screenPos.y), endPos, cardColor, 3.f);

		drawList->AddText(ImVec2(screenPos.x, screenPos.y),
		    ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)),
		    operation.m_Name.data());
	}

	void ContextMenu::DrawContextMenuImpl()
	{
		if (m_MenuIsInitialized && m_Enabled && g_ContextMenu)
		{
			if (const auto drawList = ImGui::GetBackgroundDrawList())
			{
				int position = 0;
				for (auto& operation : m_CurrentOperationsMenu.m_Operations)
				{
					DrawOperation(operation, operation == m_CurrentOperationsMenu.m_SelectedOperation, position, drawList);
					position++;
				}
			}
		}
	}
}