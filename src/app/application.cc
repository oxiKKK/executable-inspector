/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"

CApplication g_app{};

int32_t CApplication::run()
{
	// create processor manager
	m_processor_manager = std::make_unique<CProcessorManager>();
	if (!m_processor_manager)
	{
		return 1;
	}

	if (!m_processor_manager->initialize())
	{
		return 1;
	}

	// create library loader
#ifdef PLATFORM_WIN
	m_library_loader = std::make_unique<CLibraryLoaderWin32>();
#else
	m_library_loader = std::make_unique<CLibraryLoaderLinux>();
#endif
	if (!m_library_loader)
	{
		return 1;
	}

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