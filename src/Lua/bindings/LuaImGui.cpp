#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "../wrappers/LuaImDrawList.hpp"
#include "core/frontend/widgets/toggle/imgui_toggle.hpp"

#include <rage/vector.hpp>
#include <imgui_internal.h>
#include <script/types.hpp>


namespace Terminus::LuaJIT
{
	class LuaImGuiLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	private:
		struct SolStrArray
		{
			std::vector<std::string> strings;
			std::vector<const char*> chars;
		};

		static inline SolStrArray SolTbl2StrArr(const sol::table& t)
		{
			SolStrArray result;
			result.strings.reserve(t.size());
			for (auto&& [i, v] : t)
			{
				if (!v.is<std::string>())
					continue;

				result.strings.emplace_back(v.as<std::string>());
			}

			result.chars.reserve(result.strings.size());
			for (const auto& str : result.strings)
				result.chars.emplace_back(str.c_str());

			return result;
		}

		static inline std::tuple<std::string, bool> InputTextMultiline(const std::string& label, std::string text, unsigned int buffSize)
		{
			text.resize(buffSize);
			bool selected = ImGui::InputTextMultiline(label.c_str(), text.data(), buffSize);
			return std::make_tuple(text.c_str(), selected);
		}

		static inline std::tuple<std::string, bool> InputTextMultiline1(const std::string& label, std::string text, unsigned int buffSize, ImVec2 size, sol::optional<int> flags)
		{
			text.resize(buffSize);
			auto inputFlags = static_cast<ImGuiInputTextFlags>(flags.value_or(0));
			bool selected   = ImGui::InputTextMultiline(label.c_str(), text.data(), buffSize, size, inputFlags);
			return std::make_tuple(text.c_str(), selected);
		}

		static inline bool Begin(const std::string& name)
		{
			return ImGui::Begin(name.c_str());
		}

		static inline bool Begin1(const std::string& name, int flags)
		{
			return ImGui::Begin(name.c_str(), nullptr, static_cast<ImGuiWindowFlags>(flags));
		}

		static inline std::tuple<bool, bool> Begin2(const std::string& name, bool open, sol::optional<int> flags)
		{
			bool pOpen{open};
			bool visible = ImGui::Begin(name.c_str(), &pOpen, static_cast<ImGuiWindowFlags>(flags.value_or(0)));
			return std::make_tuple(visible, pOpen);
		}

		static inline bool BeginChild(const std::string& name)
		{
			return ImGui::BeginChild(name.c_str());
		}

		static inline bool BeginChild1(const std::string& name, const ImVec2& size)
		{
			return ImGui::BeginChild(name.c_str(), size);
		}

		static inline bool BeginChild2(const std::string& name, const ImVec2& size, int childFlags, sol::optional<int> windowFlags)
		{
			auto winFlags = static_cast<ImGuiWindowFlags>(windowFlags.value_or(0));
			return ImGui::BeginChild(name.c_str(), size, static_cast<ImGuiChildFlags>(childFlags), winFlags);
		}

		static inline bool BeginTable(const std::string& label, int columnCount, sol::optional<int> flags)
		{
			return ImGui::BeginTable(label.c_str(), columnCount, static_cast<ImGuiTableFlags>(flags.value_or(0)));
		}

		static inline bool BeginTable1(const std::string& label, int columnCount, int flags, const ImVec2& size, sol::optional<float> innerWidth)
		{
			return ImGui::BeginTable(label.c_str(), columnCount, static_cast<ImGuiTableFlags>(flags), size, innerWidth.value_or(0.f));
		}

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.table ImGui
			* description: 
				A basic API that exposes a few ImGui widgets.
			@*/
			auto imguiTable = L["ImGui"].get_or_create<sol::table>();

			/*@terminus.function ImGui.PushID
			* param id<integer>
			@*/
			imguiTable["PushID"] = [](int id) {
				ImGui::PushID(id);
			};

			/*@terminus.function ImGui.PopID
			*
			@*/
			imguiTable["PopID"] = []() {
				ImGui::PopID();
			};

			/*@terminus.function ImGui.Bullet
			* 
			@*/
			imguiTable["Bullet"] = []() {
				ImGui::Bullet();
			};

			/*@terminus.function ImGui.Text
			* param text<string> 
			* param ...<any> Optional string format arguments
			@*/
			imguiTable["Text"] = [&](const std::string& fmt, sol::variadic_args args) {
				ImGui::Text(LuaStringFormat(L, fmt, args).c_str());
			};

			/*@terminus.function ImGui.TextDisabled
			* param text<string>
			* param ...<any> Optional string format arguments
			@*/
			imguiTable["TextDisabled"] = [&](const std::string& fmt, sol::variadic_args args) {
				ImGui::TextDisabled(LuaStringFormat(L, fmt, args).c_str());
			};

			/*@terminus.function ImGui.TextWrapped
			* param text<string>
			* param ...<any> Optional string format arguments
			@*/
			imguiTable["TextWrapped"] = [&](const std::string& fmt, sol::variadic_args args) {
				ImGui::TextWrapped(LuaStringFormat(L, fmt, args).c_str());
			};

			/*@terminus.function ImGui.TextUnformatted
			* param text<string> 
			@*/
			imguiTable["TextUnformatted"] = [](const std::string& text) {
				ImGui::TextUnformatted(text.c_str());
			};

			/*@terminus.function ImGui.TextColored
			* param col<Vector4>
			* param text<string>
			* param ...<any> Optional string format arguments
			@*/
			imguiTable["TextColored"] = [&](const ImVec4& col, const std::string& fmt, sol::variadic_args args) {
				ImGui::TextColored(col, LuaStringFormat(L, fmt, args).c_str());
			};

			/*@terminus.function ImGui.BulletText
			* param text<string>
			* param ...<any> Optional string format arguments
			@*/
			imguiTable["BulletText"] = [&](const std::string& fmt, sol::variadic_args args) {
				ImGui::BulletText(LuaStringFormat(L, fmt, args).c_str());
			};

			/*@terminus.function ImGui.Button
			* param label<string> 
			* param size<Vector2?> Optional button size
			* return boolean clicked
			@*/
			imguiTable["Button"] = [](const std::string& label, sol::optional<ImVec2> size) {
				return ImGui::Button(label.c_str(), size.value_or(ImVec2()));
			};

			/*@terminus.function ImGui.SmallButton
			* param label<string>
			* return boolean clicked
			@*/
			imguiTable["SmallButton"] = [](const std::string& label) {
				return ImGui::SmallButton(label.c_str());
			};

			/*@terminus.function ImGui.ArrowButton
			* param label<string> 
			* param direction<integer> [ImGuiDir](lua://ImGuiDir)
			* return boolean clicked
			@*/
			imguiTable["ArrowButton"] = [](const std::string& label, int direction) {
				return ImGui::ArrowButton(label.c_str(), static_cast<ImGuiDir>(direction));
			};

