#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"

#include <imgui_internal.h>


namespace Terminus::LuaJIT
{
	class LuaImGuiEnumsLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			// clang-format off

			/*@terminus.enum ImGuiSeparatorFlags
			* field None<integer>
			* field Horizontal<integer> Axis default to current layout type, so generally Horizontal unless e.g. in a menu bar
			* field Vertical<integer>
			* field SpanAllColumns<integer> Make separator cover all columns of a legacy Columns() set.
			@*/
			L.new_enum("ImGuiSeparatorFlags",
				"None", ImGuiSeparatorFlags_None,
				"Horizontal", ImGuiSeparatorFlags_Horizontal,
				"Vertical", ImGuiSeparatorFlags_Vertical,
				"SpanAllColumns", ImGuiSeparatorFlags_SpanAllColumns);

			/*@terminus.enum ImGuiMouseCursor
			* field None<integer>
			* field Arrow<integer>
			* field TextInput<integer> When hovering over InputText, etc.
			* field ResizeAll<integer> (Unused by Dear ImGui functions)
			* field ResizeNS<integer> When hovering over a horizontal border
			* field ResizeEW<integer> When hovering over a vertical border or a column
			* field ResizeNESW<integer> When hovering over the bottom-left corner of a window
			* field ResizeNWSE<integer> When hovering over the bottom-right corner of a window
			* field Hand<integer> (Unused by Dear ImGui functions. Use for e.g. hyperlinks)
			* field Wait<integer> When waiting for something to process/load.
			* field Progress<integer> When waiting for something to process/load, but application is still interactive.
			* field NotAllowed<integer> When hovering something with disallowed interaction. Usually a crossed circle.
			@*/
			L.new_enum("ImGuiMouseCursor",
				"None", ImGuiMouseCursor_None,
				"Arrow", ImGuiMouseCursor_Arrow,
				"TextInput", ImGuiMouseCursor_TextInput,
				"ResizeAll", ImGuiMouseCursor_ResizeAll,
				"ResizeNS", ImGuiMouseCursor_ResizeNS,
				"ResizeEW", ImGuiMouseCursor_ResizeEW,
				"ResizeNESW", ImGuiMouseCursor_ResizeNESW,
				"ResizeNWSE", ImGuiMouseCursor_ResizeNWSE,
				"Hand", ImGuiMouseCursor_Hand,
				"Wait", ImGuiMouseCursor_Wait,
				"Progress", ImGuiMouseCursor_Progress,
				"NotAllowed", ImGuiMouseCursor_NotAllowed);

			/*@terminus.enum ImGuiDir
			* field None<integer>
			* field Left<integer>
			* field Right<integer>
			* field Up<integer>
			* field Down<integer>
			@*/
			L.new_enum("ImGuiDir",
			    "None", ImGuiDir_None,
			    "Left", ImGuiDir_Left,
			    "Right", ImGuiDir_Right,
			    "Up", ImGuiDir_Up,
			    "Down", ImGuiDir_Down);

			/*@terminus.enum ImGuiComboFlags
			* field None<integer>
			* field PopupAlignLeft<integer> Align the popup toward the left by default
			* field HeightSmall<integer> Max ~4 items visible. Tip: If you want your combo popup to be a specific size you can use SetNextWindowSizeConstraints() prior to calling BeginCombo()
			* field HeightRegular<integer> Max ~8 items visible (default)
			* field HeightLarge<integer> Max ~20 items visible
			* field HeightLargest<integer> As many fitting items as possible
			* field NoArrowButton<integer> Display on the preview box without the square arrow button
			* field NoPreview<integer> Display only a square arrow button
			* field WidthFitPreview<integer> Width dynamically calculated from preview contents
			* field HeightMask_<integer>
			@*/
			L.new_enum("ImGuiComboFlags",
				"None", ImGuiComboFlags_None,
				"PopupAlignLeft", ImGuiComboFlags_PopupAlignLeft,
				"HeightSmall", ImGuiComboFlags_HeightSmall,
				"HeightRegular", ImGuiComboFlags_HeightRegular,
				"HeightLarge", ImGuiComboFlags_HeightLarge,
				"HeightLargest", ImGuiComboFlags_HeightLargest,
				"NoArrowButton", ImGuiComboFlags_NoArrowButton,
				"NoPreview", ImGuiComboFlags_NoPreview,
				"WidthFitPreview", ImGuiComboFlags_WidthFitPreview,
				"HeightMask_", ImGuiComboFlags_HeightMask_);

			/*@terminus.enum ImGuiChildFlags
			* field None<integer>
			* field Borders<integer> Show an outer border and enable WindowPadding. (IMPORTANT: this is always == 1 == true for legacy reason)
			* field AlwaysUseWindowPadding<integer> Pad with style.WindowPadding even if no border are drawn (no padding by default for non-bordered child windows because it makes more sense)
			* field ResizeX<integer> Allow resize from right border (layout direction). Enable .ini saving (unless ImGuiWindowFlags_NoSavedSettings passed to window flags)
			* field ResizeY<integer> Allow resize from bottom border (layout direction). "
			* field AutoResizeX<integer> Enable auto-resizing width. Read "IMPORTANT: Size measurement" details above.
			* field AutoResizeY<integer> Enable auto-resizing height. Read "IMPORTANT: Size measurement" details above.
			* field AlwaysAutoResize<integer> Combined with AutoResizeX/AutoResizeY. Always measure size even when child is hidden, always return true, always disable clipping optimization! NOT RECOMMENDED.
			* field FrameStyle<integer> Style the child window like a framed item: use FrameBg, FrameRounding, FrameBorderSize, FramePadding instead of ChildBg, ChildRounding, ChildBorderSize, WindowPadding.
			* field NavFlattened<integer> [BETA] Share focus scope, allow keyboard/gamepad navigation to cross over parent border to this child or between sibling child windows.
			@*/
			L.new_enum("ImGuiChildFlags",
			    "None", ImGuiChildFlags_None,
			    "Borders", ImGuiChildFlags_Borders,
			    "AlwaysUseWindowPadding", ImGuiChildFlags_AlwaysUseWindowPadding,
			    "ResizeX", ImGuiChildFlags_ResizeX,
			    "ResizeY", ImGuiChildFlags_ResizeY,
			    "AutoResizeX", ImGuiChildFlags_AutoResizeX,
			    "AutoResizeY", ImGuiChildFlags_AutoResizeY,
			    "AlwaysAutoResize", ImGuiChildFlags_AlwaysAutoResize,
			    "FrameStyle", ImGuiChildFlags_FrameStyle,
			    "NavFlattened", ImGuiChildFlags_NavFlattened);

