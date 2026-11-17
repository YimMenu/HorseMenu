#pragma once

#include <sol/sol.hpp>


namespace Terminus::LuaJIT
{
	class LuaImDrawList final
	{
	public:
		LuaImDrawList(ImDrawList* ptr);

		void AddText(const ImVec2& pos, int col, const std::string& text);
		void AddText1(float fontSize, const ImVec2& pos, int col, const std::string& text, sol::optional<float> wrapWidth);

		void AddLine(const ImVec2& p1, const ImVec2& p2, int col, sol::optional<float> thickness);
		void AddPolyline(sol::table points, int numPoints, int col, int flags, float thickness);

		void AddRect(const ImVec2& pMin, const ImVec2& pMax, int col, sol::optional<float> rounding);
		void AddRect1(const ImVec2& pMin, const ImVec2& pMax, int col, float rounding, sol::optional<int> flags);
		void AddRect2(const ImVec2& pMin, const ImVec2& pMax, int col, float rounding, int flags, sol::optional<float> thickness);

		void AddRectFilled(const ImVec2& pMin, const ImVec2& pMax, int col, sol::optional<float> rounding);
		void AddRectFilled1(const ImVec2& pMin, const ImVec2& pMax, int col, float rounding, sol::optional<int> flags);
		void AddRectFilledMultiColor(const ImVec2& pMin, const ImVec2& pMax, int colUpL, int colUpR, int colBotR, int colBotL);

		void AddCircle(const ImVec2& center, float radius, int col, sol::optional<int> numSegments);
		void AddCircle1(const ImVec2& center, float radius, int col, int numSegments, sol::optional<float> thickness);
		void AddCircleFilled(const ImVec2& center, float radius, int col, sol::optional<int> numSegments);

		void AddNgon(const ImVec2& center, float radius, int col, int numSegments, sol::optional<float> thickness);
		void AddNgonFilled(const ImVec2& center, float radius, int col, int numSegments);

		void AddBezierCubic(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col, float thickness, sol::optional<int> numSegments);
		void AddBezierQuadratic(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col, float thickness, sol::optional<int> numSegments);

		void AddQuad(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col, sol::optional<float> thickness);
		void AddQuadFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col);

		void AddTriangle(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col, sol::optional<float> thickness);
		void AddTriangleFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col);

		void PathClear();
		void PathStroke(int col, sol::optional<int> flags);
		void PathStroke1(int col, int flags, sol::optional<float> thickness);
		void PathLineTo(const ImVec2& pos);
		void PathArcTo(const ImVec2& center, float radius, float aMin, float aMax, sol::optional<int> numSegments);
		void PathArcToFast(const ImVec2& center, float radius, int aMinOf12, int aMaxOf12);
		void PathRect(const ImVec2& min, const ImVec2& max, sol::optional<float> rounding);
		void PathRect1(const ImVec2& min, const ImVec2& max, float rounding, sol::optional<int> flags);
		void PathFillConcave(int col);
		void PathFillConvex(int col);
		void PathBezierCubicCurveTo(const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, sol::optional<int> numSegments);
		void PathBezierQuadraticCurveTo(const ImVec2& p2, const ImVec2& p3, sol::optional<int> numSegments);
		void PathEllipticalArcTo(const ImVec2& center, const ImVec2& radius, float rot, float aMin, float aMax, sol::optional<int> numSegments);

		void PushClipRect(const ImVec2& min, const ImVec2 max, sol::optional<bool> intersectWithCurrentClipRect);
		void PopClipRect();

	private:
		void Assert();

		ImDrawList* m_Ptr;
	};
}
