#pragma once
#include <string>
#include <imgui_internal.h>

// https://github.com/ocornut/imgui/issues/902#issuecomment-1103072284
namespace ImGui
{
	static const ImVec4 &white = {1, 1, 1, 1}, blue = {0.000f, 0.703f, 0.917f, 1}, red = {0.976f, 0.117f, 0.265f, 1}, grey = {0.230f, 0.226f, 0.289f, 1}, lgrey = {0.630f, 0.626f, 0.689f, 1}, green = {0.000f, 0.386f, 0.265f, 1}, lime = {0.55f, 0.90f, 0.06f, 1}, yellow = {0.91f, 1.00f, 0.21f, 1}, purple = {1, 0, 1, 1}, orange = {1.00f, 0.36f, 0.09f, 1};

	using str = std::string;
	template<typename T>
	using list   = std::vector<T>;
	namespace im = ImGui;
	void ColorfulText(const std::string& text, const list<std::pair<char, ImVec4>>& colors = {})
	{
		auto p              = im::GetCursorScreenPos();
		const auto first_px = p.x, first_py = p.y;
		auto im_colors           = ImGui::GetStyle().Colors;
		const auto default_color = im_colors[ImGuiCol_Text];
		str temp_str;
		struct text_t
		{
			ImVec4 color;
			str text;
		};
		list<text_t> texts;
		bool color_time   = false;
		ImVec4 last_color = default_color;
		for (const auto& i : text)
		{
			if (color_time)
			{
				const auto& f = std::find_if(colors.begin(), colors.end(), [i](const auto& v) {
					return v.first == i;
				});
				if (f != colors.end())
					last_color = f->second;
				else
					temp_str += i;
				color_time = false;
				continue;
			};
			switch (i)
			{
			case '$':
				color_time = true;
				if (!temp_str.empty())
				{
					texts.push_back({last_color, temp_str});
					temp_str.clear();
				};
				break;
			default: temp_str += i;
			};
		};
		if (!temp_str.empty())
		{
			texts.push_back({last_color, temp_str});
			temp_str.clear();
		};
		float max_x = p.x;
		for (const auto& i : texts)
		{
			im_colors[ImGuiCol_Text] = i.color;
			list<str> lines;
			temp_str.clear();
			for (const auto& lc : i.text)
			{
				if (lc == '\n')
				{
					lines.push_back(temp_str += lc);
					temp_str.clear();
				}
				else
					temp_str += lc;
			};
			bool last_is_line = false;
			if (!temp_str.empty())
				lines.push_back(temp_str);
			else
				last_is_line = true;
			float last_px = 0.f;
			for (const auto& j : lines)
			{
				RenderText(p, j.c_str());
				p.y += GetFont()->FontSize + 5.0f;
				last_px = p.x;
				max_x   = (max_x < last_px) ? last_px : max_x;
				p.x     = first_px;
			};
			const auto& last = lines.back();
			if (last.back() != '\n')
				p.x = last_px;
			else
				p.x = first_px;
			if (!last_is_line)
				p.y -= GetFont()->FontSize + 5.0f;
			if (i.text.back() != '\n')
				p.x += CalcTextSize(last.c_str()).x;
		};
		im_colors[ImGuiCol_Text] = default_color;
		Dummy({max_x - p.x, p.y - first_py});
	};
}