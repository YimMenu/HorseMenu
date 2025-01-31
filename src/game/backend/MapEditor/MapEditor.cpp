#include "MapEditor.hpp"
#include "Camera/MapEditorCustomCamera.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/NativeHooks.hpp"

#include "Items/MapPed.hpp"
#include "Items/MapObject.hpp"
#include "Items/MapVehicle.hpp"

namespace YimMenu::Features
{
	class MapEditorTest : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			MapEditor::Toggle();
		}
	};

	static MapEditorTest _MapEditor{"mapeditor", "Open Map Editor (BETA)", "This is still very much a work in progress"};
}

namespace YimMenu
{
	MapEditor::MapEditor() :
	    m_Menu(&m_Info)
	{
	}

	void MapEditor::ToggleImpl()
	{
		m_Opened = !m_Opened;
		if (m_Opened)
			Open();
		else
			Close();
	}

	void MapEditor::UpdateImpl()
	{
		while (true)
		{
			ScriptMgr::Yield();

			if (!m_Opened) 
			{
				// ensure we always update our entities
				for (auto& entity : m_GlobalEntityStore)
					entity->Update();
			}
			else
			{
				EVENT::SUPPRESS_SHOCKING_EVENTS_NEXT_FRAME();

				m_Controls.BeginFrame();
				m_Camera->Update(m_Controls);
				m_Selection.Update(*m_Camera, m_Controls);
				m_Menu.Update(m_Controls);
				for (auto& entity : m_GlobalEntityStore)
					entity->Update();
				m_Controls.EndFrame();
			}
		}
	}

	void MapEditor::Open()
	{
		static bool ensure_disable_whistling_hook =
		[] {
			NativeHooks::AddHook("player_horse"_J, NativeIndex::IS_SCRIPTED_SPEECH_PLAYING, [](rage::scrNativeCallContext* ctx) {
				if (MapEditor::IsOpen())
					ctx->SetReturnValue(TRUE);
				else
					ctx->SetReturnValue(AUDIO::IS_SCRIPTED_SPEECH_PLAYING(ctx->GetArg<int>(0)));
			});
			return true;
		}();

		static bool ensure_disable_ui_state_machines_hook = [] {
			NativeHooks::AddHook(NativeHooks::ALL_SCRIPTS, NativeIndex::UI_STATE_MACHINE_CREATE, [](rage::scrNativeCallContext* ctx) {
				if (MapEditor::IsOpen())
				{
					LOGF(VERBOSE, "Blocked UI_STATE_MACHINE_CREATE from 0x{:X}", SCRIPTS::GET_HASH_OF_THIS_SCRIPT_NAME());
					ctx->SetReturnValue(TRUE);
				}
				else
					ctx->SetReturnValue(UISTATEMACHINE::UI_STATE_MACHINE_CREATE(ctx->GetArg<int>(0), ctx->GetArg<int>(1)));
			});
			return true;
		}();

		// disable freecam and noclip first because they'll interfere with our custom cam
		static auto freecamCmd = Commands::GetCommand<BoolCommand>("freecam"_J);
		freecamCmd->SetState(false);
		static auto noclipCmd = Commands::GetCommand<BoolCommand>("noclip"_J);
		noclipCmd->SetState(false);

		CreateCamera();

		Self::GetPed().SetVisible(false);
		Self::GetPed().SetFrozen(true);
		Self::GetPed().SetCollision(false);
		Self::GetPed().SetInvincible(true); // alligators can still kill you in noclip, who would've thought?
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(Self::GetPlayer().GetId(), true);
		EVENT::REMOVE_ALL_SHOCKING_EVENTS(false);

		MISC::CLEAR_AREA(0.0f, 0.0f, 0.0f, 19999.0f, 0x80000);
	}

	void MapEditor::Close()
	{
		if (m_Selection.HasSelection())
			CancelSelectionImpl();

		DestroyCamera();
		m_Menu.Destroy();

		Self::GetPed().SetVisible(true);
		Self::GetPed().SetFrozen(false);
		Self::GetPed().SetCollision(true);
		Self::GetPed().SetInvincible(false);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(Self::GetPlayer().GetId(), false);
	}