			/*@terminus.enum ImGuiWindowFlags
			* field None<integer>
			* field NoTitleBar<integer> Disable title-bar
			* field NoResize<integer> Disable user resizing with the lower-right grip
			* field NoMove<integer> Disable user moving the window
			* field NoScrollbar<integer> Disable scrollbars (window can still scroll with mouse or programmatically)
			* field NoScrollWithMouse<integer> Disable user vertically scrolling with mouse wheel. On child window, mouse wheel will be forwarded to the parent unless NoScrollbar is also set.
			* field NoCollapse<integer> Disable user collapsing window by double-clicking on it. Also referred to as Window Menu Button (e.g. within a docking node).
			* field AlwaysAutoResize<integer> Resize every window to its content every frame
			* field NoBackground<integer> Disable drawing background color (WindowBg, etc.) and outside border. Similar as using SetNextWindowBgAlpha(0.0f).
			* field NoSavedSettings<integer> Never load/save settings in .ini file
			* field NoMouseInputs<integer> Disable catching mouse, hovering test with pass through.
			* field MenuBar<integer> Has a menu-bar
			* field HorizontalScrollbar<integer> Allow horizontal scrollbar to appear (off by default). You may use SetNextWindowContentSize(ImVec2(width,0.0f)); prior to calling Begin() to specify width. Read code in imgui_demo in the "Horizontal Scrolling" section.
			* field NoFocusOnAppearing<integer> Disable taking focus when transitioning from hidden to visible state
			* field NoBringToFrontOnFocus<integer> Disable bringing window to front when taking focus (e.g. clicking on it or programmatically giving it focus)
			* field AlwaysVerticalScrollbar<integer> Always show vertical scrollbar (even if ContentSize.y < Size.y)
			* field AlwaysHorizontalScrollbar<integer> Always show horizontal scrollbar (even if ContentSize.x < Size.x)
			* field NoNavInputs<integer> No keyboard/gamepad navigation within the window
			* field NoNavFocus<integer> No focusing toward this window with keyboard/gamepad navigation (e.g. skipped by CTRL+TAB)
			* field UnsavedDocument<integer> Display a dot next to the title. When used in a tab/docking context, tab is selected when clicking the X + closure is not assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
			* field NoNav<integer>
			* field NoDecoration<integer>
			* field NoInputs<integer>
			@*/
			L.new_enum("ImGuiWindowFlags",
			    "None", ImGuiWindowFlags_None,
			    "NoTitleBar", ImGuiWindowFlags_NoTitleBar,
			    "NoResize", ImGuiWindowFlags_NoResize,
			    "NoMove", ImGuiWindowFlags_NoMove,
			    "NoScrollbar", ImGuiWindowFlags_NoScrollbar,
			    "NoScrollWithMouse", ImGuiWindowFlags_NoScrollWithMouse,
			    "NoCollapse", ImGuiWindowFlags_NoCollapse,
			    "AlwaysAutoResize", ImGuiWindowFlags_AlwaysAutoResize,
			    "NoBackground", ImGuiWindowFlags_NoBackground,
			    "NoSavedSettings", ImGuiWindowFlags_NoSavedSettings,
			    "NoMouseInputs", ImGuiWindowFlags_NoMouseInputs,
			    "MenuBar", ImGuiWindowFlags_MenuBar,
			    "HorizontalScrollbar", ImGuiWindowFlags_HorizontalScrollbar,
			    "NoFocusOnAppearing", ImGuiWindowFlags_NoFocusOnAppearing,
			    "NoBringToFrontOnFocus", ImGuiWindowFlags_NoBringToFrontOnFocus,
			    "AlwaysHorizontalScrollbar", ImGuiWindowFlags_AlwaysHorizontalScrollbar,
			    "NoNavInputs", ImGuiWindowFlags_NoNavInputs,
			    "NoNavFocus", ImGuiWindowFlags_NoNavFocus,
			    "UnsavedDocument", ImGuiWindowFlags_UnsavedDocument,
			    "NoNav", ImGuiWindowFlags_NoNav,
			    "NoDecoration", ImGuiWindowFlags_NoDecoration,
			    "NoInputs", ImGuiWindowFlags_NoInputs);

			/*@terminus.enum ImGuiStyleVar
			* field Alpha<integer> float     Alpha
			* field DisabledAlpha<integer> float     DisabledAlpha
			* field WindowPadding<integer> ImVec2    WindowPadding
			* field WindowRounding<integer> float     WindowRounding
			* field WindowBorderSize<integer> float     WindowBorderSize
			* field WindowMinSize<integer> ImVec2    WindowMinSize
			* field WindowTitleAlign<integer> ImVec2    WindowTitleAlign
			* field ChildRounding<integer> float     ChildRounding
			* field ChildBorderSize<integer> float     ChildBorderSize
			* field PopupRounding<integer> float     PopupRounding
			* field PopupBorderSize<integer> float     PopupBorderSize
			* field FramePadding<integer> ImVec2    FramePadding
			* field FrameRounding<integer> float     FrameRounding
			* field FrameBorderSize<integer> float     FrameBorderSize
			* field ItemSpacing<integer> ImVec2    ItemSpacing
			* field ItemInnerSpacing<integer> ImVec2    ItemInnerSpacing
			* field IndentSpacing<integer> float     IndentSpacing
			* field CellPadding<integer> ImVec2    CellPadding
			* field ScrollbarSize<integer> float     ScrollbarSize
			* field ScrollbarRounding<integer> float     ScrollbarRounding
			* field ScrollbarPadding<integer> float     ScrollbarPadding
			* field GrabMinSize<integer> float     GrabMinSize
			* field GrabRounding<integer> float     GrabRounding
			* field ImageBorderSize<integer> float     ImageBorderSize
			* field TabRounding<integer> float     TabRounding
			* field TabBorderSize<integer> float     TabBorderSize
			* field TabMinWidthBase<integer> float     TabMinWidthBase
			* field TabMinWidthShrink<integer> float     TabMinWidthShrink
			* field TabBarBorderSize<integer> float     TabBarBorderSize
			* field TabBarOverlineSize<integer> float     TabBarOverlineSize
			* field TableAngledHeadersAngle<integer> float     TableAngledHeadersAngle
			* field TableAngledHeadersTextAlign<integer> ImVec2  TableAngledHeadersTextAlign
			* field TreeLinesSize<integer> float     TreeLinesSize
			* field TreeLinesRounding<integer> float     TreeLinesRounding
			* field ButtonTextAlign<integer> ImVec2    ButtonTextAlign
			* field SelectableTextAlign<integer> ImVec2    SelectableTextAlign
			* field SeparatorTextBorderSize<integer> float     SeparatorTextBorderSize
			* field SeparatorTextAlign<integer> ImVec2    SeparatorTextAlign
			* field SeparatorTextPadding<integer> ImVec2    SeparatorTextPadding
			@*/
			L.new_enum("ImGuiStyleVar",
			    "DisabledAlpha", ImGuiStyleVar_DisabledAlpha,
			    "WindowPadding", ImGuiStyleVar_WindowPadding,
			    "WindowRounding", ImGuiStyleVar_WindowRounding,
			    "WindowBorderSize", ImGuiStyleVar_WindowBorderSize,
			    "WindowMinSize", ImGuiStyleVar_WindowMinSize,
			    "WindowTitleAlign", ImGuiStyleVar_WindowTitleAlign,
			    "ChildRounding", ImGuiStyleVar_ChildRounding,
			    "ChildBorderSize", ImGuiStyleVar_ChildBorderSize,
			    "PopupRounding", ImGuiStyleVar_PopupRounding,
			    "PopupBorderSize", ImGuiStyleVar_PopupBorderSize,
			    "FramePadding", ImGuiStyleVar_FramePadding,
			    "FrameRounding", ImGuiStyleVar_FrameRounding,
			    "FrameBorderSize", ImGuiStyleVar_FrameBorderSize,
			    "ItemSpacing", ImGuiStyleVar_ItemSpacing,
			    "ItemInnerSpacing", ImGuiStyleVar_ItemInnerSpacing,
			    "IndentSpacing", ImGuiStyleVar_IndentSpacing,
			    "CellPadding", ImGuiStyleVar_CellPadding,
			    "ScrollbarSize", ImGuiStyleVar_ScrollbarSize,
			    "ScrollbarRounding", ImGuiStyleVar_ScrollbarRounding,
			    "ScrollbarPadding", ImGuiStyleVar_ScrollbarPadding,
			    "GrabMinSize", ImGuiStyleVar_GrabMinSize,
			    "GrabRounding", ImGuiStyleVar_GrabRounding,
			    "ImageBorderSize", ImGuiStyleVar_ImageBorderSize,
			    "TabRounding", ImGuiStyleVar_TabRounding,
			    "TabBorderSize", ImGuiStyleVar_TabBorderSize,
			    "TabMinWidthBase", ImGuiStyleVar_TabMinWidthBase,
			    "TabMinWidthShrink", ImGuiStyleVar_TabMinWidthShrink,
			    "TabBarBorderSize", ImGuiStyleVar_TabBarBorderSize,
			    "TabBarOverlineSize", ImGuiStyleVar_TabBarOverlineSize,
			    "TableAngledHeadersAngle", ImGuiStyleVar_TableAngledHeadersAngle,
			    "TableAngledHeadersTextAlign", ImGuiStyleVar_TableAngledHeadersTextAlign,
			    "TreeLinesSize", ImGuiStyleVar_TreeLinesSize,
			    "TreeLinesRounding", ImGuiStyleVar_TreeLinesRounding,
			    "ButtonTextAlign", ImGuiStyleVar_ButtonTextAlign,
			    "SelectableTextAlign", ImGuiStyleVar_SelectableTextAlign,
			    "SeparatorTextBorderSize", ImGuiStyleVar_SeparatorTextBorderSize,
			    "SeparatorTextAlign", ImGuiStyleVar_SeparatorTextAlign,
			    "SeparatorTextPadding", ImGuiStyleVar_SeparatorTextPadding);

