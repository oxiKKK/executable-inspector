/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef ASSERT_H
#define ASSERT_H
#pragma once

// distinguish assert macro
#ifdef COMPILER_MSVC
# define ASSERTION_MACRO _ASSERTE
#else
# define ASSERTION_MACRO assert
#endif

#ifdef _DEBUG
// throws an assertion if x isn't true
#define ASSERT_TRUE(x, message)																						\
	{ if (!!((x) && message) == false) con::error("ASSERT_TRUE({}, {})", #x, message); ASSERTION_MACRO((x) && message); }

// throws an assertion if x isn't true
#define ASSERT_FALSE(x, message)																					\
	{ if (!!(!(x) && message) == false) con::error("ASSERT_FALSE({}, {})", #x, message); ASSERTION_MACRO(!(x) && message); }

#define ASSERT_UNREFERENCED(message)																				\
	{ con::error("accessed unreferenced code: {}", message); con::error("{}({})", __FILE__, __LINE__); ASSERTION_MACRO(!message); }

// convenience macro to check wheter something is not null
#define ASSERT_NONNULL(x)						\
	ASSERT_TRUE((x) != 0, #x " is NULL!")

#else
#define ASSERT_TRUE(x, message)
#define ASSERT_FALSE(x, message)
#define ASSERT_UNREFERENCED(message)
#define ASSERT_NONNULL(x)
#endif

#ifdef _DEBUG
#define DEBUG_CODE(code) \
	{code}
#else
#define DEBUG_CODE(code)
#endif

#define BREAK_IF(x) \
	if (x) debugger()

#endif // ASSERT_H