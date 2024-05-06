#include "Network.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu::Submenus
{
	Network::Network() :
	    Submenu::Submenu("Network")
	{
		auto session  = std::make_shared<Category>("Session");
		auto spoofing = std::make_shared<Category>("Spoofing");
		auto database = std::make_shared<Category>("Player Database");
		session->AddItem(std::make_shared<CommandItem>("explodeall"_J));
		session->AddItem(std::make_shared<CommandItem>("maxhonorall"_J));
		session->AddItem(std::make_shared<CommandItem>("minhonorall"_J));
		session->AddItem(std::make_shared<BoolCommandItem>("blockalltelemetry"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidegod"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J));
		database->AddItem(std::make_shared<ImGuiItem>([] {
			static char search[64];
			ImGui::InputText("##search", search, sizeof(search));

			if (auto selected = g_PlayerDatabase.GetSelected())
			{
				ImGui::InputText("Name", &selected.name);
				ImGui::InputInt("RID", &selected.rid);
				ImGui::Checkbox("Is Modder", &selected.is_modder);
				ImGui::Checkbox("Is Admin", &selected.is_admin);
			}
		}));
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(database));
	}
}