			/*@terminus.enum ImGuiCol
			* field Text<integer>
			* field TextDisabled<integer>
			* field WindowBg<integer> Background of normal windows
			* field ChildBg<integer> Background of child windows
			* field PopupBg<integer> Background of popups, menus, tooltips windows
			* field Border<integer>
			* field BorderShadow<integer>
			* field FrameBg<integer> Background of checkbox, radio button, plot, slider, text input
			* field FrameBgHovered<integer>
			* field FrameBgActive<integer>
			* field TitleBg<integer> Title bar
			* field TitleBgActive<integer> Title bar when focused
			* field TitleBgCollapsed<integer> Title bar when collapsed
			* field MenuBarBg<integer>
			* field ScrollbarBg<integer>
			* field ScrollbarGrab<integer>
			* field ScrollbarGrabHovered<integer>
			* field ScrollbarGrabActive<integer>
			* field CheckMark<integer> Checkbox tick and RadioButton circle
			* field SliderGrab<integer>
			* field SliderGrabActive<integer>
			* field Button<integer>
			* field ButtonHovered<integer>
			* field ButtonActive<integer>
			* field Header<integer> Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
			* field HeaderHovered<integer>
			* field HeaderActive<integer>
			* field Separator<integer>
			* field SeparatorHovered<integer>
			* field SeparatorActive<integer>
			* field ResizeGrip<integer> Resize grip in lower-right and lower-left corners of windows.
			* field ResizeGripHovered<integer>
			* field ResizeGripActive<integer>
			* field InputTextCursor<integer> InputText cursor/caret
			* field TabHovered<integer> Tab background, when hovered
			* field Tab<integer> Tab background, when tab-bar is focused & tab is unselected
			* field TabSelected<integer> Tab background, when tab-bar is focused & tab is selected
			* field TabSelectedOverline<integer> Tab horizontal overline, when tab-bar is focused & tab is selected
			* field TabDimmed<integer> Tab background, when tab-bar is unfocused & tab is unselected
			* field TabDimmedSelected<integer> Tab background, when tab-bar is unfocused & tab is selected
			* field TabDimmedSelectedOverline<integer> horizontal overline, when tab-bar is unfocused & tab is selected
			* field PlotLines<integer>
			* field PlotLinesHovered<integer>
			* field PlotHistogram<integer>
			* field PlotHistogramHovered<integer>
			* field TableHeaderBg<integer> Table header background
			* field TableBorderStrong<integer> Table outer and header borders (prefer using Alpha=1.0 here)
			* field TableBorderLight<integer> Table inner borders (prefer using Alpha=1.0 here)
			* field TableRowBg<integer> Table row background (even rows)
			* field TableRowBgAlt<integer> Table row background (odd rows)
			* field TextLink<integer> Hyperlink color
			* field TextSelectedBg<integer> Selected text inside an InputText
			* field TreeLines<integer> Tree node hierarchy outlines when using ImGuiTreeNodeFlags_DrawLines
			* field DragDropTarget<integer> Rectangle highlighting a drop target
			* field UnsavedMarker<integer> Unsaved Document marker (in window title and tabs)
			* field NavCursor<integer> Color of keyboard/gamepad navigation cursor/rectangle, when visible
			* field NavWindowingHighlight<integer> Highlight window when using CTRL+TAB
			* field NavWindowingDimBg<integer> Darken/colorize entire screen behind the CTRL+TAB window list, when active
			* field ModalWindowDimBg<integer> Darken/colorize entire screen behind a modal window, when one is active
			@*/
			L.new_enum("ImGuiCol",
			    "TextDisabled", ImGuiCol_TextDisabled,
			    "WindowBg", ImGuiCol_WindowBg,
			    "ChildBg", ImGuiCol_ChildBg,
			    "PopupBg", ImGuiCol_PopupBg,
			    "Border", ImGuiCol_Border,
			    "BorderShadow", ImGuiCol_BorderShadow,
			    "FrameBg", ImGuiCol_FrameBg,
			    "FrameBgHovered", ImGuiCol_FrameBgHovered,
			    "FrameBgActive", ImGuiCol_FrameBgActive,
			    "TitleBg", ImGuiCol_TitleBg,
			    "TitleBgActive", ImGuiCol_TitleBgActive,
			    "TitleBgCollapsed", ImGuiCol_TitleBgCollapsed,
			    "MenuBarBg", ImGuiCol_MenuBarBg,
			    "ScrollbarBg", ImGuiCol_ScrollbarBg,
			    "ScrollbarGrab", ImGuiCol_ScrollbarGrab,
			    "ScrollbarGrabHovered", ImGuiCol_ScrollbarGrabHovered,
			    "ScrollbarGrabActive", ImGuiCol_ScrollbarGrabActive,
			    "CheckMark", ImGuiCol_CheckMark,
			    "SliderGrab", ImGuiCol_SliderGrab,
			    "SliderGrabActive", ImGuiCol_SliderGrabActive,
			    "Button", ImGuiCol_Button,
			    "ButtonHovered", ImGuiCol_ButtonHovered,
			    "ButtonActive", ImGuiCol_ButtonActive,
			    "Header", ImGuiCol_Header,
			    "HeaderHovered", ImGuiCol_HeaderHovered,
			    "HeaderActive", ImGuiCol_HeaderActive,
			    "Separator", ImGuiCol_Separator,
			    "SeparatorHovered", ImGuiCol_SeparatorHovered,
			    "SeparatorActive", ImGuiCol_SeparatorActive,
			    "ResizeGrip", ImGuiCol_ResizeGrip,
			    "ResizeGripHovered", ImGuiCol_ResizeGripHovered,
			    "ResizeGripActive", ImGuiCol_ResizeGripActive,
			    "InputTextCursor", ImGuiCol_InputTextCursor,
			    "TabHovered", ImGuiCol_TabHovered,
			    "Tab", ImGuiCol_Tab,
			    "TabSelected", ImGuiCol_TabSelected,
			    "TabSelectedOverline", ImGuiCol_TabSelectedOverline,
			    "TabDimmed", ImGuiCol_TabDimmed,
			    "TabDimmedSelected", ImGuiCol_TabDimmedSelected,
			    "TabDimmedSelectedOverline", ImGuiCol_TabDimmedSelectedOverline,
			    "PlotLines", ImGuiCol_PlotLines,
			    "PlotLinesHovered", ImGuiCol_PlotLinesHovered,
			    "PlotHistogram", ImGuiCol_PlotHistogram,
			    "PlotHistogramHovered", ImGuiCol_PlotHistogramHovered,
			    "TableHeaderBg", ImGuiCol_TableHeaderBg,
			    "TableBorderStrong", ImGuiCol_TableBorderStrong,
			    "TableBorderLight", ImGuiCol_TableBorderLight,
			    "TableRowBg", ImGuiCol_TableRowBg,
			    "TableRowBgAlt", ImGuiCol_TableRowBgAlt,
			    "TextLink", ImGuiCol_TextLink,
			    "TextSelectedBg", ImGuiCol_TextSelectedBg,
			    "TreeLines", ImGuiCol_TreeLines,
			    "DragDropTarget", ImGuiCol_DragDropTarget,
			    "UnsavedMarker", ImGuiCol_UnsavedMarker,
			    "NavCursor", ImGuiCol_NavCursor,
			    "NavWindowingHighlight", ImGuiCol_NavWindowingHighlight,
			    "NavWindowingDimBg", ImGuiCol_NavWindowingDimBg,
			    "ModalWindowDimBg", ImGuiCol_ModalWindowDimBg);

