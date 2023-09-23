#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/LoopedCommand.hpp"

using namespace std::chrono_literals;

class IDirectSoundCaptureBuffer
{
	inline int GetActualReadPos()
	{
		return m_ReadPosition + (m_AudioPage * 32000);
	}

	virtual void QueryInterface(){}; // 0x00

	virtual int AddRef() // 0x08
	{
		return 0;
	};

	virtual int Release() // 0x10
	{
		return 0;
	}

	virtual HRESULT GetCaps(void* caps) // 0x18
	{
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT GetCurrentPosition(int* capture, int* read) // 0x20
	{
		if (capture)
			*capture = 0;

		if (read)
			*read = m_ReadPosition;

		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT GetFormat(void* out, int length, int* out_length) // 0x28
	{
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT GetStatus(int* status) // 0x30
	{
		*status = 1;        // DSCBSTATUS_CAPTURING
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Initialize(void*, void*) // 0x38
	{
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Lock(DWORD dwOffset, DWORD dwBytes, char** ppvAudioPtr1, LPDWORD pdwAudioBytes1, char** ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags) // 0x40
	{
		if (dwOffset > m_ReadPosition && m_AudioPage != 0)
		{
			dwOffset -= 32000; // fix page offset if we have to read back
		}

		dwOffset += (m_AudioPage * 32000); // add our page offset to get the actual position

		// fix artifacts after audio ends
		if (dwBytes > 1280)
			dwOffset = 0;

		if (dwOffset + dwBytes <= m_AudioSize)
		{
			*ppvAudioPtr1   = &m_AudioBuffer[dwOffset];
			*pdwAudioBytes1 = dwBytes;
			*ppvAudioPtr2   = NULL;
			*pdwAudioBytes2 = 0;
		}
		else
		{
			*ppvAudioPtr1   = &m_AudioBuffer[dwOffset];
			*pdwAudioBytes1 = m_AudioSize - dwOffset;
			*ppvAudioPtr2   = &m_AudioBuffer[0];
			*pdwAudioBytes2 = dwBytes - *pdwAudioBytes1;
		}

		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Start(int flags) // 0x48
	{
		if (YimMenu::FileMgr::GetProjectFile("./audio.wav").Exists())
		{
			std::ifstream waveStream(YimMenu::FileMgr::GetProjectFile("./audio.wav").Path(), std::ios::in | std::ios::binary);

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
		}
		else
		{
			return -1;

			m_AudioBuffer = new char[0xFFFF];
			m_AudioSize   = 0xFFFF;
		}

		m_Running = true;
		std::thread thread([this] {
			m_LastReadTime = std::chrono::high_resolution_clock::now();

			while (YimMenu::g_Running && m_Running)
			{
				std::this_thread::yield();

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
		});

		thread.detach();

		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Stop() // 0x50
	{
		m_Running = false;
		delete[] m_AudioBuffer;

		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2) // 0x58
	{
		return (HRESULT)0L; // DS_OK
	}

	char* m_AudioBuffer                                       = nullptr;
	int m_AudioSize                                           = 0;
	int m_AudioPage                                           = 0;
	int m_ReadPosition                                        = 0;
	bool m_Running                                             = false;
	std::chrono::high_resolution_clock::time_point m_LastReadTime = std::chrono::high_resolution_clock::time_point();
};
inline IDirectSoundCaptureBuffer g_DirectSoundCaptureBuffer{};

class IDirectSoundCapture
{
	virtual void QueryInterface(){};

	virtual int AddRef()
	{
		LOG(VERBOSE) << __FUNCTION__;
		return 0;
	};

	virtual int Release()
	{
		LOG(VERBOSE) << __FUNCTION__;
		return 0;
	}

	virtual HRESULT CreateSoundBuffer(void* desc, IDirectSoundCaptureBuffer** buffer, void* unknown)
	{
		LOG(VERBOSE) << __FUNCTION__;
		*buffer = &g_DirectSoundCaptureBuffer;
		return (HRESULT)0L; // DS_OK
	}
};
inline IDirectSoundCapture g_DirectSoundCapture{};

namespace YimMenu::Hooks
{
	HRESULT Voice::DirectSoundCaptureCreate(GUID* guid, IDirectSoundCapture** sound, void* unknown)
	{
		static auto override = Commands::GetCommand<LoopedCommand>("voicechatoverride"_J);	
		if ((*guid) == g_YimDevice && override->GetState()) 
		{
			LOG(VERBOSE) << __FUNCTION__ ": Returning YimMenu capture";
			*sound = &g_DirectSoundCapture;
			return (HRESULT)0L; // DS_OK
		}
		{
			LOG(VERBOSE) << __FUNCTION__ ": Returning original";
			return BaseHook::Get<Voice::DirectSoundCaptureCreate, DetourHook<decltype(&Voice::DirectSoundCaptureCreate)>>()
			    ->Original()(guid, sound, unknown);
		}
	}
}