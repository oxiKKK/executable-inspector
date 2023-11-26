/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"
#include "application.h"

CApplication g_app{};

int32_t CApplication::run()
{
	// create GLFW window
	m_window = std::make_unique<CGLFWWindow>("Executable Inspector", Vector2D<int32_t>(1280, 720));
	if (!m_window || !m_window->is_successfull())
	{
		return 1;
	}

	while (on_frame())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(k_frametime_ms));
	}

	return 0;
}

bool CApplication::on_frame()
{
	// User has requested a window close or the window just
	// has to be closed now.
	if (m_window->should_close())
	{
		return false;
	}

	m_window->update();

	return true;
}