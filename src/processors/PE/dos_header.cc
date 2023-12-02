/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"
#include "PE_processor.h"

bool CPEProcessor::process_dos_hdr()
{
	auto pdos_magic = m_reader->at<WORD>(0);

	con::print("DOS magic: {:04X}", *pdos_magic);

	if (!process_dos_magic(*pdos_magic))
	{
		return false;
	}

	// now we must only get valid types
	// delegate the work to a subroutine
	switch (m_data.file_magic.value())
	{
	case IMAGE_DOS_SIGNATURE: return process_dos_signature();
	case IMAGE_OS2_SIGNATURE: return process_os2_signature();
	case IMAGE_VXD_SIGNATURE: return process_vxd_signature();
	}

	ASSERT_UNREFERENCED("should not ever happen, maybe missed something?");
	return false;
}

bool CPEProcessor::process_dos_magic(uint16_t magic)
{
	m_data.file_magic = { magic, fmt::format("0x{:04X}", magic) };

	switch (magic)
	{
	case IMAGE_DOS_SIGNATURE:
		m_data.file_magic = { IMAGE_DOS_SIGNATURE, "MZ" };
		break;
	case IMAGE_OS2_SIGNATURE:
		m_data.file_magic = { IMAGE_OS2_SIGNATURE, "NE" };
		break;
	case IMAGE_VXD_SIGNATURE:
		m_data.file_magic = { IMAGE_VXD_SIGNATURE, "VXD" };
		break;
	default:
		m_data.file_magic = { magic, fmt::format("0x{:04X}", magic) };
		con::error("unknown DOS magic: {}", m_data.file_magic.name());
		return false;
	}

	con::print("DOS header: {}", m_data.file_magic.name());
	return true;
}

bool CPEProcessor::process_dos_signature()
{
	auto pdos_hdr = m_reader->at<IMAGE_DOS_HEADER>(0);

	m_data.dos_hdr.number_of_pages = pdos_hdr->e_cp;
	m_data.dos_hdr.dos_header_size = pdos_hdr->e_lfanew;
	m_data.dos_hdr.checksum = pdos_hdr->e_csum;

	// validate elfanew
	if (!m_data.dos_hdr.dos_header_size || m_data.dos_hdr.dos_header_size < sizeof(IMAGE_DOS_HEADER))
	{
		con::error("invalid PE header offset: {}", m_data.dos_hdr.dos_header_size.string());
		return false;
	}

	con::print("number_of_pages: {}", m_data.dos_hdr.number_of_pages);
	con::print("dos_header_size: {}", m_data.dos_hdr.dos_header_size.string());
	con::print("checksum:        {:04X}", m_data.dos_hdr.checksum);

	return true;
}

bool CPEProcessor::process_os2_signature()
{
	ASSERT_UNREFERENCED("unimplemented");
	return false;
}

bool CPEProcessor::process_vxd_signature()
{
	ASSERT_UNREFERENCED("unimplemented");
	return false;
}
