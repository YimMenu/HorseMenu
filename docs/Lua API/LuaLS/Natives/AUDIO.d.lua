---@meta

---@class AUDIO
AUDIO = {}

function AUDIO._0x7455CD705F7E933E() end

function AUDIO.CLEAR_CONVERSATION_HISTORY() end

---@param convoRoot any
function AUDIO._CLEAR_CONVERSATION_HISTORY_FOR_SCRIPTED_CONVERSATION(convoRoot) end

---@param convoRoot any
---@return boolean
function AUDIO.CREATE_NEW_SCRIPTED_CONVERSATION(convoRoot) end

---@param ped integer
---@param p1 any
---@return boolean
function AUDIO._0xDF947FE0D551684E(ped, p1) end

---@param convoRoot any
---@param SpeakerPedIndex integer
---@param characterName any
function AUDIO.ADD_PED_TO_CONVERSATION(convoRoot, SpeakerPedIndex, characterName) end

---@param listeningToPed integer
---@param ped integer
---@param listenerName any
function AUDIO._0xA2323A2EAE32A290(listeningToPed, ped, listenerName) end

---@param convoRoot any
---@param animScene integer
---@return boolean
function AUDIO._0x79F9C57B8D0DFE90(convoRoot, animScene) end

---@param convoRoot any
---@param p1 boolean
---@param p2 boolean
---@param cloneConversation boolean
function AUDIO.START_SCRIPT_CONVERSATION(convoRoot, p1, p2, cloneConversation) end

---@param convoRoot any
---@param p1 boolean
---@param p2 boolean
---@param cloneConversation boolean
function AUDIO.PRELOAD_SCRIPT_CONVERSATION(convoRoot, p1, p2, cloneConversation) end

---@param convoRoot any
function AUDIO.START_PRELOADED_CONVERSATION(convoRoot) end

---@param convoRoot any
---@return boolean
function AUDIO._0x0CB3D1919E8D7CBA(convoRoot) end

---@param p0 boolean
---@return boolean
function AUDIO._0xFE5C6177064BD390(p0) end

---@param convoRoot any
---@return boolean
function AUDIO._IS_SCRIPTED_CONVERSATION_CREATED(convoRoot) end

---@param p0 boolean
---@return boolean
function AUDIO._0x5A13586A9447931F(p0) end

---@param convoRoot any
---@return boolean
function AUDIO.IS_SCRIPTED_CONVERSATION_LOADED(convoRoot) end

---@param p0 boolean
---@return boolean
function AUDIO._IS_ANY_CONVERSATION_PLAYING(p0) end

---@param p0 any
---@return boolean
function AUDIO.IS_SCRIPTED_CONVERSATION_PLAYING(p0) end

---@param p0 any
---@return boolean
function AUDIO._IS_SCRIPTED_CONVERSION_ONGOING(p0) end

---@param p0 boolean
---@return boolean
function AUDIO._0x847748AE5D7B1071(p0) end

---@param convoRoot any
---@return boolean
function AUDIO._0xD0730C1FA40348D9(convoRoot) end

---@param p0 any
---@return integer
function AUDIO.GET_CURRENT_SCRIPTED_CONVERSATION_LINE(p0) end

---@param p0 any
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
function AUDIO.PAUSE_SCRIPTED_CONVERSATION(p0, p1, p2, p3, p4) end

---@param p0 any
function AUDIO.RESTART_SCRIPTED_CONVERSATION(p0) end

---@param p0 boolean
---@param p1 boolean
---@param p2 boolean
function AUDIO._STOP_ALL_SCRIPTED_CONVERSIONS(p0, p1, p2) end

---@param p0 any
---@param p1 boolean
---@param p2 boolean
---@return integer
function AUDIO.STOP_SCRIPTED_CONVERSATION(p0, p1, p2) end

---@param p0 any
function AUDIO.SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE(p0) end

---@param p0 any
---@return integer
function AUDIO._0xF336E9F989B3518F(p0) end