			/*@terminus.function ImGui.InvisibleButton
			* param label<string> 
			* param size<Vector2> Button size
			* return boolean clicked
			@*/
			imguiTable["InvisibleButton"] = [](const std::string& label, ImVec2& size) {
				return ImGui::InvisibleButton(label.c_str(), size);
			};

			/*@terminus.function ImGui.Checkbox
			* param label<string> 
			* param v<boolean>
			* return boolean value
			* return boolean clicked
			@*/
			imguiTable["Checkbox"] = [](const std::string& label, bool v) {
				bool value{v};
				bool clicked = ImGui::Checkbox(label.c_str(), &value);
				return std::make_tuple(value, clicked);
			};

			/*@terminus.function ImGui.RadioButton
			* param label<string> 
			* param active<boolean>
			* return boolean clicked
			@*/

			/*@terminus.function ImGui.RadioButton
			* param label<string> 
			* param v<integer> Current index
			* param vButton<integer> Index to change to
			* return integer newValue
			* return boolean clicked
			@*/
			imguiTable["RadioButton"] = sol::overload(
			    [](const std::string& label, bool active) {
				    return ImGui::RadioButton(label.c_str(), active);
			    },
			    [](const std::string& label, int v, int vButton) {
				    bool ret = ImGui::RadioButton(label.c_str(), &v, vButton);
				    return std::make_tuple(v, ret);
			    });

			/*@terminus.function ImGui.ProgressBar
			* param fraction<number> 
			* param size<Vector2?> Optional frame size
			* param overlayText<string?> Optional overlay text. Defaults to precentage.
			@*/
			imguiTable["ProgressBar"] = sol::overload(
			    [](float fraction) {
				    ImGui::ProgressBar(fraction);
			    },
			    [](float fraction, ImVec2 size, sol::optional<std::string> overlay) {
				    ImGui::ProgressBar(fraction, size, overlay.value_or("").c_str());
			    });


			///////////////////////////////////////////// windows /////////////////////////////////////////////////////////////

			/*@terminus.function ImGui.Begin
			* param name<string>
			* return boolean visible
			@*/

			/*@terminus.function ImGui.Begin
			* param name<string>
			* param windowFlags<integer> [ImGuiWindowFlags](lua://ImGuiWindowFlags)
			* return boolean visible
			@*/

			/*@terminus.function ImGui.Begin
			* param name<string>
			* param open<boolean>
			* param windowFlags<integer?> Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
			* return boolean visible
			@*/
			imguiTable["Begin"] = sol::overload(&Begin, &Begin1, &Begin2);

			/*@terminus.function ImGui.End
			* 
			@*/
			imguiTable["End"] = []() {
				ImGui::End();
			};

			/*@terminus.function ImGui.BeginChild
			* param name<string>
			* param size<Vector2?> child size.
			* return boolean visible
			@*/

			/*@terminus.function ImGui.BeginChild
			* param name<string>
			* param size<Vector2> child size.
			* param childFlags<integer?> [ImGuiChildFlags](lua://ImGuiChildFlags)
			* return boolean visible
			@*/

			/*@terminus.function ImGui.BeginChild
			* param name<string>
			* param size<Vector2> child size.
			* param childFlags<integer> [ImGuiChildFlags](lua://ImGuiChildFlags)
			* param windowFlags<integer?> Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
			* return boolean visible
			@*/
			imguiTable["BeginChild"] = sol::overload(&BeginChild, &BeginChild1, &BeginChild2);

			/*@terminus.function ImGui.EndChild
			* 
			@*/
			imguiTable["EndChild"] = []() {
				ImGui::EndChild();
			};

			/*@terminus.function ImGui.OpenPopup
			* param name<string> Popup name
			* param flags<integer?> Optional [ImGuiPopupFlags](lua://ImGuiPopupFlags)
			@*/
			imguiTable["OpenPopup"] = [](const std::string& name, sol::optional<int> popupFlags) {
				ImGui::OpenPopup(name.c_str(), static_cast<ImGuiPopupFlags>(popupFlags.value_or(0)));
			};


			/*@terminus.function ImGui.IsPopupOpen
			* param name<string> Popup name
			* param flags<integer?> Optional [ImGuiPopupFlags](lua://ImGuiPopupFlags)
			* return boolean
			@*/
			imguiTable["IsPopupOpen"] = [](const std::string& name, sol::optional<int> popupFlags) {
				return ImGui::IsPopupOpen(name.c_str(), static_cast<ImGuiPopupFlags>(popupFlags.value_or(0)));
			};

			/*@terminus.function ImGui.CloseCurrentPopup
			* 
			@*/
			imguiTable["CloseCurrentPopup"] = []() {
				ImGui::CloseCurrentPopup();
			};

			/*@terminus.function ImGui.BeginPopup
			* param name<string>
			* param windowFlags<integer?> Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
			* return boolean isOpen
			@*/
			imguiTable["BeginPopup"] = [](const std::string& name, sol::optional<int> windowFlags) {
				return ImGui::BeginPopup(name.c_str(), static_cast<ImGuiWindowFlags>(windowFlags.value_or(0)));
			};

			/*@terminus.function ImGui.BeginPopupModal
			* param name<string>
			* param windowFlags<integer?> Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
			* return boolean visible
			@*/

			/*@terminus.function ImGui.BeginPopupModal
			* param name<string>
			* param open<boolean> When true, the popup will have a `(x)` close button in the title bar.
			* param windowFlags<integer?> Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
			* return boolean visible
			* return boolean open
			@*/
			imguiTable["BeginPopupModal"] = sol::overload(
			    [](const std::string& name, sol::optional<int> windowFlags) {
				    return ImGui::BeginPopupModal(name.c_str(), nullptr, static_cast<ImGuiWindowFlags>(windowFlags.value_or(0)));
			    },
			    [](const std::string& name, bool open, sol::optional<int> windowFlags) {
				    bool pOpen{open};
				    bool visible =
				        ImGui::BeginPopupModal(name.c_str(), &pOpen, static_cast<ImGuiWindowFlags>(windowFlags.value_or(0)));
				    return std::make_tuple(visible, pOpen);
			    });

			/*@terminus.function ImGui.EndPopup
			* 
			@*/
			imguiTable["EndPopup"] = []() {
				ImGui::EndPopup();
			};

			/*@terminus.function ImGui.BeginTabBar
			* param strID<string>
			* param flags<integer?> Optional [ImGuiTabBarFlags](lua://ImGuiTabBarFlags)
			* return boolean
			@*/
			imguiTable["BeginTabBar"] = [](const std::string& strID, sol::optional<int> flags) {
				return ImGui::BeginTabBar(strID.c_str(), static_cast<ImGuiTabBarFlags>(flags.value_or(0)));
			};

			/*@terminus.function ImGui.EndTabBar
			* 
			@*/
			imguiTable["EndTabBar"] = []() {
				ImGui::EndTabBar();
			};

			/*@terminus.function ImGui.BeginTabItem
			* param strID<string>
			* return boolean
			@*/

