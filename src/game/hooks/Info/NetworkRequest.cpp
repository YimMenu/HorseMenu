#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
#pragma pack(push, 8)
	class HttpRequest
	{
	public:
		virtual ~HttpRequest()                                         = default;
		virtual void Unk_0x08()                                        = 0;
		virtual void Unk_0x10()                                        = 0;
		virtual void Unk_0x18()                                        = 0;
		virtual void Unk_0x20()                                        = 0;
		virtual void Unk_0x28()                                        = 0;
		virtual void Unk_0x30()                                        = 0;
		virtual void Unk_0x38()                                        = 0;
		virtual void Unk_0x40()                                        = 0;
		virtual void Unk_0x48()                                        = 0;
		virtual void Unk_0x50()                                        = 0;
		virtual void Unk_0x58()                                        = 0;
		virtual bool GetProtocol(HttpRequest* obj, char* EndPoint)     = 0;
		virtual void Unk_0x68()                                        = 0;
		virtual const char* GetDomain(int64_t* unk, size_t size = 128) = 0;
		virtual int8_t GetEndpoint(char* out, size_t size = 256)       = 0;

		const std::string GetFull()
		{
			int64_t Unk = 0;
			char Out[256];
			static std::string Domain{};
			static std::string EndPoint{};
			static std::string Protocol{};

			Domain = GetDomain(&Unk);
			if (GetEndpoint(Out))
			{
				EndPoint = Out;
				GetProtocol(this, Out) ? Protocol = "https://" : Protocol = "http://";
			}

			return Protocol + Domain + "/" + EndPoint;
		}
	};
#pragma pack(pop)


	uint8_t* Info::NetworkRequest(HttpRequest* Request, uint8_t* a2, uint32_t a3)
	{
		// LOG(INFO) << "URL: " << Request->GetFull();
		return BaseHook::Get<Info::NetworkRequest, DetourHook<decltype(&Info::NetworkRequest)>>()->Original()(Request, a2, a3);
	}

}