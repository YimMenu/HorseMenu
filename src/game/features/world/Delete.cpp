#include "core/commands/Command.hpp"
#include "game/rdr/Pools.hpp"

namespace YimMenu::Features
{
	class DeleteAllObjects : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto obj : Pools::GetObjects())
			{
				if (obj)
					obj.Delete();
			}
		}
	};

	class DeleteAllPeds : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto ped : Pools::GetPeds())
			{
				if (!ped.IsPlayer())
					ped.Delete();
			}
		}
	};

	class DeleteAllVehs : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto veh : Pools::GetVehicles())
			{
				veh.Delete();
			}
		}
	};

	static DeleteAllObjects _DeleteAllObjects{"delobjs", "Delete All Objects", "Deletes all objects in the game world, including mission critical objects"};
	static DeleteAllPeds _DeleteAllPeds{"delpeds", "Delete All Peds", "Deletes all peds in the game world, including mission critical peds"};
	static DeleteAllVehs _DeleteAllVehs{"delvehs", "Delete All Vehicles", "Deletes all vehicles in the game world, including mission critical vehicles"};
}