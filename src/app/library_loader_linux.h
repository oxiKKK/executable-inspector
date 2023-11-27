/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef LIBRARY_LOADER_LINUX_H
#define LIBRARY_LOADER_LINUX_H
#pragma once

class CLibraryLoaderLinux : ILibraryLoader
{
public:
	uintptr_t load_library(const std::string& name);
	uintptr_t locate_export(const std::string& library, const std::string& fn);
};

#endif // LIBRARY_LOADER_LINUX_H