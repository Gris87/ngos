#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H



#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/ngos/types.h>



struct DmiAdditionalInformation
{
    u8          entryLength;
    u16         referencedHandle;
    u8          referencedOffset;
    DmiStringId string;
    u8          value[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H
