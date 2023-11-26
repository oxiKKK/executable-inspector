/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef GUI_H
#define GUI_H
#pragma once

class CGUI
{
public:
	CGUI(GLFWwindow* glfw_window, std::string_view glsl_version);
	~CGUI();

	CGUI() = delete;
	CGUI(const CGUI&) = delete;
	CGUI(CGUI&&) = delete;

	void render();

	forceinline bool is_successfull() const
	{
		return m_success;
	}

private:
	GLFWwindow* m_glfw_window{};

	bool m_success{};
};

#endif // GUI_H