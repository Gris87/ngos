#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_CPUMODEL_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_CPUMODEL_H



#include <common/src/bits64/cpu/cpufamily.h>
#include <common/src/bits64/cpu/cpuvendor.h>
#include <common/src/bits64/cpu/model/amd.h>
#include <common/src/bits64/cpu/model/intel.h>
#include <ngos/types.h>



inline const char* cpuModelToString(CpuVendor vendor, CpuFamily family, u8 model) // TEST: NO
{
    // COMMON_LT((" | vendor = %u, family = %u, model = %u", vendor, family, model)); // Commented to avoid bad looking logs



    switch (vendor)
    {
        case CpuVendor::INTEL: return intelCpuModelToString(family, (IntelCpuModel)model);
        case CpuVendor::AMD:   return amdCpuModelToString(family, (AmdCpuModel)model);

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_CPUMODEL_H
