#include <game/rdr/Natives.hpp>
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

void RDR2_ChangeWeather(const char* weather)
{
	MISC::_SET_OVERRIDE_WEATHER(MISC::GET_HASH_KEY(weather));
}
void RDR2_ChangeTime(int H = 12, int M = 0, int S = 0, int transition = 0, bool freeze = false)
{
	NETWORK::_NETWORK_CLOCK_TIME_OVERRIDE(H, M, S, transition, freeze);
}
