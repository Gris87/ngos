#ifndef IMAGE_BUILDER_SRC_PE_COFFHEADER_H
#define IMAGE_BUILDER_SRC_PE_COFFHEADER_H



#include <Qt>



#define NUMBER_OF_SECTIONS 3

#define IMAGE_MACHINE_INTEL_386                           0x014C
#define IMAGE_MACHINE_X64                                 0x8664
#define IMAGE_MACHINE_MIPS_R3000                          0x0162
#define IMAGE_MACHINE_MIPS_R10000                         0x0168
#define IMAGE_MACHINE_MIPS_LITTLE_ENDIAN_WCI_V2           0x0169
#define IMAGE_MACHINE_OLD_ALPHA_AXP                       0x0183
#define IMAGE_MACHINE_ALPHA_AXP                           0x0184
#define IMAGE_MACHINE_HITACHI_SH3                         0x01A2
#define IMAGE_MACHINE_HITACHI_SH3_DSP                     0x01A3
#define IMAGE_MACHINE_HITACHI_SH4                         0x01A6
#define IMAGE_MACHINE_HITACHI_SH5                         0x01A8
#define IMAGE_MACHINE_ARM_LITTLE_ENDIAN                   0x01C0
#define IMAGE_MACHINE_THUMB                               0x01C2
#define IMAGE_MACHINE_ARMV7                               0x01C4
#define IMAGE_MACHINE_MATSUSHITA_AM33                     0x01D3
#define IMAGE_MACHINE_POWERPC_LITTLE_ENDIAN               0x01F0
#define IMAGE_MACHINE_POWERPC_WITH_FLOATING_POINT_SUPPORT 0x01F1
#define IMAGE_MACHINE_INTEL_IA64                          0x0200
#define IMAGE_MACHINE_MIPS16                              0x0266
#define IMAGE_MACHINE_MOTOROLA_68000_SERIES               0x0268
#define IMAGE_MACHINE_ALPHA_AXP_64_BIT                    0x0284
#define IMAGE_MACHINE_MIPS_WITH_FPU                       0x0366
#define IMAGE_MACHINE_MIPS16_WITH_FPU                     0x0466
#define IMAGE_MACHINE_EFI_BYTE_CODE                       0x0EBC
#define IMAGE_MACHINE_AMD_AMD64                           0x8664
#define IMAGE_MACHINE_MITSUBISHI_M32R_LITTLE_ENDIAN       0x9041
#define IMAGE_MACHINE_ARM64_LITTLE_ENDIAN                 0xAA64
#define IMAGE_MACHINE_CLR_PURE_MSIL                       0xC0EE

#define IMAGE_FILE_RELOCS_STRIPPED         0x0001 // Relocation information was stripped from file
#define IMAGE_FILE_EXECUTABLE_IMAGE        0x0002 // The file is executable
#define IMAGE_FILE_LINE_NUMS_STRIPPED      0x0004 // COFF line numbers were stripped from file
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED     0x0008 // COFF symbol table entries were stripped from file
#define IMAGE_FILE_AGGRESIVE_WS_TRIM       0x0010 // Aggressively trim the working set(obsolete)
#define IMAGE_FILE_LARGE_ADDRESS_AWARE     0x0020 // The application can handle addresses greater than 2 GB
#define IMAGE_FILE_BYTES_REVERSED_LO       0x0080 // The bytes of the word are reversed(obsolete)
#define IMAGE_FILE_32BIT_MACHINE           0x0100 // The computer supports 32-bit words
#define IMAGE_FILE_DEBUG_STRIPPED          0x0200 // Debugging information was removed and stored separately in another file
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400 // If the image is on removable media, copy it to and run it from the swap file
#define IMAGE_FILE_NET_RUN_FROM_SWAP       0x0800 // If the image is on the network, copy it to and run it from the swap file
#define IMAGE_FILE_SYSTEM                  0x1000 // The image is a system file
#define IMAGE_FILE_DLL                     0x2000 // The image is a DLL file
#define IMAGE_FILE_UP_SYSTEM_ONLY          0x4000 // The image should only be ran on a single processor computer
#define IMAGE_FILE_BYTES_REVERSED_HI       0x8000 // The bytes of the word are reversed(obsolete)



struct COFFHeader
{
    quint16 machine;
    quint16 numberOfSections;
    quint32 timeDateStamp;
    quint32 pointerToSymbolTable;
    quint32 numberOfSymbols;
    quint16 sizeOfOptionalHeader;
    quint16 characteristics;

    void print(); // TEST: NO
    bool verify(); // TEST: NO
};



#endif // IMAGE_BUILDER_SRC_PE_COFFHEADER_H