			/*@terminus.function ImGui.BeginTabItem
			* param strID<string>
			* param open<boolean>
			* param flags<integer?> Optional [ImGuiTabItemFlags](lua://ImGuiTabItemFlags)
			* return boolean
			@*/
			imguiTable["BeginTabItem"] = sol::overload(
			    [](const std::string& strID) {
				    return ImGui::BeginTabItem(strID.c_str());
			    },
			    [](const std::string& strID, bool pOpen, sol::optional<int> flags) {
				    return ImGui::BeginTabItem(strID.c_str(), &pOpen, static_cast<ImGuiTabItemFlags>(flags.value_or(0)));
				}
			);

			/*@terminus.function ImGui.EndTabItem
			* 
			@*/
			imguiTable["EndTabItem"] = []() {
				ImGui::EndTabItem();
			};

			/*@terminus.function ImGui.TabItemButton Creates a Tab behaving like a button. Returns true when clicked and cannot be selected in the tab bar.
			* param strID<string>
			* param flags<integer?> Optional [ImGuiTabItemFlags](lua://ImGuiTabItemFlags)
			* return boolean
			@*/
			imguiTable["TabItemButton"] = [](const std::string& strID, sol::optional<int> flags) {
				return ImGui::TabItemButton(strID.c_str(), static_cast<ImGuiTabItemFlags>(flags.value_or(0)));
			};

			/*@terminus.function ImGui.Combo
			* param label<string>
			* param currentItem<integer>
			* param itemsSeparatedByZeros<string> A string with items separated by null terminators. Ex: `"Item1\0Item2\0Item3"`
			* return integer currentItem
			* return boolean opened
			@*/

			/*@terminus.function ImGui.Combo
			* param label<string>
			* param currentItem<integer>
			* param items<{[integer]: string}> A table of strings. Must be a contiguous string array, anything else will be ignored.
			* return integer currentItem
			* return boolean opened
			@*/
			imguiTable["Combo"] = sol::overload(
			    [](const std::string& label, int currentItem, const std::string& itemsSeparatedByZeros) {
				    bool clicked = ImGui::Combo(label.c_str(), &currentItem, itemsSeparatedByZeros.c_str());
				    return std::make_tuple(currentItem, clicked);
			    },
			    [](const std::string& label, int currentItem, const sol::table& items) {
				    auto res     = SolTbl2StrArr(items);
				    bool clicked = ImGui::Combo(label.c_str(), &currentItem, res.chars.data(), static_cast<int>(res.chars.size()));
				    return std::make_tuple(currentItem, clicked);
			    });


			///////////////////////////////////////////// containers /////////////////////////////////////////////////////////////

			/*@terminus.function ImGui.BeginTable
			* param label<string>
			* param columnCount<integer> child size.
			* param tableFlags<integer?> Optional [ImGuiTableFlags](lua://ImGuiTableFlags)
			* return boolean visible
			@*/

			/*@terminus.function ImGui.BeginTable
			* param label<string>
			* param columnCount<integer> child size.
			* param tableFlags<integer> [ImGuiTableFlags](lua://ImGuiTableFlags)
			* param outerSize<Vector2>
			* param innerWidth<number?>
			* return boolean visible
			@*/
			imguiTable["BeginTable"] = sol::overload(&BeginTable, &BeginTable1);

			/*@terminus.function ImGui.TableSetupColumn
			* param label<string>
			* param flags<integer?> Optional [ImGuiTableColumnFlags](lua://ImGuiTableColumnFlags)
			@*/

			/*@terminus.function ImGui.TableSetupColumn
			* param label<string>
			* param flags<integer> [ImGuiTableColumnFlags](lua://ImGuiTableColumnFlags)
			* param initWidthOrWeight<number?> Optional initial column width or weight
			@*/
			imguiTable["TableSetupColumn"] = sol::overload(
			    [](const std::string& label, sol::optional<int> columnFlags) {
				    ImGui::TableSetupColumn(label.c_str(), static_cast<ImGuiTableColumnFlags>(columnFlags.value_or(0)));
			    },
			    [](const std::string& label, int columnFlags, sol::optional<float> initWidthOrWeight) {
				    ImGui::TableSetupColumn(label.c_str(), static_cast<ImGuiTableColumnFlags>(columnFlags), initWidthOrWeight.value_or(0.f));
			    }
			);

			/*@terminus.function ImGui.TableSetupScrollFreeze
			* param columns<integer>
			* param rows<integer>
			@*/
			imguiTable["TableSetupScrollFreeze"] = [](int columns, int rows) {
				ImGui::TableSetupScrollFreeze(columns, rows);
			};

			/*@terminus.function ImGui.TableHeadersRow
			*
			@*/
			imguiTable["TableHeadersRow"] = []() {
				ImGui::TableHeadersRow();
			};

			/*@terminus.function ImGui.TableAngledHeadersRow Submit a row with angled headers for every column with the ImGuiTableColumnFlags_AngledHeader flag. MUST BE FIRST ROW.
			*
			@*/
			imguiTable["TableAngledHeadersRow"] = []() {
				ImGui::TableAngledHeadersRow();
			};

			/*@terminus.function ImGui.TableNextRow
			* param flags<integer?> Optional [ImGuiTableRowFlags](lua://ImGuiTableRowFlags)
			@*/
			imguiTable["TableNextRow"] = sol::overload(
				[](sol::optional<int> flags) {
					ImGui::TableNextRow(static_cast<ImGuiTableRowFlags>(flags.value_or(0)));
				},
			    [](int flags, sol::optional<float> minRowHeight) {
				    ImGui::TableNextRow(static_cast<ImGuiTableRowFlags>(flags), minRowHeight.value_or(0.0f));
				}
			);

			/*@terminus.function ImGui.TableNextColumn
			* return boolean
			@*/
			imguiTable["TableNextColumn"] = []() {
				return ImGui::TableNextColumn();
			};

			/*@terminus.function ImGui.TableSetColumnIndex
			* return boolean
			@*/
			imguiTable["TableSetColumnIndex"] = [](int index) {
				return ImGui::TableSetColumnIndex(index);
			};

			/*@terminus.function ImGui.TableGetRowIndex
			* return integer
			@*/
			imguiTable["TableGetRowIndex"] = []() {
				return ImGui::TableGetRowIndex();
			};

			/*@terminus.function ImGui.TableGetColumnIndex
			* return integer
			@*/
			imguiTable["TableGetColumnIndex"] = []() {
				return ImGui::TableGetColumnIndex();
			};

			/*@terminus.function ImGui.TableGetColumnCount
			* return integer
			@*/
			imguiTable["TableGetColumnCount"] = []() {
				return ImGui::TableGetColumnCount();
			};

			/*@terminus.function ImGui.TableGetColumnName Returns an empty string if column didn't have a name declared by TableSetupColumn(). Pass -1 to use current column.
			* param columnNumber<integer?>
			* return string
			@*/
			imguiTable["TableGetColumnName"] = [](sol::optional<int> columnNumber) {
				return std::string(ImGui::TableGetColumnName(columnNumber.value_or(-1)));
			};

