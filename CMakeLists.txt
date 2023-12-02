cmake_minimum_required(VERSION 3.27)
project(executable-inspector CXX C)

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

include(cmake/DetectCompiler.cmake)

# commonly used paths
set(ROOT_PATH ${PROJECT_SOURCE_DIR})
set(SRC_PATH ${ROOT_PATH}/src)
set(PUBLIC_PATH ${ROOT_PATH}/src/public)
set(THIRDPARTY_PATH ${ROOT_PATH}/src/thirdparty)

message("ROOT_PATH: ${ROOT_PATH}")
message("SRC_PATH: ${SRC_PATH}")
message("PUBLIC_PATH: ${PUBLIC_PATH}")
message("THIRDPARTY_PATH: ${THIRDPARTY_PATH}")

message("Install prefix: ${CMAKE_INSTALL_PREFIX}")

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# is multi-config?
GET_PROPERTY(MULTICONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (MULTICONFIG)
	message("Is multi-config: Yes")
else()
	message("Is multi-config: No")
endif()

# for multi-config generators such as VisualStudio, the variable for build type is different than
# on single-config generators such as Ninja, hence the name.
if (MULTICONFIG)
	set(BUILD_TYPE ${CMAKE_CONFIGURATION_TYPES})
else()
	set(BUILD_TYPE ${CMAKE_BUILD_TYPE})
endif()

message("Build type: ${BUILD_TYPE}")

# define debug/ndebug macros
add_compile_definitions($<$<CONFIG:Release>:NDEBUG>)
add_compile_definitions($<$<CONFIG:Debug>:_DEBUG>)

# select compiler
if (IS_MSVC)
	add_compile_definitions(COMPILER_MSVC)
	add_compile_definitions(PLATFORM_WIN)
elseif (IS_GCC)
	add_compile_definitions(COMPILER_GCC)
	add_compile_definitions(PLATFORM_LINUX)
endif()

# output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_PATH}) # static library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_PATH}) # a dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_PATH}) # an exe

# global include directories
include_directories(
	${SRC_PATH}
	${THIRDPARTY_PATH}/imgui
	${THIRDPARTY_PATH}/imgui/imgui # this is needed for the backend files
)

# in order to replace vanilla imconfig.h with our own
add_compile_definitions(PUBLIC IMGUI_USER_CONFIG="${PUBLIC_PATH}/imgui_config.h")

set(INSTALL_PATH "${ROOT_PATH}/bin")

# https://stackoverflow.com/questions/8880802/cmake-linking-shared-library
set(CMAKE_INSTALL_RPATH ${INSTALL_PATH})

message("CMAKE_INSTALL_RPATH: ${CMAKE_INSTALL_RPATH}")

# thirdparty dependencies
include(cmake/thirdparty/fmt.cmake)
include(cmake/thirdparty/glfw.cmake)
include(cmake/thirdparty/soil.cmake)
include(cmake/thirdparty/imgui.cmake)

# subdirectories
add_subdirectory(src/app)
#add_subdirectory(src/assets)
add_subdirectory(src/processors/elf)
add_subdirectory(src/processors/PE)

# install targets
install(TARGETS executable-inspector DESTINATION ${INSTALL_PATH})
#install(TARGETS assets DESTINATION ${INSTALL_PATH})
install(TARGETS elfprocessor DESTINATION ${INSTALL_PATH})
install(TARGETS peprocessor DESTINATION ${INSTALL_PATH})