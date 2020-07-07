#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_CPUFAMILY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_CPUFAMILY_H



#include <com/ngos/shared/common/cpu/cpuvendor.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class CpuFamily: u16 // Ignore CppEnumVerifier
{
    NONE           = 0,
    INTEL_FAMILY_6 = 6,
    AMD_FAMILY_23  = 23
};



inline const char8* enumToString(CpuVendor vendor, CpuFamily family) // TEST: NO
{
    // COMMON_LT((" | vendor = %u, family = %u", vendor, family)); // Commented to avoid bad looking logs



    if (family == CpuFamily::NONE)
    {
        return "NONE";
    }



    switch (vendor)
    {
        case CpuVendor::INTEL:
        {
            switch (family)
            {
                case CpuFamily::INTEL_FAMILY_6: return "INTEL_FAMILY_6";

                default: return "UNKNOWN";
            }
        }
        break;

        case CpuVendor::AMD:
        {
            switch (family)
            {
                case CpuFamily::AMD_FAMILY_23: return "AMD_FAMILY_23";

                default: return "UNKNOWN";
            }
        }
        break;

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(CpuVendor vendor, CpuFamily family) // TEST: NO
{
    // COMMON_LT((" | vendor = %u, family = %u", vendor, family)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%04X (%s)", family, enumToString(vendor, family));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_CPUFAMILY_H
