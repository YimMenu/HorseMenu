#include "core/commands/BoolCommand.hpp"
#include "core/commands/IntCommand.hpp"
#include "core/commands/Command.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"


namespace YimMenu::Features
{
	BoolCommand _SpoofDiscriminator("spoofdiscriminator", "Spoof Discriminator", "Spoofs the session discriminator used for matchmaking");
	IntCommand _Discriminator("discriminator", "Discriminator", "The discriminator value to spoof to");
	
	class CopyCurrentDiscriminator : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			_Discriminator.SetState(BaseHook::Get<Hooks::Spoofing::GetDiscriminator, DetourHook<decltype(&Hooks::Spoofing::GetDiscriminator)>>()->Original()());
		}
	};

	static CopyCurrentDiscriminator _CopyCurrentDiscriminator{"copydiscriminator", "Copy Current Discriminator", "Copies the active game discriminator into the spoof discrimantor field"};
}

namespace YimMenu::Hooks
{
	int Spoofing::GetDiscriminator()
	{
		if (Features::_SpoofDiscriminator.GetState())
		{
			return Features::_Discriminator.GetState();
		}
		else
		{
			return BaseHook::Get<Spoofing::GetDiscriminator, DetourHook<decltype(&Spoofing::GetDiscriminator)>>()->Original()();
		}
	}
}