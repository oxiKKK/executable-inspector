/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H
#pragma once

#include <utility>
#include <cassert>
#include <fstream>

// Helper class that allows us to better manage raw byte buffer
// The template parameter is the addressing type on such file.
template<typename A> requires(std::is_integral<A>::value)
class ByteBuffer
{
public:
	// Create data from filepath
	bool create(const std::filesystem::path& filepath, A size);

	// Create data from a buffer
	bool create(uint8_t* data, A size);

	void destroy();
	~ByteBuffer()
	{
		destroy();
	}

private:
	// Allocates # number of bytes for the byte buffer
	bool allocate(A size);

	// Deallocates previously allocated data
	void deallocate();

	// Copy data from filepath
	bool copy_data(const std::filesystem::path& filepath);

	// Copy data from buffer
	bool copy_data(uint8_t* data);

public:
	inline uint8_t* const get_raw() const { return m_byte_buffer; }
	inline auto get_size() const { return m_size; }

	// Returns pointer to the address at specified offset
	template<class T>
	inline T* get_at(A off) const
	{
		if (!m_byte_buffer)
			return nullptr;

		if (off >= m_size)
		{
			ASSERT_UNREFERENCED("offset too large");
			return nullptr;
		}

		return reinterpret_cast<T*>(m_byte_buffer + off);
	}

	// Converts all bytes into readable string form
	std::string to_string(A at, const std::string& delimiter = " ") const;

private:
	uint8_t* m_byte_buffer = nullptr;
	A m_size = 0;
};

template<typename A> requires(std::is_integral<A>::value)
inline bool ByteBuffer<A>::create(const std::filesystem::path& filepath, A size)
{
	if (!allocate(size))
		return false;

	if (!copy_data(filepath))
		return false;

	return true;
}

template<typename A> requires(std::is_integral<A>::value)
inline bool ByteBuffer<A>::create(uint8_t* data, A size)
{
	if (!allocate(size))
		return false;

	if (!copy_data(data))
		return false;

	return true;
}

template<typename A> requires(std::is_integral<A>::value)
inline void ByteBuffer<A>::destroy()
{
	deallocate();
}

template<typename A> requires(std::is_integral<A>::value)
inline bool ByteBuffer<A>::allocate(A size)
{
	m_size = size;

	m_byte_buffer = new uint8_t[m_size];
	if (!m_byte_buffer)
	{
		return false;
	}

	return true;
}

template<typename A> requires(std::is_integral<A>::value)
inline void ByteBuffer<A>::deallocate()
{
	if (!m_byte_buffer)
	{
		return;
	}

	delete[] m_byte_buffer;
	m_byte_buffer = nullptr;
}

template<typename A> requires(std::is_integral<A>::value)
inline bool ByteBuffer<A>::copy_data(const std::filesystem::path& filepath)
{
	std::ifstream ifs(filepath, std::ios_base::in | std::ios_base::binary);

	if (ifs.bad())
	{
		return false;
	}

	ifs.read(reinterpret_cast<char*>(m_byte_buffer), m_size);
	ifs.close();

	return true;
}

template<typename A> requires(std::is_integral<A>::value)
inline bool ByteBuffer<A>::copy_data(uint8_t* data)
{
	if (!data)
	{
		return false;
	}

	memcpy(m_byte_buffer, data, m_size);

	return true;
}

template<typename A> requires(std::is_integral<A>::value)
inline std::string ByteBuffer<A>::to_string(A at, const std::string& delimiter) const
{
	if (!m_size)
		return "null";

	if (at >= m_size - at)
	{
		return "null";
	}

	std::string ret;

	for (A i = at; i < m_size; i++)
	{
		uint8_t byte = *get_at<uint8_t>(i);

		ret += fmt::format("{:02X}", byte);
		if (!delimiter.empty())
			ret += delimiter;
	}

	return ret;
}

#endif // BYTEBUFFER_H