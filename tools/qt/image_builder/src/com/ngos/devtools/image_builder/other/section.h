#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_SECTION_H                                                                                                                                                  // Colorize: green
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_SECTION_H                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <Qt>                                                                                                                                                                                            // Colorize: green
#include <stdio.h>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class Section: quint16                                                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    RELOC,                                                                                                                                                                                               // Colorize: green
    CONFIG,                                                                                                                                                                                              // Colorize: green
    KERNEL,                                                                                                                                                                                              // Colorize: green
    MAXIMUM                                                                                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(Section section) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    switch (section)                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case Section::RELOC:   return "RELOC";                                                                                                                                                           // Colorize: green
        case Section::CONFIG:  return "CONFIG";                                                                                                                                                          // Colorize: green
        case Section::KERNEL:  return "KERNEL";                                                                                                                                                          // Colorize: green
        case Section::MAXIMUM: return "MAXIMUM";                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(Section section) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    static char8 res[22];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%04X (%s)", (quint16)section, enumToString(section));                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_SECTION_H                                                                                                                                                // Colorize: green