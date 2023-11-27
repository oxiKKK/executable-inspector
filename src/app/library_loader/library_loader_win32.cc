/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"

class CLibraryLoaderWin32 : ILibraryLoader
{
public:
	uintptr_t load_library(const std::string& name);
	uintptr_t locate_export(const std::string& library, const std::string& fn);
};

// TODO: implement

uintptr_t CLibraryLoaderWin32::load_library(const std::string& name)
{
	return uintptr_t();
}

uintptr_t CLibraryLoaderWin32::locate_export(const std::string& library, const std::string& fn)
{
	return uintptr_t();
}