---@param p0 any
---@param currentScriptedConvoLine integer
---@return integer
function AUDIO._0x254B0241E964B450(p0, currentScriptedConvoLine) end

---@param p0 any
---@param currentScriptedConvoLine integer
---@return integer
function AUDIO._0x152ED1B56E8F1F50(p0, currentScriptedConvoLine) end

---@param p0 any
---@param currentScriptedConvoLine integer
---@return integer
function AUDIO._0x935DBD96D4A3DA1F(p0, currentScriptedConvoLine) end

---@param p0 any
---@return integer
function AUDIO._0x295859EB18F48D82(p0) end

---@param convoRoot any
---@param singleLineIndex integer
function AUDIO._0x40CA665AB9D8D505(convoRoot, singleLineIndex) end

---@param p0 any
function AUDIO._0xF232C2C546AC16D0(p0) end

---@param audSpeechEvent any
function AUDIO._0x1E6F9A9FE1A99F36(audSpeechEvent) end

---@param InChargeOfAudio boolean
function AUDIO.REGISTER_SCRIPT_WITH_AUDIO(InChargeOfAudio) end

function AUDIO.UNREGISTER_SCRIPT_WITH_AUDIO() end

---@param BankName any
---@return boolean
function AUDIO.REQUEST_SCRIPT_AUDIO_BANK(BankName) end

---@param BankName any
function AUDIO.RELEASE_NAMED_SCRIPT_AUDIO_BANK(BankName) end

function AUDIO.RELEASE_SCRIPT_AUDIO_BANK() end

---@return integer
function AUDIO.GET_SOUND_ID() end

---@param SoundId integer
function AUDIO.RELEASE_SOUND_ID(SoundId) end

---@param SoundName any
---@param SetName any
---@param p2 boolean
---@param p3 any
---@param p4 boolean
---@param p5 any
function AUDIO.PLAY_SOUND(SoundName, SetName, p2, p3, p4, p5) end

---@param SoundName any
---@param SetName any
---@param p2 boolean
---@param p3 any
function AUDIO.PLAY_SOUND_FRONTEND(SoundName, SetName, p2, p3) end

---@param item integer
---@param soundSet integer
---@param p2 any
function AUDIO._PLAY_SOUND_FROM_ITEM(item, soundSet, p2) end

---@param audioName any
---@param entity integer
---@param audioRef any
---@param isNetwork boolean
---@param p4 any
---@param p5 any
function AUDIO.PLAY_SOUND_FROM_ENTITY(audioName, entity, audioRef, isNetwork, p4, p5) end

---@param audioName any
---@param x number
---@param y number
---@param z number
---@param audioRef any
---@param isNetwork boolean
---@param p6 any
---@param p7 boolean
---@param p8 any
function AUDIO._PLAY_SOUND_FROM_POSITION(audioName, x, y, z, audioRef, isNetwork, p6, p7, p8) end

---@param audioName any
---@param audioRef any
function AUDIO._STOP_SOUND_WITH_NAME(audioName, audioRef) end

---@param audioName any
---@param audioRef any
---@return boolean
function AUDIO._0x580D71DFE0088E34(audioName, audioRef) end

---@param item integer
---@param soundSet integer
---@return boolean
function AUDIO._IS_SCRIPTED_AUDIO_CUSTOM(item, soundSet) end

---@param variableName any
---@param variableValue number
---@param audioName any
---@param audioRef any
function AUDIO._SET_VARIABLE_ON_SOUND_WITH_NAME(variableName, variableValue, audioName, audioRef) end

---@param ped integer
---@param whistleConfig any
---@param value number
function AUDIO._SET_WHISTLE_CONFIG_FOR_PED(ped, whistleConfig, value) end

---@param ped integer
---@param p1 any
---@param p2 any
function AUDIO._SET_SOUND_RELATIONSHIP_ON_PED(ped, p1, p2) end

---@param soundId integer
---@param name any
---@param soundSet any
---@param p3 boolean
function AUDIO._PLAY_SOUND_FRONTEND_WITH_SOUND_ID(soundId, name, soundSet, p3) end

