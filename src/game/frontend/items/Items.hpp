#include "core/frontend/manager/UIItem.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	class BoolCommand;
	class Command;

	class Button : public UIItem
	{
	public:
		explicit Button(const std::string_view& Name, std::function<void()> OnClick, ImVec2 size = {0, 25}, const std::string_view& information = "Empty");
		void Draw() override;

	private:
		std::string_view m_Name;
		std::string_view m_Information;
		std::function<void()> m_OnClick;
		ImVec2 m_Size;
	};

	class CommandItem : public UIItem
	{
	public:
		explicit CommandItem(joaat_t id);
		void Draw() override;

	private:
		Command* m_Command;
	};

	class BoolCommandItem : public UIItem
	{
	public:
		explicit BoolCommandItem(joaat_t id);
		void Draw() override;

	private:
		BoolCommand* m_Command;
	};

	class ImGuiItem : public UIItem
	{
	public:
		explicit ImGuiItem(std::function<void()> callback);
		void Draw() override;

	private:
		std::function<void()> m_Callback;
	};

	class HotkeySetter : public UIItem
	{
	public:

		explicit HotkeySetter(joaat_t);
		void Draw() override;

	private:
		joaat_t m_Id;
	};
}