#pragma once
#include <rage/vector.hpp>
#include "game/rdr/Entity.hpp"

namespace YimMenu
{
	static inline float m_OperationCardX = 125.0f;
	static inline float m_OperationCardY = 15.0f;

	struct ContextMenuOperation
	{
		std::string m_Name;
		std::function<void(Entity)> m_Operation;

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

		Entity m_Entity = nullptr;
		ContextOperationsMenu m_CurrentOperationsMenu{};
		rage::fvector2 m_ScreenPos{};

		void GameTickImpl();
		void DrawContextMenuImpl();

	public:
		static bool IsEnabled()
		{
			return GetInstance().m_Enabled;
		}

		static void DrawContextMenu()
		{
			GetInstance().DrawContextMenuImpl();
		}

		static void GameTick()
		{
			GetInstance().GameTickImpl();
		}
	};
}