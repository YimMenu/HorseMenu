#pragma once

namespace YimMenu
{
	struct ModelDefinition
	{
		std::uint32_t m_Hash;
		const char* m_FriendlyName;
	};
}

namespace YimMenu::CategoryUtils
{
	// TODO: this can probably be improved

	template<typename T>
	concept GenericModelDefinition = std::is_base_of_v<ModelDefinition, T>;

	template<GenericModelDefinition T>
	struct ModelListView
	{
		const T* m_PreviousEntry{};
		const T* m_CurrentEntry{};
		const T* m_NextEntry{};
	};

	template<GenericModelDefinition T>
	struct ModelCategoryView
	{
		const std::pair<const char*, std::vector<T>>* m_PreviousEntry{};
		const std::pair<const char*, std::vector<T>>* m_CurrentEntry{};
		const std::pair<const char*, std::vector<T>>* m_NextEntry{};
	};

	template<GenericModelDefinition T>
	ModelCategoryView<T> GetCategoryView(const std::vector<std::pair<const char*, std::vector<T>>>& list, std::uint32_t hash)
	{
		ModelCategoryView<T> res{};

		for (auto it = list.begin(); it != list.end(); it++)
		{
			for (auto& m : it->second)
			{
				if (m.m_Hash == hash)
				{
					if (it != list.begin())
					{
						res.m_PreviousEntry = &*std::prev(it);
					}
					if (std::next(it) != list.end())
					{
						res.m_NextEntry = &*std::next(it);
					}
					res.m_CurrentEntry = &*it;
					return res;
				}
			}
		}
		
		return res;
	}

	template<GenericModelDefinition T>
	ModelListView<T> GetListView(const std::vector<T>& category, std::uint32_t hash)
	{
		ModelListView<T> res{};

		for (std::size_t i = 0; i < category.size(); i++)
		{
			if (category.at(i).m_Hash == hash)
			{
				if (i != 0)
					res.m_PreviousEntry = &category.at(i - 1);
				if (i != category.size() - 1)
					res.m_NextEntry = &category.at(i + 1);
				res.m_CurrentEntry = &category.at(i);
				return res;
			}
		}

		return res;
	}
}