---@param soundId integer
---@param soundName any
---@param entity integer
---@param soundsetName any
---@param p4 boolean
---@param p5 any
function AUDIO._PLAY_SOUND_FROM_ENTITY_WITH_SET(soundId, soundName, entity, soundsetName, p4, p5) end

---@param soundId integer
---@param soundName any
---@param x number
---@param y number
---@param z number
---@param soundsetName any
---@param p6 boolean
---@param p7 integer
---@param p8 boolean
function AUDIO._PLAY_SOUND_FROM_POSITION_WITH_ID(soundId, soundName, x, y, z, soundsetName, p6, p7, p8) end

---@param soundId integer
---@param x number
---@param y number
---@param z number
function AUDIO._UPDATE_SOUND_POSITION(soundId, x, y, z) end

---@param soundId integer
function AUDIO._STOP_SOUND_WITH_ID(soundId) end

---@param soundId integer
---@param variableName any
---@param variableValue number
function AUDIO._SET_VARIABLE_ON_SOUND_WITH_ID(soundId, variableName, variableValue) end

---@param soundName any
---@param soundsetName any
---@param soundId integer
---@return boolean
function AUDIO.PREPARE_SOUND(soundName, soundsetName, soundId) end

---@param soundName any
---@param soundsetName any
function AUDIO._RELEASE_SHARD_SOUNDS(soundName, soundsetName) end

---@param soundsetName any
---@param p1 boolean
---@return boolean
function AUDIO.PREPARE_SOUNDSET(soundsetName, p1) end

---@param soundsetName any
function AUDIO._RELEASE_SOUNDSET(soundsetName) end

---@param soundName any
---@param entity integer
---@param soundsetName any
---@param soundId integer
---@return boolean
function AUDIO.PREPARE_SOUND_WITH_ENTITY(soundName, entity, soundsetName, soundId) end

---@param p0 any
---@param p1 number
function AUDIO._0x3E93DDDCBB6111E4(p0, p1) end

---@param audioName any
---@param soundsetName any
---@return boolean
function AUDIO._HAS_SOUND_AUDIO_NAME_FINISHED(audioName, soundsetName) end

---@param soundId integer
---@return boolean
function AUDIO._HAS_SOUND_ID_FINISHED(soundId) end

---@param PedIndex integer
---@param params integer
---@return boolean
function AUDIO.PLAY_PED_AMBIENT_SPEECH_NATIVE(PedIndex, params) end

---@param PositionX number
---@param PositionY number
---@param PositionZ number
---@param params integer
---@return boolean
function AUDIO.PLAY_AMBIENT_SPEECH_FROM_POSITION_NATIVE(PositionX, PositionY, PositionZ, params) end

---@param p0 integer
---@param p1 any
---@return any
function AUDIO._0x72E4D1C4639BC465(p0, p1) end

---@param p0 any
---@return any
function AUDIO._0xB18FEC133C7C6C69(p0) end

---@param p0 any
function AUDIO._0xDC93F0948F2C28F4(p0) end

---@param speechEventType integer
---@param p1 integer
---@param p2 boolean
function AUDIO._0x0D7FD6A55FD63AEF(speechEventType, p1, p2) end

---@param speechEventType integer
function AUDIO._0x660A8F876DF1D4F8(speechEventType) end

---@param p0 any
---@param p1 any
---@param p2 any
function AUDIO._0x380A2E353AD30917(p0, p1, p2) end

---@param p0 any
function AUDIO._0x0FAF7171BF613B80(p0) end

---@param PedIndex integer
---@param DamageReason integer
---@param RawDamage number
---@param p3 boolean
---@param SyncOverNetwork boolean
function AUDIO.PLAY_PAIN(PedIndex, DamageReason, RawDamage, p3, SyncOverNetwork) end

---@param p0 any
function AUDIO._0x6652B0C8F3D414D0(p0) end

---@param ropeId integer
---@param name any
function AUDIO._0xF092B6030D6FD49C(ropeId, name) end

---@param ropeId integer
---@param p1 number
function AUDIO._0x2651DDC0EA269073(ropeId, p1) end

