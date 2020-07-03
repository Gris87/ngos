#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>



struct DmiSystemConfigurationEntry
{
    DmiEntryHeader header;
    u8             stringCount;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H
