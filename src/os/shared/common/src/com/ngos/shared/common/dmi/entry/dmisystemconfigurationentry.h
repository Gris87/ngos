#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>



struct DmiSystemConfigurationEntry
{
    DmiEntryHeader header;
    u8             stringCount;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H