---@param PedIndex integer
---@param VoiceName any
function AUDIO.SET_AMBIENT_VOICE_NAME(PedIndex, VoiceName) end

---@param ped integer
---@param voice integer
function AUDIO._SET_VOFX_PED_VOICE(ped, voice) end

---@param PedIndex integer
---@param p1 any
function AUDIO.STOP_CURRENT_PLAYING_SPEECH(PedIndex, p1) end

---@param PedIndex integer
---@param p1 any
function AUDIO.STOP_CURRENT_PLAYING_AMBIENT_SPEECH(PedIndex, p1) end

---@param PedIndex integer
---@return boolean
function AUDIO.IS_AMBIENT_SPEECH_PLAYING(PedIndex) end

---@param PedIndex integer
---@return boolean
function AUDIO.IS_SCRIPTED_SPEECH_PLAYING(PedIndex) end

---@param PedIndex integer
---@return boolean
function AUDIO.IS_ANY_SPEECH_PLAYING(PedIndex) end

---@return any
function AUDIO._0x2B101AD9F651243A() end

---@param p0 any
---@return any
function AUDIO._0x4A98E228A936DBCC(p0) end

---@param p0 any
---@return any
function AUDIO._0x6BFFB7C276866996(p0) end

---@param PedIndex integer
---@param context any
---@param allowBackupPVG boolean
---@return boolean
function AUDIO.DOES_CONTEXT_EXIST_FOR_THIS_PED(PedIndex, context, allowBackupPVG) end

