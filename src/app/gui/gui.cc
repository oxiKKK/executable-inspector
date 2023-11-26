/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"
#include "gui.h"

CGUI::CGUI(GLFWwindow* glfw_window)
{
	m_glfw_window = glfw_window;

	m_success = true;
}

CGUI::~CGUI()
{
	m_glfw_window = nullptr;
}

void CGUI::render()
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

