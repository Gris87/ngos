#include "cpu.h"                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/asm/bitutils.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/registers/x86flags.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/x86bugsnames.h>                                                                                                                                       // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/x86featuresnames.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/amdcpumodel.h>                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpumodel.h>                                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/intelcpumodel.h>                                                                                                                                      // Colorize: green
#include <com/ngos/shared/common/msr/msr.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/msr/msrregisters.h>                                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/linkage.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/string/string.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define INTEL_MINIMAL_FAMILY static_cast<good_U16>(CpuFamily::INTEL_FAMILY_6)                                                                                                                            // Colorize: green
#define INTEL_MINIMAL_MODEL  static_cast<good_U8>(IntelCpuModel::FAMILY_6_HASWELL_CLIENT_S)                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define AMD_MINIMAL_FAMILY static_cast<good_U16>(CpuFamily::AMD_FAMILY_23)                                                                                                                               // Colorize: green
#define AMD_MINIMAL_MODEL  static_cast<good_U8>(AmdCpuModel::FAMILY_23_NAPLES)                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define CPUID_LEVEL_LOWER_BOUND     0x00000001                                                                                                                                                           // Colorize: green
#define CPUID_LEVEL_UPPER_BOUND     0x0000FFFF                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define EXT_CPUID_LEVEL_LOWER_BOUND 0x80000001                                                                                                                                                           // Colorize: green
#define EXT_CPUID_LEVEL_UPPER_BOUND 0x8000FFFF                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define CPUID_EAX 0                                                                                                                                                                                      // Colorize: green
#define CPUID_EBX 1                                                                                                                                                                                      // Colorize: green
#define CPUID_ECX 2                                                                                                                                                                                      // Colorize: green
#define CPUID_EDX 3                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CpuidVendor    CPU::sVendor;                                                                                                                                                                             // Colorize: green
CpuVendor      CPU::sCpuVendor;                                                                                                                                                                          // Colorize: green
CpuidModelName CPU::sModelName;                                                                                                                                                                          // Colorize: green
u32            CPU::sCpuidLevel;
u32            CPU::sExtendedCpuidLevel;
CpuFamily      CPU::sFamily;                                                                                                                                                                             // Colorize: green
u8             CPU::sModel;
u8             CPU::sStepping;
u32            CPU::sMicrocodeRevision;
u32            CPU::sNumberOfCores;
u32            CPU::sNumberOfThreads;
u8             CPU::sNumberOfApicIdsPerPackage;
i8             CPU::sX86CoreIdBits;
u16            CPU::sCacheLineFlushSize;
u16            CPU::sCacheAlignment;
i32            CPU::sCacheMaxRmid;
i32            CPU::sCacheOccScale;
u32            CPU::sPower;
u8             CPU::sPhysicalBits;
u8             CPU::sVirtualBits;
good_U32       CPU::sFeatures[(enum_t)x86FeatureWord::MAXIMUM];                                                                                                                                          // Colorize: green
good_U32       CPU::sBugs[(enum_t)x86BugWord::MAXIMUM];                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::init()                                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Set default values                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        sNumberOfCores      = 1;                                                                                                                                                                         // Colorize: green
        sNumberOfThreads    = 1;                                                                                                                                                                         // Colorize: green
        sCacheLineFlushSize = 64;                                                                                                                                                                        // Colorize: green
        sCacheAlignment     = 64;                                                                                                                                                                        // Colorize: green
        sCacheMaxRmid       = -1;                                                                                                                                                                        // Colorize: green
        sCacheOccScale      = -1;                                                                                                                                                                        // Colorize: green
        sPhysicalBits       = 36;                                                                                                                                                                        // Colorize: green
        sVirtualBits        = 48;                                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that CPUID supported                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!hasX86Flags(FLAGS(X86Flag::CPUID_SUPPORTED)))                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("CPU didn't support CPUID"));                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return NgosStatus::NOT_SUPPORTED;                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green



    COMMON_LVV(("CPUID detection available"));

    COMMON_ASSERT_EXECUTION(setFeature(X86Feature::CPUID),       NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initCpuFeatures(),                NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initScatteredFeatures(),          NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initSpeculationControl(),         NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(doPostprocessing(),               NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(filterFeaturesDependentOnCpuid(), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initCpuBugs(),                    NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("sVendor.uints[0]           = 0x%08X", sVendor.uints[0]));
        COMMON_LVVV(("sVendor.uints[1]           = 0x%08X", sVendor.uints[1]));
        COMMON_LVVV(("sVendor.uints[2]           = 0x%08X", sVendor.uints[2]));
        COMMON_LVVV(("sVendor.chars              = %.12s",  sVendor.chars));
        COMMON_LVVV(("sCpuVendor                 = %s",     enumToFullString(sCpuVendor)));
        COMMON_LVVV(("sModelName.uints[0]        = 0x%08X", sModelName.uints[0]));
        COMMON_LVVV(("sModelName.uints[1]        = 0x%08X", sModelName.uints[1]));
        COMMON_LVVV(("sModelName.uints[2]        = 0x%08X", sModelName.uints[2]));
        COMMON_LVVV(("sModelName.uints[3]        = 0x%08X", sModelName.uints[3]));
        COMMON_LVVV(("sModelName.uints[4]        = 0x%08X", sModelName.uints[4]));
        COMMON_LVVV(("sModelName.uints[5]        = 0x%08X", sModelName.uints[5]));
        COMMON_LVVV(("sModelName.uints[6]        = 0x%08X", sModelName.uints[6]));
        COMMON_LVVV(("sModelName.uints[7]        = 0x%08X", sModelName.uints[7]));
        COMMON_LVVV(("sModelName.uints[8]        = 0x%08X", sModelName.uints[8]));
        COMMON_LVVV(("sModelName.uints[9]        = 0x%08X", sModelName.uints[9]));
        COMMON_LVVV(("sModelName.uints[10]       = 0x%08X", sModelName.uints[10]));
        COMMON_LVVV(("sModelName.uints[11]       = 0x%08X", sModelName.uints[11]));
        COMMON_LVVV(("sModelName.chars           = %.48s",  sModelName.chars));
        COMMON_LVVV(("sCpuidLevel                = 0x%08X", sCpuidLevel));
        COMMON_LVVV(("sExtendedCpuidLevel        = 0x%08X", sExtendedCpuidLevel));
        COMMON_LVVV(("sFamily                    = %s",     enumToFullString(sCpuVendor, sFamily)));
        COMMON_LVVV(("sModel                     = %s",     enumToFullString(sCpuVendor, sFamily, sModel)));
        COMMON_LVVV(("sStepping                  = %u",     sStepping));
        COMMON_LVVV(("sMicrocodeRevision         = 0x%08X", sMicrocodeRevision));
        COMMON_LVVV(("sNumberOfCores             = %u",     sNumberOfCores));
        COMMON_LVVV(("sNumberOfThreads           = %u",     sNumberOfThreads));
        COMMON_LVVV(("sNumberOfApicIdsPerPackage = %u",     sNumberOfApicIdsPerPackage));
        COMMON_LVVV(("sX86CoreIdBits             = %d",     sX86CoreIdBits));
        COMMON_LVVV(("sCacheLineFlushSize        = %u",     sCacheLineFlushSize));
        COMMON_LVVV(("sCacheAlignment            = %u",     sCacheAlignment));
        COMMON_LVVV(("sCacheMaxRmid              = %d",     sCacheMaxRmid));
        COMMON_LVVV(("sCacheOccScale             = %d",     sCacheOccScale));
        COMMON_LVVV(("sPower                     = %u",     sPower));
        COMMON_LVVV(("sPhysicalBits              = %u",     sPhysicalBits));
        COMMON_LVVV(("sVirtualBits               = %u",     sVirtualBits));



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            COMMON_LVVV(("CPU features:"));

            for (good_I64 i = 0; i < (i64)x86FeatureWord::MAXIMUM; ++i)
            {
                COMMON_LVVV(("sFeatures[%-27s] = 0x%08X", enumToFullString((x86FeatureWord)i), sFeatures[i]));
            }

            COMMON_LVVV(("CPU bugs:"));

            for (good_I64 i = 0; i < (i64)x86BugWord::MAXIMUM; ++i)
            {
                COMMON_LVVV(("sBugs[%-24s] = 0x%08X", enumToFullString((x86BugWord)i), sBugs[i]));
            }
        }
#endif



        // Ignore CppAlignmentVerifier [BEGIN]
        // COMMON_TEST_ASSERT(sVendor.uints[0]              == 0x756E6547,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sVendor.uints[1]              == 0x49656E69,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sVendor.uints[2]              == 0x6C65746E,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(strncmp(sVendor.chars, "GenuineIntel", 12) == 0,                                                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sCpuVendor                    == CpuVendor::INTEL,                                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[0]           == 0x65746E49,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[1]           == 0x6F43206C,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[2]           == 0x50206572,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[3]           == 0x65636F72,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[4]           == 0x726F7373,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[5]           == 0x6B532820,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[6]           == 0x6B616C79,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[7]           == 0x00002965,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[8]           == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[9]           == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[10]          == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModelName.uints[11]          == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(strncmp(sModelName.chars, "Intel Core Processor (Skylake)", 48) == 0,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sCpuidLevel                   == 0x0000000D,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sCpuidLevel                      >= CPUID_LEVEL_LOWER_BOUND && sCpuidLevel <= CPUID_LEVEL_UPPER_BOUND,                 NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sExtendedCpuidLevel           == 0x80000008,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sExtendedCpuidLevel              >= EXT_CPUID_LEVEL_LOWER_BOUND && sExtendedCpuidLevel <= EXT_CPUID_LEVEL_UPPER_BOUND, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sFamily                       == CpuFamily::INTEL_FAMILY_6,                                                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sModel                        == 94,                                                                                NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sStepping                     == 3,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMicrocodeRevision            == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfCores                == 2,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfThreads              == 4,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfApicIdsPerPackage    == 4,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sX86CoreIdBits                == 1,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sCacheLineFlushSize              == 64,                                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sCacheAlignment                  == 64,                                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sCacheMaxRmid                    == -1,                                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sCacheOccScale                   == -1,                                                                                NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sPower                        == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sPhysicalBits                 == 40,                                                                                NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sVirtualBits                  == 57,                                                                                NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((enum_t)x86FeatureWord::MAXIMUM  == 16,                                                                                NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sFeatures[0]                  == 0x82D82203,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[1]                  == 0x178BFBFD,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[2]                  == 0x00000004,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[3]                  == 0x00184389,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[4]                  == 0x00010000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[5]                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[6]                  == 0x00000005,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[7]                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[8]                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[9]                  == 0x00000021,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[10]                 == 0x28100800,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[11]                 == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[12]                 == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[13]                 == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[14]                 == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sFeatures[15]                 == 0x0000000D,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)x86BugWord::MAXIMUM         == 1,                                                                                 NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sBugs[0]                      == 0x0000003E,                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // Ignore CppAlignmentVerifier [END]
    }



    return NgosStatus::OK;
}

