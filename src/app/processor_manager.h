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

	virtual IFileProcessor* processor_factory(const std::filesystem::path& file);

private:
	void assign_processor_fo_filenames(const std::vector<std::string_view>& filenames, std::string_view processor);

private:
	std::unordered_map<std::string_view, std::string_view> m_file_extension_to_processor_library;
};

#endif // PROCESSOR_MANAGER_H