#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Voice.hpp"

using namespace std::chrono_literals;

class IDirectSoundCaptureBuffer
{
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
			*read = YimMenu::Voice::GetReadPosition();

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
		YimMenu::Voice::OnLock(dwOffset, dwBytes, ppvAudioPtr1, reinterpret_cast<uint32_t*>(pdwAudioBytes1), ppvAudioPtr2, reinterpret_cast<uint32_t*>(pdwAudioBytes2));
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Start(int flags) // 0x48
	{
		YimMenu::Voice::OnStart();
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Stop() // 0x50
	{
		YimMenu::Voice::OnStop();
		return (HRESULT)0L; // DS_OK
	}

	virtual HRESULT Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2) // 0x58
	{
		return (HRESULT)0L; // DS_OK
	}
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
			return BaseHook::Get<Voice::DirectSoundCaptureCreate, DetourHook<decltype(&Voice::DirectSoundCaptureCreate)>>()->Original()(guid, sound, unknown);
		}
	}
}