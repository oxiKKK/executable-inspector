/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PROCESSOR_MANAGER_INTERFACE_H
#define PROCESSOR_MANAGER_INTERFACE_H
#pragma once

#include "file_processor_interface.h"

class IProcessorManager
{
public:
	virtual bool initialize() = 0;

	virtual bool process_file(const std::filesystem::path& file) = 0;

	virtual void render_processors() = 0;
};

#endif // PROCESSOR_MANAGER_INTERFACE_H