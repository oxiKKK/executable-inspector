set(SOURCES
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/imgui_demo.cpp
	imgui/imgui.cpp

	# backends
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_opengl3.cpp
)

# Create the target.
add_library(imgui SHARED  ${SOURCES})

# include directories
target_include_directories(imgui PRIVATE
	${SHARED_INCLUDES}
	${CMAKE_CURRENT_SOURCE_DIR}/imgui
)

# NOTE: we need this for the includes
target_link_libraries(imgui PRIVATE
	${OPENGL_LIBRARIES}
	glfw
)