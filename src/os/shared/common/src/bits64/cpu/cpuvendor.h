#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_CPUVENDOR_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_CPUVENDOR_H



#include <ngos/types.h>



enum class CpuVendor: u8
{
    NONE    = 0,
    INTEL   = 1,
    AMD     = 2,
    UNKNOWN = 3
};



inline const char* cpuVendorToString(CpuVendor vendor) // TEST: NO
{
    // COMMON_LT((" | vendor = %u", vendor)); // Commented to avoid bad looking logs



    switch (vendor)
    {
        case CpuVendor::NONE:    return "NONE";
        case CpuVendor::INTEL:   return "INTEL";
        case CpuVendor::AMD:     return "AMD";
        case CpuVendor::UNKNOWN: return "UNKNOWN";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_CPUVENDOR_H
