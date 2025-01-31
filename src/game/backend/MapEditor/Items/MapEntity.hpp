#pragma once
#include "game/rdr/Entity.hpp"

namespace YimMenu
{
	class MapEntity
	{
	private:
		void AddToGlobalStore();
		void RemoveFromGlobalStore();

		// blip funcs for creator view


	protected:
		// returns true if successful
		virtual bool CreateGameObjectImpl() = 0;
		virtual void CreateBlip() = 0;
		void DeleteBlip();

	public:
		// please add entries to the bottom
		enum class Type : std::uint8_t
		{
			PED,
			OBJECT,
			VEHICLE
		};

		struct ModelDimensions
		{
			rage::fvector3 m_Min;
			rage::fvector3 m_Max;
		};

		Type m_Type;
		std::uint32_t m_ModelHash;
		rage::fvector3 m_Position;
		rage::fvector3 m_Rotation;
		bool m_Selected = false;
		bool m_Hidden = false;
		std::chrono::system_clock::time_point m_LastEditTime;
		bool m_ObjectCreationPending = true;

		Entity m_GameEntity{nullptr};
		int m_Blip{};

		MapEntity() :
			m_Position({}),
			m_Rotation({})
		{
			m_LastEditTime = std::chrono::system_clock::now();
			AddToGlobalStore();
		}

		MapEntity(const MapEntity& other) :
		    m_ModelHash(other.m_ModelHash),
		    m_Position(other.m_Position),
		    m_Rotation(other.m_Rotation),
		    m_Type(other.m_Type),
		    m_LastEditTime(other.m_LastEditTime)
		{
			AddToGlobalStore();
		}

		~MapEntity();

		// basic physical stuff
		void CreateGameObject();
		virtual void ChangeModel(std::uint32_t model) = 0; // requires recreating object
		virtual std::shared_ptr<MapEntity> Clone() = 0;
		virtual void Update();
		void DestroyGameObject();
		void Move(rage::fvector3 new_pos);
		void Rotate(rage::fvector3 new_rot);
		void Select();
		void Place();
		void Hide();
		void Unhide();
		ModelDimensions GetDimensions();

		// serialization
		virtual void Serialize(nlohmann::json& object);
		virtual void Deserialize(nlohmann::json& object);
	};
}