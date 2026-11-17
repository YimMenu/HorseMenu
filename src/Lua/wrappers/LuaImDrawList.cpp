#include "LuaImDrawList.hpp"


namespace Terminus::LuaJIT
{

	LuaImDrawList::LuaImDrawList(ImDrawList* ptr) :
		m_Ptr(ptr)
	{
	}

	void LuaImDrawList::Assert()
	{
		if (!m_Ptr)
			throw sol::error("Attempt to index a null ImDrawlist object");
	}

	void LuaImDrawList::AddText(const ImVec2& pos, int col, const std::string& text)
	{
		Assert();
		m_Ptr->AddText(pos, static_cast<ImU32>(col), text.c_str());
	}

	void LuaImDrawList::AddText1(float fontSize, const ImVec2& pos, int col, const std::string& text, sol::optional<float> wrapWidth)
	{
		Assert();
		m_Ptr->AddText(ImGui::GetFont(), fontSize, pos, static_cast<ImU32>(col), text.c_str(), nullptr, wrapWidth.value_or(0.0f));
	}

	void LuaImDrawList::AddLine(const ImVec2& p1, const ImVec2& p2, int col, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->AddLine(p1, p2, static_cast<ImU32>(col), thickness.value_or(1.0f));
	}

	void LuaImDrawList::AddPolyline(sol::table points, int numPoints, int col, int flags, float thickness)
	{
		Assert();

		std::vector<ImVec2> pts;
		for (auto&& [i, v] : points)
		{
			if (!v.is<ImVec2>())
				throw sol::error("Invalid argument #1. Function AddPolyline expects a contiguous array of Vector2 objects.");

			pts.push_back(v.as<ImVec2>());
		}
		m_Ptr->AddPolyline(pts.data(), static_cast<int>(pts.size()), static_cast<ImU32>(col), static_cast<ImDrawFlags>(flags), thickness);
	}

	void LuaImDrawList::AddRect(const ImVec2& pMin, const ImVec2& pMax, int col, sol::optional<float> rounding)
	{
		Assert();
		m_Ptr->AddRect(pMin, pMax, static_cast<ImU32>(col), rounding.value_or(0.0f));
	}

	void LuaImDrawList::AddRect1(const ImVec2& pMin, const ImVec2& pMax, int col, float rounding, sol::optional<int> flags)
	{
		Assert();
		m_Ptr->AddRect(pMin, pMax, static_cast<ImU32>(col), rounding, static_cast<ImDrawFlags>(flags.value_or(0)));
	}

	void LuaImDrawList::AddRect2(const ImVec2& pMin, const ImVec2& pMax, int col, float rounding, int flags, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->AddRect(pMin, pMax, static_cast<ImU32>(col), rounding, flags, thickness.value_or(1.0f));
	}

	void LuaImDrawList::AddRectFilled(const ImVec2& pMin, const ImVec2& pMax, int col, sol::optional<float> rounding)
	{
		Assert();
		m_Ptr->AddRectFilled(pMin, pMax, static_cast<ImU32>(col), rounding.value_or(0.0f));
	}

	void LuaImDrawList::AddRectFilled1(const ImVec2& pMin, const ImVec2& pMax, int col, float rounding, sol::optional<int> flags)
	{
		Assert();
		m_Ptr->AddRectFilled(pMin, pMax, static_cast<ImU32>(col), rounding, flags.value_or(0));
	}

	void LuaImDrawList::AddRectFilledMultiColor(const ImVec2& pMin, const ImVec2& pMax, int colUpL, int colUpR, int colBotR, int colBotL)
	{
		Assert();
		m_Ptr->AddRectFilledMultiColor(pMin, pMax, colUpL, colUpR, colBotR, colBotL);
	}

	void LuaImDrawList::AddCircle(const ImVec2& center, float radius, int col, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->AddCircle(center, radius, static_cast<ImU32>(col), numSegments.value_or(0));
	}

	void LuaImDrawList::AddCircle1(const ImVec2& center, float radius, int col, int numSegments, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->AddCircle(center, radius, static_cast<ImU32>(col), numSegments, thickness.value_or(1.0f));
	}

	void LuaImDrawList::AddCircleFilled(const ImVec2& center, float radius, int col, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->AddCircleFilled(center, radius, static_cast<ImU32>(col), numSegments.value_or(0));
	}

	void LuaImDrawList::AddNgon(const ImVec2& center, float radius, int col, int numSegments, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->AddNgon(center, radius, static_cast<ImU32>(col), numSegments, thickness.value_or(1.0f));
	}

