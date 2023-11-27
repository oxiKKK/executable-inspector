set(SOURCES
	elf_processor.cc
)

# Create the target.
add_library(elfprocessor SHARED ${SOURCES})

# include directories
target_include_directories(elfprocessor PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_precompile_headers(elfprocessor PRIVATE
	precompiled.h
)