			/*@terminus.enum ImGuiPopupFlags
			* field None<integer>
			* field MouseButtonLeft<integer> For BeginPopupContext*(): open on Left Mouse release. Guaranteed to always be == 0 (same as ImGuiMouseButton_Left)
			* field MouseButtonRight<integer> For BeginPopupContext*(): open on Right Mouse release. Guaranteed to always be == 1 (same as ImGuiMouseButton_Right)
			* field MouseButtonMiddle<integer> For BeginPopupContext*(): open on Middle Mouse release. Guaranteed to always be == 2 (same as ImGuiMouseButton_Middle)
			* field MouseButtonMask_<integer>
			* field MouseButtonDefault_<integer>
			* field NoReopen<integer> For OpenPopup*(), BeginPopupContext*(): don't reopen same popup if already open (won't reposition, won't reinitialize navigation)
			* field NoOpenOverExistingPopup<integer> For OpenPopup*(), BeginPopupContext*(): don't open if there's already a popup at the same level of the popup stack
			* field NoOpenOverItems<integer> For BeginPopupContextWindow(): don't return true when hovering items, only when hovering empty space
			* field AnyPopupId<integer> For IsPopupOpen(): ignore the ImGuiID parameter and test for any popup.
			* field AnyPopupLevel<integer> For IsPopupOpen(): search/test at any level of the popup stack (default test in the current level)
			* field AnyPopup<integer>
			@*/
			L.new_enum("ImGuiPopupFlags",
			    "None", ImGuiPopupFlags_None,
			    "MouseButtonLeft", ImGuiPopupFlags_MouseButtonLeft,
			    "MouseButtonRight", ImGuiPopupFlags_MouseButtonRight,
			    "MouseButtonMiddle", ImGuiPopupFlags_MouseButtonMiddle,
			    "MouseButtonMask_", ImGuiPopupFlags_MouseButtonMask_,
			    "MouseButtonDefault_", ImGuiPopupFlags_MouseButtonDefault_,
			    "NoReopen", ImGuiPopupFlags_NoReopen,
			    "NoOpenOverExistingPopup", ImGuiPopupFlags_NoOpenOverExistingPopup,
			    "NoOpenOverItems", ImGuiPopupFlags_NoOpenOverItems,
			    "AnyPopupId", ImGuiPopupFlags_AnyPopupId,
			    "AnyPopupLevel", ImGuiPopupFlags_AnyPopupLevel,
			    "AnyPopup", ImGuiPopupFlags_AnyPopup);

			/*@terminus.enum ImGuiSelectableFlags
			* field None<integer>
			* field NoAutoClosePopups<integer> Clicking this doesn't close parent popup window (overrides ImGuiItemFlags_AutoClosePopups)
			* field SpanAllColumns<integer> Frame will span all columns of its container table (text will still fit in current column)
			* field AllowDoubleClick<integer> Generate press events on double clicks too
			* field Disabled<integer> Cannot be selected, display grayed out text
			* field AllowOverlap<integer> (WIP) Hit testing to allow subsequent widgets to overlap this one
			* field Highlight<integer> Make the item be displayed as if it is hovered
			* field SelectOnNav<integer> Auto-select when moved into, unless Ctrl is held. Automatic when in a BeginMultiSelect() block.
			@*/
			L.new_enum("ImGuiSelectableFlags",
			    "None", ImGuiSelectableFlags_None,
			    "NoAutoClosePopups", ImGuiSelectableFlags_NoAutoClosePopups,
			    "SpanAllColumns", ImGuiSelectableFlags_SpanAllColumns,
			    "AllowDoubleClick", ImGuiSelectableFlags_AllowDoubleClick,
			    "Disabled", ImGuiSelectableFlags_Disabled,
			    "AllowOverlap", ImGuiSelectableFlags_AllowOverlap,
			    "Highlight", ImGuiSelectableFlags_Highlight,
			    "SelectOnNav", ImGuiSelectableFlags_SelectOnNav);

			/*@terminus.enum ImGuiInputTextFlags
			* field None<integer>
			* field CharsDecimal<integer> Allow 0123456789.+-* /
			* field CharsHexadecimal<integer> Allow 0123456789ABCDEFabcdef
			* field CharsScientific<integer> Allow 0123456789.+-* /eE (Scientific notation input)
			* field CharsUppercase<integer> Turn a..z into A..Z
			* field CharsNoBlank<integer> Filter out spaces, tabs
			* field AllowTabInput<integer> Pressing TAB input a '\t' character into the text field
			* field EnterReturnsTrue<integer> Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider using IsItemDeactivatedAfterEdit() instead!
			* field EscapeClearsAll<integer> Escape key clears content if not empty, and deactivate otherwise (contrast to default behavior of Escape to revert)
			* field CtrlEnterForNewLine<integer> In multi-line mode, validate with Enter, add new line with Ctrl+Enter (default is opposite: validate with Ctrl+Enter, add line with Enter).
			* field ReadOnly<integer> Read-only mode
			* field Password<integer> Password mode, display all characters as '*', disable copy
			* field AlwaysOverwrite<integer> Overwrite mode
			* field AutoSelectAll<integer> Select entire text when first taking mouse focus
			* field ParseEmptyRefVal<integer> InputFloat(), InputInt(), InputScalar() etc. only: parse empty string as zero value.
			* field DisplayEmptyRefVal<integer> InputFloat(), InputInt(), InputScalar() etc. only: when value is zero, do not display it. Generally used with ImGuiInputTextFlags_ParseEmptyRefVal.
			* field NoHorizontalScroll<integer> Disable following the cursor horizontally
			* field NoUndoRedo<integer> Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
			* field ElideLeft<integer> When text doesn't fit, elide left side to ensure right side stays visible. Useful for path/filenames. Single-line only!
			* field CallbackCompletion<integer> Callback on pressing TAB (for completion handling)
			* field CallbackHistory<integer> Callback on pressing Up/Down arrows (for history handling)
			* field CallbackAlways<integer> Callback on each iteration. User code may query cursor position, modify text buffer.
			* field CallbackCharFilter<integer> Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard.
			* field CallbackResize<integer> Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)
			* field CallbackEdit<integer> Callback on any edit. Note that InputText() already returns true on edit + you can always use IsItemEdited(). The callback is useful to manipulate the underlying buffer while focus is active.
			* field WordWrap<integer> InputTextMultine(): word-wrap lines that are too long.
			@*/
			L.new_enum("ImGuiInputTextFlags",
			    "None", ImGuiInputTextFlags_None,
			    "CharsDecimal", ImGuiInputTextFlags_CharsDecimal,
			    "CharsHexadecimal", ImGuiInputTextFlags_CharsHexadecimal,
			    "CharsScientific", ImGuiInputTextFlags_CharsScientific,
			    "CharsUppercase", ImGuiInputTextFlags_CharsUppercase,
			    "CharsNoBlank", ImGuiInputTextFlags_CharsNoBlank,
			    "AllowTabInput", ImGuiInputTextFlags_AllowTabInput,
			    "EnterReturnsTrue", ImGuiInputTextFlags_EnterReturnsTrue,
			    "EscapeClearsAll", ImGuiInputTextFlags_EscapeClearsAll,
			    "CtrlEnterForNewLine", ImGuiInputTextFlags_CtrlEnterForNewLine,
			    "ReadOnly", ImGuiInputTextFlags_ReadOnly,
			    "Password", ImGuiInputTextFlags_Password,
			    "AlwaysOverwrite", ImGuiInputTextFlags_AlwaysOverwrite,
			    "AutoSelectAll", ImGuiInputTextFlags_AutoSelectAll,
			    "ParseEmptyRefVal", ImGuiInputTextFlags_ParseEmptyRefVal,
			    "DisplayEmptyRefVal", ImGuiInputTextFlags_DisplayEmptyRefVal,
			    "NoHorizontalScroll", ImGuiInputTextFlags_NoHorizontalScroll,
			    "NoUndoRedo", ImGuiInputTextFlags_NoUndoRedo,
			    "ElideLeft", ImGuiInputTextFlags_ElideLeft,
			    "CallbackCompletion", ImGuiInputTextFlags_CallbackCompletion,
			    "CallbackHistory", ImGuiInputTextFlags_CallbackHistory,
			    "CallbackAlways", ImGuiInputTextFlags_CallbackAlways,
			    "CallbackCharFilter", ImGuiInputTextFlags_CallbackCharFilter,
			    "CallbackResize", ImGuiInputTextFlags_CallbackResize,
			    "CallbackEdit", ImGuiInputTextFlags_CallbackEdit,
			    "WordWrap", ImGuiInputTextFlags_WordWrap);

