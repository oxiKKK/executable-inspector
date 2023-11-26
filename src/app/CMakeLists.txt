set(SOURCES
)

# Create the target.
add_executable(executable-inspector ${SOURCES})

# include directories
target_include_directories(executable-inspector PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)

# needed static libs
target_link_libraries(executable-inspector PRIVATE
	imgui
	soil
)

target_precompile_headers(executable-inspector PRIVATE
	precompiled.h
)