			/*@terminus.function ImGui.TableGetColumnFlags
			* param columnNumber<integer?>
			* return integer
			@*/
			imguiTable["TableGetColumnFlags"] = [](sol::optional<int> columnNumber) {
				return ImGui::TableGetColumnFlags(columnNumber.value_or(-1));
			};

			/*@terminus.function ImGui.TableSetColumnEnabled
			* param columnNumber<integer>
			* param enabled<boolean>
			@*/
			imguiTable["TableSetColumnEnabled"] = [](int columnNumber, bool v) {
				ImGui::TableSetColumnEnabled(columnNumber, v);
			};

			/*@terminus.function ImGui.TableSetBgColor
			* param target<integer> [ImGuiTableBgTarget](ImGuiTableBgTarget)
			* param color<integer>
			* param columnNumber<integer?>
			@*/
			imguiTable["TableSetBgColor"] = [](int target, int color, sol::optional<int> columnNumber) {
				ImGui::TableSetBgColor(static_cast<ImGuiTableBgTarget>(target), static_cast<ImU32>(color), columnNumber.value_or(-1));
			};

			/*@terminus.function ImGui.EndTable
			* 
			@*/
			imguiTable["EndTable"] = []() {
				ImGui::EndTable();
			};

			/*@terminus.function ImGui.BeginCombo
			* param label<string> 
			* param preview<string> 
			* param flags<integer?> Optional [ImGuiComboFlags](lua://ImGuiComboFlags)
			* return boolean opened
			@*/
			imguiTable["BeginCombo"] = [](const std::string& label, const std::string& previewValue, sol::optional<int> flags) {
				return ImGui::BeginCombo(label.c_str(), previewValue.c_str(), static_cast<ImGuiComboFlags>(flags.value_or(0)));
			};

			/*@terminus.function ImGui.EndCombo
			* 
			@*/
			imguiTable["EndCombo"] = []() {
				ImGui::EndCombo();
			};

			/*@terminus.function ImGui.ListBox
			* param label<string>
			* param currentItem<integer>
			* param items<{[integer]: string}> A table of strings. Must be a contiguous string array, anything else will be ignored.
			* param heightInItems<integer?> Optional max items to show. Defaults to -1
			* return integer currentItem
			* return boolean visible
			@*/
			imguiTable["ListBox"] = [](const std::string& label, int currentItem, const sol::table& items, sol::optional<int> heightInItems) {
				auto res     = SolTbl2StrArr(items);
				bool visible = ImGui::ListBox(label.c_str(),
				    &currentItem,
				    res.chars.data(),
				    static_cast<int>(res.chars.size()),
				    heightInItems.value_or(-1));

				return std::make_tuple(currentItem, visible);
			};

			/*@terminus.function ImGui.BeginListBox
			* param label<string> 
			* param size<Vector2?> Optional listbox size
			* return boolean visible
			@*/
			imguiTable["BeginListBox"] = [](const std::string& label, sol::optional<ImVec2> size) {
				return ImGui::BeginListBox(label.c_str(), size.value_or(ImVec2()));
			};

			/*@terminus.function ImGui.EndListBox
			* 
			@*/
			imguiTable["EndListBox"] = []() {
				ImGui::EndListBox();
			};

			/*@terminus.function ImGui.Selectable
			* param label<string> 
			* param selected<boolean>
			* param flags<integer?> Optional [ImGuiSelectableFlags](lua://ImGuiSelectableFlags)
			* param size<Vector2?> Optional selectable size
			* return boolean clicked
			@*/
			imguiTable["Selectable"] = sol::overload(
			    [](const std::string& label, bool selected) {
				    return ImGui::Selectable(label.c_str(), selected);
			    },
			    [](const std::string& label, bool selected, int flags, sol::optional<ImVec2> size) {
				    auto selectableFlags = static_cast<ImGuiSelectableFlags>(flags);
				    return ImGui::Selectable(label.c_str(), selected, selectableFlags, size.value_or(ImVec2()));
			    });

			/*@terminus.function ImGui.MenuItem
			* param label<string> 
			* param selected<boolean>
			* return boolean selected
			* return boolean clicked
			@*/
			imguiTable["MenuItem"] = [](const std::string& label, bool selected) {
				bool clicked = ImGui::MenuItem(label.c_str(), nullptr, &selected);
				return std::make_tuple(selected, clicked);
			};


			///////////////////////////////////////////// input /////////////////////////////////////////////////////////////

			/*@terminus.function ImGui.SliderInt
			* param label<string>
			* param v<integer>
			* param vMin<integer> Minimum value
			* param vMax<integer> Maximum value
			* return integer v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.SliderInt
			* param label<string>
			* param v<integer>
			* param vMin<integer> Minimum value
			* param vMax<integer> Maximum value
			* param fmt<string> format string
			* param flags<integer?> Optional [ImGuiSliderFlags](lua://ImGuiSliderFlags)
			* return integer v
			* return boolean changed
			@*/
			imguiTable["SliderInt"] = sol::overload(
			    [](const std::string& label, int v, int vMin, int vMax) {
				    bool changed = ImGui::SliderInt(label.c_str(), &v, vMin, vMax);
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, int v, int vMin, int vMax, const std::string& fmt, sol::optional<int> flags) {
				    auto sliderFlags = static_cast<ImGuiSliderFlags>(flags.value_or(0));
				    bool changed     = ImGui::SliderInt(label.c_str(), &v, vMin, vMax, fmt.c_str(), sliderFlags);
				    return std::make_tuple(v, changed);
			    });

			/*@terminus.function ImGui.SliderFloat
			* param label<string>
			* param v<number>
			* param vMin<number> Minimum value
			* param vMax<number> Maximum value
			* return number v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.SliderFloat
			* param label<string>
			* param v<number>
			* param vMin<number> Minimum value
			* param vMax<number> Maximum value
			* param fmt<string> format string
			* param flags<integer?> Optional [ImGuiSliderFlags](lua://ImGuiSliderFlags)
			* return number v
			* return boolean changed
			@*/
			imguiTable["SliderFloat"] = sol::overload(
			    [](const std::string& label, float v, float vMin, float vMax) {
				    bool changed = ImGui::SliderFloat(label.c_str(), &v, vMin, vMax);
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, float v, float vMin, float vMax, const std::string& fmt, sol::optional<int> flags) {
				    auto sliderFlags = static_cast<ImGuiSliderFlags>(flags.value_or(0));
				    bool changed     = ImGui::SliderFloat(label.c_str(), &v, vMin, vMax, fmt.c_str(), sliderFlags);
				    return std::make_tuple(v, changed);
			    });