			/*@terminus.enum ImGuiSliderFlags
			* field None<integer>
			* field Logarithmic<integer> Make the widget logarithmic (linear otherwise). Consider using ImGuiSliderFlags_NoRoundToFormat with this if using a format-string with small amount of digits.
			* field NoRoundToFormat<integer> Disable rounding underlying value to match precision of the display format string (e.g. %.3f values are rounded to those 3 digits).
			* field NoInput<integer> Disable CTRL+Click or Enter key allowing to input text directly into the widget.
			* field WrapAround<integer> Enable wrapping around from max to min and from min to max. Only supported by DragXXX() functions for now.
			* field ClampOnInput<integer> Clamp value to min/max bounds when input manually with CTRL+Click. By default CTRL+Click allows going out of bounds.
			* field ClampZeroRange<integer> Clamp even if min==max==0.0f. Otherwise due to legacy reason DragXXX functions don't clamp with those values. When your clamping limits are dynamic you almost always want to use it.
			* field NoSpeedTweaks<integer> Disable keyboard modifiers altering tweak speed. Useful if you want to alter tweak speed yourself based on your own logic.
			* field AlwaysClamp<integer>
			@*/
			L.new_enum("ImGuiSliderFlags",
				"None", ImGuiSliderFlags_None,
				"Logarithmic", ImGuiSliderFlags_Logarithmic,
				"NoRoundToFormat", ImGuiSliderFlags_NoRoundToFormat,
				"NoInput", ImGuiSliderFlags_NoInput,
				"WrapAround", ImGuiSliderFlags_WrapAround,
				"ClampOnInput", ImGuiSliderFlags_ClampOnInput,
				"ClampZeroRange", ImGuiSliderFlags_ClampZeroRange,
				"NoSpeedTweaks", ImGuiSliderFlags_NoSpeedTweaks,
				"AlwaysClamp", ImGuiSliderFlags_AlwaysClamp);

			/*@terminus.enum ImGuiTableFlags
			* field None<integer> 
			* field Resizable<integer> Enable resizing columns.
			* field Reorderable<integer> Enable reordering columns in header row (need calling TableSetupColumn() + TableHeadersRow() to display headers)
			* field Hideable<integer> Enable hiding/disabling columns in context menu.
			* field Sortable<integer> Enable sorting. Call TableGetSortSpecs() to obtain sort specs. Also see ImGuiTableFlags_SortMulti and ImGuiTableFlags_SortTristate.
			* field NoSavedSettings<integer> Disable persisting columns order, width and sort settings in the .ini file.
			* field ContextMenuInBody<integer> Right-click on columns body/contents will display table context menu. By default it is available in TableHeadersRow().
			* field RowBg<integer> Set each RowBg color with ImGuiCol_TableRowBg or ImGuiCol_TableRowBgAlt (equivalent of calling TableSetBgColor with ImGuiTableBgFlags_RowBg0 on each row manually)
			* field BordersInnerH<integer> Draw horizontal borders between rows.
			* field BordersOuterH<integer> Draw horizontal borders at the top and bottom.
			* field BordersInnerV<integer> Draw vertical borders between columns.
			* field BordersOuterV<integer> Draw vertical borders on the left and right sides.
			* field BordersH<integer> Draw horizontal borders.
			* field BordersV<integer> Draw vertical borders.
			* field BordersInner<integer> Draw inner borders.
			* field BordersOuter<integer> Draw outer borders.
			* field Borders<integer> Draw all borders.
			* field NoBordersInBody<integer> [ALPHA] Disable vertical borders in columns Body (borders will always appear in Headers). -> May move to style
			* field NoBordersInBodyUntilResize<integer> [ALPHA] Disable vertical borders in columns Body until hovered for resize (borders will always appear in Headers). -> May move to style
			* field SizingFixedFit<integer> Columns default to _WidthFixed or _WidthAuto (if resizable or not resizable), matching contents width.
			* field SizingFixedSame<integer> Columns default to _WidthFixed or _WidthAuto (if resizable or not resizable), matching the maximum contents width of all columns. Implicitly enable ImGuiTableFlags_NoKeepColumnsVisible.
			* field SizingStretchProp<integer> Columns default to _WidthStretch with default weights proportional to each columns contents widths.
			* field SizingStretchSame<integer> Columns default to _WidthStretch with default weights all equal, unless overridden by TableSetupColumn().
			* field NoHostExtendX<integer> Make outer width auto-fit to columns, overriding outer_size.x value. Only available when ScrollX/ScrollY are disabled and Stretch columns are not used.
			* field NoHostExtendY<integer> Make outer height stop exactly at outer_size.y (prevent auto-extending table past the limit). Only available when ScrollX/ScrollY are disabled. Data below the limit will be clipped and not visible.
			* field NoKeepColumnsVisible<integer> Disable keeping column always minimally visible when ScrollX is off and table gets too small. Not recommended if columns are resizable.
			* field PreciseWidths<integer> Disable distributing remainder width to stretched columns (width allocation on a 100-wide table with 3 columns: Without this flag: 33,33,34. With this flag: 33,33,33). With larger number of columns, resizing will appear to be less smooth.
			* field NoClip<integer> Disable clipping rectangle for every individual columns (reduce draw command count, items will be able to overflow into other columns). Generally incompatible with TableSetupScrollFreeze().
			* field PadOuterX<integer> Default if BordersOuterV is on. Enable outermost padding. Generally desirable if you have headers.
			* field NoPadOuterX<integer> Default if BordersOuterV is off. Disable outermost padding.
			* field NoPadInnerX<integer> Disable inner padding between columns (double inner padding if BordersOuterV is on, single inner padding if BordersOuterV is off).
			* field ScrollX<integer> Enable horizontal scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size. Changes default sizing policy. Because this creates a child window, ScrollY is currently generally recommended when using ScrollX.
			* field ScrollY<integer> Enable vertical scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size.
			* field SortMulti<integer> Hold shift when clicking headers to sort on multiple column. TableGetSortSpecs() may return specs where (SpecsCount > 1).
			* field SortTristate<integer> Allow no sorting, disable default sorting. TableGetSortSpecs() may return specs where (SpecsCount == 0).
			* field HighlightHoveredColumn<integer> Highlight column headers when hovered (may evolve into a fuller highlight)
			* field SizingMask_<integer> 
			@*/
			L.new_enum("ImGuiTableFlags",
				"None", ImGuiTableFlags_None,
				"Resizable", ImGuiTableFlags_Resizable,
				"Reorderable", ImGuiTableFlags_Reorderable,
				"Hideable", ImGuiTableFlags_Hideable,
				"Sortable", ImGuiTableFlags_Sortable,
				"NoSavedSettings", ImGuiTableFlags_NoSavedSettings,
				"ContextMenuInBody", ImGuiTableFlags_ContextMenuInBody,
				"RowBg", ImGuiTableFlags_RowBg,
				"BordersInnerH", ImGuiTableFlags_BordersInnerH,
				"BordersOuterH", ImGuiTableFlags_BordersOuterH,
				"BordersInnerV", ImGuiTableFlags_BordersInnerV,
				"BordersOuterV", ImGuiTableFlags_BordersOuterV,
				"BordersH", ImGuiTableFlags_BordersH,
				"BordersV", ImGuiTableFlags_BordersV,
				"BordersInner", ImGuiTableFlags_BordersInner,
				"BordersOuter", ImGuiTableFlags_BordersOuter,
				"Borders", ImGuiTableFlags_Borders,
				"NoBordersInBody", ImGuiTableFlags_NoBordersInBody,
				"NoBordersInBodyUntilResize", ImGuiTableFlags_NoBordersInBodyUntilResize,
				"SizingFixedFit", ImGuiTableFlags_SizingFixedFit,
				"SizingFixedSame", ImGuiTableFlags_SizingFixedSame,
				"SizingStretchProp", ImGuiTableFlags_SizingStretchProp,
				"SizingStretchSame", ImGuiTableFlags_SizingStretchSame,
				"NoHostExtendX", ImGuiTableFlags_NoHostExtendX,
				"NoHostExtendY", ImGuiTableFlags_NoHostExtendY,
				"NoKeepColumnsVisible", ImGuiTableFlags_NoKeepColumnsVisible,
				"PreciseWidths", ImGuiTableFlags_PreciseWidths,
				"NoClip", ImGuiTableFlags_NoClip,
				"PadOuterX", ImGuiTableFlags_PadOuterX,
				"NoPadOuterX", ImGuiTableFlags_NoPadOuterX,
				"NoPadInnerX", ImGuiTableFlags_NoPadInnerX,
				"ScrollX", ImGuiTableFlags_ScrollX,
				"ScrollY", ImGuiTableFlags_ScrollY,
				"SortMulti", ImGuiTableFlags_SortMulti,
				"SortTristate", ImGuiTableFlags_SortTristate,
				"HighlightHoveredColumn", ImGuiTableFlags_HighlightHoveredColumn,
				"SizingMask_", ImGuiTableFlags_SizingMask_);

