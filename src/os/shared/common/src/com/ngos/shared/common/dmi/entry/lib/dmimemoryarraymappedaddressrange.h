#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYARRAYMAPPEDADDRESSRANGE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYARRAYMAPPEDADDRESSRANGE_H



#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/macro/constants.h>



struct DmiMemoryArrayMappedAddressRange
{
    u64 address(u64 offset = 0)
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return ((u64)value + offset) * KB;
    }



    u32 value;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYARRAYMAPPEDADDRESSRANGE_H