			/*@terminus.function ImGui.InputInt
			* param label<string>
			* param v<integer>
			* return integer v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.InputInt
			* param label<string>
			* param v<integer>
			* param step<integer> step
			* param stepFast<integer> fast step
			* param flags<integer?> Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
			* return integer v
			* return boolean changed
			@*/
			imguiTable["InputInt"] = sol::overload(
			    [](const std::string& label, int v, sol::optional<int> step) {
				    bool changed = ImGui::InputInt(label.c_str(), &v);
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, int v, int step, int stepFast, sol::optional<int> flags) {
				    bool changed = ImGui::InputInt(label.c_str(), &v, step, stepFast, static_cast<ImGuiInputTextFlags>(flags.value_or(0)));
				    return std::make_tuple(v, changed);
			    });

			/*@terminus.function ImGui.InputFloat
			* param label<string>
			* param v<number>
			* return number v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.InputFloat
			* param label<string>
			* param v<number>
			* param step<number> step
			* param stepFast<number> fast step
			* param fmt<string?> Optional format string
			* return number v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.InputFloat
			* param label<string>
			* param v<number>
			* param step<number> step
			* param stepFast<number> fast step
			* param fmt<string> format string
			* param flags<integer?> Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
			* return number v
			* return boolean changed
			@*/
			imguiTable["InputFloat"] = sol::overload(
			    [](const std::string& label, float v) {
				    bool changed = ImGui::InputFloat(label.c_str(), &v);
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, float v, float step, float stepFast, sol::optional<std::string> fmt) {
				    bool changed = ImGui::InputFloat(label.c_str(), &v, step, stepFast, fmt.value_or("%.3f").c_str());
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, float v, float step, float stepFast, const std::string& fmt, sol::optional<int> flags) {
				    auto inputFlags = static_cast<ImGuiInputTextFlags>(flags.value_or(0));
				    bool changed    = ImGui::InputFloat(label.c_str(), &v, step, stepFast, fmt.c_str(), inputFlags);
				    return std::make_tuple(v, changed);
			    });

			/*@terminus.function ImGui.InputDouble
			* param label<string>
			* param v<number>
			* return number v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.InputDouble
			* param label<string>
			* param v<number>
			* param step<number> step
			* param stepFast<number> fast step
			* param fmt<string?> Optional format string
			* return number v
			* return boolean changed
			@*/

			/*@terminus.function ImGui.InputDouble
			* param label<string>
			* param v<number>
			* param step<number> step
			* param stepFast<number> fast step
			* param fmt<string> format string
			* param flags<integer?> Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
			* return number v
			* return boolean changed
			@*/
			imguiTable["InputDouble"] = sol::overload(
			    [](const std::string& label, double v) {
				    bool changed = ImGui::InputDouble(label.c_str(), &v);
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, double v, double step, double stepFast, sol::optional<std::string> fmt) {
				    bool changed = ImGui::InputDouble(label.c_str(), &v, step, stepFast, fmt.value_or("%.3f").c_str());
				    return std::make_tuple(v, changed);
			    },
			    [](const std::string& label, double v, double step, double stepFast, const std::string& fmt, sol::optional<int> flags) {
				    auto inputFlags = static_cast<ImGuiInputTextFlags>(flags.value_or(0));
				    bool changed    = ImGui::InputDouble(label.c_str(), &v, step, stepFast, fmt.c_str(), inputFlags);
				    return std::make_tuple(v, changed);
			    });

			/*@terminus.function ImGui.InputText
			* param label<string>
			* param text<string>
			* param bufferSize<integer>
			* param flags<integer?> Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
			* return string text
			* return boolean changed
			@*/
			imguiTable["InputText"] = [](const std::string& label, std::string text, uint32_t bufferSize, sol::optional<int> flags) {
				text.resize(bufferSize);
				bool changed = ImGui::InputText(label.c_str(), text.data(), bufferSize, static_cast<ImGuiInputTextFlags>(flags.value_or(0)));
				return std::make_tuple(text.c_str(), changed);
			};

			/*@terminus.function ImGui.InputTextWithHint
			* param label<string>
			* param hint<string>
			* param text<string>
			* param bufferSize<integer>
			* param flags<integer?> Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
			* return string text
			* return boolean changed
			@*/
			imguiTable["InputTextWithHint"] = [](const std::string& label, const std::string& hint, std::string text, uint32_t bufferSize, sol::optional<int> flags) {
				text.resize(bufferSize);
				bool changed = ImGui::InputTextWithHint(label.c_str(),
				    hint.c_str(),
				    text.data(),
				    bufferSize,
				    static_cast<ImGuiInputTextFlags>(flags.value_or(0)));

				return std::make_tuple(text.c_str(), changed);
			};

			/*@terminus.function ImGui.InputTextMultiline
			* param label<string>
			* param text<string>
			* param bufferSize<integer>
			* return string text
			* return boolean changed
			@*/

			/*@terminus.function ImGui.InputTextMultiline
			* param label<string>
			* param text<string>
			* param bufferSize<integer>
			* param flags<integer> [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
			* param size<Vector2?> Optional widget size
			* return string text
			* return boolean changed
			@*/
			imguiTable["InputTextMultiline"] = sol::overload(&InputTextMultiline, &InputTextMultiline1);
			
			/*@terminus.function ImGui.ColorButton
			* param label<string> 
			* param color<Vector4>
			* return boolean clicked
			@*/

			/*@terminus.function ImGui.ColorButton
			* param label<string> 
			* param color<Vector4>
			* param flags<integer?> Optional [ImGuiColorEditFlags](lua://ImGuiColorEditFlags)
			* return boolean clicked
			@*/

			/*@terminus.function ImGui.ColorButton
			* param label<string> 
			* param color<Vector4>
			* param flags<integer> [ImGuiColorEditFlags](lua://ImGuiColorEditFlags)
			* param size<Vector2?> Optional picker size
			* return boolean clicked
			@*/
			imguiTable["ColorButton"] = sol::overload(
			    [](const std::string& label, const ImVec4& col, sol::optional<int> flags) {
				    return ImGui::ColorButton(label.c_str(), col, static_cast<ImGuiColorEditFlags>(flags.value_or(0)));
			    },
			    [](const std::string& label, const ImVec4& col, int flags, sol::optional<ImVec2> size) {
				    return ImGui::ColorButton(label.c_str(), col, static_cast<ImGuiColorEditFlags>(flags), size.value_or(ImVec2()));
			    });

			/*@terminus.function ImGui.ColorEdit3
			* param label<string>
			* param outCol<Vector3>
			* param flags<integer?> Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
			* return boolean changed Returns true when the color changes. The vector is mutated in-place.
			@*/
			imguiTable["ColorEdit3"] = [](const std::string& label, Vector3& outCol, sol::optional<int> flags) {
				float arg[3]{
					static_cast<float>(outCol.x),
					static_cast<float>(outCol.y),
					static_cast<float>(outCol.z)
				};

				bool changed = ImGui::ColorEdit3(label.c_str(), arg, static_cast<ImGuiColorEditFlags>(flags.value_or(0)));

				outCol.x = arg[0];
				outCol.y = arg[1];
				outCol.z = arg[2];

				return changed;
			};

