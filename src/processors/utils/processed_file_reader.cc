/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"

ProcessedFileReader::ProcessedFileReader(const std::filesystem::path& filepath) :
	m_input_filepath(filepath)
{
	con::print("ProcessedFileReader: trying to read input file: \"{}\"", m_input_filepath);

	if (!std::filesystem::exists(m_input_filepath))
	{
		con::error("ProcessedFileReader: input file does not exist");
		return;
	}

	auto perms = std::filesystem::status(m_input_filepath).permissions();

	// check if we have read permissions
	if ((perms & std::filesystem::perms::owner_read) == std::filesystem::perms::none)
	{
		con::error("ProcessedFileReader: insufficient amount of permissions to read from the file. (perms={})", static_cast<size_t>(perms));
		return;
	}

	m_success = true;
}

ProcessedFileReader::~ProcessedFileReader()
{
}

