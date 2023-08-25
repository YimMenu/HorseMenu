#pragma once
#include <cstdint>

enum class eRenderingType : uint8_t {
	DX12 = 1,
	Unk,
	Vulkan
};
class RenderingInfo {
public:
	virtual ~RenderingInfo() = default;

	uint8_t unk_0008; //0x0008
	eRenderingType m_rendering_type; //0x0009

	bool is_rendering_type(eRenderingType type) {
		return m_rendering_type == type;
	}
	void set_rendering_type(eRenderingType type) {
		if (!is_rendering_type(type)) {
			m_rendering_type = type;
		}
	}
};