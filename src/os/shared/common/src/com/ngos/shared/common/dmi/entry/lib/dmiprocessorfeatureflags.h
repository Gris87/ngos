#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFEATUREFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFEATUREFLAGS_H



#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#include <common/src/com/ngos/shared/common/ngos/flags.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



typedef u32 dmi_processor_feature_flags;

enum class DmiProcessorFeatureFlag: dmi_processor_feature_flags
{
    NONE      = 0,
    FPU       = (1ULL << 0),
    VME       = (1ULL << 1),
    DE        = (1ULL << 2),
    PSE       = (1ULL << 3),
    TSC       = (1ULL << 4),
    MSR       = (1ULL << 5),
    PAE       = (1ULL << 6),
    MCE       = (1ULL << 7),
    CX8       = (1ULL << 8),
    APIC      = (1ULL << 9),
    SEP       = (1ULL << 11),
    MTRR      = (1ULL << 12),
    PGE       = (1ULL << 13),
    MCA       = (1ULL << 14),
    CMOV      = (1ULL << 15),
    PAT       = (1ULL << 16),
    PSE36     = (1ULL << 17),
    PN        = (1ULL << 18),
    CLFLUSH   = (1ULL << 19),
    DS        = (1ULL << 21),
    ACPI      = (1ULL << 22),
    MMX       = (1ULL << 23),
    FXSR      = (1ULL << 24),
    SSE       = (1ULL << 25),
    SSE2      = (1ULL << 26),
    SELFSNOOP = (1ULL << 27),
    HT        = (1ULL << 28),
    TM        = (1ULL << 29),
    IA64      = (1ULL << 30),
    PBE       = (1ULL << 31)
};

DEFINE_FLAGS(DmiProcessorFeatureFlags, dmi_processor_feature_flags); // TEST: NO



inline const char8* flagToString(DmiProcessorFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiProcessorFeatureFlag::NONE:      return "NONE";
        case DmiProcessorFeatureFlag::FPU:       return "FPU";
        case DmiProcessorFeatureFlag::VME:       return "VME";
        case DmiProcessorFeatureFlag::DE:        return "DE";
        case DmiProcessorFeatureFlag::PSE:       return "PSE";
        case DmiProcessorFeatureFlag::TSC:       return "TSC";
        case DmiProcessorFeatureFlag::MSR:       return "MSR";
        case DmiProcessorFeatureFlag::PAE:       return "PAE";
        case DmiProcessorFeatureFlag::MCE:       return "MCE";
        case DmiProcessorFeatureFlag::CX8:       return "CX8";
        case DmiProcessorFeatureFlag::APIC:      return "APIC";
        case DmiProcessorFeatureFlag::SEP:       return "SEP";
        case DmiProcessorFeatureFlag::MTRR:      return "MTRR";
        case DmiProcessorFeatureFlag::PGE:       return "PGE";
        case DmiProcessorFeatureFlag::MCA:       return "MCA";
        case DmiProcessorFeatureFlag::CMOV:      return "CMOV";
        case DmiProcessorFeatureFlag::PAT:       return "PAT";
        case DmiProcessorFeatureFlag::PSE36:     return "PSE36";
        case DmiProcessorFeatureFlag::PN:        return "PN";
        case DmiProcessorFeatureFlag::CLFLUSH:   return "CLFLUSH";
        case DmiProcessorFeatureFlag::DS:        return "DS";
        case DmiProcessorFeatureFlag::ACPI:      return "ACPI";
        case DmiProcessorFeatureFlag::MMX:       return "MMX";
        case DmiProcessorFeatureFlag::FXSR:      return "FXSR";
        case DmiProcessorFeatureFlag::SSE:       return "SSE";
        case DmiProcessorFeatureFlag::SSE2:      return "SSE2";
        case DmiProcessorFeatureFlag::SELFSNOOP: return "SELFSNOOP";
        case DmiProcessorFeatureFlag::HT:        return "HT";
        case DmiProcessorFeatureFlag::TM:        return "TM";
        case DmiProcessorFeatureFlag::IA64:      return "IA64";
        case DmiProcessorFeatureFlag::PBE:       return "PBE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiProcessorFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiProcessorFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[207];

    FLAGS_TO_STRING(res, flags.flags, DmiProcessorFeatureFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiProcessorFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[220];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiProcessorFeatureFlag, "0x%08X");

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFEATUREFLAGS_H
