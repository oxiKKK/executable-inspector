/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef PRETTY_VALUE_H
#define PRETTY_VALUE_H
#pragma once

#include <utility>
#include <type_traits>


//
// Pretty value
//
//	Wrapper around type T that contains helper methods while 
//	sizeof(PrettyValue<T>) == sizeof(T).
//
//	Note: Don't use this raw class, use pre-defined classes below.
//
template<typename T> requires(std::is_integral<T>::value)
class PrettyValue
{
public:
	constexpr PrettyValue(T val) :
		m_value(val)
	{}
	constexpr PrettyValue() :
		m_value({})
	{}

public:
	// These operators has to be overrided by the class that derives this.
	virtual forceinline constexpr operator T() const { return m_value; };
	virtual forceinline constexpr bool operator=(T val) { return m_value = val; };

	// Returns a string depending on the overrided string() function.
	forceinline constexpr operator std::string() const { return string(); }

public:
	forceinline constexpr T value() const { return m_value; }

	template<typename U>
	forceinline constexpr U cast() const { return static_cast<U>(m_value); }

	forceinline constexpr uint8_t u8() const { return cast<uint8_t>(); }
	forceinline constexpr uint16_t u16() const { return cast<uint16_t>(); }
	forceinline constexpr uint32_t u32() const { return cast<uint32_t>(); }
	forceinline constexpr uint64_t u64() const { return cast<uint64_t>(); }

	forceinline constexpr int8_t i8() const { return cast<int8_t>(); }
	forceinline constexpr int16_t i16() const { return cast<int16_t>(); }
	forceinline constexpr int32_t i32() const { return cast<int32_t>(); }
	forceinline constexpr int64_t i64() const { return cast<int64_t>(); }

	// True if value is aligned to 'to'.
	forceinline constexpr bool is_aligned(T to) const
	{
		// ensure that 'to' is not zero to avoid division by zero
		if (to == 0)
		{
			return false;
		}

		return (m_value % to) == 0;
	}

	// True if value is power of 2
	forceinline constexpr bool is_power_of_two() const { return m_value != 0 && !(m_value & (m_value - 1)); }

public:
	// Override this function to output custom-formatted values in a form of std::string
	// when this object is implicitly casted into std::string.
	virtual std::string string() const { return m_value ? std::to_string(m_value) : "null"; }

protected:
	T m_value;
};

//
// Hexadecimal pretty value declaration
//

template<typename T> requires(std::is_integral<T>::value)
class PrettyHexValue : public PrettyValue<T>
{
private:
	using PrettyValue<T>::m_value;

public:
	// These has to be declared in order for the compiler to figure stuff out.
	constexpr PrettyHexValue(T val) : PrettyValue<T>(val) {}
	constexpr PrettyHexValue() : PrettyValue<T>() {}

	forceinline constexpr operator T() const override { return m_value; }
	forceinline constexpr bool operator=(T val) { return m_value = val; }

public:
	forceinline std::string string() const override
	{
		return string(sizeof(T) * 2);
	}

	forceinline std::string string(size_t padding) const
	{
		return m_value ? std::format("0x{:0>{}X}", m_value, padding) : "null";
	}
};

//
// Decimal pretty value declaration
//

template<typename T> requires(std::is_integral<T>::value)
class PrettyDecValue : public PrettyValue<T>
{
private:
	using PrettyValue<T>::m_value;

public:
	// These has to be declared in order for the compiler to figure stuff out.
	constexpr PrettyDecValue(T val) : PrettyValue<T>(val) {}
	constexpr PrettyDecValue() : PrettyValue<T>() {}

	forceinline constexpr operator T() const override { return m_value; }
	forceinline constexpr bool operator=(T val) { return m_value = val; }

public:
	forceinline std::string string() const override
	{
		return m_value ? std::to_string(m_value) : "null";
	}
};

//
// Binary pretty value declaration
//

template<typename T> requires(std::is_integral<T>::value)
class PrettyBinValue : public PrettyValue<T>
{
private:
	using PrettyValue<T>::m_value;

public:
	// These has to be declared in order for the compiler to figure stuff out.
	constexpr PrettyBinValue(T val) : PrettyValue<T>(val) {}
	constexpr PrettyBinValue() : PrettyValue<T>() {}

	forceinline constexpr operator T() const override { return m_value; }
	forceinline constexpr bool operator=(T val) { return m_value = val; }

public:
	forceinline std::string string() const override
	{
		return m_value ? std::format("0b{:b}", m_value) : "null";
	}
};

#endif // PRETTY_VALUE_H