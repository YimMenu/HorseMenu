---@meta

---@class CAM
CAM = {}

---@param bSetActive boolean
---@param DoGameCamInterp boolean
---@param Duration integer
---@param bShouldLockInterpolationSourceFrame boolean
---@param bShouldApplyAcrossAllThreads boolean
---@param RenderingOptions integer
function CAM.RENDER_SCRIPT_CAMS(bSetActive, DoGameCamInterp, Duration, bShouldLockInterpolationSourceFrame, bShouldApplyAcrossAllThreads, RenderingOptions) end

---@param bShouldApplyAcrossAllThreads boolean
---@param DistanceToBlend number
---@param BlendType integer
---@param p3 boolean
---@param p4 boolean
---@param p5 boolean
function CAM.STOP_RENDERING_SCRIPT_CAMS_USING_CATCH_UP(bShouldApplyAcrossAllThreads, DistanceToBlend, BlendType, p3, p4, p5) end

---@param CameraName any
---@param StartActivated boolean
---@return integer
function CAM.CREATE_CAM(CameraName, StartActivated) end

---@param CameraName any
---@param vecPosX number
---@param vecPosY number
---@param vecPosZ number
---@param vecRotX number
---@param vecRotY number
---@param vecRotZ number
---@param FOV number
---@param StartActivated boolean
---@param RotOrder integer
---@return integer
function CAM.CREATE_CAM_WITH_PARAMS(CameraName, vecPosX, vecPosY, vecPosZ, vecRotX, vecRotY, vecRotZ, FOV, StartActivated, RotOrder) end

---@param Camera integer
---@param StartActivated boolean
---@return integer
function CAM.CREATE_CAMERA(Camera, StartActivated) end

---@param Camera integer
---@param vecPosX number
---@param vecPosY number
---@param vecPosZ number
---@param vecRotX number
---@param vecRotY number
---@param vecRotZ number
---@param FOV number
---@param StartActivated boolean
---@param RotOrder integer
---@return integer
function CAM.CREATE_CAMERA_WITH_PARAMS(Camera, vecPosX, vecPosY, vecPosZ, vecRotX, vecRotY, vecRotZ, FOV, StartActivated, RotOrder) end

---@param CameraIndex integer
---@param bShouldApplyAcrossAllThreads boolean
function CAM.DESTROY_CAM(CameraIndex, bShouldApplyAcrossAllThreads) end

---@param bShouldApplyAcrossAllThreads boolean
function CAM.DESTROY_ALL_CAMS(bShouldApplyAcrossAllThreads) end

---@param CameraIndex integer
---@return boolean
function CAM.DOES_CAM_EXIST(CameraIndex) end

---@param CameraIndex integer
---@param bActiveState boolean
function CAM.SET_CAM_ACTIVE(CameraIndex, bActiveState) end

---@param CameraIndex integer
---@return boolean
function CAM.IS_CAM_ACTIVE(CameraIndex) end

---@param CamIndex integer
---@return boolean
function CAM.IS_CAM_RENDERING(CamIndex) end

---@return integer
function CAM.GET_RENDERING_CAM() end

---@param CameraIndex integer
---@return Vector3
function CAM.GET_CAM_COORD(CameraIndex) end

---@param CameraIndex integer
---@param RotOrder integer
---@return Vector3
function CAM.GET_CAM_ROT(CameraIndex, RotOrder) end

---@param CameraIndex integer
---@return number
function CAM.GET_CAM_FOV(CameraIndex) end

---@param CameraIndex integer
---@param vPosX number
---@param vPosY number
---@param vPosZ number
---@param vRotX number
---@param vRotY number
---@param vRotZ number
---@param FOV number
---@param Duration integer
---@param GraphTypePos integer
---@param GraphTypeRot integer
---@param RotOrder integer
---@param p12 boolean
---@param p13 boolean
function CAM.SET_CAM_PARAMS(CameraIndex, vPosX, vPosY, vPosZ, vRotX, vRotY, vRotZ, FOV, Duration, GraphTypePos, GraphTypeRot, RotOrder, p12, p13) end

---@param CameraIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
function CAM.SET_CAM_COORD(CameraIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ) end

---@param CameraIndex integer
---@param VecNewRotX number
---@param VecNewRotY number
---@param VecNewRotZ number
---@param RotOrder integer
function CAM.SET_CAM_ROT(CameraIndex, VecNewRotX, VecNewRotY, VecNewRotZ, RotOrder) end

---@param CameraIndex integer
---@param FOV number
function CAM.SET_CAM_FOV(CameraIndex, FOV) end

---@param CameraIndex integer
---@param NearClip number
function CAM.SET_CAM_NEAR_CLIP(CameraIndex, NearClip) end

---@param CameraIndex integer
---@param FarClip number
function CAM.SET_CAM_FAR_CLIP(CameraIndex, FarClip) end

---@param CameraIndex integer
---@param Strength number
function CAM.SET_CAM_MOTION_BLUR_STRENGTH(CameraIndex, Strength) end

function CAM._0xFC3F638BE2B6BB02() end

---@param cam integer
---@param args integer
function CAM._0xE4B7945EF4F1BFB2(cam, args) end

---@param p0 any
function CAM._0x1FC6C727D30FFDDE(p0) end

---@param CameraIndex integer
---@param EntityIndex integer
---@param vecOffsetX number
---@param vecOffsetY number
---@param vecOffsetZ number
---@param bOffsetIsRelative boolean
function CAM.ATTACH_CAM_TO_ENTITY(CameraIndex, EntityIndex, vecOffsetX, vecOffsetY, vecOffsetZ, bOffsetIsRelative) end

---@param CameraIndex integer
---@param PedIndex integer
---@param BoneTag integer
---@param vecOffsetX number
---@param vecOffsetY number
---@param vecOffsetZ number
---@param bOffsetIsRelative boolean
function CAM.ATTACH_CAM_TO_PED_BONE(CameraIndex, PedIndex, BoneTag, vecOffsetX, vecOffsetY, vecOffsetZ, bOffsetIsRelative) end

---@param CameraIndex integer
function CAM.DETACH_CAM(CameraIndex) end

---@param CameraIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
function CAM.POINT_CAM_AT_COORD(CameraIndex, VecCoorsX, VecCoorsY, VecCoorsZ) end

---@param CameraIndex integer
---@param EntityIndex integer
---@param vecOffsetX number
---@param vecOffsetY number
---@param vecOffsetZ number
---@param bOffsetIsRelative boolean
function CAM.POINT_CAM_AT_ENTITY(CameraIndex, EntityIndex, vecOffsetX, vecOffsetY, vecOffsetZ, bOffsetIsRelative) end

---@param CameraIndex integer
function CAM.STOP_CAM_POINTING(CameraIndex) end

---@param cam integer
---@param distance number
function CAM._SET_CAM_FOCUS_DISTANCE(cam, distance) end

---@param cam integer
---@param pause boolean
function CAM._PAUSE_CAMERA_FOCUS(cam, pause) end

---@param CameraIndex integer
---@param bState boolean
function CAM.SET_CAM_AFFECTS_AIMING(CameraIndex, bState) end

---@param CameraIndex integer
---@param bState boolean
function CAM.SET_CAM_CONTROLS_MINI_MAP_HEADING(CameraIndex, bState) end

---@param CameraIndex integer
---@param enable boolean
function CAM.ALLOW_MOTION_BLUR_DECAY(CameraIndex, enable) end

---@param CameraIndex integer
---@param vPosX number
---@param vPosY number
---@param vPosZ number
---@param vRotX number
---@param vRotY number
---@param vRotZ number
---@param iDuration integer
---@param Flags integer
---@param RotOrder integer
function CAM.ADD_CAM_SPLINE_NODE(CameraIndex, vPosX, vPosY, vPosZ, vRotX, vRotY, vRotZ, iDuration, Flags, RotOrder) end

---@param CameraIndex integer
---@param phase number
function CAM.SET_CAM_SPLINE_PHASE(CameraIndex, phase) end

---@param CameraIndex integer
---@return number
function CAM.GET_CAM_SPLINE_PHASE(CameraIndex) end

---@param CameraIndex integer
---@param Duration integer
function CAM.SET_CAM_SPLINE_DURATION(CameraIndex, Duration) end

---@param CameraIndex integer
---@param SmoothingStyle integer
function CAM.SET_CAM_SPLINE_SMOOTHING_STYLE(CameraIndex, SmoothingStyle) end

