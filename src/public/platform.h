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

#include <chrono>
using namespace std::chrono_literals;

#endif // PLATFORM_H