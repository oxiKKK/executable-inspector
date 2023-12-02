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

// result from file processing
class ProcessResult
{
public:
	ProcessResult(IFileProcessor* processor);

	IFileProcessor* m_processor{ nullptr };
};

#endif // PROCESS_RESULT_H