NgosStatus CPU::toString(good_Char8 *buffer, u16 size)
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
                , sVendor.chars
                , sFamily
                , sModel
                , sModelName.chars
                , sStepping
                , sMicrocodeRevision
                , sCpuidLevel
                , sCacheLineFlushSize
                , sCacheAlignment
                , sPhysicalBits
                , sVirtualBits);
    // Ignore CppAlignmentVerifier [END]



    AVOID_UNUSED(res);
    AVOID_UNUSED(size);
    COMMON_TEST_ASSERT(res < size, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::featuresToString(good_Char8 *buffer, u16 size)
{
    COMMON_LT((" | buffer = 0x%p, size = %u", buffer, size));

    COMMON_ASSERT(buffer,   "buffer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",   NgosStatus::ASSERTION);



    AVOID_UNUSED(size);



    u16 currentIndex = 0;

    for (good_I64 i = 0; i < (i64)x86FeatureWord::MAXIMUM; ++i)
    {
        u32 feature = sFeatures[i];

        for (good_I64 j = 0; j < 32; ++j)
        {
            if ((feature & (1ULL << j)) != 0)
            {
                const good_Char8 *featureName = x86FeaturesNames[WORD_BIT(i, j)];

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

NgosStatus CPU::bugsToString(good_Char8 *buffer, u16 size)
{
    COMMON_LT((" | buffer = 0x%p, size = %u", buffer, size));

    COMMON_ASSERT(buffer,   "buffer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",   NgosStatus::ASSERTION);



    AVOID_UNUSED(size);



    u16 currentIndex = 0;

    for (good_I64 i = 0; i < (i64)x86BugWord::MAXIMUM; ++i)
    {
        u32 bug = sBugs[i];

        for (good_I64 j = 0; j < 32; ++j)
        {
            if (bug & (1ULL << j))
            {
                const good_Char8 *bugName = x86BugsNames[WORD_BIT(i, j)];

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

NgosStatus CPU::check(const good_Char8 **wantedFeature)
{
    COMMON_LT((" | wantedFeature = 0x%p", wantedFeature));

    COMMON_ASSERT(wantedFeature != nullptr, "wantedFeature is null", NgosStatus::ASSERTION);



    X86Feature features[] =
    {
        X86Feature::CPUID
        , X86Feature::FPU
        , X86Feature::LM
        , X86Feature::MSR
        , X86Feature::PAE
        , X86Feature::NX
        , X86Feature::TSC
        , X86Feature::FXSR
        , X86Feature::XSAVE
        , X86Feature::AES
        , X86Feature::CX8
        , X86Feature::CMOV

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        , X86Feature::LA57
#endif

        , X86Feature::XMM
        , X86Feature::XMM2
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_SSE3
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



    i64 featuresCount = ARRAY_COUNT(features);
    COMMON_LVVV(("featuresCount = %d", featuresCount));

    for (good_I64 i = 0; i < featuresCount; ++i)
    {
        X86Feature feature = features[i];

        if (!hasFeature(feature))
        {
            *wantedFeature = x86FeaturesNames[(u64)feature];

            return NgosStatus::NOT_SUPPORTED;
        }
    }



    if (isOutdated())
    {
        return NgosStatus::NOT_SUPPORTED;
    }



    return NgosStatus::OK;
}

bool CPU::isOutdated()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



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
                return true;
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
                return true;
            }
        }
        break;

        case CpuVendor::NONE:
        case CpuVendor::UNKNOWN:
        {
            COMMON_LF(("Unexpected CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));

            return true;
        }
        break;

        default:
        {
            COMMON_LF(("Unknown CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));

            return true;
        }
        break;
    }



    return false;
}

CpuVendor CPU::getVendor()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sCpuVendor;
}

good_Char8* CPU::getModelName()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sModelName.chars;
}

CpuFamily CPU::getFamily()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sFamily;
}

u8 CPU::getModel()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sModel;
}

u8 CPU::getStepping()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sStepping;
}

u32 CPU::getMicrocodeRevision()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sMicrocodeRevision;
}

u32 CPU::getNumberOfCores()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sNumberOfCores;
}

u32 CPU::getNumberOfThreads()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sNumberOfThreads;
}

NgosStatus CPU::setFeature(X86Feature feature)
{
    COMMON_LT((" | feature = 0x%04X", feature));

    COMMON_ASSERT(((u64)feature / 32) < (u64)x86FeatureWord::MAXIMUM, "feature is invalid", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(BitUtils::set((u8 *)sFeatures, (u64)feature), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::clearFeature(X86Feature feature)
{
    COMMON_LT((" | feature = 0x%04X", feature));

    COMMON_ASSERT(((u64)feature / 32) < (u64)x86FeatureWord::MAXIMUM, "feature is invalid", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(BitUtils::clear((u8 *)sFeatures, (u64)feature), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

bool CPU::hasFeature(X86Feature feature)
{
    // COMMON_LT((" | feature = 0x%04X", feature)); // Commented to avoid bad looking logs

    COMMON_ASSERT(((u64)feature / 32) < (u64)x86FeatureWord::MAXIMUM, "feature is invalid", false);



    return BitUtils::test((u8 *)sFeatures, (u64)feature);
}

NgosStatus CPU::setBug(X86Bug bug)
{
    COMMON_LT((" | bug = 0x%04X", bug));

    COMMON_ASSERT(((u64)bug / 32) < (u64)x86BugWord::MAXIMUM, "bug is invalid", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(BitUtils::set((u8 *)sBugs, (u64)bug), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::clearBug(X86Bug bug)
{
    COMMON_LT((" | bug = 0x%04X", bug));

    COMMON_ASSERT(((u64)bug / 32) < (u64)x86BugWord::MAXIMUM, "bug is invalid", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(BitUtils::clear((u8 *)sBugs, (u64)bug), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

bool CPU::hasBug(X86Bug bug)
{
    COMMON_LT((" | bug = 0x%04X", bug));

    COMMON_ASSERT(((u64)bug / 32) < (u64)x86BugWord::MAXIMUM, "bug is invalid", false);



    return BitUtils::test((u8 *)sBugs, (u64)bug);
}

bool CPU::isCpuIdLevelSupported(u32 cpuidLevel)
{
    // COMMON_LT((" | cpuidLevel = 0x%08X", cpuidLevel)); // Commented to avoid bad looking logs

    COMMON_ASSERT(cpuidLevel >= CPUID_LEVEL_LOWER_BOUND && cpuidLevel <= CPUID_LEVEL_UPPER_BOUND, "cpuidLevel is invalid", false);



    return sCpuidLevel >= cpuidLevel;
}

bool CPU::hasX86Flags(X86Flags flags)
{
    COMMON_LT((" | flags = %s", flagsToFullString(flags)));

    COMMON_ASSERT(flags != FLAGS(X86Flag::NONE), "flags is invalid", false);



    X86Flags f0 = 0;
    X86Flags f1 = 0;



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "pushfq"            "\n\t"    // pushfq             # Push RFLAGS to the stack
        "pushfq"            "\n\t"    // pushfq             # Push RFLAGS to the stack
        "popq   %0"         "\n\t"    // popq   %rbp        # Get RFLAGS from the stack to f0. %rbp == f0
        "movq   %0, %1"     "\n\t"    // movq   %rbp, %r12  # Store f0 to f1. %rbp == f0. %r12 == f1
        "xorq   %2, %1"     "\n\t"    // xorq   %rdi, %r12  # Xor f1 with flags. %rdi == flags. %r12 == f1
        "pushq  %1"         "\n\t"    // pushq  %r12        # Push new value for RFLAGS to stack
        "popfq"             "\n\t"    // popfq              # Set new value for RFLAGS from the stack. If RFLAGS did't support some flags they stay zero
        "pushfq"            "\n\t"    // pushfq             # Push RFLAGS to the stack
        "popq   %1"         "\n\t"    // popq   %r12        # Get RFLAGS from the stack to f1. %r12 == f1
        "popfq"                       // popfq              # Restore RFLAGS from the stack
            :                         // Output parameters
                "=&r" (f0.flags),     // 'r' - any general register, '=' - write only, '&' - operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands
                "=&r" (f1.flags)      // 'r' - any general register, '=' - write only, '&' - operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands
            :                         // Input parameters
                "ri" (flags.flags)    // 'r' - any general register, or 'i' - immediate integer operand is allowed
    );
    // Ignore CppAlignmentVerifier [END]



    // Validation
    {
        COMMON_LVVV(("f0    = %s", flagsToFullString(f0)));
        COMMON_LVVV(("f1    = %s", flagsToFullString(f1)));
        COMMON_LVVV(("flags = %s", flagsToFullString(flags)));

        // COMMON_TEST_ASSERT(f0 == 0x0000000000000202, false); // Commented due to value variation
        // COMMON_TEST_ASSERT(f1 == 0x0000000000200202, false); // Commented due to value variation
        COMMON_TEST_ASSERT(flags == 0x0000000000200000, false);
    }



    return flags == (f0 ^ f1);
}

NgosStatus CPU::cpuid(u32 id, u32 count, u32 *a, u32 *b, u32 *c, u32 *d)
{
    COMMON_LT((" | id = 0x%08X, count = %u, a = 0x%p, b = 0x%p, c = 0x%p, d = 0x%p", id, count, a, b, c, d));

    COMMON_ASSERT(a != nullptr, "a is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(b != nullptr, "b is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(c != nullptr, "c is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(d != nullptr, "d is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "cpuid"               // cpuid  # Gets information about CPU to eax, ebx, ecx, edx
            :                 // Output parameters
                "=a" (*a),    // 'a' - EAX, '=' - write only
                "=b" (*b),    // 'b' - EBX, '=' - write only
                "=c" (*c),    // 'c' - ECX, '=' - write only
                "=d" (*d)     // 'd' - EDX, '=' - write only
            :                 // Input parameters
                "a" (id),     // 'a' - EAX // Ignore CppSingleCharVerifier
                "c" (count)   // 'c' - ECX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus CPU::initCpuFeatures()
{
    COMMON_LT((""));



    u32 ignored;



    COMMON_ASSERT_EXECUTION(cpuid(0x00000000, 0, &sCpuidLevel, &sVendor.uints[0], &sVendor.uints[2], &sVendor.uints[1]), NgosStatus::ASSERTION);

    if (sVendor.isIntel())
    {
        COMMON_LVV(("Intel CPU detected"));

        sCpuVendor = CpuVendor::INTEL;
    }
    else
    if (sVendor.isAMD())
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

            COMMON_ASSERT_EXECUTION(cpuid(0x00000001, 0, &tfms, &misc, &sFeatures[(u64)x86FeatureWord::CPUID_00000001_ECX], &sFeatures[(u64)x86FeatureWord::CPUID_00000001_EDX]), NgosStatus::ASSERTION);



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



            if (hasFeature(X86Feature::CLFLUSH))
            {
                COMMON_LVV(("X86Feature::CLFLUSH supported"));

                sCacheLineFlushSize = ((misc >> 8) & 0xFF) * 8;
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
            COMMON_ASSERT_EXECUTION(cpuid(0x00000006, 0, &sFeatures[(u64)x86FeatureWord::CPUID_00000006_EAX], &ignored, &ignored, &ignored), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x00000007)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x00000007, 0, &ignored, &sFeatures[(u64)x86FeatureWord::CPUID_00000007_EBX], &sFeatures[(u64)x86FeatureWord::CPUID_00000007_ECX], &sFeatures[(u64)x86FeatureWord::CPUID_00000007_EDX]), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x0000000D)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x0000000D, 1, &sFeatures[(u64)x86FeatureWord::CPUID_0000000D_1_EAX], &ignored, &ignored, &ignored), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sCpuidLevel >= 0x0000000F)
        {
            i32 ebx;
            i32 ecx;

            COMMON_ASSERT_EXECUTION(cpuid(0x0000000F, 0, &ignored, (u32 *)&ebx, &ignored, &sFeatures[(u64)x86FeatureWord::CPUID_0000000F_0_EDX]), NgosStatus::ASSERTION);

            if (hasFeature(X86Feature::CQM_LLC))
            {
                COMMON_LVV(("X86Feature::CQM_LLC supported"));



                sCacheMaxRmid = ebx;

                COMMON_ASSERT_EXECUTION(cpuid(0x0000000F, 1, &ignored, (u32 *)&ebx, (u32 *)&ecx, &sFeatures[(u64)x86FeatureWord::CPUID_0000000F_1_EDX]), NgosStatus::ASSERTION);

                if (
                    hasFeature(X86Feature::CQM_OCCUP_LLC)
                    ||
                    hasFeature(X86Feature::CQM_MBM_TOTAL)
                    ||
                    hasFeature(X86Feature::CQM_MBM_LOCAL)
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
            COMMON_ASSERT_EXECUTION(cpuid(0x80000001, 0, &ignored, &ignored, &sFeatures[(u64)x86FeatureWord::CPUID_80000001_ECX], &sFeatures[(u64)x86FeatureWord::CPUID_80000001_EDX]), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x80000004)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x80000002, 0, &sModelName.uints[0], &sModelName.uints[1], &sModelName.uints[2],  &sModelName.uints[3]),  NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(cpuid(0x80000003, 0, &sModelName.uints[4], &sModelName.uints[5], &sModelName.uints[6],  &sModelName.uints[7]),  NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(cpuid(0x80000004, 0, &sModelName.uints[8], &sModelName.uints[9], &sModelName.uints[10], &sModelName.uints[11]), NgosStatus::ASSERTION);



            // TODO: Need to extract to a function and provide tests to it
            good_Char8 *modelStr = sModelName.chars;



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

                for (good_I64 i = offset; i < length; ++i)
                {
                    modelStr[i - offset] = modelStr[i];
                }

                // TODO: Should be done once
                for (good_I64 i = length - offset; i < length; ++i)
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
            COMMON_ASSERT_EXECUTION(cpuid(0x80000007, 0, &ignored, &sFeatures[(u64)x86FeatureWord::CPUID_80000007_EBX], &ignored, &sPower), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x80000008)
        {
            u32 misc;

            COMMON_ASSERT_EXECUTION(cpuid(0x80000008, 0, &misc, &sFeatures[(u64)x86FeatureWord::CPUID_80000008_EBX], &ignored, &ignored), NgosStatus::ASSERTION);

            sVirtualBits  = (misc >> 8) & 0xFF;
            sPhysicalBits = misc & 0xFF;
        }
        else
        {
            break;
        }

        if (sExtendedCpuidLevel >= 0x8000000A)
        {
            COMMON_ASSERT_EXECUTION(cpuid(0x8000000A, 0, &ignored, &ignored, &ignored, &sFeatures[(u64)x86FeatureWord::CPUID_8000000A_EDX]), NgosStatus::ASSERTION);
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
            COMMON_LF(("Unexpected CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));
        }
        break;

        default:
        {
            COMMON_LF(("Unknown CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));
        }
        break;
    }



    COMMON_ASSERT_EXECUTION(doCommonPreprocessing(), NgosStatus::ASSERTION);



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

NgosStatus CPU::doCommonPreprocessing()
{
    COMMON_LT((""));



    if (hasFeature(X86Feature::HT))
    {
        COMMON_LVV(("X86Feature::HT supported"));



        u32 ignored;
        u32 ebx;

        COMMON_ASSERT_EXECUTION(cpuid(0x00000001, 0, &ignored, &ebx, &ignored, &ignored), NgosStatus::ASSERTION);

        // If Hyper-Threading is set EBX[16:23] in cpuid 0x00000001 contain the number of
        // apicids which are reserved per package. Store the resulting
        // shift value for the package management code.
        sNumberOfApicIdsPerPackage = ebx >> 16;

        COMMON_LVVV(("sNumberOfApicIdsPerPackage = %u", sNumberOfApicIdsPerPackage));

        sX86CoreIdBits = BitUtils::getCountOrder16(sNumberOfApicIdsPerPackage);
    }



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



    u32 ignored;
    u32 maximumLevel;
    u32 registers[4];

    COMMON_ASSERT_EXECUTION(cpuid(level & 0xFFFF0000, 0, &maximumLevel, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);



    if (maximumLevel >= level)
    {
        COMMON_TEST_ASSERT(maximumLevel >= (level & 0xFFFF0000) && maximumLevel <= (level | 0xFFFF), NgosStatus::ASSERTION)

        COMMON_ASSERT_EXECUTION(cpuid(level, count, &registers[0], &registers[1], &registers[2], &registers[3]), NgosStatus::ASSERTION);



        if (registers[registerId] & (1ULL << bit))
        {
            COMMON_ASSERT_EXECUTION(setFeature(feature), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus CPU::initSpeculationControl()
{
    COMMON_LT((""));



    if (hasFeature(X86Feature::SPEC_CTRL))
    {
        COMMON_LVV(("X86Feature::SPEC_CTRL supported"));
        COMMON_LVV(("X86Feature::IBRS set because X86Feature::SPEC_CTRL supported"));
        COMMON_LVV(("X86Feature::IBPB set because X86Feature::SPEC_CTRL supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::SPEC_CTRL supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBRS),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBPB),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::INTEL_STIBP))
    {
        COMMON_LVV(("X86Feature::INTEL_STIBP supported"));
        COMMON_LVV(("X86Feature::STIBP set because X86Feature::INTEL_STIBP supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::STIBP), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::SPEC_CTRL_SSBD) || hasFeature(X86Feature::VIRT_SSBD))
    {
        COMMON_LVV(("X86Feature::SPEC_CTRL_SSBD or X86Feature::VIRT_SSBD supported"));
        COMMON_LVV(("X86Feature::SSBD set because X86Feature::SPEC_CTRL_SSBD supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::SSBD), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::AMD_IBRS))
    {
        COMMON_LVV(("X86Feature::AMD_IBRS supported"));
        COMMON_LVV(("X86Feature::IBRS set because X86Feature::AMD_IBRS supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_IBRS supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBRS),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::AMD_IBPB))
    {
        COMMON_LVV(("X86Feature::AMD_IBPB supported"));
        COMMON_LVV(("X86Feature::IBPB set because X86Feature::AMD_IBPB supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBPB), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::AMD_STIBP))
    {
        COMMON_LVV(("X86Feature::AMD_STIBP supported"));
        COMMON_LVV(("X86Feature::STIBP set because X86Feature::AMD_STIBP supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_STIBP supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::STIBP),         NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::AMD_SSBD))
    {
        COMMON_LVV(("X86Feature::AMD_SSBD supported"));
        COMMON_LVV(("X86Feature::SSBD set because X86Feature::AMD_SSBD supported"));
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_SSBD supported"));
        COMMON_LVV(("X86Feature::VIRT_SSBD resetted because X86Feature::AMD_SSBD supported"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::SSBD),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::VIRT_SSBD),   NgosStatus::ASSERTION);
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
            COMMON_LF(("Unexpected CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));
        }
        break;

        default:
        {
            COMMON_LF(("Unknown CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));
        }
        break;
    }



    COMMON_ASSERT_EXECUTION(doCommonPostprocessing(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CPU::doIntelPostprocessing()
{
    COMMON_LT((""));



    COMMON_LVV(("X86Feature::CONSTANT_TSC supported"));

    COMMON_ASSERT_EXECUTION(setFeature(X86Feature::CONSTANT_TSC), NgosStatus::ASSERTION);



    if (!hasFeature(X86Feature::IA64))
    {
        COMMON_LVV(("Getting microcode revision since X86Feature::IA64 not supported"));

        COMMON_ASSERT_EXECUTION(initIntelMicrocodeRevision(), NgosStatus::ASSERTION);
    }



    // Early microcode releases for the Spectre v2 mitigation were broken. Therefore we are disabling Speculation Control in the case
    if (
        (
         hasFeature(X86Feature::IBRS)
         ||
         hasFeature(X86Feature::IBPB)
         ||
         hasFeature(X86Feature::STIBP)
         ||
         hasFeature(X86Feature::INTEL_STIBP)
         ||
         hasFeature(X86Feature::SPEC_CTRL)
        )
        &&
        isIntelBadSpectreMicrocode()
       )
    {
        COMMON_LVV(("X86Feature::IBRS, X86Feature::IBPB, X86Feature::STIBP, X86Feature::INTEL_STIBP or X86Feature::SPEC_CTRL supported"));
        COMMON_LW(("Intel Spectre v2 broken microcode detected; disabling Speculation Control"));

        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::IBRS),           NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::IBPB),           NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::STIBP),          NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::INTEL_STIBP),    NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::SPEC_CTRL),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::MSR_SPEC_CTRL),  NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::SSBD),           NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::SPEC_CTRL_SSBD), NgosStatus::ASSERTION);
    }



    // Bit 8 in cpuid 0x80000007 EDX means that TSC runs at constant rate with P/T states and does not stop in deep C-states.
    if (sPower & (1ULL << 8))
    {
        COMMON_LVV(("X86Feature::CONSTANT_TSC and X86Feature::NONSTOP_TSC supported due to bit 8 in cpuid 0x80000007 EDX"));

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::CONSTANT_TSC), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::NONSTOP_TSC),  NgosStatus::ASSERTION);
    }



    if (!MSR::testBit(MSR_IA32_MISC_ENABLE, MSR_IA32_MISC_ENABLE_FAST_STRING_BIT))
    {
        COMMON_LW(("Fast string operations disabled in MSR"));
        COMMON_LVV(("X86Feature::ERMS resetted because fast string operations disabled in MSR"));

        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::ERMS), NgosStatus::ASSERTION);
    }



    if (hasFeature(X86Feature::MPX) && !hasFeature(X86Feature::SMEP))
    {
        COMMON_LW(("X86Feature::MPX resetted because X86Feature::SMEP not supported"));

        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::MPX), NgosStatus::ASSERTION);
    }



    if (sCpuidLevel >= 0x0000000B)
    {
        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(0x0000000B, 0, &ignored, &sNumberOfCores,   &ignored, &ignored), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(cpuid(0x0000000B, 1, &ignored, &sNumberOfThreads, &ignored, &ignored), NgosStatus::ASSERTION);

        COMMON_TEST_ASSERT(sNumberOfThreads % sNumberOfCores == 0, NgosStatus::ASSERTION);

        sNumberOfCores = sNumberOfThreads / sNumberOfCores;
    }
    else
    if (sCpuidLevel >= 0x00000004)
    {
        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(0x00000004, 0, &sNumberOfCores, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);

        sNumberOfCores   = (sNumberOfCores >> 26) + 1;
        sNumberOfThreads = sNumberOfApicIdsPerPackage;

        COMMON_TEST_ASSERT(sNumberOfThreads % sNumberOfCores == 0, NgosStatus::ASSERTION);
    }
    else
    {
        sNumberOfThreads = sNumberOfApicIdsPerPackage;
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doAmdPostprocessing()
{
    COMMON_LT((""));



    if (sExtendedCpuidLevel >= 0x80000008)
    {
        u32 ignored;
        u32 ecx;

        COMMON_ASSERT_EXECUTION(cpuid(0x80000008, 0, &ignored, &ignored, &ecx, &ignored), NgosStatus::ASSERTION);



        sNumberOfCores   = (ecx >> 12) & 0x0F;
        sNumberOfThreads = (ecx & 0xFF) + 1;

        if (sNumberOfCores == 0)
        {
            sNumberOfCores = 1;
        }
    }
    else
    {
        sNumberOfThreads = sNumberOfApicIdsPerPackage;
    }



    return NgosStatus::OK;
}

NgosStatus CPU::doCommonPostprocessing()
{
    COMMON_LT((""));



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



    if (hasFeature(X86Feature::NX))
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

NgosStatus CPU::filterFeaturesDependentOnCpuid()
{
    COMMON_LT((""));



    if (hasFeature(X86Feature::MWAIT) && sCpuidLevel < 0x00000005)
    {
        COMMON_LW(("X86Feature::MWAIT resetted because sCpuidLevel < 0x00000005"));

        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::MWAIT), NgosStatus::ASSERTION);
    }

    if (hasFeature(X86Feature::DCA) && sCpuidLevel < 0x00000009)
    {
        COMMON_LW(("X86Feature::DCA resetted because sCpuidLevel < 0x00000009"));

        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::DCA), NgosStatus::ASSERTION);
    }

    if (hasFeature(X86Feature::XSAVE) && sCpuidLevel < 0x0000000D)
    {
        COMMON_LW(("X86Feature::XSAVE resetted because sCpuidLevel < 0x0000000D"));

        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::XSAVE), NgosStatus::ASSERTION);
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

    if (hasFeature(X86Feature::ARCH_CAPABILITIES))
    {
        COMMON_LVV(("X86Feature::ARCH_CAPABILITIES supported"));

        ia32Capabilities = MSR::read(MSR_IA32_ARCH_CAPABILITIES);

        COMMON_LVVV(("ia32Capabilities = 0x%016llX", ia32Capabilities));
    }



    if (
        !isCpuNoSpecStoreBypass()
        &&
        !(ia32Capabilities & MSR_IA32_ARCH_CAPABILITIES_SSB_NO)
        &&
        !hasFeature(X86Feature::AMD_SSB_NO)
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

        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBRS_ENHANCED), NgosStatus::ASSERTION);
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

NgosStatus CPU::initIntelMicrocodeRevision()
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
    if (hasFeature(X86Feature::HYPERVISOR))
    {
        COMMON_LVV(("X86Feature::HYPERVISOR supported"));

        return false;
    }



    return (
            (
                sModel == (u8)IntelCpuModel::FAMILY_6_SKYLAKE_SERVER_DE
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
                sModel == (u8)IntelCpuModel::FAMILY_6_KABY_LAKE_U
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
                sModel == (u8)IntelCpuModel::FAMILY_6_KABY_LAKE_DT
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
