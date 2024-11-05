#include "Voice.hpp"

namespace YimMenu
{
	Voice::Voice() :
	    IStateSerializer("voice"),
	    m_AudioDirectory(FileMgr::GetProjectFolder("./audio/"))
	{
		FileMgr::CreateFolderIfNotExists(m_AudioDirectory.Path());
	}

	Voice::~Voice()
	{
		std::lock_guard lock(m_BufferModifyMutex);
		m_Running = false;
		if (m_AudioBuffer)
		{
			delete[] m_AudioBuffer;
			m_AudioBuffer = nullptr;
		}
	}

	void Voice::LoadFileImpl()
	{
		std::lock_guard lock(m_BufferModifyMutex);

		if (m_AudioBuffer)
		{
			delete[] m_AudioBuffer;
			m_AudioBuffer = nullptr;
		}

		if (std::filesystem::exists(m_AudioDirectory.Path() / m_AudioFile))
		{
			std::ifstream waveStream(m_AudioDirectory.Path() / m_AudioFile, std::ios::in | std::ios::binary);

			// https://www-mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html
			int headerSize = 0;
			int dataSize   = 0;
			waveStream.seekg(4, std::ios_base::cur);          // RIFF
			waveStream.seekg(4, std::ios_base::cur);          // chunk size
			waveStream.seekg(4, std::ios_base::cur);          // Wave ID
			waveStream.seekg(4, std::ios_base::cur);          // ckID "fmt "
			waveStream.read((char*)&headerSize, 4);           // cksize "fmt "
			waveStream.seekg(headerSize, std::ios_base::cur); // format
			waveStream.seekg(4, std::ios_base::cur);          // ckID "data"
			waveStream.read((char*)&dataSize, 4);             // cksize "data"

			m_AudioBuffer = new char[dataSize];
			memset(m_AudioBuffer, 0, dataSize);
			m_AudioSize = dataSize;
			waveStream.read(m_AudioBuffer, m_AudioSize);
			waveStream.close();

			LOGF(VERBOSE, __FUNCTION__ ": audio file loaded");
		}

		m_AudioPage    = 0;
		m_ReadPosition = 0;
		m_LastReadTime = {};
	}

	void Voice::SetVoiceFileImpl(std::string file)
	{
		m_AudioFile = file;
		LoadFileImpl();
		MarkStateDirty();
	}

	void Voice::OnStartImpl()
	{
		std::lock_guard lock(m_BufferModifyMutex);
		if (m_AudioBuffer)
		{
			m_Running = true;
			std::thread thread([this] {
				m_LastReadTime = std::chrono::high_resolution_clock::now();

				while (YimMenu::g_Running && m_Running && m_AudioBuffer)
				{
					{
						std::lock_guard lock(m_BufferModifyMutex);
						// the buffer can only support up to 32000 bytes of data at once, so we have to page it instead
						if (std::chrono::high_resolution_clock::now() - m_LastReadTime >= 1ms)
						{
							m_LastReadTime = std::chrono::high_resolution_clock::now();
							m_ReadPosition += ((2 * 16000) / 1000); // F*M*Nc/1000

							// reset page idx after audio playback completes
							if (GetActualReadPos() > m_AudioSize)
							{
								m_ReadPosition = 0;
								m_AudioPage    = 0;
							}

							// use next page if we go beyond 32000
							if (m_ReadPosition > 32000)
							{
								m_ReadPosition = m_ReadPosition % 32000;
								m_AudioPage++;
							}
						}
					}

					std::this_thread::yield();
				}
			});

			thread.detach();
		}
	}

	void Voice::OnStopImpl()
	{
		m_Running = false;
	}

	void Voice::OnLockImpl(uint32_t offset, uint32_t bytes, char** audio_ptr_1, uint32_t* audio_size_1, char** audio_ptr_2, uint32_t* audio_size_2)
	{
		std::lock_guard lock(m_BufferModifyMutex);

		if (offset > m_ReadPosition && m_AudioPage != 0)
		{
			offset -= 32000; // fix page offset if we have to read back
		}

		offset += (m_AudioPage * 32000); // add our page offset to get the actual position

		// fix artifacts after audio ends
		if (bytes > 1280)
			offset = 0;

		if (offset + bytes <= m_AudioSize)
		{
			*audio_ptr_1  = &m_AudioBuffer[offset];
			*audio_size_1 = bytes;
			*audio_ptr_2  = NULL;
			*audio_size_2 = 0;
		}
		else
		{
			*audio_ptr_1  = &m_AudioBuffer[offset];
			*audio_size_1 = m_AudioSize - offset;
			*audio_ptr_2  = &m_AudioBuffer[0];
			*audio_size_2 = bytes - *audio_size_1;
		}
	}

	int Voice::GetActualReadPos()
	{
		return m_ReadPosition + (m_AudioPage * 32000);
	}

	void Voice::SaveStateImpl(nlohmann::json& state)
	{
		state["file"] = m_AudioFile;
	}

	void Voice::LoadStateImpl(nlohmann::json& state)
	{
		if (state.contains("file") && state["file"].is_string())
		{
			Voice::SetVoiceFile(state["file"]);
		}
	}
}