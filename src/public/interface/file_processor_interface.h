/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef FILE_PROCESSOR_INTERFACE_H
#define FILE_PROCESSOR_INTERFACE_H
#pragma once

#include <filesystem>

class IFileProcessor
{
public:
	~IFileProcessor() {}

	virtual bool process_file(const std::filesystem::path& filepath) = 0;

	virtual void render_gui() = 0;
};

#endif // FILE_PROCESSOR_INTERFACE_H