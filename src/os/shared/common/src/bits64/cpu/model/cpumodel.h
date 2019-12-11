#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_CPUMODEL_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_CPUMODEL_H



#include <common/src/bits64/cpu/cpufamily.h>
#include <common/src/bits64/cpu/cpuvendor.h>
#include <common/src/bits64/cpu/model/amd.h>
#include <common/src/bits64/cpu/model/intel.h>
#include <ngos/types.h>



inline const char8* enumToString(CpuVendor vendor, CpuFamily family, u8 model) // TEST: NO
{
    // COMMON_LT((" | vendor = %u, family = %u, model = %u", vendor, family, model)); // Commented to avoid bad looking logs



    switch (vendor)
    {
        case CpuVendor::INTEL: return enumToString(family, (IntelCpuModel)model);
        case CpuVendor::AMD:   return enumToString(family, (AmdCpuModel)model);

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(CpuVendor vendor, CpuFamily family, u8 model) // TEST: NO
{
    // COMMON_LT((" | vendor = %u, family = %u, model = %u", vendor, family, model)); // Commented to avoid bad looking logs



    switch (vendor)
    {
        case CpuVendor::INTEL: return enumToFullString(family, (IntelCpuModel)model);
        case CpuVendor::AMD:   return enumToFullString(family, (AmdCpuModel)model);

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_CPUMODEL_H