---@param DestinationCam integer
---@param OriginCam integer
---@param Duration integer
---@param GraphTypePos integer
---@param GraphTypeRot integer
function CAM.SET_CAM_ACTIVE_WITH_INTERP(DestinationCam, OriginCam, Duration, GraphTypePos, GraphTypeRot) end

---@param CameraIndex integer
---@return boolean
function CAM.IS_CAM_INTERPOLATING(CameraIndex) end

---@param CameraIndex integer
---@param ShakeName any
---@param fAmplitudeScalar number
function CAM.SHAKE_CAM(CameraIndex, ShakeName, fAmplitudeScalar) end

---@param CameraIndex integer
---@return boolean
function CAM.IS_CAM_SHAKING(CameraIndex) end

---@param CameraIndex integer
---@param bStopImmediately boolean
function CAM.STOP_CAM_SHAKING(CameraIndex, bStopImmediately) end

---@param CameraIndex integer
---@param AnimName any
---@param AnimDictName any
---@param vOriginPositionX number
---@param vOriginPositionY number
---@param vOriginPositionZ number
---@param vOriginRotationX number
---@param vOriginRotationY number
---@param vOriginRotationZ number
---@param AnimFlags integer
---@param RotOrder integer
---@return boolean
function CAM.PLAY_CAM_ANIM(CameraIndex, AnimName, AnimDictName, vOriginPositionX, vOriginPositionY, vOriginPositionZ, vOriginRotationX, vOriginRotationY, vOriginRotationZ, AnimFlags, RotOrder) end

function CAM._0xCF69EA05CD9C33C9() end

---@return boolean
function CAM._IS_ANIM_SCENE_CAM_ACTIVE() end

---@return boolean
function CAM.IS_SCREEN_FADED_OUT() end

---@return boolean
function CAM.IS_SCREEN_FADED_IN() end

---@return boolean
function CAM.IS_SCREEN_FADING_OUT() end

---@return boolean
function CAM.IS_SCREEN_FADING_IN() end

---@param time integer
function CAM.DO_SCREEN_FADE_IN(time) end

---@param time integer
function CAM.DO_SCREEN_FADE_OUT(time) end

---@return boolean
function CAM.HAS_LETTER_BOX() end

---@param p0 boolean
---@param p1 boolean
function CAM._REQUEST_LETTER_BOX_NOW(p0, p1) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 integer
---@param p4 boolean
---@param p5 boolean
function CAM._REQUEST_LETTER_BOX_OVERTIME(p0, p1, p2, p3, p4, p5) end

function CAM._FORCE_LETTER_BOX_THIS_UPDATE() end

---@return number
function CAM.GET_LETTER_BOX_RATIO() end

---@return any
function CAM._0x73FF6BE63DC18819() end

---@return any
function CAM._0x450769C833D58844() end

---@param bSet boolean
---@param Duration integer
function CAM.SET_WIDESCREEN_BORDERS(bSet, Duration) end

---@return Vector3
function CAM.GET_GAMEPLAY_CAM_COORD() end

---@param RotOrder integer
---@return Vector3
function CAM.GET_GAMEPLAY_CAM_ROT(RotOrder) end

---@return number
function CAM.GET_GAMEPLAY_CAM_FOV() end

---@param maxStrength number
function CAM.SET_GAMEPLAY_CAM_MAX_MOTION_BLUR_STRENGTH_THIS_UPDATE(maxStrength) end

---@return number
function CAM.GET_GAMEPLAY_CAM_RELATIVE_HEADING() end

---@param heading number
---@param p1 number
function CAM.SET_GAMEPLAY_CAM_RELATIVE_HEADING(heading, p1) end

---@return number
function CAM.GET_GAMEPLAY_CAM_RELATIVE_PITCH() end

---@param pitch number
---@param smoothRate number
function CAM.SET_GAMEPLAY_CAM_RELATIVE_PITCH(pitch, smoothRate) end

---@param p0 any
function CAM._0x0961B089947BA6D0(p0) end

function CAM._0x04084490CC302CFB() end

---@param isFirstPersonThisFrame boolean
function CAM.SET_SCRIPTED_CAMERA_IS_FIRST_PERSON_THIS_FRAME(isFirstPersonThisFrame) end

---@return boolean
function CAM._IS_IN_FULL_FIRST_PERSON_MODE() end

