#pragma once

namespace YimMenu::Data
{
	static std::vector<std::pair<int, const char*>> g_MountInstance = {
	    {0, "Inactive Horses"},
	    {1, "Inactive Vehicles"},
	    {2, "Active Horse"},
	    {3, "Active Vehicle"},
	    {4, "All Horses"},
	    {5, "All Vehicles"},
	    {6, "All Mounts"},
	};

	static std::vector<std::pair<int, const char*>> g_StableMountEvent = {
	    {0, "Release Mount"},
	    {1, "Delete Mount"},
	    {2, "Delete Local Mount"},
	    {3, "Release Local Mount"},
	    {4, "Set Mission Critical"},
	    {5, "Clear Mission Critical"},
	    {6, "Summon Vehicle"},
	    {7, "Horse Command Backoff"},
	    {8, "Horse Command Stay Wait"},
	    {9, "Horse Buck Rider"},
	    {10, "Horse Buck Any Rider"},
	    {11, "Horse Dismount Passenger"},
	    {12, "Vehicle Buck Rider"},
	    {13, "Vehicle Buck Any Rider"},
	    {14, "Vehicle Dismount Passenger"},
	    {15, "Vehicle Clear Task"},
	    {16, "Vehicle Dismiss"},
	};
}