	std::uint32_t MapEditor::AllocateNewIndex()
	{
		return m_Info.m_CurrentIndex++; // works for now
	}

	std::shared_ptr<MapEntity> MapEditor::CreateNewEntityOfType(MapEntity::Type type)
	{
		switch (type)
		{
		case MapEntity::Type::PED: 
			 return std::make_shared<MapPed>(); 
		case MapEntity::Type::OBJECT: 
			return std::make_shared<MapObject>();
		case MapEntity::Type::VEHICLE:
			return std::make_shared<MapVehicle>();
		default:
			LOG(WARNING) << "MapEditor::CreateNewEntityOfType: don't know how to create entity of type " << (int)type;
			return nullptr;
		}
	}

	std::shared_ptr<MapEntity> MapEditor::GetEntityImpl(std::uint32_t index)
	{
		if (auto it = m_Entitites.find(index); it != m_Entitites.end())
			return it->second;
		return nullptr;
	}

	std::optional<std::uint32_t> MapEditor::GetIndexFromGameEntityImpl(Entity entity)
	{
		if (!entity)
			return std::nullopt;

		for (auto& entry : m_Entitites)
			if (entry.second->m_GameEntity && entry.second->m_GameEntity == entity)
				return entry.first;

		return std::nullopt;
	}

	std::uint32_t MapEditor::RegisterEntityImpl(std::shared_ptr<MapEntity> new_entity)
	{
		auto index = AllocateNewIndex();
		m_Entitites.emplace(index, std::move(new_entity));
		return index;
	}

	void MapEditor::ReplaceEntityImpl(std::uint32_t index, std::shared_ptr<MapEntity> to_replace)
	{
		if (auto it = m_Entitites.find(index); it != m_Entitites.end())
		{
			it->second->DestroyGameObject();
			it->second = std::move(to_replace);
		}
		else
		{
			LOG(WARNING) << "MapEditor::ReplaceEntityImpl: an item with index " << index << " does not exist";
		}
	}

	void MapEditor::DeleteEntityImpl(std::uint32_t index)
	{
		if (m_Selection.IsEntitySelected(index))
			m_Selection.UnlinkSelectedEntity();

		if (auto it = m_Entitites.find(index); it != m_Entitites.end())
		{
			it->second->DestroyGameObject();
			m_Entitites.erase(it);
		}
	}

	void MapEditor::AddEntityToGlobalStoreImpl(MapEntity* entity)
	{
		m_GlobalEntityStore.insert(entity);
	}

	void MapEditor::RemoveEntityFromGlobalStoreImpl(MapEntity* entity)
	{
		m_GlobalEntityStore.erase(entity);
	}

	bool MapEditor::IsGameEntityRegisteredWithGlobalStoreImpl(Entity entity)
	{
		// a small optimization
		auto c_entity = entity;
		(volatile void) c_entity.GetHandle();

		for (auto& el : m_GlobalEntityStore)
		{
			if (el->m_GameEntity && el->m_GameEntity == c_entity)
				return true; 
		}

		return false;
	}

	void MapEditor::SelectItemImpl(std::uint32_t index)
	{
		if (m_Selection.HasSelection())
		{
			LOG(WARNING) << "MapEditor::SelectItemImpl: an item is already selected";
			CancelSelectionImpl();
		}

		auto entity = GetEntityImpl(index);

		if (!entity)
		{
			LOG(WARNING) << "MapEditor::SelectItemImpl: an item with index " << entity << " does not exist";
			return;
		}

		// let's hide our old entity first
		entity->Hide();

		// then we'll clone our entity used for selection
		auto new_entity = entity->Clone();
		new_entity->CreateGameObject(); // render our new object
		new_entity->Select(); // and mark it as selected

		// set up item selection
		m_Selection.m_Entity = new_entity;
		m_Selection.m_ExistingEntity = index;

		// make UI go to the item submenu
		m_Menu.OnItemSelected(new_entity->m_Type);
	}

	void MapEditor::SelectItemImpl(std::shared_ptr<MapEntity> entity)
	{
		if (m_Selection.HasSelection())
		{
			if (m_Selection.HasConcreteSelection())
			{
				LOG(WARNING) << "MapEditor::SelectItemImpl: a concrete item is already selected";
				return;
			}
			
			CancelSelectionImpl();
		}

		entity->Select();
		m_Selection.m_Entity = entity;
		m_Selection.m_ExistingEntity = std::nullopt;
	}

