/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PROCESSOR_INTERFACE_H
#define PROCESSOR_INTERFACE_H
#pragma once

#include <filesystem>

class IProcessorGUI
{
public:
	~IProcessorGUI() {}

	virtual void render_gui() = 0;
};

class IFileProcessor
{
public:
	~IFileProcessor() {}

	virtual bool process_file(const std::filesystem::path& filepath);
};

#endif // PROCESSOR_INTERFACE_H