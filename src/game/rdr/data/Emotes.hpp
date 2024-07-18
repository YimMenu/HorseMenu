#include <array>
#include "game/rdr/Enums.hpp"

namespace YimMenu::Emote
{
    constexpr int numCategories = 5;
    constexpr int maxEmotesPerCategory = 37;

    int selectedEmoteCategoryIndex = 0;
    int selectedEmoteMemberIndex = 0;

    constexpr std::array<const char*, numCategories> emoteCategories = {
        "Actions",
        "Dances",
        "Greetings",
        "Reactions",
        "Taunts" /*, "Gun Twirl" */
    };

    struct EmoteItemData
    {
        const char* name;
        uint32_t hash;
        EmoteType type;
    };

    // Emote Items
    constexpr std::array<std::array<EmoteItemData, maxEmotesPerCategory>, numCategories> emoteCategoryMembers = {{
    // Actions
    {{
        {"Beckon", 0x7FC09D55, EMOTE_TYPE_ACTION},
        {"Biting Gold Coin", 0x17AA1FFF, EMOTE_TYPE_ACTION},
        {"Blow Kiss", 0x72E36635, EMOTE_TYPE_ACTION},
        {"Boast", 0xB55EEAF3, EMOTE_TYPE_ACTION},
        {"Check Pocket Watch", 0xE953BBB7, EMOTE_TYPE_ACTION},
        {"Coin Flip", 0xD833963E, EMOTE_TYPE_ACTION},
        {"Fist Pump", 0xFFF9D9F1, EMOTE_TYPE_ACTION},
        {"Flex", 0xD1DE4D57, EMOTE_TYPE_ACTION},
        {"Follow Me", 0x427B55FF, EMOTE_TYPE_ACTION},
        {"Hissyfit", 0x2F7D0AAE, EMOTE_TYPE_ACTION},
        {"Howl", 0x344F2AAD, EMOTE_TYPE_ACTION},
        {"Hypnosis Pocket Watch", 0xCC2CC3AC, EMOTE_TYPE_ACTION},
        {"Idea", 0xEEC55CB7, EMOTE_TYPE_ACTION},
        {"Let's Craft", 0xE73CA11A, EMOTE_TYPE_ACTION},
        {"Let's Fish", 0x451FDE80, EMOTE_TYPE_ACTION},
        {"Let's Go", 0x5EFEBD3B, EMOTE_TYPE_ACTION},
        {"Let's Play Cards", 0xCDB9A85C, EMOTE_TYPE_ACTION},
        {"Listen", 0xB56B609E, EMOTE_TYPE_ACTION},
        {"Look Distance", 0x37BD5D0E, EMOTE_TYPE_ACTION},
        {"Look Yonder", 0x0078D3CC, EMOTE_TYPE_ACTION},
        {"New Threads", 0xC932823C, EMOTE_TYPE_ACTION},
        {"Point", 0x1CFB34E2, EMOTE_TYPE_ACTION},
        {"Posse Up", 0x1C46EA2F, EMOTE_TYPE_ACTION},
        {"Prayer", 0x325069E6, EMOTE_TYPE_ACTION},
        {"Prospector Jig", 0x4DF1E20B, EMOTE_TYPE_ACTION},
        {"Rock Paper Scissors", 0xB755B5B1, EMOTE_TYPE_ACTION},
        {"Scheme", 0x2322C484, EMOTE_TYPE_ACTION},
        {"Shoot Hip", 0x9E47E124, EMOTE_TYPE_ACTION},
        {"Skyward Shooting", 0x7396A2DE, EMOTE_TYPE_ACTION},
        {"Smoke Cigarette", 0x8B7F8EEB, EMOTE_TYPE_ACTION},
        {"Smoke Cigar", 0x81615BA3, EMOTE_TYPE_ACTION},
        {"Smoke Pipe", 0x89DAFC52, EMOTE_TYPE_ACTION},
        {"Spin and Aim", 0x3AE9C12A, EMOTE_TYPE_ACTION},
        {"Spit", 0x826DB95A, EMOTE_TYPE_ACTION},
        {"Spooky", 0xD0528D38, EMOTE_TYPE_ACTION},
        {"Stop Here", 0x9B31C214, EMOTE_TYPE_ACTION},
        {"Take Notes", 0xBA51B111, EMOTE_TYPE_ACTION}
    }},
    // Dances
    {{
        {"Awkward A", 0xEE810879, EMOTE_TYPE_DANCE_FLOOR},
        {"Carefree A", 0xF0AF179A, EMOTE_TYPE_DANCE_FLOOR},
        {"Carefree B", 0xDA4651B5, EMOTE_TYPE_DANCE_FLOOR},
        {"Confident A", 0xF504A733, EMOTE_TYPE_DANCE_FLOOR},
        {"Confident B", 0xFED34C73, EMOTE_TYPE_DANCE_FLOOR},
        {"Drunk A", 0x9548C407, EMOTE_TYPE_DANCE_FLOOR},
        {"Drunk B", 0x3E32E670, EMOTE_TYPE_DANCE_FLOOR},
        {"Formal A", 0x6FBDDC68, EMOTE_TYPE_DANCE_FLOOR},
        {"Graceful A", 0x847214D2, EMOTE_TYPE_DANCE_FLOOR},
        {"Old A", 0xCFC7AEBA, EMOTE_TYPE_DANCE_FLOOR},
        {"Wild A", 0x0CF840A9, EMOTE_TYPE_DANCE_FLOOR},
        {"Wild B", 0x43F71CA8, EMOTE_TYPE_DANCE_FLOOR}
    }},
    // Greetings
    {{
        {"Fancy Bow", 0x8186AA35, EMOTE_TYPE_GREET},
        {"Gentle Wave", 0x35B5A903, EMOTE_TYPE_GREET},
        {"Get Over Here", 0x9CA62011, EMOTE_TYPE_GREET},
        {"Glad", 0x1F3549C4, EMOTE_TYPE_GREET},
        {"Hat Flick", 0xE18A99A1, EMOTE_TYPE_GREET},
        {"Hat Tip", 0xA927A00F, EMOTE_TYPE_GREET},
        {"Hey You", 0x3196F0E3, EMOTE_TYPE_GREET},
        {"Outpour", 0xE68763B3, EMOTE_TYPE_GREET},
        {"Respectful Bow", 0x949C021C, EMOTE_TYPE_GREET},
        {"Seven", 0x3CB5E70E, EMOTE_TYPE_GREET},
        {"Subtle Wave", 0xA38D1E64, EMOTE_TYPE_GREET},
        {"Tada", 0xE4746943, EMOTE_TYPE_GREET},
        {"Thumbsup", 0x1960746B, EMOTE_TYPE_GREET},
        {"Tough", 0x700DD5CB, EMOTE_TYPE_GREET},
        {"Wave Near", 0xEBC75584, EMOTE_TYPE_GREET}
    }},
    // Reactions
    {{
        {"Amazed", 0xFD1A80D5, EMOTE_TYPE_REACT},
        {"Applause", 0xF2D01E20, EMOTE_TYPE_REACT},
        {"Beg Mercy", 0x09D39270, EMOTE_TYPE_REACT},
        {"Clap Along", 0xC84FB6B6, EMOTE_TYPE_REACT},
        {"Facepalm", 0xAD799324, EMOTE_TYPE_REACT},
        {"Hangover", 0xFB4C77D3, EMOTE_TYPE_REACT},
        {"How Dare You", 0x6B6D921F, EMOTE_TYPE_REACT},
        {"Hurl", 0xBD4EC3FB, EMOTE_TYPE_REACT},
        {"Hush Your Mouth", 0x9DF6FD3F, EMOTE_TYPE_REACT},
        {"Jovial Laugh", 0x11B0F575, EMOTE_TYPE_REACT},
        {"Nod Head", 0xCEF7AA76, EMOTE_TYPE_REACT},
        {"Phew", 0xAEC37CFB, EMOTE_TYPE_REACT},
        {"Point Laugh", 0x2FDFF3B2, EMOTE_TYPE_REACT},
        {"Scared", 0xB1C3DE80, EMOTE_TYPE_REACT},
        {"Shake Head", 0xD91245C6, EMOTE_TYPE_REACT},
        {"Shot", 0xF96C2623, EMOTE_TYPE_REACT},
        {"Shrug", 0x2E097BB5, EMOTE_TYPE_REACT},
        {"Shuffle", 0xC4610D39, EMOTE_TYPE_REACT},
        {"Slow Clap", 0x3D04F806, EMOTE_TYPE_REACT},
        {"Sniffing", 0xAFF1D9B3, EMOTE_TYPE_REACT},
        {"Sob", 0x04D94578, EMOTE_TYPE_REACT},
        {"Surrender", 0xC303F8C3, EMOTE_TYPE_REACT},
        {"Thanks", 0x7FCB989C, EMOTE_TYPE_REACT},
        {"Thumbsdown", 0x59F420A1, EMOTE_TYPE_REACT},
        {"Wag Finger", 0xFF45D102, EMOTE_TYPE_REACT},
        {"Who Me", 0x13A5C689, EMOTE_TYPE_REACT},
        {"Yeehaw", 0x1A92F963, EMOTE_TYPE_REACT}
    }},
    // Taunts
    {{
        {"Best Shot", 0x5E4C76AD, EMOTE_TYPE_TAUNT},
        {"Boohoo", 0x0EB7A5F2, EMOTE_TYPE_TAUNT},
        {"Chicken", 0x6CC9FE53, EMOTE_TYPE_TAUNT},
        {"Cougar Snarl", 0x299BD92F, EMOTE_TYPE_TAUNT},
        {"Cuckoo", 0xA25C7339, EMOTE_TYPE_TAUNT},
        {"Fake Draw", 0xFE94B69A, EMOTE_TYPE_TAUNT},
        {"Fiddlehead", 0x203F0CD8, EMOTE_TYPE_TAUNT},
        {"Finger Slinger", 0xD097AF13, EMOTE_TYPE_TAUNT},
        {"Flip Off", 0x39C68938, EMOTE_TYPE_TAUNT},
        {"Frighten", 0xBA4E4740, EMOTE_TYPE_TAUNT},
        {"Gorilla Chest", 0x711D2A1F, EMOTE_TYPE_TAUNT},
        {"I'm Watching You", 0xDF036AFF, EMOTE_TYPE_TAUNT},
        {"Provoke", 0x5B65DD1D, EMOTE_TYPE_TAUNT},
        {"Ripper", 0x6C281B79, EMOTE_TYPE_TAUNT},
        {"Throat Slit", 0x4AE9E06C, EMOTE_TYPE_TAUNT},
        {"Up Yours", 0x15216DE4, EMOTE_TYPE_TAUNT},
        {"Versus", 0x828C7F5B, EMOTE_TYPE_TAUNT},
        {"War Cry", 0x3AD8141A, EMOTE_TYPE_TAUNT},
        {"You Stink", 0xF6130E04, EMOTE_TYPE_TAUNT}
    }}
    }};
}
