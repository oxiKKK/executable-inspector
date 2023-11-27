/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"
#include "elf_processor.h"

CElfProcessor g_processor;

__attribute__((visibility("default"))) void* get_processor_factory()
{
	return reinterpret_cast<void*>(&g_processor);
}

bool CElfProcessor::process_file(const std::filesystem::path& filepath)
{
	return false;
}

void CElfProcessor::render_gui()
{
}