			/*@terminus.enum ImGuiTableColumnFlags
			* field None<integer> 
			* field Disabled<integer> Overriding/master disable flag: hide column, won't show in context menu (unlike calling TableSetColumnEnabled() which manipulates the user accessible state)
			* field DefaultHide<integer> Default as a hidden/disabled column.
			* field DefaultSort<integer> Default as a sorting column.
			* field WidthStretch<integer> Column will stretch. Preferable with horizontal scrolling disabled (default if table sizing policy is _SizingStretchSame or _SizingStretchProp).
			* field WidthFixed<integer> Column will not stretch. Preferable with horizontal scrolling enabled (default if table sizing policy is _SizingFixedFit and table is resizable).
			* field NoResize<integer> Disable manual resizing.
			* field NoReorder<integer> Disable manual reordering this column, this will also prevent other columns from crossing over this column.
			* field NoHide<integer> Disable ability to hide/disable this column.
			* field NoClip<integer> Disable clipping for this column (all NoClip columns will render in a same draw command).
			* field NoSort<integer> Disable ability to sort on this field (even if ImGuiTableFlags_Sortable is set on the table).
			* field NoSortAscending<integer> Disable ability to sort in the ascending direction.
			* field NoSortDescending<integer> Disable ability to sort in the descending direction.
			* field NoHeaderLabel<integer> TableHeadersRow() will submit an empty label for this column. Convenient for some small columns. Name will still appear in context menu or in angled headers. You may append into this cell by calling TableSetColumnIndex() right after the TableHeadersRow() call.
			* field NoHeaderWidth<integer> Disable header text width contribution to automatic column width.
			* field PreferSortAscending<integer> Make the initial sort direction Ascending when first sorting on this column (default).
			* field PreferSortDescending<integer> Make the initial sort direction Descending when first sorting on this column.
			* field IndentEnable<integer> Use current Indent value when entering cell (default for column 0).
			* field IndentDisable<integer> Ignore current Indent value when entering cell (default for columns > 0). Indentation changes _within_ the cell will still be honored.
			* field AngledHeader<integer> TableHeadersRow() will submit an angled header row for this column. Note this will add an extra row.
			* field IsEnabled<integer> Status: is enabled == not hidden by user/api (referred to as "Hide" in _DefaultHide and _NoHide) flags.
			* field IsVisible<integer> Status: is visible == is enabled AND not clipped by scrolling.
			* field IsSorted<integer> Status: is currently part of the sort specs
			* field IsHovered<integer> Status: is hovered by mouse
			* field WidthMask_<integer> 
			* field IndentMask_<integer> 
			* field StatusMask_<integer> 
			* field NoDirectResize_<integer> [Internal] Disable user resizing this column directly (it may however we resized indirectly from its left edge)
			@*/
			L.new_enum("ImGuiTableColumnFlags",
				"None", ImGuiTableColumnFlags_None,
				"Disabled", ImGuiTableColumnFlags_Disabled,
				"DefaultHide", ImGuiTableColumnFlags_DefaultHide,
				"DefaultSort", ImGuiTableColumnFlags_DefaultSort,
				"WidthStretch", ImGuiTableColumnFlags_WidthStretch,
				"WidthFixed", ImGuiTableColumnFlags_WidthFixed,
				"NoResize", ImGuiTableColumnFlags_NoResize,
				"NoReorder", ImGuiTableColumnFlags_NoReorder,
				"NoHide", ImGuiTableColumnFlags_NoHide,
				"NoClip", ImGuiTableColumnFlags_NoClip,
				"NoSort", ImGuiTableColumnFlags_NoSort,
				"NoSortAscending", ImGuiTableColumnFlags_NoSortAscending,
				"NoSortDescending", ImGuiTableColumnFlags_NoSortDescending,
				"NoHeaderLabel", ImGuiTableColumnFlags_NoHeaderLabel,
				"NoHeaderWidth", ImGuiTableColumnFlags_NoHeaderWidth,
				"PreferSortAscending", ImGuiTableColumnFlags_PreferSortAscending,
				"PreferSortDescending", ImGuiTableColumnFlags_PreferSortDescending,
				"IndentEnable", ImGuiTableColumnFlags_IndentEnable,
				"IndentDisable", ImGuiTableColumnFlags_IndentDisable,
				"AngledHeader", ImGuiTableColumnFlags_AngledHeader,
				"IsEnabled", ImGuiTableColumnFlags_IsEnabled,
				"IsVisible", ImGuiTableColumnFlags_IsVisible,
				"IsSorted", ImGuiTableColumnFlags_IsSorted,
				"IsHovered", ImGuiTableColumnFlags_IsHovered,
				"WidthMask_", ImGuiTableColumnFlags_WidthMask_,
				"IndentMask_", ImGuiTableColumnFlags_IndentMask_,
				"StatusMask_", ImGuiTableColumnFlags_StatusMask_,
				"NoDirectResize_", ImGuiTableColumnFlags_NoDirectResize_);

