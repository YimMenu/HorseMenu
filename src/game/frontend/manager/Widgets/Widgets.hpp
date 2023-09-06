#include "game/frontend/manager/UIManager.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	class Button : public Option
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

	class LoopedCommandToggle : public Option
	{
	public:
		explicit LoopedCommandToggle(joaat_t id);
		void Draw() override;

	private:
		joaat_t m_Id;
	};

	class HotkeySetter : public Option
	{
	public:

		explicit HotkeySetter(joaat_t);
		void Draw() override;

	private:
		joaat_t m_Id;
	};
}