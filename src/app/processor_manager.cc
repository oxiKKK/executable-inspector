/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"
#include "processor_manager.h"

bool CProcessorManager::initialize()
{
	//
	// create mappings
	//
	assign_processor_fo_filenames({ "dll", "exe" }, "libpeprocessor");

	return false;
}

IFileProcessor* CProcessorManager::processor_factory(const std::filesystem::path& file)
{
	auto extension = file.extension();

	auto it = m_file_extension_to_processor_library.find(extension.string());
	if (it == m_file_extension_to_processor_library.end())
	{
		return nullptr;
	}

	// first load the appropriate library
	uintptr_t library_base = g_app.library_loader()->load_library(it->second.data());
	if (!library_base)
	{
		return nullptr;
	}

	// now, locate the export
	uintptr_t export_ptr = g_app.library_loader()->locate_export(it->second.data(), GET_PROCESSOR_FACTORY_EXPORT);
	if (!export_ptr)
	{
		return nullptr;
	}

	// cast into function and call it
	pfn_get_processor_factory factory = reinterpret_cast<pfn_get_processor_factory>(export_ptr);
	void* result = factory();

	return reinterpret_cast<IFileProcessor*>(result);
}

void CProcessorManager::assign_processor_fo_filenames(const std::vector<std::string_view>& filenames, std::string_view processor)
{
	for (auto& filename : filenames)
	{
		m_file_extension_to_processor_library[filename] = processor;
	}
}