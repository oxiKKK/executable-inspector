set(SOURCES
	main.cc
	application.cc
	glfw_window.cc
	processor_manager.cc
	gui/gui.cc
)

# platform specific files
if (IS_MSVC)
	set(SOURCES ${SOURCES} library_loader/library_loader_win32.cc)
else()
	set(SOURCES ${SOURCES} library_loader/library_loader_linux.cc)
endif()

# Create the target.
add_executable(executable-inspector ${SOURCES})

# include directories
target_include_directories(executable-inspector PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}
)

# needed static libs
target_link_libraries(executable-inspector PRIVATE
	${OPENGL_LIBRARIES}
	glfw
	imgui
	soil
)

target_precompile_headers(executable-inspector PRIVATE
	precompiled.h
)