/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PROCESSOR_MANAGER_H
#define PROCESSOR_MANAGER_H
#pragma once

// exported fn
#define GET_PROCESSOR_FACTORY_EXPORT "get_processor_factory"
typedef void* (*pfn_get_processor_factory)();

class CProcessorManager : public IProcessorManager
{
public:
	virtual bool initialize();

	virtual bool process_file(const std::filesystem::path& file);

	virtual void render_processors();

private:
	IFileProcessor* processor_factory(const std::filesystem::path& file);

	// gets the processor library name that needs to be loaded in memory
	std::string determine_processor_library_filename_by_file(const std::filesystem::path& file);

	void assign_processor_fo_filenames(const std::vector<std::string>& extensions, const std::string& processor);

private:
	std::unordered_map<std::string, std::string> m_file_extension_to_processor_library;

	std::unordered_map<std::filesystem::path, IFileProcessor*> m_processors{};
};

#endif // PROCESSOR_MANAGER_H