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

	forceinline bool successful()
	{
		return m_success;
	}

	forceinline auto filesize()
	{
		return m_input_filesize;
	}

	// delegate api to byte buffer
	forceinline auto raw() const { return m_file_buffer.get_raw(); }
	template<class T>
	forceinline auto at(uintptr_t off) const { return m_file_buffer.get_at<T>(off); }

private:
	bool m_success{ false };

	uintmax_t m_input_filesize{};
	std::filesystem::path m_input_filepath{};

	ByteBuffer<uintptr_t> m_file_buffer{};
};

#endif // PROCESSED_FILE_READER_H