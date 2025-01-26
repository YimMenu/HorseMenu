#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/LoopedCommand.hpp"

enum class eDeviceType
{
	NONE,
	INPUT,
	OUTPUT
};

class CFoundDevice
{
public:
	GUID m_Guid;                     // 0x00
	char16_t m_Name[64];             // 0x10
	eDeviceType m_DeviceType;        // 0x90
	eDeviceType m_DefaultDeviceType; // 0x94
};
static_assert(sizeof(CFoundDevice) == 0x98);

namespace YimMenu::Hooks
{
	int Voice::EnumerateAudioDevices(CFoundDevice* devices, int count, int flags)
	{
		auto res = BaseHook::Get<Voice::EnumerateAudioDevices, DetourHook<decltype(&Voice::EnumerateAudioDevices)>>()->Original()(devices, count, flags);

		static auto override = Commands::GetCommand<LoopedCommand>("voicechatoverride"_J);
		if ((flags & 1) && override->GetState())
		{
			for (int i = 0; i < count; i++)
			{
				if (devices[i].m_DeviceType != eDeviceType::OUTPUT)
				{
					memset(&devices[i], 0, sizeof(CFoundDevice));
					lstrcpyW((LPWSTR)devices[i].m_Name, L"Terminus Virtual Input Device");
					memcpy(&devices[i].m_Guid, &g_YimDevice, sizeof(GUID));
					devices[i].m_DeviceType         = eDeviceType::INPUT;
					devices[i].m_DefaultDeviceType  = eDeviceType::INPUT;

					if (i >= res)
						res++;

					break;
				}
			}
		}

		return res;
	}
}