#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_IMAGESECTIONHEADERCHARACTERISTICSFLAGS_H                                                                                                                   // Colorize: green
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_IMAGESECTIONHEADERCHARACTERISTICSFLAGS_H                                                                                                                   // Colorize: green
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
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
typedef quint32 image_section_header_characteristics_flags;                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class ImageSectionHeaderCharacteristicsFlag: image_section_header_characteristics_flags                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                   = 0,                                                                                                                                                                          // Colorize: green
    TYPE_NO_PAD            = (1ULL << 3),  // The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1BYTES                                     // Colorize: green
    CNT_CODE               = (1ULL << 5),  // The section contains executable code                                                                                                                       // Colorize: green
    CNT_INITIALIZED_DATA   = (1ULL << 6),  // The section contains initialized data                                                                                                                      // Colorize: green
    CNT_UNINITIALIZED_DATA = (1ULL << 7),  // The section contains uninitialized data                                                                                                                    // Colorize: green
    LNK_OTHER              = (1ULL << 8),  // Reserved                                                                                                                                                   // Colorize: green
    LNK_INFO               = (1ULL << 9),  // The section contains comments or other information. This is valid only for object files                                                                    // Colorize: green
    LNK_REMOVE             = (1ULL << 11), // The section will not become part of the image. This is valid only for object files                                                                         // Colorize: green
    LNK_COMDAT             = (1ULL << 12), // The section contains COMDAT data. This is valid only for object files                                                                                      // Colorize: green
    NO_DEFER_SPEC_EXC      = (1ULL << 14), // Reset speculative exceptions handling bits in the TLB entries for this section                                                                             // Colorize: green
    GPREL                  = (1ULL << 15), // The section contains data referenced through the global pointer                                                                                            // Colorize: green
    MEM_PURGEABLE          = (1ULL << 17), // Reserved                                                                                                                                                   // Colorize: green
    MEM_LOCKED             = (1ULL << 18), // Reserved                                                                                                                                                   // Colorize: green
    MEM_PRELOAD            = (1ULL << 19), // Reserved                                                                                                                                                   // Colorize: green
    ALIGN_BIT_0            = (1ULL << 20), // Align bit                                                                                                                                                  // Colorize: green
    ALIGN_BIT_1            = (1ULL << 21), // Align bit                                                                                                                                                  // Colorize: green
    ALIGN_BIT_2            = (1ULL << 22), // Align bit                                                                                                                                                  // Colorize: green
    ALIGN_BIT_3            = (1ULL << 23), // Align bit                                                                                                                                                  // Colorize: green
    ALIGN_1BYTES           = 0x00100000, // Align data on a 1-byte boundary. This is valid only for object files                                                                                         // Colorize: green
    ALIGN_2BYTES           = 0x00200000, // Align data on a 2-byte boundary. This is valid only for object files                                                                                         // Colorize: green
    ALIGN_4BYTES           = 0x00300000, // Align data on a 4-byte boundary. This is valid only for object files                                                                                         // Colorize: green
    ALIGN_8BYTES           = 0x00400000, // Align data on a 8-byte boundary. This is valid only for object files                                                                                         // Colorize: green
    ALIGN_16BYTES          = 0x00500000, // Align data on a 16-byte boundary. This is valid only for object files                                                                                        // Colorize: green
    ALIGN_32BYTES          = 0x00600000, // Align data on a 32-byte boundary. This is valid only for object files                                                                                        // Colorize: green
    ALIGN_64BYTES          = 0x00700000, // Align data on a 64-byte boundary. This is valid only for object files                                                                                        // Colorize: green
    ALIGN_128BYTES         = 0x00800000, // Align data on a 128-byte boundary. This is valid only for object files                                                                                       // Colorize: green
    ALIGN_256BYTES         = 0x00900000, // Align data on a 256-byte boundary. This is valid only for object files                                                                                       // Colorize: green
    ALIGN_512BYTES         = 0x00A00000, // Align data on a 512-byte boundary. This is valid only for object files                                                                                       // Colorize: green
    ALIGN_1024BYTES        = 0x00B00000, // Align data on a 1024-byte boundary. This is valid only for object files                                                                                      // Colorize: green
    ALIGN_2048BYTES        = 0x00C00000, // Align data on a 2048-byte boundary. This is valid only for object files                                                                                      // Colorize: green
    ALIGN_4096BYTES        = 0x00D00000, // Align data on a 4096-byte boundary. This is valid only for object files                                                                                      // Colorize: green
    ALIGN_8192BYTES        = 0x00E00000, // Align data on a 8192-byte boundary. This is valid only for object files                                                                                      // Colorize: green
    LNK_NRELOC_OVFL        = (1ULL << 24), // The section contains extended relocations. The count of relocations for the section exceeds the 16 bits that is reserved for it in the section header. If the numberOfRelocations field in the section header is 0xFFFF, the actual relocation count is stored in the virtualAddress field of the first relocation. It is an error if IMAGE_SCN_LNK_NRELOC_OVFL is set and there are fewer than 0xFFFF relocations in the section // Colorize: green
    MEM_DISCARDABLE        = (1ULL << 25), // The section can be discarded as needed                                                                                                                     // Colorize: green
    MEM_NOT_CACHED         = (1ULL << 26), // The section cannot be cached                                                                                                                               // Colorize: green
    MEM_NOT_PAGED          = (1ULL << 27), // The section cannot be paged                                                                                                                                // Colorize: green
    MEM_SHARED             = (1ULL << 28), // The section can be shared in memory                                                                                                                        // Colorize: green
    MEM_EXECUTE            = (1ULL << 29), // The section can be executed as code                                                                                                                        // Colorize: green
    MEM_READ               = (1ULL << 30), // The section can be read                                                                                                                                    // Colorize: green
    MEM_WRITE              = (1ULL << 31), // The section can be written to                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(ImageSectionHeaderCharacteristicsFlags, image_section_header_characteristics_flags); // TEST: NO                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(ImageSectionHeaderCharacteristicsFlag flag) // TEST: NO                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case ImageSectionHeaderCharacteristicsFlag::NONE: return "NONE";                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(ImageSectionHeaderCharacteristicsFlag flag) // TEST: NO                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[24];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", (image_section_header_characteristics_flags)flag, flagToString(flag));                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const ImageSectionHeaderCharacteristicsFlags &flags) // TEST: NO                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[48];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, ImageSectionHeaderCharacteristicsFlag);                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const ImageSectionHeaderCharacteristicsFlags &flags) // TEST: NO                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[61];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, ImageSectionHeaderCharacteristicsFlag, "0x%08X");                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_IMAGESECTIONHEADERCHARACTERISTICSFLAGS_H                                                                                                                 // Colorize: green
