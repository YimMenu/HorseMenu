#pragma once
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	static inline float m_OperationCardX = 125.0f;
	static inline float m_OperationCardY = 15.0f;

	struct ContextMenuOperation
	{
		std::string m_Name;
		std::function<void()> m_Operation;

		bool operator==(const ContextMenuOperation& other) const
		{
			return m_Name == other.m_Name;
		};
	};

	struct ContextOperationsMenu
	{
		std::vector<ContextMenuOperation> m_Operations;
		std::string m_Name;
		ContextMenuOperation m_SelectedOperation;

		ContextOperationsMenu() = default;
		ContextOperationsMenu(std::string name, std::vector<ContextMenuOperation> operations) :
		    m_Name(name),
		    m_Operations(operations)
		{
			m_SelectedOperation = m_Operations.front();
		}

		bool operator==(const ContextOperationsMenu& other) const
		{
			return m_Name == other.m_Name;
		};

		void SelectNext()
		{
			auto it = std::find(m_Operations.begin(), m_Operations.end(), m_SelectedOperation);
			if (it != m_Operations.end())
			{
				it++;
				if (it == m_Operations.end())
				{
					it = m_Operations.begin();
				}
				m_SelectedOperation = *it;
			}
		}

		void SelectPrevious()
		{
			auto it = std::find(m_Operations.begin(), m_Operations.end(), m_SelectedOperation);
			if (it != m_Operations.end())
			{
				if (it == m_Operations.begin())
				{
					it = m_Operations.end();
				}
				it--;
				m_SelectedOperation = *it;
			}
		}
	};

	class ContextMenu
	{
	private:
		static ContextMenu& GetInstance()
		{
			static ContextMenu instance{};
			return instance;
		}

		bool m_Enabled = false;
		int m_EntityHandle{};
		void* m_EntityPointer{};
		ContextOperationsMenu m_CurrentOperationsMenu{};
		bool m_MenuIsInitialized = false;
		rage::fvector2 m_ScreenPos{};

		double CumulativeDistanceToMiddleOfScreenImpl(rage::fvector2 screenPos);
		int GetEntityHandleClosestToMiddleOfScreenImpl(bool includePlayers, bool includePeds, bool includeVehicles, bool includeObjects);
		void SetEntityImpl(int handle, void* pointer);
		void HandleEntityAndMenuImpl();
		void DrawContextMenuImpl();

	public:
		static void Enable()
		{
			GetInstance().m_Enabled = true;
		}

		static void Disable()
		{
			GetInstance().m_Enabled = false;
		}

		static bool* GetEnabled()
		{
			return &GetInstance().m_Enabled;
		}

		static double CumulativeDistanceToMiddleOfScreen(rage::fvector2 screenPos)
		{
			return GetInstance().CumulativeDistanceToMiddleOfScreenImpl(screenPos);
		}

		static int GetEntityHandleClosestToMiddleOfScreen(bool includePlayers, bool includePeds = false, bool includeVehicles = false, bool includeObjects = false)
		{
			return GetInstance().GetEntityHandleClosestToMiddleOfScreenImpl(includePlayers, includePeds, includeVehicles, includeObjects);
		}

		static void HandleEntityAndMenu()
		{
			GetInstance().HandleEntityAndMenuImpl();
		}

		static void DrawContextMenu()
		{
			GetInstance().DrawContextMenuImpl();
		}

		static void SetEntity(int handle, void* pointer)
		{
			GetInstance().SetEntityImpl(handle, pointer);
		}

		static int GetEntityHandle()
		{
			return GetInstance().m_EntityHandle;
		}

		static void* GetEntityPointer()
		{
			return GetInstance().m_EntityPointer;
		}

		static bool IsMenuIinitialized()
		{
			return GetInstance().m_MenuIsInitialized;
		}

		static rage::fvector2 GetScreenPos()
		{
			return GetInstance().m_ScreenPos;
		}
	};
}