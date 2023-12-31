/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"
#include "glfw_window.h"

CGLFWWindow::CGLFWWindow(std::string_view title, Vector2D<int32_t> resolution)
{
	m_title = title;
	m_resolution = resolution;

	if (!glfwInit())
	{
		con::error("failed to initialize GLFW");
		return;
	}

	// GL 3.0 + GLSL 130
	const std::string_view glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	m_glfw_window = glfwCreateWindow(
		m_resolution.x, m_resolution.y,
		m_title.c_str(),
		nullptr, nullptr);

	if (!m_glfw_window)
	{
		con::error("failed to create GLFW window");
		return;
	}

	// Pair context to current thread
	glfwMakeContextCurrent(m_glfw_window);

	// TODO: window icon

	// Enable vsync
	glfwSwapInterval(1);

	// create GUI sublayer
	m_gui = std::make_unique<CGUI>(m_glfw_window, glsl_version);
	if (!m_gui)
	{
		return;
	}

	con::print("created GLFW window \"{}\", {}x{}", m_title, m_resolution.x, m_resolution.y);
	m_success = true;
}

CGLFWWindow::~CGLFWWindow()
{
	glfwDestroyWindow(m_glfw_window);
	glfwTerminate();
}

bool CGLFWWindow::should_close()
{
	return glfwWindowShouldClose(m_glfw_window);
}

void CGLFWWindow::update()
{
	glfwPollEvents();

	m_gui->render();

	glfwMakeContextCurrent(m_glfw_window);
	glfwSwapBuffers(m_glfw_window);
}
