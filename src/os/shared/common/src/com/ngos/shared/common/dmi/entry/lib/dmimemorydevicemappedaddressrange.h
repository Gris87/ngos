#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEMAPPEDADDRESSRANGE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEMAPPEDADDRESSRANGE_H



#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiMemoryDeviceMappedAddressRange
{
    bad_uint64 address(bad_uint64 offset = 0)
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return ((bad_uint64)value + offset) * KB;
    }



    bad_uint32 value;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEMAPPEDADDRESSRANGE_H
