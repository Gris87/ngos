#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_CPUFAMILY_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_CPUFAMILY_H



#include <common/src/bits64/cpu/cpuvendor.h>
#include <ngos/types.h>



enum class CpuFamily: u16 // Ignore CppEnumVerifier
{
    NONE           = 0,
    INTEL_FAMILY_6 = 6,
    AMD_FAMILY_23  = 23
};



inline const char8* enumToString(CpuVendor vendor, CpuFamily family) // TEST: NO
{
    // COMMON_LT((" | vendor = %u, family = %u", vendor, family)); // Commented to avoid bad looking logs



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



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_CPUFAMILY_H