---@param ShakeName any
---@param fAmplitudeScalar number
function CAM.SHAKE_GAMEPLAY_CAM(ShakeName, fAmplitudeScalar) end

---@param shakeName any
---@param intensity number
function CAM._0xC3E9E5D4F413B773(shakeName, intensity) end

---@return boolean
function CAM.IS_GAMEPLAY_CAM_SHAKING() end

---@param shakeName any
---@return boolean
function CAM._0x0060B31968E60E41(shakeName) end

---@param fAmplitudeScalar number
function CAM.SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE(fAmplitudeScalar) end

---@param shakeName any
---@param intensity number
function CAM._0xFEFDDC6E8FDF8A75(shakeName, intensity) end

---@param bStopImmediately boolean
function CAM.STOP_GAMEPLAY_CAM_SHAKING(bStopImmediately) end

---@param shakeName any
---@param p1 boolean
function CAM._STOP_GAMEPLAY_CAM_SHAKING_WITH_NAME(shakeName, p1) end

---@param PedIndex integer
function CAM.SET_GAMEPLAY_CAM_FOLLOW_PED_THIS_UPDATE(PedIndex) end

---@return boolean
function CAM.IS_GAMEPLAY_CAM_RENDERING() end

---@return boolean
function CAM.IS_INTERPOLATING_FROM_SCRIPT_CAMS() end

---@return boolean
function CAM.IS_INTERPOLATING_TO_SCRIPT_CAMS() end

---@return boolean
function CAM.IS_GAMEPLAY_CAM_LOOKING_BEHIND() end

---@param Index integer
function CAM.SET_GAMEPLAY_CAM_IGNORE_ENTITY_COLLISION_THIS_UPDATE(Index) end

---@param object integer
function CAM.DISABLE_CAM_COLLISION_FOR_OBJECT(object) end

---@param p0 any
function CAM._0x39073DA4EDDBC91D(p0) end

function CAM._0x70A6658D476C6187() end

function CAM._0x18C3DFAC458783BB() end

function CAM._0xF1A6FEEDF3776EF9() end

function CAM._0xE6F364DE6C2FDEFE() end

function CAM._0x0F1FFEF5D54AE832() end

function CAM._0x3C8F74E8FE751614() end

function CAM._0x06557F6D96C86881() end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param radius number
---@return boolean
function CAM.IS_SPHERE_VISIBLE(VecCoorsX, VecCoorsY, VecCoorsZ, radius) end

---@return any
function CAM._0x190F7DA1AC09A8EF() end

---@param camInitialZoom number
function CAM._SET_GAMEPLAY_CAM_INITIAL_ZOOM(camInitialZoom) end

---@param camInitialHeading number
function CAM._SET_GAMEPLAY_CAM_INITIAL_HEADING(camInitialHeading) end

---@param camInitialPitch number
function CAM._SET_GAMEPLAY_CAM_INITIAL_PITCH(camInitialPitch) end

---@param minRelativeHeading number
---@param maxRelativeHeading number
function CAM.SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(minRelativeHeading, maxRelativeHeading) end

---@param minRelativePitch number
---@param maxRelativePitch number
function CAM.SET_THIRD_PERSON_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(minRelativePitch, maxRelativePitch) end

---@param minDistance number
---@param maxDistance number
function CAM.SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE(minDistance, maxDistance) end

---@param Vehicle integer
---@param InVehicleState integer
function CAM.SET_IN_VEHICLE_CAM_STATE_THIS_UPDATE(Vehicle, InVehicleState) end

function CAM.DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE() end

function CAM.DISABLE_FIRST_PERSON_FLASH_EFFECT_THIS_UPDATE() end

function CAM._DISABLE_CINEMATIC_MODE_THIS_FRAME() end

---@return boolean
function CAM._IS_IN_CINEMATIC_MODE() end

function CAM._0x718C6ECF5E8CBDD4() end

function CAM._FORCE_THIRD_PERSON_CAM_THIS_FRAME() end

function CAM._FORCE_THIRD_PERSON_CAM_FAR_THIS_FRAME() end

---@return boolean
function CAM._FORCE_FIRST_PERSON_CAM_THIS_FRAME() end

function CAM._DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE_2() end

function CAM._0x632BE8D84846FA56() end

---@param p0 any
function CAM._0x71D71E08A7ED5BD7(p0) end

