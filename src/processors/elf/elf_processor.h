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
	virtual bool process_file(const std::filesystem::path& filepath);

	virtual void render_gui();
};

extern CElfProcessor g_processor;

#endif // ELF_PROCESSOR_H