			/*@terminus.enum ImGuiColorEditFlags
			* field None<integer> 
			* field NoAlpha<integer> ColorEdit, ColorPicker, ColorButton: ignore Alpha component (will only read 3 components from the input pointer).
			* field NoPicker<integer> ColorEdit: disable picker when clicking on color square.
			* field NoOptions<integer> ColorEdit: disable toggling options menu when right-clicking on inputs/small preview.
			* field NoSmallPreview<integer> ColorEdit, ColorPicker: disable color square preview next to the inputs. (e.g. to show only the inputs)
			* field NoInputs<integer> ColorEdit, ColorPicker: disable inputs sliders/text widgets (e.g. to show only the small preview color square).
			* field NoTooltip<integer> ColorEdit, ColorPicker, ColorButton: disable tooltip when hovering the preview.
			* field NoLabel<integer> ColorEdit, ColorPicker: disable display of inline text label (the label is still forwarded to the tooltip and picker).
			* field NoSidePreview<integer> ColorPicker: disable bigger color preview on right side of the picker, use small color square preview instead.
			* field NoDragDrop<integer> ColorEdit: disable drag and drop target. ColorButton: disable drag and drop source.
			* field NoBorder<integer> ColorButton: disable border (which is enforced by default)
			* field AlphaOpaque<integer> ColorEdit, ColorPicker, ColorButton: disable alpha in the preview,. Contrary to _NoAlpha it may still be edited when calling ColorEdit4()/ColorPicker4(). For ColorButton() this does the same as _NoAlpha.
			* field AlphaNoBg<integer> ColorEdit, ColorPicker, ColorButton: disable rendering a checkerboard background behind transparent color.
			* field AlphaPreviewHalf<integer> ColorEdit, ColorPicker, ColorButton: display half opaque / half transparent preview.
			* field AlphaBar<integer> ColorEdit, ColorPicker: show vertical alpha bar/gradient in picker.
			* field HDR<integer> (WIP) ColorEdit: Currently only disable 0.0f..1.0f limits in RGBA edition (note: you probably want to use ImGuiColorEditFlags_Float flag as well).
			* field DisplayRGB<integer> ColorEdit: override _display_ type among RGB/HSV/Hex. ColorPicker: select any combination using one or more of RGB/HSV/Hex.
			* field DisplayHSV<integer> "
			* field DisplayHex<integer> "
			* field Uint8<integer> ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0..255.
			* field Float<integer> ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0.0f..1.0f floats instead of 0..255 integers. No round-trip of value via integers.
			* field PickerHueBar<integer> ColorPicker: bar for Hue, rectangle for Sat/Value.
			* field PickerHueWheel<integer> ColorPicker: wheel for Hue, triangle for Sat/Value.
			* field InputRGB<integer> ColorEdit, ColorPicker: input and output data in RGB format.
			* field InputHSV<integer> ColorEdit, ColorPicker: input and output data in HSV format.
			* field DefaultOptions_<integer> 
			* field AlphaMask_<integer> 
			* field DisplayMask_<integer> 
			* field DataTypeMask_<integer> 
			* field PickerMask_<integer> 
			* field InputMask_<integer> 
			@*/
			L.new_enum("ImGuiColorEditFlags",
				"None", ImGuiColorEditFlags_None,
				"NoAlpha", ImGuiColorEditFlags_NoAlpha,
				"NoPicker", ImGuiColorEditFlags_NoPicker,
				"NoOptions", ImGuiColorEditFlags_NoOptions,
				"NoSmallPreview", ImGuiColorEditFlags_NoSmallPreview,
				"NoInputs", ImGuiColorEditFlags_NoInputs,
				"NoTooltip", ImGuiColorEditFlags_NoTooltip,
				"NoLabel", ImGuiColorEditFlags_NoLabel,
				"NoSidePreview", ImGuiColorEditFlags_NoSidePreview,
				"NoDragDrop", ImGuiColorEditFlags_NoDragDrop,
				"NoBorder", ImGuiColorEditFlags_NoBorder,
				"AlphaOpaque", ImGuiColorEditFlags_AlphaOpaque,
				"AlphaNoBg", ImGuiColorEditFlags_AlphaNoBg,
				"AlphaPreviewHalf", ImGuiColorEditFlags_AlphaPreviewHalf,
				"AlphaBar", ImGuiColorEditFlags_AlphaBar,
				"HDR", ImGuiColorEditFlags_HDR,
				"DisplayRGB", ImGuiColorEditFlags_DisplayRGB,
				"DisplayHSV", ImGuiColorEditFlags_DisplayHSV,
				"DisplayHex", ImGuiColorEditFlags_DisplayHex,
				"Uint8", ImGuiColorEditFlags_Uint8,
				"Float", ImGuiColorEditFlags_Float,
				"PickerHueBar", ImGuiColorEditFlags_PickerHueBar,
				"PickerHueWheel", ImGuiColorEditFlags_PickerHueWheel,
				"InputRGB", ImGuiColorEditFlags_InputRGB,
				"InputHSV", ImGuiColorEditFlags_InputHSV,
				"DefaultOptions_", ImGuiColorEditFlags_DefaultOptions_,
				"AlphaMask_", ImGuiColorEditFlags_AlphaMask_,
				"DisplayMask_", ImGuiColorEditFlags_DisplayMask_,
				"DataTypeMask_", ImGuiColorEditFlags_DataTypeMask_,
				"PickerMask_", ImGuiColorEditFlags_PickerMask_,
				"InputMask_", ImGuiColorEditFlags_InputMask_);

