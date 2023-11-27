/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) oxiKKK 2022-present
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef LIBRARY_LOADER_INTERFACE_H
#define LIBRARY_LOADER_INTERFACE_H
#pragma once

class ILibraryLoader
{
public:
	virtual uintptr_t load_library(const std::filesystem::path& library) = 0;
	virtual uintptr_t locate_export(const std::filesystem::path& library, const std::string& fn) = 0;
};

#endif // LIBRARY_LOADER_INTERFACE_H