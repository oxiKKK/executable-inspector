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

std::optional<std::unique_ptr<IBaseProcessor>> CProcessorManager::processor_factory(const std::filesystem::path& file)
{
	auto extension = file.extension();

	auto it = m_file_extension_to_processor_library.find(extension.string());
	if (it == m_file_extension_to_processor_library.end())
	{
		return std::nullopt;
	}

	return std::make_optional();
}

void CProcessorManager::assign_processor_fo_filenames(const std::vector<std::string_view>& filenames, std::string_view processor)
{
	for (auto& filename : filenames)
	{
		m_file_extension_to_processor_library[filename] = processor;
	}
}