#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_CPUVENDOR_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_CPUVENDOR_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class CpuVendor: u8
{
    NONE    = 0,
    INTEL   = 1,
    AMD     = 2,
    UNKNOWN = 3
};



inline const char8* enumToString(CpuVendor vendor) // TEST: NO
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



inline const char8* enumToFullString(CpuVendor vendor) // TEST: NO
{
    // COMMON_LT((" | vendor = %u", vendor)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", vendor, enumToString(vendor));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_CPUVENDOR_H
