/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PROCESS_RESULT_H
#define PROCESS_RESULT_H
#pragma once

#include <chrono>

// result from file processing
class ProcessResult
{
public:
	ProcessResult(IFileProcessor* processor);

	IFileProcessor* m_processor{ nullptr };

	// high-perf timings
	std::chrono::duration<float, std::ratio<1, 1>> m_processing_time;
};

#endif // PROCESS_RESULT_H