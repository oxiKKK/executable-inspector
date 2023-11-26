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

CGUI::CGUI(GLFWwindow* glfw_window, std::string_view glsl_version)
{
	m_glfw_window = glfw_window;

	//
	// initialize imgui
	//

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking Branch Features

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(m_glfw_window, true);
	ImGui_ImplOpenGL3_Init(glsl_version.data());

	con::print("initialized GUI");

	m_success = true;
}

CGUI::~CGUI()
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(m_glfw_window);
	glfwTerminate();

	m_glfw_window = nullptr;
}

void CGUI::render()
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	//ImGui::ShowDemoWindow();

	render_imgui();

	// Rendering
	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(m_glfw_window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CGUI::render_imgui()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Options"))
		{
			if (ImGui::MenuItem("Open")) {}
			if (ImGui::MenuItem("Recent")) {}
			if (ImGui::MenuItem("Close")) {}

			ImGui::Separator();

			if (ImGui::MenuItem("Exit")) {}

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			if (ImGui::MenuItem("About")) {}

			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

	ImGui::Begin("Stuff");
	{
		ImGui::End();
	}
}

