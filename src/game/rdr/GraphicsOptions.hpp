#pragma once
#include <cstdint>

class GraphicsOptions
{
public:
	char m_padding_0[0x8];
	int gfx_adv_shadowSoftShadows; // 8
	char m_padding_1[0x4];
	bool m_motion_blur;
	char m_padding_12[0x3];
	int gfx_adv_particleLightingQuality;
	char m_padding_2[0x4];
	int gfx_adv_waterRefractionQuality;
	int gfx_adv_waterReflectionQuality;
	char m_padding_3[0x4];
	int gfx_adv_waterLightingQuality;
	int gfx_adv_furDisplayQuality;
	char m_padding_4[0x4];
	int gfx_adv_shadowGrassShadows;
	char m_padding_5[0x10];
	int gfx_adv_scatteringVolumeQuality;
	int gfx_adv_volumetricsRaymarchQuality;
	int gfx_adv_volumetricsLightingQuality;
	char m_padding_6[0x4];
	int gfx_adv_terrainShadowQuality;
	char m_padding_7[0x58];
	int m_gfx_tessellation; 
	int m_gfx_shadowQuality;
	int m_gfx_farShadowQuality;
	int m_gfx_reflectionQuality;
	int m_gfx_mirrorQuality;
	int m_gfx_ssao;
	int m_gfx_textureQuality;
	int m_gfx_particleQuality;
	int m_gfx_waterQuality;
	int m_gfx_volumetricsQuality;
	int m_gfx_lightingQuality;
	int m_gfx_ambientLightingQuality;
	char m_padding_8[0x28];
	bool m_hdr;
	char m_padding_9[0x2F];
	uint32_t m_screen_resolution_x;
	uint32_t m_screen_resolution_y;
	char m_padding_10[0x4];
	bool m_unk;
};