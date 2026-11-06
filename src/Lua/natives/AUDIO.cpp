#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_AUDIO__0x7455CD705F7E933E()
	{
		AUDIO::_0x7455CD705F7E933E();
	}

	static void LUA_NATIVE_AUDIO_CLEAR_CONVERSATION_HISTORY()
	{
		AUDIO::CLEAR_CONVERSATION_HISTORY();
	}

	static void LUA_NATIVE_AUDIO__CLEAR_CONVERSATION_HISTORY_FOR_SCRIPTED_CONVERSATION(sol::stack_object convoRoot)
	{
		AUDIO::_CLEAR_CONVERSATION_HISTORY_FOR_SCRIPTED_CONVERSATION(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO_CREATE_NEW_SCRIPTED_CONVERSATION(sol::stack_object convoRoot)
	{
		auto retval = (bool)AUDIO::CREATE_NEW_SCRIPTED_CONVERSATION(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__0xDF947FE0D551684E(Ped ped, sol::stack_object p1)
	{
		auto retval = (bool)AUDIO::_0xDF947FE0D551684E(ped, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_ADD_PED_TO_CONVERSATION(sol::stack_object convoRoot, Ped SpeakerPedIndex, sol::stack_object characterName)
	{
		AUDIO::ADD_PED_TO_CONVERSATION(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr, SpeakerPedIndex, characterName.is<const char*>() ? characterName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__0xA2323A2EAE32A290(Ped listeningToPed, Ped ped, sol::stack_object listenerName)
	{
		AUDIO::_0xA2323A2EAE32A290(listeningToPed, ped, listenerName.is<const char*>() ? listenerName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO__0x79F9C57B8D0DFE90(sol::stack_object convoRoot, AnimScene animScene)
	{
		auto retval = (bool)AUDIO::_0x79F9C57B8D0DFE90(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr, animScene);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_START_SCRIPT_CONVERSATION(sol::stack_object convoRoot, bool p1, bool p2, bool cloneConversation)
	{
		AUDIO::START_SCRIPT_CONVERSATION(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr, p1, p2, cloneConversation);
	}

	static void LUA_NATIVE_AUDIO_PRELOAD_SCRIPT_CONVERSATION(sol::stack_object convoRoot, bool p1, bool p2, bool cloneConversation)
	{
		AUDIO::PRELOAD_SCRIPT_CONVERSATION(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr, p1, p2, cloneConversation);
	}

	static void LUA_NATIVE_AUDIO_START_PRELOADED_CONVERSATION(sol::stack_object convoRoot)
	{
		AUDIO::START_PRELOADED_CONVERSATION(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO__0x0CB3D1919E8D7CBA(sol::stack_object convoRoot)
	{
		auto retval = (bool)AUDIO::_0x0CB3D1919E8D7CBA(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__0xFE5C6177064BD390(bool p0)
	{
		auto retval = (bool)AUDIO::_0xFE5C6177064BD390(p0);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__IS_SCRIPTED_CONVERSATION_CREATED(sol::stack_object convoRoot)
	{
		auto retval = (bool)AUDIO::_IS_SCRIPTED_CONVERSATION_CREATED(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__0x5A13586A9447931F(bool p0)
	{
		auto retval = (bool)AUDIO::_0x5A13586A9447931F(p0);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_IS_SCRIPTED_CONVERSATION_LOADED(sol::stack_object convoRoot)
	{
		auto retval = (bool)AUDIO::IS_SCRIPTED_CONVERSATION_LOADED(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__IS_ANY_CONVERSATION_PLAYING(bool p0)
	{
		auto retval = (bool)AUDIO::_IS_ANY_CONVERSATION_PLAYING(p0);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_IS_SCRIPTED_CONVERSATION_PLAYING(sol::stack_object p0)
	{
		auto retval = (bool)AUDIO::IS_SCRIPTED_CONVERSATION_PLAYING(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__IS_SCRIPTED_CONVERSION_ONGOING(sol::stack_object p0)
	{
		auto retval = (bool)AUDIO::_IS_SCRIPTED_CONVERSION_ONGOING(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__0x847748AE5D7B1071(bool p0)
	{
		auto retval = (bool)AUDIO::_0x847748AE5D7B1071(p0);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__0xD0730C1FA40348D9(sol::stack_object convoRoot)
	{
		auto retval = (bool)AUDIO::_0xD0730C1FA40348D9(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_AUDIO_GET_CURRENT_SCRIPTED_CONVERSATION_LINE(sol::stack_object p0)
	{
		auto retval = AUDIO::GET_CURRENT_SCRIPTED_CONVERSATION_LINE(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_PAUSE_SCRIPTED_CONVERSATION(sol::stack_object p0, bool p1, bool p2, bool p3, bool p4)
	{
		AUDIO::PAUSE_SCRIPTED_CONVERSATION(p0.is<const char*>() ? p0.as<const char*>() : nullptr, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_AUDIO_RESTART_SCRIPTED_CONVERSATION(sol::stack_object p0)
	{
		AUDIO::RESTART_SCRIPTED_CONVERSATION(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__STOP_ALL_SCRIPTED_CONVERSIONS(bool p0, bool p1, bool p2)
	{
		AUDIO::_STOP_ALL_SCRIPTED_CONVERSIONS(p0, p1, p2);
	}

	static int LUA_NATIVE_AUDIO_STOP_SCRIPTED_CONVERSATION(sol::stack_object p0, bool p1, bool p2)
	{
		auto retval = AUDIO::STOP_SCRIPTED_CONVERSATION(p0.is<const char*>() ? p0.as<const char*>() : nullptr, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE(sol::stack_object p0)
	{
		AUDIO::SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static int LUA_NATIVE_AUDIO__0xF336E9F989B3518F(sol::stack_object p0)
	{
		auto retval = AUDIO::_0xF336E9F989B3518F(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static Ped LUA_NATIVE_AUDIO__0x254B0241E964B450(sol::stack_object p0, int currentScriptedConvoLine)
	{
		auto retval = AUDIO::_0x254B0241E964B450(p0.is<const char*>() ? p0.as<const char*>() : nullptr, currentScriptedConvoLine);
		return retval;
	}

	static Ped LUA_NATIVE_AUDIO__0x152ED1B56E8F1F50(sol::stack_object p0, int currentScriptedConvoLine)
	{
		auto retval = AUDIO::_0x152ED1B56E8F1F50(p0.is<const char*>() ? p0.as<const char*>() : nullptr, currentScriptedConvoLine);
		return retval;
	}

	static int LUA_NATIVE_AUDIO__0x935DBD96D4A3DA1F(sol::stack_object p0, int currentScriptedConvoLine)
	{
		auto retval = AUDIO::_0x935DBD96D4A3DA1F(p0.is<const char*>() ? p0.as<const char*>() : nullptr, currentScriptedConvoLine);
		return retval;
	}

	static int LUA_NATIVE_AUDIO__0x295859EB18F48D82(sol::stack_object p0)
	{
		auto retval = AUDIO::_0x295859EB18F48D82(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x40CA665AB9D8D505(sol::stack_object convoRoot, int singleLineIndex)
	{
		AUDIO::_0x40CA665AB9D8D505(convoRoot.is<const char*>() ? convoRoot.as<const char*>() : nullptr, singleLineIndex);
	}

	static void LUA_NATIVE_AUDIO__0xF232C2C546AC16D0(sol::stack_object p0)
	{
		AUDIO::_0xF232C2C546AC16D0(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__0x1E6F9A9FE1A99F36(sol::stack_object audSpeechEvent)
	{
		AUDIO::_0x1E6F9A9FE1A99F36(audSpeechEvent.is<const char*>() ? audSpeechEvent.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO_REGISTER_SCRIPT_WITH_AUDIO(bool InChargeOfAudio)
	{
		AUDIO::REGISTER_SCRIPT_WITH_AUDIO(InChargeOfAudio);
	}

	static void LUA_NATIVE_AUDIO_UNREGISTER_SCRIPT_WITH_AUDIO()
	{
		AUDIO::UNREGISTER_SCRIPT_WITH_AUDIO();
	}

	static bool LUA_NATIVE_AUDIO_REQUEST_SCRIPT_AUDIO_BANK(sol::stack_object BankName)
	{
		auto retval = (bool)AUDIO::REQUEST_SCRIPT_AUDIO_BANK(BankName.is<const char*>() ? BankName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_RELEASE_NAMED_SCRIPT_AUDIO_BANK(sol::stack_object BankName)
	{
		AUDIO::RELEASE_NAMED_SCRIPT_AUDIO_BANK(BankName.is<const char*>() ? BankName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO_RELEASE_SCRIPT_AUDIO_BANK()
	{
		AUDIO::RELEASE_SCRIPT_AUDIO_BANK();
	}

	static int LUA_NATIVE_AUDIO_GET_SOUND_ID()
	{
		auto retval = AUDIO::GET_SOUND_ID();
		return retval;
	}

	static void LUA_NATIVE_AUDIO_RELEASE_SOUND_ID(int SoundId)
	{
		AUDIO::RELEASE_SOUND_ID(SoundId);
	}

	static void LUA_NATIVE_AUDIO_PLAY_SOUND(sol::stack_object SoundName, sol::stack_object SetName, bool p2, Any p3, bool p4, Any p5)
	{
		AUDIO::PLAY_SOUND(SoundName.is<const char*>() ? SoundName.as<const char*>() : nullptr, SetName.is<const char*>() ? SetName.as<const char*>() : nullptr, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_AUDIO_PLAY_SOUND_FRONTEND(sol::stack_object SoundName, sol::stack_object SetName, bool p2, Any p3)
	{
		AUDIO::PLAY_SOUND_FRONTEND(SoundName.is<const char*>() ? SoundName.as<const char*>() : nullptr, SetName.is<const char*>() ? SetName.as<const char*>() : nullptr, p2, p3);
	}

	static void LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_ITEM(Hash item, Hash soundSet, Any p2)
	{
		AUDIO::_PLAY_SOUND_FROM_ITEM(item, soundSet, p2);
	}

	static void LUA_NATIVE_AUDIO_PLAY_SOUND_FROM_ENTITY(sol::stack_object audioName, Entity entity, sol::stack_object audioRef, bool isNetwork, Any p4, Any p5)
	{
		AUDIO::PLAY_SOUND_FROM_ENTITY(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, entity, audioRef.is<const char*>() ? audioRef.as<const char*>() : nullptr, isNetwork, p4, p5);
	}

	static void LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_POSITION(sol::stack_object audioName, float x, float y, float z, sol::stack_object audioRef, bool isNetwork, Any p6, bool p7, Any p8)
	{
		AUDIO::_PLAY_SOUND_FROM_POSITION(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, x, y, z, audioRef.is<const char*>() ? audioRef.as<const char*>() : nullptr, isNetwork, p6, p7, p8);
	}

	static void LUA_NATIVE_AUDIO__STOP_SOUND_WITH_NAME(sol::stack_object audioName, sol::stack_object audioRef)
	{
		AUDIO::_STOP_SOUND_WITH_NAME(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, audioRef.is<const char*>() ? audioRef.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO__0x580D71DFE0088E34(sol::stack_object audioName, sol::stack_object audioRef)
	{
		auto retval = (bool)AUDIO::_0x580D71DFE0088E34(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, audioRef.is<const char*>() ? audioRef.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__IS_SCRIPTED_AUDIO_CUSTOM(Hash item, Hash soundSet)
	{
		auto retval = (bool)AUDIO::_IS_SCRIPTED_AUDIO_CUSTOM(item, soundSet);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__SET_VARIABLE_ON_SOUND_WITH_NAME(sol::stack_object variableName, float variableValue, sol::stack_object audioName, sol::stack_object audioRef)
	{
		AUDIO::_SET_VARIABLE_ON_SOUND_WITH_NAME(variableName.is<const char*>() ? variableName.as<const char*>() : nullptr, variableValue, audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, audioRef.is<const char*>() ? audioRef.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__SET_WHISTLE_CONFIG_FOR_PED(Ped ped, sol::stack_object whistleConfig, float value)
	{
		AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(ped, whistleConfig.is<const char*>() ? whistleConfig.as<const char*>() : nullptr, value);
	}

	static void LUA_NATIVE_AUDIO__SET_SOUND_RELATIONSHIP_ON_PED(Ped ped, sol::stack_object p1, sol::stack_object p2)
	{
		AUDIO::_SET_SOUND_RELATIONSHIP_ON_PED(ped, p1.is<const char*>() ? p1.as<const char*>() : nullptr, p2.is<const char*>() ? p2.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__PLAY_SOUND_FRONTEND_WITH_SOUND_ID(int soundId, sol::stack_object name, sol::stack_object soundSet, bool p3)
	{
		AUDIO::_PLAY_SOUND_FRONTEND_WITH_SOUND_ID(soundId, name.is<const char*>() ? name.as<const char*>() : nullptr, soundSet.is<const char*>() ? soundSet.as<const char*>() : nullptr, p3);
	}

	static void LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_ENTITY_WITH_SET(int soundId, sol::stack_object soundName, Entity entity, sol::stack_object soundsetName, bool p4, Any p5)
	{
		AUDIO::_PLAY_SOUND_FROM_ENTITY_WITH_SET(soundId, soundName.is<const char*>() ? soundName.as<const char*>() : nullptr, entity, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr, p4, p5);
	}

	static void LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_POSITION_WITH_ID(int soundId, sol::stack_object soundName, float x, float y, float z, sol::stack_object soundsetName, bool p6, int p7, bool p8)
	{
		AUDIO::_PLAY_SOUND_FROM_POSITION_WITH_ID(soundId, soundName.is<const char*>() ? soundName.as<const char*>() : nullptr, x, y, z, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr, p6, p7, p8);
	}

	static void LUA_NATIVE_AUDIO__UPDATE_SOUND_POSITION(int soundId, float x, float y, float z)
	{
		AUDIO::_UPDATE_SOUND_POSITION(soundId, x, y, z);
	}

	static void LUA_NATIVE_AUDIO__STOP_SOUND_WITH_ID(int soundId)
	{
		AUDIO::_STOP_SOUND_WITH_ID(soundId);
	}

	static void LUA_NATIVE_AUDIO__SET_VARIABLE_ON_SOUND_WITH_ID(int soundId, sol::stack_object variableName, float variableValue)
	{
		AUDIO::_SET_VARIABLE_ON_SOUND_WITH_ID(soundId, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr, variableValue);
	}

	static bool LUA_NATIVE_AUDIO_PREPARE_SOUND(sol::stack_object soundName, sol::stack_object soundsetName, int soundId)
	{
		auto retval = (bool)AUDIO::PREPARE_SOUND(soundName.is<const char*>() ? soundName.as<const char*>() : nullptr, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr, soundId);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__RELEASE_SHARD_SOUNDS(sol::stack_object soundName, sol::stack_object soundsetName)
	{
		AUDIO::_RELEASE_SHARD_SOUNDS(soundName.is<const char*>() ? soundName.as<const char*>() : nullptr, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO_PREPARE_SOUNDSET(sol::stack_object soundsetName, bool p1)
	{
		auto retval = (bool)AUDIO::PREPARE_SOUNDSET(soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr, p1);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__RELEASE_SOUNDSET(sol::stack_object soundsetName)
	{
		AUDIO::_RELEASE_SOUNDSET(soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO_PREPARE_SOUND_WITH_ENTITY(sol::stack_object soundName, Entity entity, sol::stack_object soundsetName, int soundId)
	{
		auto retval = (bool)AUDIO::PREPARE_SOUND_WITH_ENTITY(soundName.is<const char*>() ? soundName.as<const char*>() : nullptr, entity, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr, soundId);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x3E93DDDCBB6111E4(sol::stack_object p0, float p1)
	{
		AUDIO::_0x3E93DDDCBB6111E4(p0.is<const char*>() ? p0.as<const char*>() : nullptr, p1);
	}

	static bool LUA_NATIVE_AUDIO__HAS_SOUND_AUDIO_NAME_FINISHED(sol::stack_object audioName, sol::stack_object soundsetName)
	{
		auto retval = (bool)AUDIO::_HAS_SOUND_AUDIO_NAME_FINISHED(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__HAS_SOUND_ID_FINISHED(int soundId)
	{
		auto retval = (bool)AUDIO::_HAS_SOUND_ID_FINISHED(soundId);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_PLAY_PED_AMBIENT_SPEECH_NATIVE(Ped PedIndex, uintptr_t params)
	{
		auto retval = (bool)AUDIO::PLAY_PED_AMBIENT_SPEECH_NATIVE(PedIndex, (Any*)params);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_PLAY_AMBIENT_SPEECH_FROM_POSITION_NATIVE(float PositionX, float PositionY, float PositionZ, uintptr_t params)
	{
		auto retval = (bool)AUDIO::PLAY_AMBIENT_SPEECH_FROM_POSITION_NATIVE(PositionX, PositionY, PositionZ, (Any*)params);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0x72E4D1C4639BC465(Entity p0, Any p1)
	{
		auto retval = AUDIO::_0x72E4D1C4639BC465(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xB18FEC133C7C6C69(Any p0)
	{
		auto retval = AUDIO::_0xB18FEC133C7C6C69(p0);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0xDC93F0948F2C28F4(Any p0)
	{
		AUDIO::_0xDC93F0948F2C28F4(p0);
	}

	static void LUA_NATIVE_AUDIO__0x0D7FD6A55FD63AEF(int speechEventType, int p1, bool p2)
	{
		AUDIO::_0x0D7FD6A55FD63AEF(speechEventType, p1, p2);
	}

	static void LUA_NATIVE_AUDIO__0x660A8F876DF1D4F8(int speechEventType)
	{
		AUDIO::_0x660A8F876DF1D4F8(speechEventType);
	}

	static void LUA_NATIVE_AUDIO__0x380A2E353AD30917(Any p0, Any p1, Any p2)
	{
		AUDIO::_0x380A2E353AD30917(p0, p1, p2);
	}

	static void LUA_NATIVE_AUDIO__0x0FAF7171BF613B80(Any p0)
	{
		AUDIO::_0x0FAF7171BF613B80(p0);
	}

	static void LUA_NATIVE_AUDIO_PLAY_PAIN(Ped PedIndex, int DamageReason, float RawDamage, bool p3, bool SyncOverNetwork)
	{
		AUDIO::PLAY_PAIN(PedIndex, DamageReason, RawDamage, p3, SyncOverNetwork);
	}

	static void LUA_NATIVE_AUDIO__0x6652B0C8F3D414D0(Any p0)
	{
		AUDIO::_0x6652B0C8F3D414D0(p0);
	}

	static void LUA_NATIVE_AUDIO__0xF092B6030D6FD49C(int ropeId, sol::stack_object name)
	{
		AUDIO::_0xF092B6030D6FD49C(ropeId, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__0x2651DDC0EA269073(int ropeId, float p1)
	{
		AUDIO::_0x2651DDC0EA269073(ropeId, p1);
	}

	static void LUA_NATIVE_AUDIO_SET_AMBIENT_VOICE_NAME(Ped PedIndex, sol::stack_object VoiceName)
	{
		AUDIO::SET_AMBIENT_VOICE_NAME(PedIndex, VoiceName.is<const char*>() ? VoiceName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__SET_VOFX_PED_VOICE(Ped ped, Hash voice)
	{
		AUDIO::_SET_VOFX_PED_VOICE(ped, voice);
	}

	static void LUA_NATIVE_AUDIO_STOP_CURRENT_PLAYING_SPEECH(Ped PedIndex, Any p1)
	{
		AUDIO::STOP_CURRENT_PLAYING_SPEECH(PedIndex, p1);
	}

	static void LUA_NATIVE_AUDIO_STOP_CURRENT_PLAYING_AMBIENT_SPEECH(Ped PedIndex, Any p1)
	{
		AUDIO::STOP_CURRENT_PLAYING_AMBIENT_SPEECH(PedIndex, p1);
	}

	static bool LUA_NATIVE_AUDIO_IS_AMBIENT_SPEECH_PLAYING(Ped PedIndex)
	{
		auto retval = (bool)AUDIO::IS_AMBIENT_SPEECH_PLAYING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_IS_SCRIPTED_SPEECH_PLAYING(Ped PedIndex)
	{
		auto retval = (bool)AUDIO::IS_SCRIPTED_SPEECH_PLAYING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_IS_ANY_SPEECH_PLAYING(Ped PedIndex)
	{
		auto retval = (bool)AUDIO::IS_ANY_SPEECH_PLAYING(PedIndex);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0x2B101AD9F651243A()
	{
		auto retval = AUDIO::_0x2B101AD9F651243A();
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0x4A98E228A936DBCC(Any p0)
	{
		auto retval = AUDIO::_0x4A98E228A936DBCC(p0);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0x6BFFB7C276866996(Any p0)
	{
		auto retval = AUDIO::_0x6BFFB7C276866996(p0);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_DOES_CONTEXT_EXIST_FOR_THIS_PED(Ped PedIndex, sol::stack_object context, bool allowBackupPVG)
	{
		auto retval = (bool)AUDIO::DOES_CONTEXT_EXIST_FOR_THIS_PED(PedIndex, context.is<const char*>() ? context.as<const char*>() : nullptr, allowBackupPVG);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xF0EE69F500952FA5(Any p0)
	{
		auto retval = AUDIO::_0xF0EE69F500952FA5(p0);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0x9D6DEC9791A4E501(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = AUDIO::_0x9D6DEC9791A4E501(p0, p1, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x864A842B86993851(Ped ped)
	{
		AUDIO::_0x864A842B86993851(ped);
	}

	static bool LUA_NATIVE_AUDIO_IS_PED_IN_CURRENT_CONVERSATION(sol::stack_object p0, Ped PedIndex, Any p2)
	{
		auto retval = (bool)AUDIO::IS_PED_IN_CURRENT_CONVERSATION(p0.is<const char*>() ? p0.as<const char*>() : nullptr, PedIndex, p2);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO__IS_PED_IN_ANY_CONVERSATION(Ped ped, bool p1)
	{
		auto retval = (bool)AUDIO::_IS_PED_IN_ANY_CONVERSATION(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_SET_PED_IS_DRUNK(Ped PedIndex, bool IsDrunk)
	{
		AUDIO::SET_PED_IS_DRUNK(PedIndex, IsDrunk);
	}

	static void LUA_NATIVE_AUDIO__0x3A00D87B20A2A5E4(Any p0, Any p1)
	{
		AUDIO::_0x3A00D87B20A2A5E4(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0xD47D47EFBF103FB8(Any p0, Any p1)
	{
		AUDIO::_0xD47D47EFBF103FB8(p0, p1);
	}

	static void LUA_NATIVE_AUDIO_PLAY_ANIMAL_VOCALIZATION(Ped PedIndex, sol::stack_object vocalizationName, bool p2)
	{
		AUDIO::PLAY_ANIMAL_VOCALIZATION(PedIndex, vocalizationName.is<const char*>() ? vocalizationName.as<const char*>() : nullptr, p2);
	}

	static void LUA_NATIVE_AUDIO__PLAY_ANIMAL_VOCALIZATION_PHEROMONE_VIAL_RESPONSE(Ped ped, Hash p1, bool p2)
	{
		AUDIO::_PLAY_ANIMAL_VOCALIZATION_PHEROMONE_VIAL_RESPONSE(ped, p1, p2);
	}

	static bool LUA_NATIVE_AUDIO_IS_ANIMAL_VOCALIZATION_PLAYING(Ped PedIndex)
	{
		auto retval = (bool)AUDIO::IS_ANIMAL_VOCALIZATION_PLAYING(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_SET_ANIMAL_MOOD(Ped PedIndex, int Mood)
	{
		AUDIO::SET_ANIMAL_MOOD(PedIndex, Mood);
	}

	static void LUA_NATIVE_AUDIO__0xFCDEC42B1C78B7F8(Any p0, Any p1)
	{
		AUDIO::_0xFCDEC42B1C78B7F8(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0xEB4D592620B8C209(Any p0)
	{
		AUDIO::_0xEB4D592620B8C209(p0);
	}

	static void LUA_NATIVE_AUDIO__0xA6847BBA4FCDD13F(Any p0, Any p1)
	{
		AUDIO::_0xA6847BBA4FCDD13F(p0, p1);
	}

	static void LUA_NATIVE_AUDIO_SET_STATIC_EMITTER_ENABLED(sol::stack_object EmitterName, bool enabled)
	{
		AUDIO::SET_STATIC_EMITTER_ENABLED(EmitterName.is<const char*>() ? EmitterName.as<const char*>() : nullptr, enabled);
	}

	static void LUA_NATIVE_AUDIO_PLAY_END_CREDITS_MUSIC(bool bActive)
	{
		AUDIO::PLAY_END_CREDITS_MUSIC(bActive);
	}

	static Any LUA_NATIVE_AUDIO__0x7678FE0455ED1145(Any p0, Any p1, Any p2)
	{
		auto retval = AUDIO::_0x7678FE0455ED1145(p0, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xFFE9C53DEEA3DB0B(Any p0, Any p1, float x, float y, float z, bool isSrlLoaded, Any p6)
	{
		auto retval = AUDIO::_0xFFE9C53DEEA3DB0B(p0, p1, x, y, z, isSrlLoaded, p6);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x5E3CCF03995388B5(Any p0, Any p1, Any p2, Any p3)
	{
		AUDIO::_0x5E3CCF03995388B5(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_AUDIO__0x43037ABFE214A851()
	{
		AUDIO::_0x43037ABFE214A851();
	}

	static void LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_STATE(sol::stack_object zoneName, bool enabled, bool forceUpdate)
	{
		AUDIO::SET_AMBIENT_ZONE_STATE(zoneName.is<const char*>() ? zoneName.as<const char*>() : nullptr, enabled, forceUpdate);
	}

	static void LUA_NATIVE_AUDIO_CLEAR_AMBIENT_ZONE_STATE(sol::stack_object zoneName, bool forceUpdate)
	{
		AUDIO::CLEAR_AMBIENT_ZONE_STATE(zoneName.is<const char*>() ? zoneName.as<const char*>() : nullptr, forceUpdate);
	}

	static void LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_LIST_STATE(sol::stack_object zoneListName, bool enabled, bool forceUpdate)
	{
		AUDIO::SET_AMBIENT_ZONE_LIST_STATE(zoneListName.is<const char*>() ? zoneListName.as<const char*>() : nullptr, enabled, forceUpdate);
	}

	static void LUA_NATIVE_AUDIO_CLEAR_AMBIENT_ZONE_LIST_STATE(sol::stack_object zoneListName, bool forceUpdate)
	{
		AUDIO::CLEAR_AMBIENT_ZONE_LIST_STATE(zoneListName.is<const char*>() ? zoneListName.as<const char*>() : nullptr, forceUpdate);
	}

	static void LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_STATE_PERSISTENT(sol::stack_object zoneName, bool enabled, bool forceUpdate)
	{
		AUDIO::SET_AMBIENT_ZONE_STATE_PERSISTENT(zoneName.is<const char*>() ? zoneName.as<const char*>() : nullptr, enabled, forceUpdate);
	}

	static void LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT(sol::stack_object zoneListName, bool enabled, bool forceUpdate)
	{
		AUDIO::SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT(zoneListName.is<const char*>() ? zoneListName.as<const char*>() : nullptr, enabled, forceUpdate);
	}

	static void LUA_NATIVE_AUDIO__SET_AMBIENT_ZONE_POSITION(sol::stack_object ambientZone, float x, float y, float z, float heading)
	{
		AUDIO::_SET_AMBIENT_ZONE_POSITION(ambientZone.is<const char*>() ? ambientZone.as<const char*>() : nullptr, x, y, z, heading);
	}

	static bool LUA_NATIVE_AUDIO_IS_HORN_ACTIVE(Vehicle VehIndex)
	{
		auto retval = (bool)AUDIO::IS_HORN_ACTIVE(VehIndex);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0xFD461D0ABA5559B1(Any p0, Any p1)
	{
		AUDIO::_0xFD461D0ABA5559B1(p0, p1);
	}

	static bool LUA_NATIVE_AUDIO_IS_STREAM_PLAYING(int streamId)
	{
		auto retval = (bool)AUDIO::IS_STREAM_PLAYING(streamId);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_LOAD_STREAM(sol::stack_object streamName, sol::stack_object SetName)
	{
		auto retval = (bool)AUDIO::LOAD_STREAM(streamName.is<const char*>() ? streamName.as<const char*>() : nullptr, SetName.is<const char*>() ? SetName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_PLAY_STREAM_FROM_PED(Ped PedIndex, int streamId)
	{
		AUDIO::PLAY_STREAM_FROM_PED(PedIndex, streamId);
	}

	static void LUA_NATIVE_AUDIO_PLAY_STREAM_FRONTEND(int streamId)
	{
		AUDIO::PLAY_STREAM_FRONTEND(streamId);
	}

	static void LUA_NATIVE_AUDIO_PLAY_STREAM_FROM_POSITION(float positionX, float positionY, float positionZ, int streamId)
	{
		AUDIO::PLAY_STREAM_FROM_POSITION(positionX, positionY, positionZ, streamId);
	}

	static void LUA_NATIVE_AUDIO__0x3A3BE6B920525237(Any p0, Any p1)
	{
		AUDIO::_0x3A3BE6B920525237(p0, p1);
	}

	static void LUA_NATIVE_AUDIO_STOP_STREAM(int streamId)
	{
		AUDIO::STOP_STREAM(streamId);
	}

	static void LUA_NATIVE_AUDIO_STOP_PED_SPEAKING(Ped PedIndex, bool ShouldDisable)
	{
		AUDIO::STOP_PED_SPEAKING(PedIndex, ShouldDisable);
	}

	static void LUA_NATIVE_AUDIO_DISABLE_PED_PAIN_AUDIO(Ped PedIndex, bool ShouldDisable)
	{
		AUDIO::DISABLE_PED_PAIN_AUDIO(PedIndex, ShouldDisable);
	}

	static bool LUA_NATIVE_AUDIO_IS_AMBIENT_SPEECH_DISABLED(Ped PedIndex)
	{
		auto retval = (bool)AUDIO::IS_AMBIENT_SPEECH_DISABLED(PedIndex);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO_SET_IS_SCRIPTED_SPEECH_DISABLED(Ped ped, bool disabled)
	{
		auto retval = AUDIO::SET_IS_SCRIPTED_SPEECH_DISABLED(ped, disabled);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__BLOCK_SPEECH_CONTEXT(sol::stack_object context, bool block)
	{
		AUDIO::_BLOCK_SPEECH_CONTEXT(context.is<const char*>() ? context.as<const char*>() : nullptr, block);
	}

	static void LUA_NATIVE_AUDIO__UNLOAD_SPEECH_CONTEXT(sol::stack_object speechContext)
	{
		AUDIO::_UNLOAD_SPEECH_CONTEXT(speechContext.is<const char*>() ? speechContext.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO_SET_HORN_ENABLED(Vehicle VehicleIndex, bool Enable)
	{
		AUDIO::SET_HORN_ENABLED(VehicleIndex, Enable);
	}

	static void LUA_NATIVE_AUDIO_SET_AUDIO_VEHICLE_PRIORITY(Vehicle VehicleIndex, int priority)
	{
		AUDIO::SET_AUDIO_VEHICLE_PRIORITY(VehicleIndex, priority);
	}

	static void LUA_NATIVE_AUDIO__0x259ACC5B52A2B2D9(Any p0, Any p1)
	{
		AUDIO::_0x259ACC5B52A2B2D9(p0, p1);
	}

	static void LUA_NATIVE_AUDIO_FORCE_USE_AUDIO_GAME_OBJECT(Vehicle VehicleIndex, sol::stack_object GameObjectName)
	{
		AUDIO::FORCE_USE_AUDIO_GAME_OBJECT(VehicleIndex, GameObjectName.is<const char*>() ? GameObjectName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO_SET_GPS_ACTIVE(bool DisableGps)
	{
		AUDIO::SET_GPS_ACTIVE(DisableGps);
	}

	static bool LUA_NATIVE_AUDIO__START_AUDIO_SCENESET(sol::stack_object audioName, sol::stack_object sceneset)
	{
		auto retval = (bool)AUDIO::_START_AUDIO_SCENESET(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, sceneset.is<const char*>() ? sceneset.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__STOP_AUDIO_SCENESET(sol::stack_object sceneset)
	{
		AUDIO::_STOP_AUDIO_SCENESET(sceneset.is<const char*>() ? sceneset.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_AUDIO__SET_AUDIO_SCENESET(sol::stack_object audioName, sol::stack_object sceneset)
	{
		auto retval = (bool)AUDIO::_SET_AUDIO_SCENESET(audioName.is<const char*>() ? audioName.as<const char*>() : nullptr, sceneset.is<const char*>() ? sceneset.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_START_AUDIO_SCENE(sol::stack_object SceneName)
	{
		auto retval = (bool)AUDIO::START_AUDIO_SCENE(SceneName.is<const char*>() ? SceneName.as<const char*>() : nullptr);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xDC2F83A0612CA34D(Any p0)
	{
		auto retval = AUDIO::_0xDC2F83A0612CA34D(p0);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_STOP_AUDIO_SCENE(sol::stack_object SceneName)
	{
		AUDIO::STOP_AUDIO_SCENE(SceneName.is<const char*>() ? SceneName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__0x6AB944DF68B512D3(Any p0)
	{
		AUDIO::_0x6AB944DF68B512D3(p0);
	}

	static void LUA_NATIVE_AUDIO_STOP_AUDIO_SCENES()
	{
		AUDIO::STOP_AUDIO_SCENES();
	}

	static bool LUA_NATIVE_AUDIO_IS_AUDIO_SCENE_ACTIVE(sol::stack_object SceneName)
	{
		auto retval = (bool)AUDIO::IS_AUDIO_SCENE_ACTIVE(SceneName.is<const char*>() ? SceneName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_SET_AUDIO_SCENE_VARIABLE(sol::stack_object SceneName, sol::stack_object VariableName, float Value)
	{
		AUDIO::SET_AUDIO_SCENE_VARIABLE(SceneName.is<const char*>() ? SceneName.as<const char*>() : nullptr, VariableName.is<const char*>() ? VariableName.as<const char*>() : nullptr, Value);
	}

	static Hash LUA_NATIVE_AUDIO__GET_ENTITY_AUDIO_MIX_GROUP(Entity entity)
	{
		auto retval = AUDIO::_GET_ENTITY_AUDIO_MIX_GROUP(entity);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_ADD_ENTITY_TO_AUDIO_MIX_GROUP(Entity EntityIndex, sol::stack_object groupName, float fadeIn)
	{
		AUDIO::ADD_ENTITY_TO_AUDIO_MIX_GROUP(EntityIndex, groupName.is<const char*>() ? groupName.as<const char*>() : nullptr, fadeIn);
	}

	static Any LUA_NATIVE_AUDIO__0x131EC9247E7A2903(Any p0)
	{
		auto retval = AUDIO::_0x131EC9247E7A2903(p0);
		return retval;
	}

	static void LUA_NATIVE_AUDIO_REMOVE_ENTITY_FROM_AUDIO_MIX_GROUP(Entity EntityIndex, float fadeOut)
	{
		AUDIO::REMOVE_ENTITY_FROM_AUDIO_MIX_GROUP(EntityIndex, fadeOut);
	}

	static Any LUA_NATIVE_AUDIO__0xE600F61F54A444A6()
	{
		auto retval = AUDIO::_0xE600F61F54A444A6();
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_AUDIO_IS_MUSIC_PLAYING()
	{
		auto retval = (bool)AUDIO::AUDIO_IS_MUSIC_PLAYING();
		return retval;
	}

	static Hash LUA_NATIVE_AUDIO__0xBE28DB99556FF8D9(Entity entity)
	{
		auto retval = AUDIO::_0xBE28DB99556FF8D9(entity);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x8E901B65206C2D3E(Ped ped)
	{
		AUDIO::_0x8E901B65206C2D3E(ped);
	}

	static void LUA_NATIVE_AUDIO__0xC4CFCE4C656EF480(Ped ped)
	{
		AUDIO::_0xC4CFCE4C656EF480(ped);
	}

	static void LUA_NATIVE_AUDIO__0xABDB4863D3D72021(Entity entity, Any p1, Any p2, float p3, Any p4)
	{
		AUDIO::_0xABDB4863D3D72021(entity, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_AUDIO__0xB93A769B8B726950(Ped ped, Hash p1)
	{
		AUDIO::_0xB93A769B8B726950(ped, p1);
	}

	static void LUA_NATIVE_AUDIO__0xE891504B2F0E2DBA(Any p0, Any p1)
	{
		AUDIO::_0xE891504B2F0E2DBA(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x9EB779765E68C52E(Any p0, Any p1)
	{
		AUDIO::_0x9EB779765E68C52E(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0xE9694B2D6CB87B06(Entity entity, Any p1)
	{
		AUDIO::_0xE9694B2D6CB87B06(entity, p1);
	}

	static Any LUA_NATIVE_AUDIO__0x886657C5B3D8EDE3(Entity entity)
	{
		auto retval = AUDIO::_0x886657C5B3D8EDE3(entity);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xC68C02DE259C927C(Any p0)
	{
		auto retval = AUDIO::_0xC68C02DE259C927C(p0);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0x2FFF4A78384AFFDF(Entity entity)
	{
		auto retval = AUDIO::_0x2FFF4A78384AFFDF(entity);
		return retval;
	}

	static AnimScene LUA_NATIVE_AUDIO__0x62377977E4F08668(Entity entity)
	{
		auto retval = AUDIO::_0x62377977E4F08668(entity);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__GET_PED_SONG_INDEX_HOST(Ped ped)
	{
		auto retval = AUDIO::_GET_PED_SONG_INDEX_HOST(ped);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xD05A460328560477(Any p0)
	{
		auto retval = AUDIO::_0xD05A460328560477(p0);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x8D29FDF565DED9AE(Any p0, Any p1, Any p2)
	{
		AUDIO::_0x8D29FDF565DED9AE(p0, p1, p2);
	}

	static void LUA_NATIVE_AUDIO__0x448F2647DD6F2E27(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		AUDIO::_0x448F2647DD6F2E27(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_AUDIO__0x139A4B9DF2D26CBF(Any p0, Any p1)
	{
		AUDIO::_0x139A4B9DF2D26CBF(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x018ABE833CA64D2A(Any p0, Any p1)
	{
		AUDIO::_0x018ABE833CA64D2A(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0xBC07CA8FD710E7FD(Any p0, Any p1)
	{
		AUDIO::_0xBC07CA8FD710E7FD(p0, p1);
	}

	static bool LUA_NATIVE_AUDIO_PREPARE_MUSIC_EVENT(sol::stack_object eventName)
	{
		auto retval = (bool)AUDIO::PREPARE_MUSIC_EVENT(eventName.is<const char*>() ? eventName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_CANCEL_MUSIC_EVENT(sol::stack_object eventName)
	{
		auto retval = (bool)AUDIO::CANCEL_MUSIC_EVENT(eventName.is<const char*>() ? eventName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_AUDIO_TRIGGER_MUSIC_EVENT(sol::stack_object eventName)
	{
		auto retval = (bool)AUDIO::TRIGGER_MUSIC_EVENT(eventName.is<const char*>() ? eventName.as<const char*>() : nullptr);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__TRIGGER_MUSIC_EVENT_WITH_HASH(Hash eventName)
	{
		auto retval = AUDIO::_TRIGGER_MUSIC_EVENT_WITH_HASH(eventName);
		return retval;
	}

	static int LUA_NATIVE_AUDIO_GET_MUSIC_PLAYTIME()
	{
		auto retval = AUDIO::GET_MUSIC_PLAYTIME();
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0xF64034D533CE8AAC(Any p0, Any p1, Any p2)
	{
		AUDIO::_0xF64034D533CE8AAC(p0, p1, p2);
	}

	static void LUA_NATIVE_AUDIO_SET_PED_WALLA_DENSITY(float density, float applyValue)
	{
		AUDIO::SET_PED_WALLA_DENSITY(density, applyValue);
	}

	static void LUA_NATIVE_AUDIO__0xDAD6CD07CAA4F382()
	{
		AUDIO::_0xDAD6CD07CAA4F382();
	}

	static void LUA_NATIVE_AUDIO_SET_PED_INTERIOR_WALLA_DENSITY(float density, float applyValue)
	{
		AUDIO::SET_PED_INTERIOR_WALLA_DENSITY(density, applyValue);
	}

	static void LUA_NATIVE_AUDIO_FORCE_PED_PANIC_WALLA()
	{
		AUDIO::FORCE_PED_PANIC_WALLA();
	}

	static void LUA_NATIVE_AUDIO__0x138ADB94F8B90616()
	{
		AUDIO::_0x138ADB94F8B90616();
	}

	static void LUA_NATIVE_AUDIO_USE_FOOTSTEP_SCRIPT_SWEETENERS(Ped PedIndex, bool use, Hash soundSetHash)
	{
		AUDIO::USE_FOOTSTEP_SCRIPT_SWEETENERS(PedIndex, use, soundSetHash);
	}

	static void LUA_NATIVE_AUDIO_SET_AUDIO_FLAG(sol::stack_object flagName, bool enabled)
	{
		AUDIO::SET_AUDIO_FLAG(flagName.is<const char*>() ? flagName.as<const char*>() : nullptr, enabled);
	}

	static void LUA_NATIVE_AUDIO__0x6DA15746D5CC1A92(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		AUDIO::_0x6DA15746D5CC1A92(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_AUDIO__0x078F77FD1A43EAB3(Any p0, Any p1)
	{
		AUDIO::_0x078F77FD1A43EAB3(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x3D0BBCCF401B5FDB()
	{
		AUDIO::_0x3D0BBCCF401B5FDB();
	}

	static void LUA_NATIVE_AUDIO_SET_PORTAL_SETTINGS_OVERRIDE(sol::stack_object OldPortalSettingsName, sol::stack_object NewPortalSettingsName)
	{
		AUDIO::SET_PORTAL_SETTINGS_OVERRIDE(OldPortalSettingsName.is<const char*>() ? OldPortalSettingsName.as<const char*>() : nullptr, NewPortalSettingsName.is<const char*>() ? NewPortalSettingsName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO_REMOVE_PORTAL_SETTINGS_OVERRIDE(sol::stack_object PortalSettingsName)
	{
		AUDIO::REMOVE_PORTAL_SETTINGS_OVERRIDE(PortalSettingsName.is<const char*>() ? PortalSettingsName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__0xEA546C31FD45F8CD(Any p0)
	{
		AUDIO::_0xEA546C31FD45F8CD(p0);
	}

	static Any LUA_NATIVE_AUDIO__0x44A5EEF54F62E823(Any p0)
	{
		auto retval = AUDIO::_0x44A5EEF54F62E823(p0);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x017492B2201E3428(Any p0, Any p1, Any p2, Any p3)
	{
		AUDIO::_0x017492B2201E3428(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_AUDIO__0xC886CD666ADD42E1(Any p0, Any p1)
	{
		AUDIO::_0xC886CD666ADD42E1(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x5AE0CB5F35F034FD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7)
	{
		AUDIO::_0x5AE0CB5F35F034FD(p0, p1, p2, p3, p4, p5, p6, p7);
	}

	static void LUA_NATIVE_AUDIO__0x821C32C728B24477(Any p0, Any p1, Any p2)
	{
		AUDIO::_0x821C32C728B24477(p0, p1, p2);
	}

	static void LUA_NATIVE_AUDIO__0x06C5DF5EE444BC6B(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		AUDIO::_0x06C5DF5EE444BC6B(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_AUDIO__0x341CDD17EFC2472E(Any p0, Any p1)
	{
		AUDIO::_0x341CDD17EFC2472E(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x7E176C676F8652A9(Any p0)
	{
		AUDIO::_0x7E176C676F8652A9(p0);
	}

	static Any LUA_NATIVE_AUDIO__0x2B9C37C01BF25EDB(Any p0)
	{
		auto retval = AUDIO::_0x2B9C37C01BF25EDB(p0);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xA6A3A3F96B8B030E()
	{
		auto retval = AUDIO::_0xA6A3A3F96B8B030E();
		return retval;
	}

	static int LUA_NATIVE_AUDIO__GET_LOADED_STREAM_ID_FROM_CREATION(sol::stack_object streamName, sol::stack_object soundSet)
	{
		auto retval = AUDIO::_GET_LOADED_STREAM_ID_FROM_CREATION(streamName.is<const char*>() ? streamName.as<const char*>() : nullptr, soundSet.is<const char*>() ? soundSet.as<const char*>() : nullptr);
		return retval;
	}

	static Any LUA_NATIVE_AUDIO__0xC369E2234E34A0CA(Any p0, Any p1)
	{
		auto retval = AUDIO::_0xC369E2234E34A0CA(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_AUDIO__0x35B8C070E0C16E2F(Any p0, Any p1)
	{
		AUDIO::_0x35B8C070E0C16E2F(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0xE7E6CB8B713ED190()
	{
		AUDIO::_0xE7E6CB8B713ED190();
	}

	static void LUA_NATIVE_AUDIO__0x569ABC36E28DDEAA()
	{
		AUDIO::_0x569ABC36E28DDEAA();
	}

	static void LUA_NATIVE_AUDIO__0x839C9F124BE74D94(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		AUDIO::_0x839C9F124BE74D94(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_AUDIO_AUDIO_TRIGGER_EXPLOSION(sol::stack_object name, float x, float y, float z)
	{
		AUDIO::AUDIO_TRIGGER_EXPLOSION(name.is<const char*>() ? name.as<const char*>() : nullptr, x, y, z);
	}

	static void LUA_NATIVE_AUDIO__0x3E98AC9D8C56C62C(Any p0)
	{
		AUDIO::_0x3E98AC9D8C56C62C(p0);
	}

	static void LUA_NATIVE_AUDIO__0xCBF2BEBB468A34F3(Any p0)
	{
		AUDIO::_0xCBF2BEBB468A34F3(p0);
	}

	static void LUA_NATIVE_AUDIO__0xA2B851605748AD0E()
	{
		AUDIO::_0xA2B851605748AD0E();
	}

	static void LUA_NATIVE_AUDIO__0xCFAD2C8CD1054523(Any p0, Any p1, Any p2, Any p3)
	{
		AUDIO::_0xCFAD2C8CD1054523(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_AUDIO__0xD733528B6C35647A(Any p0, Any p1)
	{
		AUDIO::_0xD733528B6C35647A(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x5BC885EBD75FAA7D(Any p0, Any p1)
	{
		AUDIO::_0x5BC885EBD75FAA7D(p0, p1);
	}

	static void LUA_NATIVE_AUDIO__0x6B7A88A61B41E589(Any p0)
	{
		AUDIO::_0x6B7A88A61B41E589(p0);
	}

	static void LUA_NATIVE_AUDIO__0x4BE3EC91C01F0FE8()
	{
		AUDIO::_0x4BE3EC91C01F0FE8();
	}

	static void LUA_NATIVE_AUDIO_SET_AUDIO_ONLINE_TRANSITION_STAGE(sol::stack_object p0)
	{
		AUDIO::SET_AUDIO_ONLINE_TRANSITION_STAGE(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_AUDIO__STOP_ALL_SCRIPTED_AUDIO_SOUNDS()
	{
		AUDIO::_STOP_ALL_SCRIPTED_AUDIO_SOUNDS();
	}

	static void LUA_NATIVE_AUDIO__0x64B956F4E761DF5C(Any p0)
	{
		AUDIO::_0x64B956F4E761DF5C(p0);
	}

	void RegisterNatives_AUDIO(sol::state& L)
	{
		auto AUDIO = L["AUDIO"].get_or_create<sol::table>();
		AUDIO.set_function("_0x7455CD705F7E933E", LUA_NATIVE_AUDIO__0x7455CD705F7E933E);
		AUDIO.set_function("CLEAR_CONVERSATION_HISTORY", LUA_NATIVE_AUDIO_CLEAR_CONVERSATION_HISTORY);
		AUDIO.set_function("_CLEAR_CONVERSATION_HISTORY_FOR_SCRIPTED_CONVERSATION", LUA_NATIVE_AUDIO__CLEAR_CONVERSATION_HISTORY_FOR_SCRIPTED_CONVERSATION);
		AUDIO.set_function("CREATE_NEW_SCRIPTED_CONVERSATION", LUA_NATIVE_AUDIO_CREATE_NEW_SCRIPTED_CONVERSATION);
		AUDIO.set_function("_0xDF947FE0D551684E", LUA_NATIVE_AUDIO__0xDF947FE0D551684E);
		AUDIO.set_function("ADD_PED_TO_CONVERSATION", LUA_NATIVE_AUDIO_ADD_PED_TO_CONVERSATION);
		AUDIO.set_function("_0xA2323A2EAE32A290", LUA_NATIVE_AUDIO__0xA2323A2EAE32A290);
		AUDIO.set_function("_0x79F9C57B8D0DFE90", LUA_NATIVE_AUDIO__0x79F9C57B8D0DFE90);
		AUDIO.set_function("START_SCRIPT_CONVERSATION", LUA_NATIVE_AUDIO_START_SCRIPT_CONVERSATION);
		AUDIO.set_function("PRELOAD_SCRIPT_CONVERSATION", LUA_NATIVE_AUDIO_PRELOAD_SCRIPT_CONVERSATION);
		AUDIO.set_function("START_PRELOADED_CONVERSATION", LUA_NATIVE_AUDIO_START_PRELOADED_CONVERSATION);
		AUDIO.set_function("_0x0CB3D1919E8D7CBA", LUA_NATIVE_AUDIO__0x0CB3D1919E8D7CBA);
		AUDIO.set_function("_0xFE5C6177064BD390", LUA_NATIVE_AUDIO__0xFE5C6177064BD390);
		AUDIO.set_function("_IS_SCRIPTED_CONVERSATION_CREATED", LUA_NATIVE_AUDIO__IS_SCRIPTED_CONVERSATION_CREATED);
		AUDIO.set_function("_0x5A13586A9447931F", LUA_NATIVE_AUDIO__0x5A13586A9447931F);
		AUDIO.set_function("IS_SCRIPTED_CONVERSATION_LOADED", LUA_NATIVE_AUDIO_IS_SCRIPTED_CONVERSATION_LOADED);
		AUDIO.set_function("_IS_ANY_CONVERSATION_PLAYING", LUA_NATIVE_AUDIO__IS_ANY_CONVERSATION_PLAYING);
		AUDIO.set_function("IS_SCRIPTED_CONVERSATION_PLAYING", LUA_NATIVE_AUDIO_IS_SCRIPTED_CONVERSATION_PLAYING);
		AUDIO.set_function("_IS_SCRIPTED_CONVERSION_ONGOING", LUA_NATIVE_AUDIO__IS_SCRIPTED_CONVERSION_ONGOING);
		AUDIO.set_function("_0x847748AE5D7B1071", LUA_NATIVE_AUDIO__0x847748AE5D7B1071);
		AUDIO.set_function("_0xD0730C1FA40348D9", LUA_NATIVE_AUDIO__0xD0730C1FA40348D9);
		AUDIO.set_function("GET_CURRENT_SCRIPTED_CONVERSATION_LINE", LUA_NATIVE_AUDIO_GET_CURRENT_SCRIPTED_CONVERSATION_LINE);
		AUDIO.set_function("PAUSE_SCRIPTED_CONVERSATION", LUA_NATIVE_AUDIO_PAUSE_SCRIPTED_CONVERSATION);
		AUDIO.set_function("RESTART_SCRIPTED_CONVERSATION", LUA_NATIVE_AUDIO_RESTART_SCRIPTED_CONVERSATION);
		AUDIO.set_function("_STOP_ALL_SCRIPTED_CONVERSIONS", LUA_NATIVE_AUDIO__STOP_ALL_SCRIPTED_CONVERSIONS);
		AUDIO.set_function("STOP_SCRIPTED_CONVERSATION", LUA_NATIVE_AUDIO_STOP_SCRIPTED_CONVERSATION);
		AUDIO.set_function("SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE", LUA_NATIVE_AUDIO_SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE);
		AUDIO.set_function("_0xF336E9F989B3518F", LUA_NATIVE_AUDIO__0xF336E9F989B3518F);
		AUDIO.set_function("_0x254B0241E964B450", LUA_NATIVE_AUDIO__0x254B0241E964B450);
		AUDIO.set_function("_0x152ED1B56E8F1F50", LUA_NATIVE_AUDIO__0x152ED1B56E8F1F50);
		AUDIO.set_function("_0x935DBD96D4A3DA1F", LUA_NATIVE_AUDIO__0x935DBD96D4A3DA1F);
		AUDIO.set_function("_0x295859EB18F48D82", LUA_NATIVE_AUDIO__0x295859EB18F48D82);
		AUDIO.set_function("_0x40CA665AB9D8D505", LUA_NATIVE_AUDIO__0x40CA665AB9D8D505);
		AUDIO.set_function("_0xF232C2C546AC16D0", LUA_NATIVE_AUDIO__0xF232C2C546AC16D0);
		AUDIO.set_function("_0x1E6F9A9FE1A99F36", LUA_NATIVE_AUDIO__0x1E6F9A9FE1A99F36);
		AUDIO.set_function("REGISTER_SCRIPT_WITH_AUDIO", LUA_NATIVE_AUDIO_REGISTER_SCRIPT_WITH_AUDIO);
		AUDIO.set_function("UNREGISTER_SCRIPT_WITH_AUDIO", LUA_NATIVE_AUDIO_UNREGISTER_SCRIPT_WITH_AUDIO);
		AUDIO.set_function("REQUEST_SCRIPT_AUDIO_BANK", LUA_NATIVE_AUDIO_REQUEST_SCRIPT_AUDIO_BANK);
		AUDIO.set_function("RELEASE_NAMED_SCRIPT_AUDIO_BANK", LUA_NATIVE_AUDIO_RELEASE_NAMED_SCRIPT_AUDIO_BANK);
		AUDIO.set_function("RELEASE_SCRIPT_AUDIO_BANK", LUA_NATIVE_AUDIO_RELEASE_SCRIPT_AUDIO_BANK);
		AUDIO.set_function("GET_SOUND_ID", LUA_NATIVE_AUDIO_GET_SOUND_ID);
		AUDIO.set_function("RELEASE_SOUND_ID", LUA_NATIVE_AUDIO_RELEASE_SOUND_ID);
		AUDIO.set_function("PLAY_SOUND", LUA_NATIVE_AUDIO_PLAY_SOUND);
		AUDIO.set_function("PLAY_SOUND_FRONTEND", LUA_NATIVE_AUDIO_PLAY_SOUND_FRONTEND);
		AUDIO.set_function("_PLAY_SOUND_FROM_ITEM", LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_ITEM);
		AUDIO.set_function("PLAY_SOUND_FROM_ENTITY", LUA_NATIVE_AUDIO_PLAY_SOUND_FROM_ENTITY);
		AUDIO.set_function("_PLAY_SOUND_FROM_POSITION", LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_POSITION);
		AUDIO.set_function("_STOP_SOUND_WITH_NAME", LUA_NATIVE_AUDIO__STOP_SOUND_WITH_NAME);
		AUDIO.set_function("_0x580D71DFE0088E34", LUA_NATIVE_AUDIO__0x580D71DFE0088E34);
		AUDIO.set_function("_IS_SCRIPTED_AUDIO_CUSTOM", LUA_NATIVE_AUDIO__IS_SCRIPTED_AUDIO_CUSTOM);
		AUDIO.set_function("_SET_VARIABLE_ON_SOUND_WITH_NAME", LUA_NATIVE_AUDIO__SET_VARIABLE_ON_SOUND_WITH_NAME);
		AUDIO.set_function("_SET_WHISTLE_CONFIG_FOR_PED", LUA_NATIVE_AUDIO__SET_WHISTLE_CONFIG_FOR_PED);
		AUDIO.set_function("_SET_SOUND_RELATIONSHIP_ON_PED", LUA_NATIVE_AUDIO__SET_SOUND_RELATIONSHIP_ON_PED);
		AUDIO.set_function("_PLAY_SOUND_FRONTEND_WITH_SOUND_ID", LUA_NATIVE_AUDIO__PLAY_SOUND_FRONTEND_WITH_SOUND_ID);
		AUDIO.set_function("_PLAY_SOUND_FROM_ENTITY_WITH_SET", LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_ENTITY_WITH_SET);
		AUDIO.set_function("_PLAY_SOUND_FROM_POSITION_WITH_ID", LUA_NATIVE_AUDIO__PLAY_SOUND_FROM_POSITION_WITH_ID);
		AUDIO.set_function("_UPDATE_SOUND_POSITION", LUA_NATIVE_AUDIO__UPDATE_SOUND_POSITION);
		AUDIO.set_function("_STOP_SOUND_WITH_ID", LUA_NATIVE_AUDIO__STOP_SOUND_WITH_ID);
		AUDIO.set_function("_SET_VARIABLE_ON_SOUND_WITH_ID", LUA_NATIVE_AUDIO__SET_VARIABLE_ON_SOUND_WITH_ID);
		AUDIO.set_function("PREPARE_SOUND", LUA_NATIVE_AUDIO_PREPARE_SOUND);
		AUDIO.set_function("_RELEASE_SHARD_SOUNDS", LUA_NATIVE_AUDIO__RELEASE_SHARD_SOUNDS);
		AUDIO.set_function("PREPARE_SOUNDSET", LUA_NATIVE_AUDIO_PREPARE_SOUNDSET);
		AUDIO.set_function("_RELEASE_SOUNDSET", LUA_NATIVE_AUDIO__RELEASE_SOUNDSET);
		AUDIO.set_function("PREPARE_SOUND_WITH_ENTITY", LUA_NATIVE_AUDIO_PREPARE_SOUND_WITH_ENTITY);
		AUDIO.set_function("_0x3E93DDDCBB6111E4", LUA_NATIVE_AUDIO__0x3E93DDDCBB6111E4);
		AUDIO.set_function("_HAS_SOUND_AUDIO_NAME_FINISHED", LUA_NATIVE_AUDIO__HAS_SOUND_AUDIO_NAME_FINISHED);
		AUDIO.set_function("_HAS_SOUND_ID_FINISHED", LUA_NATIVE_AUDIO__HAS_SOUND_ID_FINISHED);
		AUDIO.set_function("PLAY_PED_AMBIENT_SPEECH_NATIVE", LUA_NATIVE_AUDIO_PLAY_PED_AMBIENT_SPEECH_NATIVE);
		AUDIO.set_function("PLAY_AMBIENT_SPEECH_FROM_POSITION_NATIVE", LUA_NATIVE_AUDIO_PLAY_AMBIENT_SPEECH_FROM_POSITION_NATIVE);
		AUDIO.set_function("_0x72E4D1C4639BC465", LUA_NATIVE_AUDIO__0x72E4D1C4639BC465);
		AUDIO.set_function("_0xB18FEC133C7C6C69", LUA_NATIVE_AUDIO__0xB18FEC133C7C6C69);
		AUDIO.set_function("_0xDC93F0948F2C28F4", LUA_NATIVE_AUDIO__0xDC93F0948F2C28F4);
		AUDIO.set_function("_0x0D7FD6A55FD63AEF", LUA_NATIVE_AUDIO__0x0D7FD6A55FD63AEF);
		AUDIO.set_function("_0x660A8F876DF1D4F8", LUA_NATIVE_AUDIO__0x660A8F876DF1D4F8);
		AUDIO.set_function("_0x380A2E353AD30917", LUA_NATIVE_AUDIO__0x380A2E353AD30917);
		AUDIO.set_function("_0x0FAF7171BF613B80", LUA_NATIVE_AUDIO__0x0FAF7171BF613B80);
		AUDIO.set_function("PLAY_PAIN", LUA_NATIVE_AUDIO_PLAY_PAIN);
		AUDIO.set_function("_0x6652B0C8F3D414D0", LUA_NATIVE_AUDIO__0x6652B0C8F3D414D0);
		AUDIO.set_function("_0xF092B6030D6FD49C", LUA_NATIVE_AUDIO__0xF092B6030D6FD49C);
		AUDIO.set_function("_0x2651DDC0EA269073", LUA_NATIVE_AUDIO__0x2651DDC0EA269073);
		AUDIO.set_function("SET_AMBIENT_VOICE_NAME", LUA_NATIVE_AUDIO_SET_AMBIENT_VOICE_NAME);
		AUDIO.set_function("_SET_VOFX_PED_VOICE", LUA_NATIVE_AUDIO__SET_VOFX_PED_VOICE);
		AUDIO.set_function("STOP_CURRENT_PLAYING_SPEECH", LUA_NATIVE_AUDIO_STOP_CURRENT_PLAYING_SPEECH);
		AUDIO.set_function("STOP_CURRENT_PLAYING_AMBIENT_SPEECH", LUA_NATIVE_AUDIO_STOP_CURRENT_PLAYING_AMBIENT_SPEECH);
		AUDIO.set_function("IS_AMBIENT_SPEECH_PLAYING", LUA_NATIVE_AUDIO_IS_AMBIENT_SPEECH_PLAYING);
		AUDIO.set_function("IS_SCRIPTED_SPEECH_PLAYING", LUA_NATIVE_AUDIO_IS_SCRIPTED_SPEECH_PLAYING);
		AUDIO.set_function("IS_ANY_SPEECH_PLAYING", LUA_NATIVE_AUDIO_IS_ANY_SPEECH_PLAYING);
		AUDIO.set_function("_0x2B101AD9F651243A", LUA_NATIVE_AUDIO__0x2B101AD9F651243A);
		AUDIO.set_function("_0x4A98E228A936DBCC", LUA_NATIVE_AUDIO__0x4A98E228A936DBCC);
		AUDIO.set_function("_0x6BFFB7C276866996", LUA_NATIVE_AUDIO__0x6BFFB7C276866996);
		AUDIO.set_function("DOES_CONTEXT_EXIST_FOR_THIS_PED", LUA_NATIVE_AUDIO_DOES_CONTEXT_EXIST_FOR_THIS_PED);
		AUDIO.set_function("_0xF0EE69F500952FA5", LUA_NATIVE_AUDIO__0xF0EE69F500952FA5);
		AUDIO.set_function("_0x9D6DEC9791A4E501", LUA_NATIVE_AUDIO__0x9D6DEC9791A4E501);
		AUDIO.set_function("_0x864A842B86993851", LUA_NATIVE_AUDIO__0x864A842B86993851);
		AUDIO.set_function("IS_PED_IN_CURRENT_CONVERSATION", LUA_NATIVE_AUDIO_IS_PED_IN_CURRENT_CONVERSATION);
		AUDIO.set_function("_IS_PED_IN_ANY_CONVERSATION", LUA_NATIVE_AUDIO__IS_PED_IN_ANY_CONVERSATION);
		AUDIO.set_function("SET_PED_IS_DRUNK", LUA_NATIVE_AUDIO_SET_PED_IS_DRUNK);
		AUDIO.set_function("_0x3A00D87B20A2A5E4", LUA_NATIVE_AUDIO__0x3A00D87B20A2A5E4);
		AUDIO.set_function("_0xD47D47EFBF103FB8", LUA_NATIVE_AUDIO__0xD47D47EFBF103FB8);
		AUDIO.set_function("PLAY_ANIMAL_VOCALIZATION", LUA_NATIVE_AUDIO_PLAY_ANIMAL_VOCALIZATION);
		AUDIO.set_function("_PLAY_ANIMAL_VOCALIZATION_PHEROMONE_VIAL_RESPONSE", LUA_NATIVE_AUDIO__PLAY_ANIMAL_VOCALIZATION_PHEROMONE_VIAL_RESPONSE);
		AUDIO.set_function("IS_ANIMAL_VOCALIZATION_PLAYING", LUA_NATIVE_AUDIO_IS_ANIMAL_VOCALIZATION_PLAYING);
		AUDIO.set_function("SET_ANIMAL_MOOD", LUA_NATIVE_AUDIO_SET_ANIMAL_MOOD);
		AUDIO.set_function("_0xFCDEC42B1C78B7F8", LUA_NATIVE_AUDIO__0xFCDEC42B1C78B7F8);
		AUDIO.set_function("_0xEB4D592620B8C209", LUA_NATIVE_AUDIO__0xEB4D592620B8C209);
		AUDIO.set_function("_0xA6847BBA4FCDD13F", LUA_NATIVE_AUDIO__0xA6847BBA4FCDD13F);
		AUDIO.set_function("SET_STATIC_EMITTER_ENABLED", LUA_NATIVE_AUDIO_SET_STATIC_EMITTER_ENABLED);
		AUDIO.set_function("PLAY_END_CREDITS_MUSIC", LUA_NATIVE_AUDIO_PLAY_END_CREDITS_MUSIC);
		AUDIO.set_function("_0x7678FE0455ED1145", LUA_NATIVE_AUDIO__0x7678FE0455ED1145);
		AUDIO.set_function("_0xFFE9C53DEEA3DB0B", LUA_NATIVE_AUDIO__0xFFE9C53DEEA3DB0B);
		AUDIO.set_function("_0x5E3CCF03995388B5", LUA_NATIVE_AUDIO__0x5E3CCF03995388B5);
		AUDIO.set_function("_0x43037ABFE214A851", LUA_NATIVE_AUDIO__0x43037ABFE214A851);
		AUDIO.set_function("SET_AMBIENT_ZONE_STATE", LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_STATE);
		AUDIO.set_function("CLEAR_AMBIENT_ZONE_STATE", LUA_NATIVE_AUDIO_CLEAR_AMBIENT_ZONE_STATE);
		AUDIO.set_function("SET_AMBIENT_ZONE_LIST_STATE", LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_LIST_STATE);
		AUDIO.set_function("CLEAR_AMBIENT_ZONE_LIST_STATE", LUA_NATIVE_AUDIO_CLEAR_AMBIENT_ZONE_LIST_STATE);
		AUDIO.set_function("SET_AMBIENT_ZONE_STATE_PERSISTENT", LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_STATE_PERSISTENT);
		AUDIO.set_function("SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT", LUA_NATIVE_AUDIO_SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT);
		AUDIO.set_function("_SET_AMBIENT_ZONE_POSITION", LUA_NATIVE_AUDIO__SET_AMBIENT_ZONE_POSITION);
		AUDIO.set_function("IS_HORN_ACTIVE", LUA_NATIVE_AUDIO_IS_HORN_ACTIVE);
		AUDIO.set_function("_0xFD461D0ABA5559B1", LUA_NATIVE_AUDIO__0xFD461D0ABA5559B1);
		AUDIO.set_function("IS_STREAM_PLAYING", LUA_NATIVE_AUDIO_IS_STREAM_PLAYING);
		AUDIO.set_function("LOAD_STREAM", LUA_NATIVE_AUDIO_LOAD_STREAM);
		AUDIO.set_function("PLAY_STREAM_FROM_PED", LUA_NATIVE_AUDIO_PLAY_STREAM_FROM_PED);
		AUDIO.set_function("PLAY_STREAM_FRONTEND", LUA_NATIVE_AUDIO_PLAY_STREAM_FRONTEND);
		AUDIO.set_function("PLAY_STREAM_FROM_POSITION", LUA_NATIVE_AUDIO_PLAY_STREAM_FROM_POSITION);
		AUDIO.set_function("_0x3A3BE6B920525237", LUA_NATIVE_AUDIO__0x3A3BE6B920525237);
		AUDIO.set_function("STOP_STREAM", LUA_NATIVE_AUDIO_STOP_STREAM);
		AUDIO.set_function("STOP_PED_SPEAKING", LUA_NATIVE_AUDIO_STOP_PED_SPEAKING);
		AUDIO.set_function("DISABLE_PED_PAIN_AUDIO", LUA_NATIVE_AUDIO_DISABLE_PED_PAIN_AUDIO);
		AUDIO.set_function("IS_AMBIENT_SPEECH_DISABLED", LUA_NATIVE_AUDIO_IS_AMBIENT_SPEECH_DISABLED);
		AUDIO.set_function("SET_IS_SCRIPTED_SPEECH_DISABLED", LUA_NATIVE_AUDIO_SET_IS_SCRIPTED_SPEECH_DISABLED);
		AUDIO.set_function("_BLOCK_SPEECH_CONTEXT", LUA_NATIVE_AUDIO__BLOCK_SPEECH_CONTEXT);
		AUDIO.set_function("_UNLOAD_SPEECH_CONTEXT", LUA_NATIVE_AUDIO__UNLOAD_SPEECH_CONTEXT);
		AUDIO.set_function("SET_HORN_ENABLED", LUA_NATIVE_AUDIO_SET_HORN_ENABLED);
		AUDIO.set_function("SET_AUDIO_VEHICLE_PRIORITY", LUA_NATIVE_AUDIO_SET_AUDIO_VEHICLE_PRIORITY);
		AUDIO.set_function("_0x259ACC5B52A2B2D9", LUA_NATIVE_AUDIO__0x259ACC5B52A2B2D9);
		AUDIO.set_function("FORCE_USE_AUDIO_GAME_OBJECT", LUA_NATIVE_AUDIO_FORCE_USE_AUDIO_GAME_OBJECT);
		AUDIO.set_function("SET_GPS_ACTIVE", LUA_NATIVE_AUDIO_SET_GPS_ACTIVE);
		AUDIO.set_function("_START_AUDIO_SCENESET", LUA_NATIVE_AUDIO__START_AUDIO_SCENESET);
		AUDIO.set_function("_STOP_AUDIO_SCENESET", LUA_NATIVE_AUDIO__STOP_AUDIO_SCENESET);
		AUDIO.set_function("_SET_AUDIO_SCENESET", LUA_NATIVE_AUDIO__SET_AUDIO_SCENESET);
		AUDIO.set_function("START_AUDIO_SCENE", LUA_NATIVE_AUDIO_START_AUDIO_SCENE);
		AUDIO.set_function("_0xDC2F83A0612CA34D", LUA_NATIVE_AUDIO__0xDC2F83A0612CA34D);
		AUDIO.set_function("STOP_AUDIO_SCENE", LUA_NATIVE_AUDIO_STOP_AUDIO_SCENE);
		AUDIO.set_function("_0x6AB944DF68B512D3", LUA_NATIVE_AUDIO__0x6AB944DF68B512D3);
		AUDIO.set_function("STOP_AUDIO_SCENES", LUA_NATIVE_AUDIO_STOP_AUDIO_SCENES);
		AUDIO.set_function("IS_AUDIO_SCENE_ACTIVE", LUA_NATIVE_AUDIO_IS_AUDIO_SCENE_ACTIVE);
		AUDIO.set_function("SET_AUDIO_SCENE_VARIABLE", LUA_NATIVE_AUDIO_SET_AUDIO_SCENE_VARIABLE);
		AUDIO.set_function("_GET_ENTITY_AUDIO_MIX_GROUP", LUA_NATIVE_AUDIO__GET_ENTITY_AUDIO_MIX_GROUP);
		AUDIO.set_function("ADD_ENTITY_TO_AUDIO_MIX_GROUP", LUA_NATIVE_AUDIO_ADD_ENTITY_TO_AUDIO_MIX_GROUP);
		AUDIO.set_function("_0x131EC9247E7A2903", LUA_NATIVE_AUDIO__0x131EC9247E7A2903);
		AUDIO.set_function("REMOVE_ENTITY_FROM_AUDIO_MIX_GROUP", LUA_NATIVE_AUDIO_REMOVE_ENTITY_FROM_AUDIO_MIX_GROUP);
		AUDIO.set_function("_0xE600F61F54A444A6", LUA_NATIVE_AUDIO__0xE600F61F54A444A6);
		AUDIO.set_function("AUDIO_IS_MUSIC_PLAYING", LUA_NATIVE_AUDIO_AUDIO_IS_MUSIC_PLAYING);
		AUDIO.set_function("_0xBE28DB99556FF8D9", LUA_NATIVE_AUDIO__0xBE28DB99556FF8D9);
		AUDIO.set_function("_0x8E901B65206C2D3E", LUA_NATIVE_AUDIO__0x8E901B65206C2D3E);
		AUDIO.set_function("_0xC4CFCE4C656EF480", LUA_NATIVE_AUDIO__0xC4CFCE4C656EF480);
		AUDIO.set_function("_0xABDB4863D3D72021", LUA_NATIVE_AUDIO__0xABDB4863D3D72021);
		AUDIO.set_function("_0xB93A769B8B726950", LUA_NATIVE_AUDIO__0xB93A769B8B726950);
		AUDIO.set_function("_0xE891504B2F0E2DBA", LUA_NATIVE_AUDIO__0xE891504B2F0E2DBA);
		AUDIO.set_function("_0x9EB779765E68C52E", LUA_NATIVE_AUDIO__0x9EB779765E68C52E);
		AUDIO.set_function("_0xE9694B2D6CB87B06", LUA_NATIVE_AUDIO__0xE9694B2D6CB87B06);
		AUDIO.set_function("_0x886657C5B3D8EDE3", LUA_NATIVE_AUDIO__0x886657C5B3D8EDE3);
		AUDIO.set_function("_0xC68C02DE259C927C", LUA_NATIVE_AUDIO__0xC68C02DE259C927C);
		AUDIO.set_function("_0x2FFF4A78384AFFDF", LUA_NATIVE_AUDIO__0x2FFF4A78384AFFDF);
		AUDIO.set_function("_0x62377977E4F08668", LUA_NATIVE_AUDIO__0x62377977E4F08668);
		AUDIO.set_function("_GET_PED_SONG_INDEX_HOST", LUA_NATIVE_AUDIO__GET_PED_SONG_INDEX_HOST);
		AUDIO.set_function("_0xD05A460328560477", LUA_NATIVE_AUDIO__0xD05A460328560477);
		AUDIO.set_function("_0x8D29FDF565DED9AE", LUA_NATIVE_AUDIO__0x8D29FDF565DED9AE);
		AUDIO.set_function("_0x448F2647DD6F2E27", LUA_NATIVE_AUDIO__0x448F2647DD6F2E27);
		AUDIO.set_function("_0x139A4B9DF2D26CBF", LUA_NATIVE_AUDIO__0x139A4B9DF2D26CBF);
		AUDIO.set_function("_0x018ABE833CA64D2A", LUA_NATIVE_AUDIO__0x018ABE833CA64D2A);
		AUDIO.set_function("_0xBC07CA8FD710E7FD", LUA_NATIVE_AUDIO__0xBC07CA8FD710E7FD);
		AUDIO.set_function("PREPARE_MUSIC_EVENT", LUA_NATIVE_AUDIO_PREPARE_MUSIC_EVENT);
		AUDIO.set_function("CANCEL_MUSIC_EVENT", LUA_NATIVE_AUDIO_CANCEL_MUSIC_EVENT);
		AUDIO.set_function("TRIGGER_MUSIC_EVENT", LUA_NATIVE_AUDIO_TRIGGER_MUSIC_EVENT);
		AUDIO.set_function("_TRIGGER_MUSIC_EVENT_WITH_HASH", LUA_NATIVE_AUDIO__TRIGGER_MUSIC_EVENT_WITH_HASH);
		AUDIO.set_function("GET_MUSIC_PLAYTIME", LUA_NATIVE_AUDIO_GET_MUSIC_PLAYTIME);
		AUDIO.set_function("_0xF64034D533CE8AAC", LUA_NATIVE_AUDIO__0xF64034D533CE8AAC);
		AUDIO.set_function("SET_PED_WALLA_DENSITY", LUA_NATIVE_AUDIO_SET_PED_WALLA_DENSITY);
		AUDIO.set_function("_0xDAD6CD07CAA4F382", LUA_NATIVE_AUDIO__0xDAD6CD07CAA4F382);
		AUDIO.set_function("SET_PED_INTERIOR_WALLA_DENSITY", LUA_NATIVE_AUDIO_SET_PED_INTERIOR_WALLA_DENSITY);
		AUDIO.set_function("FORCE_PED_PANIC_WALLA", LUA_NATIVE_AUDIO_FORCE_PED_PANIC_WALLA);
		AUDIO.set_function("_0x138ADB94F8B90616", LUA_NATIVE_AUDIO__0x138ADB94F8B90616);
		AUDIO.set_function("USE_FOOTSTEP_SCRIPT_SWEETENERS", LUA_NATIVE_AUDIO_USE_FOOTSTEP_SCRIPT_SWEETENERS);
		AUDIO.set_function("SET_AUDIO_FLAG", LUA_NATIVE_AUDIO_SET_AUDIO_FLAG);
		AUDIO.set_function("_0x6DA15746D5CC1A92", LUA_NATIVE_AUDIO__0x6DA15746D5CC1A92);
		AUDIO.set_function("_0x078F77FD1A43EAB3", LUA_NATIVE_AUDIO__0x078F77FD1A43EAB3);
		AUDIO.set_function("_0x3D0BBCCF401B5FDB", LUA_NATIVE_AUDIO__0x3D0BBCCF401B5FDB);
		AUDIO.set_function("SET_PORTAL_SETTINGS_OVERRIDE", LUA_NATIVE_AUDIO_SET_PORTAL_SETTINGS_OVERRIDE);
		AUDIO.set_function("REMOVE_PORTAL_SETTINGS_OVERRIDE", LUA_NATIVE_AUDIO_REMOVE_PORTAL_SETTINGS_OVERRIDE);
		AUDIO.set_function("_0xEA546C31FD45F8CD", LUA_NATIVE_AUDIO__0xEA546C31FD45F8CD);
		AUDIO.set_function("_0x44A5EEF54F62E823", LUA_NATIVE_AUDIO__0x44A5EEF54F62E823);
		AUDIO.set_function("_0x017492B2201E3428", LUA_NATIVE_AUDIO__0x017492B2201E3428);
		AUDIO.set_function("_0xC886CD666ADD42E1", LUA_NATIVE_AUDIO__0xC886CD666ADD42E1);
		AUDIO.set_function("_0x5AE0CB5F35F034FD", LUA_NATIVE_AUDIO__0x5AE0CB5F35F034FD);
		AUDIO.set_function("_0x821C32C728B24477", LUA_NATIVE_AUDIO__0x821C32C728B24477);
		AUDIO.set_function("_0x06C5DF5EE444BC6B", LUA_NATIVE_AUDIO__0x06C5DF5EE444BC6B);
		AUDIO.set_function("_0x341CDD17EFC2472E", LUA_NATIVE_AUDIO__0x341CDD17EFC2472E);
		AUDIO.set_function("_0x7E176C676F8652A9", LUA_NATIVE_AUDIO__0x7E176C676F8652A9);
		AUDIO.set_function("_0x2B9C37C01BF25EDB", LUA_NATIVE_AUDIO__0x2B9C37C01BF25EDB);
		AUDIO.set_function("_0xA6A3A3F96B8B030E", LUA_NATIVE_AUDIO__0xA6A3A3F96B8B030E);
		AUDIO.set_function("_GET_LOADED_STREAM_ID_FROM_CREATION", LUA_NATIVE_AUDIO__GET_LOADED_STREAM_ID_FROM_CREATION);
		AUDIO.set_function("_0xC369E2234E34A0CA", LUA_NATIVE_AUDIO__0xC369E2234E34A0CA);
		AUDIO.set_function("_0x35B8C070E0C16E2F", LUA_NATIVE_AUDIO__0x35B8C070E0C16E2F);
		AUDIO.set_function("_0xE7E6CB8B713ED190", LUA_NATIVE_AUDIO__0xE7E6CB8B713ED190);
		AUDIO.set_function("_0x569ABC36E28DDEAA", LUA_NATIVE_AUDIO__0x569ABC36E28DDEAA);
		AUDIO.set_function("_0x839C9F124BE74D94", LUA_NATIVE_AUDIO__0x839C9F124BE74D94);
		AUDIO.set_function("AUDIO_TRIGGER_EXPLOSION", LUA_NATIVE_AUDIO_AUDIO_TRIGGER_EXPLOSION);
		AUDIO.set_function("_0x3E98AC9D8C56C62C", LUA_NATIVE_AUDIO__0x3E98AC9D8C56C62C);
		AUDIO.set_function("_0xCBF2BEBB468A34F3", LUA_NATIVE_AUDIO__0xCBF2BEBB468A34F3);
		AUDIO.set_function("_0xA2B851605748AD0E", LUA_NATIVE_AUDIO__0xA2B851605748AD0E);
		AUDIO.set_function("_0xCFAD2C8CD1054523", LUA_NATIVE_AUDIO__0xCFAD2C8CD1054523);
		AUDIO.set_function("_0xD733528B6C35647A", LUA_NATIVE_AUDIO__0xD733528B6C35647A);
		AUDIO.set_function("_0x5BC885EBD75FAA7D", LUA_NATIVE_AUDIO__0x5BC885EBD75FAA7D);
		AUDIO.set_function("_0x6B7A88A61B41E589", LUA_NATIVE_AUDIO__0x6B7A88A61B41E589);
		AUDIO.set_function("_0x4BE3EC91C01F0FE8", LUA_NATIVE_AUDIO__0x4BE3EC91C01F0FE8);
		AUDIO.set_function("SET_AUDIO_ONLINE_TRANSITION_STAGE", LUA_NATIVE_AUDIO_SET_AUDIO_ONLINE_TRANSITION_STAGE);
		AUDIO.set_function("_STOP_ALL_SCRIPTED_AUDIO_SOUNDS", LUA_NATIVE_AUDIO__STOP_ALL_SCRIPTED_AUDIO_SOUNDS);
		AUDIO.set_function("_0x64B956F4E761DF5C", LUA_NATIVE_AUDIO__0x64B956F4E761DF5C);
	}
}
