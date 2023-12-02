set(SOURCES
	utils.cc
	processed_file_reader.cc
)

# Create the target.
add_library(processor-utils STATIC ${SOURCES})

# include directories
target_include_directories(processor-utils PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_precompile_headers(processor-utils PRIVATE
	precompiled.h
)