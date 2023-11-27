/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"

uintptr_t CLibraryLoaderLinux::load_library(const std::filesystem::path& library)
{
	void* handle = dlopen(library.string().c_str(), RTLD_NOW | RTLD_LOCAL);
	if (!handle)
	{
		con::error("could not open library \"{}\" ({})", library.string(), dlerror());
		return 0;
	}

	return reinterpret_cast<uintptr_t>(handle);
}

uintptr_t CLibraryLoaderLinux::locate_export(const std::filesystem::path& library, const std::string& fn)
{
	void* handle = dlopen(library.string().c_str(), RTLD_NOW | RTLD_LOCAL);
	if (!handle)
	{
		con::error("could not open library \"{}\" ({})", library.string(), dlerror());
		return 0;
	}

	void* symbol = dlsym(handle, fn.c_str());
	if (!symbol)
	{
		con::error("could not locate symbol \"{}\" in library \"{}\" ({})", fn, library.string(), dlerror());
		return 0;
	}

	return reinterpret_cast<uintptr_t>(symbol);
}
