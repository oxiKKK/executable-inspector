/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef CONSOLE_H
#define CONSOLE_H
#pragma once

namespace con
{

namespace detail
{

enum EPrintType
{
	PRINT,
	DEBUG,
	ERROR,
	WARN,
};

template<EPrintType Type>
inline void print_impl(const std::string& s)
{
	static_assert(Type >= PRINT && Type <= WARN);

	if constexpr (Type == PRINT)
	{
		fmt::print(fg(fmt::color::floral_white), "{}\n", s);
	}
	else if constexpr (Type == DEBUG)
	{
		fmt::print(fg(fmt::color::purple) | fmt::emphasis::bold, "debug: ");
		fmt::print(fg(fmt::color::purple), "{}\n", s);
	}
	else if constexpr (Type == WARN)
	{
		fmt::print(fg(fmt::color::dark_orange) | fmt::emphasis::bold, "warn: ");
		fmt::print(fg(fmt::color::dark_orange), "{}\n", s);
	}
	else if constexpr (Type == ERROR)
	{
		fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "error: ");
		fmt::print(fg(fmt::color::red), "{}\n", s);
	}
}

} // namespace detail

//----------------------------------------------------------
// debug

template <class... _Types>
forceinline void debug(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
#ifdef _DEBUG
	detail::print_impl<detail::DEBUG>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
#endif
}

forceinline void debug(const std::string& s)
{
#ifdef _DEBUG
	detail::print_impl<detail::DEBUG>(s);
#endif
}

//----------------------------------------------------------
// classic print

template <class... _Types>
forceinline void print(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
	detail::print_impl<detail::PRINT>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
}

forceinline void print(const std::string& s)
{
	detail::print_impl<detail::PRINT>(s);
}

//----------------------------------------------------------
// warning

template <class... _Types>
forceinline void warn(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
	detail::print_impl<detail::WARN>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
}

forceinline void warn(const std::string& s)
{
	detail::print_impl<detail::WARN>(s);
}

//----------------------------------------------------------
// error

template <class... _Types>
forceinline void error(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
	detail::print_impl<detail::ERROR>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
}

forceinline void error(const std::string& s)
{
	detail::print_impl<detail::ERROR>(s);
}

//
// debug routines
//

//----------------------------------------------------------
// debug classic print

template <class... _Types>
forceinline void dprint(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
#ifdef _DEBUG
	detail::print_impl<detail::PRINT>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
#endif
}

forceinline void dprint(const std::string& s)
{
#ifdef _DEBUG
	detail::print_impl<detail::PRINT>(s);
#endif
}

//----------------------------------------------------------
// debug warning

template <class... _Types>
forceinline void dwarn(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
#ifdef _DEBUG
	detail::print_impl<detail::WARN>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
#endif
}

forceinline void dwarn(const std::string& s)
{
#ifdef _DEBUG
	detail::print_impl<detail::WARN>(s);
#endif
}

//----------------------------------------------------------
// debug error

template <class... _Types>
forceinline void derror(const fmt::format_string<_Types...> _Fmt, _Types&&... _Args)
{
#ifdef _DEBUG
	detail::print_impl<detail::ERROR>(fmt::vformat(_Fmt.get(), fmt::make_format_args(_Args...)));
#endif
}

forceinline void derror(const std::string& s)
{
#ifdef _DEBUG
	detail::print_impl<detail::ERROR>(s);
#endif
}

} // namespace con

#endif // CONSOLE_H