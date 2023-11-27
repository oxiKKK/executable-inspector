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

# needed static libs
target_link_libraries(elfprocessor PRIVATE
	${OPENGL_LIBRARIES}
	glfw
	imgui
	soil
)

target_precompile_headers(elfprocessor PRIVATE
	precompiled.h
)