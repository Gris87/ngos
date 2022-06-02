#ifndef COM_NGOS_SHARED_COMMON_DMI_DMIENTRYHEADER_H
#define COM_NGOS_SHARED_COMMON_DMI_DMIENTRYHEADER_H



#include <com/ngos/shared/common/dmi/dmientrytype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct DmiEntryHeader
{
    DmiEntryType type;
    u8           length;
    u16          handle;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_DMIENTRYHEADER_H
