#pragma once
#include "util/Joaat.hpp"

namespace rage
{
	class scrThread;
	class scrProgram;
}

namespace YimMenu
{
	// internal struct to track SP/MP status along with script hash
	struct ScriptIdentifier
	{
		joaat_t m_Hash;
		bool m_IsMp;

		ScriptIdentifier(joaat_t hash, bool is_mp) :
		    m_Hash(hash),
		    m_IsMp(is_mp)
		{
		}

		ScriptIdentifier() :
		    m_Hash(0),
		    m_IsMp(false)
		{

		}

		bool operator==(const ScriptIdentifier& other)
		{
			return m_Hash == other.m_Hash && m_IsMp == other.m_IsMp;
		}

		bool operator!=(const ScriptIdentifier& other)
		{
			return m_Hash != other.m_Hash || m_IsMp != other.m_IsMp;
		}

		// is serialized in a few places
		friend void to_json(nlohmann::json& nlohmann_json_j, const ScriptIdentifier& nlohmann_json_t)
		{
			nlohmann_json_j["hash"] = nlohmann_json_t.m_Hash;
			nlohmann_json_j["is_mp"] = nlohmann_json_t.m_IsMp;
		}

		friend void from_json(const nlohmann::json& nlohmann_json_j, ScriptIdentifier& nlohmann_json_t)
		{
			nlohmann_json_j.at("hash").get_to(nlohmann_json_t.m_Hash);
			nlohmann_json_j.at("is_mp").get_to(nlohmann_json_t.m_IsMp);
		}; 
	};
}

namespace YimMenu::Scripts
{
	extern rage::scrThread* FindScriptThread(joaat_t hash);
	extern rage::scrProgram* FindScriptProgram(joaat_t hash);
	extern void RunAsScript(rage::scrThread* thread, std::function<void()> callback);
	extern void SendScriptEvent(uint64_t* data, int count, int metadataIndex, int bits);
	extern const char* GetScriptName(joaat_t hash);
	extern void ForceScriptHost(rage::scrThread* thread);
	extern bool RequestScript(joaat_t script);
	extern bool UsingMPScripts();
	extern ScriptIdentifier GetScriptIdentifier(rage::scrThread* thread);
}