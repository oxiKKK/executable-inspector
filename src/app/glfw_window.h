/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H
#pragma once

class CGLFWWindow
{
public:
	CGLFWWindow(std::string_view title, Vector2D<int32_t> resolution);
	~CGLFWWindow();

	CGLFWWindow() = delete;
	CGLFWWindow(const CGLFWWindow&) = delete;
	CGLFWWindow(CGLFWWindow&&) = delete;

	forceinline bool is_successfull() const
	{
		return m_success;
	}

	bool should_close();

	void update();

private:
	std::string m_title{};
	Vector2D<int32_t> m_resolution{};

	GLFWwindow* m_glfw_window{};

	bool m_success{};

	std::unique_ptr<CGUI> m_gui{};
};

#endif // GLFW_WINDOW_H