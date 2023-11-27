/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) oxiKKK 2022-present
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

//
// custom_format.h -- custom types for fmt::format
//

#ifndef CUSTOM_FORMAT_H
#define CUSTOM_FORMAT_H
#pragma once

#include <filesystem>

template <>
struct fmt::formatter<std::filesystem::path> : fmt::formatter<std::string> {
	auto format(const std::filesystem::path& p, fmt::format_context& ctx) {
		return fmt::formatter<std::string>::format(
			fmt::format("{}", p.string()), ctx);
	}
};

#endif // CUSTOM_FORMAT_H