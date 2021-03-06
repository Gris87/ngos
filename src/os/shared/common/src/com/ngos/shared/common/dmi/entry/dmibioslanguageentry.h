#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioslanguageflags.h>



struct DmiBiosLanguageEntry
{
    DmiEntryHeader       header;
    u8                   installableLanguages;
    DmiBiosLanguageFlags flags;
    u8                   __reserved[15];
    DmiStringId          currentLanguage;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSLANGUAGEENTRY_H
