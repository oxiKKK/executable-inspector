/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef ALIASTED_VALUE_H
#define ALIASTED_VALUE_H
#pragma once

#include <utility>
#include <type_traits>

// Class that allows to hold a constant value and a name associated to that value.
// This can be useful when printing named constans instead of actual values.
template<typename T> requires std::is_integral_v<T>
class AliasedValue
{
public:
	AliasedValue(T constant, const std::string& name) :
		m_named_constant(constant, name)
	{
	}

	AliasedValue() {}

public:
	forceinline T value() const { return m_named_constant.first; }
	forceinline const std::string& name() const { return m_named_constant.second; }
	forceinline bool is(T val) const { return value() == val; }

private:
	std::pair<T, std::string> m_named_constant{};
};

#endif // ALIASTED_VALUE_H