#pragma once
#include <rage/vector.hpp>

#include "Camera/MapEditorCamera.hpp"
#include "Menu/MapEditorMenu.hpp"
#include "Items/MapEntity.hpp"
#include "MapControls.hpp"
#include "MapEditorSelection.hpp"
#include "MapInfo.hpp"

#include <unordered_set>

namespace YimMenu
{
	class MapEditor
	{
		bool m_Opened = false;
		bool m_Loaded = false;
		std::optional<std::string> m_LoadedMapName = std::nullopt;
		std::unordered_map<std::uint32_t, std::shared_ptr<MapEntity>> m_Entitites{};
		std::unordered_set<MapEntity*> m_GlobalEntityStore{}; // this is used to call Update() on every entity, including entities that are not placed on the map yet
		                                                      // we store them with raw pointers to avoid reference cycles, which is safe as long as the destructor gets called
		std::shared_ptr<MapEditorCamera> m_Camera{};
		MapControls m_Controls{};
		MapEditorSelection m_Selection{};
		MapEditorMenu m_Menu;
		MapInfo m_Info{};
		std::vector<std::string> m_MapsAvailable{};

	public:
		static bool IsOpen()
		{
			return GetInstance().m_Opened;
		}

		static void Update()
		{
			GetInstance().UpdateImpl();
		}

		static void Toggle()
		{
			GetInstance().ToggleImpl();
		}

		// expose some stuff to the outside world
		// TODO: use the observer pattern to minimize this
		// i.e. another class to manage entities and an event sink to send deletion/selection events to

		static std::optional<std::uint32_t> GetIndexFromGameEntity(Entity entity)
		{
			return GetInstance().GetIndexFromGameEntityImpl(entity);
		}

		static void DeleteEntity(std::uint32_t index)
		{
			GetInstance().DeleteEntityImpl(index);
		}

		static void AddEntityToGlobalStore(MapEntity* entity)
		{
			GetInstance().AddEntityToGlobalStoreImpl(entity);
		}

		static void RemoveEntityFromGlobalStore(MapEntity* entity)
		{
			GetInstance().RemoveEntityFromGlobalStoreImpl(entity);
		}

		static bool IsGameEntityRegisteredWithGlobalStore(Entity entity)
		{
			return GetInstance().IsGameEntityRegisteredWithGlobalStoreImpl(entity);
		}

		static void SelectItem(std::uint32_t index)
		{
			GetInstance().SelectItemImpl(index);
		}

		static void PlaceItem()
		{
			GetInstance().PlaceItemImpl();
		}

		static void CancelSelection()
		{
			GetInstance().CancelSelectionImpl();
		}

		static std::shared_ptr<MapEntity> GetEditingEntity(MapEntity::Type type)
		{
			return GetInstance().GetEditingEntityImpl(type);
		}

		static void ClearEditingEntity()
		{
			GetInstance().ClearEditingEntityImpl();
		}

		static void SaveMap()
		{
			GetInstance().SaveMapImpl();
		}

		static const std::vector<std::string>& GetAvailableMaps()
		{
			return GetInstance().m_MapsAvailable;
		}

		static void RefreshAvailableMaps()
		{
			GetInstance().RefreshAvailableMapsImpl();
		}

		static bool LoadMap(std::string_view map)
		{
			return GetInstance().LoadMapImpl(map);
		}

		static void DeleteMap(std::string_view map)
		{
			GetInstance().DeleteMapImpl(map);
		}

	private:
		MapEditor();

		static MapEditor& GetInstance()
		{
			static MapEditor instance;
			return instance;
		}

		void ToggleImpl();
		void UpdateImpl();

		void Open();
		void Close();

		// object system
		std::uint32_t AllocateNewIndex();
		std::shared_ptr<MapEntity> CreateNewEntityOfType(MapEntity::Type type);
		std::shared_ptr<MapEntity> GetEntityImpl(std::uint32_t index);
		std::optional<std::uint32_t> GetIndexFromGameEntityImpl(Entity entity);
		std::uint32_t RegisterEntityImpl(std::shared_ptr<MapEntity> new_entity);
		void ReplaceEntityImpl(std::uint32_t index, std::shared_ptr<MapEntity> to_replace);
		void DeleteEntityImpl(std::uint32_t index);
		void AddEntityToGlobalStoreImpl(MapEntity* entity);
		void RemoveEntityFromGlobalStoreImpl(MapEntity* entity);
		bool IsGameEntityRegisteredWithGlobalStoreImpl(Entity entity);

		// selection
		void SelectItemImpl(std::uint32_t index); // select a concrete entity
		void SelectItemImpl(std::shared_ptr<MapEntity> entity); // select an non-concrete entity
		void PlaceItemImpl();
		void CancelSelectionImpl();

		// camera
		void CreateCamera();
		void DestroyCamera();

		// UI
		std::shared_ptr<MapEntity> GetEditingEntityImpl(MapEntity::Type type); // get selected entity for UI
		void ClearEditingEntityImpl(); // clear selected entity if it's non-concrete

		// serialization and map system
		void ResetMapImpl(); // clears everything
		void RefreshAvailableMapsImpl();
		void SaveMapImpl();
		bool LoadMapImpl(std::string_view name);
		void DeleteMapImpl(std::string_view name);
	};
}