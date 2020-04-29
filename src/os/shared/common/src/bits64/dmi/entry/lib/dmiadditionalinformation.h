#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H



#include <common/src/bits64/dmi/dmistringid.h>
#include <ngos/types.h>



struct DmiAdditionalInformation
{
    u8          entryLength;
    u16         referencedHandle;
    u8          referencedOffset;
    DmiStringId string;
    u8          value[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIADDITIONALINFORMATION_H
