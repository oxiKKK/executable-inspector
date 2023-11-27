/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

class CApplication
{
public:
	int32_t run();

	// getters
	forceinline auto library_loader() { return m_library_loader.get(); }

private:
	bool on_frame();

private:
	std::unique_ptr<CGLFWWindow> m_window{};
	std::unique_ptr<IProcessorManager> m_processor_manager{};
	std::unique_ptr<ILibraryLoader> m_library_loader{};

	inline static constexpr int32_t k_frametime_ms = 1 / 60; // 60 fps
};

extern CApplication g_app;

#endif // APPLICATION_H