			/*@terminus.function ImGui.ColorPicker3
			* param label<string>
			* param outCol<Vector3>
			* param flags<integer?> Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
			* return boolean changed Returns true when the color changes. The vector is mutated in-place.
			@*/
			imguiTable["ColorPicker3"] = [](const std::string& label, Vector3& outCol, sol::optional<int> flags) {
				float arg[3]{
					static_cast<float>(outCol.x),
					static_cast<float>(outCol.y),
					static_cast<float>(outCol.z)
				};

				bool changed = ImGui::ColorPicker3(label.c_str(), arg, static_cast<ImGuiColorEditFlags>(flags.value_or(0)));

				outCol.x = arg[0];
				outCol.y = arg[1];
				outCol.z = arg[2];

				return changed;
			};

			/*@terminus.function ImGui.ColorEdit4
			* param label<string>
			* param outCol<Vector4>
			* param flags<integer?> Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
			* return boolean changed Returns true when the color changes. The vector is mutated in-place.
			@*/
			imguiTable["ColorEdit4"] = [](const std::string& label, ImVec4& outCol, sol::optional<int> flags) {
				float arg[4]{
					static_cast<float>(outCol.x),
					static_cast<float>(outCol.y),
					static_cast<float>(outCol.z),
					static_cast<float>(outCol.w)
				};

				bool changed = ImGui::ColorEdit4(label.c_str(), arg, static_cast<ImGuiColorEditFlags>(flags.value_or(0)));

				outCol.x = arg[0];
				outCol.y = arg[1];
				outCol.z = arg[2];
				outCol.w = arg[3];

				return changed;
			};

			/*@terminus.function ImGui.ColorPicker4
			* param label<string>
			* param outCol<Vector4>
			* param flags<integer?> Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
			* return boolean changed Returns true when the color changes. The vector is mutated in-place.
			@*/
			imguiTable["ColorPicker4"] = [](const std::string& label, ImVec4& outCol, sol::optional<int> flags) {
				float arg[4]{static_cast<float>(outCol.x),
				    static_cast<float>(outCol.y),
				    static_cast<float>(outCol.z),
				    static_cast<float>(outCol.w)};

				bool changed = ImGui::ColorPicker4(label.c_str(), arg, static_cast<ImGuiColorEditFlags>(flags.value_or(0)));

				outCol.x = arg[0];
				outCol.y = arg[1];
				outCol.z = arg[2];
				outCol.w = arg[3];

				return changed;
			};


			//////////////////////////////////////////////// layout ////////////////////////////////////////////////

			/*@terminus.function ImGui.BeginDisabled Disables all ImGui widgets created between this call and EndDisabled
			* param cond<boolean?> Optional condition
			@*/
			imguiTable["BeginDisabled"] = [](sol::optional<bool> bCond) {
				ImGui::BeginDisabled(bCond.value_or(true));
			};

			/*@terminus.function ImGui.EndDisabled
			*
			@*/
			imguiTable["EndDisabled"] = []() {
				ImGui::EndDisabled();
			};

			/*@terminus.function ImGui.SameLine
			*
			@*/

			/*@terminus.function ImGui.SameLine
			* param offsetX<number> X position to start at. Defaults to `0`.
			* param spacing<number?> Optional spacing after the previous item. Defaults to the current item spacing.
			@*/
			imguiTable["SameLine"] = sol::overload(
			    []() { ImGui::SameLine(); },
			    [](sol::optional<float> offsetX) {
				    ImGui::SameLine(offsetX.value_or(0.0f));
			    },
			    [](float offsetX, float spacing) {
				    ImGui::SameLine(offsetX, spacing);
			    });

			/*@terminus.function ImGui.NewLine
			* 
			@*/
			imguiTable["NewLine"] = []() {
				ImGui::NewLine();
			};

			/*@terminus.function ImGui.Spacing
			* 
			@*/
			imguiTable["Spacing"] = []() {
				ImGui::Spacing();
			};

			/*@terminus.function ImGui.Separator
			* 
			@*/
			imguiTable["Separator"] = []() {
				ImGui::Separator();
			};

			/*@terminus.function ImGui.SeparatorEx
			* param flags<integer> [ImGuiSeparatorFlags](lua://ImGuiSeparatorFlags)
			* param thickness<number?> Optional separator thickness. Defaults to 1.0
			@*/
			imguiTable["SeparatorEx"] = [](int flags, sol::optional<float> thickness) {
				ImGui::SeparatorEx(static_cast<ImGuiSeparatorFlags>(flags), thickness.value_or(1.0f));
			};

			/*@terminus.function ImGui.SeparatorText
			* param text<string>
			@*/
			imguiTable["SeparatorText"] = [](const std::string& text) {
				ImGui::SeparatorText(text.c_str());
			};

			/*@terminus.function ImGui.Indent
			* param indentX<number?> Optional indentation width. Defaults to the current item spacing.
			@*/
			imguiTable["Indent"] = [](sol::optional<float> indentX) {
				ImGui::Indent(indentX.value_or(0.f));
			};

			/*@terminus.function ImGui.Unindent
			* param indentX<number?> Optional indentation width. Defaults to the current item spacing.
			@*/
			imguiTable["Unindent"] = [](sol::optional<float> indentX) {
				ImGui::Unindent(indentX.value_or(0.f));
			};

			/*@terminus.function ImGui.Dummy
			* param size<Vector2>
			@*/
			imguiTable["Dummy"] = [](const ImVec2& size) {
				ImGui::Dummy(size);
			};

			/*@terminus.function ImGui.SetCursorPos
			* param pos<Vector2>
			@*/
			imguiTable["SetCursorPos"] = [](const ImVec2& pos) {
				ImGui::SetCursorPos(pos);
			};

			/*@terminus.function ImGui.SetCursorPosX
			* param x<number> X position relative to the current window.
			@*/
			imguiTable["SetCursorPosX"] = [](float x) {
				ImGui::SetCursorPosX(x);
			};

			/*@terminus.function ImGui.SetCursorPosY
			* param y<number> Y position relative to the current window.
			@*/
			imguiTable["SetCursorPosY"] = [](float y) {
				ImGui::SetCursorPosY(y);
			};

			/*@terminus.function ImGui.GetCursorPos
			* return Vector2 cursorPos
			@*/
			imguiTable["GetCursorPos"] = []() {
				return ImGui::GetCursorPos();
			};

			/*@terminus.function ImGui.GetCursorPosX
			* return number x Current X position relative to the current window.
			@*/
			imguiTable["GetCursorPosX"] = []() {
				return ImGui::GetCursorPosX();
			};

			/*@terminus.function ImGui.GetCursorPosY
			* return number y Current Y position relative to the current window.
			@*/
			imguiTable["GetCursorPosY"] = []() {
				return ImGui::GetCursorPosY();
			};

