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

private:
	bool on_frame();

private:
	std::unique_ptr<CGLFWWindow> m_window;

	inline static constexpr int32_t k_frametime_ms = 1 / 60; // 60 fps
};

extern CApplication g_app;

#endif // APPLICATION_H