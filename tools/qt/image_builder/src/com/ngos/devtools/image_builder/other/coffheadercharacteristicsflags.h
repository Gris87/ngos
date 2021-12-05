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
    RELOCS_STRIPPED         = (1ULL << 0),  // Relocation information was stripped from file                                                                                                             // Colorize: green
    EXECUTABLE_IMAGE        = (1ULL << 1),  // The file is executable                                                                                                                                    // Colorize: green
    LINE_NUMS_STRIPPED      = (1ULL << 2),  // COFF line numbers were stripped from file                                                                                                                 // Colorize: green
    LOCAL_SYMS_STRIPPED     = (1ULL << 3),  // COFF symbol table entries were stripped from file                                                                                                         // Colorize: green
    AGGRESIVE_WS_TRIM       = (1ULL << 4),  // Aggressively trim the working set(obsolete)                                                                                                               // Colorize: green
    LARGE_ADDRESS_AWARE     = (1ULL << 5),  // The application can handle addresses greater than 2 GB                                                                                                    // Colorize: green
    BYTES_REVERSED_LO       = (1ULL << 7),  // The bytes of the word are reversed(obsolete)                                                                                                              // Colorize: green
    _32BIT_MACHINE          = (1ULL << 8),  // The computer supports 32-bit words                                                                                                                        // Colorize: green
    DEBUG_STRIPPED          = (1ULL << 9),  // Debugging information was removed and stored separately in another file                                                                                   // Colorize: green
    REMOVABLE_RUN_FROM_SWAP = (1ULL << 10), // If the image is on removable media, copy it to and run it from the swap file                                                                              // Colorize: green
    NET_RUN_FROM_SWAP       = (1ULL << 11), // If the image is on the network, copy it to and run it from the swap file                                                                                  // Colorize: green
    SYSTEM                  = (1ULL << 12), // The image is a system file                                                                                                                                // Colorize: green
    DLL                     = (1ULL << 13), // The image is a DLL file                                                                                                                                   // Colorize: green
    UP_SYSTEM_ONLY          = (1ULL << 14), // The image should only be ran on a single processor computer                                                                                               // Colorize: green
    BYTES_REVERSED_HI       = (1ULL << 15)  // The bytes of the word are reversed(obsolete)                                                                                                              // Colorize: green
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