---@param p0 any
---@return any
function AUDIO._0xF0EE69F500952FA5(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function AUDIO._0x9D6DEC9791A4E501(p0, p1, p2, p3) end

---@param ped integer
function AUDIO._0x864A842B86993851(ped) end

---@param p0 any
---@param PedIndex integer
---@param p2 any
---@return boolean
function AUDIO.IS_PED_IN_CURRENT_CONVERSATION(p0, PedIndex, p2) end

---@param ped integer
---@param p1 boolean
---@return boolean
function AUDIO._IS_PED_IN_ANY_CONVERSATION(ped, p1) end

---@param PedIndex integer
---@param IsDrunk boolean
function AUDIO.SET_PED_IS_DRUNK(PedIndex, IsDrunk) end

---@param p0 any
---@param p1 any
function AUDIO._0x3A00D87B20A2A5E4(p0, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0xD47D47EFBF103FB8(p0, p1) end

---@param PedIndex integer
---@param vocalizationName any
---@param p2 boolean
function AUDIO.PLAY_ANIMAL_VOCALIZATION(PedIndex, vocalizationName, p2) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function AUDIO._PLAY_ANIMAL_VOCALIZATION_PHEROMONE_VIAL_RESPONSE(ped, p1, p2) end

---@param PedIndex integer
---@return boolean
function AUDIO.IS_ANIMAL_VOCALIZATION_PLAYING(PedIndex) end

---@param PedIndex integer
---@param Mood integer
function AUDIO.SET_ANIMAL_MOOD(PedIndex, Mood) end

---@param p0 any
---@param p1 any
function AUDIO._0xFCDEC42B1C78B7F8(p0, p1) end

---@param p0 any
function AUDIO._0xEB4D592620B8C209(p0) end

---@param p0 any
---@param p1 any
function AUDIO._0xA6847BBA4FCDD13F(p0, p1) end

---@param EmitterName any
---@param enabled boolean
function AUDIO.SET_STATIC_EMITTER_ENABLED(EmitterName, enabled) end

---@param bActive boolean
function AUDIO.PLAY_END_CREDITS_MUSIC(bActive) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function AUDIO._0x7678FE0455ED1145(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param x number
---@param y number
---@param z number
---@param isSrlLoaded boolean
---@param p6 any
---@return any
function AUDIO._0xFFE9C53DEEA3DB0B(p0, p1, x, y, z, isSrlLoaded, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function AUDIO._0x5E3CCF03995388B5(p0, p1, p2, p3) end

function AUDIO._0x43037ABFE214A851() end

---@param zoneName any
---@param enabled boolean
---@param forceUpdate boolean
function AUDIO.SET_AMBIENT_ZONE_STATE(zoneName, enabled, forceUpdate) end

---@param zoneName any
---@param forceUpdate boolean
function AUDIO.CLEAR_AMBIENT_ZONE_STATE(zoneName, forceUpdate) end

---@param zoneListName any
---@param enabled boolean
---@param forceUpdate boolean
function AUDIO.SET_AMBIENT_ZONE_LIST_STATE(zoneListName, enabled, forceUpdate) end

---@param zoneListName any
---@param forceUpdate boolean
function AUDIO.CLEAR_AMBIENT_ZONE_LIST_STATE(zoneListName, forceUpdate) end

---@param zoneName any
---@param enabled boolean
---@param forceUpdate boolean
function AUDIO.SET_AMBIENT_ZONE_STATE_PERSISTENT(zoneName, enabled, forceUpdate) end

---@param zoneListName any
---@param enabled boolean
---@param forceUpdate boolean
function AUDIO.SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT(zoneListName, enabled, forceUpdate) end

---@param ambientZone any
---@param x number
---@param y number
---@param z number
---@param heading number
function AUDIO._SET_AMBIENT_ZONE_POSITION(ambientZone, x, y, z, heading) end

---@param VehIndex integer
---@return boolean
function AUDIO.IS_HORN_ACTIVE(VehIndex) end

---@param p0 any
---@param p1 any
function AUDIO._0xFD461D0ABA5559B1(p0, p1) end

---@param streamId integer
---@return boolean
function AUDIO.IS_STREAM_PLAYING(streamId) end

---@param streamName any
---@param SetName any
---@return boolean
function AUDIO.LOAD_STREAM(streamName, SetName) end

---@param PedIndex integer
---@param streamId integer
function AUDIO.PLAY_STREAM_FROM_PED(PedIndex, streamId) end

---@param streamId integer
function AUDIO.PLAY_STREAM_FRONTEND(streamId) end

---@param positionX number
---@param positionY number
---@param positionZ number
---@param streamId integer
function AUDIO.PLAY_STREAM_FROM_POSITION(positionX, positionY, positionZ, streamId) end

---@param p0 any
---@param p1 any
function AUDIO._0x3A3BE6B920525237(p0, p1) end

---@param streamId integer
function AUDIO.STOP_STREAM(streamId) end

---@param PedIndex integer
---@param ShouldDisable boolean
function AUDIO.STOP_PED_SPEAKING(PedIndex, ShouldDisable) end

---@param PedIndex integer
---@param ShouldDisable boolean
function AUDIO.DISABLE_PED_PAIN_AUDIO(PedIndex, ShouldDisable) end

---@param PedIndex integer
---@return boolean
function AUDIO.IS_AMBIENT_SPEECH_DISABLED(PedIndex) end

---@param ped integer
---@param disabled boolean
---@return any
function AUDIO.SET_IS_SCRIPTED_SPEECH_DISABLED(ped, disabled) end

---@param context any
---@param block boolean
function AUDIO._BLOCK_SPEECH_CONTEXT(context, block) end

---@param speechContext any
function AUDIO._UNLOAD_SPEECH_CONTEXT(speechContext) end

---@param VehicleIndex integer
---@param Enable boolean
function AUDIO.SET_HORN_ENABLED(VehicleIndex, Enable) end

---@param VehicleIndex integer
---@param priority integer
function AUDIO.SET_AUDIO_VEHICLE_PRIORITY(VehicleIndex, priority) end

---@param p0 any
---@param p1 any
function AUDIO._0x259ACC5B52A2B2D9(p0, p1) end

---@param VehicleIndex integer
---@param GameObjectName any
function AUDIO.FORCE_USE_AUDIO_GAME_OBJECT(VehicleIndex, GameObjectName) end

---@param DisableGps boolean
function AUDIO.SET_GPS_ACTIVE(DisableGps) end

---@param audioName any
---@param sceneset any
---@return boolean
function AUDIO._START_AUDIO_SCENESET(audioName, sceneset) end

---@param sceneset any
function AUDIO._STOP_AUDIO_SCENESET(sceneset) end

---@param audioName any
---@param sceneset any
---@return boolean
function AUDIO._SET_AUDIO_SCENESET(audioName, sceneset) end

---@param SceneName any
---@return boolean
function AUDIO.START_AUDIO_SCENE(SceneName) end

---@param p0 any
---@return any
function AUDIO._0xDC2F83A0612CA34D(p0) end

---@param SceneName any
function AUDIO.STOP_AUDIO_SCENE(SceneName) end

---@param p0 any
function AUDIO._0x6AB944DF68B512D3(p0) end

function AUDIO.STOP_AUDIO_SCENES() end

---@param SceneName any
---@return boolean
function AUDIO.IS_AUDIO_SCENE_ACTIVE(SceneName) end

---@param SceneName any
---@param VariableName any
---@param Value number
function AUDIO.SET_AUDIO_SCENE_VARIABLE(SceneName, VariableName, Value) end

---@param entity integer
---@return integer
function AUDIO._GET_ENTITY_AUDIO_MIX_GROUP(entity) end

---@param EntityIndex integer
---@param groupName any
---@param fadeIn number
function AUDIO.ADD_ENTITY_TO_AUDIO_MIX_GROUP(EntityIndex, groupName, fadeIn) end

---@param p0 any
---@return any
function AUDIO._0x131EC9247E7A2903(p0) end

---@param EntityIndex integer
---@param fadeOut number
function AUDIO.REMOVE_ENTITY_FROM_AUDIO_MIX_GROUP(EntityIndex, fadeOut) end

---@return any
function AUDIO._0xE600F61F54A444A6() end

---@return boolean
function AUDIO.AUDIO_IS_MUSIC_PLAYING() end

---@param entity integer
---@return integer
function AUDIO._0xBE28DB99556FF8D9(entity) end

---@param ped integer
function AUDIO._0x8E901B65206C2D3E(ped) end

---@param ped integer
function AUDIO._0xC4CFCE4C656EF480(ped) end

---@param entity integer
---@param p1 any
---@param p2 any
---@param p3 number
---@param p4 any
function AUDIO._0xABDB4863D3D72021(entity, p1, p2, p3, p4) end

---@param ped integer
---@param p1 integer
function AUDIO._0xB93A769B8B726950(ped, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0xE891504B2F0E2DBA(p0, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0x9EB779765E68C52E(p0, p1) end

---@param entity integer
---@param p1 any
function AUDIO._0xE9694B2D6CB87B06(entity, p1) end

---@param entity integer
---@return any
function AUDIO._0x886657C5B3D8EDE3(entity) end

---@param p0 any
---@return any
function AUDIO._0xC68C02DE259C927C(p0) end

---@param entity integer
---@return any
function AUDIO._0x2FFF4A78384AFFDF(entity) end

---@param entity integer
---@return integer
function AUDIO._0x62377977E4F08668(entity) end

---@param ped integer
---@return any
function AUDIO._GET_PED_SONG_INDEX_HOST(ped) end

---@param p0 any
---@return any
function AUDIO._0xD05A460328560477(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function AUDIO._0x8D29FDF565DED9AE(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function AUDIO._0x448F2647DD6F2E27(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function AUDIO._0x139A4B9DF2D26CBF(p0, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0x018ABE833CA64D2A(p0, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0xBC07CA8FD710E7FD(p0, p1) end

---@param eventName any
---@return boolean
function AUDIO.PREPARE_MUSIC_EVENT(eventName) end

---@param eventName any
---@return boolean
function AUDIO.CANCEL_MUSIC_EVENT(eventName) end

---@param eventName any
---@return boolean
function AUDIO.TRIGGER_MUSIC_EVENT(eventName) end

---@param eventName integer
---@return any
function AUDIO._TRIGGER_MUSIC_EVENT_WITH_HASH(eventName) end

---@return integer
function AUDIO.GET_MUSIC_PLAYTIME() end

---@param p0 any
---@param p1 any
---@param p2 any
function AUDIO._0xF64034D533CE8AAC(p0, p1, p2) end

---@param density number
---@param applyValue number
function AUDIO.SET_PED_WALLA_DENSITY(density, applyValue) end

function AUDIO._0xDAD6CD07CAA4F382() end

---@param density number
---@param applyValue number
function AUDIO.SET_PED_INTERIOR_WALLA_DENSITY(density, applyValue) end

function AUDIO.FORCE_PED_PANIC_WALLA() end

function AUDIO._0x138ADB94F8B90616() end

---@param PedIndex integer
---@param use boolean
---@param soundSetHash integer
function AUDIO.USE_FOOTSTEP_SCRIPT_SWEETENERS(PedIndex, use, soundSetHash) end

---@param flagName any
---@param enabled boolean
function AUDIO.SET_AUDIO_FLAG(flagName, enabled) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function AUDIO._0x6DA15746D5CC1A92(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
function AUDIO._0x078F77FD1A43EAB3(p0, p1) end

function AUDIO._0x3D0BBCCF401B5FDB() end

---@param OldPortalSettingsName any
---@param NewPortalSettingsName any
function AUDIO.SET_PORTAL_SETTINGS_OVERRIDE(OldPortalSettingsName, NewPortalSettingsName) end

---@param PortalSettingsName any
function AUDIO.REMOVE_PORTAL_SETTINGS_OVERRIDE(PortalSettingsName) end

---@param p0 any
function AUDIO._0xEA546C31FD45F8CD(p0) end

---@param p0 any
---@return any
function AUDIO._0x44A5EEF54F62E823(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function AUDIO._0x017492B2201E3428(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function AUDIO._0xC886CD666ADD42E1(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function AUDIO._0x5AE0CB5F35F034FD(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param p0 any
---@param p1 any
---@param p2 any
function AUDIO._0x821C32C728B24477(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function AUDIO._0x06C5DF5EE444BC6B(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function AUDIO._0x341CDD17EFC2472E(p0, p1) end

---@param p0 any
function AUDIO._0x7E176C676F8652A9(p0) end

---@param p0 any
---@return any
function AUDIO._0x2B9C37C01BF25EDB(p0) end

---@return any
function AUDIO._0xA6A3A3F96B8B030E() end

---@param streamName any
---@param soundSet any
---@return integer
function AUDIO._GET_LOADED_STREAM_ID_FROM_CREATION(streamName, soundSet) end

---@param p0 any
---@param p1 any
---@return any
function AUDIO._0xC369E2234E34A0CA(p0, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0x35B8C070E0C16E2F(p0, p1) end

function AUDIO._0xE7E6CB8B713ED190() end

function AUDIO._0x569ABC36E28DDEAA() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function AUDIO._0x839C9F124BE74D94(p0, p1, p2, p3, p4) end

---@param name any
---@param x number
---@param y number
---@param z number
function AUDIO.AUDIO_TRIGGER_EXPLOSION(name, x, y, z) end

---@param p0 any
function AUDIO._0x3E98AC9D8C56C62C(p0) end

---@param p0 any
function AUDIO._0xCBF2BEBB468A34F3(p0) end

function AUDIO._0xA2B851605748AD0E() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function AUDIO._0xCFAD2C8CD1054523(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function AUDIO._0xD733528B6C35647A(p0, p1) end

---@param p0 any
---@param p1 any
function AUDIO._0x5BC885EBD75FAA7D(p0, p1) end

---@param p0 any
function AUDIO._0x6B7A88A61B41E589(p0) end

function AUDIO._0x4BE3EC91C01F0FE8() end

---@param p0 any
function AUDIO.SET_AUDIO_ONLINE_TRANSITION_STAGE(p0) end

function AUDIO._STOP_ALL_SCRIPTED_AUDIO_SOUNDS() end

---@param p0 any
function AUDIO._0x64B956F4E761DF5C(p0) end
