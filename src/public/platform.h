/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) oxiKKK 2022-present
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PLATFORM_H
#define PLATFORM_H
#pragma once

// platform-specific includes
#ifdef COMPILER_MSVC
#define NOMINMAX
# include <Windows.h>
#else
# include <cstdint>
# include <dlfcn.h>
# include <unistd.h>
#endif

// fmt library
#include <fmt/color.h>
#include <fmt/format.h>
#include <fmt/chrono.h>

// stricmp
// on linux this function doesn't exist.
#ifndef COMPILER_MSVC
# define stricmp strcasecmp
#endif

#ifdef COMPILER_MSVC
# define forceinline __forceinline inline
#else
# define forceinline __attribute__((always_inline)) inline
#endif

#ifdef COMPILER_MSVC
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#else
#define EXPORT 
#define IMPORT 
#endif

// decl singleton for a class instance
#define DECL_SINGLETON(name)			\
	static forceinline name& the()		\
	{									\
		static name g_##name;			\
		return g_##name;				\
	}

#include <chrono>
using namespace std::chrono_literals;

// our assert header
#include "assert.h"

#include "custom_format.h"

#endif // PLATFORM_H