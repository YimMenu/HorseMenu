#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_CAM_RENDER_SCRIPT_CAMS(bool bSetActive, bool DoGameCamInterp, int Duration, bool bShouldLockInterpolationSourceFrame, bool bShouldApplyAcrossAllThreads, int RenderingOptions)
	{
		CAM::RENDER_SCRIPT_CAMS(bSetActive, DoGameCamInterp, Duration, bShouldLockInterpolationSourceFrame, bShouldApplyAcrossAllThreads, RenderingOptions);
	}

	static void LUA_NATIVE_CAM_STOP_RENDERING_SCRIPT_CAMS_USING_CATCH_UP(bool bShouldApplyAcrossAllThreads, float DistanceToBlend, int BlendType, bool p3, bool p4, bool p5)
	{
		CAM::STOP_RENDERING_SCRIPT_CAMS_USING_CATCH_UP(bShouldApplyAcrossAllThreads, DistanceToBlend, BlendType, p3, p4, p5);
	}

	static Cam LUA_NATIVE_CAM_CREATE_CAM(sol::stack_object CameraName, bool StartActivated)
	{
		auto retval = CAM::CREATE_CAM(CameraName.is<const char*>() ? CameraName.as<const char*>() : nullptr, StartActivated);
		return retval;
	}

	static Cam LUA_NATIVE_CAM_CREATE_CAM_WITH_PARAMS(sol::stack_object CameraName, float vecPosX, float vecPosY, float vecPosZ, float vecRotX, float vecRotY, float vecRotZ, float FOV, bool StartActivated, int RotOrder)
	{
		auto retval = CAM::CREATE_CAM_WITH_PARAMS(CameraName.is<const char*>() ? CameraName.as<const char*>() : nullptr, vecPosX, vecPosY, vecPosZ, vecRotX, vecRotY, vecRotZ, FOV, StartActivated, RotOrder);
		return retval;
	}

	static Cam LUA_NATIVE_CAM_CREATE_CAMERA(Hash Camera, bool StartActivated)
	{
		auto retval = CAM::CREATE_CAMERA(Camera, StartActivated);
		return retval;
	}

	static Cam LUA_NATIVE_CAM_CREATE_CAMERA_WITH_PARAMS(Hash Camera, float vecPosX, float vecPosY, float vecPosZ, float vecRotX, float vecRotY, float vecRotZ, float FOV, bool StartActivated, int RotOrder)
	{
		auto retval = CAM::CREATE_CAMERA_WITH_PARAMS(Camera, vecPosX, vecPosY, vecPosZ, vecRotX, vecRotY, vecRotZ, FOV, StartActivated, RotOrder);
		return retval;
	}

	static void LUA_NATIVE_CAM_DESTROY_CAM(Cam CameraIndex, bool bShouldApplyAcrossAllThreads)
	{
		CAM::DESTROY_CAM(CameraIndex, bShouldApplyAcrossAllThreads);
	}

	static void LUA_NATIVE_CAM_DESTROY_ALL_CAMS(bool bShouldApplyAcrossAllThreads)
	{
		CAM::DESTROY_ALL_CAMS(bShouldApplyAcrossAllThreads);
	}

	static bool LUA_NATIVE_CAM_DOES_CAM_EXIST(Cam CameraIndex)
	{
		auto retval = (bool)CAM::DOES_CAM_EXIST(CameraIndex);
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_CAM_ACTIVE(Cam CameraIndex, bool bActiveState)
	{
		CAM::SET_CAM_ACTIVE(CameraIndex, bActiveState);
	}

	static bool LUA_NATIVE_CAM_IS_CAM_ACTIVE(Cam CameraIndex)
	{
		auto retval = (bool)CAM::IS_CAM_ACTIVE(CameraIndex);
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_CAM_RENDERING(Cam CamIndex)
	{
		auto retval = (bool)CAM::IS_CAM_RENDERING(CamIndex);
		return retval;
	}

	static Cam LUA_NATIVE_CAM_GET_RENDERING_CAM()
	{
		auto retval = CAM::GET_RENDERING_CAM();
		return retval;
	}

	static Vector3 LUA_NATIVE_CAM_GET_CAM_COORD(Cam CameraIndex)
	{
		auto retval = CAM::GET_CAM_COORD(CameraIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_CAM_GET_CAM_ROT(Cam CameraIndex, int RotOrder)
	{
		auto retval = CAM::GET_CAM_ROT(CameraIndex, RotOrder);
		return retval;
	}

	static float LUA_NATIVE_CAM_GET_CAM_FOV(Cam CameraIndex)
	{
		auto retval = CAM::GET_CAM_FOV(CameraIndex);
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_CAM_PARAMS(Cam CameraIndex, float vPosX, float vPosY, float vPosZ, float vRotX, float vRotY, float vRotZ, float FOV, int Duration, int GraphTypePos, int GraphTypeRot, int RotOrder, bool p12, bool p13)
	{
		CAM::SET_CAM_PARAMS(CameraIndex, vPosX, vPosY, vPosZ, vRotX, vRotY, vRotZ, FOV, Duration, GraphTypePos, GraphTypeRot, RotOrder, p12, p13);
	}

	static void LUA_NATIVE_CAM_SET_CAM_COORD(Cam CameraIndex, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ)
	{
		CAM::SET_CAM_COORD(CameraIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ);
	}

	static void LUA_NATIVE_CAM_SET_CAM_ROT(Cam CameraIndex, float VecNewRotX, float VecNewRotY, float VecNewRotZ, int RotOrder)
	{
		CAM::SET_CAM_ROT(CameraIndex, VecNewRotX, VecNewRotY, VecNewRotZ, RotOrder);
	}

	static void LUA_NATIVE_CAM_SET_CAM_FOV(Cam CameraIndex, float FOV)
	{
		CAM::SET_CAM_FOV(CameraIndex, FOV);
	}

	static void LUA_NATIVE_CAM_SET_CAM_NEAR_CLIP(Cam CameraIndex, float NearClip)
	{
		CAM::SET_CAM_NEAR_CLIP(CameraIndex, NearClip);
	}

	static void LUA_NATIVE_CAM_SET_CAM_FAR_CLIP(Cam CameraIndex, float FarClip)
	{
		CAM::SET_CAM_FAR_CLIP(CameraIndex, FarClip);
	}

	static void LUA_NATIVE_CAM_SET_CAM_MOTION_BLUR_STRENGTH(Cam CameraIndex, float Strength)
	{
		CAM::SET_CAM_MOTION_BLUR_STRENGTH(CameraIndex, Strength);
	}

	static void LUA_NATIVE_CAM__0xFC3F638BE2B6BB02()
	{
		CAM::_0xFC3F638BE2B6BB02();
	}

	static void LUA_NATIVE_CAM__0xE4B7945EF4F1BFB2(Cam cam, uintptr_t args)
	{
		CAM::_0xE4B7945EF4F1BFB2(cam, (Any*)args);
	}

	static void LUA_NATIVE_CAM__0x1FC6C727D30FFDDE(Any p0)
	{
		CAM::_0x1FC6C727D30FFDDE(p0);
	}

	static void LUA_NATIVE_CAM_ATTACH_CAM_TO_ENTITY(Cam CameraIndex, Entity EntityIndex, float vecOffsetX, float vecOffsetY, float vecOffsetZ, bool bOffsetIsRelative)
	{
		CAM::ATTACH_CAM_TO_ENTITY(CameraIndex, EntityIndex, vecOffsetX, vecOffsetY, vecOffsetZ, bOffsetIsRelative);
	}

	static void LUA_NATIVE_CAM_ATTACH_CAM_TO_PED_BONE(Cam CameraIndex, Ped PedIndex, int BoneTag, float vecOffsetX, float vecOffsetY, float vecOffsetZ, bool bOffsetIsRelative)
	{
		CAM::ATTACH_CAM_TO_PED_BONE(CameraIndex, PedIndex, BoneTag, vecOffsetX, vecOffsetY, vecOffsetZ, bOffsetIsRelative);
	}

	static void LUA_NATIVE_CAM_DETACH_CAM(Cam CameraIndex)
	{
		CAM::DETACH_CAM(CameraIndex);
	}

	static void LUA_NATIVE_CAM_POINT_CAM_AT_COORD(Cam CameraIndex, float VecCoorsX, float VecCoorsY, float VecCoorsZ)
	{
		CAM::POINT_CAM_AT_COORD(CameraIndex, VecCoorsX, VecCoorsY, VecCoorsZ);
	}

	static void LUA_NATIVE_CAM_POINT_CAM_AT_ENTITY(Cam CameraIndex, Entity EntityIndex, float vecOffsetX, float vecOffsetY, float vecOffsetZ, bool bOffsetIsRelative)
	{
		CAM::POINT_CAM_AT_ENTITY(CameraIndex, EntityIndex, vecOffsetX, vecOffsetY, vecOffsetZ, bOffsetIsRelative);
	}

	static void LUA_NATIVE_CAM_STOP_CAM_POINTING(Cam CameraIndex)
	{
		CAM::STOP_CAM_POINTING(CameraIndex);
	}

	static void LUA_NATIVE_CAM__SET_CAM_FOCUS_DISTANCE(Cam cam, float distance)
	{
		CAM::_SET_CAM_FOCUS_DISTANCE(cam, distance);
	}

	static void LUA_NATIVE_CAM__PAUSE_CAMERA_FOCUS(Cam cam, bool pause)
	{
		CAM::_PAUSE_CAMERA_FOCUS(cam, pause);
	}

	static void LUA_NATIVE_CAM_SET_CAM_AFFECTS_AIMING(Cam CameraIndex, bool bState)
	{
		CAM::SET_CAM_AFFECTS_AIMING(CameraIndex, bState);
	}

	static void LUA_NATIVE_CAM_SET_CAM_CONTROLS_MINI_MAP_HEADING(Cam CameraIndex, bool bState)
	{
		CAM::SET_CAM_CONTROLS_MINI_MAP_HEADING(CameraIndex, bState);
	}

	static void LUA_NATIVE_CAM_ALLOW_MOTION_BLUR_DECAY(Cam CameraIndex, bool enable)
	{
		CAM::ALLOW_MOTION_BLUR_DECAY(CameraIndex, enable);
	}

	static void LUA_NATIVE_CAM_ADD_CAM_SPLINE_NODE(Cam CameraIndex, float vPosX, float vPosY, float vPosZ, float vRotX, float vRotY, float vRotZ, int iDuration, int Flags, int RotOrder)
	{
		CAM::ADD_CAM_SPLINE_NODE(CameraIndex, vPosX, vPosY, vPosZ, vRotX, vRotY, vRotZ, iDuration, Flags, RotOrder);
	}

	static void LUA_NATIVE_CAM_SET_CAM_SPLINE_PHASE(Cam CameraIndex, float phase)
	{
		CAM::SET_CAM_SPLINE_PHASE(CameraIndex, phase);
	}

	static float LUA_NATIVE_CAM_GET_CAM_SPLINE_PHASE(Cam CameraIndex)
	{
		auto retval = CAM::GET_CAM_SPLINE_PHASE(CameraIndex);
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_CAM_SPLINE_DURATION(Cam CameraIndex, int Duration)
	{
		CAM::SET_CAM_SPLINE_DURATION(CameraIndex, Duration);
	}

	static void LUA_NATIVE_CAM_SET_CAM_SPLINE_SMOOTHING_STYLE(Cam CameraIndex, int SmoothingStyle)
	{
		CAM::SET_CAM_SPLINE_SMOOTHING_STYLE(CameraIndex, SmoothingStyle);
	}

	static void LUA_NATIVE_CAM_SET_CAM_ACTIVE_WITH_INTERP(Cam DestinationCam, Cam OriginCam, int Duration, int GraphTypePos, int GraphTypeRot)
	{
		CAM::SET_CAM_ACTIVE_WITH_INTERP(DestinationCam, OriginCam, Duration, GraphTypePos, GraphTypeRot);
	}

	static bool LUA_NATIVE_CAM_IS_CAM_INTERPOLATING(Cam CameraIndex)
	{
		auto retval = (bool)CAM::IS_CAM_INTERPOLATING(CameraIndex);
		return retval;
	}

	static void LUA_NATIVE_CAM_SHAKE_CAM(Cam CameraIndex, sol::stack_object ShakeName, float fAmplitudeScalar)
	{
		CAM::SHAKE_CAM(CameraIndex, ShakeName.is<const char*>() ? ShakeName.as<const char*>() : nullptr, fAmplitudeScalar);
	}

	static bool LUA_NATIVE_CAM_IS_CAM_SHAKING(Cam CameraIndex)
	{
		auto retval = (bool)CAM::IS_CAM_SHAKING(CameraIndex);
		return retval;
	}

	static void LUA_NATIVE_CAM_STOP_CAM_SHAKING(Cam CameraIndex, bool bStopImmediately)
	{
		CAM::STOP_CAM_SHAKING(CameraIndex, bStopImmediately);
	}

	static bool LUA_NATIVE_CAM_PLAY_CAM_ANIM(Cam CameraIndex, sol::stack_object AnimName, sol::stack_object AnimDictName, float vOriginPositionX, float vOriginPositionY, float vOriginPositionZ, float vOriginRotationX, float vOriginRotationY, float vOriginRotationZ, int AnimFlags, int RotOrder)
	{
		auto retval = (bool)CAM::PLAY_CAM_ANIM(CameraIndex, AnimName.is<const char*>() ? AnimName.as<const char*>() : nullptr, AnimDictName.is<const char*>() ? AnimDictName.as<const char*>() : nullptr, vOriginPositionX, vOriginPositionY, vOriginPositionZ, vOriginRotationX, vOriginRotationY, vOriginRotationZ, AnimFlags, RotOrder);
		return retval;
	}

	static void LUA_NATIVE_CAM__0xCF69EA05CD9C33C9()
	{
		CAM::_0xCF69EA05CD9C33C9();
	}

	static bool LUA_NATIVE_CAM__IS_ANIM_SCENE_CAM_ACTIVE()
	{
		auto retval = (bool)CAM::_IS_ANIM_SCENE_CAM_ACTIVE();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_SCREEN_FADED_OUT()
	{
		auto retval = (bool)CAM::IS_SCREEN_FADED_OUT();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_SCREEN_FADED_IN()
	{
		auto retval = (bool)CAM::IS_SCREEN_FADED_IN();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_SCREEN_FADING_OUT()
	{
		auto retval = (bool)CAM::IS_SCREEN_FADING_OUT();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_SCREEN_FADING_IN()
	{
		auto retval = (bool)CAM::IS_SCREEN_FADING_IN();
		return retval;
	}

	static void LUA_NATIVE_CAM_DO_SCREEN_FADE_IN(int time)
	{
		CAM::DO_SCREEN_FADE_IN(time);
	}

	static void LUA_NATIVE_CAM_DO_SCREEN_FADE_OUT(int time)
	{
		CAM::DO_SCREEN_FADE_OUT(time);
	}

	static bool LUA_NATIVE_CAM_HAS_LETTER_BOX()
	{
		auto retval = (bool)CAM::HAS_LETTER_BOX();
		return retval;
	}

	static void LUA_NATIVE_CAM__REQUEST_LETTER_BOX_NOW(bool p0, bool p1)
	{
		CAM::_REQUEST_LETTER_BOX_NOW(p0, p1);
	}

	static void LUA_NATIVE_CAM__REQUEST_LETTER_BOX_OVERTIME(int p0, int p1, bool p2, int p3, bool p4, bool p5)
	{
		CAM::_REQUEST_LETTER_BOX_OVERTIME(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_CAM__FORCE_LETTER_BOX_THIS_UPDATE()
	{
		CAM::_FORCE_LETTER_BOX_THIS_UPDATE();
	}

	static float LUA_NATIVE_CAM_GET_LETTER_BOX_RATIO()
	{
		auto retval = CAM::GET_LETTER_BOX_RATIO();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x73FF6BE63DC18819()
	{
		auto retval = CAM::_0x73FF6BE63DC18819();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x450769C833D58844()
	{
		auto retval = CAM::_0x450769C833D58844();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_WIDESCREEN_BORDERS(bool bSet, int Duration)
	{
		CAM::SET_WIDESCREEN_BORDERS(bSet, Duration);
	}

	static Vector3 LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_COORD()
	{
		auto retval = CAM::GET_GAMEPLAY_CAM_COORD();
		return retval;
	}

	static Vector3 LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_ROT(int RotOrder)
	{
		auto retval = CAM::GET_GAMEPLAY_CAM_ROT(RotOrder);
		return retval;
	}

	static float LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_FOV()
	{
		auto retval = CAM::GET_GAMEPLAY_CAM_FOV();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_MAX_MOTION_BLUR_STRENGTH_THIS_UPDATE(float maxStrength)
	{
		CAM::SET_GAMEPLAY_CAM_MAX_MOTION_BLUR_STRENGTH_THIS_UPDATE(maxStrength);
	}

	static float LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_RELATIVE_HEADING()
	{
		auto retval = CAM::GET_GAMEPLAY_CAM_RELATIVE_HEADING();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_RELATIVE_HEADING(float heading, float p1)
	{
		CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(heading, p1);
	}

	static float LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_RELATIVE_PITCH()
	{
		auto retval = CAM::GET_GAMEPLAY_CAM_RELATIVE_PITCH();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_RELATIVE_PITCH(float pitch, float smoothRate)
	{
		CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(pitch, smoothRate);
	}

	static void LUA_NATIVE_CAM__0x0961B089947BA6D0(Any p0)
	{
		CAM::_0x0961B089947BA6D0(p0);
	}

	static void LUA_NATIVE_CAM__0x04084490CC302CFB()
	{
		CAM::_0x04084490CC302CFB();
	}

	static void LUA_NATIVE_CAM_SET_SCRIPTED_CAMERA_IS_FIRST_PERSON_THIS_FRAME(bool isFirstPersonThisFrame)
	{
		CAM::SET_SCRIPTED_CAMERA_IS_FIRST_PERSON_THIS_FRAME(isFirstPersonThisFrame);
	}

	static bool LUA_NATIVE_CAM__IS_IN_FULL_FIRST_PERSON_MODE()
	{
		auto retval = (bool)CAM::_IS_IN_FULL_FIRST_PERSON_MODE();
		return retval;
	}

	static void LUA_NATIVE_CAM_SHAKE_GAMEPLAY_CAM(sol::stack_object ShakeName, float fAmplitudeScalar)
	{
		CAM::SHAKE_GAMEPLAY_CAM(ShakeName.is<const char*>() ? ShakeName.as<const char*>() : nullptr, fAmplitudeScalar);
	}

	static void LUA_NATIVE_CAM__0xC3E9E5D4F413B773(sol::stack_object shakeName, float intensity)
	{
		CAM::_0xC3E9E5D4F413B773(shakeName.is<const char*>() ? shakeName.as<const char*>() : nullptr, intensity);
	}

	static bool LUA_NATIVE_CAM_IS_GAMEPLAY_CAM_SHAKING()
	{
		auto retval = (bool)CAM::IS_GAMEPLAY_CAM_SHAKING();
		return retval;
	}

	static bool LUA_NATIVE_CAM__0x0060B31968E60E41(sol::stack_object shakeName)
	{
		auto retval = (bool)CAM::_0x0060B31968E60E41(shakeName.is<const char*>() ? shakeName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE(float fAmplitudeScalar)
	{
		CAM::SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE(fAmplitudeScalar);
	}

	static void LUA_NATIVE_CAM__0xFEFDDC6E8FDF8A75(sol::stack_object shakeName, float intensity)
	{
		CAM::_0xFEFDDC6E8FDF8A75(shakeName.is<const char*>() ? shakeName.as<const char*>() : nullptr, intensity);
	}

	static void LUA_NATIVE_CAM_STOP_GAMEPLAY_CAM_SHAKING(bool bStopImmediately)
	{
		CAM::STOP_GAMEPLAY_CAM_SHAKING(bStopImmediately);
	}

	static void LUA_NATIVE_CAM__STOP_GAMEPLAY_CAM_SHAKING_WITH_NAME(sol::stack_object shakeName, bool p1)
	{
		CAM::_STOP_GAMEPLAY_CAM_SHAKING_WITH_NAME(shakeName.is<const char*>() ? shakeName.as<const char*>() : nullptr, p1);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_FOLLOW_PED_THIS_UPDATE(Ped PedIndex)
	{
		CAM::SET_GAMEPLAY_CAM_FOLLOW_PED_THIS_UPDATE(PedIndex);
	}

	static bool LUA_NATIVE_CAM_IS_GAMEPLAY_CAM_RENDERING()
	{
		auto retval = (bool)CAM::IS_GAMEPLAY_CAM_RENDERING();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_INTERPOLATING_FROM_SCRIPT_CAMS()
	{
		auto retval = (bool)CAM::IS_INTERPOLATING_FROM_SCRIPT_CAMS();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_INTERPOLATING_TO_SCRIPT_CAMS()
	{
		auto retval = (bool)CAM::IS_INTERPOLATING_TO_SCRIPT_CAMS();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_GAMEPLAY_CAM_LOOKING_BEHIND()
	{
		auto retval = (bool)CAM::IS_GAMEPLAY_CAM_LOOKING_BEHIND();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_IGNORE_ENTITY_COLLISION_THIS_UPDATE(Entity Index)
	{
		CAM::SET_GAMEPLAY_CAM_IGNORE_ENTITY_COLLISION_THIS_UPDATE(Index);
	}

	static void LUA_NATIVE_CAM_DISABLE_CAM_COLLISION_FOR_OBJECT(Object object)
	{
		CAM::DISABLE_CAM_COLLISION_FOR_OBJECT(object);
	}

	static void LUA_NATIVE_CAM__0x39073DA4EDDBC91D(Any p0)
	{
		CAM::_0x39073DA4EDDBC91D(p0);
	}

	static void LUA_NATIVE_CAM__0x70A6658D476C6187()
	{
		CAM::_0x70A6658D476C6187();
	}

	static void LUA_NATIVE_CAM__0x18C3DFAC458783BB()
	{
		CAM::_0x18C3DFAC458783BB();
	}

	static void LUA_NATIVE_CAM__0xF1A6FEEDF3776EF9()
	{
		CAM::_0xF1A6FEEDF3776EF9();
	}

	static void LUA_NATIVE_CAM__0xE6F364DE6C2FDEFE()
	{
		CAM::_0xE6F364DE6C2FDEFE();
	}

	static void LUA_NATIVE_CAM__0x0F1FFEF5D54AE832()
	{
		CAM::_0x0F1FFEF5D54AE832();
	}

	static void LUA_NATIVE_CAM__0x3C8F74E8FE751614()
	{
		CAM::_0x3C8F74E8FE751614();
	}

	static void LUA_NATIVE_CAM__0x06557F6D96C86881()
	{
		CAM::_0x06557F6D96C86881();
	}

	static bool LUA_NATIVE_CAM_IS_SPHERE_VISIBLE(float VecCoorsX, float VecCoorsY, float VecCoorsZ, float radius)
	{
		auto retval = (bool)CAM::IS_SPHERE_VISIBLE(VecCoorsX, VecCoorsY, VecCoorsZ, radius);
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x190F7DA1AC09A8EF()
	{
		auto retval = CAM::_0x190F7DA1AC09A8EF();
		return retval;
	}

	static void LUA_NATIVE_CAM__SET_GAMEPLAY_CAM_INITIAL_ZOOM(float camInitialZoom)
	{
		CAM::_SET_GAMEPLAY_CAM_INITIAL_ZOOM(camInitialZoom);
	}

	static void LUA_NATIVE_CAM__SET_GAMEPLAY_CAM_INITIAL_HEADING(float camInitialHeading)
	{
		CAM::_SET_GAMEPLAY_CAM_INITIAL_HEADING(camInitialHeading);
	}

	static void LUA_NATIVE_CAM__SET_GAMEPLAY_CAM_INITIAL_PITCH(float camInitialPitch)
	{
		CAM::_SET_GAMEPLAY_CAM_INITIAL_PITCH(camInitialPitch);
	}

	static void LUA_NATIVE_CAM_SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(float minRelativeHeading, float maxRelativeHeading)
	{
		CAM::SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(minRelativeHeading, maxRelativeHeading);
	}

	static void LUA_NATIVE_CAM_SET_THIRD_PERSON_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(float minRelativePitch, float maxRelativePitch)
	{
		CAM::SET_THIRD_PERSON_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(minRelativePitch, maxRelativePitch);
	}

	static void LUA_NATIVE_CAM_SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE(float minDistance, float maxDistance)
	{
		CAM::SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE(minDistance, maxDistance);
	}

	static void LUA_NATIVE_CAM_SET_IN_VEHICLE_CAM_STATE_THIS_UPDATE(Vehicle Vehicle, int InVehicleState)
	{
		CAM::SET_IN_VEHICLE_CAM_STATE_THIS_UPDATE(Vehicle, InVehicleState);
	}

	static void LUA_NATIVE_CAM_DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE()
	{
		CAM::DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE();
	}

	static void LUA_NATIVE_CAM_DISABLE_FIRST_PERSON_FLASH_EFFECT_THIS_UPDATE()
	{
		CAM::DISABLE_FIRST_PERSON_FLASH_EFFECT_THIS_UPDATE();
	}

	static void LUA_NATIVE_CAM__DISABLE_CINEMATIC_MODE_THIS_FRAME()
	{
		CAM::_DISABLE_CINEMATIC_MODE_THIS_FRAME();
	}

	static bool LUA_NATIVE_CAM__IS_IN_CINEMATIC_MODE()
	{
		auto retval = (bool)CAM::_IS_IN_CINEMATIC_MODE();
		return retval;
	}

	static void LUA_NATIVE_CAM__0x718C6ECF5E8CBDD4()
	{
		CAM::_0x718C6ECF5E8CBDD4();
	}

	static void LUA_NATIVE_CAM__FORCE_THIRD_PERSON_CAM_THIS_FRAME()
	{
		CAM::_FORCE_THIRD_PERSON_CAM_THIS_FRAME();
	}

	static void LUA_NATIVE_CAM__FORCE_THIRD_PERSON_CAM_FAR_THIS_FRAME()
	{
		CAM::_FORCE_THIRD_PERSON_CAM_FAR_THIS_FRAME();
	}

	static bool LUA_NATIVE_CAM__FORCE_FIRST_PERSON_CAM_THIS_FRAME()
	{
		auto retval = (bool)CAM::_FORCE_FIRST_PERSON_CAM_THIS_FRAME();
		return retval;
	}

	static void LUA_NATIVE_CAM__DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE_2()
	{
		CAM::_DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE_2();
	}

	static void LUA_NATIVE_CAM__0x632BE8D84846FA56()
	{
		CAM::_0x632BE8D84846FA56();
	}

	static void LUA_NATIVE_CAM__0x71D71E08A7ED5BD7(Any p0)
	{
		CAM::_0x71D71E08A7ED5BD7(p0);
	}

	static bool LUA_NATIVE_CAM_IS_FOLLOW_VEHICLE_CAM_ACTIVE()
	{
		auto retval = (bool)CAM::IS_FOLLOW_VEHICLE_CAM_ACTIVE();
		return retval;
	}

	static void LUA_NATIVE_CAM__0x7E40A01B11398FCB()
	{
		CAM::_0x7E40A01B11398FCB();
	}

	static bool LUA_NATIVE_CAM_IS_AIM_CAM_ACTIVE()
	{
		auto retval = (bool)CAM::IS_AIM_CAM_ACTIVE();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_FIRST_PERSON_AIM_CAM_ACTIVE()
	{
		auto retval = (bool)CAM::IS_FIRST_PERSON_AIM_CAM_ACTIVE();
		return retval;
	}

	static bool LUA_NATIVE_CAM_IS_FIRST_PERSON_CAMERA_ACTIVE(Any p0, Any p1, Any p2)
	{
		auto retval = (bool)CAM::IS_FIRST_PERSON_CAMERA_ACTIVE(p0, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_CAM__0xDC62CD70658E7A02()
	{
		auto retval = CAM::_0xDC62CD70658E7A02();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x796085220ADCC847()
	{
		auto retval = CAM::_0x796085220ADCC847();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0xB6A80E1E3A5444F1()
	{
		auto retval = CAM::_0xB6A80E1E3A5444F1();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x8B1A5FE7E41E52B2()
	{
		auto retval = CAM::_0x8B1A5FE7E41E52B2();
		return retval;
	}

	static float LUA_NATIVE_CAM_GET_FIRST_PERSON_AIM_CAM_ZOOM_FACTOR()
	{
		auto retval = CAM::GET_FIRST_PERSON_AIM_CAM_ZOOM_FACTOR();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_FIRST_PERSON_AIM_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(float MinRelativeHeading, float MaxRelativeHeading)
	{
		CAM::SET_FIRST_PERSON_AIM_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(MinRelativeHeading, MaxRelativeHeading);
	}

	static void LUA_NATIVE_CAM_SET_FIRST_PERSON_AIM_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(float MinRelativePitch, float MaxRelativePitch)
	{
		CAM::SET_FIRST_PERSON_AIM_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(MinRelativePitch, MaxRelativePitch);
	}

	static void LUA_NATIVE_CAM__0xC205B3C54C6A4E37(Any p0)
	{
		CAM::_0xC205B3C54C6A4E37(p0);
	}

	static Vector3 LUA_NATIVE_CAM_GET_FINAL_RENDERED_CAM_COORD()
	{
		auto retval = CAM::GET_FINAL_RENDERED_CAM_COORD();
		return retval;
	}

	static Vector3 LUA_NATIVE_CAM_GET_FINAL_RENDERED_CAM_ROT(int RotOrder)
	{
		auto retval = CAM::GET_FINAL_RENDERED_CAM_ROT(RotOrder);
		return retval;
	}

	static float LUA_NATIVE_CAM_GET_FINAL_RENDERED_CAM_FOV()
	{
		auto retval = CAM::GET_FINAL_RENDERED_CAM_FOV();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_COORD_HINT(float vCoordX, float vCoordY, float vCoordZ, int iDwellTime, int iInterpTo, int iInterpFrom, Hash Type)
	{
		CAM::SET_GAMEPLAY_COORD_HINT(vCoordX, vCoordY, vCoordZ, iDwellTime, iInterpTo, iInterpFrom, Type);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_PED_HINT(Ped Ped, float OffsetX, float OffsetY, float OffsetZ, bool RelativeOffset, int iDwellTime, int iInterpTo, int iInterpFrom)
	{
		CAM::SET_GAMEPLAY_PED_HINT(Ped, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_VEHICLE_HINT(Vehicle Vehicle, float OffsetX, float OffsetY, float OffsetZ, bool RelativeOffset, int iDwellTime, int iInterpTo, int iInterpFrom)
	{
		CAM::SET_GAMEPLAY_VEHICLE_HINT(Vehicle, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_OBJECT_HINT(Object Obejct, float OffsetX, float OffsetY, float OffsetZ, bool RelativeOffset, int iDwellTime, int iInterpTo, int iInterpFrom)
	{
		CAM::SET_GAMEPLAY_OBJECT_HINT(Obejct, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_ENTITY_HINT(Entity Enttity, float OffsetX, float OffsetY, float OffsetZ, bool RelativeOffset, int iDwellTime, int iInterpTo, int iInterpFrom, Hash Type)
	{
		CAM::SET_GAMEPLAY_ENTITY_HINT(Enttity, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom, Type);
	}

	static bool LUA_NATIVE_CAM_IS_GAMEPLAY_HINT_ACTIVE()
	{
		auto retval = (bool)CAM::IS_GAMEPLAY_HINT_ACTIVE();
		return retval;
	}

	static void LUA_NATIVE_CAM_STOP_GAMEPLAY_HINT(bool bStopImmediately)
	{
		CAM::STOP_GAMEPLAY_HINT(bStopImmediately);
	}

	static void LUA_NATIVE_CAM_STOP_CODE_GAMEPLAY_HINT(bool StopImmediately)
	{
		CAM::STOP_CODE_GAMEPLAY_HINT(StopImmediately);
	}

	static void LUA_NATIVE_CAM__0x88544C0E3291DCAE(bool p0)
	{
		CAM::_0x88544C0E3291DCAE(p0);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_FOV(float fov)
	{
		CAM::SET_GAMEPLAY_HINT_FOV(fov);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_FOLLOW_DISTANCE_SCALAR(float DistanceScalar)
	{
		CAM::SET_GAMEPLAY_HINT_FOLLOW_DISTANCE_SCALAR(DistanceScalar);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_BASE_ORBIT_PITCH_OFFSET(float BasePitchOffset)
	{
		CAM::SET_GAMEPLAY_HINT_BASE_ORBIT_PITCH_OFFSET(BasePitchOffset);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_CAMERA_RELATIVE_SIDE_OFFSET(float SideOffset)
	{
		CAM::SET_GAMEPLAY_HINT_CAMERA_RELATIVE_SIDE_OFFSET(SideOffset);
	}

	static void LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_CAMERA_RELATIVE_VERTICAL_OFFSET(float VerticalOffset)
	{
		CAM::SET_GAMEPLAY_HINT_CAMERA_RELATIVE_VERTICAL_OFFSET(VerticalOffset);
	}

	static void LUA_NATIVE_CAM__0xF48664E9C83825E3(Any p0, Any p1)
	{
		CAM::_0xF48664E9C83825E3(p0, p1);
	}

	static void LUA_NATIVE_CAM__0x1F6EBD94680252CE(Any p0, Any p1)
	{
		CAM::_0x1F6EBD94680252CE(p0, p1);
	}

	static void LUA_NATIVE_CAM__0xE28F73212A813E82(Any p0, Any p1, Any p2, Any p3)
	{
		CAM::_0xE28F73212A813E82(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_CAM__0x4D2F46D1B28D90FB(Any p0, Any p1)
	{
		CAM::_0x4D2F46D1B28D90FB(p0, p1);
	}

	static void LUA_NATIVE_CAM__START_CAMERA_ORBIT(uintptr_t p0)
	{
		CAM::_START_CAMERA_ORBIT((Any*)p0);
	}

	static void LUA_NATIVE_CAM__0x641092322A8852AB()
	{
		CAM::_0x641092322A8852AB();
	}

	static void LUA_NATIVE_CAM__0xDB382FE20C2DA222(Any p0)
	{
		CAM::_0xDB382FE20C2DA222(p0);
	}

	static void LUA_NATIVE_CAM__0x2DD3149DC34A3F4C(Any p0)
	{
		CAM::_0x2DD3149DC34A3F4C(p0);
	}

	static void LUA_NATIVE_CAM__FREEZE_GAMEPLAY_CAM_THIS_FRAME()
	{
		CAM::_FREEZE_GAMEPLAY_CAM_THIS_FRAME();
	}

	static void LUA_NATIVE_CAM__0x3C486E334520579D()
	{
		CAM::_0x3C486E334520579D();
	}

	static void LUA_NATIVE_CAM__0x41E452A3C580D1A7()
	{
		CAM::_0x41E452A3C580D1A7();
	}

	static void LUA_NATIVE_CAM_SET_CINEMATIC_BUTTON_ACTIVE(bool bEnable)
	{
		CAM::SET_CINEMATIC_BUTTON_ACTIVE(bEnable);
	}

	static bool LUA_NATIVE_CAM_IS_CINEMATIC_CAM_RENDERING()
	{
		auto retval = (bool)CAM::IS_CINEMATIC_CAM_RENDERING();
		return retval;
	}

	static void LUA_NATIVE_CAM_DISABLE_CINEMATIC_BONNET_CAMERA_THIS_UPDATE()
	{
		CAM::DISABLE_CINEMATIC_BONNET_CAMERA_THIS_UPDATE();
	}

	static void LUA_NATIVE_CAM_INVALIDATE_CINEMATIC_VEHICLE_IDLE_MODE()
	{
		CAM::INVALIDATE_CINEMATIC_VEHICLE_IDLE_MODE();
	}

	static void LUA_NATIVE_CAM_FORCE_CINEMATIC_RENDERING_THIS_UPDATE(bool ActiveThisFrame)
	{
		CAM::FORCE_CINEMATIC_RENDERING_THIS_UPDATE(ActiveThisFrame);
	}

	static void LUA_NATIVE_CAM__0x9AC65A36D3C0C189(Any p0)
	{
		CAM::_0x9AC65A36D3C0C189(p0);
	}

	static bool LUA_NATIVE_CAM__0x975F6EBB62632FE3()
	{
		auto retval = (bool)CAM::_0x975F6EBB62632FE3();
		return retval;
	}

	static void LUA_NATIVE_CAM_SET_CINEMATIC_MODE_ACTIVE(bool Active)
	{
		CAM::SET_CINEMATIC_MODE_ACTIVE(Active);
	}

	static bool LUA_NATIVE_CAM__0x1811A02277A9E49D()
	{
		auto retval = (bool)CAM::_0x1811A02277A9E49D();
		return retval;
	}

	static void LUA_NATIVE_CAM__FORCE_CINEMATIC_DEATH_CAM_ON_PED(Ped targetPed)
	{
		CAM::_FORCE_CINEMATIC_DEATH_CAM_ON_PED(targetPed);
	}

	static void LUA_NATIVE_CAM__REACTIVATE_PED_HEADSHOT_EXECUTE_SLOWCAM(Ped ped, int p1)
	{
		CAM::_REACTIVATE_PED_HEADSHOT_EXECUTE_SLOWCAM(ped, p1);
	}

	static void LUA_NATIVE_CAM__0x5B637D6F3B67716A(Any p0)
	{
		CAM::_0x5B637D6F3B67716A(p0);
	}

	static void LUA_NATIVE_CAM__0xC252C0CC969AF79A(Any p0)
	{
		CAM::_0xC252C0CC969AF79A(p0);
	}

	static void LUA_NATIVE_CAM__0xE2BB2D6A9FE2ECDE(Any p0)
	{
		CAM::_0xE2BB2D6A9FE2ECDE(p0);
	}

	static void LUA_NATIVE_CAM__SET_START_CINEMATIC_DEATH_CAM(bool p0)
	{
		CAM::_SET_START_CINEMATIC_DEATH_CAM(p0);
	}

	static Any LUA_NATIVE_CAM__0x6072B7420A83A03F()
	{
		auto retval = CAM::_0x6072B7420A83A03F();
		return retval;
	}

	static bool LUA_NATIVE_CAM__0x1204EB53A5FBC63D()
	{
		auto retval = (bool)CAM::_0x1204EB53A5FBC63D();
		return retval;
	}

	static void LUA_NATIVE_CAM__0x6519238858AF5479(Any p0)
	{
		CAM::_0x6519238858AF5479(p0);
	}

	static void LUA_NATIVE_CAM__CREATE_KILL_CAM(Ped ped)
	{
		CAM::_CREATE_KILL_CAM(ped);
	}

	static bool LUA_NATIVE_CAM__IS_CAM_PHOTOFX_RUNNING()
	{
		auto retval = (bool)CAM::_IS_CAM_PHOTOFX_RUNNING();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x6DFD37E586D4F44F()
	{
		auto retval = CAM::_0x6DFD37E586D4F44F();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x80D7A3E39B120BC4()
	{
		auto retval = CAM::_0x80D7A3E39B120BC4();
		return retval;
	}

	static void LUA_NATIVE_CAM__0x63E5841A9264D016(bool toggle)
	{
		CAM::_0x63E5841A9264D016(toggle);
	}

	static void LUA_NATIVE_CAM__TRIGGER_MISSION_FAILED_CAM()
	{
		CAM::_TRIGGER_MISSION_FAILED_CAM();
	}

	static void LUA_NATIVE_CAM__0x16E9ABDD34DDD931()
	{
		CAM::_0x16E9ABDD34DDD931();
	}

	static bool LUA_NATIVE_CAM_IS_DEATH_FAIL_CAMERA_RUNNING()
	{
		auto retval = (bool)CAM::IS_DEATH_FAIL_CAMERA_RUNNING();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x7CE9DC58E3E4755F()
	{
		auto retval = CAM::_0x7CE9DC58E3E4755F();
		return retval;
	}

	static void LUA_NATIVE_CAM__0x3B8E3AD9677CE12B(Any p0, Any p1, Any p2)
	{
		CAM::_0x3B8E3AD9677CE12B(p0, p1, p2);
	}

	static void LUA_NATIVE_CAM__0xDF7F5BE9150E47E4(Any p0)
	{
		CAM::_0xDF7F5BE9150E47E4(p0);
	}

	static void LUA_NATIVE_CAM__0xB85C13E0BF1F2A1C(Any p0)
	{
		CAM::_0xB85C13E0BF1F2A1C(p0);
	}

	static void LUA_NATIVE_CAM__0x066167C63111D8CF(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		CAM::_0x066167C63111D8CF(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_CAM__0xA8BA2E0204D8486F()
	{
		CAM::_0xA8BA2E0204D8486F();
	}

	static void LUA_NATIVE_CAM__0xC3742F1FDF0A6824()
	{
		CAM::_0xC3742F1FDF0A6824();
	}

	static void LUA_NATIVE_CAM__0x0FF7125F07DEB84F(Any p0, Any p1)
	{
		CAM::_0x0FF7125F07DEB84F(p0, p1);
	}

	static void LUA_NATIVE_CAM__0x6CAB0BA160B168D2()
	{
		CAM::_0x6CAB0BA160B168D2();
	}

	static void LUA_NATIVE_CAM__LOAD_CINEMATIC_CAM_LOCATION(sol::stack_object locationDictName)
	{
		CAM::_LOAD_CINEMATIC_CAM_LOCATION(locationDictName.is<const char*>() ? locationDictName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_CAM__UNLOAD_CINEMATIC_CAMERA_LOCATION(sol::stack_object dictionaryName)
	{
		CAM::_UNLOAD_CINEMATIC_CAMERA_LOCATION(dictionaryName.is<const char*>() ? dictionaryName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_CAM__IS_CINEMATIC_CAM_LOCATION_LOADED(sol::stack_object sLocationDictName)
	{
		auto retval = (bool)CAM::_IS_CINEMATIC_CAM_LOCATION_LOADED(sLocationDictName.is<const char*>() ? sLocationDictName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_CAM__IS_CINEMATIC_CAM_LOCATION_LOADED_2(sol::stack_object locationDictName)
	{
		auto retval = (bool)CAM::_IS_CINEMATIC_CAM_LOCATION_LOADED_2(locationDictName.is<const char*>() ? locationDictName.as<const char*>() : nullptr);
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x465F04F68AD38197(sol::stack_object dictionary, sol::stack_object shotName, int duration)
	{
		auto retval = CAM::_0x465F04F68AD38197(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, duration);
		return retval;
	}

	static Any LUA_NATIVE_CAM__0xEA113BF9B0C0C5D7(sol::stack_object dictionary, sol::stack_object shotName, int duration)
	{
		auto retval = CAM::_0xEA113BF9B0C0C5D7(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, duration);
		return retval;
	}

	static void LUA_NATIVE_CAM__CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT_2(sol::stack_object dictionary, sol::stack_object shotName, int duration)
	{
		CAM::_CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT_2(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, duration);
	}

	static void LUA_NATIVE_CAM_CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT(sol::stack_object dictionary, sol::stack_object shotName, sol::stack_object cameraName, Any p3)
	{
		CAM::CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, cameraName.is<const char*>() ? cameraName.as<const char*>() : nullptr, p3);
	}

	static void LUA_NATIVE_CAM__0xA54D643D0773EB65(sol::stack_object dictionary, sol::stack_object shotName, int duration)
	{
		CAM::_0xA54D643D0773EB65(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, duration);
	}

	static void LUA_NATIVE_CAM_CINEMATIC_LOCATION_STOP_SCRIPTED_SHOT_EVENT(Any p0, Any p1, Any p2)
	{
		CAM::CINEMATIC_LOCATION_STOP_SCRIPTED_SHOT_EVENT(p0, p1, p2);
	}

	static bool LUA_NATIVE_CAM__0xC3AEBB276825A359(sol::stack_object dictionary, sol::stack_object shotName, int duration)
	{
		auto retval = (bool)CAM::_0xC3AEBB276825A359(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, duration);
		return retval;
	}

	static bool LUA_NATIVE_CAM__0x1D931B7CC0EE3956(sol::stack_object dictionary, sol::stack_object shotName, sol::stack_object cameraName)
	{
		auto retval = (bool)CAM::_0x1D931B7CC0EE3956(dictionary.is<const char*>() ? dictionary.as<const char*>() : nullptr, shotName.is<const char*>() ? shotName.as<const char*>() : nullptr, cameraName.is<const char*>() ? cameraName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_CAM__CINEMATIC_LOCATION_SET_LOCATION_AND_ROTATION(sol::stack_object name, float x, float y, float z, float rotX, float rotY, float rotZ)
	{
		CAM::_CINEMATIC_LOCATION_SET_LOCATION_AND_ROTATION(name.is<const char*>() ? name.as<const char*>() : nullptr, x, y, z, rotX, rotY, rotZ);
	}

	static void LUA_NATIVE_CAM_CINEMATIC_LOCATION_OVERRIDE_TARGET_ENTITY_THIS_UPDATE(sol::stack_object name, Entity entity)
	{
		CAM::CINEMATIC_LOCATION_OVERRIDE_TARGET_ENTITY_THIS_UPDATE(name.is<const char*>() ? name.as<const char*>() : nullptr, entity);
	}

	static void LUA_NATIVE_CAM__LOAD_CAMERA_DATA_DICT(sol::stack_object cameraDictionary)
	{
		CAM::_LOAD_CAMERA_DATA_DICT(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_CAM__UNLOAD_CAMERA_DATA_DICT(sol::stack_object cameraDictionary)
	{
		CAM::_UNLOAD_CAMERA_DATA_DICT(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_CAM__IS_CAM_DATA_DICT_LOADED(sol::stack_object cameraDictionary)
	{
		auto retval = (bool)CAM::_IS_CAM_DATA_DICT_LOADED(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_CAM__0xC285FD21294A1C49(sol::stack_object cameraDictionary)
	{
		auto retval = (bool)CAM::_0xC285FD21294A1C49(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_CAM__CAM_CREATE(sol::stack_object cameraDictionary)
	{
		CAM::_CAM_CREATE(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_CAM__CAM_DESTROY(sol::stack_object cameraDictionary)
	{
		CAM::_CAM_DESTROY(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_CAM__IS_CAMERA_AVAILABLE(sol::stack_object cameraDictionary)
	{
		auto retval = (bool)CAM::_IS_CAMERA_AVAILABLE(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x4138EE36BC3DC0A7(Any p0, Any p1)
	{
		auto retval = CAM::_0x4138EE36BC3DC0A7(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_CAM__0xFEB8646818294C75(Any p0, Any p1)
	{
		CAM::_0xFEB8646818294C75(p0, p1);
	}

	static void LUA_NATIVE_CAM__0x29E6655DF3590B0D(Any p0)
	{
		CAM::_0x29E6655DF3590B0D(p0);
	}

	static void LUA_NATIVE_CAM__0xAC77757C05DE9E5A(sol::stack_object cameraDictionary)
	{
		CAM::_0xAC77757C05DE9E5A(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_CAM__0x8E036B41C37D0E5F(Any p0)
	{
		CAM::_0x8E036B41C37D0E5F(p0);
	}

	static void LUA_NATIVE_CAM__0x1D9F72DD4FD9A9D7(Any p0)
	{
		CAM::_0x1D9F72DD4FD9A9D7(p0);
	}

	static void LUA_NATIVE_CAM__CAM_CREATE_2(sol::stack_object cameraDictionary)
	{
		CAM::_CAM_CREATE_2(cameraDictionary.is<const char*>() ? cameraDictionary.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_CAM__0x728491FB3DFFEF99(Any p0)
	{
		CAM::_0x728491FB3DFFEF99(p0);
	}

	static Any LUA_NATIVE_CAM__0x14C4A49E36C29E49()
	{
		auto retval = CAM::_0x14C4A49E36C29E49();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0xF824530B612FE0CE()
	{
		auto retval = CAM::_0xF824530B612FE0CE();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0xEF9A3132A0AA6B19()
	{
		auto retval = CAM::_0xEF9A3132A0AA6B19();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x5060FA977CEA4455()
	{
		auto retval = CAM::_0x5060FA977CEA4455();
		return retval;
	}

	static float LUA_NATIVE_CAM__GET_PHOTO_MODE_FOCAL_LENGTH()
	{
		auto retval = CAM::_GET_PHOTO_MODE_FOCAL_LENGTH();
		return retval;
	}

	static float LUA_NATIVE_CAM__GET_PHOTO_MODE_FOCUS_DISTANCE()
	{
		auto retval = CAM::_GET_PHOTO_MODE_FOCUS_DISTANCE();
		return retval;
	}

	static float LUA_NATIVE_CAM__GET_PHOTO_MODE_DOF()
	{
		auto retval = CAM::_GET_PHOTO_MODE_DOF();
		return retval;
	}

	static Any LUA_NATIVE_CAM__0x2AB7C81B3F70570C()
	{
		auto retval = CAM::_0x2AB7C81B3F70570C();
		return retval;
	}

	static void LUA_NATIVE_CAM__0x8505E05FC8822843(Any p0)
	{
		CAM::_0x8505E05FC8822843(p0);
	}

	void RegisterNatives_CAM(sol::state& L)
	{
		auto CAM = L["CAM"].get_or_create<sol::table>();
		CAM.set_function("RENDER_SCRIPT_CAMS", LUA_NATIVE_CAM_RENDER_SCRIPT_CAMS);
		CAM.set_function("STOP_RENDERING_SCRIPT_CAMS_USING_CATCH_UP", LUA_NATIVE_CAM_STOP_RENDERING_SCRIPT_CAMS_USING_CATCH_UP);
		CAM.set_function("CREATE_CAM", LUA_NATIVE_CAM_CREATE_CAM);
		CAM.set_function("CREATE_CAM_WITH_PARAMS", LUA_NATIVE_CAM_CREATE_CAM_WITH_PARAMS);
		CAM.set_function("CREATE_CAMERA", LUA_NATIVE_CAM_CREATE_CAMERA);
		CAM.set_function("CREATE_CAMERA_WITH_PARAMS", LUA_NATIVE_CAM_CREATE_CAMERA_WITH_PARAMS);
		CAM.set_function("DESTROY_CAM", LUA_NATIVE_CAM_DESTROY_CAM);
		CAM.set_function("DESTROY_ALL_CAMS", LUA_NATIVE_CAM_DESTROY_ALL_CAMS);
		CAM.set_function("DOES_CAM_EXIST", LUA_NATIVE_CAM_DOES_CAM_EXIST);
		CAM.set_function("SET_CAM_ACTIVE", LUA_NATIVE_CAM_SET_CAM_ACTIVE);
		CAM.set_function("IS_CAM_ACTIVE", LUA_NATIVE_CAM_IS_CAM_ACTIVE);
		CAM.set_function("IS_CAM_RENDERING", LUA_NATIVE_CAM_IS_CAM_RENDERING);
		CAM.set_function("GET_RENDERING_CAM", LUA_NATIVE_CAM_GET_RENDERING_CAM);
		CAM.set_function("GET_CAM_COORD", LUA_NATIVE_CAM_GET_CAM_COORD);
		CAM.set_function("GET_CAM_ROT", LUA_NATIVE_CAM_GET_CAM_ROT);
		CAM.set_function("GET_CAM_FOV", LUA_NATIVE_CAM_GET_CAM_FOV);
		CAM.set_function("SET_CAM_PARAMS", LUA_NATIVE_CAM_SET_CAM_PARAMS);
		CAM.set_function("SET_CAM_COORD", LUA_NATIVE_CAM_SET_CAM_COORD);
		CAM.set_function("SET_CAM_ROT", LUA_NATIVE_CAM_SET_CAM_ROT);
		CAM.set_function("SET_CAM_FOV", LUA_NATIVE_CAM_SET_CAM_FOV);
		CAM.set_function("SET_CAM_NEAR_CLIP", LUA_NATIVE_CAM_SET_CAM_NEAR_CLIP);
		CAM.set_function("SET_CAM_FAR_CLIP", LUA_NATIVE_CAM_SET_CAM_FAR_CLIP);
		CAM.set_function("SET_CAM_MOTION_BLUR_STRENGTH", LUA_NATIVE_CAM_SET_CAM_MOTION_BLUR_STRENGTH);
		CAM.set_function("_0xFC3F638BE2B6BB02", LUA_NATIVE_CAM__0xFC3F638BE2B6BB02);
		CAM.set_function("_0xE4B7945EF4F1BFB2", LUA_NATIVE_CAM__0xE4B7945EF4F1BFB2);
		CAM.set_function("_0x1FC6C727D30FFDDE", LUA_NATIVE_CAM__0x1FC6C727D30FFDDE);
		CAM.set_function("ATTACH_CAM_TO_ENTITY", LUA_NATIVE_CAM_ATTACH_CAM_TO_ENTITY);
		CAM.set_function("ATTACH_CAM_TO_PED_BONE", LUA_NATIVE_CAM_ATTACH_CAM_TO_PED_BONE);
		CAM.set_function("DETACH_CAM", LUA_NATIVE_CAM_DETACH_CAM);
		CAM.set_function("POINT_CAM_AT_COORD", LUA_NATIVE_CAM_POINT_CAM_AT_COORD);
		CAM.set_function("POINT_CAM_AT_ENTITY", LUA_NATIVE_CAM_POINT_CAM_AT_ENTITY);
		CAM.set_function("STOP_CAM_POINTING", LUA_NATIVE_CAM_STOP_CAM_POINTING);
		CAM.set_function("_SET_CAM_FOCUS_DISTANCE", LUA_NATIVE_CAM__SET_CAM_FOCUS_DISTANCE);
		CAM.set_function("_PAUSE_CAMERA_FOCUS", LUA_NATIVE_CAM__PAUSE_CAMERA_FOCUS);
		CAM.set_function("SET_CAM_AFFECTS_AIMING", LUA_NATIVE_CAM_SET_CAM_AFFECTS_AIMING);
		CAM.set_function("SET_CAM_CONTROLS_MINI_MAP_HEADING", LUA_NATIVE_CAM_SET_CAM_CONTROLS_MINI_MAP_HEADING);
		CAM.set_function("ALLOW_MOTION_BLUR_DECAY", LUA_NATIVE_CAM_ALLOW_MOTION_BLUR_DECAY);
		CAM.set_function("ADD_CAM_SPLINE_NODE", LUA_NATIVE_CAM_ADD_CAM_SPLINE_NODE);
		CAM.set_function("SET_CAM_SPLINE_PHASE", LUA_NATIVE_CAM_SET_CAM_SPLINE_PHASE);
		CAM.set_function("GET_CAM_SPLINE_PHASE", LUA_NATIVE_CAM_GET_CAM_SPLINE_PHASE);
		CAM.set_function("SET_CAM_SPLINE_DURATION", LUA_NATIVE_CAM_SET_CAM_SPLINE_DURATION);
		CAM.set_function("SET_CAM_SPLINE_SMOOTHING_STYLE", LUA_NATIVE_CAM_SET_CAM_SPLINE_SMOOTHING_STYLE);
		CAM.set_function("SET_CAM_ACTIVE_WITH_INTERP", LUA_NATIVE_CAM_SET_CAM_ACTIVE_WITH_INTERP);
		CAM.set_function("IS_CAM_INTERPOLATING", LUA_NATIVE_CAM_IS_CAM_INTERPOLATING);
		CAM.set_function("SHAKE_CAM", LUA_NATIVE_CAM_SHAKE_CAM);
		CAM.set_function("IS_CAM_SHAKING", LUA_NATIVE_CAM_IS_CAM_SHAKING);
		CAM.set_function("STOP_CAM_SHAKING", LUA_NATIVE_CAM_STOP_CAM_SHAKING);
		CAM.set_function("PLAY_CAM_ANIM", LUA_NATIVE_CAM_PLAY_CAM_ANIM);
		CAM.set_function("_0xCF69EA05CD9C33C9", LUA_NATIVE_CAM__0xCF69EA05CD9C33C9);
		CAM.set_function("_IS_ANIM_SCENE_CAM_ACTIVE", LUA_NATIVE_CAM__IS_ANIM_SCENE_CAM_ACTIVE);
		CAM.set_function("IS_SCREEN_FADED_OUT", LUA_NATIVE_CAM_IS_SCREEN_FADED_OUT);
		CAM.set_function("IS_SCREEN_FADED_IN", LUA_NATIVE_CAM_IS_SCREEN_FADED_IN);
		CAM.set_function("IS_SCREEN_FADING_OUT", LUA_NATIVE_CAM_IS_SCREEN_FADING_OUT);
		CAM.set_function("IS_SCREEN_FADING_IN", LUA_NATIVE_CAM_IS_SCREEN_FADING_IN);
		CAM.set_function("DO_SCREEN_FADE_IN", LUA_NATIVE_CAM_DO_SCREEN_FADE_IN);
		CAM.set_function("DO_SCREEN_FADE_OUT", LUA_NATIVE_CAM_DO_SCREEN_FADE_OUT);
		CAM.set_function("HAS_LETTER_BOX", LUA_NATIVE_CAM_HAS_LETTER_BOX);
		CAM.set_function("_REQUEST_LETTER_BOX_NOW", LUA_NATIVE_CAM__REQUEST_LETTER_BOX_NOW);
		CAM.set_function("_REQUEST_LETTER_BOX_OVERTIME", LUA_NATIVE_CAM__REQUEST_LETTER_BOX_OVERTIME);
		CAM.set_function("_FORCE_LETTER_BOX_THIS_UPDATE", LUA_NATIVE_CAM__FORCE_LETTER_BOX_THIS_UPDATE);
		CAM.set_function("GET_LETTER_BOX_RATIO", LUA_NATIVE_CAM_GET_LETTER_BOX_RATIO);
		CAM.set_function("_0x73FF6BE63DC18819", LUA_NATIVE_CAM__0x73FF6BE63DC18819);
		CAM.set_function("_0x450769C833D58844", LUA_NATIVE_CAM__0x450769C833D58844);
		CAM.set_function("SET_WIDESCREEN_BORDERS", LUA_NATIVE_CAM_SET_WIDESCREEN_BORDERS);
		CAM.set_function("GET_GAMEPLAY_CAM_COORD", LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_COORD);
		CAM.set_function("GET_GAMEPLAY_CAM_ROT", LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_ROT);
		CAM.set_function("GET_GAMEPLAY_CAM_FOV", LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_FOV);
		CAM.set_function("SET_GAMEPLAY_CAM_MAX_MOTION_BLUR_STRENGTH_THIS_UPDATE", LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_MAX_MOTION_BLUR_STRENGTH_THIS_UPDATE);
		CAM.set_function("GET_GAMEPLAY_CAM_RELATIVE_HEADING", LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_RELATIVE_HEADING);
		CAM.set_function("SET_GAMEPLAY_CAM_RELATIVE_HEADING", LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_RELATIVE_HEADING);
		CAM.set_function("GET_GAMEPLAY_CAM_RELATIVE_PITCH", LUA_NATIVE_CAM_GET_GAMEPLAY_CAM_RELATIVE_PITCH);
		CAM.set_function("SET_GAMEPLAY_CAM_RELATIVE_PITCH", LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_RELATIVE_PITCH);
		CAM.set_function("_0x0961B089947BA6D0", LUA_NATIVE_CAM__0x0961B089947BA6D0);
		CAM.set_function("_0x04084490CC302CFB", LUA_NATIVE_CAM__0x04084490CC302CFB);
		CAM.set_function("SET_SCRIPTED_CAMERA_IS_FIRST_PERSON_THIS_FRAME", LUA_NATIVE_CAM_SET_SCRIPTED_CAMERA_IS_FIRST_PERSON_THIS_FRAME);
		CAM.set_function("_IS_IN_FULL_FIRST_PERSON_MODE", LUA_NATIVE_CAM__IS_IN_FULL_FIRST_PERSON_MODE);
		CAM.set_function("SHAKE_GAMEPLAY_CAM", LUA_NATIVE_CAM_SHAKE_GAMEPLAY_CAM);
		CAM.set_function("_0xC3E9E5D4F413B773", LUA_NATIVE_CAM__0xC3E9E5D4F413B773);
		CAM.set_function("IS_GAMEPLAY_CAM_SHAKING", LUA_NATIVE_CAM_IS_GAMEPLAY_CAM_SHAKING);
		CAM.set_function("_0x0060B31968E60E41", LUA_NATIVE_CAM__0x0060B31968E60E41);
		CAM.set_function("SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE", LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE);
		CAM.set_function("_0xFEFDDC6E8FDF8A75", LUA_NATIVE_CAM__0xFEFDDC6E8FDF8A75);
		CAM.set_function("STOP_GAMEPLAY_CAM_SHAKING", LUA_NATIVE_CAM_STOP_GAMEPLAY_CAM_SHAKING);
		CAM.set_function("_STOP_GAMEPLAY_CAM_SHAKING_WITH_NAME", LUA_NATIVE_CAM__STOP_GAMEPLAY_CAM_SHAKING_WITH_NAME);
		CAM.set_function("SET_GAMEPLAY_CAM_FOLLOW_PED_THIS_UPDATE", LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_FOLLOW_PED_THIS_UPDATE);
		CAM.set_function("IS_GAMEPLAY_CAM_RENDERING", LUA_NATIVE_CAM_IS_GAMEPLAY_CAM_RENDERING);
		CAM.set_function("IS_INTERPOLATING_FROM_SCRIPT_CAMS", LUA_NATIVE_CAM_IS_INTERPOLATING_FROM_SCRIPT_CAMS);
		CAM.set_function("IS_INTERPOLATING_TO_SCRIPT_CAMS", LUA_NATIVE_CAM_IS_INTERPOLATING_TO_SCRIPT_CAMS);
		CAM.set_function("IS_GAMEPLAY_CAM_LOOKING_BEHIND", LUA_NATIVE_CAM_IS_GAMEPLAY_CAM_LOOKING_BEHIND);
		CAM.set_function("SET_GAMEPLAY_CAM_IGNORE_ENTITY_COLLISION_THIS_UPDATE", LUA_NATIVE_CAM_SET_GAMEPLAY_CAM_IGNORE_ENTITY_COLLISION_THIS_UPDATE);
		CAM.set_function("DISABLE_CAM_COLLISION_FOR_OBJECT", LUA_NATIVE_CAM_DISABLE_CAM_COLLISION_FOR_OBJECT);
		CAM.set_function("_0x39073DA4EDDBC91D", LUA_NATIVE_CAM__0x39073DA4EDDBC91D);
		CAM.set_function("_0x70A6658D476C6187", LUA_NATIVE_CAM__0x70A6658D476C6187);
		CAM.set_function("_0x18C3DFAC458783BB", LUA_NATIVE_CAM__0x18C3DFAC458783BB);
		CAM.set_function("_0xF1A6FEEDF3776EF9", LUA_NATIVE_CAM__0xF1A6FEEDF3776EF9);
		CAM.set_function("_0xE6F364DE6C2FDEFE", LUA_NATIVE_CAM__0xE6F364DE6C2FDEFE);
		CAM.set_function("_0x0F1FFEF5D54AE832", LUA_NATIVE_CAM__0x0F1FFEF5D54AE832);
		CAM.set_function("_0x3C8F74E8FE751614", LUA_NATIVE_CAM__0x3C8F74E8FE751614);
		CAM.set_function("_0x06557F6D96C86881", LUA_NATIVE_CAM__0x06557F6D96C86881);
		CAM.set_function("IS_SPHERE_VISIBLE", LUA_NATIVE_CAM_IS_SPHERE_VISIBLE);
		CAM.set_function("_0x190F7DA1AC09A8EF", LUA_NATIVE_CAM__0x190F7DA1AC09A8EF);
		CAM.set_function("_SET_GAMEPLAY_CAM_INITIAL_ZOOM", LUA_NATIVE_CAM__SET_GAMEPLAY_CAM_INITIAL_ZOOM);
		CAM.set_function("_SET_GAMEPLAY_CAM_INITIAL_HEADING", LUA_NATIVE_CAM__SET_GAMEPLAY_CAM_INITIAL_HEADING);
		CAM.set_function("_SET_GAMEPLAY_CAM_INITIAL_PITCH", LUA_NATIVE_CAM__SET_GAMEPLAY_CAM_INITIAL_PITCH);
		CAM.set_function("SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE", LUA_NATIVE_CAM_SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE);
		CAM.set_function("SET_THIRD_PERSON_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE", LUA_NATIVE_CAM_SET_THIRD_PERSON_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE);
		CAM.set_function("SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE", LUA_NATIVE_CAM_SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE);
		CAM.set_function("SET_IN_VEHICLE_CAM_STATE_THIS_UPDATE", LUA_NATIVE_CAM_SET_IN_VEHICLE_CAM_STATE_THIS_UPDATE);
		CAM.set_function("DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE", LUA_NATIVE_CAM_DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE);
		CAM.set_function("DISABLE_FIRST_PERSON_FLASH_EFFECT_THIS_UPDATE", LUA_NATIVE_CAM_DISABLE_FIRST_PERSON_FLASH_EFFECT_THIS_UPDATE);
		CAM.set_function("_DISABLE_CINEMATIC_MODE_THIS_FRAME", LUA_NATIVE_CAM__DISABLE_CINEMATIC_MODE_THIS_FRAME);
		CAM.set_function("_IS_IN_CINEMATIC_MODE", LUA_NATIVE_CAM__IS_IN_CINEMATIC_MODE);
		CAM.set_function("_0x718C6ECF5E8CBDD4", LUA_NATIVE_CAM__0x718C6ECF5E8CBDD4);
		CAM.set_function("_FORCE_THIRD_PERSON_CAM_THIS_FRAME", LUA_NATIVE_CAM__FORCE_THIRD_PERSON_CAM_THIS_FRAME);
		CAM.set_function("_FORCE_THIRD_PERSON_CAM_FAR_THIS_FRAME", LUA_NATIVE_CAM__FORCE_THIRD_PERSON_CAM_FAR_THIS_FRAME);
		CAM.set_function("_FORCE_FIRST_PERSON_CAM_THIS_FRAME", LUA_NATIVE_CAM__FORCE_FIRST_PERSON_CAM_THIS_FRAME);
		CAM.set_function("_DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE_2", LUA_NATIVE_CAM__DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE_2);
		CAM.set_function("_0x632BE8D84846FA56", LUA_NATIVE_CAM__0x632BE8D84846FA56);
		CAM.set_function("_0x71D71E08A7ED5BD7", LUA_NATIVE_CAM__0x71D71E08A7ED5BD7);
		CAM.set_function("IS_FOLLOW_VEHICLE_CAM_ACTIVE", LUA_NATIVE_CAM_IS_FOLLOW_VEHICLE_CAM_ACTIVE);
		CAM.set_function("_0x7E40A01B11398FCB", LUA_NATIVE_CAM__0x7E40A01B11398FCB);
		CAM.set_function("IS_AIM_CAM_ACTIVE", LUA_NATIVE_CAM_IS_AIM_CAM_ACTIVE);
		CAM.set_function("IS_FIRST_PERSON_AIM_CAM_ACTIVE", LUA_NATIVE_CAM_IS_FIRST_PERSON_AIM_CAM_ACTIVE);
		CAM.set_function("IS_FIRST_PERSON_CAMERA_ACTIVE", LUA_NATIVE_CAM_IS_FIRST_PERSON_CAMERA_ACTIVE);
		CAM.set_function("_0xDC62CD70658E7A02", LUA_NATIVE_CAM__0xDC62CD70658E7A02);
		CAM.set_function("_0x796085220ADCC847", LUA_NATIVE_CAM__0x796085220ADCC847);
		CAM.set_function("_0xB6A80E1E3A5444F1", LUA_NATIVE_CAM__0xB6A80E1E3A5444F1);
		CAM.set_function("_0x8B1A5FE7E41E52B2", LUA_NATIVE_CAM__0x8B1A5FE7E41E52B2);
		CAM.set_function("GET_FIRST_PERSON_AIM_CAM_ZOOM_FACTOR", LUA_NATIVE_CAM_GET_FIRST_PERSON_AIM_CAM_ZOOM_FACTOR);
		CAM.set_function("SET_FIRST_PERSON_AIM_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE", LUA_NATIVE_CAM_SET_FIRST_PERSON_AIM_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE);
		CAM.set_function("SET_FIRST_PERSON_AIM_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE", LUA_NATIVE_CAM_SET_FIRST_PERSON_AIM_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE);
		CAM.set_function("_0xC205B3C54C6A4E37", LUA_NATIVE_CAM__0xC205B3C54C6A4E37);
		CAM.set_function("GET_FINAL_RENDERED_CAM_COORD", LUA_NATIVE_CAM_GET_FINAL_RENDERED_CAM_COORD);
		CAM.set_function("GET_FINAL_RENDERED_CAM_ROT", LUA_NATIVE_CAM_GET_FINAL_RENDERED_CAM_ROT);
		CAM.set_function("GET_FINAL_RENDERED_CAM_FOV", LUA_NATIVE_CAM_GET_FINAL_RENDERED_CAM_FOV);
		CAM.set_function("SET_GAMEPLAY_COORD_HINT", LUA_NATIVE_CAM_SET_GAMEPLAY_COORD_HINT);
		CAM.set_function("SET_GAMEPLAY_PED_HINT", LUA_NATIVE_CAM_SET_GAMEPLAY_PED_HINT);
		CAM.set_function("SET_GAMEPLAY_VEHICLE_HINT", LUA_NATIVE_CAM_SET_GAMEPLAY_VEHICLE_HINT);
		CAM.set_function("SET_GAMEPLAY_OBJECT_HINT", LUA_NATIVE_CAM_SET_GAMEPLAY_OBJECT_HINT);
		CAM.set_function("SET_GAMEPLAY_ENTITY_HINT", LUA_NATIVE_CAM_SET_GAMEPLAY_ENTITY_HINT);
		CAM.set_function("IS_GAMEPLAY_HINT_ACTIVE", LUA_NATIVE_CAM_IS_GAMEPLAY_HINT_ACTIVE);
		CAM.set_function("STOP_GAMEPLAY_HINT", LUA_NATIVE_CAM_STOP_GAMEPLAY_HINT);
		CAM.set_function("STOP_CODE_GAMEPLAY_HINT", LUA_NATIVE_CAM_STOP_CODE_GAMEPLAY_HINT);
		CAM.set_function("_0x88544C0E3291DCAE", LUA_NATIVE_CAM__0x88544C0E3291DCAE);
		CAM.set_function("SET_GAMEPLAY_HINT_FOV", LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_FOV);
		CAM.set_function("SET_GAMEPLAY_HINT_FOLLOW_DISTANCE_SCALAR", LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_FOLLOW_DISTANCE_SCALAR);
		CAM.set_function("SET_GAMEPLAY_HINT_BASE_ORBIT_PITCH_OFFSET", LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_BASE_ORBIT_PITCH_OFFSET);
		CAM.set_function("SET_GAMEPLAY_HINT_CAMERA_RELATIVE_SIDE_OFFSET", LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_CAMERA_RELATIVE_SIDE_OFFSET);
		CAM.set_function("SET_GAMEPLAY_HINT_CAMERA_RELATIVE_VERTICAL_OFFSET", LUA_NATIVE_CAM_SET_GAMEPLAY_HINT_CAMERA_RELATIVE_VERTICAL_OFFSET);
		CAM.set_function("_0xF48664E9C83825E3", LUA_NATIVE_CAM__0xF48664E9C83825E3);
		CAM.set_function("_0x1F6EBD94680252CE", LUA_NATIVE_CAM__0x1F6EBD94680252CE);
		CAM.set_function("_0xE28F73212A813E82", LUA_NATIVE_CAM__0xE28F73212A813E82);
		CAM.set_function("_0x4D2F46D1B28D90FB", LUA_NATIVE_CAM__0x4D2F46D1B28D90FB);
		CAM.set_function("_START_CAMERA_ORBIT", LUA_NATIVE_CAM__START_CAMERA_ORBIT);
		CAM.set_function("_0x641092322A8852AB", LUA_NATIVE_CAM__0x641092322A8852AB);
		CAM.set_function("_0xDB382FE20C2DA222", LUA_NATIVE_CAM__0xDB382FE20C2DA222);
		CAM.set_function("_0x2DD3149DC34A3F4C", LUA_NATIVE_CAM__0x2DD3149DC34A3F4C);
		CAM.set_function("_FREEZE_GAMEPLAY_CAM_THIS_FRAME", LUA_NATIVE_CAM__FREEZE_GAMEPLAY_CAM_THIS_FRAME);
		CAM.set_function("_0x3C486E334520579D", LUA_NATIVE_CAM__0x3C486E334520579D);
		CAM.set_function("_0x41E452A3C580D1A7", LUA_NATIVE_CAM__0x41E452A3C580D1A7);
		CAM.set_function("SET_CINEMATIC_BUTTON_ACTIVE", LUA_NATIVE_CAM_SET_CINEMATIC_BUTTON_ACTIVE);
		CAM.set_function("IS_CINEMATIC_CAM_RENDERING", LUA_NATIVE_CAM_IS_CINEMATIC_CAM_RENDERING);
		CAM.set_function("DISABLE_CINEMATIC_BONNET_CAMERA_THIS_UPDATE", LUA_NATIVE_CAM_DISABLE_CINEMATIC_BONNET_CAMERA_THIS_UPDATE);
		CAM.set_function("INVALIDATE_CINEMATIC_VEHICLE_IDLE_MODE", LUA_NATIVE_CAM_INVALIDATE_CINEMATIC_VEHICLE_IDLE_MODE);
		CAM.set_function("FORCE_CINEMATIC_RENDERING_THIS_UPDATE", LUA_NATIVE_CAM_FORCE_CINEMATIC_RENDERING_THIS_UPDATE);
		CAM.set_function("_0x9AC65A36D3C0C189", LUA_NATIVE_CAM__0x9AC65A36D3C0C189);
		CAM.set_function("_0x975F6EBB62632FE3", LUA_NATIVE_CAM__0x975F6EBB62632FE3);
		CAM.set_function("SET_CINEMATIC_MODE_ACTIVE", LUA_NATIVE_CAM_SET_CINEMATIC_MODE_ACTIVE);
		CAM.set_function("_0x1811A02277A9E49D", LUA_NATIVE_CAM__0x1811A02277A9E49D);
		CAM.set_function("_FORCE_CINEMATIC_DEATH_CAM_ON_PED", LUA_NATIVE_CAM__FORCE_CINEMATIC_DEATH_CAM_ON_PED);
		CAM.set_function("_REACTIVATE_PED_HEADSHOT_EXECUTE_SLOWCAM", LUA_NATIVE_CAM__REACTIVATE_PED_HEADSHOT_EXECUTE_SLOWCAM);
		CAM.set_function("_0x5B637D6F3B67716A", LUA_NATIVE_CAM__0x5B637D6F3B67716A);
		CAM.set_function("_0xC252C0CC969AF79A", LUA_NATIVE_CAM__0xC252C0CC969AF79A);
		CAM.set_function("_0xE2BB2D6A9FE2ECDE", LUA_NATIVE_CAM__0xE2BB2D6A9FE2ECDE);
		CAM.set_function("_SET_START_CINEMATIC_DEATH_CAM", LUA_NATIVE_CAM__SET_START_CINEMATIC_DEATH_CAM);
		CAM.set_function("_0x6072B7420A83A03F", LUA_NATIVE_CAM__0x6072B7420A83A03F);
		CAM.set_function("_0x1204EB53A5FBC63D", LUA_NATIVE_CAM__0x1204EB53A5FBC63D);
		CAM.set_function("_0x6519238858AF5479", LUA_NATIVE_CAM__0x6519238858AF5479);
		CAM.set_function("_CREATE_KILL_CAM", LUA_NATIVE_CAM__CREATE_KILL_CAM);
		CAM.set_function("_IS_CAM_PHOTOFX_RUNNING", LUA_NATIVE_CAM__IS_CAM_PHOTOFX_RUNNING);
		CAM.set_function("_0x6DFD37E586D4F44F", LUA_NATIVE_CAM__0x6DFD37E586D4F44F);
		CAM.set_function("_0x80D7A3E39B120BC4", LUA_NATIVE_CAM__0x80D7A3E39B120BC4);
		CAM.set_function("_0x63E5841A9264D016", LUA_NATIVE_CAM__0x63E5841A9264D016);
		CAM.set_function("_TRIGGER_MISSION_FAILED_CAM", LUA_NATIVE_CAM__TRIGGER_MISSION_FAILED_CAM);
		CAM.set_function("_0x16E9ABDD34DDD931", LUA_NATIVE_CAM__0x16E9ABDD34DDD931);
		CAM.set_function("IS_DEATH_FAIL_CAMERA_RUNNING", LUA_NATIVE_CAM_IS_DEATH_FAIL_CAMERA_RUNNING);
		CAM.set_function("_0x7CE9DC58E3E4755F", LUA_NATIVE_CAM__0x7CE9DC58E3E4755F);
		CAM.set_function("_0x3B8E3AD9677CE12B", LUA_NATIVE_CAM__0x3B8E3AD9677CE12B);
		CAM.set_function("_0xDF7F5BE9150E47E4", LUA_NATIVE_CAM__0xDF7F5BE9150E47E4);
		CAM.set_function("_0xB85C13E0BF1F2A1C", LUA_NATIVE_CAM__0xB85C13E0BF1F2A1C);
		CAM.set_function("_0x066167C63111D8CF", LUA_NATIVE_CAM__0x066167C63111D8CF);
		CAM.set_function("_0xA8BA2E0204D8486F", LUA_NATIVE_CAM__0xA8BA2E0204D8486F);
		CAM.set_function("_0xC3742F1FDF0A6824", LUA_NATIVE_CAM__0xC3742F1FDF0A6824);
		CAM.set_function("_0x0FF7125F07DEB84F", LUA_NATIVE_CAM__0x0FF7125F07DEB84F);
		CAM.set_function("_0x6CAB0BA160B168D2", LUA_NATIVE_CAM__0x6CAB0BA160B168D2);
		CAM.set_function("_LOAD_CINEMATIC_CAM_LOCATION", LUA_NATIVE_CAM__LOAD_CINEMATIC_CAM_LOCATION);
		CAM.set_function("_UNLOAD_CINEMATIC_CAMERA_LOCATION", LUA_NATIVE_CAM__UNLOAD_CINEMATIC_CAMERA_LOCATION);
		CAM.set_function("_IS_CINEMATIC_CAM_LOCATION_LOADED", LUA_NATIVE_CAM__IS_CINEMATIC_CAM_LOCATION_LOADED);
		CAM.set_function("_IS_CINEMATIC_CAM_LOCATION_LOADED_2", LUA_NATIVE_CAM__IS_CINEMATIC_CAM_LOCATION_LOADED_2);
		CAM.set_function("_0x465F04F68AD38197", LUA_NATIVE_CAM__0x465F04F68AD38197);
		CAM.set_function("_0xEA113BF9B0C0C5D7", LUA_NATIVE_CAM__0xEA113BF9B0C0C5D7);
		CAM.set_function("_CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT_2", LUA_NATIVE_CAM__CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT_2);
		CAM.set_function("CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT", LUA_NATIVE_CAM_CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT);
		CAM.set_function("_0xA54D643D0773EB65", LUA_NATIVE_CAM__0xA54D643D0773EB65);
		CAM.set_function("CINEMATIC_LOCATION_STOP_SCRIPTED_SHOT_EVENT", LUA_NATIVE_CAM_CINEMATIC_LOCATION_STOP_SCRIPTED_SHOT_EVENT);
		CAM.set_function("_0xC3AEBB276825A359", LUA_NATIVE_CAM__0xC3AEBB276825A359);
		CAM.set_function("_0x1D931B7CC0EE3956", LUA_NATIVE_CAM__0x1D931B7CC0EE3956);
		CAM.set_function("_CINEMATIC_LOCATION_SET_LOCATION_AND_ROTATION", LUA_NATIVE_CAM__CINEMATIC_LOCATION_SET_LOCATION_AND_ROTATION);
		CAM.set_function("CINEMATIC_LOCATION_OVERRIDE_TARGET_ENTITY_THIS_UPDATE", LUA_NATIVE_CAM_CINEMATIC_LOCATION_OVERRIDE_TARGET_ENTITY_THIS_UPDATE);
		CAM.set_function("_LOAD_CAMERA_DATA_DICT", LUA_NATIVE_CAM__LOAD_CAMERA_DATA_DICT);
		CAM.set_function("_UNLOAD_CAMERA_DATA_DICT", LUA_NATIVE_CAM__UNLOAD_CAMERA_DATA_DICT);
		CAM.set_function("_IS_CAM_DATA_DICT_LOADED", LUA_NATIVE_CAM__IS_CAM_DATA_DICT_LOADED);
		CAM.set_function("_0xC285FD21294A1C49", LUA_NATIVE_CAM__0xC285FD21294A1C49);
		CAM.set_function("_CAM_CREATE", LUA_NATIVE_CAM__CAM_CREATE);
		CAM.set_function("_CAM_DESTROY", LUA_NATIVE_CAM__CAM_DESTROY);
		CAM.set_function("_IS_CAMERA_AVAILABLE", LUA_NATIVE_CAM__IS_CAMERA_AVAILABLE);
		CAM.set_function("_0x4138EE36BC3DC0A7", LUA_NATIVE_CAM__0x4138EE36BC3DC0A7);
		CAM.set_function("_0xFEB8646818294C75", LUA_NATIVE_CAM__0xFEB8646818294C75);
		CAM.set_function("_0x29E6655DF3590B0D", LUA_NATIVE_CAM__0x29E6655DF3590B0D);
		CAM.set_function("_0xAC77757C05DE9E5A", LUA_NATIVE_CAM__0xAC77757C05DE9E5A);
		CAM.set_function("_0x8E036B41C37D0E5F", LUA_NATIVE_CAM__0x8E036B41C37D0E5F);
		CAM.set_function("_0x1D9F72DD4FD9A9D7", LUA_NATIVE_CAM__0x1D9F72DD4FD9A9D7);
		CAM.set_function("_CAM_CREATE_2", LUA_NATIVE_CAM__CAM_CREATE_2);
		CAM.set_function("_0x728491FB3DFFEF99", LUA_NATIVE_CAM__0x728491FB3DFFEF99);
		CAM.set_function("_0x14C4A49E36C29E49", LUA_NATIVE_CAM__0x14C4A49E36C29E49);
		CAM.set_function("_0xF824530B612FE0CE", LUA_NATIVE_CAM__0xF824530B612FE0CE);
		CAM.set_function("_0xEF9A3132A0AA6B19", LUA_NATIVE_CAM__0xEF9A3132A0AA6B19);
		CAM.set_function("_0x5060FA977CEA4455", LUA_NATIVE_CAM__0x5060FA977CEA4455);
		CAM.set_function("_GET_PHOTO_MODE_FOCAL_LENGTH", LUA_NATIVE_CAM__GET_PHOTO_MODE_FOCAL_LENGTH);
		CAM.set_function("_GET_PHOTO_MODE_FOCUS_DISTANCE", LUA_NATIVE_CAM__GET_PHOTO_MODE_FOCUS_DISTANCE);
		CAM.set_function("_GET_PHOTO_MODE_DOF", LUA_NATIVE_CAM__GET_PHOTO_MODE_DOF);
		CAM.set_function("_0x2AB7C81B3F70570C", LUA_NATIVE_CAM__0x2AB7C81B3F70570C);
		CAM.set_function("_0x8505E05FC8822843", LUA_NATIVE_CAM__0x8505E05FC8822843);
	}
}
