#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIOEMSTRINGSENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIOEMSTRINGSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>



struct DmiOemStringsEntry
{
    DmiEntryHeader header;
    u8             stringCount;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIOEMSTRINGSENTRY_H
