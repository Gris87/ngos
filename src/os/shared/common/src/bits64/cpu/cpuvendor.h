#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_CPUVENDOR_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_CPUVENDOR_H



#include <ngos/types.h>



enum class CpuVendor: u8
{
    NONE,
    INTEL,
    AMD,
    UNKNOWN
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_CPUVENDOR_H
