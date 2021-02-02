#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H



#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/ngos/types.h>



struct DmiAdditionalInformation
{
    bad_uint8          entryLength;
    bad_uint16         referencedHandle;
    bad_uint8          referencedOffset;
    DmiStringId string;
    bad_uint8          value[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H
