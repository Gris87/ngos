#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmibioslanguageflags.h>



struct DmiBiosLanguageEntry
{
    DmiEntryHeader       header;
    u8                   installableLanguages;
    DmiBiosLanguageFlags flags;
    u8                   __reserved[15];
    u8                   currentLanguageStringId;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H
