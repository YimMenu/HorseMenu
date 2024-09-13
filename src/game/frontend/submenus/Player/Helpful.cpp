#include "Helpful.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Vehicle.hpp"

namespace YimMenu::Submenus
{
	std::shared_ptr<Category> BuildHelpfulMenu() 
	{ 
		auto menu = std::make_shared<Category>("Helpful");

		menu->AddItem(std::make_shared<PlayerCommandItem>("spawngoldchest"_J));
		menu->AddItem(std::make_shared<ImGuiItem>([] {
			// TODO: move, refactor, or remove these
			if (ImGui::Button("Spawn Bounty Wagon for Player"))
			{
				FiberPool::Push([] {
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(Players::GetSelected().GetPed().GetHandle(), true, true);
					float rot = ENTITY::GET_ENTITY_ROTATION(Players::GetSelected().GetPed().GetHandle(), 0).z;
					Vehicle::Create("wagonarmoured01x"_J, coords, rot);
					Notifications::Show("Spawned Wagon", "Spawned Bounty Wagon for Player", NotificationType::Success);
				});
			};

			if (ImGui::Button("Spawn Hunting Wagon for Player"))
			{
				FiberPool::Push([] {
					int id   = Players::GetSelected().GetId();
					auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id);
					Vector3 dim1, dim2;
					MISC::GET_MODEL_DIMENSIONS(MISC::GET_HASH_KEY("huntercart01"), &dim1, &dim2);
					float offset = dim2.y * 1.6;

					Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(ped);
					float rot   = (ENTITY::GET_ENTITY_ROTATION(ped, 0)).z;
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(ped, true, true);

					Vehicle::Create("huntercart01"_J,
					    Vector3{pos.x + (dir.x * offset), pos.y + (dir.y * offset), pos.z},
					    ENTITY::GET_ENTITY_ROTATION(ped, 0).z);
					Notifications::Show("Spawned Wagon", "Spawned Hunting Wagon for Player", NotificationType::Success);
				});
			}
		}));

		return menu;
	}
}