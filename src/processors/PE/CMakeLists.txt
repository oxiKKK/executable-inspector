set(SOURCES
	PE_processor.cc
	dos_header.cc
)

# Create the target.
add_library(peprocessor SHARED ${SOURCES})

# include directories
target_include_directories(peprocessor PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)

# needed static libs
target_link_libraries(peprocessor PRIVATE
	${OPENGL_LIBRARIES}
	glfw
	imgui
	soil
	processor-utils
)

target_precompile_headers(peprocessor PRIVATE
	precompiled.h
)