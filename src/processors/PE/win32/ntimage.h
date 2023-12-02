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

#define IMAGE_DOS_SIGNATURE                 0x5A4D      // MZ
#define IMAGE_OS2_SIGNATURE                 0x454E      // NE
#define IMAGE_OS2_SIGNATURE_LE              0x454C      // LE
#define IMAGE_VXD_SIGNATURE                 0x454C      // LE
#define IMAGE_NT_SIGNATURE                  0x00004550  // PE00

// NOTE: DOS header are using 2-byte packing!
typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
	WORD   e_magic;                     // Magic number
	WORD   e_cblp;                      // Bytes on last page of file
	WORD   e_cp;                        // Pages in file
	WORD   e_crlc;                      // Relocations
	WORD   e_cparhdr;                   // Size of header in paragraphs
	WORD   e_minalloc;                  // Minimum extra paragraphs needed
	WORD   e_maxalloc;                  // Maximum extra paragraphs needed
	WORD   e_ss;                        // Initial (relative) SS value
	WORD   e_sp;                        // Initial SP value
	WORD   e_csum;                      // Checksum
	WORD   e_ip;                        // Initial IP value
	WORD   e_cs;                        // Initial (relative) CS value
	WORD   e_lfarlc;                    // File address of relocation table
	WORD   e_ovno;                      // Overlay number
	WORD   e_res[4];                    // Reserved words
	WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
	WORD   e_oeminfo;                   // OEM information; e_oemid specific
	WORD   e_res2[10];                  // Reserved words
	LONG   e_lfanew;                    // File address of new exe header
} __attribute__((aligned(2), packed)) IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

// NOTE: DOS header are using 2-byte packing!
typedef struct _IMAGE_OS2_HEADER {      // OS/2 .EXE header
	WORD   ne_magic;                    // Magic number
	CHAR   ne_ver;                      // Version number
	CHAR   ne_rev;                      // Revision number
	WORD   ne_enttab;                   // Offset of Entry Table
	WORD   ne_cbenttab;                 // Number of bytes in Entry Table
	LONG   ne_crc;                      // Checksum of whole file
	WORD   ne_flags;                    // Flag word
	WORD   ne_autodata;                 // Automatic data segment number
	WORD   ne_heap;                     // Initial heap allocation
	WORD   ne_stack;                    // Initial stack allocation
	LONG   ne_csip;                     // Initial CS:IP setting
	LONG   ne_sssp;                     // Initial SS:SP setting
	WORD   ne_cseg;                     // Count of file segments
	WORD   ne_cmod;                     // Entries in Module Reference Table
	WORD   ne_cbnrestab;                // Size of non-resident name table
	WORD   ne_segtab;                   // Offset of Segment Table
	WORD   ne_rsrctab;                  // Offset of Resource Table
	WORD   ne_restab;                   // Offset of resident name table
	WORD   ne_modtab;                   // Offset of Module Reference Table
	WORD   ne_imptab;                   // Offset of Imported Names Table
	LONG   ne_nrestab;                  // Offset of Non-resident Names Table
	WORD   ne_cmovent;                  // Count of movable entries
	WORD   ne_align;                    // Segment alignment shift count
	WORD   ne_cres;                     // Count of resource segments
	BYTE   ne_exetyp;                   // Target Operating system
	BYTE   ne_flagsothers;              // Other .EXE flags
	WORD   ne_pretthunks;               // offset to return thunks
	WORD   ne_psegrefbytes;             // offset to segment ref. bytes
	WORD   ne_swaparea;                 // Minimum code swap area size
	WORD   ne_expver;                   // Expected Windows version number
} __attribute__((aligned(2), packed)) IMAGE_OS2_HEADER, * PIMAGE_OS2_HEADER;

#endif // COMPILER_MSVC

#endif // WIN32_NTIMAGE_H