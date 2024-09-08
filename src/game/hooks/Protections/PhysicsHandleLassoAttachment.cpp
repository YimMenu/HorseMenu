#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"

namespace YimMenu::Hooks
{
	void Protections::PhysicsHandleLassoAttachment(void* inst, void* attachment)
	{
		if (!attachment)
		{
			Notifications::Show("Protections", "Blocked out of bounds lasso attachment index crash", NotificationType::Warning);
			return;
		}

		return BaseHook::Get<Protections::PhysicsHandleLassoAttachment, DetourHook<decltype(&Protections::PhysicsHandleLassoAttachment)>>()
		    ->Original()(inst, attachment);
	}
}