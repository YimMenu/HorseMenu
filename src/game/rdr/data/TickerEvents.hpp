#pragma once

namespace YimMenu::Data
{
	static std::vector<std::pair<int, const char*>> g_TickerEvents = 
	{
	    {2, "Versus (Normal)"},
	    {3, "Versus (Teamkill)"},
	    {6, "Versus (Incapacitated)"},
	    {7, "Versus (Incapacitated Execution)"},
	    {52, "Gang Started"},
	    {72, "Versus Mission Start"},
	    {73, "Mission Failed To Join"},
	    {74, "Mission Request"},
	    {75, "Mission Force Join"},
	    {76, "Mission Force Leave"},
	    {78, "Deathmatch 1V1"},
	    {80, "Deathmatch Posse Leader Feud"},
	    {81, "Deathmatch Posse Feud"},
	    {82, "Deathmatch Posse Fighting"},
	    {101, "Split Money With Posse"},
	    {102, "Passive Mode Ended"},
	    {103, "Pressed Charges"},
	    {108, "Bounty Mission Failed To Launch"},
	    {109, "Player Has Flavored Moonshine"},
	};
}