/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PE_PROCESSOR_H
#define PE_PROCESSOR_H
#pragma once

#include "win32/minwindef.h"

#include "collected_data.h"

class CPEProcessor : public IFileProcessor
{
public:
	virtual const char* processor_name() { return "PE processor"; }

	virtual bool process_file(const std::filesystem::path& filepath, EProcessOptions options = PROCESS_NONE);

	virtual void render_gui();

private:
	bool process_dos_hdr();

private:
	std::unique_ptr<ProcessedFileReader> m_reader{};
};

extern CPEProcessor g_processor;

#endif // PE_PROCESSOR_H