	void LuaImDrawList::AddNgonFilled(const ImVec2& center, float radius, int col, int numSegments)
	{
		Assert();
		m_Ptr->AddNgonFilled(center, radius, static_cast<ImU32>(col), numSegments);
	}

	void LuaImDrawList::AddBezierCubic(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col, float thickness, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->AddBezierCubic(p1, p2, p3, p4, static_cast<ImU32>(col), thickness, numSegments.value_or(0));
	}

	void LuaImDrawList::AddBezierQuadratic(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col, float thickness, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->AddBezierQuadratic(p1, p2, p3, static_cast<ImU32>(col), thickness, numSegments.value_or(0));
	}

	void LuaImDrawList::AddQuad(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->AddQuad(p1, p2, p3, p4, static_cast<ImU32>(col), thickness.value_or(1.0f));
	}

	void LuaImDrawList::AddQuadFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col)
	{
		Assert();
		m_Ptr->AddQuadFilled(p1, p2, p3, p4, static_cast<ImU32>(col));
	}

	void LuaImDrawList::AddTriangle(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->AddTriangle(p1, p2, p3, static_cast<ImU32>(col), thickness.value_or(1.0f));
	}

	void LuaImDrawList::AddTriangleFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col)
	{
		Assert();
		m_Ptr->AddTriangleFilled(p1, p2, p3, static_cast<ImU32>(col));
	}

	void LuaImDrawList::PathClear()
	{
		Assert();
		m_Ptr->PathClear();
	}

	void LuaImDrawList::PathStroke(int col, sol::optional<int> flags)
	{
		Assert();
		m_Ptr->PathStroke(static_cast<ImU32>(col), static_cast<ImDrawFlags>(flags.value_or(0)));
	}

	void LuaImDrawList::PathStroke1(int col, int flags, sol::optional<float> thickness)
	{
		Assert();
		m_Ptr->PathStroke(static_cast<ImU32>(col), static_cast<ImDrawFlags>(flags), thickness.value_or(1.0f));
	}

	void LuaImDrawList::PathLineTo(const ImVec2& pos)
	{
		Assert();
		m_Ptr->PathLineTo(pos);
	}

	void LuaImDrawList::PathArcTo(const ImVec2& center, float radius, float aMin, float aMax, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->PathArcTo(center, radius, aMin, aMax, numSegments.value_or(0));
	}

	void LuaImDrawList::PathArcToFast(const ImVec2& center, float radius, int aMinOf12, int aMaxOf12)
	{
		Assert();
		m_Ptr->PathArcToFast(center, radius, aMinOf12, aMaxOf12);
	}

	void LuaImDrawList::PathRect(const ImVec2& min, const ImVec2& max, sol::optional<float> rounding)
	{
		Assert();
		m_Ptr->PathRect(min, max, rounding.value_or(0.0f));
	}

	void LuaImDrawList::PathRect1(const ImVec2& min, const ImVec2& max, float rounding, sol::optional<int> flags)
	{
		Assert();
		m_Ptr->PathRect(min, max, rounding, static_cast<ImDrawFlags>(flags.value_or(0)));
	}

	void LuaImDrawList::PathFillConcave(int col)
	{
		Assert();
		m_Ptr->PathFillConcave(static_cast<ImU32>(col));
	}

	void LuaImDrawList::PathFillConvex(int col)
	{
		Assert();
		m_Ptr->PathFillConvex(static_cast<ImU32>(col));
	}

	void LuaImDrawList::PathBezierCubicCurveTo(const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->PathBezierCubicCurveTo(p2, p3, p4, numSegments.value_or(0));
	}

	void LuaImDrawList::PathBezierQuadraticCurveTo(const ImVec2& p2, const ImVec2& p3, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->PathBezierQuadraticCurveTo(p2, p3, numSegments.value_or(0));
	}

	void LuaImDrawList::PathEllipticalArcTo(const ImVec2& center, const ImVec2& radius, float rot, float aMin, float aMax, sol::optional<int> numSegments)
	{
		Assert();
		m_Ptr->PathEllipticalArcTo(center, radius, rot, aMin, aMax, numSegments.value_or(0));
	}

	void LuaImDrawList::PushClipRect(const ImVec2& min, const ImVec2 max, sol::optional<bool> intersectWithCurrentClipRect)
	{
		Assert();
		m_Ptr->PushClipRect(min, max, intersectWithCurrentClipRect.value_or(false));
	}

	void LuaImDrawList::PopClipRect()
	{
		Assert();
		m_Ptr->PopClipRect();
	}
}
