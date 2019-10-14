#include "cpu.h"

#include <asm/bitutils.h>
#include <common/src/bits64/cpu/flags.h>
#include <common/src/bits64/cpu/generated/x86bugsnames.h>
#include <common/src/bits64/cpu/generated/x86featuresnames.h>
#include <common/src/bits64/cpu/model/amd.h>
#include <common/src/bits64/cpu/model/cpumodel.h>
#include <common/src/bits64/cpu/model/intel.h>
#include <common/src/bits64/cpu/msr/msr.h>
#include <common/src/bits64/cpu/msr/msrregisters.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>



#define VENDOR_INTEL_1 0x756E6547   // Genu
#define VENDOR_INTEL_2 0x49656E69   // ineI
#define VENDOR_INTEL_3 0x6C65746E   // ntel

#define VENDOR_AMD_1   0x68747541   // Auth
#define VENDOR_AMD_2   0x69746E65   // enti
#define VENDOR_AMD_3   0x444D4163   // cAMD

#define INTEL_MINIMAL_FAMILY (u16)CpuFamily::INTEL_FAMILY_6
#define INTEL_MINIMAL_MODEL  (u8)IntelCpuModel::FAMILY_6_HASWELL_S

#define AMD_MINIMAL_FAMILY (u16)CpuFamily::AMD_FAMILY_23
#define AMD_MINIMAL_MODEL  (u8)AmdCpuModel::FAMILY_23_NAPLES

#define CPUID_LEVEL_LOWER_BOUND     0x00000001
#define CPUID_LEVEL_UPPER_BOUND     0x0000FFFF

#define EXT_CPUID_LEVEL_LOWER_BOUND 0x80000001
#define EXT_CPUID_LEVEL_UPPER_BOUND 0x8000FFFF

#define CPUID_EAX 0
#define CPUID_EBX 1
#define CPUID_ECX 2
#define CPUID_EDX 3



u32       CPU::sVendor[3];
CpuVendor CPU::sCpuVendor;
u32       CPU::sModelName[12];
u32       CPU::sCpuidLevel;
u32       CPU::sExtendedCpuidLevel;
CpuFamily CPU::sFamily;
u8        CPU::sModel;
u8        CPU::sStepping;
u32       CPU::sMicrocodeRevision;
i8        CPU::sX86CoreIdBits;
u16       CPU::sCacheLineFlushSize;
u16       CPU::sCacheAlignment;
i32       CPU::sCacheMaxRmid;
i32       CPU::sCacheOccScale;
u32       CPU::sPower;
u8        CPU::sPhysicalBits;
u8        CPU::sVirtualBits;
u32       CPU::sFlags[(u64)x86FeatureWord::MAXIMUM];
u32       CPU::sBugs[(u64)x86BugWord::MAXIMUM];



