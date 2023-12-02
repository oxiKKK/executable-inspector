/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef COLLECTED_DATA_H
#define COLLECTED_DATA_H
#pragma once

struct dos_hdr_t
{
	uint16_t number_of_pages{};
	PrettyHexValue<uint16_t> dos_header_size{}; // size of DOS header including the stub
	uint16_t checksum{};
};

struct collected_data_t
{
	// can be either 1) dos header 2) os2 header 3) VXD header (virtual driver, win 95/98 era)
	AliasedValue<uint32_t> file_magic{};

	dos_hdr_t dos_hdr{};
};

#endif // COLLECTED_DATA_H