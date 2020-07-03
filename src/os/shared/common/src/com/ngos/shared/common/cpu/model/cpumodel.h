#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_MODEL_CPUMODEL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_MODEL_CPUMODEL_H



#include <com/ngos/shared/common/cpu/cpufamily.h>
#include <com/ngos/shared/common/cpu/cpuvendor.h>
#include <com/ngos/shared/common/cpu/model/amdcpumodel.h>
#include <com/ngos/shared/common/cpu/model/intelcpumodel.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_MODEL_CPUMODEL_H
