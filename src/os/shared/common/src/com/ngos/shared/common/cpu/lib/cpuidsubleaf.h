#ifndef COM_NGOS_SHARED_COMMON_CPU_CPUIDSUBLEAF_H                                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_CPUIDSUBLEAF_H                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuidleaf.h>                                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class CpuidSubLeaf: good_U32 // Ignore CppEnumVerifier                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NO_SUBLEAF = 0,

    //
    // CpuidLeaf::XSAVE_FEATURES
    //

    XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_0 = 0,
    XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_1 = 1,
    XSAVE_FEATURES_AVX                                    = 2,
    XSAVE_FEATURES_MPX_BOUND_REGISTERS                    = 3,
    XSAVE_FEATURES_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS  = 4,
    XSAVE_FEATURES_AVX512_OPMASK                          = 5,
    XSAVE_FEATURES_AVX512_ZMM_FROM_0_TO_15                = 6,
    XSAVE_FEATURES_AVX512_ZMM_FROM_16_TO_31               = 7,
    XSAVE_FEATURES_PT                                     = 8,
    XSAVE_FEATURES_PKRU                                   = 9
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(CpuidLeaf leaf, CpuidSubLeaf subLeaf) // TEST: NO                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | leaf = %u, subLeaf = %u", leaf, subLeaf)); // Commented to avoid bad looking logs                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (leaf)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuidLeaf::XSAVE_FEATURES:                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            switch (subLeaf)                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_0: return "XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_0";                                                // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_1: return "XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_1";                                                // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_AVX:                                    return "XSAVE_FEATURES_AVX";                                                                                   // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_MPX_BOUND_REGISTERS:                    return "XSAVE_FEATURES_MPX_BOUND_REGISTERS";                                                                   // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS:  return "XSAVE_FEATURES_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS";                                                 // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_AVX512_OPMASK:                          return "XSAVE_FEATURES_AVX512_OPMASK";                                                                         // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_AVX512_ZMM_FROM_0_TO_15:                return "XSAVE_FEATURES_AVX512_ZMM_FROM_0_TO_15";                                                               // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_AVX512_ZMM_FROM_16_TO_31:               return "XSAVE_FEATURES_AVX512_ZMM_FROM_16_TO_31";                                                              // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_PT:                                     return "XSAVE_FEATURES_PT";                                                                                    // Colorize: green
                case CpuidSubLeaf::XSAVE_FEATURES_PKRU:                                   return "XSAVE_FEATURES_PKRU";                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                default: return "UNKNOWN";                                                                                                                                                               // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default:                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            switch (subLeaf)                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                case CpuidSubLeaf::NO_SUBLEAF: return "NO_SUBLEAF";                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                default: return "UNKNOWN";                                                                                                                                                               // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(CpuidLeaf leaf, CpuidSubLeaf subLeaf) // TEST: NO                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | leaf = %u, subLeaf = %u", leaf, subLeaf)); // Commented to avoid bad looking logs                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[50];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", static_cast<good_U32>(subLeaf), enumToString(leaf, subLeaf));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_CPUIDSUBLEAF_H                                                                                                                                                         // Colorize: green
