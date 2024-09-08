#pragma once

#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

inline const char* WeatherTypes[]{

    "BLIZZARD",
    "CLOUDS",
    "DRIZZLE",
    "FOG",
    "GROUNDBLIZZARD",
    "HAIL",
    "HIGHPRESSURE",
    "HURRICANE",
    "MISTY",
    "OVERCAST",
    "OVERCASTDARK",
    "RAIN",
    "SANDSTORM",
    "SHOWER",
    "SLEET",
    "SNOW",
    "SNOWLIGHT",
    "SUNNY",
    "THUNDER",
    "THUNDERSTORM",
    "WHITEOUT",
};

void ChangeWeather(const char* weather)
{
	MISC::_SET_OVERRIDE_WEATHER(MISC::GET_HASH_KEY(weather));
}

void ChangeTime(int H = 12, int M = 0, int S = 0, int transition = 0, bool freeze = false)
{
	NETWORK::_NETWORK_CLOCK_TIME_OVERRIDE_2(H, M, S, transition, freeze, true);
}