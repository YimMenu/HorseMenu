#pragma once
#include "core/filemgr/File.hpp"

namespace YimMenu
{
	class IStateSerializer;

	class Settings
	{
	private:
		std::filesystem::path m_SettingsFile;
		std::vector<IStateSerializer*> m_StateSerializers;
		bool m_InitialLoadDone;
		nlohmann::json m_Json;

	public:
		Settings();

		static void Initialize(File settingsFile)
		{
			GetInstance().InitializeImpl(settingsFile);
		}

		static void Save()
		{
			GetInstance().SaveImpl();
		}

		static void AddComponent(IStateSerializer* serializer)
		{
			GetInstance().m_StateSerializers.push_back(serializer);
		}

		// TODO: this is broken
		static void LoadComponent(IStateSerializer* serializer)
		{
			GetInstance().LoadComponentImpl(serializer);
		}

		static bool InitialLoadDone()
		{
			return GetInstance().m_InitialLoadDone;
		}

		static std::string GetFilePath()
		{
			return GetInstance().m_SettingsFile.string();
		}

	private:
		static Settings& GetInstance()
		{
			static Settings Instance;
			return Instance;
		}

		void InitializeImpl(File settingsFile);
		void SaveImpl();
		void LoadComponentImpl(IStateSerializer* serializer);
		void SaveComponentImpl(IStateSerializer* serializer);
		void Reset();
		bool ShouldSave();
	};
}