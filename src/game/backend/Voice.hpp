#pragma once
#include "game/rdr/Player.hpp"
#include "core/settings/IStateSerializer.hpp"
#include "core/filemgr/FileMgr.hpp"

namespace YimMenu
{
	class Voice : IStateSerializer
	{
	public:
		static inline Player GetSpoofingPlayer()
		{
			return GetInstance().m_SpoofingPlayer;
		}

		static inline void SetSpoofingPlayer(Player player)
		{
			GetInstance().m_SpoofingPlayer = player;
		}

		static Folder GetAudioDirectory()
		{
			return GetInstance().m_AudioDirectory;
		}

		static std::string GetVoiceFile()
		{
			return GetInstance().m_AudioFile;
		}

		static void SetVoiceFile(std::string file)
		{
			GetInstance().SetVoiceFileImpl(file);
		}

		static void OnStart()
		{
			GetInstance().OnStartImpl();
		}

		static void OnStop()
		{
			GetInstance().OnStopImpl();
		}

		static void OnLock(uint32_t offset, uint32_t bytes, char** audio_ptr_1, uint32_t* audio_size_1, char** audio_ptr_2, uint32_t* audio_size_2)
		{
			GetInstance().OnLockImpl(offset, bytes, audio_ptr_1, audio_size_1, audio_ptr_2, audio_size_2);
		}

		static int GetReadPosition()
		{
			return GetInstance().m_ReadPosition;
		}

	private:
		Voice();
		~Voice();

		void LoadFileImpl();
		void SetVoiceFileImpl(std::string file);
		void OnStartImpl();
		void OnStopImpl();
		void OnLockImpl(uint32_t offset, uint32_t bytes, char** audio_ptr_1, uint32_t* audio_size_1, char** audio_ptr_2, uint32_t* audio_size_2);

		int GetActualReadPos();

		virtual void SaveStateImpl(nlohmann::json& state) override;
		virtual void LoadStateImpl(nlohmann::json& state) override;

		static Voice& GetInstance()
		{
			static Voice Instance;
			return Instance;
		}

		Player m_SpoofingPlayer = nullptr;
		std::atomic_bool m_Running = false;
		char* m_AudioBuffer = nullptr;
		int m_AudioSize = 0;
		int m_AudioPage = 0;
		int m_ReadPosition = 0;
		std::chrono::high_resolution_clock::time_point m_LastReadTime{};
		std::mutex m_BufferModifyMutex;
		Folder m_AudioDirectory;
		std::string m_AudioFile = "";
	};
}