			/*@terminus.function ImGui.GetContentRegionAvail
			* return Vector2 avail Available content region.
			@*/
			imguiTable["GetContentRegionAvail"] = []() {
				return ImGui::GetContentRegionAvail();
			};

			/*@terminus.function ImGui.GetWindowWidth
			* return number width
			@*/
			imguiTable["GetWindowWidth"] = []() {
				return ImGui::GetWindowWidth();
			};

			/*@terminus.function ImGui.GetWindowHeight
			* return number height
			@*/
			imguiTable["GetWindowHeight"] = []() {
				return ImGui::GetWindowHeight();
			};

			/*@terminus.function ImGui.GetWindowSize
			* return Vector2 windowSize
			@*/
			imguiTable["GetWindowSize"] = []() {
				return ImGui::GetWindowSize();
			};

			/*@terminus.function ImGui.GetWindowPos
			* return Vector2 windowPos Current window position.
			@*/
			imguiTable["GetWindowPos"] = []() {
				return ImGui::GetWindowPos();
			};

			/*@terminus.function ImGui.GetFrameHeight
			* return number frameHeight
			@*/
			imguiTable["GetFrameHeight"] = []() {
				return ImGui::GetFrameHeight();
			};

			/*@terminus.function ImGui.GetFrameHeightWithSpacing
			* return number frameHeight Frame height with spacing.
			@*/
			imguiTable["GetFrameHeightWithSpacing"] = []() {
				return ImGui::GetFrameHeightWithSpacing();
			};

			/*@terminus.function ImGui.SetNextItemWidth
			* param width<number> Width of the next item.
			@*/
			imguiTable["SetNextItemWidth"] = [](float width) {
				ImGui::SetNextItemWidth(width);
			};

			/*@terminus.function ImGui.PushItemWidth
			* param width<number> Width of subsequent items.
			@*/
			imguiTable["PushItemWidth"] = [](float width) {
				ImGui::PushItemWidth(width);
			};

			/*@terminus.function ImGui.PopItemWidth
			* 
			@*/
			imguiTable["PopItemWidth"] = []() {
				ImGui::PopItemWidth();
			};

			/*@terminus.function ImGui.CalcTextSize
			* param text<string>
			* param wrapWidth<number?>
			* return Vector2 size
			@*/

			/*@terminus.function ImGui.CalcTextSize
			* param text<string>
			* param hideTextAfterDoubleHash<boolean>
			* param wrapWidth<number?>
			* return Vector2 size
			@*/
			imguiTable["CalcTextSize"] = sol::overload(
			    [](const std::string& text, sol::optional<float> wrapWidth) {
				    return ImGui::CalcTextSize(text.c_str(), nullptr, false, wrapWidth.value_or(-1.0f));
				},
				[](const std::string& text, bool hideTextAfterDoubleHash, sol::optional<float> wrapWidth) {
					return ImGui::CalcTextSize(text.c_str(), nullptr, hideTextAfterDoubleHash, wrapWidth.value_or(-1.0f));
				}
			);

			/*@terminus.function ImGui.GetItemRectMin
			* param scale<number>
			@*/
			imguiTable["SetWindowFontScale"] = [](const float& scale) {
				ImGui::SetWindowFontScale(scale);
			};

			/*@terminus.function ImGui.GetItemRectMin
			* return Vector2 rectMin
			@*/
			imguiTable["GetItemRectMin"] = []() {
				return ImGui::GetItemRectMin();
			};

			/*@terminus.function ImGui.GetItemRectMax
			* return Vector2 rectMax
			@*/
			imguiTable["GetItemRectMax"] = []() {
				return ImGui::GetItemRectMax();
			};

			/*@terminus.function ImGui.GetItemRectSize
			* return Vector2 size
			@*/
			imguiTable["GetItemRectSize"] = []() {
				return ImGui::GetItemRectSize();
			};

			/*@terminus.function ImGui.GetItemID
			* return integer itemID
			@*/
			imguiTable["GetItemID"] = []() {
				return static_cast<int>(ImGui::GetItemID());
			};

			/*@terminus.function ImGui.IsItemHovered
			* param flags<integer?> Optional [ImGuiHoveredFlags](ImGuiHoveredFlags)
			* return boolean
			@*/
			imguiTable["IsItemHovered"] = [](sol::optional<int> flags) {
				return ImGui::IsItemHovered(static_cast<ImGuiHoveredFlags>(flags.value_or(0)));
			};

			/*@terminus.function ImGui.IsItemActive
			* return boolean
			@*/
			imguiTable["IsItemActive"] = []() {
				return ImGui::IsItemActive();
			};

			/*@terminus.function ImGui.IsItemFocused
			* return boolean
			@*/
			imguiTable["IsItemFocused"] = []() {
				return ImGui::IsItemActive();
			};

			/*@terminus.function ImGui.IsItemVisible
			* return boolean
			@*/
			imguiTable["IsItemVisible"] = []() {
				return ImGui::IsItemVisible();
			};

			/*@terminus.function ImGui.IsItemEdited
			* return boolean
			@*/
			imguiTable["IsItemEdited"] = []() {
				return ImGui::IsItemEdited();
			};

			/*@terminus.function ImGui.IsItemActivated
			* return boolean
			@*/
			imguiTable["IsItemActivated"] = []() {
				return ImGui::IsItemActivated();
			};

			/*@terminus.function ImGui.IsItemDeactivated
			* return boolean
			@*/
			imguiTable["IsItemDeactivated"] = []() {
				return ImGui::IsItemDeactivated();
			};

			/*@terminus.function ImGui.IsItemDeactivatedAfterEdit
			* return boolean
			@*/
			imguiTable["IsItemDeactivatedAfterEdit"] = []() {
				return ImGui::IsItemDeactivatedAfterEdit();
			};

			/*@terminus.function ImGui.IsItemToggledOpen
			* return boolean
			@*/
			imguiTable["IsItemToggledOpen"] = []() {
				return ImGui::IsItemToggledOpen();
			};

			/*@terminus.function ImGui.IsAnyItemHovered
			* return boolean
			@*/
			imguiTable["IsAnyItemHovered"] = []() {
				return ImGui::IsAnyItemHovered();
			};

			/*@terminus.function ImGui.IsAnyItemActive
			* return boolean
			@*/
			imguiTable["IsAnyItemActive"] = []() {
				return ImGui::IsAnyItemActive();
			};

			/*@terminus.function ImGui.IsAnyItemFocused
			* return boolean
			@*/
			imguiTable["IsAnyItemFocused"] = []() {
				return ImGui::IsAnyItemFocused();
			};

			/*@terminus.function ImGui.IsItemClicked
			* param mouseBtn<integer?> 0: "left" | 1: "right" | 2: "middle"
			* return boolean
			@*/
			imguiTable["IsItemClicked"] = [](sol::optional<int> mouseBtn) {
				return ImGui::IsItemClicked(static_cast<ImGuiMouseButton>(mouseBtn.value_or(0)));
			};

