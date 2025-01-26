#pragma once
#include "../Items/MapEntity.hpp"
#include "../MapControls.hpp"
#include "../MapInfo.hpp"
#include "NativeMenu.hpp"

namespace YimMenu
{
	class MapEditorMenu : protected NativeMenu
	{
		static std::unordered_map<MapEntity::Type, std::vector<NativeMenu::Submenu>> sm_SubmenusByType;
		MapInfo* m_Info;

	public:
		MapEditorMenu(MapInfo* info);

		virtual void UpdateView() override;

		void Setup();
		void Update(MapControls& controls);
		void Destroy();

		Submenu GetDefaultSubmenu(MapEntity::Type type);
		std::optional<MapEntity::Type> GetSubmenuType(const Submenu& menu);

		void OnItemSelected(MapEntity::Type type);
	};
}