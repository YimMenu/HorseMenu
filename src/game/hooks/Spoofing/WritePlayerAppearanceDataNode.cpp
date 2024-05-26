#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"


class CPlayerAppearanceNode
{
public:
	char pad_0[0x5C];
	uint32_t model_hash;
};


namespace YimMenu::Features
{
	BoolCommand _SpoofModel("spoofmodel", "Spoof Model", "Spoofs your model to other players!");
}

namespace YimMenu::Hooks
{
	void Spoofing::WritePlayerAppearanceDataNode(rage::netObject* player, int64_t* node)
	{
		BaseHook::Get<Spoofing::WritePlayerAppearanceDataNode, DetourHook<decltype(&Spoofing::WritePlayerAppearanceDataNode)>>()
		    ->Original()(player, node);

		if (Features::_SpoofModel.GetState())
		{
			auto data_node        = reinterpret_cast<CPlayerAppearanceNode*>(node);
			data_node->model_hash = 0x9233448C;
		}
	}
}