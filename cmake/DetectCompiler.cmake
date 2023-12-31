# detect which compiler we're using
#
# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html#variable:CMAKE_%3CLANG%3E_COMPILER_ID
#

message("CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

if (MSVC)
	set(IS_MSVC ON)
	add_compile_definitions(COMPILER_MSVC)
	add_compile_definitions(PLAT_WIN)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(IS_GCC ON)
	add_compile_definitions(COMPILER_GCC)
	add_compile_definitions(PLAT_LINUX)
else()
	message(FATAL_ERROR "Invalid compiler detected. You have to use either GCC or MSVC.")
endif()
