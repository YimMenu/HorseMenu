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

	class Group : public UIItem
	{
	public:
		explicit Group(const std::string& name, ImVec2 size = {0, 0});
		void Draw() override;
		
		void AddItem(std::shared_ptr<UIItem>&& item)
		{
			m_Items.push_back(std::move(item));
		}

	private:
		std::string m_Name;
		ImVec2 m_Size;
		std::vector<std::shared_ptr<UIItem>> m_Items;
	};

	class Column : public UIItem
	{
	public:
		explicit Column(const int columns) :
		    m_Columns(columns)
		{
		}

		void AddItem(std::shared_ptr<UIItem>&& item)
		{
			m_Items.push_back(std::move(item));
		}

		void Draw();
		void AddNextColumn();
		void AddColumnOffset(const int column, const int offset);

	private:
		std::vector<std::shared_ptr<UIItem>> m_Items;
		int m_Columns;
	};

	class InputTextWithHint : public UIItem
	{
	public:
		explicit InputTextWithHint(std::string label, std::string hint, std::string* buf, ImGuiInputTextFlags_ flag = ImGuiInputTextFlags_None, std::function<void()> cb = nullptr);
		void Draw() override;

	private:
		std::string m_Id;
		std::string m_Hint;
		std::string* m_Buf;
		ImGuiInputTextFlags_ m_Flag;
		std::function<void()> m_Callback;
	};
}