	void MapEditor::PlaceItemImpl()
	{
		if (!m_Selection.HasSelection())
		{
			LOG(WARNING) << "MapEditor::PlaceItemImpl: no selection found";
			return;
		}

		if (m_Selection.m_ExistingEntity.has_value())
		{
			// we've selected an existing entity, so placing our temp entity will overwrite whatever's stored there
			ReplaceEntityImpl(m_Selection.m_ExistingEntity.value(), m_Selection.m_Entity);
		}
		else
		{
			// we're placing a new item
			RegisterEntityImpl(m_Selection.m_Entity);
		}

		m_Selection.m_Entity->Place(); // no longer select the entity since it's an actual object on the map now
		m_Selection.Clear();
	}

	void MapEditor::CancelSelectionImpl()
	{
		if (!m_Selection.HasSelection())
		{
			LOG(WARNING) << "MapEditor::CancelSelectionImpl: no selection found";
			return;
		}

		// get rid of temp object
		m_Selection.m_Entity->DestroyGameObject();

		if (m_Selection.m_ExistingEntity.has_value())
		{
			// restore whatever we've selected
			auto old_entity = GetEntityImpl(m_Selection.m_ExistingEntity.value());

			if (!old_entity)
			{
				LOG(WARNING) << "MapEditor::CancelSelectionImpl: cannot find existing entity";
				return;
			}

			old_entity->Unhide();
		}

		m_Selection.Clear();
	}


	void MapEditor::CreateCamera()
	{
		if (m_Camera)
			DestroyCamera();

		// TODO: integrate native camera
		m_Camera = std::make_shared<MapEditorCustomCamera>();
		m_Camera->Setup();
	}

	void MapEditor::DestroyCamera()
	{
		if (!m_Camera)
			return;

		m_Camera->Destroy();
		m_Camera.reset();
	}

	std::shared_ptr<MapEntity> MapEditor::GetEditingEntityImpl(MapEntity::Type type)
	{
		if (m_Selection.HasSelection()) 
		{ 
			if (m_Selection.m_Entity->m_Type != type)
			{
				if (m_Selection.HasConcreteSelection())
				{
					LOG(WARNING) << "MapEditor::GetEditingEntityImpl: already have a concrete selection of an entity with a different type";
					return nullptr;
				}

				ClearEditingEntityImpl();
			}
			else
			{
				return m_Selection.m_Entity; // return existing entity to edit
			}
		}

		// need to create a new non-concrete entity
		// try to clone an existing entity of the same type that has been edited recently first
		std::shared_ptr<MapEntity> most_recent_entity;
		for (auto& [id, entity] : m_Entitites)
		{
			if (entity->m_Type == type && (!most_recent_entity || most_recent_entity->m_LastEditTime < entity->m_LastEditTime))
				most_recent_entity = entity;
		}

		if (most_recent_entity)
		{
			auto new_entity = most_recent_entity->Clone();
			new_entity->CreateGameObject();

			// create new non-concrete selection for our clone
			SelectItemImpl(new_entity);
			return new_entity;
		}

		// we have to create a new entity from scratch
		std::shared_ptr<MapEntity> new_entity = CreateNewEntityOfType(type);

		if (!new_entity)
			return nullptr;

		// select
		new_entity->CreateGameObject();
		SelectItemImpl(new_entity);

		return new_entity;
	}

	void MapEditor::ClearEditingEntityImpl()
	{
		if (m_Selection.HasSelection())
		{
			if (m_Selection.HasConcreteSelection())
				return;

			CancelSelectionImpl();
		}
	}

	void MapEditor::ResetMapImpl()
	{
		if (m_Selection.HasSelection())
			CancelSelectionImpl();

		m_Entitites.clear();

		if (m_GlobalEntityStore.size() > 0)
		{
			LOG(WARNING) << "MapEditor::ResetMapImpl: found " << m_GlobalEntityStore.size() << " orphaned entities in the global store. This WILL cause crashes";
			m_GlobalEntityStore.clear();
		}

		m_Info.Reset();
		m_LoadedMapName = std::nullopt;
	}

