/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef ELF_PROCESSOR_H
#define ELF_PROCESSOR_H
#pragma once

class CElfProcessor : public IFileProcessor
{
public:
	virtual const char* processor_name() { return "elf processor"; }

	virtual bool process_file(const std::filesystem::path& filepath, EProcessOptions options = PROCESS_NONE);

	virtual void render_gui();
};

extern CElfProcessor g_processor;

#endif // ELF_PROCESSOR_H