/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PROCESSED_FILE_READER_H
#define PROCESSED_FILE_READER_H
#pragma once

#include <filesystem>

class ProcessedFileReader
{
public:
	ProcessedFileReader(const std::filesystem::path& filepath);
	~ProcessedFileReader();

	ProcessedFileReader() = default;
	ProcessedFileReader(const ProcessedFileReader&) = default;
	ProcessedFileReader(ProcessedFileReader&&) = default;

	forceinline bool successfull()
	{
		return m_success;
	}

	forceinline auto filesize()
	{
		return m_filesize;
	}

private:
	bool m_success{ false };
	uintmax_t m_filesize{};

	std::filesystem::path m_input_filepath{};
};

#endif // PROCESSED_FILE_READER_H