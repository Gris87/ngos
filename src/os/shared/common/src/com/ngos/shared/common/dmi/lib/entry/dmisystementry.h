#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemwakeuptype.h>
#include <com/ngos/shared/common/uuid/uuid.h>



struct DmiSystemEntry
{
    DmiEntryHeader header;
    DmiStringId    manufacturer;
    DmiStringId    productName;
    DmiStringId    version;
    DmiStringId    serialNumber;
} __attribute__((packed));



struct DmiSystemEntryV21: public DmiSystemEntry
{
    Uuid                uuid;
    DmiSystemWakeUpType wakeUpType;
} __attribute__((packed));



struct DmiSystemEntryV24: public DmiSystemEntryV21
{
    DmiStringId skuNumber;
    DmiStringId family;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMENTRY_H
