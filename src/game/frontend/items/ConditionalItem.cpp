#include "Items.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/frontend/widgets/toggle/imgui_toggle.hpp"

namespace YimMenu
{
	ConditionalItem::ConditionalItem(joaat_t bool_cmd_id, std::shared_ptr<UIItem> to_draw) :
	    m_Condition(Commands::GetCommand<BoolCommand>(bool_cmd_id)),
	    m_Item(to_draw)
	{
	}

	void ConditionalItem::Draw()
	{
		if (!m_Condition)
		{
			return;
		}

		if (m_Condition->GetState())
			m_Item->Draw();
	}
}