			/*@terminus.function ImGui.IsAnyItemHovered
			* return boolean
			@*/
			imguiTable["IsAnyItemHovered"] = []() {
				return ImGui::IsAnyItemHovered();
			};


			//////////////////////////////////////////////// style ////////////////////////////////////////////////

			/*@terminus.function ImGui.PushStyleVar
			* param styleVar<integer> [ImGuiStyleVar](lua://ImGuiStyleVar) index
			* param v<number> style value
			@*/

			/*@terminus.function ImGui.PushStyleVar
			* param styleVar<integer> [ImGuiStyleVar](lua://ImGuiStyleVar) index
			* param v<Vector2>
			@*/
			imguiTable["PushStyleVar"] = sol::overload(
			    [](int styleVar, float v) {
				    ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(styleVar), v);
			    },
			    [](int styleVar, const ImVec2& v) {
				    ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(styleVar), v);
			    });

			/*@terminus.function ImGui.PopStyleVar
			* param count<integer?> Count of pushed style variables to pop. Defaults to 1; Must match the number of pushed style vars.
			@*/
			imguiTable["PopStyleVar"] = [](sol::optional<int> count) {
				ImGui::PopStyleVar(std::max(count.value_or(1), 1));
			};

			/*@terminus.function ImGui.PushStyleColor
			* param colIdx<integer> [ImGuiCol](lua://ImGuiCol) index
			* param color<Vector4>
			@*/
			imguiTable["PushStyleColor"] = [](int colIdx, const ImVec4& col) {
				ImGui::PushStyleColor(static_cast<ImGuiCol>(colIdx), col);
			};

			/*@terminus.function ImGui.PopStyleColor
			* param count<integer?> Count of pushed style colors to pop. Defaults to 1; Must match the number of pushed style cols.
			@*/
			imguiTable["PopStyleColor"] = [](sol::optional<int> count) {
				ImGui::PopStyleColor(std::max(count.value_or(1), 1));
			};

			/*@terminus.function ImGui.SetMouseCursor
			* param cursorIdx<integer> [ImGuiMouseCursor](lua://ImGuiMouseCursor) index
			@*/
			imguiTable["SetMouseCursor"] = [](int cursorIdx) {
				ImGui::SetMouseCursor(static_cast<ImGuiMouseCursor>(cursorIdx));
			};


			//////////////////////////////////////////////// custom widgets ////////////////////////////////////////////////

			/*@terminus.function ImGui.Toggle Draws a toggle widget that can be used instead of a regular ImGui checkbox.
			* param label<string> Tooltip text
			* param v<boolean> Tooltip text
			@*/

			/*@terminus.function ImGui.Toggle Draws a toggle widget that can be used instead of a regular ImGui checkbox.
			* param label<string>
			* param v<boolean> 
			* param size<Vector2>
			* return boolean value
			* return boolean clicked
			@*/
			imguiTable["Toggle"] = sol::overload(
				[](const std::string& label, bool v) {
					bool value{v};
				    bool clicked = ImGui::Toggle(label.c_str(), &value, ImVec2());
					return std::make_tuple(value, clicked);
				},
				[](const std::string& label, bool v, const ImVec2& size) {
					bool value{v};
				    bool clicked = ImGui::Toggle(label.c_str(), &value, size);
				    return std::make_tuple(value, clicked);
				}
			);


			//////////////////////////////////////////////// misc ////////////////////////////////////////////////

			/*@terminus.function ImGui.SetTooltip
			* param text<string>
			* param ...<any> Optional format args
			@*/
			imguiTable["SetTooltip"] = [&](const std::string& text, sol::variadic_args args) {
				ImGui::SetTooltip(LuaStringFormat(L, text, args).c_str());
			};

			/*@terminus.function ImGui.BeginTooltip
			*
			@*/
			imguiTable["BeginTooltip"] = [&]() {
				ImGui::BeginTooltip();
			};

			/*@terminus.function ImGui.EndTooltip
			*
			@*/
			imguiTable["EndTooltip"] = [&]() {
				ImGui::EndTooltip();
			};

			/*@terminus.function ImGui.GetWindowDrawList
			* return ImDrawList
			@*/
			imguiTable["GetWindowDrawList"] = []() {
				return LuaImDrawList(ImGui::GetWindowDrawList());
			};

			/*@terminus.function ImGui.GetBackgroundDrawList
			* return ImDrawList
			@*/
			imguiTable["GetBackgroundDrawList"] = []() {
				return LuaImDrawList(ImGui::GetBackgroundDrawList());
			};

			/*@terminus.function ImGui.GetForegroundDrawList
			* return ImDrawList
			@*/
			imguiTable["GetForegroundDrawList"] = []() {
				return LuaImDrawList(ImGui::GetForegroundDrawList());
			};

			/*@terminus.function ImGui.GetTime
			* return number
			@*/
			imguiTable["GetTime"] = []() {
				return ImGui::GetTime();
			};

			/*@terminus.function ImGui.GetFrameCount
			* return integer
			@*/
			imguiTable["GetFrameCount"] = []() {
				return ImGui::GetFrameCount();
			};

			/*@terminus.function ImGui.GetFontSize
			* return integer
			@*/
			imguiTable["GetFontSize"] = []() {
				return ImGui::GetFontSize();
			};

			/*@terminus.function ImGui.ColorConvertU32ToFloat4
			* param col<integer> Packed 32bit integer
			* return Vector4 rgba Normalised RGBA
			@*/
			imguiTable["ColorConvertU32ToFloat4"] = [](int col) {
				return ImGui::ColorConvertU32ToFloat4(static_cast<ImU32>(col));
			};

			/*@terminus.function ImGui.ColorConvertFloat4ToU32
			* param col<Vector4> Normalised RGBA
			* return integer u32 Packed 32bit integer
			@*/
			imguiTable["ColorConvertFloat4ToU32"] = [](const ImVec4& col) {
				return ImGui::ColorConvertFloat4ToU32(col);
			};

			/*@terminus.function ImGui.ColorConvertHSVtoRGB
			* param h<number>
			* param s<number>
			* param v<number>
			* return number r
			* return number g
			* return number b
			@*/
			imguiTable["ColorConvertHSVtoRGB"] = [](float h, float s, float v) {
				float r{}, g{}, b{};
				ImGui::ColorConvertHSVtoRGB(h, s, v, r, g, b);
				return std::make_tuple(r, g, b);
			};

			/*@terminus.function ImGui.ColorConvertRGBtoHSV
			* param r<number>
			* param g<number>
			* param b<number>
			* return number h
			* return number s
			* return number v
			@*/
			imguiTable["ColorConvertRGBtoHSV"] = [](float r, float g, float b) {
				float h{}, s{}, v{};
				ImGui::ColorConvertHSVtoRGB(r, g, b, h, s, v);
				return std::make_tuple(h, s, v);
			};
		}
	};

	LuaImGuiLib _LuaImGuiLib;
}
