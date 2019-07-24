#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_CPUFAMILY_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_CPUFAMILY_H



#include <ngos/types.h>



enum class CpuFamily: u16
{
    NONE           = 0,
    INTEL_FAMILY_6 = 6,
    AMD_FAMILY_23  = 23
};



inline const char* cpuFamilyToString(CpuFamily family) // TEST: NO
{
    // COMMON_LT((" | family = %u", family)); // Commented to avoid bad looking logs



    switch (family)
    {
        case CpuFamily::NONE:           return "NONE";
        case CpuFamily::INTEL_FAMILY_6: return "INTEL_FAMILY_6";
        case CpuFamily::AMD_FAMILY_23:  return "AMD_FAMILY_23";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_CPUFAMILY_H
