#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static AnimScene LUA_NATIVE_ANIMSCENE__CREATE_ANIM_SCENE(sol::stack_object animDict, int flags, sol::stack_object playbackListName, bool p3, bool p4)
	{
		auto retval = ANIMSCENE::_CREATE_ANIM_SCENE(animDict.is<const char*>() ? animDict.as<const char*>() : nullptr, flags, playbackListName.is<const char*>() ? playbackListName.as<const char*>() : nullptr, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__DELETE_ANIM_SCENE(AnimScene animScene)
	{
		ANIMSCENE::_DELETE_ANIM_SCENE(animScene);
	}

	static void LUA_NATIVE_ANIMSCENE_TRIGGER_ANIM_SCENE_SKIP(AnimScene animScene)
	{
		ANIMSCENE::TRIGGER_ANIM_SCENE_SKIP(animScene);
	}

	static bool LUA_NATIVE_ANIMSCENE__0x4B85B3CF91972222(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_0x4B85B3CF91972222(animScene);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__CLEAR_ANIM_SCENE_WAS_SKIPPED(AnimScene animScene)
	{
		ANIMSCENE::_CLEAR_ANIM_SCENE_WAS_SKIPPED(animScene);
	}

	static bool LUA_NATIVE_ANIMSCENE_DOES_ANIM_SCENE_EXIST(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::DOES_ANIM_SCENE_EXIST(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__DOES_ENTITY_WITH_ID_EXIST_IN_ANIM_SCENE(AnimScene animScene, sol::stack_object entityId)
	{
		auto retval = (bool)ANIMSCENE::_DOES_ENTITY_WITH_ID_EXIST_IN_ANIM_SCENE(animScene, entityId.is<const char*>() ? entityId.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__DOES_ANIM_SCENE_OWNERSHIP_OF_ENTITY_EXIST(AnimScene animScene, sol::stack_object entityName)
	{
		auto retval = (bool)ANIMSCENE::_DOES_ANIM_SCENE_OWNERSHIP_OF_ENTITY_EXIST(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_LOAD_ANIM_SCENE(AnimScene animScene)
	{
		ANIMSCENE::LOAD_ANIM_SCENE(animScene);
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_LOADED(AnimScene animScene, bool p1, bool p2)
	{
		auto retval = (bool)ANIMSCENE::IS_ANIM_SCENE_LOADED(animScene, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_LOADING(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_LOADING(animScene, p1);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_METADATA_ASSET_IN_RANGE_LOADING(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_METADATA_ASSET_IN_RANGE_LOADING(animScene, p1);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_METADATA_LOADED(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::IS_ANIM_SCENE_METADATA_LOADED(animScene, p1);
		return retval;
	}

	static int LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_PLAYBACK_LIST_PHASE_AUDIO_LOAD_STRESS(AnimScene animScene, sol::stack_object phaseName)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_PLAYBACK_LIST_PHASE_AUDIO_LOAD_STRESS(animScene, phaseName.is<const char*>() ? phaseName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_START_ANIM_SCENE(AnimScene animScene)
	{
		ANIMSCENE::START_ANIM_SCENE(animScene);
	}

	static void LUA_NATIVE_ANIMSCENE_RESET_ANIM_SCENE(AnimScene animScene, sol::stack_object playbackListName)
	{
		ANIMSCENE::RESET_ANIM_SCENE(animScene, playbackListName.is<const char*>() ? playbackListName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_ANIMSCENE_ABORT_ANIM_SCENE(AnimScene animScene, bool p1)
	{
		ANIMSCENE::ABORT_ANIM_SCENE(animScene, p1);
	}

	static void LUA_NATIVE_ANIMSCENE_RESUME_ANIM_SCENE_FROM_LAST_CHECKPOINT(AnimScene animScene)
	{
		ANIMSCENE::RESUME_ANIM_SCENE_FROM_LAST_CHECKPOINT(animScene);
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_RUNNING(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::IS_ANIM_SCENE_RUNNING(animScene, p1);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_FINISHED(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::IS_ANIM_SCENE_FINISHED(animScene, p1);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_EXITING_THIS_FRAME(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::IS_ANIM_SCENE_EXITING_THIS_FRAME(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_HAS_ANIM_SCENE_EXITED(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::HAS_ANIM_SCENE_EXITED(animScene, p1);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0x73616E64696C132E(AnimScene animScene, bool p1)
	{
		auto retval = (bool)ANIMSCENE::_0x73616E64696C132E(animScene, p1);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_IN_SECTION(AnimScene animScene, sol::stack_object sectionName, bool p2)
	{
		auto retval = (bool)ANIMSCENE::IS_ANIM_SCENE_IN_SECTION(animScene, sectionName.is<const char*>() ? sectionName.as<const char*>() : nullptr, p2);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_SKIPPABLE(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_SKIPPABLE(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_ABORTED(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_ABORTED(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0xD70C7A30412F8FA0(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_0xD70C7A30412F8FA0(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0x9AAE3C1148A09BCA(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_0x9AAE3C1148A09BCA(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0xA96619FE85159ED2(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_0xA96619FE85159ED2(animScene);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_FADE_ANIM_SCENE_AUDIO_IN(AnimScene animScene, float p1)
	{
		ANIMSCENE::FADE_ANIM_SCENE_AUDIO_IN(animScene, p1);
	}

	static void LUA_NATIVE_ANIMSCENE_FADE_ANIM_SCENE_AUDIO_OUT(AnimScene animScene, float p1)
	{
		ANIMSCENE::FADE_ANIM_SCENE_AUDIO_OUT(animScene, p1);
	}

	static void LUA_NATIVE_ANIMSCENE_BLOCK_ANIM_SCENE_FADING_NEXT_FRAME(bool p0, bool p1)
	{
		ANIMSCENE::BLOCK_ANIM_SCENE_FADING_NEXT_FRAME(p0, p1);
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_ORIGIN(AnimScene animScene, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, int order)
	{
		ANIMSCENE::SET_ANIM_SCENE_ORIGIN(animScene, posX, posY, posZ, rotX, rotY, rotZ, order);
	}

	static std::tuple<Vector3, Vector3> LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_ORIGIN(AnimScene animScene, Vector3 position, Vector3 rotation, int order)
	{
		std::tuple<Vector3, Vector3> return_values;
		ANIMSCENE::GET_ANIM_SCENE_ORIGIN(animScene, &position, &rotation, order);
		std::get<0>(return_values) = position;
		std::get<1>(return_values) = rotation;

		return return_values;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_PAUSED(AnimScene animScene, bool toggle)
	{
		ANIMSCENE::SET_ANIM_SCENE_PAUSED(animScene, toggle);
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PAUSED(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_PAUSED(animScene);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_RATE(AnimScene animScene, float rate)
	{
		ANIMSCENE::SET_ANIM_SCENE_RATE(animScene, rate);
	}

	static float LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_RATE(AnimScene animScene)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_RATE(animScene);
		return retval;
	}

	static float LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_PHASE(AnimScene animScene)
	{
		auto retval = ANIMSCENE::GET_ANIM_SCENE_PHASE(animScene);
		return retval;
	}

	static float LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_TIME(AnimScene animScene)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_TIME(animScene);
		return retval;
	}

	static float LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_DURATION(AnimScene animScene)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_DURATION(animScene);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_ENTITY(AnimScene animScene, sol::stack_object entityName, Entity entity, int flags)
	{
		ANIMSCENE::SET_ANIM_SCENE_ENTITY(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr, entity, flags);
	}

	static void LUA_NATIVE_ANIMSCENE_REMOVE_ANIM_SCENE_ENTITY(AnimScene animScene, sol::stack_object entityName, Entity entity)
	{
		ANIMSCENE::REMOVE_ANIM_SCENE_ENTITY(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr, entity);
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ENTITY_EXITING_ANIM_SCENE_THIS_FRAME(AnimScene animScene, sol::stack_object entityName)
	{
		auto retval = (bool)ANIMSCENE::IS_ENTITY_EXITING_ANIM_SCENE_THIS_FRAME(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_COULD_ANIM_SCENE_ENTITY_REACH_EXIT_NEXT_FRAME(AnimScene animScene, sol::stack_object entityName, Any p2, Any p3)
	{
		auto retval = (bool)ANIMSCENE::COULD_ANIM_SCENE_ENTITY_REACH_EXIT_NEXT_FRAME(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr, p2, p3);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_HAS_ENTITY_EXITED_ANIM_SCENE(AnimScene animScene, sol::stack_object entityName)
	{
		auto retval = (bool)ANIMSCENE::HAS_ENTITY_EXITED_ANIM_SCENE(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__HAS_ENTITY_ENTERED_ANIM_SCENE(AnimScene animScene, sol::stack_object entityName)
	{
		auto retval = (bool)ANIMSCENE::_HAS_ENTITY_ENTERED_ANIM_SCENE(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr);
		return retval;
	}

	static Ped LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_PED(AnimScene animScene, sol::stack_object name, bool isNetwork)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_PED(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr, isNetwork);
		return retval;
	}

	static Object LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_OBJECT(AnimScene animScene, sol::stack_object name, bool isNetwork)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_OBJECT(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr, isNetwork);
		return retval;
	}

	static Vehicle LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_VEHICLE(AnimScene animScene, sol::stack_object name, bool isNetwork)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_VEHICLE(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr, isNetwork);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_BOOL(AnimScene animScene, sol::stack_object name, bool value, bool p3)
	{
		ANIMSCENE::SET_ANIM_SCENE_BOOL(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr, value, p3);
	}

	static bool LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_BOOL(AnimScene animScene, sol::stack_object name)
	{
		auto retval = (bool)ANIMSCENE::GET_ANIM_SCENE_BOOL(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_FLOAT(AnimScene animScene, sol::stack_object name, float value, bool p3, bool p4)
	{
		ANIMSCENE::SET_ANIM_SCENE_FLOAT(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr, value, p3, p4);
	}

	static float LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_FLOAT(AnimScene animScene, sol::stack_object name)
	{
		auto retval = ANIMSCENE::GET_ANIM_SCENE_FLOAT(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_INT(AnimScene animScene, sol::stack_object name, int value, bool p3)
	{
		ANIMSCENE::SET_ANIM_SCENE_INT(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr, value, p3);
	}

	static int LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_INT(AnimScene animScene, sol::stack_object name)
	{
		auto retval = ANIMSCENE::GET_ANIM_SCENE_INT(animScene, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static std::tuple<bool, Vector3> LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_ENTITY_LOCATION_DATA(AnimScene animScene, sol::stack_object entityName, Vector3 matrix, bool p3, sol::stack_object playbackListName, int p5)
	{
		std::tuple<bool, Vector3> return_values;
		std::get<0>(return_values) = (bool)ANIMSCENE::GET_ANIM_SCENE_ENTITY_LOCATION_DATA(animScene, entityName.is<const char*>() ? entityName.as<const char*>() : nullptr, &matrix, p3, playbackListName.is<const char*>() ? playbackListName.as<const char*>() : nullptr, p5);
		std::get<1>(return_values) = matrix;

		return return_values;
	}

	static bool LUA_NATIVE_ANIMSCENE_IS_ENTITY_PLAYING_ANIM_SCENE(Entity entity, AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::IS_ENTITY_PLAYING_ANIM_SCENE(entity, animScene);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_ATTACH_ANIM_SCENE_TO_ENTITY(AnimScene animScene, Entity entity, int p2)
	{
		ANIMSCENE::ATTACH_ANIM_SCENE_TO_ENTITY(animScene, entity, p2);
	}

	static void LUA_NATIVE_ANIMSCENE_ATTACH_ANIM_SCENE_TO_ENTITY_PRESERVING_LOCATION(AnimScene animScene, Entity entity, int p2)
	{
		ANIMSCENE::ATTACH_ANIM_SCENE_TO_ENTITY_PRESERVING_LOCATION(animScene, entity, p2);
	}

	static void LUA_NATIVE_ANIMSCENE_DETACH_ANIM_SCENE(AnimScene animScene)
	{
		ANIMSCENE::DETACH_ANIM_SCENE(animScene);
	}

	static void LUA_NATIVE_ANIMSCENE_DETACH_ANIM_SCENE_PRESERVING_LOCATION(AnimScene animScene)
	{
		ANIMSCENE::DETACH_ANIM_SCENE_PRESERVING_LOCATION(animScene);
	}

	static void LUA_NATIVE_ANIMSCENE_TAKE_OWNERSHIP_OF_ANIM_SCENE(AnimScene animScene)
	{
		ANIMSCENE::TAKE_OWNERSHIP_OF_ANIM_SCENE(animScene);
	}

	static bool LUA_NATIVE_ANIMSCENE_CHECK_OWNERSHIP_OF_ANIM_SCENE(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::CHECK_OWNERSHIP_OF_ANIM_SCENE(animScene);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_PLAYBACK_LIST(AnimScene animScene, sol::stack_object playbackListName)
	{
		ANIMSCENE::SET_ANIM_SCENE_PLAYBACK_LIST(animScene, playbackListName.is<const char*>() ? playbackListName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_ANIMSCENE__0x1C5D33A4293E6DDE(AnimScene animScene, sol::stack_object phaseName)
	{
		auto retval = (bool)ANIMSCENE::_0x1C5D33A4293E6DDE(animScene, phaseName.is<const char*>() ? phaseName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__DOES_ANIM_SCENE_PLAY_LIST_EXIST(AnimScene animScene, sol::stack_object playbackListName)
	{
		auto retval = (bool)ANIMSCENE::_DOES_ANIM_SCENE_PLAY_LIST_EXIST(animScene, playbackListName.is<const char*>() ? playbackListName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_PLAY_LIST(AnimScene animScene, sol::stack_object playlistName, bool p2)
	{
		ANIMSCENE::SET_ANIM_SCENE_PLAY_LIST(animScene, playlistName.is<const char*>() ? playlistName.as<const char*>() : nullptr, p2);
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_ACTIVE(AnimScene animScene, sol::stack_object phaseName)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_ACTIVE(animScene, phaseName.is<const char*>() ? phaseName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE_REQUEST_ANIM_SCENE_PLAY_LIST(AnimScene animScene, sol::stack_object playlistName)
	{
		auto retval = (bool)ANIMSCENE::REQUEST_ANIM_SCENE_PLAY_LIST(animScene, playlistName.is<const char*>() ? playlistName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__RELEASE_ANIM_SCENE_PLAY_LIST(AnimScene animScene, sol::stack_object playlistName)
	{
		auto retval = (bool)ANIMSCENE::_RELEASE_ANIM_SCENE_PLAY_LIST(animScene, playlistName.is<const char*>() ? playlistName.as<const char*>() : nullptr);
		return retval;
	}

	static Hash LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_DICT(AnimScene animScene)
	{
		auto retval = ANIMSCENE::_GET_ANIM_SCENE_DICT(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0x1407F5115FB9583E(AnimScene animScene, sol::stack_object p1)
	{
		auto retval = (bool)ANIMSCENE::_0x1407F5115FB9583E(animScene, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADED(AnimScene animScene, sol::stack_object phaseName)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADED(animScene, phaseName.is<const char*>() ? phaseName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADING(AnimScene animScene, sol::stack_object phaseName)
	{
		auto retval = (bool)ANIMSCENE::_IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADING(animScene, phaseName.is<const char*>() ? phaseName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__0x1AD896BF43619551()
	{
		ANIMSCENE::_0x1AD896BF43619551();
	}

	static int LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_CURRENT_ACTIVE_CAMERA_COUNT(AnimScene animScene)
	{
		auto retval = ANIMSCENE::GET_ANIM_SCENE_CURRENT_ACTIVE_CAMERA_COUNT(animScene);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0x5D7BFDA2290B4E39(sol::stack_object p0)
	{
		auto retval = (bool)ANIMSCENE::_0x5D7BFDA2290B4E39(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__IS_MGM_SYSTEM_LOADED(sol::stack_object mgmFilename)
	{
		auto retval = (bool)ANIMSCENE::_IS_MGM_SYSTEM_LOADED(mgmFilename.is<const char*>() ? mgmFilename.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__LOAD_MGM_ASSETS(sol::stack_object mgmFilename)
	{
		auto retval = (bool)ANIMSCENE::_LOAD_MGM_ASSETS(mgmFilename.is<const char*>() ? mgmFilename.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_ANIMSCENE__CREATE_MGM_SYSTEM(sol::stack_object mgmFilename)
	{
		auto retval = ANIMSCENE::_CREATE_MGM_SYSTEM(mgmFilename.is<const char*>() ? mgmFilename.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__DELETE_MGM_SYSTEM(int mgmHandle)
	{
		ANIMSCENE::_DELETE_MGM_SYSTEM(mgmHandle);
	}

	static void LUA_NATIVE_ANIMSCENE__0xB1A196BAFE650402(int mgmHandle, Ped ped)
	{
		ANIMSCENE::_0xB1A196BAFE650402(mgmHandle, ped);
	}

	static void LUA_NATIVE_ANIMSCENE__0xAE6DE22DE0ED4554(int mgmHandle, Ped ped)
	{
		ANIMSCENE::_0xAE6DE22DE0ED4554(mgmHandle, ped);
	}

	static bool LUA_NATIVE_ANIMSCENE__0x61B2AAEF645DDAF0(int mgmEventHandle, sol::stack_object p1, int seatId, int p3, bool p4)
	{
		auto retval = (bool)ANIMSCENE::_0x61B2AAEF645DDAF0(mgmEventHandle, p1.is<const char*>() ? p1.as<const char*>() : nullptr, seatId, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__SET_MGM_EVENT(int mgmEventHandle, sol::stack_object p1, Any seatId, int p3, float p4)
	{
		ANIMSCENE::_SET_MGM_EVENT(mgmEventHandle, p1.is<const char*>() ? p1.as<const char*>() : nullptr, seatId, p3, p4);
	}

	static void LUA_NATIVE_ANIMSCENE__0x3641FCD53E59B335(int mgmHandle, Ped ped, sol::stack_object secondaryVoiceString)
	{
		ANIMSCENE::_0x3641FCD53E59B335(mgmHandle, ped, secondaryVoiceString.is<const char*>() ? secondaryVoiceString.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_ANIMSCENE__SET_BREAKOUT_ARCHETYPE(Ped ped, sol::stack_object archetype)
	{
		ANIMSCENE::_SET_BREAKOUT_ARCHETYPE(ped, archetype.is<const char*>() ? archetype.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_ANIMSCENE__CLEAR_BREAKOUT_ARCHETYPE(Ped ped)
	{
		ANIMSCENE::_CLEAR_BREAKOUT_ARCHETYPE(ped);
	}

	static bool LUA_NATIVE_ANIMSCENE__0x3B393716C3FD8237(Ped ped)
	{
		auto retval = (bool)ANIMSCENE::_0x3B393716C3FD8237(ped);
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__0xE12D7B4B959644CD()
	{
		ANIMSCENE::_0xE12D7B4B959644CD();
	}

	static void LUA_NATIVE_ANIMSCENE__0xC1193521E3B9FADD(Entity entity, bool p1)
	{
		ANIMSCENE::_0xC1193521E3B9FADD(entity, p1);
	}

	static void LUA_NATIVE_ANIMSCENE__REQUEST_PHOTO_MODE_FREEZE()
	{
		ANIMSCENE::_REQUEST_PHOTO_MODE_FREEZE();
	}

	static void LUA_NATIVE_ANIMSCENE__REQUEST_PHOTO_MODE_DEFREEZE()
	{
		ANIMSCENE::_REQUEST_PHOTO_MODE_DEFREEZE();
	}

	static bool LUA_NATIVE_ANIMSCENE__0x2DB524750DC41ED4()
	{
		auto retval = (bool)ANIMSCENE::_0x2DB524750DC41ED4();
		return retval;
	}

	static bool LUA_NATIVE_ANIMSCENE__0xEA41D44A8D42057B()
	{
		auto retval = (bool)ANIMSCENE::_0xEA41D44A8D42057B();
		return retval;
	}

	static void LUA_NATIVE_ANIMSCENE__PAUSE_SCRIPT_THREADS(bool toggle)
	{
		ANIMSCENE::_PAUSE_SCRIPT_THREADS(toggle);
	}

	static void LUA_NATIVE_ANIMSCENE__0xCDCD7B2D49AEE73A(bool p0)
	{
		ANIMSCENE::_0xCDCD7B2D49AEE73A(p0);
	}

	static bool LUA_NATIVE_ANIMSCENE_WAS_ANIM_SCENE_SKIPPED(AnimScene animScene)
	{
		auto retval = (bool)ANIMSCENE::WAS_ANIM_SCENE_SKIPPED(animScene);
		return retval;
	}

	void RegisterNatives_ANIMSCENE(sol::state& L)
	{
		auto ANIMSCENE = L["ANIMSCENE"].get_or_create<sol::table>();
		ANIMSCENE.set_function("_CREATE_ANIM_SCENE", LUA_NATIVE_ANIMSCENE__CREATE_ANIM_SCENE);
		ANIMSCENE.set_function("_DELETE_ANIM_SCENE", LUA_NATIVE_ANIMSCENE__DELETE_ANIM_SCENE);
		ANIMSCENE.set_function("TRIGGER_ANIM_SCENE_SKIP", LUA_NATIVE_ANIMSCENE_TRIGGER_ANIM_SCENE_SKIP);
		ANIMSCENE.set_function("_0x4B85B3CF91972222", LUA_NATIVE_ANIMSCENE__0x4B85B3CF91972222);
		ANIMSCENE.set_function("_CLEAR_ANIM_SCENE_WAS_SKIPPED", LUA_NATIVE_ANIMSCENE__CLEAR_ANIM_SCENE_WAS_SKIPPED);
		ANIMSCENE.set_function("DOES_ANIM_SCENE_EXIST", LUA_NATIVE_ANIMSCENE_DOES_ANIM_SCENE_EXIST);
		ANIMSCENE.set_function("_DOES_ENTITY_WITH_ID_EXIST_IN_ANIM_SCENE", LUA_NATIVE_ANIMSCENE__DOES_ENTITY_WITH_ID_EXIST_IN_ANIM_SCENE);
		ANIMSCENE.set_function("_DOES_ANIM_SCENE_OWNERSHIP_OF_ENTITY_EXIST", LUA_NATIVE_ANIMSCENE__DOES_ANIM_SCENE_OWNERSHIP_OF_ENTITY_EXIST);
		ANIMSCENE.set_function("LOAD_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_LOAD_ANIM_SCENE);
		ANIMSCENE.set_function("IS_ANIM_SCENE_LOADED", LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_LOADED);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_LOADING", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_LOADING);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_METADATA_ASSET_IN_RANGE_LOADING", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_METADATA_ASSET_IN_RANGE_LOADING);
		ANIMSCENE.set_function("IS_ANIM_SCENE_METADATA_LOADED", LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_METADATA_LOADED);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_PLAYBACK_LIST_PHASE_AUDIO_LOAD_STRESS", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_PLAYBACK_LIST_PHASE_AUDIO_LOAD_STRESS);
		ANIMSCENE.set_function("START_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_START_ANIM_SCENE);
		ANIMSCENE.set_function("RESET_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_RESET_ANIM_SCENE);
		ANIMSCENE.set_function("ABORT_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_ABORT_ANIM_SCENE);
		ANIMSCENE.set_function("RESUME_ANIM_SCENE_FROM_LAST_CHECKPOINT", LUA_NATIVE_ANIMSCENE_RESUME_ANIM_SCENE_FROM_LAST_CHECKPOINT);
		ANIMSCENE.set_function("IS_ANIM_SCENE_RUNNING", LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_RUNNING);
		ANIMSCENE.set_function("IS_ANIM_SCENE_FINISHED", LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_FINISHED);
		ANIMSCENE.set_function("IS_ANIM_SCENE_EXITING_THIS_FRAME", LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_EXITING_THIS_FRAME);
		ANIMSCENE.set_function("HAS_ANIM_SCENE_EXITED", LUA_NATIVE_ANIMSCENE_HAS_ANIM_SCENE_EXITED);
		ANIMSCENE.set_function("_0x73616E64696C132E", LUA_NATIVE_ANIMSCENE__0x73616E64696C132E);
		ANIMSCENE.set_function("IS_ANIM_SCENE_IN_SECTION", LUA_NATIVE_ANIMSCENE_IS_ANIM_SCENE_IN_SECTION);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_SKIPPABLE", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_SKIPPABLE);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_ABORTED", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_ABORTED);
		ANIMSCENE.set_function("_0xD70C7A30412F8FA0", LUA_NATIVE_ANIMSCENE__0xD70C7A30412F8FA0);
		ANIMSCENE.set_function("_0x9AAE3C1148A09BCA", LUA_NATIVE_ANIMSCENE__0x9AAE3C1148A09BCA);
		ANIMSCENE.set_function("_0xA96619FE85159ED2", LUA_NATIVE_ANIMSCENE__0xA96619FE85159ED2);
		ANIMSCENE.set_function("FADE_ANIM_SCENE_AUDIO_IN", LUA_NATIVE_ANIMSCENE_FADE_ANIM_SCENE_AUDIO_IN);
		ANIMSCENE.set_function("FADE_ANIM_SCENE_AUDIO_OUT", LUA_NATIVE_ANIMSCENE_FADE_ANIM_SCENE_AUDIO_OUT);
		ANIMSCENE.set_function("BLOCK_ANIM_SCENE_FADING_NEXT_FRAME", LUA_NATIVE_ANIMSCENE_BLOCK_ANIM_SCENE_FADING_NEXT_FRAME);
		ANIMSCENE.set_function("SET_ANIM_SCENE_ORIGIN", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_ORIGIN);
		ANIMSCENE.set_function("GET_ANIM_SCENE_ORIGIN", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_ORIGIN);
		ANIMSCENE.set_function("SET_ANIM_SCENE_PAUSED", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_PAUSED);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_PAUSED", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PAUSED);
		ANIMSCENE.set_function("SET_ANIM_SCENE_RATE", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_RATE);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_RATE", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_RATE);
		ANIMSCENE.set_function("GET_ANIM_SCENE_PHASE", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_PHASE);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_TIME", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_TIME);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_DURATION", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_DURATION);
		ANIMSCENE.set_function("SET_ANIM_SCENE_ENTITY", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_ENTITY);
		ANIMSCENE.set_function("REMOVE_ANIM_SCENE_ENTITY", LUA_NATIVE_ANIMSCENE_REMOVE_ANIM_SCENE_ENTITY);
		ANIMSCENE.set_function("IS_ENTITY_EXITING_ANIM_SCENE_THIS_FRAME", LUA_NATIVE_ANIMSCENE_IS_ENTITY_EXITING_ANIM_SCENE_THIS_FRAME);
		ANIMSCENE.set_function("COULD_ANIM_SCENE_ENTITY_REACH_EXIT_NEXT_FRAME", LUA_NATIVE_ANIMSCENE_COULD_ANIM_SCENE_ENTITY_REACH_EXIT_NEXT_FRAME);
		ANIMSCENE.set_function("HAS_ENTITY_EXITED_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_HAS_ENTITY_EXITED_ANIM_SCENE);
		ANIMSCENE.set_function("_HAS_ENTITY_ENTERED_ANIM_SCENE", LUA_NATIVE_ANIMSCENE__HAS_ENTITY_ENTERED_ANIM_SCENE);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_PED", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_PED);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_OBJECT", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_OBJECT);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_VEHICLE", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_VEHICLE);
		ANIMSCENE.set_function("SET_ANIM_SCENE_BOOL", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_BOOL);
		ANIMSCENE.set_function("GET_ANIM_SCENE_BOOL", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_BOOL);
		ANIMSCENE.set_function("SET_ANIM_SCENE_FLOAT", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_FLOAT);
		ANIMSCENE.set_function("GET_ANIM_SCENE_FLOAT", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_FLOAT);
		ANIMSCENE.set_function("SET_ANIM_SCENE_INT", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_INT);
		ANIMSCENE.set_function("GET_ANIM_SCENE_INT", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_INT);
		ANIMSCENE.set_function("GET_ANIM_SCENE_ENTITY_LOCATION_DATA", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_ENTITY_LOCATION_DATA);
		ANIMSCENE.set_function("IS_ENTITY_PLAYING_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_IS_ENTITY_PLAYING_ANIM_SCENE);
		ANIMSCENE.set_function("ATTACH_ANIM_SCENE_TO_ENTITY", LUA_NATIVE_ANIMSCENE_ATTACH_ANIM_SCENE_TO_ENTITY);
		ANIMSCENE.set_function("ATTACH_ANIM_SCENE_TO_ENTITY_PRESERVING_LOCATION", LUA_NATIVE_ANIMSCENE_ATTACH_ANIM_SCENE_TO_ENTITY_PRESERVING_LOCATION);
		ANIMSCENE.set_function("DETACH_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_DETACH_ANIM_SCENE);
		ANIMSCENE.set_function("DETACH_ANIM_SCENE_PRESERVING_LOCATION", LUA_NATIVE_ANIMSCENE_DETACH_ANIM_SCENE_PRESERVING_LOCATION);
		ANIMSCENE.set_function("TAKE_OWNERSHIP_OF_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_TAKE_OWNERSHIP_OF_ANIM_SCENE);
		ANIMSCENE.set_function("CHECK_OWNERSHIP_OF_ANIM_SCENE", LUA_NATIVE_ANIMSCENE_CHECK_OWNERSHIP_OF_ANIM_SCENE);
		ANIMSCENE.set_function("SET_ANIM_SCENE_PLAYBACK_LIST", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_PLAYBACK_LIST);
		ANIMSCENE.set_function("_0x1C5D33A4293E6DDE", LUA_NATIVE_ANIMSCENE__0x1C5D33A4293E6DDE);
		ANIMSCENE.set_function("_DOES_ANIM_SCENE_PLAY_LIST_EXIST", LUA_NATIVE_ANIMSCENE__DOES_ANIM_SCENE_PLAY_LIST_EXIST);
		ANIMSCENE.set_function("SET_ANIM_SCENE_PLAY_LIST", LUA_NATIVE_ANIMSCENE_SET_ANIM_SCENE_PLAY_LIST);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_ACTIVE", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_ACTIVE);
		ANIMSCENE.set_function("REQUEST_ANIM_SCENE_PLAY_LIST", LUA_NATIVE_ANIMSCENE_REQUEST_ANIM_SCENE_PLAY_LIST);
		ANIMSCENE.set_function("_RELEASE_ANIM_SCENE_PLAY_LIST", LUA_NATIVE_ANIMSCENE__RELEASE_ANIM_SCENE_PLAY_LIST);
		ANIMSCENE.set_function("_GET_ANIM_SCENE_DICT", LUA_NATIVE_ANIMSCENE__GET_ANIM_SCENE_DICT);
		ANIMSCENE.set_function("_0x1407F5115FB9583E", LUA_NATIVE_ANIMSCENE__0x1407F5115FB9583E);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADED", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADED);
		ANIMSCENE.set_function("_IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADING", LUA_NATIVE_ANIMSCENE__IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADING);
		ANIMSCENE.set_function("_0x1AD896BF43619551", LUA_NATIVE_ANIMSCENE__0x1AD896BF43619551);
		ANIMSCENE.set_function("GET_ANIM_SCENE_CURRENT_ACTIVE_CAMERA_COUNT", LUA_NATIVE_ANIMSCENE_GET_ANIM_SCENE_CURRENT_ACTIVE_CAMERA_COUNT);
		ANIMSCENE.set_function("_0x5D7BFDA2290B4E39", LUA_NATIVE_ANIMSCENE__0x5D7BFDA2290B4E39);
		ANIMSCENE.set_function("_IS_MGM_SYSTEM_LOADED", LUA_NATIVE_ANIMSCENE__IS_MGM_SYSTEM_LOADED);
		ANIMSCENE.set_function("_LOAD_MGM_ASSETS", LUA_NATIVE_ANIMSCENE__LOAD_MGM_ASSETS);
		ANIMSCENE.set_function("_CREATE_MGM_SYSTEM", LUA_NATIVE_ANIMSCENE__CREATE_MGM_SYSTEM);
		ANIMSCENE.set_function("_DELETE_MGM_SYSTEM", LUA_NATIVE_ANIMSCENE__DELETE_MGM_SYSTEM);
		ANIMSCENE.set_function("_0xB1A196BAFE650402", LUA_NATIVE_ANIMSCENE__0xB1A196BAFE650402);
		ANIMSCENE.set_function("_0xAE6DE22DE0ED4554", LUA_NATIVE_ANIMSCENE__0xAE6DE22DE0ED4554);
		ANIMSCENE.set_function("_0x61B2AAEF645DDAF0", LUA_NATIVE_ANIMSCENE__0x61B2AAEF645DDAF0);
		ANIMSCENE.set_function("_SET_MGM_EVENT", LUA_NATIVE_ANIMSCENE__SET_MGM_EVENT);
		ANIMSCENE.set_function("_0x3641FCD53E59B335", LUA_NATIVE_ANIMSCENE__0x3641FCD53E59B335);
		ANIMSCENE.set_function("_SET_BREAKOUT_ARCHETYPE", LUA_NATIVE_ANIMSCENE__SET_BREAKOUT_ARCHETYPE);
		ANIMSCENE.set_function("_CLEAR_BREAKOUT_ARCHETYPE", LUA_NATIVE_ANIMSCENE__CLEAR_BREAKOUT_ARCHETYPE);
		ANIMSCENE.set_function("_0x3B393716C3FD8237", LUA_NATIVE_ANIMSCENE__0x3B393716C3FD8237);
		ANIMSCENE.set_function("_0xE12D7B4B959644CD", LUA_NATIVE_ANIMSCENE__0xE12D7B4B959644CD);
		ANIMSCENE.set_function("_0xC1193521E3B9FADD", LUA_NATIVE_ANIMSCENE__0xC1193521E3B9FADD);
		ANIMSCENE.set_function("_REQUEST_PHOTO_MODE_FREEZE", LUA_NATIVE_ANIMSCENE__REQUEST_PHOTO_MODE_FREEZE);
		ANIMSCENE.set_function("_REQUEST_PHOTO_MODE_DEFREEZE", LUA_NATIVE_ANIMSCENE__REQUEST_PHOTO_MODE_DEFREEZE);
		ANIMSCENE.set_function("_0x2DB524750DC41ED4", LUA_NATIVE_ANIMSCENE__0x2DB524750DC41ED4);
		ANIMSCENE.set_function("_0xEA41D44A8D42057B", LUA_NATIVE_ANIMSCENE__0xEA41D44A8D42057B);
		ANIMSCENE.set_function("_PAUSE_SCRIPT_THREADS", LUA_NATIVE_ANIMSCENE__PAUSE_SCRIPT_THREADS);
		ANIMSCENE.set_function("_0xCDCD7B2D49AEE73A", LUA_NATIVE_ANIMSCENE__0xCDCD7B2D49AEE73A);
		ANIMSCENE.set_function("WAS_ANIM_SCENE_SKIPPED", LUA_NATIVE_ANIMSCENE_WAS_ANIM_SCENE_SKIPPED);
	}
}
