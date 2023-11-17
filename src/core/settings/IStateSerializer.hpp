#pragma once

namespace YimMenu
{
	class IStateSerializer
	{
		std::string m_SerComponentName;
		bool m_IsDirty;

	public:
		IStateSerializer(const std::string& name);
		virtual void SaveStateImpl(nlohmann::json& state) = 0;
		virtual void LoadStateImpl(nlohmann::json& state) = 0;

		inline void SaveState(nlohmann::json& state)
		{
			SaveStateImpl(state);
			m_IsDirty = false;
		}

		inline void LoadState(nlohmann::json& state)
		{
			LoadStateImpl(state);
			m_IsDirty = false;
		}

		inline bool IsStateDirty()
		{
			return m_IsDirty;
		}

		inline void MarkStateDirty()
		{
			m_IsDirty = true;
		}

		inline const std::string& GetSerializerComponentName()
		{
			return m_SerComponentName;
		}
	};
}