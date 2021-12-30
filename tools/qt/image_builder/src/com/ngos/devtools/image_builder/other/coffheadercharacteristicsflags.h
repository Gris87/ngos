#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_COFFHEADERCHARACTERISTICSFLAGS_H                                                                                                                           // Colorize: green
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_COFFHEADERCHARACTERISTICSFLAGS_H                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <Qt>                                                                                                                                                                                            // Colorize: green
#include <stdio.h>                                                                                                                                                                                       // Colorize: green
#include <string.h>                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/flags.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/ngos/linkage.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/devtools/shared/utils/string.h>                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
typedef quint16 coff_header_characteristics_flags;                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class COFFHeaderCharacteristicsFlag: coff_header_characteristics_flags                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                    = 0,                                                                                                                                                                         // Colorize: green
    RELOCS_STRIPPED         = (1ULL << 0),  // Image only, Windows CE, and Microsoft Windows NT and later. This indicates that the file does not contain base relocations and must therefore be loaded at its preferred base address. If the base address is not available, the loader reports an error. The default behavior of the linker is to strip base relocations from executable (EXE) files. // Colorize: green
    EXECUTABLE_IMAGE        = (1ULL << 1),  // Image only. This indicates that the image file is valid and can be run. If this flag is not set, it indicates a linker error.                             // Colorize: green
    LINE_NUMS_STRIPPED      = (1ULL << 2),  // COFF line numbers have been removed. This flag is deprecated and should be zero.                                                                          // Colorize: green
    LOCAL_SYMS_STRIPPED     = (1ULL << 3),  // COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero.                                                // Colorize: green
    AGGRESSIVE_WS_TRIM      = (1ULL << 4),  // Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero.                                             // Colorize: green
    LARGE_ADDRESS_AWARE     = (1ULL << 5),  // Application can handle > 2-GB addresses.                                                                                                                  // Colorize: green
    BYTES_REVERSED_LO       = (1ULL << 7),  // Little endian: the least significant bit (LSB) precedes the most significant bit (MSB) in memory. This flag is deprecated and should be zero.             // Colorize: green
    _32BIT_MACHINE          = (1ULL << 8),  // Machine is based on a 32-bit-word architecture.                                                                                                           // Colorize: green
    DEBUG_STRIPPED          = (1ULL << 9),  // Debugging information is removed from the image file.                                                                                                     // Colorize: green
    REMOVABLE_RUN_FROM_SWAP = (1ULL << 10), // If the image is on removable media, fully load it and copy it to the swap file.                                                                           // Colorize: green
    NET_RUN_FROM_SWAP       = (1ULL << 11), // If the image is on network media, fully load it and copy it to the swap file.                                                                             // Colorize: green
    SYSTEM                  = (1ULL << 12), // The image file is a system file, not a user program.                                                                                                      // Colorize: green
    DLL                     = (1ULL << 13), // The image file is a dynamic-link library (DLL). Such files are considered executable files for almost all purposes, although they cannot be directly run. // Colorize: green
    UP_SYSTEM_ONLY          = (1ULL << 14), // The file should be run only on a uniprocessor machine.                                                                                                    // Colorize: green
    BYTES_REVERSED_HI       = (1ULL << 15)  // Big endian: the MSB precedes the LSB in memory. This flag is deprecated and should be zero.                                                               // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(COFFHeaderCharacteristicsFlags, coff_header_characteristics_flags); // TEST: NO                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(COFFHeaderCharacteristicsFlag flag) // TEST: NO                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case COFFHeaderCharacteristicsFlag::NONE: return "NONE";                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(COFFHeaderCharacteristicsFlag flag) // TEST: NO                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[24];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", (coff_header_characteristics_flags)flag, flagToString(flag));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const COFFHeaderCharacteristicsFlags &flags) // TEST: NO                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[48];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, COFFHeaderCharacteristicsFlag);                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const COFFHeaderCharacteristicsFlags &flags) // TEST: NO                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[61];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, COFFHeaderCharacteristicsFlag, "0x%08X");                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_COFFHEADERCHARACTERISTICSFLAGS_H                                                                                                                         // Colorize: green
