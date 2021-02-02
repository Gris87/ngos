#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H



#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiPhysicalMemoryArrayMaximumCapacity
{
    bad_uint64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (bad_uint64)value * KB;
    }



    bad_uint32 value;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
