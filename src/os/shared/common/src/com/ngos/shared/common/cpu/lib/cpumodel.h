#ifndef COM_NGOS_SHARED_COMMON_CPU_MODEL_CPUMODEL_H                                                                                                                                                      // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_MODEL_CPUMODEL_H                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpufamily.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuvendor.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/amdcpumodel.h>                                                                                                                                                // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/intelcpumodel.h>                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const good_Char8* enumToString(CpuVendor vendor, CpuFamily family, good_U8 model) // TEST: NO                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | vendor = %u, family = %u, model = %u", vendor, family, model)); // Commented to avoid bad looking logs                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (vendor)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuVendor::INTEL: return enumToString(family, static_cast<IntelCpuModel>(model));                                                                                                           // Colorize: green
        case CpuVendor::AMD:   return enumToString(family, static_cast<AmdCpuModel>(model));                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const good_Char8* enumToFullString(CpuVendor vendor, CpuFamily family, good_U8 model) // TEST: NO                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | vendor = %u, family = %u, model = %u", vendor, family, model)); // Commented to avoid bad looking logs                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (vendor)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuVendor::INTEL: return enumToFullString(family, static_cast<IntelCpuModel>(model));                                                                                                       // Colorize: green
        case CpuVendor::AMD:   return enumToFullString(family, static_cast<AmdCpuModel>(model));                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_MODEL_CPUMODEL_H                                                                                                                                                    // Colorize: green
