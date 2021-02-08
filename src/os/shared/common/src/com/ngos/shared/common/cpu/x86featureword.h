#ifndef COM_NGOS_SHARED_COMMON_CPU_X86FEATUREWORD_H
#define COM_NGOS_SHARED_COMMON_CPU_X86FEATUREWORD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class x86FeatureWord: u8
{
    CPUID_00000001_ECX,
    CPUID_00000001_EDX,
    CPUID_00000006_EAX,
    CPUID_00000007_EBX,
    CPUID_00000007_ECX,
    CPUID_00000007_EDX,
    CPUID_0000000D_1_EAX,
    CPUID_0000000F_0_EDX,
    CPUID_0000000F_1_EDX,
    CPUID_80000001_ECX,
    CPUID_80000001_EDX,
    CPUID_80000007_EBX,
    CPUID_80000008_EBX,
    CPUID_8000000A_EDX,
    NGOS_AUXILIARY_FLAGS,
    NGOS_OTHER_FLAGS,
    MAXIMUM
};



inline const char8* enumToString(x86FeatureWord word) // TEST: NO
{
    // COMMON_LT((" | word = %u", word)); // Commented to avoid bad looking logs



    switch (word)
    {
        case x86FeatureWord::CPUID_00000001_ECX:   return "CPUID_00000001_ECX";
        case x86FeatureWord::CPUID_00000001_EDX:   return "CPUID_00000001_EDX";
        case x86FeatureWord::CPUID_00000006_EAX:   return "CPUID_00000006_EAX";
        case x86FeatureWord::CPUID_00000007_EBX:   return "CPUID_00000007_EBX";
        case x86FeatureWord::CPUID_00000007_ECX:   return "CPUID_00000007_ECX";
        case x86FeatureWord::CPUID_00000007_EDX:   return "CPUID_00000007_EDX";
        case x86FeatureWord::CPUID_0000000D_1_EAX: return "CPUID_0000000D_1_EAX";
        case x86FeatureWord::CPUID_0000000F_0_EDX: return "CPUID_0000000F_0_EDX";
        case x86FeatureWord::CPUID_0000000F_1_EDX: return "CPUID_0000000F_1_EDX";
        case x86FeatureWord::CPUID_80000001_ECX:   return "CPUID_80000001_ECX";
        case x86FeatureWord::CPUID_80000001_EDX:   return "CPUID_80000001_EDX";
        case x86FeatureWord::CPUID_80000007_EBX:   return "CPUID_80000007_EBX";
        case x86FeatureWord::CPUID_80000008_EBX:   return "CPUID_80000008_EBX";
        case x86FeatureWord::CPUID_8000000A_EDX:   return "CPUID_8000000A_EDX";
        case x86FeatureWord::NGOS_AUXILIARY_FLAGS: return "NGOS_AUXILIARY_FLAGS";
        case x86FeatureWord::NGOS_OTHER_FLAGS:     return "NGOS_OTHER_FLAGS";
        case x86FeatureWord::MAXIMUM:              return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(x86FeatureWord word) // TEST: NO
{
    // COMMON_LT((" | word = %u", word)); // Commented to avoid bad looking logs



    static char8 res[28];

    sprintf(res, "0x%02X (%s)", (u8)word, enumToString(word));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_CPU_X86FEATUREWORD_H
