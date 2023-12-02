/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PRECOMPILED_H
#define PRECOMPILED_H
#pragma once

// c++ standard
#include <memory>
#include <thread>
#include <unordered_map>

// public
#include <public/platform.h>
#include <public/vector.h>
#include <public/interface/file_processor_interface.h>
#include <public/interface/processor_manager_interface.h>
#include <public/interface/library_loader_interface.h>
#include <public/bytebuffer.h>
#include <public/processors/processed_file_reader.h>

// glfw
#include <GLFW/glfw3.h>

// imgui
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

// project
#include "elf_processor.h"

#endif // PRECOMPILED_H