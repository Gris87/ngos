#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H



#include <common/src/bits64/log/log.h>
#include <macro/constants.h>



struct DmiPhysicalMemoryArrayMaximumCapacity
{
    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (u64)value * KB;
    }



    u32 value;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H