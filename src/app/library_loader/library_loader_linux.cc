/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"

uintptr_t CLibraryLoaderLinux::load_library(const std::string& name)
{
	void* handle = dlopen(name.c_str(), RTLD_NOW | RTLD_LOCAL);
	if (!handle)
	{
		con::error("could not open library \"{}\" ({})", name, dlerror());
		return 0;
	}

	return reinterpret_cast<uintptr_t>(handle);
}

uintptr_t CLibraryLoaderLinux::locate_export(const std::string& library, const std::string& fn)
{
	void* handle = dlopen(library.c_str(), RTLD_NOW | RTLD_LOCAL);
	if (!handle)
	{
		con::error("could not open library \"{}\" ({})", library, dlerror());
		return 0;
	}

	void* symbol = dlsym(handle, fn.c_str());
	if (!symbol)
	{
		con::error("could not locate symbol \"{}\" in library \"{}\" ({})", fn, library, dlerror());
		return 0;
	}

	return reinterpret_cast<uintptr_t>(symbol);
}