NgosStatus CPU::init()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(initX86FeaturesNames(), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initX86BugsNames(),     NgosStatus::ASSERTION);



    sCacheLineFlushSize = 64;
    sCacheAlignment     = 64;
    sCacheMaxRmid       = -1;
    sCacheOccScale      = -1;
    sPhysicalBits       = 36;
    sVirtualBits        = 48;



    if (hasEFlag(X86_EFLAGS_ID))
    {
        COMMON_LVV(("CPUID detection available"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::CPUID), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(initCpuFeatures(),          NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_LF(("CPU didn't support CPUID"));

        return NgosStatus::NOT_SUPPORTED;
    }



    COMMON_ASSERT_EXECUTION(setFlag(X86Feature::ALWAYS),      NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initScatteredFeatures(),          NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initSpeculationControl(),         NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(doPostprocessing(),               NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(filterFeaturesDependentOnCpuid(), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initCpuBugs(),                    NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("sVendor[0]          = 0x%08X",  sVendor[0]));
        COMMON_LVVV(("sVendor[1]          = 0x%08X",  sVendor[1]));
        COMMON_LVVV(("sVendor[2]          = 0x%08X",  sVendor[2]));
        COMMON_LVVV(("sVendor             = %.12s",   sVendor));
        COMMON_LVVV(("sCpuVendor          = %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));
        COMMON_LVVV(("sModelName[0]       = 0x%08X",  sModelName[0]));
        COMMON_LVVV(("sModelName[1]       = 0x%08X",  sModelName[1]));
        COMMON_LVVV(("sModelName[2]       = 0x%08X",  sModelName[2]));
        COMMON_LVVV(("sModelName[3]       = 0x%08X",  sModelName[3]));
        COMMON_LVVV(("sModelName[4]       = 0x%08X",  sModelName[4]));
        COMMON_LVVV(("sModelName[5]       = 0x%08X",  sModelName[5]));
        COMMON_LVVV(("sModelName[6]       = 0x%08X",  sModelName[6]));
        COMMON_LVVV(("sModelName[7]       = 0x%08X",  sModelName[7]));
        COMMON_LVVV(("sModelName[8]       = 0x%08X",  sModelName[8]));
        COMMON_LVVV(("sModelName[9]       = 0x%08X",  sModelName[9]));
        COMMON_LVVV(("sModelName[10]      = 0x%08X",  sModelName[10]));
        COMMON_LVVV(("sModelName[11]      = 0x%08X",  sModelName[11]));
        COMMON_LVVV(("sModelName          = %.48s",   sModelName));
        COMMON_LVVV(("sCpuidLevel         = 0x%08X",  sCpuidLevel));
        COMMON_LVVV(("sExtendedCpuidLevel = 0x%08X",  sExtendedCpuidLevel));
        COMMON_LVVV(("sFamily             = %u (%s)", sFamily, cpuFamilyToString(sCpuVendor, sFamily)));
        COMMON_LVVV(("sModel              = %u (%s)", sModel, cpuModelToString(sCpuVendor, sFamily, sModel)));
        COMMON_LVVV(("sStepping           = %u",      sStepping));
        COMMON_LVVV(("sMicrocodeRevision  = 0x%08X",  sMicrocodeRevision));
        COMMON_LVVV(("sX86CoreIdBits      = %d",      sX86CoreIdBits));
        COMMON_LVVV(("sCacheLineFlushSize = %u",      sCacheLineFlushSize));
        COMMON_LVVV(("sCacheAlignment     = %u",      sCacheAlignment));
        COMMON_LVVV(("sCacheMaxRmid       = %d",      sCacheMaxRmid));
        COMMON_LVVV(("sCacheOccScale      = %d",      sCacheOccScale));
        COMMON_LVVV(("sPower              = %u",      sPower));
        COMMON_LVVV(("sPhysicalBits       = %u",      sPhysicalBits));
        COMMON_LVVV(("sVirtualBits        = %u",      sVirtualBits));



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            COMMON_LVVV(("CPU flags:"));

            for (i64 i = 0; i < (i64)x86FeatureWord::MAXIMUM; ++i)
            {
                COMMON_LVVV(("sFlags[%-20s] = 0x%08X", x86FeatureWordToString((x86FeatureWord)i), sFlags[i]));
            }

            COMMON_LVVV(("CPU bugs:"));

            for (i64 i = 0; i < (i64)x86BugWord::MAXIMUM; ++i)
            {
                COMMON_LVVV(("sBugs[%-17s] = 0x%08X", x86BugWordToString((x86BugWord)i), sBugs[i]));
            }
        }
#endif



        // Ignore CppAlignmentVerifier [BEGIN]
        // COMMON_TEST_ASSERT(sVendor[0]                    == 0x756E6547,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sVendor[1]                    == 0x49656E69,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sVendor[2]                    == 0x6C65746E,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(strncmp((const char8 *)sVendor, "GenuineIntel", 12) == 0,                                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sCpuVendor                    == CpuVendor::INTEL,                                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[0]                 == 0x65746E49,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[1]                 == 0x6F43206C,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[2]                 == 0x50206572,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[3]                 == 0x65636F72,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[4]                 == 0x726F7373,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[5]                 == 0x6B532820,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[6]                 == 0x6B616C79,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[7]                 == 0x00002965,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[8]                 == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[9]                 == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[10]                == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName[11]                == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(strncmp((const char8 *)sModelName, "Intel Core Processor (Skylake)", 48) == 0,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sCpuidLevel                   == 0x0000000D,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sCpuidLevel                      >= CPUID_LEVEL_LOWER_BOUND && sCpuidLevel <= CPUID_LEVEL_UPPER_BOUND,                 NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sExtendedCpuidLevel           == 0x80000008,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sExtendedCpuidLevel              >= EXT_CPUID_LEVEL_LOWER_BOUND && sExtendedCpuidLevel <= EXT_CPUID_LEVEL_UPPER_BOUND, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sFamily                       == CpuFamily::INTEL_FAMILY_6,                                                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModel                        == 94,                                                                                NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sStepping                     == 3,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMicrocodeRevision            == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sX86CoreIdBits                == 1,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sCacheLineFlushSize              == 64,                                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sCacheAlignment                  == 64,                                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sCacheMaxRmid                    == -1,                                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sCacheOccScale                   == -1,                                                                                NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sPower                        == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sPhysicalBits                 == 40,                                                                                NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sVirtualBits                  == 57,                                                                                NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)x86FeatureWord::MAXIMUM     == 16,                                                                                NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sFlags[0]                     == 0x82D82203,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[1]                     == 0x178BFBFD,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[2]                     == 0x00000004,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[3]                     == 0x00184389,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[4]                     == 0x00010000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[5]                     == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[6]                     == 0x00000005,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[7]                     == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[8]                     == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[9]                     == 0x00000021,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[10]                    == 0x28100800,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[11]                    == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[12]                    == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[13]                    == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[14]                    == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFlags[15]                    == 0x0000000D,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)x86BugWord::MAXIMUM         == 1,                                                                                 NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sBugs[0]                      == 0x0000003E,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus CPU::toString(char8 *buffer, u16 size)
{
    COMMON_LT((" | buffer = 0x%p, size = %u", buffer, size));

    COMMON_ASSERT(buffer,   "buffer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",   NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    i64 res = sprintf(buffer,
            "CPU info:\n"
            "           Vendor:                %.12s\n"
            "           CPU Family:            %u\n"
            "           Model:                 %u\n"
            "           Model name:            %.48s\n"
            "           Stepping:              %u\n"
            "           Microcode:             0x%08X\n"
            "           CPUID level:           %u\n"
            "           Cache line flush size: %u\n"
            "           Cache alignment:       %u\n"
            "           Address sizes:         %u bits physical, %u bits virtual"
            , sVendor, sFamily, sModel, sModelName, sStepping, sMicrocodeRevision, sCpuidLevel, sCacheLineFlushSize, sCacheAlignment, sPhysicalBits, sVirtualBits);
    // Ignore CppAlignmentVerifier [END]



    AVOID_UNUSED(res);
    AVOID_UNUSED(size);
    COMMON_TEST_ASSERT(res < size, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::flagsToString(char8 *buffer, u16 size)
{
    COMMON_LT((" | buffer = 0x%p, size = %u", buffer, size));

    COMMON_ASSERT(buffer,   "buffer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",   NgosStatus::ASSERTION);



    AVOID_UNUSED(size);



    u16 currentIndex = 0;

    for (i64 i = 0; i < (i64)x86FeatureWord::MAXIMUM; ++i)
    {
        u32 flag = sFlags[i];

        for (i64 j = 0; j < 32; ++j)
        {
            if (flag & (1ULL << j))
            {
                const char8 *featureName = x86FeaturesNames[WORD_BIT(i, j)];

                if (*featureName)
                {
                    if (currentIndex > 0)
                    {
                        COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);

                        buffer[currentIndex] = ' ';
                        ++currentIndex;
                    }



                    while (*featureName)
                    {
                        COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);

                        buffer[currentIndex] = *featureName;
                        ++currentIndex;
                        ++featureName;
                    }
                }
            }
        }
    }



    COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);

    buffer[currentIndex] = 0;



    return NgosStatus::OK;
}

NgosStatus CPU::bugsToString(char8 *buffer, u16 size)
{
    COMMON_LT((" | buffer = 0x%p, size = %u", buffer, size));

    COMMON_ASSERT(buffer,   "buffer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",   NgosStatus::ASSERTION);



    AVOID_UNUSED(size);



    u16 currentIndex = 0;

    for (i64 i = 0; i < (i64)x86BugWord::MAXIMUM; ++i)
    {
        u32 bug = sBugs[i];

        for (i64 j = 0; j < 32; ++j)
        {
            if (bug & (1ULL << j))
            {
                const char8 *bugName = x86BugsNames[WORD_BIT(i, j)];

                if (*bugName)
                {
                    if (currentIndex > 0)
                    {
                        COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);

                        buffer[currentIndex] = ' ';
                        ++currentIndex;
                    }



                    while (*bugName)
                    {
                        COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);

                        buffer[currentIndex] = *bugName;
                        ++currentIndex;
                        ++bugName;
                    }
                }
            }
        }
    }



    COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);

    buffer[currentIndex] = 0;



    return NgosStatus::OK;
}

NgosStatus CPU::check(const char8 **wantedFlag)
{
    COMMON_LT((" | wantedFlag = 0x%p", wantedFlag));

    COMMON_ASSERT(wantedFlag, "wantedFlag is null", NgosStatus::ASSERTION);



    X86Feature flags[] =
    {
        X86Feature::ALWAYS
        , X86Feature::CPUID
        , X86Feature::FPU
        , X86Feature::LM
        , X86Feature::MSR
        , X86Feature::PAE
        , X86Feature::NX
        , X86Feature::TSC
        , X86Feature::FXSR
        , X86Feature::XSAVE
        , X86Feature::CX8
        , X86Feature::CMOV

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        , X86Feature::LA57
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE
        , X86Feature::XMM
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE2
        , X86Feature::XMM2
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE3
        , X86Feature::XMM3
        , X86Feature::SSSE3
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE4
        , X86Feature::XMM4_1
        , X86Feature::XMM4_2
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX
        , X86Feature::AVX
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX2
        , X86Feature::AVX2
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1
        , X86Feature::AVX512F
        , X86Feature::AVX512CD
        , X86Feature::AVX512ER
        , X86Feature::AVX512PF
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2
        , X86Feature::AVX512F
        , X86Feature::AVX512CD
        , X86Feature::AVX512BW
        , X86Feature::AVX512DQ
        , X86Feature::AVX512VL
#elif NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3
        , X86Feature::AVX512F
        , X86Feature::AVX512CD
        , X86Feature::AVX512BW
        , X86Feature::AVX512DQ
        , X86Feature::AVX512VL
        , X86Feature::AVX512IFMA
        , X86Feature::AVX512VBMI
#endif



#if NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4
        , X86Feature::FMA4
#elif NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
        , X86Feature::FMA
#endif
    };



    i64 flagsCount = sizeof(flags) / sizeof(flags[0]);
    COMMON_LVVV(("flagsCount = %d", flagsCount));

    for (i64 i = 0; i < flagsCount; ++i)
    {
        X86Feature flag = flags[i];

        if (!hasFlag(flag))
        {
            *wantedFlag = x86FeaturesNames[(u64)flag];

            return NgosStatus::NOT_SUPPORTED;
        }
    }



    switch (sCpuVendor)
    {
        case CpuVendor::INTEL:
        {
            if (
                (u16)sFamily != INTEL_MINIMAL_FAMILY
                ||
                sModel < INTEL_MINIMAL_MODEL
               )
            {
                return NgosStatus::NOT_SUPPORTED;
            }
        }
        break;

        case CpuVendor::AMD:
        {
            if (
                (u16)sFamily < AMD_MINIMAL_FAMILY
                ||
                (
                 (u16)sFamily == AMD_MINIMAL_FAMILY
                 &&
                 sModel < AMD_MINIMAL_MODEL
                )
               )
            {
                return NgosStatus::NOT_SUPPORTED;
            }
        }
        break;

        case CpuVendor::NONE:
        case CpuVendor::UNKNOWN:
        {
            COMMON_LF(("Unexpected CPU vendor %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));

            return NgosStatus::NOT_SUPPORTED;
        }
        break;

        default:
        {
            COMMON_LF(("Unknown CPU vendor %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));

            return NgosStatus::NOT_SUPPORTED;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus CPU::setFlag(X86Feature flag)
{
    COMMON_LT((" | flag = 0x%04X", flag));

    COMMON_ASSERT(((u64)flag >> 5) < (u64)x86FeatureWord::MAXIMUM, "flag is invalid", NgosStatus::ASSERTION); // ">> 5" == "/ 32"



    COMMON_ASSERT_EXECUTION(BitUtils::set((u8 *)sFlags, (u64)flag), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::clearFlag(X86Feature flag)
{
    COMMON_LT((" | flag = 0x%04X", flag));

    COMMON_ASSERT(((u64)flag >> 5) < (u64)x86FeatureWord::MAXIMUM, "flag is invalid", NgosStatus::ASSERTION); // ">> 5" == "/ 32"



    COMMON_ASSERT_EXECUTION(BitUtils::clear((u8 *)sFlags, (u64)flag), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

bool CPU::hasFlag(X86Feature flag)
{
    COMMON_LT((" | flag = 0x%04X", flag));

    COMMON_ASSERT(((u64)flag >> 5) < (u64)x86FeatureWord::MAXIMUM, "flag is invalid", false); // ">> 5" == "/ 32"



    return BitUtils::test((u8 *)sFlags, (u64)flag);
}

NgosStatus CPU::setBug(X86Bug bug)
{
    COMMON_LT((" | bug = 0x%04X", bug));

    COMMON_ASSERT(((u64)bug >> 5) < (u64)x86BugWord::MAXIMUM, "bug is invalid", NgosStatus::ASSERTION); // ">> 5" == "/ 32"



    COMMON_ASSERT_EXECUTION(BitUtils::set((u8 *)sBugs, (u64)bug), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::clearBug(X86Bug bug)
{
    COMMON_LT((" | bug = 0x%04X", bug));

    COMMON_ASSERT(((u64)bug >> 5) < (u64)x86BugWord::MAXIMUM, "bug is invalid", NgosStatus::ASSERTION); // ">> 5" == "/ 32"



    COMMON_ASSERT_EXECUTION(BitUtils::clear((u8 *)sBugs, (u64)bug), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

bool CPU::hasBug(X86Bug bug)
{
    COMMON_LT((" | bug = 0x%04X", bug));

    COMMON_ASSERT(((u64)bug >> 5) < (u64)x86BugWord::MAXIMUM, "bug is invalid", false); // ">> 5" == "/ 32"



    return BitUtils::test((u8 *)sBugs, (u64)bug);
}

bool CPU::isCpuIdLevelSupported(u32 cpuidLevel)
{
    COMMON_LT((" | cpuidLevel = 0x%08X", cpuidLevel));

    COMMON_ASSERT(cpuidLevel >= CPUID_LEVEL_LOWER_BOUND && cpuidLevel <= CPUID_LEVEL_UPPER_BOUND, "cpuidLevel is invalid", false);



    return sCpuidLevel >= cpuidLevel;
}

bool CPU::hasEFlag(u64 mask)
{
    COMMON_LT((" | mask = 0x%016lX", mask));

    COMMON_ASSERT(mask > 0, "mask is zero", false);



    u64 f0 = 0;
    u64 f1 = 0;



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "pushfq"            "\n\t"      // pushfq               # Push EFLAGS to the stack
        "pushfq"            "\n\t"      // pushfq               # Push EFLAGS to the stack
        "popq    %0"        "\n\t"      // popq     %rbp        # Get EFLAGS from the stack to f0. %rbp == f0
        "movq    %0, %1"    "\n\t"      // movq     %rbp, %r12  # Store f0 to f1. %rbp == f0. %r12 == f1
        "xorq    %2, %1"    "\n\t"      // xorq     %rdi, %r12  # Xor f1 with mask. %rdi == mask. %r12 == f1
        "pushq   %1"        "\n\t"      // pushq    %r12        # Push new value for EFLAGS to stack
        "popfq"             "\n\t"      // popfq                # Set new value for EFLAGS from the stack. If EFLAGS did't support some flags they stay zero
        "pushfq"            "\n\t"      // pushfq               # Push EFLAGS to the stack
        "popq    %1"        "\n\t"      // popq     %r12        # Get EFLAGS from the stack to f1. %r12 == f1
        "popfq"                         // popfq                # Restore EFLAGS from the stack
            :                           // Output parameters
                "=&r" (f0),             // 'r' - any general register, '=' - write only, '&' - operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands
                "=&r" (f1)              // 'r' - any general register, '=' - write only, '&' - operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands
            :                           // Input parameters
                "ri" (mask)             // 'r' - any general register, or 'i' - immediate integer operand is allowed
    );
    // Ignore CppAlignmentVerifier [END]



    // Validation
    {
        COMMON_LVVV(("f0   = 0x%016lX", f0));
        COMMON_LVVV(("f1   = 0x%016lX", f1));
        COMMON_LVVV(("mask = 0x%016lX", mask));



        // COMMON_TEST_ASSERT(f0 == 0x0000000000000202, false); // Commented due to value variation
        // COMMON_TEST_ASSERT(f1 == 0x0000000000200202, false); // Commented due to value variation
        COMMON_TEST_ASSERT(mask  == 0x0000000000200000, false);
    }



    return (f0 ^ f1) == mask;
}

NgosStatus CPU::cpuid(u32 id, u32 count, u32 *a, u32 *b, u32 *c, u32 *d)
{
    COMMON_LT((" | id = 0x%08X, count = %u, a = 0x%p, b = 0x%p, c = 0x%p, d = 0x%p", id, count, a, b, c, d));

    COMMON_ASSERT(a, "a is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(b, "b is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(c, "c is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(d, "d is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "cpuid"             // cpuid    # Gets information about CPU to eax, ebx, ecx, edx
            :               // Output parameters
                "=a" (*a),  // 'a' - EAX, '=' - write only
                "=b" (*b),  // 'b' - EBX, '=' - write only
                "=c" (*c),  // 'c' - ECX, '=' - write only
                "=d" (*d)   // 'd' - EDX, '=' - write only
            :               // Input parameters
                "a" (id),   // 'a' - EAX // Ignore CppSingleCharVerifier
                "c" (count) // 'c' - ECX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus CPU::initCpuFeatures()
{
    COMMON_LT((""));



    u32 ignored;



    COMMON_ASSERT_EXECUTION(cpuid(0x00000000, 0, &sCpuidLevel, &sVendor[0], &sVendor[2], &sVendor[1]), NgosStatus::ASSERTION);

    if (sVendor[0] == VENDOR_INTEL_1 && sVendor[1] == VENDOR_INTEL_2 && sVendor[2] == VENDOR_INTEL_3)
    {
        COMMON_LVV(("Intel CPU detected"));

        sCpuVendor = CpuVendor::INTEL;
    }
    else
    if (sVendor[0] == VENDOR_AMD_1 && sVendor[1] == VENDOR_AMD_2 && sVendor[2] == VENDOR_AMD_3)
    {
        COMMON_LVV(("AMD CPU detected"));

        sCpuVendor = CpuVendor::AMD;
    }
    else
    {
        COMMON_LVV(("Unknown CPU detected"));

        sCpuVendor = CpuVendor::UNKNOWN;
    }



    // Handle general CPUID levels
    do
    {
        if (sCpuidLevel >= 0x00000001)
        {
            u32 tfms;
            u32 misc;

            COMMON_ASSERT_EXECUTION(cpuid(0x00000001, 0, &tfms, &misc, &sFlags[(u64)x86FeatureWord::CPUID_00000001_ECX], &sFlags[(u64)x86FeatureWord::CPUID_00000001_EDX]), NgosStatus::ASSERTION);



            //
            // https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits
            //
            u16 family = (tfms >> 8) & 0x0F;   // 11:8 - Family
            sModel     = (tfms >> 4) & 0x0F;   // 7:4 - Model
            sStepping  = tfms & 0x0F;          // 3:0 - Stepping

            if (family == 15)
            {
                family += (tfms >> 20) & 0xFF; // 27:20 - Extended Family
            }

            if (family >= 6)
            {
                sModel += ((tfms >> 16) & 0x0F) << 4; // 19:16 - Extended Model
            }

            sFamily = (CpuFamily)family;



            if (hasFlag(X86Feature::CLFLUSH))
            {
                COMMON_LVV(("X86Feature::CLFLUSH supported"));

                sCacheLineFlushSize = ((misc >> 8) & 0xFF) << 3; // "<< 3" == "* 8"
                sCacheAlignment     = sCacheLineFlushSize;
            }



            COMMON_ASSERT_EXECUTION(doPreprocessing(), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x00000006)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x00000006, 0, &sFlags[(u64)x86FeatureWord::CPUID_00000006_EAX], &ignored, &ignored, &ignored), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x00000007)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x00000007, 0, &ignored, &sFlags[(u64)x86FeatureWord::CPUID_00000007_EBX], &sFlags[(u64)x86FeatureWord::CPUID_00000007_ECX], &sFlags[(u64)x86FeatureWord::CPUID_00000007_EDX]), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x0000000D)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x0000000D, 1, &sFlags[(u64)x86FeatureWord::CPUID_0000000D_1_EAX], &ignored, &ignored, &ignored), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x0000000F)
        {
            i32 ebx;
            i32 ecx;

            COMMON_ASSERT_EXECUTION(cpuid(0x0000000F, 0, &ignored, (u32 *)&ebx, &ignored, &sFlags[(u64)x86FeatureWord::CPUID_0000000F_0_EDX]), NgosStatus::ASSERTION);

            if (hasFlag(X86Feature::CQM_LLC))
            {
                COMMON_LVV(("X86Feature::CQM_LLC supported"));



                sCacheMaxRmid = ebx;

                COMMON_ASSERT_EXECUTION(cpuid(0x0000000F, 1, &ignored, (u32 *)&ebx, (u32 *)&ecx, &sFlags[(u64)x86FeatureWord::CPUID_0000000F_1_EDX]), NgosStatus::ASSERTION);

                if (
                    hasFlag(X86Feature::CQM_OCCUP_LLC)
                    ||
                    hasFlag(X86Feature::CQM_MBM_TOTAL)
                    ||
                    hasFlag(X86Feature::CQM_MBM_LOCAL)
                   )
                {
                    COMMON_LVV(("X86Feature::CQM_OCCUP_LLC, X86Feature::CQM_MBM_TOTAL or X86Feature::CQM_MBM_LOCAL supported"));

                    sCacheMaxRmid  = ecx;
                    sCacheOccScale = ebx;
                }
            }
        }
        else
        {
            break;
        }

        break;
    } while(true);



    COMMON_ASSERT_EXECUTION(cpuid(0x80000000, 0, &sExtendedCpuidLevel, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);



    // Handle extended CPUID levels
    do
    {
        if (sExtendedCpuidLevel >= 0x80000001)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x80000001, 0, &ignored, &ignored, &sFlags[(u64)x86FeatureWord::CPUID_80000001_ECX], &sFlags[(u64)x86FeatureWord::CPUID_80000001_EDX]), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x80000004)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x80000002, 0, &sModelName[0], &sModelName[1], &sModelName[2],  &sModelName[3]),  NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(cpuid(0x80000003, 0, &sModelName[4], &sModelName[5], &sModelName[6],  &sModelName[7]),  NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(cpuid(0x80000004, 0, &sModelName[8], &sModelName[9], &sModelName[10], &sModelName[11]), NgosStatus::ASSERTION);



            char8 *modelStr = (char8 *)sModelName;



            i64 length = strnlen(modelStr, sizeof(sModelName));

            while (length > 0 && modelStr[length - 1] == ' ')
            {
                modelStr[length - 1] = 0;
                --length;
            }



            if (
                length > 0
                &&
                modelStr[0] == ' '
               )
            {
                i64 offset = 1;

                while (offset < length && modelStr[offset] == ' ')
                {
                    ++offset;
                }

                for (i64 i = offset; i < length; ++i)
                {
                    modelStr[i - offset] = modelStr[i];
                }

                for (i64 i = length - offset; i < length; ++i)
                {
                    modelStr[i] = 0;
                }
            }
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x80000007)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x80000007, 0, &ignored, &sFlags[(u64)x86FeatureWord::CPUID_80000007_EBX], &ignored, &sPower), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x80000008)
        {
            u32 misc;

            COMMON_ASSERT_EXECUTION(cpuid(0x80000008, 0, &misc, &sFlags[(u64)x86FeatureWord::CPUID_80000008_EBX], &ignored, &ignored), NgosStatus::ASSERTION);

            sVirtualBits  = (misc >> 8) & 0xFF;
            sPhysicalBits = misc & 0xFF;
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x8000000A)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x8000000A, 0, &ignored, &ignored, &ignored, &sFlags[(u64)x86FeatureWord::CPUID_8000000A_EDX]), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        break;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus CPU::doPreprocessing()
{
    COMMON_LT((""));



    switch (sCpuVendor)
    {
        case CpuVendor::INTEL:
        {
            COMMON_ASSERT_EXECUTION(doIntelPreprocessing(), NgosStatus::ASSERTION);
        }
        break;

        case CpuVendor::AMD:
        {
            COMMON_ASSERT_EXECUTION(doAmdPreprocessing(), NgosStatus::ASSERTION);
        }
        break;

        case CpuVendor::NONE:
        case CpuVendor::UNKNOWN:
        {
            COMMON_LF(("Unexpected CPU vendor %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));
        }
        break;

        default:
        {
            COMMON_LF(("Unknown CPU vendor %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doIntelPreprocessing()
{
    COMMON_LT((""));



    NgosStatus status = MSR::clearBit(MSR_IA32_MISC_ENABLE, MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT);

    if (status == NgosStatus::OK)
    {
        COMMON_LVV(("MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT successfully cleared"));
    }
    else
    if (status == NgosStatus::NO_EFFECT)
    {
        COMMON_LVV(("MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT already cleared"));
    }
    else
    {
        COMMON_LF(("Failed to reset MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT"));

        return NgosStatus::FAILED;
    }



    status = MSR::clearBit(MSR_IA32_MISC_ENABLE, MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT);

    if (status == NgosStatus::OK)
    {
        COMMON_LVV(("MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT successfully cleared"));
        COMMON_LVV(("Updating CPUID level"));

        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(0x00000000, 0, &sCpuidLevel, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);
    }
    else
    if (status == NgosStatus::NO_EFFECT)
    {
        COMMON_LVV(("MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT already cleared"));
    }
    else
    {
        COMMON_LF(("Failed to reset MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT"));

        return NgosStatus::FAILED;
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doAmdPreprocessing()
{
    COMMON_LT((""));



    return NgosStatus::OK;
}

NgosStatus CPU::initScatteredFeatures()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::APERFMPERF,    CPUID_ECX, 0,  0x00000006, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::EPB,           CPUID_ECX, 3,  0x00000006, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CAT_L3,        CPUID_EBX, 1,  0x00000010, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CAT_L2,        CPUID_EBX, 2,  0x00000010, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CDP_L3,        CPUID_ECX, 2,  0x00000010, 1), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CDP_L2,        CPUID_ECX, 2,  0x00000010, 2), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::MBA,           CPUID_EBX, 3,  0x00000010, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::HW_PSTATE,     CPUID_EDX, 7,  0x80000007, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CPB,           CPUID_EDX, 9,  0x80000007, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::PROC_FEEDBACK, CPUID_EDX, 11, 0x80000007, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::SME,           CPUID_EAX, 0,  0x8000001F, 0), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::SEV,           CPUID_EAX, 1,  0x8000001F, 0), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::setScatteredFeature(X86Feature feature, u8 registerId, u8 bit, u32 level, u32 count)
{
    COMMON_LT((" | feature = 0x%04X, registerId = %u, bit = %u, level = %u, count = %u", feature, registerId, bit, level, count));

    COMMON_ASSERT(registerId < 4, "registerId is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 32,       "bit is invalid",        NgosStatus::ASSERTION);
    COMMON_ASSERT(level > 0,      "level is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(count <= 2,     "count is invalid",      NgosStatus::ASSERTION);



    u32 maximumLevel;
    u32 ignored;
    u32 registers[4];

    COMMON_ASSERT_EXECUTION(cpuid(level & 0xFFFF0000, 0, &maximumLevel, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);



    if (maximumLevel >= level)
    {
        COMMON_TEST_ASSERT(maximumLevel >= (level & 0xFFFF0000) && maximumLevel <= (level | 0xFFFF), NgosStatus::ASSERTION)

        COMMON_ASSERT_EXECUTION(cpuid(level, count, &registers[0], &registers[1], &registers[2], &registers[3]), NgosStatus::ASSERTION);



        if (registers[registerId] & (1ULL << bit))
        {
            COMMON_ASSERT_EXECUTION(setFlag(feature), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus CPU::initSpeculationControl()
{
    COMMON_LT((""));



    if (hasFlag(X86Feature::SPEC_CTRL))
    {
        COMMON_LVV(("X86Feature::SPEC_CTRL supported"));
        COMMON_LVV(("X86Feature::IBRS set because X86Feature::SPEC_CTRL supported"));
        COMMON_LVV(("X86Feature::IBPB set because X86Feature::SPEC_CTRL supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::SPEC_CTRL supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::IBRS),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::IBPB),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::INTEL_STIBP))
    {
        COMMON_LVV(("X86Feature::INTEL_STIBP supported"));
        COMMON_LVV(("X86Feature::STIBP set because X86Feature::INTEL_STIBP supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::STIBP), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::SPEC_CTRL_SSBD) || hasFlag(X86Feature::VIRT_SSBD))
    {
        COMMON_LVV(("X86Feature::SPEC_CTRL_SSBD or X86Feature::VIRT_SSBD supported"));
        COMMON_LVV(("X86Feature::SSBD set because X86Feature::SPEC_CTRL_SSBD supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::SSBD), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::AMD_IBRS))
    {
        COMMON_LVV(("X86Feature::AMD_IBRS supported"));
        COMMON_LVV(("X86Feature::IBRS set because X86Feature::AMD_IBRS supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_IBRS supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::IBRS),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::AMD_IBPB))
    {
        COMMON_LVV(("X86Feature::AMD_IBPB supported"));
        COMMON_LVV(("X86Feature::IBPB set because X86Feature::AMD_IBPB supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::IBPB), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::AMD_STIBP))
    {
        COMMON_LVV(("X86Feature::AMD_STIBP supported"));
        COMMON_LVV(("X86Feature::STIBP set because X86Feature::AMD_STIBP supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_STIBP supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::STIBP),         NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::AMD_SSBD))
    {
        COMMON_LVV(("X86Feature::AMD_SSBD supported"));
        COMMON_LVV(("X86Feature::SSBD set because X86Feature::AMD_SSBD supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_SSBD supported"));
        COMMON_LVV(("X86Feature::VIRT_SSBD resetted because X86Feature::AMD_SSBD supported"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::SSBD),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::VIRT_SSBD),   NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doPostprocessing()
{
    COMMON_LT((""));



    switch (sCpuVendor)
    {
        case CpuVendor::INTEL:
        {
            COMMON_ASSERT_EXECUTION(doIntelPostprocessing(), NgosStatus::ASSERTION);
        }
        break;

        case CpuVendor::AMD:
        {
            COMMON_ASSERT_EXECUTION(doAmdPostprocessing(), NgosStatus::ASSERTION);
        }
        break;

        case CpuVendor::NONE:
        case CpuVendor::UNKNOWN:
        {
            COMMON_LF(("Unexpected CPU vendor %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));
        }
        break;

        default:
        {
            COMMON_LF(("Unknown CPU vendor %u (%s)", sCpuVendor, cpuVendorToString(sCpuVendor)));
        }
        break;
    }



    NgosStatus status = MSR::setBit(MSR_EFER, MSR_EFER_SCE_BIT);

    if (status == NgosStatus::OK)
    {
        COMMON_LVV(("MSR_EFER_SCE_BIT successfully set"));
    }
    else
    if (status == NgosStatus::NO_EFFECT)
    {
        COMMON_LVV(("MSR_EFER_SCE_BIT already set"));
    }
    else
    {
        COMMON_LF(("Failed to set MSR_EFER_SCE_BIT"));

        return NgosStatus::FAILED;
    }



    if (hasFlag(X86Feature::NX))
    {
        COMMON_LVV(("X86Feature::NX supported"));



        status = MSR::setBit(MSR_EFER, MSR_EFER_NX_BIT);

        if (status == NgosStatus::OK)
        {
            COMMON_LVV(("MSR_EFER_NX_BIT successfully set"));
        }
        else
        if (status == NgosStatus::NO_EFFECT)
        {
            COMMON_LVV(("MSR_EFER_NX_BIT already set"));
        }
        else
        {
            COMMON_LF(("Failed to set MSR_EFER_NX_BIT"));

            return NgosStatus::FAILED;
        }
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doIntelPostprocessing()
{
    COMMON_LT((""));



    COMMON_LVV(("X86Feature::CONSTANT_TSC supported"));

    COMMON_ASSERT_EXECUTION(setFlag(X86Feature::CONSTANT_TSC), NgosStatus::ASSERTION);



    if (!hasFlag(X86Feature::IA64))
    {
        COMMON_LVV(("Getting microcode revision since X86Feature::IA64 not supported"));

        COMMON_ASSERT_EXECUTION(getIntelMicrocodeRevision(), NgosStatus::ASSERTION);
    }



    // Early microcode releases for the Spectre v2 mitigation were broken. Therefore we are disabling Speculation Control in the case
    if (
        (
         hasFlag(X86Feature::IBRS)
         ||
         hasFlag(X86Feature::IBPB)
         ||
         hasFlag(X86Feature::STIBP)
         ||
         hasFlag(X86Feature::INTEL_STIBP)
         ||
         hasFlag(X86Feature::SPEC_CTRL)
        )
        &&
        isIntelBadSpectreMicrocode()
       )
    {
        COMMON_LVV(("X86Feature::IBRS, X86Feature::IBPB, X86Feature::STIBP, X86Feature::INTEL_STIBP or X86Feature::SPEC_CTRL supported"));
        COMMON_LW(("Intel Spectre v2 broken microcode detected; disabling Speculation Control"));

        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::IBRS),           NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::IBPB),           NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::STIBP),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::INTEL_STIBP),    NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::SPEC_CTRL),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::MSR_SPEC_CTRL),  NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::SSBD),           NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::SPEC_CTRL_SSBD), NgosStatus::ASSERTION);
    }



    // Bit 8 in cpuid 0x80000007 EDX means that TSC runs at constant rate with P/T states and does not stop in deep C-states.
    if (sPower & (1ULL << 8))
    {
        COMMON_LVV(("X86Feature::CONSTANT_TSC and X86Feature::NONSTOP_TSC supported due to bit 8 in cpuid 0x80000007 EDX"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::CONSTANT_TSC), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::NONSTOP_TSC),  NgosStatus::ASSERTION);
    }



    if (!MSR::testBit(MSR_IA32_MISC_ENABLE, MSR_IA32_MISC_ENABLE_FAST_STRING_BIT))
    {
        COMMON_LW(("Fast string operations disabled in MSR"));
        COMMON_LVV(("X86Feature::ERMS resetted because fast string operations disabled in MSR"));

        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::ERMS), NgosStatus::ASSERTION);
    }



    if (hasFlag(X86Feature::HT))
    {
        COMMON_LVV(("X86Feature::HT supported"));



        u32 ebx;
        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(0x00000001, 0, &ignored, &ebx, &ignored, &ignored), NgosStatus::ASSERTION);

        // If Hyper-Threading is set EBX[16:23] in cpuid 0x00000001 contain the number of
        // apicids which are reserved per package. Store the resulting
        // shift value for the package management code.
        u8 threadsPerCore = ebx >> 16;

        COMMON_LVVV(("threadsPerCore = %u", threadsPerCore));

        sX86CoreIdBits = BitUtils::getCountOrder16(threadsPerCore);
    }



    if (hasFlag(X86Feature::MPX) && !hasFlag(X86Feature::SMEP))
    {
        COMMON_LW(("X86Feature::MPX resetted because X86Feature::SMEP not supported"));

        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::MPX), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doAmdPostprocessing()
{
    COMMON_LT((""));



    return NgosStatus::OK;
}

NgosStatus CPU::filterFeaturesDependentOnCpuid()
{
    COMMON_LT((""));



    if (hasFlag(X86Feature::MWAIT) && sCpuidLevel < 0x00000005)
    {
        COMMON_LW(("X86Feature::MWAIT resetted because sCpuidLevel < 0x00000005"));

        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::MWAIT), NgosStatus::ASSERTION);
    }

    if (hasFlag(X86Feature::DCA) && sCpuidLevel < 0x00000009)
    {
        COMMON_LW(("X86Feature::DCA resetted because sCpuidLevel < 0x00000009"));

        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::DCA), NgosStatus::ASSERTION);
    }

    if (hasFlag(X86Feature::XSAVE) && sCpuidLevel < 0x0000000D)
    {
        COMMON_LW(("X86Feature::XSAVE resetted because sCpuidLevel < 0x0000000D"));

        COMMON_ASSERT_EXECUTION(clearFlag(X86Feature::XSAVE), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CPU::initCpuBugs()
{
    COMMON_LT((""));



    if (isCpuNoSpeculation())
    {
        COMMON_LVV(("CPU is not affected by Spectre attack"));

        return NgosStatus::OK;
    }



    COMMON_LVV(("X86Bug::SPECTRE_V1 and X86Bug::SPECTRE_V2 set because CPU is affected by Spectre attack"));

    COMMON_ASSERT_EXECUTION(setBug(X86Bug::SPECTRE_V1), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(setBug(X86Bug::SPECTRE_V2), NgosStatus::ASSERTION);



    u64 ia32Capabilities = 0;

    if (hasFlag(X86Feature::ARCH_CAPABILITIES))
    {
        COMMON_LVV(("X86Feature::ARCH_CAPABILITIES supported"));

        ia32Capabilities = MSR::read(MSR_IA32_ARCH_CAPABILITIES);

        COMMON_LVVV(("ia32Capabilities = 0x%016lX", ia32Capabilities));
    }



    if (
        !isCpuNoSpecStoreBypass()
        &&
        !(ia32Capabilities & MSR_IA32_ARCH_CAPABILITIES_SSB_NO)
        &&
        !hasFlag(X86Feature::AMD_SSB_NO)
       )
    {
        COMMON_LVV(("X86Bug::SPEC_STORE_BYPASS set because CPU is affected by speculative store bypass attack"));

        COMMON_ASSERT_EXECUTION(setBug(X86Bug::SPEC_STORE_BYPASS), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_LVV(("CPU is not affected by speculative store bypass attack"));
    }



    if (ia32Capabilities & MSR_IA32_ARCH_CAPABILITIES_IBRS_ALL)
    {
        COMMON_LVV(("X86Feature::IBRS_ENHANCED set because MSR_IA32_ARCH_CAPABILITIES_IBRS_ALL found"));

        COMMON_ASSERT_EXECUTION(setFlag(X86Feature::IBRS_ENHANCED), NgosStatus::ASSERTION);
    }



    if (
        isCpuNoMeltdown()
        ||
        ia32Capabilities & MSR_IA32_ARCH_CAPABILITIES_RDCL_NO
       )
    {
        COMMON_LVV(("CPU is not affected by meltdown attack"));

        return NgosStatus::OK;
    }



    COMMON_LVV(("X86Bug::CPU_MELTDOWN set because CPU is affected by meltdown attack"));

    COMMON_ASSERT_EXECUTION(setBug(X86Bug::CPU_MELTDOWN), NgosStatus::ASSERTION);



    if (isCpuNoL1TF())
    {
        COMMON_LVV(("CPU is not affected by L1 Terminal Fault"));

        return NgosStatus::OK;
    }



    COMMON_LVV(("X86Bug::L1TF set because CPU is affected by L1 Terminal Fault"));

    COMMON_ASSERT_EXECUTION(setBug(X86Bug::L1TF), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::getIntelMicrocodeRevision()
{
    COMMON_LT((""));



    u32 ignored;



    COMMON_ASSERT_EXECUTION(MSR::write(MSR_IA32_MICROCODE_REV, 0), NgosStatus::ASSERTION);

    // Call cpuid with 0x00000001 to trigger microcode revision refresh
    COMMON_ASSERT_EXECUTION(cpuid(0x00000001, 0, &ignored, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);

    sMicrocodeRevision = (u32)(MSR::read(MSR_IA32_MICROCODE_REV) >> 32);



    return NgosStatus::OK;
}

bool CPU::isIntelBadSpectreMicrocode()
{
    COMMON_LT((""));



    // hypervisor lie to us on the microcode version so
    // we may as well hope that it is running the correct version.
    if (hasFlag(X86Feature::HYPERVISOR))
    {
        COMMON_LVV(("X86Feature::HYPERVISOR supported"));

        return false;
    }



    return (
            (
                sModel == (u8)IntelCpuModel::FAMILY_6_SKYLAKE_SERVER
                &&
                (
                    (
                        sStepping == 0x03
                        &&
                        sMicrocodeRevision <= 0x0100013E
                    )
                    ||
                    (
                        sStepping == 0x04
                        &&
                        sMicrocodeRevision <= 0x0200003C
                    )
                )
            )



            ||



            (
                sModel == (u8)IntelCpuModel::FAMILY_6_KABY_LAKE_Y_U
                &&
                (
                    (
                        sStepping == 0x09
                        &&
                        sMicrocodeRevision <= 0x80
                    )
                    ||
                    (
                        sStepping == 0x0A
                        &&
                        sMicrocodeRevision <= 0x80
                    )
                )
            )



            ||



            (
                sModel == (u8)IntelCpuModel::FAMILY_6_KABY_LAKE_DT_H_S_X
                &&
                (
                    (
                        sStepping == 0x09
                        &&
                        sMicrocodeRevision <= 0x80
                    )
                    ||
                    (
                        sStepping == 0x0A
                        &&
                        sMicrocodeRevision <= 0x80
                    )
                    ||
                    (
                        sStepping == 0x0B
                        &&
                        sMicrocodeRevision <= 0x80
                    )
                )
            )
        );
}

bool CPU::isCpuNoSpeculation()
{
    COMMON_LT((""));



    return false;
}

bool CPU::isCpuNoMeltdown()
{
    COMMON_LT((""));



    return sCpuVendor == CpuVendor::AMD;
}

bool CPU::isCpuNoSpecStoreBypass()
{
    COMMON_LT((""));



    return (
            (
                sCpuVendor == CpuVendor::INTEL
                &&
                sFamily == CpuFamily::INTEL_FAMILY_6
                &&
                (
                    sModel == (u8)IntelCpuModel::FAMILY_6_KNIGHTS_LANDING
                    ||
                    sModel == (u8)IntelCpuModel::FAMILY_6_KNIGHTS_MILL
                )
            )
        );
}

bool CPU::isCpuNoL1TF()
{
    COMMON_LT((""));



    return (
            (
                sCpuVendor == CpuVendor::INTEL
                &&
                sFamily == CpuFamily::INTEL_FAMILY_6
                &&
                (
                    sModel == (u8)IntelCpuModel::FAMILY_6_AIRMONT_MID
                    ||
                    sModel == (u8)IntelCpuModel::FAMILY_6_APOLLO_LAKE
                    ||
                    sModel == (u8)IntelCpuModel::FAMILY_6_DENVERTON
                    ||
                    sModel == (u8)IntelCpuModel::FAMILY_6_GEMINI_LAKE
                    ||
                    sModel == (u8)IntelCpuModel::FAMILY_6_KNIGHTS_LANDING
                    ||
                    sModel == (u8)IntelCpuModel::FAMILY_6_KNIGHTS_MILL
                )
            )
        );
}
