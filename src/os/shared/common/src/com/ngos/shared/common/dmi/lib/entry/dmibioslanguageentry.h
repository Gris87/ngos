#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H                                                                                                                                          // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibioslanguageflags.h>                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiBiosLanguageEntry                                                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader       header;                                                                                                                                                                         // Colorize: green
    u8                   installableLanguages;                                                                                                                                                           // Colorize: green
    DmiBiosLanguageFlags flags;                                                                                                                                                                          // Colorize: green
    u8                   __reserved[15];                                                                                                                                                                 // Colorize: green
    DmiStringId          currentLanguage;                                                                                                                                                                // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H                                                                                                                                        // Colorize: green
