#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_SECTIONHEADERCHARACTERISTICSFLAGS_H                                                                                                                   // Colorize: green
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_SECTIONHEADERCHARACTERISTICSFLAGS_H                                                                                                                   // Colorize: green
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
typedef quint32 section_header_characteristics_flags;

enum class SectionHeaderCharacteristicsFlag: section_header_characteristics_flags
{
    NONE                   = 0,
    TYPE_NO_PAD            = (1ULL << 3),  // The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1BYTES. This is valid only for object files.
    CNT_CODE               = (1ULL << 5),  // The section contains executable code.
    CNT_INITIALIZED_DATA   = (1ULL << 6),  // The section contains initialized data.
    CNT_UNINITIALIZED_DATA = (1ULL << 7),  // The section contains uninitialized data.
    LNK_OTHER              = (1ULL << 8),  // Reserved for future use.
    LNK_INFO               = (1ULL << 9),  // The section contains comments or other information. The .drectve section has this type. This is valid for object files only.
    LNK_REMOVE             = (1ULL << 11), // The section will not become part of the image. This is valid only for object files.
    LNK_COMDAT             = (1ULL << 12), // The section contains COMDAT data. For more information, see <a href="#comdat-sections-object-only" data-linktype="self-bookmark">COMDAT Sections (Object Only)</a>. This is valid only for object files.
    NO_DEFER_SPEC_EXC      = (1ULL << 14), // Reset speculative exceptions handling bits in the TLB entries for this section
    GPREL                  = (1ULL << 15), // The section contains data referenced through the global pointer (GP).
    MEM_PURGEABLE          = (1ULL << 17), // Reserved for future use.
    MEM_LOCKED             = (1ULL << 18), // Reserved for future use.
    MEM_PRELOAD            = (1ULL << 19), // Reserved for future use.
    ALIGN_BIT_0            = (1ULL << 20), // Align bit
    ALIGN_BIT_1            = (1ULL << 21), // Align bit
    ALIGN_BIT_2            = (1ULL << 22), // Align bit
    ALIGN_BIT_3            = (1ULL << 23), // Align bit
    ALIGN_1BYTES           = 0x00100000,   // Align data on a 1-byte boundary. Valid only for object files.
    ALIGN_2BYTES           = 0x00200000,   // Align data on a 2-byte boundary. Valid only for object files.
    ALIGN_4BYTES           = 0x00300000,   // Align data on a 4-byte boundary. Valid only for object files.
    ALIGN_8BYTES           = 0x00400000,   // Align data on an 8-byte boundary. Valid only for object files.
    ALIGN_16BYTES          = 0x00500000,   // Align data on a 16-byte boundary. Valid only for object files.
    ALIGN_32BYTES          = 0x00600000,   // Align data on a 32-byte boundary. Valid only for object files.
    ALIGN_64BYTES          = 0x00700000,   // Align data on a 64-byte boundary. Valid only for object files.
    ALIGN_128BYTES         = 0x00800000,   // Align data on a 128-byte boundary. Valid only for object files.
    ALIGN_256BYTES         = 0x00900000,   // Align data on a 256-byte boundary. Valid only for object files.
    ALIGN_512BYTES         = 0x00A00000,   // Align data on a 512-byte boundary. Valid only for object files.
    ALIGN_1024BYTES        = 0x00B00000,   // Align data on a 1024-byte boundary. Valid only for object files.
    ALIGN_2048BYTES        = 0x00C00000,   // Align data on a 2048-byte boundary. Valid only for object files.
    ALIGN_4096BYTES        = 0x00D00000,   // Align data on a 4096-byte boundary. Valid only for object files.
    ALIGN_8192BYTES        = 0x00E00000,   // Align data on an 8192-byte boundary. Valid only for object files.
    LNK_NRELOC_OVFL        = (1ULL << 24), // The section contains extended relocations.
    MEM_DISCARDABLE        = (1ULL << 25), // The section can be discarded as needed.
    MEM_NOT_CACHED         = (1ULL << 26), // The section cannot be cached.
    MEM_NOT_PAGED          = (1ULL << 27), // The section is not pageable.
    MEM_SHARED             = (1ULL << 28), // The section can be shared in memory.
    MEM_EXECUTE            = (1ULL << 29), // The section can be executed as code.
    MEM_READ               = (1ULL << 30), // The section can be read.
    MEM_WRITE              = (1ULL << 31)  // The section can be written to.
};
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(SectionHeaderCharacteristicsFlags, section_header_characteristics_flags); // TEST: NO                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define SECTION_HEADER_CHARACTERISTICS_FLAG_ALIGN_BITS FLAGS( \
        SectionHeaderCharacteristicsFlag::ALIGN_BIT_0, \
        SectionHeaderCharacteristicsFlag::ALIGN_BIT_1, \
        SectionHeaderCharacteristicsFlag::ALIGN_BIT_2, \
        SectionHeaderCharacteristicsFlag::ALIGN_BIT_3 \
    )                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(SectionHeaderCharacteristicsFlag flag) // TEST: NO                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case SectionHeaderCharacteristicsFlag::NONE: return "NONE";                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(SectionHeaderCharacteristicsFlag flag) // TEST: NO                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[24];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", (section_header_characteristics_flags)flag, flagToString(flag));                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const SectionHeaderCharacteristicsFlags &characteristicsFlags) // TEST: NO                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[48];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    section_header_characteristics_flags flags = characteristicsFlags.flags & ~SECTION_HEADER_CHARACTERISTICS_FLAG_ALIGN_BITS;                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    char8 *start;                                                                                                                                                                                        // Colorize: green
    char8 *cur;                                                                                                                                                                                          // Colorize: green
    u8     unknownCount;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    __FLAGS_TO_STRING_START_PART(flags, res, cur);                                                                                                                                                       // Colorize: green
    __FLAGS_TO_STRING_COMMON_PART(start, cur, unknownCount, flags, SectionHeaderCharacteristicsFlag);                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (cur != start)                                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        cur = strapp(cur, " | ");                                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    cur = strapp(cur, flagToString(static_cast<SectionHeaderCharacteristicsFlag>(characteristicsFlags.flags & SECTION_HEADER_CHARACTERISTICS_FLAG_ALIGN_BITS)));                                         // Colorize: green
    __FLAGS_TO_STRING_END_PART(start, cur, unknownCount);                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const SectionHeaderCharacteristicsFlags &characteristicsFlags) // TEST: NO                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[48];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    section_header_characteristics_flags flags = characteristicsFlags.flags & ~SECTION_HEADER_CHARACTERISTICS_FLAG_ALIGN_BITS;                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    char8 *start;                                                                                                                                                                                        // Colorize: green
    char8 *cur;                                                                                                                                                                                          // Colorize: green
    u8     unknownCount;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    __FLAGS_TO_FULL_STRING_START_PART(flags, res, cur, "0x%08X");                                                                                                                                                  // Colorize: green
    __FLAGS_TO_STRING_COMMON_PART(start, cur, unknownCount, flags, SectionHeaderCharacteristicsFlag);                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (cur != start)                                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        cur = strapp(cur, " | ");                                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    cur = strapp(cur, flagToString(static_cast<SectionHeaderCharacteristicsFlag>(characteristicsFlags.flags & SECTION_HEADER_CHARACTERISTICS_FLAG_ALIGN_BITS)));                                         // Colorize: green
    __FLAGS_TO_FULL_STRING_END_PART(start, cur, unknownCount);                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_SECTIONHEADERCHARACTERISTICSFLAGS_H                                                                                                                 // Colorize: green
