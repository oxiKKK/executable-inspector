# detect wherever we're 64 bits or 32 bits
#
# https://stackoverflow.com/questions/39258250/how-to-detect-if-64-bit-msvc-with-cmake
#

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	add_compile_definitions(PLAT_64BIT)
else()
	add_compile_definitions(PLAT_32BIT)
endif()
