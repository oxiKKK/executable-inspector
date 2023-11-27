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

// public
#include <public/platform.h>
#include <public/vector.h>
#include <public/interface/file_processor_interface.h>
#include <public/interface/processor_manager_interface.h>

// glfw
#include <GLFW/glfw3.h>

// imgui
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

// project
#include "console.h"
#include "gui/gui.h"
#include "glfw_window.h"
#include "application.h"

#endif // PRECOMPILED_H