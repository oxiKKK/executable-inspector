set(SOURCES
	elf_processor.cc
)

# Create the target.
add_library(gui SHARED ${SOURCES})

# include directories
target_include_directories(gui PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)

# needed static libs
target_link_libraries(gui PRIVATE
	${OPENGL_LIBRARIES}
	glfw
	imgui
	soil
)

target_precompile_headers(gui PRIVATE
	precompiled.h
)