---@return boolean
function CAM.IS_FOLLOW_VEHICLE_CAM_ACTIVE() end

function CAM._0x7E40A01B11398FCB() end

---@return boolean
function CAM.IS_AIM_CAM_ACTIVE() end

---@return boolean
function CAM.IS_FIRST_PERSON_AIM_CAM_ACTIVE() end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function CAM.IS_FIRST_PERSON_CAMERA_ACTIVE(p0, p1, p2) end

---@return any
function CAM._0xDC62CD70658E7A02() end

---@return any
function CAM._0x796085220ADCC847() end

---@return any
function CAM._0xB6A80E1E3A5444F1() end

---@return any
function CAM._0x8B1A5FE7E41E52B2() end

---@return number
function CAM.GET_FIRST_PERSON_AIM_CAM_ZOOM_FACTOR() end

---@param MinRelativeHeading number
---@param MaxRelativeHeading number
function CAM.SET_FIRST_PERSON_AIM_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(MinRelativeHeading, MaxRelativeHeading) end

---@param MinRelativePitch number
---@param MaxRelativePitch number
function CAM.SET_FIRST_PERSON_AIM_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(MinRelativePitch, MaxRelativePitch) end

---@param p0 any
function CAM._0xC205B3C54C6A4E37(p0) end

---@return Vector3
function CAM.GET_FINAL_RENDERED_CAM_COORD() end

---@param RotOrder integer
---@return Vector3
function CAM.GET_FINAL_RENDERED_CAM_ROT(RotOrder) end

---@return number
function CAM.GET_FINAL_RENDERED_CAM_FOV() end

---@param vCoordX number
---@param vCoordY number
---@param vCoordZ number
---@param iDwellTime integer
---@param iInterpTo integer
---@param iInterpFrom integer
---@param Type integer
function CAM.SET_GAMEPLAY_COORD_HINT(vCoordX, vCoordY, vCoordZ, iDwellTime, iInterpTo, iInterpFrom, Type) end

---@param Ped integer
---@param OffsetX number
---@param OffsetY number
---@param OffsetZ number
---@param RelativeOffset boolean
---@param iDwellTime integer
---@param iInterpTo integer
---@param iInterpFrom integer
function CAM.SET_GAMEPLAY_PED_HINT(Ped, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom) end

---@param Vehicle integer
---@param OffsetX number
---@param OffsetY number
---@param OffsetZ number
---@param RelativeOffset boolean
---@param iDwellTime integer
---@param iInterpTo integer
---@param iInterpFrom integer
function CAM.SET_GAMEPLAY_VEHICLE_HINT(Vehicle, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom) end

---@param Obejct integer
---@param OffsetX number
---@param OffsetY number
---@param OffsetZ number
---@param RelativeOffset boolean
---@param iDwellTime integer
---@param iInterpTo integer
---@param iInterpFrom integer
function CAM.SET_GAMEPLAY_OBJECT_HINT(Obejct, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom) end

---@param Enttity integer
---@param OffsetX number
---@param OffsetY number
---@param OffsetZ number
---@param RelativeOffset boolean
---@param iDwellTime integer
---@param iInterpTo integer
---@param iInterpFrom integer
---@param Type integer
function CAM.SET_GAMEPLAY_ENTITY_HINT(Enttity, OffsetX, OffsetY, OffsetZ, RelativeOffset, iDwellTime, iInterpTo, iInterpFrom, Type) end

---@return boolean
function CAM.IS_GAMEPLAY_HINT_ACTIVE() end

---@param bStopImmediately boolean
function CAM.STOP_GAMEPLAY_HINT(bStopImmediately) end

---@param StopImmediately boolean
function CAM.STOP_CODE_GAMEPLAY_HINT(StopImmediately) end

---@param p0 boolean
function CAM._0x88544C0E3291DCAE(p0) end

---@param fov number
function CAM.SET_GAMEPLAY_HINT_FOV(fov) end

---@param DistanceScalar number
function CAM.SET_GAMEPLAY_HINT_FOLLOW_DISTANCE_SCALAR(DistanceScalar) end

---@param BasePitchOffset number
function CAM.SET_GAMEPLAY_HINT_BASE_ORBIT_PITCH_OFFSET(BasePitchOffset) end

---@param SideOffset number
function CAM.SET_GAMEPLAY_HINT_CAMERA_RELATIVE_SIDE_OFFSET(SideOffset) end

