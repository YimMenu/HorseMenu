#include "Network.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

#include <map>
#include <string>


namespace YimMenu::Submenus
{
	Network::Network() :
	    Submenu::Submenu("Network")
	{
		auto session          = std::make_shared<Category>("Session");
		auto spoofing         = std::make_shared<Category>("Spoofing");
		auto nameChangerGroup = std::make_shared<Group>("Name Changer", GetListBoxDimensions());
		auto spoofingColumns  = std::make_shared<Column>(1);
		session->AddItem(std::make_shared<CommandItem>("explodeall"_J));
		session->AddItem(std::make_shared<CommandItem>("maxhonorall"_J));
		session->AddItem(std::make_shared<CommandItem>("minhonorall"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidegod"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J));
		static std::string name_input_buf, color_spoof_buf = "";
		nameChangerGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			static std::map<std::string, std::string> color_translations = {{"~e~", "Red"}, {"~f~", "Off White"}, {"~p~", "White"}, {"~o~", "Yellow"}, {"~q~", "Pure White"}, {"~d~", "Orange"}, {"~m~", "Light Grey"}, {"~t~", "Grey"}, {"~v~", "Black"}, {"~pa~", "Blue"}, {"~t1~", "Purple"}, {"~t2~", "Orange"}, {"~t3~", "Teal"}, {"~t4~", "Light Yellow"}, {"~t5~", "Pink"}, {"~t6~", "Green"}, {"~t7~", "Dark Blue"}, {"~t8~", "Red"}, {"", "None"}};
			ImGui::BeginDisabled(!*Pointers.IsSessionStarted);
			ImGui::Text(std::string("Current Name: ").append(Pointers.Username).c_str());

			InputTextWithHint("New Name", "Enter New Name", &name_input_buf).Draw();

			if (ImGui::BeginCombo("Color Selection", color_translations[color_spoof_buf].c_str()))
			{
				for (auto& [code, translation] : color_translations)
				{
					if (ImGui::Selectable(translation.c_str(), code == color_spoof_buf))
					{
						color_spoof_buf = code;
					}
				}
				ImGui::EndCombo();
			}

			if (ImGui::Button("Set Spoofed Name"))
			{
				std::string concat_name      = std::string(color_spoof_buf) + name_input_buf;
				const char* concat_name_cstr = concat_name.c_str();
				char new_name[26];
				strcpy(new_name, concat_name_cstr);
				strcpy(Pointers.Username, new_name);
			}
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip("You must change sessions for this to take effect!");
			}
			ImGui::EndDisabled();
		}));
		spoofingColumns->AddItem(nameChangerGroup);
		spoofing->AddItem(spoofingColumns);
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
	}
}