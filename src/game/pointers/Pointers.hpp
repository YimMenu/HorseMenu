#pragma once
#include <windows.h>
#include <dxgi1_4.h>
#include <d3d12.h>

//Someone can correct this
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
namespace YimMenu
{
	namespace Functions
	{
		using GetRendererInfo = RenderingInfo*(*)();
	}

	struct PointerData
	{
		Functions::GetRendererInfo GetRendererInfo;
		IDXGISwapChain1** SwapChain;
		ID3D12CommandQueue** CommandQueue;
		HWND Hwnd;
		std::int64_t** ScriptGlobals;
		void* NativeRegistrationTable;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}