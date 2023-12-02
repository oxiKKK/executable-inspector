/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#ifndef WIN32_NTIMAGE_H
#define WIN32_NTIMAGE_H
#pragma once

//
// taken from ntimage.h
//

#ifndef COMPILER_MSVC

#define IMAGE_DOS_SIGNATURE                 0x4D5A      // MZ
#define IMAGE_OS2_SIGNATURE                 0x4E45      // NE
#define IMAGE_OS2_SIGNATURE_LE              0x4C45      // LE
#define IMAGE_NT_SIGNATURE                  0x50450000  // PE00

typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
	USHORT e_magic;                     // Magic number
	USHORT e_cblp;                      // Bytes on last page of file
	USHORT e_cp;                        // Pages in file
	USHORT e_crlc;                      // Relocations
	USHORT e_cparhdr;                   // Size of header in paragraphs
	USHORT e_minalloc;                  // Minimum extra paragraphs needed
	USHORT e_maxalloc;                  // Maximum extra paragraphs needed
	USHORT e_ss;                        // Initial (relative) SS value
	USHORT e_sp;                        // Initial SP value
	USHORT e_csum;                      // Checksum
	USHORT e_ip;                        // Initial IP value
	USHORT e_cs;                        // Initial (relative) CS value
	USHORT e_lfarlc;                    // File address of relocation table
	USHORT e_ovno;                      // Overlay number
	USHORT e_res[4];                    // Reserved words
	USHORT e_oemid;                     // OEM identifier (for e_oeminfo)
	USHORT e_oeminfo;                   // OEM information; e_oemid specific
	USHORT e_res2[10];                  // Reserved words
	LONG   e_lfanew;                    // File address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

#endif // COMPILER_MSVC

#endif // WIN32_NTIMAGE_H