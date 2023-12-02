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
	assign_processor_fo_filenames({ "dll", "exe" }, "peprocessor");
	assign_processor_fo_filenames({ "so" }, "elfprocessor");

	return true;
}

bool CProcessorManager::process_file(const std::filesystem::path& file)
{
	auto factory = processor_factory(file);
	if (!factory)
	{
		return false;
	}

	auto [it, success] = m_processors.insert({ file, factory });
	if (!success)
	{
		con::error("could not create new processor for file {}", file);
		return false;
	}

	bool processed_successfully = it->second->process_file(file);
	return processed_successfully;
}

void CProcessorManager::render_processors()
{
	for (auto& [path, file_processor] : m_processors)
	{
		file_processor->render_gui();
	}
}

IFileProcessor* CProcessorManager::processor_factory(const std::filesystem::path& file)
{
	if (!std::filesystem::exists(file))
	{
		con::error("input file {} does not exist.", file);
		return nullptr;
	}

	std::string processor_lib = determine_processor_library_filename_by_file(file);
	if (processor_lib.empty())
	{
		con::error("unsupported file type for file {}.", file);
		return nullptr;
	}

	std::filesystem::path full_library_path = processor_lib;
#ifdef PLATFORM_WIN
	full_library_path.replace_extension(".dll");
#else
	full_library_path = "./" + full_library_path.string();
	full_library_path.replace_extension(".so");
#endif

	// first load the appropriate library
	uintptr_t library_base = g_app.library_loader()->load_library(full_library_path);
	if (!library_base)
	{
		return nullptr;
	}

	// now, locate the export
	uintptr_t export_ptr = g_app.library_loader()->locate_export((void*)library_base, GET_PROCESSOR_FACTORY_EXPORT);
	if (!export_ptr)
	{
		return nullptr;
	}

	// cast into function and call it
	pfn_get_processor_factory factory = reinterpret_cast<pfn_get_processor_factory>(export_ptr);
	void* result = factory();

	return reinterpret_cast<IFileProcessor*>(result);
}

std::string CProcessorManager::determine_processor_library_filename_by_file(const std::filesystem::path& file)
{
	if (!file.has_extension())
	{
		con::error("couldn't decide on file type because the file {} has no extension.", file);
		// TODO: this should be fixed in the future
		return "";
	}

	auto extension = file.extension();

	auto it = m_file_extension_to_processor_library.find(extension.string());
	if (it == m_file_extension_to_processor_library.end())
	{
		return "";
	}

	return it->second;
}

void CProcessorManager::assign_processor_fo_filenames(const std::vector<std::string>& extensions, const std::string& processor)
{
	for (auto& ext : extensions)
	{
		std::string processor_library_name = processor;
#ifdef PLATFORM_LINUX
		// on linux, our dynamic libraries are prefixed with "lib"
		processor_library_name = "lib" + processor_library_name;
#endif
		m_file_extension_to_processor_library["." + ext] = processor_library_name;
	}
}