---@param VerticalOffset number
function CAM.SET_GAMEPLAY_HINT_CAMERA_RELATIVE_VERTICAL_OFFSET(VerticalOffset) end

---@param p0 any
---@param p1 any
function CAM._0xF48664E9C83825E3(p0, p1) end

---@param p0 any
---@param p1 any
function CAM._0x1F6EBD94680252CE(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function CAM._0xE28F73212A813E82(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function CAM._0x4D2F46D1B28D90FB(p0, p1) end

---@param p0 integer
function CAM._START_CAMERA_ORBIT(p0) end

function CAM._0x641092322A8852AB() end

---@param p0 any
function CAM._0xDB382FE20C2DA222(p0) end

---@param p0 any
function CAM._0x2DD3149DC34A3F4C(p0) end

function CAM._FREEZE_GAMEPLAY_CAM_THIS_FRAME() end

function CAM._0x3C486E334520579D() end

function CAM._0x41E452A3C580D1A7() end

---@param bEnable boolean
function CAM.SET_CINEMATIC_BUTTON_ACTIVE(bEnable) end

---@return boolean
function CAM.IS_CINEMATIC_CAM_RENDERING() end

function CAM.DISABLE_CINEMATIC_BONNET_CAMERA_THIS_UPDATE() end

function CAM.INVALIDATE_CINEMATIC_VEHICLE_IDLE_MODE() end

---@param ActiveThisFrame boolean
function CAM.FORCE_CINEMATIC_RENDERING_THIS_UPDATE(ActiveThisFrame) end

---@param p0 any
function CAM._0x9AC65A36D3C0C189(p0) end

---@return boolean
function CAM._0x975F6EBB62632FE3() end

---@param Active boolean
function CAM.SET_CINEMATIC_MODE_ACTIVE(Active) end

---@return boolean
function CAM._0x1811A02277A9E49D() end

---@param targetPed integer
function CAM._FORCE_CINEMATIC_DEATH_CAM_ON_PED(targetPed) end

---@param ped integer
---@param p1 integer
function CAM._REACTIVATE_PED_HEADSHOT_EXECUTE_SLOWCAM(ped, p1) end

---@param p0 any
function CAM._0x5B637D6F3B67716A(p0) end

---@param p0 any
function CAM._0xC252C0CC969AF79A(p0) end

---@param p0 any
function CAM._0xE2BB2D6A9FE2ECDE(p0) end

---@param p0 boolean
function CAM._SET_START_CINEMATIC_DEATH_CAM(p0) end

---@return any
function CAM._0x6072B7420A83A03F() end

---@return boolean
function CAM._0x1204EB53A5FBC63D() end

---@param p0 any
function CAM._0x6519238858AF5479(p0) end

---@param ped integer
function CAM._CREATE_KILL_CAM(ped) end

---@return boolean
function CAM._IS_CAM_PHOTOFX_RUNNING() end

---@return any
function CAM._0x6DFD37E586D4F44F() end

---@return any
function CAM._0x80D7A3E39B120BC4() end

---@param toggle boolean
function CAM._0x63E5841A9264D016(toggle) end

function CAM._TRIGGER_MISSION_FAILED_CAM() end

function CAM._0x16E9ABDD34DDD931() end

---@return boolean
function CAM.IS_DEATH_FAIL_CAMERA_RUNNING() end

---@return any
function CAM._0x7CE9DC58E3E4755F() end

---@param p0 any
---@param p1 any
---@param p2 any
function CAM._0x3B8E3AD9677CE12B(p0, p1, p2) end

---@param p0 any
function CAM._0xDF7F5BE9150E47E4(p0) end

---@param p0 any
function CAM._0xB85C13E0BF1F2A1C(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function CAM._0x066167C63111D8CF(p0, p1, p2, p3, p4) end

function CAM._0xA8BA2E0204D8486F() end

function CAM._0xC3742F1FDF0A6824() end

---@param p0 any
---@param p1 any
function CAM._0x0FF7125F07DEB84F(p0, p1) end

function CAM._0x6CAB0BA160B168D2() end

---@param locationDictName any
function CAM._LOAD_CINEMATIC_CAM_LOCATION(locationDictName) end

---@param dictionaryName any
function CAM._UNLOAD_CINEMATIC_CAMERA_LOCATION(dictionaryName) end

---@param sLocationDictName any
---@return boolean
function CAM._IS_CINEMATIC_CAM_LOCATION_LOADED(sLocationDictName) end

---@param locationDictName any
---@return boolean
function CAM._IS_CINEMATIC_CAM_LOCATION_LOADED_2(locationDictName) end

---@param dictionary any
---@param shotName any
---@param duration integer
---@return any
function CAM._0x465F04F68AD38197(dictionary, shotName, duration) end

---@param dictionary any
---@param shotName any
---@param duration integer
---@return any
function CAM._0xEA113BF9B0C0C5D7(dictionary, shotName, duration) end

---@param dictionary any
---@param shotName any
---@param duration integer
function CAM._CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT_2(dictionary, shotName, duration) end

---@param dictionary any
---@param shotName any
---@param cameraName any
---@param p3 any
function CAM.CINEMATIC_LOCATION_TRIGGER_SCRIPTED_SHOT_EVENT(dictionary, shotName, cameraName, p3) end

---@param dictionary any
---@param shotName any
---@param duration integer
function CAM._0xA54D643D0773EB65(dictionary, shotName, duration) end

---@param p0 any
---@param p1 any
---@param p2 any
function CAM.CINEMATIC_LOCATION_STOP_SCRIPTED_SHOT_EVENT(p0, p1, p2) end

---@param dictionary any
---@param shotName any
---@param duration integer
---@return boolean
function CAM._0xC3AEBB276825A359(dictionary, shotName, duration) end

---@param dictionary any
---@param shotName any
---@param cameraName any
---@return boolean
function CAM._0x1D931B7CC0EE3956(dictionary, shotName, cameraName) end

---@param name any
---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
function CAM._CINEMATIC_LOCATION_SET_LOCATION_AND_ROTATION(name, x, y, z, rotX, rotY, rotZ) end

---@param name any
---@param entity integer
function CAM.CINEMATIC_LOCATION_OVERRIDE_TARGET_ENTITY_THIS_UPDATE(name, entity) end

---@param cameraDictionary any
function CAM._LOAD_CAMERA_DATA_DICT(cameraDictionary) end

---@param cameraDictionary any
function CAM._UNLOAD_CAMERA_DATA_DICT(cameraDictionary) end

---@param cameraDictionary any
---@return boolean
function CAM._IS_CAM_DATA_DICT_LOADED(cameraDictionary) end

---@param cameraDictionary any
---@return boolean
function CAM._0xC285FD21294A1C49(cameraDictionary) end

---@param cameraDictionary any
function CAM._CAM_CREATE(cameraDictionary) end

---@param cameraDictionary any
function CAM._CAM_DESTROY(cameraDictionary) end

---@param cameraDictionary any
---@return boolean
function CAM._IS_CAMERA_AVAILABLE(cameraDictionary) end

---@param p0 any
---@param p1 any
---@return any
function CAM._0x4138EE36BC3DC0A7(p0, p1) end

---@param p0 any
---@param p1 any
function CAM._0xFEB8646818294C75(p0, p1) end

---@param p0 any
function CAM._0x29E6655DF3590B0D(p0) end

---@param cameraDictionary any
function CAM._0xAC77757C05DE9E5A(cameraDictionary) end

---@param p0 any
function CAM._0x8E036B41C37D0E5F(p0) end

---@param p0 any
function CAM._0x1D9F72DD4FD9A9D7(p0) end

---@param cameraDictionary any
function CAM._CAM_CREATE_2(cameraDictionary) end

---@param p0 any
function CAM._0x728491FB3DFFEF99(p0) end

---@return any
function CAM._0x14C4A49E36C29E49() end

---@return any
function CAM._0xF824530B612FE0CE() end

---@return any
function CAM._0xEF9A3132A0AA6B19() end

---@return any
function CAM._0x5060FA977CEA4455() end

---@return number
function CAM._GET_PHOTO_MODE_FOCAL_LENGTH() end

---@return number
function CAM._GET_PHOTO_MODE_FOCUS_DISTANCE() end

---@return number
function CAM._GET_PHOTO_MODE_DOF() end

---@return any
function CAM._0x2AB7C81B3F70570C() end

---@param p0 any
function CAM._0x8505E05FC8822843(p0) end