	void MapEditor::RefreshAvailableMapsImpl()
	{
		Folder maps_folder = FileMgr::GetProjectFolder("./maps/");
		FileMgr::CreateFolderIfNotExists(maps_folder);

		m_MapsAvailable.clear();
		for (const auto& entry : std::filesystem::directory_iterator(maps_folder))
		{
			if (entry.is_regular_file() && entry.path().extension() == ".json")
			{
				m_MapsAvailable.push_back(entry.path().stem().string());
			}
		}
	}

	void MapEditor::SaveMapImpl()
	{
		if (m_Selection.HasSelection())
			CancelSelectionImpl();

		// if we have renamed the map, make sure to delete the old one first
		Folder maps_folder = FileMgr::GetProjectFolder("./maps/");
		FileMgr::CreateFolderIfNotExists(maps_folder);

		if (m_LoadedMapName)
		{
			if (*m_LoadedMapName != m_Info.m_Name)
			{
				auto old_file = maps_folder.Path() / (*m_LoadedMapName + ".json");
				if (std::filesystem::exists(old_file))
					std::filesystem::remove(old_file);
			}
		}

		nlohmann::json object;
		object["info"] = nlohmann::json::object();
		object["items"] = nlohmann::json::object();

		m_Info.Serialize(object["info"]);

		for (auto& [id, entity] : m_Entitites)
		{
			auto id_as_str = std::to_string(id);
			object["items"][id_as_str] = nlohmann::json::object();
			entity->Serialize(object["items"][id_as_str]);
		}

		auto out_path = maps_folder.Path() / (m_Info.m_Name + ".json");
		std::ofstream out_map(out_path, std::ios::trunc);
		if (!out_map.good())
		{
			LOG(WARNING) << "MapEditor::SaveMap: failed to open " << out_path.string();
			return;
		}
		out_map << object.dump(4);
		out_map.close();

		m_LoadedMapName = m_Info.m_Name;
	}

	bool MapEditor::LoadMapImpl(std::string_view name)
	{
		Folder maps_folder = FileMgr::GetProjectFolder("./maps/");
		FileMgr::CreateFolderIfNotExists(maps_folder);

		// let's see if the map actually exists first
		auto in_path = maps_folder.Path() / (std::string(name) + ".json");
		if (!std::filesystem::exists(in_path))
			return false;

		// clear existing objects
		ResetMapImpl();

		// now we load the map. Assume anything can happen from here on out
		try
		{
			nlohmann::json object;

			std::ifstream in_map(in_path);
			object << in_map;
			in_map.close();

			int largest_id = 0;

			m_Info.Deserialize(object["info"]);
			for (auto& [key, obj] : object["items"].items())
			{
				auto id_as_int = std::atoi(key.c_str());
				auto new_entity = CreateNewEntityOfType(static_cast<MapEntity::Type>(obj["type"]));

				if (!new_entity)
					throw std::exception("failed to create entity"); // recall that accessing a null pointer is UB, even when you wrap your code around an exception handler

				new_entity->Deserialize(obj);
				new_entity->CreateGameObject();
				m_Entitites.emplace(id_as_int, std::move(new_entity));

				largest_id = std::max(largest_id, id_as_int);
			}

			if (largest_id <= m_Info.m_CurrentIndex)
				m_Info.m_CurrentIndex = largest_id;
			m_Info.m_Name = name;

			if (largest_id > INT_MAX)
				throw std::exception("file probably very corrupt");

			return true;
		}
		catch (std::exception& e)
		{
			LOG(WARNING) << "MapEditor::LoadMapImpl: got exception " << e.what() << " when loading map " << name;
			ResetMapImpl(); // try as humanly as possible to recover from this corrupt state
			return false;
		}
	}

	void MapEditor::DeleteMapImpl(std::string_view name)
	{
		Folder maps_folder = FileMgr::GetProjectFolder("./maps/");
		FileMgr::CreateFolderIfNotExists(maps_folder);

		auto in_path = maps_folder.Path() / (std::string(name) + ".json");
		if (std::filesystem::exists(in_path))
			std::filesystem::remove(in_path);

		std::erase(m_MapsAvailable, name);
	}
}