set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_EXAMPLES OFF)

add_subdirectory(${THIRDPARTY_PATH}/glfw)

link_libraries(glfw)

install(TARGETS glfw DESTINATION ${INSTALL_PATH})