			/*@terminus.enum ImGuiHoveredFlags
			* field None<integer> Return true if directly over the item/window, not obstructed by another window, not obstructed by an active popup or modal blocking inputs under them.
			* field ChildWindows<integer> IsWindowHovered() only: Return true if any children of the window is hovered
			* field RootWindow<integer> IsWindowHovered() only: Test from root window (top most parent of the current hierarchy)
			* field AnyWindow<integer> IsWindowHovered() only: Return true if any window is hovered
			* field NoPopupHierarchy<integer> IsWindowHovered() only: Do not consider popup hierarchy (do not treat popup emitter as parent of popup) (when used with _ChildWindows or _RootWindow)
			* field AllowWhenBlockedByPopup<integer> Return true even if a popup window is normally blocking access to this item/window
			* field AllowWhenBlockedByActiveItem<integer> Return true even if an active item is blocking access to this item/window. Useful for Drag and Drop patterns.
			* field AllowWhenOverlappedByItem<integer> IsItemHovered() only: Return true even if the item uses AllowOverlap mode and is overlapped by another hoverable item.
			* field AllowWhenOverlappedByWindow<integer> IsItemHovered() only: Return true even if the position is obstructed or overlapped by another window.
			* field AllowWhenDisabled<integer> IsItemHovered() only: Return true even if the item is disabled
			* field NoNavOverride<integer> IsItemHovered() only: Disable using keyboard/gamepad navigation state when active, always query mouse
			* field AllowWhenOverlapped<integer> 
			* field RectOnly<integer> 
			* field RootAndChildWindows<integer> 
			* field Stationary<integer> Require mouse to be stationary for style.HoverStationaryDelay (~0.15 sec) _at least one time_. After this, can move on same item/window. Using the stationary test tends to reduces the need for a long delay.
			* field DelayNone<integer> IsItemHovered() only: Return true immediately (default). As this is the default you generally ignore this.
			* field DelayShort<integer> IsItemHovered() only: Return true after style.HoverDelayShort elapsed (~0.15 sec) (shared between items) + requires mouse to be stationary for style.HoverStationaryDelay (once per item).
			* field DelayNormal<integer> IsItemHovered() only: Return true after style.HoverDelayNormal elapsed (~0.40 sec) (shared between items) + requires mouse to be stationary for style.HoverStationaryDelay (once per item).
			* field NoSharedDelay<integer> IsItemHovered() only: Disable shared delay system where moving from one item to the next keeps the previous timer for a short time (standard for tooltips with long delays)
			@*/
			L.new_enum("ImGuiHoveredFlags",
				"None", ImGuiHoveredFlags_None,
				"ChildWindows", ImGuiHoveredFlags_ChildWindows,
				"RootWindow", ImGuiHoveredFlags_RootWindow,
				"AnyWindow", ImGuiHoveredFlags_AnyWindow,
				"NoPopupHierarchy", ImGuiHoveredFlags_NoPopupHierarchy,
				"AllowWhenBlockedByPopup", ImGuiHoveredFlags_AllowWhenBlockedByPopup,
				"AllowWhenBlockedByActiveItem", ImGuiHoveredFlags_AllowWhenBlockedByActiveItem,
				"AllowWhenOverlappedByItem", ImGuiHoveredFlags_AllowWhenOverlappedByItem,
				"AllowWhenOverlappedByWindow", ImGuiHoveredFlags_AllowWhenOverlappedByWindow,
				"AllowWhenDisabled", ImGuiHoveredFlags_AllowWhenDisabled,
				"NoNavOverride", ImGuiHoveredFlags_NoNavOverride,
				"AllowWhenOverlapped", ImGuiHoveredFlags_AllowWhenOverlapped,
				"RectOnly", ImGuiHoveredFlags_RectOnly,
				"RootAndChildWindows", ImGuiHoveredFlags_RootAndChildWindows,
				"Stationary", ImGuiHoveredFlags_Stationary,
				"DelayNone", ImGuiHoveredFlags_DelayNone,
				"DelayShort", ImGuiHoveredFlags_DelayShort,
				"DelayNormal", ImGuiHoveredFlags_DelayNormal,
				"NoSharedDelay", ImGuiHoveredFlags_NoSharedDelay);

			/*@terminus.enum ImGuiTabBarFlags
			* field None<integer> 
			* field Reorderable<integer> Allow manually dragging tabs to re-order them + New tabs are appended at the end of list
			* field AutoSelectNewTabs<integer> Automatically select new tabs when they appear
			* field TabListPopupButton<integer> Disable buttons to open the tab list popup
			* field NoCloseWithMiddleMouseButton<integer> Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You may handle this behavior manually on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
			* field NoTabListScrollingButtons<integer> Disable scrolling buttons (apply when fitting policy is ImGuiTabBarFlags_FittingPolicyScroll)
			* field NoTooltip<integer> Disable tooltips when hovering a tab
			* field DrawSelectedOverline<integer> Draw selected overline markers over selected tab
			* field FittingPolicyMixed<integer> Shrink down tabs when they don't fit, until width is style.TabMinWidthShrink, then enable scrolling buttons.
			* field FittingPolicyShrink<integer> Shrink down tabs when they don't fit
			* field FittingPolicyScroll<integer> Enable scrolling buttons when tabs don't fit
			* field FittingPolicyMask_<integer> 
			* field FittingPolicyDefault_<integer> 
			@*/
			L.new_enum("ImGuiTabBarFlags",
				"None", ImGuiTabBarFlags_None,
				"Reorderable", ImGuiTabBarFlags_Reorderable,
				"AutoSelectNewTabs", ImGuiTabBarFlags_AutoSelectNewTabs,
				"TabListPopupButton", ImGuiTabBarFlags_TabListPopupButton,
				"NoCloseWithMiddleMouseButton", ImGuiTabBarFlags_NoCloseWithMiddleMouseButton,
				"NoTabListScrollingButtons", ImGuiTabBarFlags_NoTabListScrollingButtons,
				"NoTooltip", ImGuiTabBarFlags_NoTooltip,
				"DrawSelectedOverline", ImGuiTabBarFlags_DrawSelectedOverline,
				"FittingPolicyMixed", ImGuiTabBarFlags_FittingPolicyMixed,
				"FittingPolicyShrink", ImGuiTabBarFlags_FittingPolicyShrink,
				"FittingPolicyScroll", ImGuiTabBarFlags_FittingPolicyScroll,
				"FittingPolicyMask_", ImGuiTabBarFlags_FittingPolicyMask_,
				"FittingPolicyDefault_", ImGuiTabBarFlags_FittingPolicyDefault_);

			/*@terminus.enum ImGuiTabItemFlags
			* field None<integer> 
			* field UnsavedDocument<integer> Display a dot next to the title + set ImGuiTabItemFlags_NoAssumedClosure.
			* field SetSelected<integer> Trigger flag to programmatically make the tab selected when calling BeginTabItem()
			* field NoCloseWithMiddleMouseButton<integer> Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You may handle this behavior manually on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
			* field NoPushId<integer> Don't call PushID()/PopID() on BeginTabItem()/EndTabItem()
			* field NoTooltip<integer> Disable tooltip for the given tab
			* field NoReorder<integer> Disable reordering this tab or having another tab cross over this tab
			* field Leading<integer> Enforce the tab position to the left of the tab bar (after the tab list popup button)
			* field Trailing<integer> Enforce the tab position to the right of the tab bar (before the scrolling buttons)
			* field NoAssumedClosure<integer> Tab is selected when trying to close + closure is not immediately assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
			@*/
			L.new_enum("ImGuiTabItemFlags",
				"None", ImGuiTabItemFlags_None,
				"UnsavedDocument", ImGuiTabItemFlags_UnsavedDocument,
				"SetSelected", ImGuiTabItemFlags_SetSelected,
				"NoCloseWithMiddleMouseButton", ImGuiTabItemFlags_NoCloseWithMiddleMouseButton,
				"NoPushId", ImGuiTabItemFlags_NoPushId,
				"NoTooltip", ImGuiTabItemFlags_NoTooltip,
				"NoReorder", ImGuiTabItemFlags_NoReorder,
				"Leading", ImGuiTabItemFlags_Leading,
				"Trailing", ImGuiTabItemFlags_Trailing,
				"NoAssumedClosure", ImGuiTabItemFlags_NoAssumedClosure);

			/*@terminus.enum ImGuiTableBgTarget
			* field None<integer> 
			* field RowBg0<integer> Set row background color 0 (generally used for background, automatically set when ImGuiTableFlags_RowBg is used)
			* field RowBg1<integer> Set row background color 1 (generally used for selection marking)
			* field CellBg<integer> Set cell background color (top-most color)
			@*/
			L.new_enum("ImGuiTableBgTarget",
				"None", ImGuiTableBgTarget_None,
				"RowBg0", ImGuiTableBgTarget_RowBg0,
				"RowBg1", ImGuiTableBgTarget_RowBg1,
				"CellBg", ImGuiTableBgTarget_CellBg);

			/*@terminus.enum ImGuiTableRowFlags
			* field None<integer> 
			* field Headers<integer> Identify header row (set default background color + width of its contents accounted differently for auto column width)
			@*/
			L.new_enum("ImGuiTableRowFlags",
				"None", ImGuiTableRowFlags_None,
				"Headers", ImGuiTableRowFlags_Headers);
		}
	};

	LuaImGuiEnumsLib _LuaImGuiEnumsLib;
}
