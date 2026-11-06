#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_GRAPHICS_FREE_MEMORY_FOR_MISSION_CREATOR_PHOTO()
	{
		GRAPHICS::FREE_MEMORY_FOR_MISSION_CREATOR_PHOTO();
	}

	static bool LUA_NATIVE_GRAPHICS_LOAD_MISSION_CREATOR_PHOTO(sol::stack_object szContentID, int nFileID, int nFileVersion, int nLanguage)
	{
		auto retval = (bool)GRAPHICS::LOAD_MISSION_CREATOR_PHOTO(szContentID.is<const char*>() ? szContentID.as<const char*>() : nullptr, nFileID, nFileVersion, nLanguage);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_GET_STATUS_OF_LOAD_MISSION_CREATOR_PHOTO(sol::stack_object szContentID)
	{
		auto retval = GRAPHICS::GET_STATUS_OF_LOAD_MISSION_CREATOR_PHOTO(szContentID.is<const char*>() ? szContentID.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_BEGIN_TAKE_HIGH_QUALITY_PHOTO()
	{
		auto retval = (bool)GRAPHICS::BEGIN_TAKE_HIGH_QUALITY_PHOTO();
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_GET_STATUS_OF_TAKE_HIGH_QUALITY_PHOTO()
	{
		auto retval = GRAPHICS::GET_STATUS_OF_TAKE_HIGH_QUALITY_PHOTO();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_FREE_MEMORY_FOR_HIGH_QUALITY_PHOTO()
	{
		GRAPHICS::FREE_MEMORY_FOR_HIGH_QUALITY_PHOTO();
	}

	static void LUA_NATIVE_GRAPHICS__SET_PHOTO_SELF_STAT(bool p0)
	{
		GRAPHICS::_SET_PHOTO_SELF_STAT(p0);
	}

	static void LUA_NATIVE_GRAPHICS__SET_PHOTO_STUDIO_STAT(int p0)
	{
		GRAPHICS::_SET_PHOTO_STUDIO_STAT(p0);
	}

	static void LUA_NATIVE_GRAPHICS__SET_POSSE_ID_FOR_PHOTO(Any posseId)
	{
		GRAPHICS::_SET_POSSE_ID_FOR_PHOTO(posseId);
	}

	static void LUA_NATIVE_GRAPHICS__0x9F6D859C80708B26(bool p0, bool p1)
	{
		GRAPHICS::_0x9F6D859C80708B26(p0, p1);
	}

	static bool LUA_NATIVE_GRAPHICS_IS_PHOTO_FRAME()
	{
		auto retval = (bool)GRAPHICS::IS_PHOTO_FRAME();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__SET_PHOTO_IN_PHOTOMODE_STAT(bool p0)
	{
		GRAPHICS::_SET_PHOTO_IN_PHOTOMODE_STAT(p0);
	}

	static void LUA_NATIVE_GRAPHICS__SET_PHOTO_OVERLAY_EFFECT_STAT(int p0)
	{
		GRAPHICS::_SET_PHOTO_OVERLAY_EFFECT_STAT(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x0D5B19C34068FEE7(Any p0)
	{
		GRAPHICS::_0x0D5B19C34068FEE7(p0);
	}

	static void LUA_NATIVE_GRAPHICS__SET_PLAYER_APPEAR_IN_PHOTO(Player player)
	{
		GRAPHICS::_SET_PLAYER_APPEAR_IN_PHOTO(player);
	}

	static void LUA_NATIVE_GRAPHICS__SET_REGION_PHOTO_TAKEN_STAT(sol::stack_object p0)
	{
		GRAPHICS::_SET_REGION_PHOTO_TAKEN_STAT(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__SET_DISTRICT_PHOTO_TAKEN_STAT(sol::stack_object p0)
	{
		GRAPHICS::_SET_DISTRICT_PHOTO_TAKEN_STAT(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__SET_STATE_PHOTO_TAKEN_STAT(sol::stack_object p0)
	{
		GRAPHICS::_SET_STATE_PHOTO_TAKEN_STAT(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_GRAPHICS_SAVE_HIGH_QUALITY_PHOTO(int PhotoSlotIndex)
	{
		auto retval = (bool)GRAPHICS::SAVE_HIGH_QUALITY_PHOTO(PhotoSlotIndex);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_GET_STATUS_OF_SAVE_HIGH_QUALITY_PHOTO()
	{
		auto retval = GRAPHICS::GET_STATUS_OF_SAVE_HIGH_QUALITY_PHOTO();
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_BEGIN_CREATE_LOW_QUALITY_COPY_OF_PHOTO(int qualitySetting)
	{
		auto retval = (bool)GRAPHICS::BEGIN_CREATE_LOW_QUALITY_COPY_OF_PHOTO(qualitySetting);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_GET_STATUS_OF_CREATE_LOW_QUALITY_COPY_OF_PHOTO(int qualitySetting)
	{
		auto retval = GRAPHICS::GET_STATUS_OF_CREATE_LOW_QUALITY_COPY_OF_PHOTO(qualitySetting);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_FREE_MEMORY_FOR_LOW_QUALITY_PHOTO()
	{
		GRAPHICS::FREE_MEMORY_FOR_LOW_QUALITY_PHOTO();
	}

	static void LUA_NATIVE_GRAPHICS_DRAW_LOW_QUALITY_PHOTO_TO_PHONE(bool bDraw, int PhotoRotation)
	{
		GRAPHICS::DRAW_LOW_QUALITY_PHOTO_TO_PHONE(bDraw, PhotoRotation);
	}

	static int LUA_NATIVE_GRAPHICS__GET_MAX_NUMBER_OF_LOCAL_PHOTOS()
	{
		auto retval = GRAPHICS::_GET_MAX_NUMBER_OF_LOCAL_PHOTOS();
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS__GET_CURRENT_NUMBER_OF_LOCAL_PHOTOS()
	{
		auto retval = GRAPHICS::_GET_CURRENT_NUMBER_OF_LOCAL_PHOTOS();
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_QUEUE_OPERATION_TO_CREATE_SORTED_LIST_OF_PHOTOS()
	{
		auto retval = (bool)GRAPHICS::QUEUE_OPERATION_TO_CREATE_SORTED_LIST_OF_PHOTOS();
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_GET_STATUS_OF_SORTED_LIST_OPERATION()
	{
		auto retval = GRAPHICS::GET_STATUS_OF_SORTED_LIST_OPERATION();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_DRAW_LIGHT_WITH_RANGE(float VecCoorsX, float VecCoorsY, float VecCoorsZ, int R, int G, int B, float Range, float Intensity)
	{
		GRAPHICS::DRAW_LIGHT_WITH_RANGE(VecCoorsX, VecCoorsY, VecCoorsZ, R, G, B, Range, Intensity);
	}

	static void LUA_NATIVE_GRAPHICS_UPDATE_LIGHTS_ON_ENTITY(Entity EntityIndex)
	{
		GRAPHICS::UPDATE_LIGHTS_ON_ENTITY(EntityIndex);
	}

	static void LUA_NATIVE_GRAPHICS__SET_LIGHTS_COLOR_FOR_ENTITY(Entity entity, int red, int green, int blue)
	{
		GRAPHICS::_SET_LIGHTS_COLOR_FOR_ENTITY(entity, red, green, blue);
	}

	static void LUA_NATIVE_GRAPHICS__SET_LIGHTS_INTENSITY_FOR_ENTITY(Entity entity, float intensity)
	{
		GRAPHICS::_SET_LIGHTS_INTENSITY_FOR_ENTITY(entity, intensity);
	}

	static void LUA_NATIVE_GRAPHICS__SET_LIGHTS_TYPE_FOR_ENTITY(Entity entity, int type)
	{
		GRAPHICS::_SET_LIGHTS_TYPE_FOR_ENTITY(entity, type);
	}

	static void LUA_NATIVE_GRAPHICS__DRAW_MARKER(Hash type, float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, int red, int green, int blue, int alpha, bool bobUpAndDown, bool faceCamera, int p19, bool rotate, sol::stack_object textureDict, sol::stack_object textureName, bool drawOnEnts)
	{
		GRAPHICS::_DRAW_MARKER(type, posX, posY, posZ, dirX, dirY, dirZ, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, red, green, blue, alpha, bobUpAndDown, faceCamera, p19, rotate, textureDict.is<const char*>() ? textureDict.as<const char*>() : nullptr, textureName.is<const char*>() ? textureName.as<const char*>() : nullptr, drawOnEnts);
	}

	static int LUA_NATIVE_GRAPHICS_CREATE_CHECKPOINT_WITH_NAMEHASH(Hash typeHash, float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2, float radius, int red, int green, int blue, int alpha, int reserved)
	{
		auto retval = GRAPHICS::CREATE_CHECKPOINT_WITH_NAMEHASH(typeHash, posX1, posY1, posZ1, posX2, posY2, posZ2, radius, red, green, blue, alpha, reserved);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS__DOES_CHECKPOINT_HAVE_FX(int checkpoint)
	{
		auto retval = (bool)GRAPHICS::_DOES_CHECKPOINT_HAVE_FX(checkpoint);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_CHECKPOINT_RGBA(int UniqueCheckpointIndex, int colR, int colG, int colB, int colA)
	{
		GRAPHICS::SET_CHECKPOINT_RGBA(UniqueCheckpointIndex, colR, colG, colB, colA);
	}

	static void LUA_NATIVE_GRAPHICS_SET_CHECKPOINT_RGBA2(int UniqueCheckpointIndex, int colR, int colG, int colB, int colA)
	{
		GRAPHICS::SET_CHECKPOINT_RGBA2(UniqueCheckpointIndex, colR, colG, colB, colA);
	}

	static void LUA_NATIVE_GRAPHICS__0xCC3B787E73E64160(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		GRAPHICS::_0xCC3B787E73E64160(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_GRAPHICS__0x171C18E994C1A395(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		GRAPHICS::_0x171C18E994C1A395(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_GRAPHICS_DELETE_CHECKPOINT(int UniqueCheckpointIndex)
	{
		GRAPHICS::DELETE_CHECKPOINT(UniqueCheckpointIndex);
	}

	static void LUA_NATIVE_GRAPHICS_DRAW_RECT(float CentreX, float CentreY, float Width, float Height, int R, int G, int B, int A, bool bStereo, bool p9)
	{
		GRAPHICS::DRAW_RECT(CentreX, CentreY, Width, Height, R, G, B, A, bStereo, p9);
	}

	static void LUA_NATIVE_GRAPHICS_SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU(bool bValue)
	{
		GRAPHICS::SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU(bValue);
	}

	static void LUA_NATIVE_GRAPHICS_SET_SCRIPT_GFX_DRAW_ORDER(int iDrawOrder)
	{
		GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(iDrawOrder);
	}

	static void LUA_NATIVE_GRAPHICS_DRAW_SPRITE(sol::stack_object pTextureDictionaryName, sol::stack_object pTextureName, float CentreX, float CentreY, float Width, float Height, float Rotation, int R, int G, int B, int A, bool DoStereorize)
	{
		GRAPHICS::DRAW_SPRITE(pTextureDictionaryName.is<const char*>() ? pTextureDictionaryName.as<const char*>() : nullptr, pTextureName.is<const char*>() ? pTextureName.as<const char*>() : nullptr, CentreX, CentreY, Width, Height, Rotation, R, G, B, A, DoStereorize);
	}

	static void LUA_NATIVE_GRAPHICS_ATTACH_TV_AUDIO_TO_ENTITY(Entity entity)
	{
		GRAPHICS::ATTACH_TV_AUDIO_TO_ENTITY(entity);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TV_AUDIO_FRONTEND(bool frontend)
	{
		GRAPHICS::SET_TV_AUDIO_FRONTEND(frontend);
	}

	static std::tuple<int, int> LUA_NATIVE_GRAPHICS_GET_SCREEN_RESOLUTION(int X, int Y)
	{
		std::tuple<int, int> return_values;
		GRAPHICS::GET_SCREEN_RESOLUTION(&X, &Y);
		std::get<0>(return_values) = X;
		std::get<1>(return_values) = Y;

		return return_values;
	}

	static void LUA_NATIVE_GRAPHICS__0xA04EF43030593ABC(Any p0, Any p1)
	{
		GRAPHICS::_0xA04EF43030593ABC(p0, p1);
	}

	static void LUA_NATIVE_GRAPHICS__0xA21AF60C9F99CCC5()
	{
		GRAPHICS::_0xA21AF60C9F99CCC5();
	}

	static Any LUA_NATIVE_GRAPHICS__0xC28F62AC9774FC1B()
	{
		auto retval = GRAPHICS::_0xC28F62AC9774FC1B();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0xEB48CE48EEC41FD4(Any p0)
	{
		GRAPHICS::_0xEB48CE48EEC41FD4(p0);
	}

	static std::tuple<bool, float, float> LUA_NATIVE_GRAPHICS_GET_SCREEN_COORD_FROM_WORLD_COORD(float vWorldPosX, float vWorldPosY, float vWorldPosZ, float fXpos, float Ypos)
	{
		std::tuple<bool, float, float> return_values;
		std::get<0>(return_values) = (bool)GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(vWorldPosX, vWorldPosY, vWorldPosZ, &fXpos, &Ypos);
		std::get<1>(return_values) = fXpos;
		std::get<2>(return_values) = Ypos;

		return return_values;
	}

	static bool LUA_NATIVE_GRAPHICS__IS_TEXTURE_IN_DICT(Hash txdHash, Hash dict)
	{
		auto retval = (bool)GRAPHICS::_IS_TEXTURE_IN_DICT(txdHash, dict);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_ARTIFICIAL_LIGHTS_STATE(bool bState)
	{
		GRAPHICS::SET_ARTIFICIAL_LIGHTS_STATE(bState);
	}

	static void LUA_NATIVE_GRAPHICS_DISABLE_HDTEX_THIS_FRAME()
	{
		GRAPHICS::DISABLE_HDTEX_THIS_FRAME();
	}

	static void LUA_NATIVE_GRAPHICS__0x1A9F09AB458D49C6(bool p0)
	{
		GRAPHICS::_0x1A9F09AB458D49C6(p0);
	}

	static int LUA_NATIVE_GRAPHICS_CREATE_TRACKED_POINT()
	{
		auto retval = GRAPHICS::CREATE_TRACKED_POINT();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_TRACKED_POINT_INFO(int queryIdx, float centerX, float centerY, float centerZ, float radius)
	{
		GRAPHICS::SET_TRACKED_POINT_INFO(queryIdx, centerX, centerY, centerZ, radius);
	}

	static bool LUA_NATIVE_GRAPHICS_IS_TRACKED_POINT_VISIBLE(int queryIdx)
	{
		auto retval = (bool)GRAPHICS::IS_TRACKED_POINT_VISIBLE(queryIdx);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS__0xDFE332A5DA6FE7C9(int iTrackedPoint)
	{
		auto retval = GRAPHICS::_0xDFE332A5DA6FE7C9(iTrackedPoint);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_DESTROY_TRACKED_POINT(int queryIdx)
	{
		GRAPHICS::DESTROY_TRACKED_POINT(queryIdx);
	}

	static bool LUA_NATIVE_GRAPHICS__IS_TRACKED_POINT_VALID(int point)
	{
		auto retval = (bool)GRAPHICS::_IS_TRACKED_POINT_VALID(point);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_SET_GRASS_CULL_SPHERE(float centerX, float centerY, float centerZ, float radius, int p4)
	{
		auto retval = GRAPHICS::SET_GRASS_CULL_SPHERE(centerX, centerY, centerZ, radius, p4);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_GRASS_CULL_SPHERE(int handle)
	{
		GRAPHICS::REMOVE_GRASS_CULL_SPHERE(handle);
	}

	static int LUA_NATIVE_GRAPHICS__ADD_VEG_MODIFIER_ZONE(Volume volume, int p1, int flags, int p3)
	{
		auto retval = GRAPHICS::_ADD_VEG_MODIFIER_ZONE(volume, p1, flags, p3);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_ADD_VEG_MODIFIER_SPHERE(float x, float y, float z, float radius, int modType, int flags, int p6)
	{
		auto retval = GRAPHICS::ADD_VEG_MODIFIER_SPHERE(x, y, z, radius, modType, flags, p6);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_VEG_MODIFIER_SPHERE(int vegModifierHandle, int p1)
	{
		GRAPHICS::REMOVE_VEG_MODIFIER_SPHERE(vegModifierHandle, p1);
	}

	static void LUA_NATIVE_GRAPHICS__ENABLE_STATIC_VEG_MODIFIER(Hash p0)
	{
		GRAPHICS::_ENABLE_STATIC_VEG_MODIFIER(p0);
	}

	static void LUA_NATIVE_GRAPHICS__DISABLE_STATIC_VEG_MODIFIER(Hash p0)
	{
		GRAPHICS::_DISABLE_STATIC_VEG_MODIFIER(p0);
	}

	static bool LUA_NATIVE_GRAPHICS__IS_STATIC_VEG_MODIFIER_ENABLED(Hash p0)
	{
		auto retval = (bool)GRAPHICS::_IS_STATIC_VEG_MODIFIER_ENABLED(p0);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0xEC3F7F24EEEB3BA3()
	{
		GRAPHICS::_0xEC3F7F24EEEB3BA3();
	}

	static void LUA_NATIVE_GRAPHICS__0x9F158A49B0D84C3C(Any p0)
	{
		GRAPHICS::_0x9F158A49B0D84C3C(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x910E260AEAD855DE()
	{
		GRAPHICS::_0x910E260AEAD855DE();
	}

	static bool LUA_NATIVE_GRAPHICS__CREATE_SWATCH_TEXTURE_DICT(int slots)
	{
		auto retval = (bool)GRAPHICS::_CREATE_SWATCH_TEXTURE_DICT(slots);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__DESTROY_SWATCH_TEXTURE_DICT()
	{
		GRAPHICS::_DESTROY_SWATCH_TEXTURE_DICT();
	}

	static void LUA_NATIVE_GRAPHICS__GENERATE_SWATCH_TEXTURE_DIRECTLY(int slot, Any p1)
	{
		GRAPHICS::_GENERATE_SWATCH_TEXTURE_DIRECTLY(slot, p1);
	}

	static void LUA_NATIVE_GRAPHICS__GENERATE_SWATCH_TEXTURE(int slotId, Hash componentHash, int metapedType, bool p3)
	{
		GRAPHICS::_GENERATE_SWATCH_TEXTURE(slotId, componentHash, metapedType, p3);
	}

	static void LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_SET_CASCADE_BOUNDS(int cascadeIndex, bool bEnabled, float x, float y, float z, float radiusScale, bool interpolateToDisabled, float interpolationTime)
	{
		GRAPHICS::CASCADE_SHADOWS_SET_CASCADE_BOUNDS(cascadeIndex, bEnabled, x, y, z, radiusScale, interpolateToDisabled, interpolationTime);
	}

	static void LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_ENABLE_ENTITY_TRACKER(bool scale)
	{
		GRAPHICS::CASCADE_SHADOWS_ENABLE_ENTITY_TRACKER(scale);
	}

	static void LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_SET_SHADOW_SAMPLE_TYPE(sol::stack_object typeStr)
	{
		GRAPHICS::CASCADE_SHADOWS_SET_SHADOW_SAMPLE_TYPE(typeStr.is<const char*>() ? typeStr.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_CLEAR_SHADOW_SAMPLE_TYPE()
	{
		GRAPHICS::CASCADE_SHADOWS_CLEAR_SHADOW_SAMPLE_TYPE();
	}

	static void LUA_NATIVE_GRAPHICS__0x503941F65DBA24EC(Any p0)
	{
		GRAPHICS::_0x503941F65DBA24EC(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x815653A42C5ABE76()
	{
		GRAPHICS::_0x815653A42C5ABE76();
	}

	static void LUA_NATIVE_GRAPHICS__0xFF8018C778349234(Any p0)
	{
		GRAPHICS::_0xFF8018C778349234(p0);
	}

	static void LUA_NATIVE_GRAPHICS_RESET_ADAPTATION(int numFrames)
	{
		GRAPHICS::RESET_ADAPTATION(numFrames);
	}

	static void LUA_NATIVE_GRAPHICS_TOGGLE_PAUSED_RENDERPHASES(bool on)
	{
		GRAPHICS::TOGGLE_PAUSED_RENDERPHASES(on);
	}

	static bool LUA_NATIVE_GRAPHICS_GET_TOGGLE_PAUSED_RENDERPHASES_STATUS()
	{
		auto retval = (bool)GRAPHICS::GET_TOGGLE_PAUSED_RENDERPHASES_STATUS();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_RESET_PAUSED_RENDERPHASES()
	{
		GRAPHICS::RESET_PAUSED_RENDERPHASES();
	}

	static void LUA_NATIVE_GRAPHICS_SET_HIDOF_OVERRIDE(bool enableOverride, bool enableDOF, float dofNearStart, float dofNearEnd, float dofFarStart, float dofFarEnd)
	{
		GRAPHICS::SET_HIDOF_OVERRIDE(enableOverride, enableDOF, dofNearStart, dofNearEnd, dofFarStart, dofFarEnd);
	}

	static void LUA_NATIVE_GRAPHICS__0x21F00E08CBB5F37B(sol::stack_object component)
	{
		GRAPHICS::_0x21F00E08CBB5F37B(component.is<const char*>() ? component.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__0x5AC6E0FA028369DE()
	{
		GRAPHICS::_0x5AC6E0FA028369DE();
	}

	static bool LUA_NATIVE_GRAPHICS__0xEC3D8C228FE553D7(bool p0)
	{
		auto retval = (bool)GRAPHICS::_0xEC3D8C228FE553D7(p0);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0xF5793BB386E1FF9C(Any p0)
	{
		GRAPHICS::_0xF5793BB386E1FF9C(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x5CD6A2CCE5087161(Any p0)
	{
		GRAPHICS::_0x5CD6A2CCE5087161(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0xC8D0611D9A0CF5D3(Any p0)
	{
		GRAPHICS::_0xC8D0611D9A0CF5D3(p0);
	}

	static float LUA_NATIVE_GRAPHICS__GET_PHOTO_MODE_EXPOSURE()
	{
		auto retval = GRAPHICS::_GET_PHOTO_MODE_EXPOSURE();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x62B9F9A1272AED80(Any p0)
	{
		GRAPHICS::_0x62B9F9A1272AED80(p0);
	}

	static float LUA_NATIVE_GRAPHICS__GET_PHOTO_MODE_CONTRAST()
	{
		auto retval = GRAPHICS::_GET_PHOTO_MODE_CONTRAST();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x9229ED770975BD9E()
	{
		GRAPHICS::_0x9229ED770975BD9E();
	}

	static bool LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_NON_LOOPED_AT_COORD(sol::stack_object fxName, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = (bool)GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD(sol::stack_object fxName, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = (bool)GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE(sol::stack_object fxName, Ped pedIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, int boneTag, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = (bool)GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, pedIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneTag, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(sol::stack_object fxName, Entity entityIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = (bool)GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY(sol::stack_object fxName, Entity entityIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = (bool)GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS__START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(sol::stack_object effectName, Ped ped, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, int boneIndex, float scale, bool axisX, bool axisY, bool axisZ)
	{
		auto retval = (bool)GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, ped, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, boneIndex, scale, axisX, axisY, axisZ);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_NON_LOOPED_COLOUR(float colR, float colG, float colB)
	{
		GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(colR, colG, colB);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_NON_LOOPED_ALPHA(float colA)
	{
		GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_ALPHA(colA);
	}

	static void LUA_NATIVE_GRAPHICS__SET_PARTICLE_FX_NON_LOOPED_EMITTER_SCALE(float p0, float p1, float p2)
	{
		GRAPHICS::_SET_PARTICLE_FX_NON_LOOPED_EMITTER_SCALE(p0, p1, p2);
	}

	static int LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_AT_COORD(sol::stack_object fxName, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ, bool localOnly)
	{
		auto retval = GRAPHICS::START_PARTICLE_FX_LOOPED_AT_COORD(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ, localOnly);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_ON_PED_BONE(sol::stack_object fxName, Ped pedIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, int boneTag, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = GRAPHICS::START_PARTICLE_FX_LOOPED_ON_PED_BONE(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, pedIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneTag, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_ON_ENTITY(sol::stack_object fxName, Entity entityIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = GRAPHICS::START_PARTICLE_FX_LOOPED_ON_ENTITY(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(sol::stack_object fxName, Entity entityIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, int boneIndex, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = GRAPHICS::START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneIndex, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY(sol::stack_object fxName, Entity entityIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = GRAPHICS::START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(sol::stack_object fxName, Entity entityIndex, float vecPositionX, float vecPositionY, float vecPositionZ, float vecRotationX, float vecRotationY, float vecRotationZ, int boneIndex, float scale, bool invertAxisX, bool invertAxisY, bool invertAxisZ)
	{
		auto retval = GRAPHICS::START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(fxName.is<const char*>() ? fxName.as<const char*>() : nullptr, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneIndex, scale, invertAxisX, invertAxisY, invertAxisZ);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_STOP_PARTICLE_FX_LOOPED(int ptfxId, bool localOnly)
	{
		GRAPHICS::STOP_PARTICLE_FX_LOOPED(ptfxId, localOnly);
	}

	static bool LUA_NATIVE_GRAPHICS_DOES_PARTICLE_FX_LOOPED_EXIST(int ptfxId)
	{
		auto retval = (bool)GRAPHICS::DOES_PARTICLE_FX_LOOPED_EXIST(ptfxId);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_OFFSETS(int ptfxId, float positionX, float positionY, float positionZ, float vecRotationX, float vecRotationY, float vecRotationZ)
	{
		GRAPHICS::SET_PARTICLE_FX_LOOPED_OFFSETS(ptfxId, positionX, positionY, positionZ, vecRotationX, vecRotationY, vecRotationZ);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_EVOLUTION(int ptfxId, sol::stack_object evoName, float evoVal, bool localOnly)
	{
		GRAPHICS::SET_PARTICLE_FX_LOOPED_EVOLUTION(ptfxId, evoName.is<const char*>() ? evoName.as<const char*>() : nullptr, evoVal, localOnly);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_COLOUR(int ptfxId, float colR, float colG, float colB, bool localOnly)
	{
		GRAPHICS::SET_PARTICLE_FX_LOOPED_COLOUR(ptfxId, colR, colG, colB, localOnly);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_ALPHA(int ptfxId, float colA)
	{
		GRAPHICS::SET_PARTICLE_FX_LOOPED_ALPHA(ptfxId, colA);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_SCALE(int ptfxId, float scale)
	{
		GRAPHICS::SET_PARTICLE_FX_LOOPED_SCALE(ptfxId, scale);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_FAR_CLIP_DIST(int ptfxId, float farClipDist)
	{
		GRAPHICS::SET_PARTICLE_FX_LOOPED_FAR_CLIP_DIST(ptfxId, farClipDist);
	}

	static void LUA_NATIVE_GRAPHICS__SET_PARTICLE_FX_LOOPED_UPDATE_DISTANT_SMOKE(int ptfxHandle, float scalar)
	{
		GRAPHICS::_SET_PARTICLE_FX_LOOPED_UPDATE_DISTANT_SMOKE(ptfxHandle, scalar);
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_PARTICLE_FX(int ptfxId, bool localOnly)
	{
		GRAPHICS::REMOVE_PARTICLE_FX(ptfxId, localOnly);
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_PARTICLE_FX_FROM_ENTITY(Entity entityIndex)
	{
		GRAPHICS::REMOVE_PARTICLE_FX_FROM_ENTITY(entityIndex);
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_PARTICLE_FX_IN_RANGE(float posX, float posY, float posZ, float range)
	{
		GRAPHICS::REMOVE_PARTICLE_FX_IN_RANGE(posX, posY, posZ, range);
	}

	static void LUA_NATIVE_GRAPHICS_USE_PARTICLE_FX_ASSET(sol::stack_object ptFxAssetName)
	{
		GRAPHICS::USE_PARTICLE_FX_ASSET(ptFxAssetName.is<const char*>() ? ptFxAssetName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_OVERRIDE(sol::stack_object ptFxToOverride, sol::stack_object ptFxToUseInstead)
	{
		GRAPHICS::SET_PARTICLE_FX_OVERRIDE(ptFxToOverride.is<const char*>() ? ptFxToOverride.as<const char*>() : nullptr, ptFxToUseInstead.is<const char*>() ? ptFxToUseInstead.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS_RESET_PARTICLE_FX_OVERRIDE(sol::stack_object ptFxToOverride)
	{
		GRAPHICS::RESET_PARTICLE_FX_OVERRIDE(ptFxToOverride.is<const char*>() ? ptFxToOverride.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__0x4FB67D172C4476F3(Entity entity, sol::stack_object p1, sol::stack_object p2, float p3)
	{
		GRAPHICS::_0x4FB67D172C4476F3(entity, p1.is<const char*>() ? p1.as<const char*>() : nullptr, p2.is<const char*>() ? p2.as<const char*>() : nullptr, p3);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_AMBIENT_COLOUR(Entity entity, sol::stack_object p1, float r, float g, float b)
	{
		GRAPHICS::SET_PARTICLE_FX_AMBIENT_COLOUR(entity, p1.is<const char*>() ? p1.as<const char*>() : nullptr, r, g, b);
	}

	static void LUA_NATIVE_GRAPHICS__0xD1472AFF30C103D6(float p0)
	{
		GRAPHICS::_0xD1472AFF30C103D6(p0);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_BULLET_IMPACT_SCALE(float scale)
	{
		GRAPHICS::SET_PARTICLE_FX_BULLET_IMPACT_SCALE(scale);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_BULLET_IMPACT_LODRANGE_SCALE(float scale)
	{
		GRAPHICS::SET_PARTICLE_FX_BULLET_IMPACT_LODRANGE_SCALE(scale);
	}

	static void LUA_NATIVE_GRAPHICS__SET_SNIPER_GLINTS_ENABLED(bool enabled)
	{
		GRAPHICS::_SET_SNIPER_GLINTS_ENABLED(enabled);
	}

	static void LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_FOOT_LODRANGE_SCALE(float scale)
	{
		GRAPHICS::SET_PARTICLE_FX_FOOT_LODRANGE_SCALE(scale);
	}

	static void LUA_NATIVE_GRAPHICS__0x4046493D2EEACA0E()
	{
		GRAPHICS::_0x4046493D2EEACA0E();
	}

	static void LUA_NATIVE_GRAPHICS_SET_PICKUP_LIGHT(Object object, bool toggle)
	{
		GRAPHICS::SET_PICKUP_LIGHT(object, toggle);
	}

	static void LUA_NATIVE_GRAPHICS__BLOCK_PICKUP_OBJECT_LIGHT(Object pickupObject, bool toggle)
	{
		GRAPHICS::_BLOCK_PICKUP_OBJECT_LIGHT(pickupObject, toggle);
	}

	static void LUA_NATIVE_GRAPHICS_BLOCK_PICKUP_PLACEMENT_LIGHT(Pickup pickup, bool toggle)
	{
		GRAPHICS::BLOCK_PICKUP_PLACEMENT_LIGHT(pickup, toggle);
	}

	static void LUA_NATIVE_GRAPHICS_ALLOW_PICKUP_LIGHT_SYNC(Object pickupObject, bool allow)
	{
		GRAPHICS::ALLOW_PICKUP_LIGHT_SYNC(pickupObject, allow);
	}

	static void LUA_NATIVE_GRAPHICS__SET_PEARLESCENT_FX_ENABLED(Object object, bool toggle)
	{
		GRAPHICS::_SET_PEARLESCENT_FX_ENABLED(object, toggle);
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_DECALS_IN_RANGE(float posX, float posY, float posZ, float range)
	{
		GRAPHICS::REMOVE_DECALS_IN_RANGE(posX, posY, posZ, range);
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_DECALS_FROM_OBJECT(Object ObjectIndex)
	{
		GRAPHICS::REMOVE_DECALS_FROM_OBJECT(ObjectIndex);
	}

	static int LUA_NATIVE_GRAPHICS_ADD_DECAL(Any p0, float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float sideX, float sideY, float sideZ, Any p10, float width, float height, float colR, float colG, float colB, float colA, float life, bool isLongRange, bool isDynamic, bool useComplexColn, Any p21)
	{
		auto retval = GRAPHICS::ADD_DECAL(p0, posX, posY, posZ, dirX, dirY, dirZ, sideX, sideY, sideZ, p10, width, height, colR, colG, colB, colA, life, isLongRange, isDynamic, useComplexColn, p21);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOL(float x, float y, float z, bool unused)
	{
		GRAPHICS::_ADD_BLOOD_POOL(x, y, z, unused);
	}

	static void LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOL_2(float x, float y, float z, float p3, float size, float p5, bool permanent, float p7, bool p8)
	{
		GRAPHICS::_ADD_BLOOD_POOL_2(x, y, z, p3, size, p5, permanent, p7, p8);
	}

	static void LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOLS_FOR_PED(Ped ped)
	{
		GRAPHICS::_ADD_BLOOD_POOLS_FOR_PED(ped);
	}

	static void LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOLS_FOR_PED_WITH_PARAMS(Ped ped, float p1, float size, float p3)
	{
		GRAPHICS::_ADD_BLOOD_POOLS_FOR_PED_WITH_PARAMS(ped, p1, size, p3);
	}

	static void LUA_NATIVE_GRAPHICS_START_PETROL_TRAIL_DECALS(Any p0, float width)
	{
		GRAPHICS::START_PETROL_TRAIL_DECALS(p0, width);
	}

	static void LUA_NATIVE_GRAPHICS_ADD_PETROL_TRAIL_DECAL_INFO(float posX, float posY, float posZ, float alphaMult)
	{
		GRAPHICS::ADD_PETROL_TRAIL_DECAL_INFO(posX, posY, posZ, alphaMult);
	}

	static void LUA_NATIVE_GRAPHICS_END_PETROL_TRAIL_DECALS()
	{
		GRAPHICS::END_PETROL_TRAIL_DECALS();
	}

	static Any LUA_NATIVE_GRAPHICS__0xE63D68F455CA0B47(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		auto retval = GRAPHICS::_0xE63D68F455CA0B47(p0, p1, p2, p3, p4, p5, p6);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_REMOVE_DECAL(int decalId)
	{
		GRAPHICS::REMOVE_DECAL(decalId);
	}

	static bool LUA_NATIVE_GRAPHICS_IS_DECAL_ALIVE(int decalId)
	{
		auto retval = (bool)GRAPHICS::IS_DECAL_ALIVE(decalId);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_DISABLE_PETROL_DECALS_IGNITING_THIS_FRAME()
	{
		GRAPHICS::SET_DISABLE_PETROL_DECALS_IGNITING_THIS_FRAME();
	}

	static void LUA_NATIVE_GRAPHICS__0xB032C085D9A03907()
	{
		GRAPHICS::_0xB032C085D9A03907();
	}

	static void LUA_NATIVE_GRAPHICS__0xFB680A9B33D0EDBE(bool p0)
	{
		GRAPHICS::_0xFB680A9B33D0EDBE(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x41F88A85A579A61D(float p0)
	{
		GRAPHICS::_0x41F88A85A579A61D(p0);
	}

	static void LUA_NATIVE_GRAPHICS__BLOOD_TRAIL_FOR_WAYPOINT(sol::stack_object waypointRecording, float p1)
	{
		GRAPHICS::_BLOOD_TRAIL_FOR_WAYPOINT(waypointRecording.is<const char*>() ? waypointRecording.as<const char*>() : nullptr, p1);
	}

	static void LUA_NATIVE_GRAPHICS__ADD_BLOOD_TRAIL_POINT(float x, float y, float z)
	{
		GRAPHICS::_ADD_BLOOD_TRAIL_POINT(x, y, z);
	}

	static void LUA_NATIVE_GRAPHICS__0x812C1563185C6FB2()
	{
		GRAPHICS::_0x812C1563185C6FB2();
	}

	static void LUA_NATIVE_GRAPHICS__0x4BD66B4E3427689B(sol::stack_object p0)
	{
		GRAPHICS::_0x4BD66B4E3427689B(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__ADD_BLOOD_TRAIL_SPLAT(float x, float y, float z)
	{
		GRAPHICS::_ADD_BLOOD_TRAIL_SPLAT(x, y, z);
	}

	static void LUA_NATIVE_GRAPHICS__0xF2F543D48F319A3A()
	{
		GRAPHICS::_0xF2F543D48F319A3A();
	}

	static void LUA_NATIVE_GRAPHICS__0x1460B644397453EB()
	{
		GRAPHICS::_0x1460B644397453EB();
	}

	static void LUA_NATIVE_GRAPHICS__DISABLE_FAR_ARTIFICIAL_LIGHTS(bool disable)
	{
		GRAPHICS::_DISABLE_FAR_ARTIFICIAL_LIGHTS(disable);
	}

	static void LUA_NATIVE_GRAPHICS__0x453D16D41FC51D3E(bool p0)
	{
		GRAPHICS::_0x453D16D41FC51D3E(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0xC06F2F45A73EABCD(Entity entity)
	{
		GRAPHICS::_0xC06F2F45A73EABCD(entity);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TIMECYCLE_MODIFIER(sol::stack_object ModifierName)
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER(ModifierName.is<const char*>() ? ModifierName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TIMECYCLE_MODIFIER_STRENGTH(float strength)
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER_STRENGTH(strength);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TRANSITION_TIMECYCLE_MODIFIER(sol::stack_object ModifierName, float time)
	{
		GRAPHICS::SET_TRANSITION_TIMECYCLE_MODIFIER(ModifierName.is<const char*>() ? ModifierName.as<const char*>() : nullptr, time);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TRANSITION_OUT_OF_TIMECYCLE_MODIFIER(float time)
	{
		GRAPHICS::SET_TRANSITION_OUT_OF_TIMECYCLE_MODIFIER(time);
	}

	static void LUA_NATIVE_GRAPHICS_CLEAR_TIMECYCLE_MODIFIER()
	{
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
	}

	static int LUA_NATIVE_GRAPHICS_GET_TIMECYCLE_MODIFIER_INDEX()
	{
		auto retval = GRAPHICS::GET_TIMECYCLE_MODIFIER_INDEX();
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS_GET_TIMECYCLE_TRANSITION_MODIFIER_INDEX()
	{
		auto retval = GRAPHICS::GET_TIMECYCLE_TRANSITION_MODIFIER_INDEX();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x67B0778C62E74423(Any p0)
	{
		GRAPHICS::_0x67B0778C62E74423(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x6C03118E9E5C1A14(Any p0)
	{
		GRAPHICS::_0x6C03118E9E5C1A14(p0);
	}

	static float LUA_NATIVE_GRAPHICS__GET_MODIFIED_VISIBILITY_DISTANCE()
	{
		auto retval = GRAPHICS::_GET_MODIFIED_VISIBILITY_DISTANCE();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_ENABLE_MOON_CYCLE_OVERRIDE(float value)
	{
		GRAPHICS::ENABLE_MOON_CYCLE_OVERRIDE(value);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TV_CHANNEL(int iChannel)
	{
		GRAPHICS::SET_TV_CHANNEL(iChannel);
	}

	static int LUA_NATIVE_GRAPHICS_GET_TV_CHANNEL()
	{
		auto retval = GRAPHICS::GET_TV_CHANNEL();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_SET_TV_VOLUME(float vol)
	{
		GRAPHICS::SET_TV_VOLUME(vol);
	}

	static void LUA_NATIVE_GRAPHICS_DRAW_TV_CHANNEL(float CentreX, float CentreY, float Width, float Height, float Rotation, int R, int G, int B, int A)
	{
		GRAPHICS::DRAW_TV_CHANNEL(CentreX, CentreY, Width, Height, Rotation, R, G, B, A);
	}

	static void LUA_NATIVE_GRAPHICS_SET_TV_CHANNEL_PLAYLIST(int iChannel, sol::stack_object playlistName, bool startFromNow)
	{
		GRAPHICS::SET_TV_CHANNEL_PLAYLIST(iChannel, playlistName.is<const char*>() ? playlistName.as<const char*>() : nullptr, startFromNow);
	}

	static bool LUA_NATIVE_GRAPHICS_IS_TVSHOW_CURRENTLY_PLAYING(Hash nameHash)
	{
		auto retval = (bool)GRAPHICS::IS_TVSHOW_CURRENTLY_PLAYING(nameHash);
		return retval;
	}

	static Any LUA_NATIVE_GRAPHICS__0x5C674EB487891F6B()
	{
		auto retval = GRAPHICS::_0x5C674EB487891F6B();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_ENABLE_MOVIE_SUBTITLES(bool bOnOff)
	{
		GRAPHICS::ENABLE_MOVIE_SUBTITLES(bOnOff);
	}

	static void LUA_NATIVE_GRAPHICS__0x32DE2BFFDA43E62A()
	{
		GRAPHICS::_0x32DE2BFFDA43E62A();
	}

	static void LUA_NATIVE_GRAPHICS__0xD543487A1F12828F(Any p0, Any p1, Any p2, Any p3)
	{
		GRAPHICS::_0xD543487A1F12828F(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_GRAPHICS__0xD9BC98B55BCFAA9B(Any p0)
	{
		GRAPHICS::_0xD9BC98B55BCFAA9B(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x48FE0DB54045B975(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		GRAPHICS::_0x48FE0DB54045B975(p0, p1, p2, p3, p4, p5, p6);
	}

	static void LUA_NATIVE_GRAPHICS__0x735762E8D7573E42(Any p0, Any p1, Any p2)
	{
		GRAPHICS::_0x735762E8D7573E42(p0, p1, p2);
	}

	static void LUA_NATIVE_GRAPHICS__0x981C7D863980FA51()
	{
		GRAPHICS::_0x981C7D863980FA51();
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PRELOAD_POSTFX(sol::stack_object effectName)
	{
		GRAPHICS::_ANIMPOSTFX_PRELOAD_POSTFX(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_GRAPHICS__ANIMPOSTFX_HAS_LOADED(sol::stack_object effectName)
	{
		auto retval = (bool)GRAPHICS::_ANIMPOSTFX_HAS_LOADED(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_TO_UNLOAD(sol::stack_object effectName)
	{
		GRAPHICS::_ANIMPOSTFX_SET_TO_UNLOAD(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS_ANIMPOSTFX_PLAY(sol::stack_object effectName)
	{
		GRAPHICS::ANIMPOSTFX_PLAY(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PLAY_TIMED(sol::stack_object effectName, int duration)
	{
		GRAPHICS::_ANIMPOSTFX_PLAY_TIMED(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, duration);
	}

	static void LUA_NATIVE_GRAPHICS_ANIMPOSTFX_STOP(sol::stack_object effectName)
	{
		GRAPHICS::ANIMPOSTFX_STOP(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__0x26DD2FB0A88CC412(sol::stack_object effectName, sol::stack_object effectName2, Any p2, Any p3)
	{
		GRAPHICS::_0x26DD2FB0A88CC412(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, effectName2.is<const char*>() ? effectName2.as<const char*>() : nullptr, p2, p3);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_CLEAR_EFFECT(sol::stack_object effectName)
	{
		GRAPHICS::_ANIMPOSTFX_CLEAR_EFFECT(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_GRAPHICS_ANIMPOSTFX_IS_RUNNING(sol::stack_object effectName)
	{
		auto retval = (bool)GRAPHICS::ANIMPOSTFX_IS_RUNNING(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS__ANIMPOSTFX_IS_TAG_PLAYING(sol::stack_object effectName)
	{
		auto retval = (bool)GRAPHICS::_ANIMPOSTFX_IS_TAG_PLAYING(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS_ANIMPOSTFX_STOP_ALL()
	{
		GRAPHICS::ANIMPOSTFX_STOP_ALL();
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_STOP_TAG(sol::stack_object effectName)
	{
		GRAPHICS::_ANIMPOSTFX_STOP_TAG(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_STRENGTH(sol::stack_object effectName, float strength)
	{
		GRAPHICS::_ANIMPOSTFX_SET_STRENGTH(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, strength);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_POTENCY(sol::stack_object effectName, int p1, float potency)
	{
		GRAPHICS::_ANIMPOSTFX_SET_POTENCY(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, p1, potency);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_POSTFX_COLOR(sol::stack_object effectName, int p1, int red, int green, int blue, int alpha)
	{
		GRAPHICS::_ANIMPOSTFX_SET_POSTFX_COLOR(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, p1, red, green, blue, alpha);
	}

	static bool LUA_NATIVE_GRAPHICS__0xB958D97A0DFAA0C2(sol::stack_object effectName)
	{
		auto retval = (bool)GRAPHICS::_0xB958D97A0DFAA0C2(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0xA201A3D0AC087C37(sol::stack_object effectName)
	{
		GRAPHICS::_0xA201A3D0AC087C37(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
	}

	static std::tuple<bool, bool> LUA_NATIVE_GRAPHICS__0xFBF161FCFEC8589E(sol::stack_object effectName, int p1, bool p2, bool p3)
	{
		std::tuple<bool, bool> return_values;
		std::get<0>(return_values) = (bool)GRAPHICS::_0xFBF161FCFEC8589E(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr, p1, p2, (BOOL*)&p3);
		std::get<1>(return_values) = p3;

		return return_values;
	}

	static Hash LUA_NATIVE_GRAPHICS__ANIMPOSTFX_GET_STACKHASH(sol::stack_object effectName)
	{
		auto retval = GRAPHICS::_ANIMPOSTFX_GET_STACKHASH(effectName.is<const char*>() ? effectName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PRELOAD_POSTFX_BY_STACKHASH(Hash effectNameHash)
	{
		GRAPHICS::_ANIMPOSTFX_PRELOAD_POSTFX_BY_STACKHASH(effectNameHash);
	}

	static bool LUA_NATIVE_GRAPHICS_ANIMPOSTFX_IS_PRELOADING_BY_STACKHASH(Hash effectNameHash)
	{
		auto retval = (bool)GRAPHICS::ANIMPOSTFX_IS_PRELOADING_BY_STACKHASH(effectNameHash);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x38D9D50F2085E9B3(Hash effectNameHash)
	{
		GRAPHICS::_0x38D9D50F2085E9B3(effectNameHash);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PLAY_TAG(Hash effectNameHash)
	{
		GRAPHICS::_ANIMPOSTFX_PLAY_TAG(effectNameHash);
	}

	static void LUA_NATIVE_GRAPHICS__0xC76FC4C2FC5F4405(Hash effectNameHash)
	{
		GRAPHICS::_0xC76FC4C2FC5F4405(effectNameHash);
	}

	static void LUA_NATIVE_GRAPHICS__ANIMPOSTFX_STOP_STACKHASH_POSTFX(Hash effectNameHash)
	{
		GRAPHICS::_ANIMPOSTFX_STOP_STACKHASH_POSTFX(effectNameHash);
	}

	static bool LUA_NATIVE_GRAPHICS__ANIMPOSTFX_IS_STACKHASH_PLAYING(Hash effectNameHash)
	{
		auto retval = (bool)GRAPHICS::_ANIMPOSTFX_IS_STACKHASH_PLAYING(effectNameHash);
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS__0xE75CDDEBF618C8FF(Hash effectNameHash)
	{
		auto retval = (bool)GRAPHICS::_0xE75CDDEBF618C8FF(effectNameHash);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x71845905BCCDE781(Hash effectNameHash)
	{
		GRAPHICS::_0x71845905BCCDE781(effectNameHash);
	}

	static std::tuple<bool, bool> LUA_NATIVE_GRAPHICS_ANIMPOSTFX_HAS_EVENT_TRIGGERED_BY_STACKHASH(Hash effectNameHash, int p1, bool p2, bool p3)
	{
		std::tuple<bool, bool> return_values;
		std::get<0>(return_values) = (bool)GRAPHICS::ANIMPOSTFX_HAS_EVENT_TRIGGERED_BY_STACKHASH(effectNameHash, p1, p2, (BOOL*)&p3);
		std::get<1>(return_values) = p3;

		return return_values;
	}

	static bool LUA_NATIVE_GRAPHICS__0xFF584F097C17FA8F()
	{
		auto retval = (bool)GRAPHICS::_0xFF584F097C17FA8F();
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS__0x3DA7A10583A4BEC0()
	{
		auto retval = (bool)GRAPHICS::_0x3DA7A10583A4BEC0();
		return retval;
	}

	static Any LUA_NATIVE_GRAPHICS__0xC37792A3F9C90771()
	{
		auto retval = GRAPHICS::_0xC37792A3F9C90771();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0xA0F4D12D6042F6D5(Any p0, Any p1)
	{
		GRAPHICS::_0xA0F4D12D6042F6D5(p0, p1);
	}

	static void LUA_NATIVE_GRAPHICS__0x8996FA6AD9FE4E90(Any p0)
	{
		GRAPHICS::_0x8996FA6AD9FE4E90(p0);
	}

	static void LUA_NATIVE_GRAPHICS__SET_ENTITY_RENDER_GUARMA_SHIP(Vehicle vehicle, bool toggle)
	{
		GRAPHICS::_SET_ENTITY_RENDER_GUARMA_SHIP(vehicle, toggle);
	}

	static bool LUA_NATIVE_GRAPHICS_PEDSHOT_IS_AVAILABLE()
	{
		auto retval = (bool)GRAPHICS::PEDSHOT_IS_AVAILABLE();
		return retval;
	}

	static bool LUA_NATIVE_GRAPHICS__0xFD05B1DDE83749FA(sol::stack_object p0)
	{
		auto retval = (bool)GRAPHICS::_0xFD05B1DDE83749FA(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__PEDSHOT_FINISH_CLEANUP_DATA()
	{
		GRAPHICS::_PEDSHOT_FINISH_CLEANUP_DATA();
	}

	static void LUA_NATIVE_GRAPHICS__PEDSHOT_PREVIOUS_PERSONA_PHOTO_DATA_CLEANUP()
	{
		GRAPHICS::_PEDSHOT_PREVIOUS_PERSONA_PHOTO_DATA_CLEANUP();
	}

	static void LUA_NATIVE_GRAPHICS__PEDSHOT_INIT_CLEANUP_DATA()
	{
		GRAPHICS::_PEDSHOT_INIT_CLEANUP_DATA();
	}

	static bool LUA_NATIVE_GRAPHICS__PEDSHOT_GENERATE_PERSONA_PHOTO(sol::stack_object texture, Ped ped, int playerSlot)
	{
		auto retval = (bool)GRAPHICS::_PEDSHOT_GENERATE_PERSONA_PHOTO(texture.is<const char*>() ? texture.as<const char*>() : nullptr, ped, playerSlot);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__PEDSHOT_SET_PERSONA_PHOTO_TYPE(int personaPhotoLocalCacheType)
	{
		GRAPHICS::_PEDSHOT_SET_PERSONA_PHOTO_TYPE(personaPhotoLocalCacheType);
	}

	static void LUA_NATIVE_GRAPHICS__0xA1A86055792FB249(int personaPhotoLocalCacheType)
	{
		GRAPHICS::_0xA1A86055792FB249(personaPhotoLocalCacheType);
	}

	static bool LUA_NATIVE_GRAPHICS__0x402E1A61D2587FCD(Any p0, float x, float y, float z, float p4, float p5, float heading)
	{
		auto retval = (bool)GRAPHICS::_0x402E1A61D2587FCD(p0, x, y, z, p4, p5, heading);
		return retval;
	}

	static Any LUA_NATIVE_GRAPHICS__0x5C9C3A466B3296A8(Any p0)
	{
		auto retval = GRAPHICS::_0x5C9C3A466B3296A8(p0);
		return retval;
	}

	static Any LUA_NATIVE_GRAPHICS__0xA15CCAB8AD038291(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = GRAPHICS::_0xA15CCAB8AD038291(p0, p1, p2, p3);
		return retval;
	}

	static Any LUA_NATIVE_GRAPHICS__0x285438C26C732F9D()
	{
		auto retval = GRAPHICS::_0x285438C26C732F9D();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__SET_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_STATE(int proxyInteriorIndex, bool state)
	{
		GRAPHICS::_SET_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_STATE(proxyInteriorIndex, state);
	}

	static bool LUA_NATIVE_GRAPHICS__IS_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_ENABLED(int proxyInteriorIndex)
	{
		auto retval = (bool)GRAPHICS::_IS_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_ENABLED(proxyInteriorIndex);
		return retval;
	}

	static int LUA_NATIVE_GRAPHICS__GET_PROXY_INTERIOR_INDEX(int interiorId)
	{
		auto retval = GRAPHICS::_GET_PROXY_INTERIOR_INDEX(interiorId);
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x9D1B0B5066205692()
	{
		GRAPHICS::_0x9D1B0B5066205692();
	}

	static void LUA_NATIVE_GRAPHICS__0xC489FE31AC726512(Any p0, Any p1)
	{
		GRAPHICS::_0xC489FE31AC726512(p0, p1);
	}

	static void LUA_NATIVE_GRAPHICS__SET_CLOUD_LAYER(float x, float y, int p2)
	{
		GRAPHICS::_SET_CLOUD_LAYER(x, y, p2);
	}

	static void LUA_NATIVE_GRAPHICS__SET_CLOUD_NOISE(float x, float y, float z)
	{
		GRAPHICS::_SET_CLOUD_NOISE(x, y, z);
	}

	static void LUA_NATIVE_GRAPHICS__SET_CLOUD_POSITION(float x, float y, float z)
	{
		GRAPHICS::_SET_CLOUD_POSITION(x, y, z);
	}

	static void LUA_NATIVE_GRAPHICS__SET_CLOUD_HEIGHT(float height)
	{
		GRAPHICS::_SET_CLOUD_HEIGHT(height);
	}

	static void LUA_NATIVE_GRAPHICS__0x085C5B61A0114F32(Any p0, Any p1)
	{
		GRAPHICS::_0x085C5B61A0114F32(p0, p1);
	}

	static void LUA_NATIVE_GRAPHICS__0x1FF8731BE1DFC0C0(Any p0, Any p1)
	{
		GRAPHICS::_0x1FF8731BE1DFC0C0(p0, p1);
	}

	static Any LUA_NATIVE_GRAPHICS__0xFC9B53C072F418E0()
	{
		auto retval = GRAPHICS::_0xFC9B53C072F418E0();
		return retval;
	}

	static void LUA_NATIVE_GRAPHICS__0x94B261F1F35293E1(Any p0)
	{
		GRAPHICS::_0x94B261F1F35293E1(p0);
	}

	static void LUA_NATIVE_GRAPHICS_ENABLE_ENTITYMASK()
	{
		GRAPHICS::ENABLE_ENTITYMASK();
	}

	static void LUA_NATIVE_GRAPHICS_DISABLE_ENTITYMASK()
	{
		GRAPHICS::DISABLE_ENTITYMASK();
	}

	static void LUA_NATIVE_GRAPHICS__ADD_ENTITY_TO_ENTITY_MASK(Entity entity, int mask)
	{
		GRAPHICS::_ADD_ENTITY_TO_ENTITY_MASK(entity, mask);
	}

	static void LUA_NATIVE_GRAPHICS__ADD_ENTITY_TO_ENTITY_MASK_WITH_INTENSITY(Entity entity, int mask, float intensity)
	{
		GRAPHICS::_ADD_ENTITY_TO_ENTITY_MASK_WITH_INTENSITY(entity, mask, intensity);
	}

	static void LUA_NATIVE_GRAPHICS__REMOVE_ENTITY_FROM_ENTITY_MASK(Entity entity)
	{
		GRAPHICS::_REMOVE_ENTITY_FROM_ENTITY_MASK(entity);
	}

	static std::tuple<bool, float, float, float, float> LUA_NATIVE_GRAPHICS__GET_ENTITY_MASK_LAYERS(Entity entity, float layer0, float layer1, float layer2, float layer3)
	{
		std::tuple<bool, float, float, float, float> return_values;
		std::get<0>(return_values) = (bool)GRAPHICS::_GET_ENTITY_MASK_LAYERS(entity, &layer0, &layer1, &layer2, &layer3);
		std::get<1>(return_values) = layer0;
		std::get<2>(return_values) = layer1;
		std::get<3>(return_values) = layer2;
		std::get<4>(return_values) = layer3;

		return return_values;
	}

	static std::tuple<float, float, float, float> LUA_NATIVE_GRAPHICS__SET_ENTITY_MASK_LAYERS(Entity entity, float layer0, float layer1, float layer2, float layer3)
	{
		std::tuple<float, float, float, float> return_values;
		GRAPHICS::_SET_ENTITY_MASK_LAYERS(entity, &layer0, &layer1, &layer2, &layer3);
		std::get<0>(return_values) = layer0;
		std::get<1>(return_values) = layer1;
		std::get<2>(return_values) = layer2;
		std::get<3>(return_values) = layer3;

		return return_values;
	}

	static void LUA_NATIVE_GRAPHICS__SET_ENTITY_AURA(float p0, float p1, float p2)
	{
		GRAPHICS::_SET_ENTITY_AURA(p0, p1, p2);
	}

	static void LUA_NATIVE_GRAPHICS__RESET_ENTITY_AURA()
	{
		GRAPHICS::_RESET_ENTITY_AURA();
	}

	static void LUA_NATIVE_GRAPHICS__SET_SNOW_COVERAGE_TYPE(int type)
	{
		GRAPHICS::_SET_SNOW_COVERAGE_TYPE(type);
	}

	static void LUA_NATIVE_GRAPHICS__0x519928DF02EB5101(Any p0)
	{
		GRAPHICS::_0x519928DF02EB5101(p0);
	}

	static void LUA_NATIVE_GRAPHICS__0x1C6306E5BC25C29C()
	{
		GRAPHICS::_0x1C6306E5BC25C29C();
	}

	void RegisterNatives_GRAPHICS(sol::state& L)
	{
		auto GRAPHICS = L["GRAPHICS"].get_or_create<sol::table>();
		GRAPHICS.set_function("FREE_MEMORY_FOR_MISSION_CREATOR_PHOTO", LUA_NATIVE_GRAPHICS_FREE_MEMORY_FOR_MISSION_CREATOR_PHOTO);
		GRAPHICS.set_function("LOAD_MISSION_CREATOR_PHOTO", LUA_NATIVE_GRAPHICS_LOAD_MISSION_CREATOR_PHOTO);
		GRAPHICS.set_function("GET_STATUS_OF_LOAD_MISSION_CREATOR_PHOTO", LUA_NATIVE_GRAPHICS_GET_STATUS_OF_LOAD_MISSION_CREATOR_PHOTO);
		GRAPHICS.set_function("BEGIN_TAKE_HIGH_QUALITY_PHOTO", LUA_NATIVE_GRAPHICS_BEGIN_TAKE_HIGH_QUALITY_PHOTO);
		GRAPHICS.set_function("GET_STATUS_OF_TAKE_HIGH_QUALITY_PHOTO", LUA_NATIVE_GRAPHICS_GET_STATUS_OF_TAKE_HIGH_QUALITY_PHOTO);
		GRAPHICS.set_function("FREE_MEMORY_FOR_HIGH_QUALITY_PHOTO", LUA_NATIVE_GRAPHICS_FREE_MEMORY_FOR_HIGH_QUALITY_PHOTO);
		GRAPHICS.set_function("_SET_PHOTO_SELF_STAT", LUA_NATIVE_GRAPHICS__SET_PHOTO_SELF_STAT);
		GRAPHICS.set_function("_SET_PHOTO_STUDIO_STAT", LUA_NATIVE_GRAPHICS__SET_PHOTO_STUDIO_STAT);
		GRAPHICS.set_function("_SET_POSSE_ID_FOR_PHOTO", LUA_NATIVE_GRAPHICS__SET_POSSE_ID_FOR_PHOTO);
		GRAPHICS.set_function("_0x9F6D859C80708B26", LUA_NATIVE_GRAPHICS__0x9F6D859C80708B26);
		GRAPHICS.set_function("IS_PHOTO_FRAME", LUA_NATIVE_GRAPHICS_IS_PHOTO_FRAME);
		GRAPHICS.set_function("_SET_PHOTO_IN_PHOTOMODE_STAT", LUA_NATIVE_GRAPHICS__SET_PHOTO_IN_PHOTOMODE_STAT);
		GRAPHICS.set_function("_SET_PHOTO_OVERLAY_EFFECT_STAT", LUA_NATIVE_GRAPHICS__SET_PHOTO_OVERLAY_EFFECT_STAT);
		GRAPHICS.set_function("_0x0D5B19C34068FEE7", LUA_NATIVE_GRAPHICS__0x0D5B19C34068FEE7);
		GRAPHICS.set_function("_SET_PLAYER_APPEAR_IN_PHOTO", LUA_NATIVE_GRAPHICS__SET_PLAYER_APPEAR_IN_PHOTO);
		GRAPHICS.set_function("_SET_REGION_PHOTO_TAKEN_STAT", LUA_NATIVE_GRAPHICS__SET_REGION_PHOTO_TAKEN_STAT);
		GRAPHICS.set_function("_SET_DISTRICT_PHOTO_TAKEN_STAT", LUA_NATIVE_GRAPHICS__SET_DISTRICT_PHOTO_TAKEN_STAT);
		GRAPHICS.set_function("_SET_STATE_PHOTO_TAKEN_STAT", LUA_NATIVE_GRAPHICS__SET_STATE_PHOTO_TAKEN_STAT);
		GRAPHICS.set_function("SAVE_HIGH_QUALITY_PHOTO", LUA_NATIVE_GRAPHICS_SAVE_HIGH_QUALITY_PHOTO);
		GRAPHICS.set_function("GET_STATUS_OF_SAVE_HIGH_QUALITY_PHOTO", LUA_NATIVE_GRAPHICS_GET_STATUS_OF_SAVE_HIGH_QUALITY_PHOTO);
		GRAPHICS.set_function("BEGIN_CREATE_LOW_QUALITY_COPY_OF_PHOTO", LUA_NATIVE_GRAPHICS_BEGIN_CREATE_LOW_QUALITY_COPY_OF_PHOTO);
		GRAPHICS.set_function("GET_STATUS_OF_CREATE_LOW_QUALITY_COPY_OF_PHOTO", LUA_NATIVE_GRAPHICS_GET_STATUS_OF_CREATE_LOW_QUALITY_COPY_OF_PHOTO);
		GRAPHICS.set_function("FREE_MEMORY_FOR_LOW_QUALITY_PHOTO", LUA_NATIVE_GRAPHICS_FREE_MEMORY_FOR_LOW_QUALITY_PHOTO);
		GRAPHICS.set_function("DRAW_LOW_QUALITY_PHOTO_TO_PHONE", LUA_NATIVE_GRAPHICS_DRAW_LOW_QUALITY_PHOTO_TO_PHONE);
		GRAPHICS.set_function("_GET_MAX_NUMBER_OF_LOCAL_PHOTOS", LUA_NATIVE_GRAPHICS__GET_MAX_NUMBER_OF_LOCAL_PHOTOS);
		GRAPHICS.set_function("_GET_CURRENT_NUMBER_OF_LOCAL_PHOTOS", LUA_NATIVE_GRAPHICS__GET_CURRENT_NUMBER_OF_LOCAL_PHOTOS);
		GRAPHICS.set_function("QUEUE_OPERATION_TO_CREATE_SORTED_LIST_OF_PHOTOS", LUA_NATIVE_GRAPHICS_QUEUE_OPERATION_TO_CREATE_SORTED_LIST_OF_PHOTOS);
		GRAPHICS.set_function("GET_STATUS_OF_SORTED_LIST_OPERATION", LUA_NATIVE_GRAPHICS_GET_STATUS_OF_SORTED_LIST_OPERATION);
		GRAPHICS.set_function("DRAW_LIGHT_WITH_RANGE", LUA_NATIVE_GRAPHICS_DRAW_LIGHT_WITH_RANGE);
		GRAPHICS.set_function("UPDATE_LIGHTS_ON_ENTITY", LUA_NATIVE_GRAPHICS_UPDATE_LIGHTS_ON_ENTITY);
		GRAPHICS.set_function("_SET_LIGHTS_COLOR_FOR_ENTITY", LUA_NATIVE_GRAPHICS__SET_LIGHTS_COLOR_FOR_ENTITY);
		GRAPHICS.set_function("_SET_LIGHTS_INTENSITY_FOR_ENTITY", LUA_NATIVE_GRAPHICS__SET_LIGHTS_INTENSITY_FOR_ENTITY);
		GRAPHICS.set_function("_SET_LIGHTS_TYPE_FOR_ENTITY", LUA_NATIVE_GRAPHICS__SET_LIGHTS_TYPE_FOR_ENTITY);
		GRAPHICS.set_function("_DRAW_MARKER", LUA_NATIVE_GRAPHICS__DRAW_MARKER);
		GRAPHICS.set_function("CREATE_CHECKPOINT_WITH_NAMEHASH", LUA_NATIVE_GRAPHICS_CREATE_CHECKPOINT_WITH_NAMEHASH);
		GRAPHICS.set_function("_DOES_CHECKPOINT_HAVE_FX", LUA_NATIVE_GRAPHICS__DOES_CHECKPOINT_HAVE_FX);
		GRAPHICS.set_function("SET_CHECKPOINT_RGBA", LUA_NATIVE_GRAPHICS_SET_CHECKPOINT_RGBA);
		GRAPHICS.set_function("SET_CHECKPOINT_RGBA2", LUA_NATIVE_GRAPHICS_SET_CHECKPOINT_RGBA2);
		GRAPHICS.set_function("_0xCC3B787E73E64160", LUA_NATIVE_GRAPHICS__0xCC3B787E73E64160);
		GRAPHICS.set_function("_0x171C18E994C1A395", LUA_NATIVE_GRAPHICS__0x171C18E994C1A395);
		GRAPHICS.set_function("DELETE_CHECKPOINT", LUA_NATIVE_GRAPHICS_DELETE_CHECKPOINT);
		GRAPHICS.set_function("DRAW_RECT", LUA_NATIVE_GRAPHICS_DRAW_RECT);
		GRAPHICS.set_function("SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU", LUA_NATIVE_GRAPHICS_SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU);
		GRAPHICS.set_function("SET_SCRIPT_GFX_DRAW_ORDER", LUA_NATIVE_GRAPHICS_SET_SCRIPT_GFX_DRAW_ORDER);
		GRAPHICS.set_function("DRAW_SPRITE", LUA_NATIVE_GRAPHICS_DRAW_SPRITE);
		GRAPHICS.set_function("ATTACH_TV_AUDIO_TO_ENTITY", LUA_NATIVE_GRAPHICS_ATTACH_TV_AUDIO_TO_ENTITY);
		GRAPHICS.set_function("SET_TV_AUDIO_FRONTEND", LUA_NATIVE_GRAPHICS_SET_TV_AUDIO_FRONTEND);
		GRAPHICS.set_function("GET_SCREEN_RESOLUTION", LUA_NATIVE_GRAPHICS_GET_SCREEN_RESOLUTION);
		GRAPHICS.set_function("_0xA04EF43030593ABC", LUA_NATIVE_GRAPHICS__0xA04EF43030593ABC);
		GRAPHICS.set_function("_0xA21AF60C9F99CCC5", LUA_NATIVE_GRAPHICS__0xA21AF60C9F99CCC5);
		GRAPHICS.set_function("_0xC28F62AC9774FC1B", LUA_NATIVE_GRAPHICS__0xC28F62AC9774FC1B);
		GRAPHICS.set_function("_0xEB48CE48EEC41FD4", LUA_NATIVE_GRAPHICS__0xEB48CE48EEC41FD4);
		GRAPHICS.set_function("GET_SCREEN_COORD_FROM_WORLD_COORD", LUA_NATIVE_GRAPHICS_GET_SCREEN_COORD_FROM_WORLD_COORD);
		GRAPHICS.set_function("_IS_TEXTURE_IN_DICT", LUA_NATIVE_GRAPHICS__IS_TEXTURE_IN_DICT);
		GRAPHICS.set_function("SET_ARTIFICIAL_LIGHTS_STATE", LUA_NATIVE_GRAPHICS_SET_ARTIFICIAL_LIGHTS_STATE);
		GRAPHICS.set_function("DISABLE_HDTEX_THIS_FRAME", LUA_NATIVE_GRAPHICS_DISABLE_HDTEX_THIS_FRAME);
		GRAPHICS.set_function("_0x1A9F09AB458D49C6", LUA_NATIVE_GRAPHICS__0x1A9F09AB458D49C6);
		GRAPHICS.set_function("CREATE_TRACKED_POINT", LUA_NATIVE_GRAPHICS_CREATE_TRACKED_POINT);
		GRAPHICS.set_function("SET_TRACKED_POINT_INFO", LUA_NATIVE_GRAPHICS_SET_TRACKED_POINT_INFO);
		GRAPHICS.set_function("IS_TRACKED_POINT_VISIBLE", LUA_NATIVE_GRAPHICS_IS_TRACKED_POINT_VISIBLE);
		GRAPHICS.set_function("_0xDFE332A5DA6FE7C9", LUA_NATIVE_GRAPHICS__0xDFE332A5DA6FE7C9);
		GRAPHICS.set_function("DESTROY_TRACKED_POINT", LUA_NATIVE_GRAPHICS_DESTROY_TRACKED_POINT);
		GRAPHICS.set_function("_IS_TRACKED_POINT_VALID", LUA_NATIVE_GRAPHICS__IS_TRACKED_POINT_VALID);
		GRAPHICS.set_function("SET_GRASS_CULL_SPHERE", LUA_NATIVE_GRAPHICS_SET_GRASS_CULL_SPHERE);
		GRAPHICS.set_function("REMOVE_GRASS_CULL_SPHERE", LUA_NATIVE_GRAPHICS_REMOVE_GRASS_CULL_SPHERE);
		GRAPHICS.set_function("_ADD_VEG_MODIFIER_ZONE", LUA_NATIVE_GRAPHICS__ADD_VEG_MODIFIER_ZONE);
		GRAPHICS.set_function("ADD_VEG_MODIFIER_SPHERE", LUA_NATIVE_GRAPHICS_ADD_VEG_MODIFIER_SPHERE);
		GRAPHICS.set_function("REMOVE_VEG_MODIFIER_SPHERE", LUA_NATIVE_GRAPHICS_REMOVE_VEG_MODIFIER_SPHERE);
		GRAPHICS.set_function("_ENABLE_STATIC_VEG_MODIFIER", LUA_NATIVE_GRAPHICS__ENABLE_STATIC_VEG_MODIFIER);
		GRAPHICS.set_function("_DISABLE_STATIC_VEG_MODIFIER", LUA_NATIVE_GRAPHICS__DISABLE_STATIC_VEG_MODIFIER);
		GRAPHICS.set_function("_IS_STATIC_VEG_MODIFIER_ENABLED", LUA_NATIVE_GRAPHICS__IS_STATIC_VEG_MODIFIER_ENABLED);
		GRAPHICS.set_function("_0xEC3F7F24EEEB3BA3", LUA_NATIVE_GRAPHICS__0xEC3F7F24EEEB3BA3);
		GRAPHICS.set_function("_0x9F158A49B0D84C3C", LUA_NATIVE_GRAPHICS__0x9F158A49B0D84C3C);
		GRAPHICS.set_function("_0x910E260AEAD855DE", LUA_NATIVE_GRAPHICS__0x910E260AEAD855DE);
		GRAPHICS.set_function("_CREATE_SWATCH_TEXTURE_DICT", LUA_NATIVE_GRAPHICS__CREATE_SWATCH_TEXTURE_DICT);
		GRAPHICS.set_function("_DESTROY_SWATCH_TEXTURE_DICT", LUA_NATIVE_GRAPHICS__DESTROY_SWATCH_TEXTURE_DICT);
		GRAPHICS.set_function("_GENERATE_SWATCH_TEXTURE_DIRECTLY", LUA_NATIVE_GRAPHICS__GENERATE_SWATCH_TEXTURE_DIRECTLY);
		GRAPHICS.set_function("_GENERATE_SWATCH_TEXTURE", LUA_NATIVE_GRAPHICS__GENERATE_SWATCH_TEXTURE);
		GRAPHICS.set_function("CASCADE_SHADOWS_SET_CASCADE_BOUNDS", LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_SET_CASCADE_BOUNDS);
		GRAPHICS.set_function("CASCADE_SHADOWS_ENABLE_ENTITY_TRACKER", LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_ENABLE_ENTITY_TRACKER);
		GRAPHICS.set_function("CASCADE_SHADOWS_SET_SHADOW_SAMPLE_TYPE", LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_SET_SHADOW_SAMPLE_TYPE);
		GRAPHICS.set_function("CASCADE_SHADOWS_CLEAR_SHADOW_SAMPLE_TYPE", LUA_NATIVE_GRAPHICS_CASCADE_SHADOWS_CLEAR_SHADOW_SAMPLE_TYPE);
		GRAPHICS.set_function("_0x503941F65DBA24EC", LUA_NATIVE_GRAPHICS__0x503941F65DBA24EC);
		GRAPHICS.set_function("_0x815653A42C5ABE76", LUA_NATIVE_GRAPHICS__0x815653A42C5ABE76);
		GRAPHICS.set_function("_0xFF8018C778349234", LUA_NATIVE_GRAPHICS__0xFF8018C778349234);
		GRAPHICS.set_function("RESET_ADAPTATION", LUA_NATIVE_GRAPHICS_RESET_ADAPTATION);
		GRAPHICS.set_function("TOGGLE_PAUSED_RENDERPHASES", LUA_NATIVE_GRAPHICS_TOGGLE_PAUSED_RENDERPHASES);
		GRAPHICS.set_function("GET_TOGGLE_PAUSED_RENDERPHASES_STATUS", LUA_NATIVE_GRAPHICS_GET_TOGGLE_PAUSED_RENDERPHASES_STATUS);
		GRAPHICS.set_function("RESET_PAUSED_RENDERPHASES", LUA_NATIVE_GRAPHICS_RESET_PAUSED_RENDERPHASES);
		GRAPHICS.set_function("SET_HIDOF_OVERRIDE", LUA_NATIVE_GRAPHICS_SET_HIDOF_OVERRIDE);
		GRAPHICS.set_function("_0x21F00E08CBB5F37B", LUA_NATIVE_GRAPHICS__0x21F00E08CBB5F37B);
		GRAPHICS.set_function("_0x5AC6E0FA028369DE", LUA_NATIVE_GRAPHICS__0x5AC6E0FA028369DE);
		GRAPHICS.set_function("_0xEC3D8C228FE553D7", LUA_NATIVE_GRAPHICS__0xEC3D8C228FE553D7);
		GRAPHICS.set_function("_0xF5793BB386E1FF9C", LUA_NATIVE_GRAPHICS__0xF5793BB386E1FF9C);
		GRAPHICS.set_function("_0x5CD6A2CCE5087161", LUA_NATIVE_GRAPHICS__0x5CD6A2CCE5087161);
		GRAPHICS.set_function("_0xC8D0611D9A0CF5D3", LUA_NATIVE_GRAPHICS__0xC8D0611D9A0CF5D3);
		GRAPHICS.set_function("_GET_PHOTO_MODE_EXPOSURE", LUA_NATIVE_GRAPHICS__GET_PHOTO_MODE_EXPOSURE);
		GRAPHICS.set_function("_0x62B9F9A1272AED80", LUA_NATIVE_GRAPHICS__0x62B9F9A1272AED80);
		GRAPHICS.set_function("_GET_PHOTO_MODE_CONTRAST", LUA_NATIVE_GRAPHICS__GET_PHOTO_MODE_CONTRAST);
		GRAPHICS.set_function("_0x9229ED770975BD9E", LUA_NATIVE_GRAPHICS__0x9229ED770975BD9E);
		GRAPHICS.set_function("START_PARTICLE_FX_NON_LOOPED_AT_COORD", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_NON_LOOPED_AT_COORD);
		GRAPHICS.set_function("START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD", LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD);
		GRAPHICS.set_function("START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE);
		GRAPHICS.set_function("START_PARTICLE_FX_NON_LOOPED_ON_ENTITY", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY);
		GRAPHICS.set_function("START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY", LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY);
		GRAPHICS.set_function("_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2", LUA_NATIVE_GRAPHICS__START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2);
		GRAPHICS.set_function("SET_PARTICLE_FX_NON_LOOPED_COLOUR", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_NON_LOOPED_COLOUR);
		GRAPHICS.set_function("SET_PARTICLE_FX_NON_LOOPED_ALPHA", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_NON_LOOPED_ALPHA);
		GRAPHICS.set_function("_SET_PARTICLE_FX_NON_LOOPED_EMITTER_SCALE", LUA_NATIVE_GRAPHICS__SET_PARTICLE_FX_NON_LOOPED_EMITTER_SCALE);
		GRAPHICS.set_function("START_PARTICLE_FX_LOOPED_AT_COORD", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_AT_COORD);
		GRAPHICS.set_function("START_PARTICLE_FX_LOOPED_ON_PED_BONE", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_ON_PED_BONE);
		GRAPHICS.set_function("START_PARTICLE_FX_LOOPED_ON_ENTITY", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_ON_ENTITY);
		GRAPHICS.set_function("START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE", LUA_NATIVE_GRAPHICS_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE);
		GRAPHICS.set_function("START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY", LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY);
		GRAPHICS.set_function("START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY_BONE", LUA_NATIVE_GRAPHICS_START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY_BONE);
		GRAPHICS.set_function("STOP_PARTICLE_FX_LOOPED", LUA_NATIVE_GRAPHICS_STOP_PARTICLE_FX_LOOPED);
		GRAPHICS.set_function("DOES_PARTICLE_FX_LOOPED_EXIST", LUA_NATIVE_GRAPHICS_DOES_PARTICLE_FX_LOOPED_EXIST);
		GRAPHICS.set_function("SET_PARTICLE_FX_LOOPED_OFFSETS", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_OFFSETS);
		GRAPHICS.set_function("SET_PARTICLE_FX_LOOPED_EVOLUTION", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_EVOLUTION);
		GRAPHICS.set_function("SET_PARTICLE_FX_LOOPED_COLOUR", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_COLOUR);
		GRAPHICS.set_function("SET_PARTICLE_FX_LOOPED_ALPHA", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_ALPHA);
		GRAPHICS.set_function("SET_PARTICLE_FX_LOOPED_SCALE", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_SCALE);
		GRAPHICS.set_function("SET_PARTICLE_FX_LOOPED_FAR_CLIP_DIST", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_LOOPED_FAR_CLIP_DIST);
		GRAPHICS.set_function("_SET_PARTICLE_FX_LOOPED_UPDATE_DISTANT_SMOKE", LUA_NATIVE_GRAPHICS__SET_PARTICLE_FX_LOOPED_UPDATE_DISTANT_SMOKE);
		GRAPHICS.set_function("REMOVE_PARTICLE_FX", LUA_NATIVE_GRAPHICS_REMOVE_PARTICLE_FX);
		GRAPHICS.set_function("REMOVE_PARTICLE_FX_FROM_ENTITY", LUA_NATIVE_GRAPHICS_REMOVE_PARTICLE_FX_FROM_ENTITY);
		GRAPHICS.set_function("REMOVE_PARTICLE_FX_IN_RANGE", LUA_NATIVE_GRAPHICS_REMOVE_PARTICLE_FX_IN_RANGE);
		GRAPHICS.set_function("USE_PARTICLE_FX_ASSET", LUA_NATIVE_GRAPHICS_USE_PARTICLE_FX_ASSET);
		GRAPHICS.set_function("SET_PARTICLE_FX_OVERRIDE", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_OVERRIDE);
		GRAPHICS.set_function("RESET_PARTICLE_FX_OVERRIDE", LUA_NATIVE_GRAPHICS_RESET_PARTICLE_FX_OVERRIDE);
		GRAPHICS.set_function("_0x4FB67D172C4476F3", LUA_NATIVE_GRAPHICS__0x4FB67D172C4476F3);
		GRAPHICS.set_function("SET_PARTICLE_FX_AMBIENT_COLOUR", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_AMBIENT_COLOUR);
		GRAPHICS.set_function("_0xD1472AFF30C103D6", LUA_NATIVE_GRAPHICS__0xD1472AFF30C103D6);
		GRAPHICS.set_function("SET_PARTICLE_FX_BULLET_IMPACT_SCALE", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_BULLET_IMPACT_SCALE);
		GRAPHICS.set_function("SET_PARTICLE_FX_BULLET_IMPACT_LODRANGE_SCALE", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_BULLET_IMPACT_LODRANGE_SCALE);
		GRAPHICS.set_function("_SET_SNIPER_GLINTS_ENABLED", LUA_NATIVE_GRAPHICS__SET_SNIPER_GLINTS_ENABLED);
		GRAPHICS.set_function("SET_PARTICLE_FX_FOOT_LODRANGE_SCALE", LUA_NATIVE_GRAPHICS_SET_PARTICLE_FX_FOOT_LODRANGE_SCALE);
		GRAPHICS.set_function("_0x4046493D2EEACA0E", LUA_NATIVE_GRAPHICS__0x4046493D2EEACA0E);
		GRAPHICS.set_function("SET_PICKUP_LIGHT", LUA_NATIVE_GRAPHICS_SET_PICKUP_LIGHT);
		GRAPHICS.set_function("_BLOCK_PICKUP_OBJECT_LIGHT", LUA_NATIVE_GRAPHICS__BLOCK_PICKUP_OBJECT_LIGHT);
		GRAPHICS.set_function("BLOCK_PICKUP_PLACEMENT_LIGHT", LUA_NATIVE_GRAPHICS_BLOCK_PICKUP_PLACEMENT_LIGHT);
		GRAPHICS.set_function("ALLOW_PICKUP_LIGHT_SYNC", LUA_NATIVE_GRAPHICS_ALLOW_PICKUP_LIGHT_SYNC);
		GRAPHICS.set_function("_SET_PEARLESCENT_FX_ENABLED", LUA_NATIVE_GRAPHICS__SET_PEARLESCENT_FX_ENABLED);
		GRAPHICS.set_function("REMOVE_DECALS_IN_RANGE", LUA_NATIVE_GRAPHICS_REMOVE_DECALS_IN_RANGE);
		GRAPHICS.set_function("REMOVE_DECALS_FROM_OBJECT", LUA_NATIVE_GRAPHICS_REMOVE_DECALS_FROM_OBJECT);
		GRAPHICS.set_function("ADD_DECAL", LUA_NATIVE_GRAPHICS_ADD_DECAL);
		GRAPHICS.set_function("_ADD_BLOOD_POOL", LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOL);
		GRAPHICS.set_function("_ADD_BLOOD_POOL_2", LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOL_2);
		GRAPHICS.set_function("_ADD_BLOOD_POOLS_FOR_PED", LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOLS_FOR_PED);
		GRAPHICS.set_function("_ADD_BLOOD_POOLS_FOR_PED_WITH_PARAMS", LUA_NATIVE_GRAPHICS__ADD_BLOOD_POOLS_FOR_PED_WITH_PARAMS);
		GRAPHICS.set_function("START_PETROL_TRAIL_DECALS", LUA_NATIVE_GRAPHICS_START_PETROL_TRAIL_DECALS);
		GRAPHICS.set_function("ADD_PETROL_TRAIL_DECAL_INFO", LUA_NATIVE_GRAPHICS_ADD_PETROL_TRAIL_DECAL_INFO);
		GRAPHICS.set_function("END_PETROL_TRAIL_DECALS", LUA_NATIVE_GRAPHICS_END_PETROL_TRAIL_DECALS);
		GRAPHICS.set_function("_0xE63D68F455CA0B47", LUA_NATIVE_GRAPHICS__0xE63D68F455CA0B47);
		GRAPHICS.set_function("REMOVE_DECAL", LUA_NATIVE_GRAPHICS_REMOVE_DECAL);
		GRAPHICS.set_function("IS_DECAL_ALIVE", LUA_NATIVE_GRAPHICS_IS_DECAL_ALIVE);
		GRAPHICS.set_function("SET_DISABLE_PETROL_DECALS_IGNITING_THIS_FRAME", LUA_NATIVE_GRAPHICS_SET_DISABLE_PETROL_DECALS_IGNITING_THIS_FRAME);
		GRAPHICS.set_function("_0xB032C085D9A03907", LUA_NATIVE_GRAPHICS__0xB032C085D9A03907);
		GRAPHICS.set_function("_0xFB680A9B33D0EDBE", LUA_NATIVE_GRAPHICS__0xFB680A9B33D0EDBE);
		GRAPHICS.set_function("_0x41F88A85A579A61D", LUA_NATIVE_GRAPHICS__0x41F88A85A579A61D);
		GRAPHICS.set_function("_BLOOD_TRAIL_FOR_WAYPOINT", LUA_NATIVE_GRAPHICS__BLOOD_TRAIL_FOR_WAYPOINT);
		GRAPHICS.set_function("_ADD_BLOOD_TRAIL_POINT", LUA_NATIVE_GRAPHICS__ADD_BLOOD_TRAIL_POINT);
		GRAPHICS.set_function("_0x812C1563185C6FB2", LUA_NATIVE_GRAPHICS__0x812C1563185C6FB2);
		GRAPHICS.set_function("_0x4BD66B4E3427689B", LUA_NATIVE_GRAPHICS__0x4BD66B4E3427689B);
		GRAPHICS.set_function("_ADD_BLOOD_TRAIL_SPLAT", LUA_NATIVE_GRAPHICS__ADD_BLOOD_TRAIL_SPLAT);
		GRAPHICS.set_function("_0xF2F543D48F319A3A", LUA_NATIVE_GRAPHICS__0xF2F543D48F319A3A);
		GRAPHICS.set_function("_0x1460B644397453EB", LUA_NATIVE_GRAPHICS__0x1460B644397453EB);
		GRAPHICS.set_function("_DISABLE_FAR_ARTIFICIAL_LIGHTS", LUA_NATIVE_GRAPHICS__DISABLE_FAR_ARTIFICIAL_LIGHTS);
		GRAPHICS.set_function("_0x453D16D41FC51D3E", LUA_NATIVE_GRAPHICS__0x453D16D41FC51D3E);
		GRAPHICS.set_function("_0xC06F2F45A73EABCD", LUA_NATIVE_GRAPHICS__0xC06F2F45A73EABCD);
		GRAPHICS.set_function("SET_TIMECYCLE_MODIFIER", LUA_NATIVE_GRAPHICS_SET_TIMECYCLE_MODIFIER);
		GRAPHICS.set_function("SET_TIMECYCLE_MODIFIER_STRENGTH", LUA_NATIVE_GRAPHICS_SET_TIMECYCLE_MODIFIER_STRENGTH);
		GRAPHICS.set_function("SET_TRANSITION_TIMECYCLE_MODIFIER", LUA_NATIVE_GRAPHICS_SET_TRANSITION_TIMECYCLE_MODIFIER);
		GRAPHICS.set_function("SET_TRANSITION_OUT_OF_TIMECYCLE_MODIFIER", LUA_NATIVE_GRAPHICS_SET_TRANSITION_OUT_OF_TIMECYCLE_MODIFIER);
		GRAPHICS.set_function("CLEAR_TIMECYCLE_MODIFIER", LUA_NATIVE_GRAPHICS_CLEAR_TIMECYCLE_MODIFIER);
		GRAPHICS.set_function("GET_TIMECYCLE_MODIFIER_INDEX", LUA_NATIVE_GRAPHICS_GET_TIMECYCLE_MODIFIER_INDEX);
		GRAPHICS.set_function("GET_TIMECYCLE_TRANSITION_MODIFIER_INDEX", LUA_NATIVE_GRAPHICS_GET_TIMECYCLE_TRANSITION_MODIFIER_INDEX);
		GRAPHICS.set_function("_0x67B0778C62E74423", LUA_NATIVE_GRAPHICS__0x67B0778C62E74423);
		GRAPHICS.set_function("_0x6C03118E9E5C1A14", LUA_NATIVE_GRAPHICS__0x6C03118E9E5C1A14);
		GRAPHICS.set_function("_GET_MODIFIED_VISIBILITY_DISTANCE", LUA_NATIVE_GRAPHICS__GET_MODIFIED_VISIBILITY_DISTANCE);
		GRAPHICS.set_function("ENABLE_MOON_CYCLE_OVERRIDE", LUA_NATIVE_GRAPHICS_ENABLE_MOON_CYCLE_OVERRIDE);
		GRAPHICS.set_function("SET_TV_CHANNEL", LUA_NATIVE_GRAPHICS_SET_TV_CHANNEL);
		GRAPHICS.set_function("GET_TV_CHANNEL", LUA_NATIVE_GRAPHICS_GET_TV_CHANNEL);
		GRAPHICS.set_function("SET_TV_VOLUME", LUA_NATIVE_GRAPHICS_SET_TV_VOLUME);
		GRAPHICS.set_function("DRAW_TV_CHANNEL", LUA_NATIVE_GRAPHICS_DRAW_TV_CHANNEL);
		GRAPHICS.set_function("SET_TV_CHANNEL_PLAYLIST", LUA_NATIVE_GRAPHICS_SET_TV_CHANNEL_PLAYLIST);
		GRAPHICS.set_function("IS_TVSHOW_CURRENTLY_PLAYING", LUA_NATIVE_GRAPHICS_IS_TVSHOW_CURRENTLY_PLAYING);
		GRAPHICS.set_function("_0x5C674EB487891F6B", LUA_NATIVE_GRAPHICS__0x5C674EB487891F6B);
		GRAPHICS.set_function("ENABLE_MOVIE_SUBTITLES", LUA_NATIVE_GRAPHICS_ENABLE_MOVIE_SUBTITLES);
		GRAPHICS.set_function("_0x32DE2BFFDA43E62A", LUA_NATIVE_GRAPHICS__0x32DE2BFFDA43E62A);
		GRAPHICS.set_function("_0xD543487A1F12828F", LUA_NATIVE_GRAPHICS__0xD543487A1F12828F);
		GRAPHICS.set_function("_0xD9BC98B55BCFAA9B", LUA_NATIVE_GRAPHICS__0xD9BC98B55BCFAA9B);
		GRAPHICS.set_function("_0x48FE0DB54045B975", LUA_NATIVE_GRAPHICS__0x48FE0DB54045B975);
		GRAPHICS.set_function("_0x735762E8D7573E42", LUA_NATIVE_GRAPHICS__0x735762E8D7573E42);
		GRAPHICS.set_function("_0x981C7D863980FA51", LUA_NATIVE_GRAPHICS__0x981C7D863980FA51);
		GRAPHICS.set_function("_ANIMPOSTFX_PRELOAD_POSTFX", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PRELOAD_POSTFX);
		GRAPHICS.set_function("_ANIMPOSTFX_HAS_LOADED", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_HAS_LOADED);
		GRAPHICS.set_function("_ANIMPOSTFX_SET_TO_UNLOAD", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_TO_UNLOAD);
		GRAPHICS.set_function("ANIMPOSTFX_PLAY", LUA_NATIVE_GRAPHICS_ANIMPOSTFX_PLAY);
		GRAPHICS.set_function("_ANIMPOSTFX_PLAY_TIMED", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PLAY_TIMED);
		GRAPHICS.set_function("ANIMPOSTFX_STOP", LUA_NATIVE_GRAPHICS_ANIMPOSTFX_STOP);
		GRAPHICS.set_function("_0x26DD2FB0A88CC412", LUA_NATIVE_GRAPHICS__0x26DD2FB0A88CC412);
		GRAPHICS.set_function("_ANIMPOSTFX_CLEAR_EFFECT", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_CLEAR_EFFECT);
		GRAPHICS.set_function("ANIMPOSTFX_IS_RUNNING", LUA_NATIVE_GRAPHICS_ANIMPOSTFX_IS_RUNNING);
		GRAPHICS.set_function("_ANIMPOSTFX_IS_TAG_PLAYING", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_IS_TAG_PLAYING);
		GRAPHICS.set_function("ANIMPOSTFX_STOP_ALL", LUA_NATIVE_GRAPHICS_ANIMPOSTFX_STOP_ALL);
		GRAPHICS.set_function("_ANIMPOSTFX_STOP_TAG", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_STOP_TAG);
		GRAPHICS.set_function("_ANIMPOSTFX_SET_STRENGTH", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_STRENGTH);
		GRAPHICS.set_function("_ANIMPOSTFX_SET_POTENCY", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_POTENCY);
		GRAPHICS.set_function("_ANIMPOSTFX_SET_POSTFX_COLOR", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_SET_POSTFX_COLOR);
		GRAPHICS.set_function("_0xB958D97A0DFAA0C2", LUA_NATIVE_GRAPHICS__0xB958D97A0DFAA0C2);
		GRAPHICS.set_function("_0xA201A3D0AC087C37", LUA_NATIVE_GRAPHICS__0xA201A3D0AC087C37);
		GRAPHICS.set_function("_0xFBF161FCFEC8589E", LUA_NATIVE_GRAPHICS__0xFBF161FCFEC8589E);
		GRAPHICS.set_function("_ANIMPOSTFX_GET_STACKHASH", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_GET_STACKHASH);
		GRAPHICS.set_function("_ANIMPOSTFX_PRELOAD_POSTFX_BY_STACKHASH", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PRELOAD_POSTFX_BY_STACKHASH);
		GRAPHICS.set_function("ANIMPOSTFX_IS_PRELOADING_BY_STACKHASH", LUA_NATIVE_GRAPHICS_ANIMPOSTFX_IS_PRELOADING_BY_STACKHASH);
		GRAPHICS.set_function("_0x38D9D50F2085E9B3", LUA_NATIVE_GRAPHICS__0x38D9D50F2085E9B3);
		GRAPHICS.set_function("_ANIMPOSTFX_PLAY_TAG", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_PLAY_TAG);
		GRAPHICS.set_function("_0xC76FC4C2FC5F4405", LUA_NATIVE_GRAPHICS__0xC76FC4C2FC5F4405);
		GRAPHICS.set_function("_ANIMPOSTFX_STOP_STACKHASH_POSTFX", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_STOP_STACKHASH_POSTFX);
		GRAPHICS.set_function("_ANIMPOSTFX_IS_STACKHASH_PLAYING", LUA_NATIVE_GRAPHICS__ANIMPOSTFX_IS_STACKHASH_PLAYING);
		GRAPHICS.set_function("_0xE75CDDEBF618C8FF", LUA_NATIVE_GRAPHICS__0xE75CDDEBF618C8FF);
		GRAPHICS.set_function("_0x71845905BCCDE781", LUA_NATIVE_GRAPHICS__0x71845905BCCDE781);
		GRAPHICS.set_function("ANIMPOSTFX_HAS_EVENT_TRIGGERED_BY_STACKHASH", LUA_NATIVE_GRAPHICS_ANIMPOSTFX_HAS_EVENT_TRIGGERED_BY_STACKHASH);
		GRAPHICS.set_function("_0xFF584F097C17FA8F", LUA_NATIVE_GRAPHICS__0xFF584F097C17FA8F);
		GRAPHICS.set_function("_0x3DA7A10583A4BEC0", LUA_NATIVE_GRAPHICS__0x3DA7A10583A4BEC0);
		GRAPHICS.set_function("_0xC37792A3F9C90771", LUA_NATIVE_GRAPHICS__0xC37792A3F9C90771);
		GRAPHICS.set_function("_0xA0F4D12D6042F6D5", LUA_NATIVE_GRAPHICS__0xA0F4D12D6042F6D5);
		GRAPHICS.set_function("_0x8996FA6AD9FE4E90", LUA_NATIVE_GRAPHICS__0x8996FA6AD9FE4E90);
		GRAPHICS.set_function("_SET_ENTITY_RENDER_GUARMA_SHIP", LUA_NATIVE_GRAPHICS__SET_ENTITY_RENDER_GUARMA_SHIP);
		GRAPHICS.set_function("PEDSHOT_IS_AVAILABLE", LUA_NATIVE_GRAPHICS_PEDSHOT_IS_AVAILABLE);
		GRAPHICS.set_function("_0xFD05B1DDE83749FA", LUA_NATIVE_GRAPHICS__0xFD05B1DDE83749FA);
		GRAPHICS.set_function("_PEDSHOT_FINISH_CLEANUP_DATA", LUA_NATIVE_GRAPHICS__PEDSHOT_FINISH_CLEANUP_DATA);
		GRAPHICS.set_function("_PEDSHOT_PREVIOUS_PERSONA_PHOTO_DATA_CLEANUP", LUA_NATIVE_GRAPHICS__PEDSHOT_PREVIOUS_PERSONA_PHOTO_DATA_CLEANUP);
		GRAPHICS.set_function("_PEDSHOT_INIT_CLEANUP_DATA", LUA_NATIVE_GRAPHICS__PEDSHOT_INIT_CLEANUP_DATA);
		GRAPHICS.set_function("_PEDSHOT_GENERATE_PERSONA_PHOTO", LUA_NATIVE_GRAPHICS__PEDSHOT_GENERATE_PERSONA_PHOTO);
		GRAPHICS.set_function("_PEDSHOT_SET_PERSONA_PHOTO_TYPE", LUA_NATIVE_GRAPHICS__PEDSHOT_SET_PERSONA_PHOTO_TYPE);
		GRAPHICS.set_function("_0xA1A86055792FB249", LUA_NATIVE_GRAPHICS__0xA1A86055792FB249);
		GRAPHICS.set_function("_0x402E1A61D2587FCD", LUA_NATIVE_GRAPHICS__0x402E1A61D2587FCD);
		GRAPHICS.set_function("_0x5C9C3A466B3296A8", LUA_NATIVE_GRAPHICS__0x5C9C3A466B3296A8);
		GRAPHICS.set_function("_0xA15CCAB8AD038291", LUA_NATIVE_GRAPHICS__0xA15CCAB8AD038291);
		GRAPHICS.set_function("_0x285438C26C732F9D", LUA_NATIVE_GRAPHICS__0x285438C26C732F9D);
		GRAPHICS.set_function("_SET_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_STATE", LUA_NATIVE_GRAPHICS__SET_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_STATE);
		GRAPHICS.set_function("_IS_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_ENABLED", LUA_NATIVE_GRAPHICS__IS_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_ENABLED);
		GRAPHICS.set_function("_GET_PROXY_INTERIOR_INDEX", LUA_NATIVE_GRAPHICS__GET_PROXY_INTERIOR_INDEX);
		GRAPHICS.set_function("_0x9D1B0B5066205692", LUA_NATIVE_GRAPHICS__0x9D1B0B5066205692);
		GRAPHICS.set_function("_0xC489FE31AC726512", LUA_NATIVE_GRAPHICS__0xC489FE31AC726512);
		GRAPHICS.set_function("_SET_CLOUD_LAYER", LUA_NATIVE_GRAPHICS__SET_CLOUD_LAYER);
		GRAPHICS.set_function("_SET_CLOUD_NOISE", LUA_NATIVE_GRAPHICS__SET_CLOUD_NOISE);
		GRAPHICS.set_function("_SET_CLOUD_POSITION", LUA_NATIVE_GRAPHICS__SET_CLOUD_POSITION);
		GRAPHICS.set_function("_SET_CLOUD_HEIGHT", LUA_NATIVE_GRAPHICS__SET_CLOUD_HEIGHT);
		GRAPHICS.set_function("_0x085C5B61A0114F32", LUA_NATIVE_GRAPHICS__0x085C5B61A0114F32);
		GRAPHICS.set_function("_0x1FF8731BE1DFC0C0", LUA_NATIVE_GRAPHICS__0x1FF8731BE1DFC0C0);
		GRAPHICS.set_function("_0xFC9B53C072F418E0", LUA_NATIVE_GRAPHICS__0xFC9B53C072F418E0);
		GRAPHICS.set_function("_0x94B261F1F35293E1", LUA_NATIVE_GRAPHICS__0x94B261F1F35293E1);
		GRAPHICS.set_function("ENABLE_ENTITYMASK", LUA_NATIVE_GRAPHICS_ENABLE_ENTITYMASK);
		GRAPHICS.set_function("DISABLE_ENTITYMASK", LUA_NATIVE_GRAPHICS_DISABLE_ENTITYMASK);
		GRAPHICS.set_function("_ADD_ENTITY_TO_ENTITY_MASK", LUA_NATIVE_GRAPHICS__ADD_ENTITY_TO_ENTITY_MASK);
		GRAPHICS.set_function("_ADD_ENTITY_TO_ENTITY_MASK_WITH_INTENSITY", LUA_NATIVE_GRAPHICS__ADD_ENTITY_TO_ENTITY_MASK_WITH_INTENSITY);
		GRAPHICS.set_function("_REMOVE_ENTITY_FROM_ENTITY_MASK", LUA_NATIVE_GRAPHICS__REMOVE_ENTITY_FROM_ENTITY_MASK);
		GRAPHICS.set_function("_GET_ENTITY_MASK_LAYERS", LUA_NATIVE_GRAPHICS__GET_ENTITY_MASK_LAYERS);
		GRAPHICS.set_function("_SET_ENTITY_MASK_LAYERS", LUA_NATIVE_GRAPHICS__SET_ENTITY_MASK_LAYERS);
		GRAPHICS.set_function("_SET_ENTITY_AURA", LUA_NATIVE_GRAPHICS__SET_ENTITY_AURA);
		GRAPHICS.set_function("_RESET_ENTITY_AURA", LUA_NATIVE_GRAPHICS__RESET_ENTITY_AURA);
		GRAPHICS.set_function("_SET_SNOW_COVERAGE_TYPE", LUA_NATIVE_GRAPHICS__SET_SNOW_COVERAGE_TYPE);
		GRAPHICS.set_function("_0x519928DF02EB5101", LUA_NATIVE_GRAPHICS__0x519928DF02EB5101);
		GRAPHICS.set_function("_0x1C6306E5BC25C29C", LUA_NATIVE_GRAPHICS__0x1C6306E5BC25C29C);
	}
}
