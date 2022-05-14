#include "cpu.h"                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/asm/bitutils.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid00000000eax.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid00000001eax.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid00000001ebx.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid0000000febx0.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid0000000febx1.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid0000000fecx1.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid80000000eax.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid80000007edx.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuid80000008eax.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/registers/x86flags.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/x86bugsnames.h>                                                                                                                                       // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/x86featuresnames.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/amdcpumodel.h>                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpumodel.h>                                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/cpu/lib/generated/intelcpumodel.h>                                                                                                                                      // Colorize: green
#include <com/ngos/shared/common/memory/memory.h>                                                                                                                                                        // Colorize: green
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
CpuidVendor     CPU::sVendor;                                                                                                                                                                             // Colorize: green
CpuidModelName  CPU::sModelName;                                                                                                                                                                          // Colorize: green
CpuidLeaf       CPU::sCpuidLevel                = CpuidLeaf::VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION;                                                                                                                                                      // Colorize: green
CpuidLeaf       CPU::sExtendedCpuidLevel        = CpuidLeaf::VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION;                                                                                                                                                      // Colorize: green
CpuVendor       CPU::sCpuVendor                 = CpuVendor::NONE;                                                                                                                                                                          // Colorize: green
CpuFamily       CPU::sFamily                    = CpuFamily::NONE;                                                                                                                                        // Colorize: green
good_U8         CPU::sModel                     = 0;                                                                                                                                                      // Colorize: green
good_U8         CPU::sStepping                  = 0;                                                                                                                                                      // Colorize: green
good_U32        CPU::sMicrocodeRevision         = 0;                                                                                                                                                      // Colorize: green
good_U8         CPU::sNumberOfApicIdsPerPackage = 1;                                                                                                                                                      // Colorize: green
good_I8         CPU::sX86CoreIdBits             = 0;                                                                                                                                                      // Colorize: green
good_U16        CPU::sCacheLineFlushSize        = 64;                                                                                                                                                     // Colorize: green
good_U16        CPU::sCacheAlignment            = 64;                                                                                                                                                     // Colorize: green
good_I32        CPU::sCacheMaxRmid              = -1;                                                                                                                                                     // Colorize: green
good_I32        CPU::sCacheOccScale             = -1;                                                                                                                                                     // Colorize: green
CpuidPowerFlags CPU::sPower                     = FLAGS(CpuidPowerFlag::NONE);                                                                                                                           // Colorize: green
good_U8         CPU::sPhysicalBits              = 36;                                                                                                                                                    // Colorize: green
good_U8         CPU::sVirtualBits               = 48;                                                                                                                                                    // Colorize: green
good_U32        CPU::sNumberOfCores             = 1;                                                                                                                                                     // Colorize: green
good_U32        CPU::sNumberOfThreads           = 1;                                                                                                                                                     // Colorize: green
good_U32        CPU::sFeatures[(enum_t)x86FeatureWord::MAXIMUM];                                                                                                                                          // Colorize: green
good_U32        CPU::sBugs[(enum_t)x86BugWord::MAXIMUM];                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::init()                                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
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
                                                                                                                                                                                                         // Colorize: green
        COMMON_LVV(("CPUID detection available"));                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Setup parameters                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::CPUID),    NgosStatus::ASSERTION);                                                                                                             // Colorize: green
        COMMON_ASSERT_EXECUTION(initCpuFeatures(),                NgosStatus::ASSERTION);                                                                                                                // Colorize: green
        COMMON_ASSERT_EXECUTION(initScatteredFeatures(),          NgosStatus::ASSERTION);                                                                                                                // Colorize: green
        COMMON_ASSERT_EXECUTION(initSpeculationControl(),         NgosStatus::ASSERTION);                                                                                                                // Colorize: green
        COMMON_ASSERT_EXECUTION(doPostprocessing(),               NgosStatus::ASSERTION);                                                                                                                // Colorize: green
        COMMON_ASSERT_EXECUTION(filterFeaturesDependentOnCpuid(), NgosStatus::ASSERTION);                                                                                                                // Colorize: green
        COMMON_ASSERT_EXECUTION(initCpuBugs(),                    NgosStatus::ASSERTION);                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("sVendor.uints[0]           = 0x%08X", sVendor.uints[0]));                                                                                                                          // Colorize: green
        COMMON_LVVV(("sVendor.uints[1]           = 0x%08X", sVendor.uints[1]));                                                                                                                          // Colorize: green
        COMMON_LVVV(("sVendor.uints[2]           = 0x%08X", sVendor.uints[2]));                                                                                                                          // Colorize: green
        COMMON_LVVV(("sVendor.chars              = %.12s",  sVendor.chars));                                                                                                                             // Colorize: green
        COMMON_LVVV(("sModelName.uints[0]        = 0x%08X", sModelName.uints[0]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[1]        = 0x%08X", sModelName.uints[1]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[2]        = 0x%08X", sModelName.uints[2]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[3]        = 0x%08X", sModelName.uints[3]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[4]        = 0x%08X", sModelName.uints[4]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[5]        = 0x%08X", sModelName.uints[5]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[6]        = 0x%08X", sModelName.uints[6]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[7]        = 0x%08X", sModelName.uints[7]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[8]        = 0x%08X", sModelName.uints[8]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[9]        = 0x%08X", sModelName.uints[9]));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sModelName.uints[10]       = 0x%08X", sModelName.uints[10]));                                                                                                                      // Colorize: green
        COMMON_LVVV(("sModelName.uints[11]       = 0x%08X", sModelName.uints[11]));                                                                                                                      // Colorize: green
        COMMON_LVVV(("sModelName.chars           = %.48s",  sModelName.chars));                                                                                                                          // Colorize: green
        COMMON_LVVV(("sCpuidLevel                = %s",     enumToFullString(sCpuidLevel)));                                                                                                             // Colorize: green
        COMMON_LVVV(("sExtendedCpuidLevel        = %s",     enumToFullString(sExtendedCpuidLevel)));                                                                                                     // Colorize: green
        COMMON_LVVV(("sCpuVendor                 = %s",     enumToFullString(sCpuVendor)));                                                                                                              // Colorize: green
        COMMON_LVVV(("sFamily                    = %s",     enumToFullString(sCpuVendor, sFamily)));                                                                                                     // Colorize: green
        COMMON_LVVV(("sModel                     = %s",     enumToFullString(sCpuVendor, sFamily, sModel)));                                                                                             // Colorize: green
        COMMON_LVVV(("sStepping                  = %u",     sStepping));                                                                                                                                 // Colorize: green
        COMMON_LVVV(("sMicrocodeRevision         = 0x%08X", sMicrocodeRevision));                                                                                                                        // Colorize: green
        COMMON_LVVV(("sNumberOfApicIdsPerPackage = %u",     sNumberOfApicIdsPerPackage));                                                                                                                // Colorize: green
        COMMON_LVVV(("sX86CoreIdBits             = %d",     sX86CoreIdBits));                                                                                                                            // Colorize: green
        COMMON_LVVV(("sCacheLineFlushSize        = %u",     sCacheLineFlushSize));                                                                                                                       // Colorize: green
        COMMON_LVVV(("sCacheAlignment            = %u",     sCacheAlignment));                                                                                                                           // Colorize: green
        COMMON_LVVV(("sCacheMaxRmid              = %d",     sCacheMaxRmid));                                                                                                                             // Colorize: green
        COMMON_LVVV(("sCacheOccScale             = %d",     sCacheOccScale));                                                                                                                            // Colorize: green
        COMMON_LVVV(("sPower                     = %s",     flagsToFullString(sPower)));                                                                                                                                    // Colorize: green
        COMMON_LVVV(("sPhysicalBits              = %u",     sPhysicalBits));                                                                                                                             // Colorize: green
        COMMON_LVVV(("sVirtualBits               = %u",     sVirtualBits));                                                                                                                              // Colorize: green
        COMMON_LVVV(("sNumberOfCores             = %u",     sNumberOfCores));                                                                                                                            // Colorize: green
        COMMON_LVVV(("sNumberOfThreads           = %u",     sNumberOfThreads));                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Print CPU features and bugs                                                                                                                                                                   // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE           // Colorize: green
            COMMON_LVVV(("CPU features:"));                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < static_cast<good_I64>(x86FeatureWord::MAXIMUM); ++i)                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("sFeatures[%-30s] = 0x%08X", enumToFullString(static_cast<x86FeatureWord>(i)), sFeatures[i]));                                                                              // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_LVVV(("CPU bugs:"));                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = 0; i < static_cast<good_I64>(x86BugWord::MAXIMUM); ++i)                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("sBugs[%-23s] = 0x%08X", enumToFullString(static_cast<x86BugWord>(i)), sBugs[i]));                                                                                          // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                           // Colorize: green
        // COMMON_TEST_ASSERT(sVendor.uints[0]                               == 0x756E6547,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sVendor.uints[1]                               == 0x49656E69,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sVendor.uints[2]                               == 0x6C65746E,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(strncmp(sVendor.chars, "GenuineIntel", 12)     == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[0]                            == 0x65746E49,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[1]                            == 0x6F43206C,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[2]                            == 0x50206572,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[3]                            == 0x65636F72,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[4]                            == 0x726F7373,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[5]                            == 0x6B532820,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[6]                            == 0x6B616C79,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[7]                            == 0x00002965,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[8]                            == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[9]                            == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[10]                           == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModelName.uints[11]                           == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(strncmp(sModelName.chars, "Intel Core Processor (Skylake)", 48) == 0,                                                                NgosStatus::ASSERTION); // Commented due to value variation     // Colorize: green
        // COMMON_TEST_ASSERT(sCpuidLevel                                    == CpuidLeaf::XSAVE_FEATURES,                                                         NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        COMMON_TEST_ASSERT(static_cast<good_Enum_t>(sCpuidLevel)             >= CPUID_LEVEL_LOWER_BOUND && static_cast<good_Enum_t>(sCpuidLevel) <= CPUID_LEVEL_UPPER_BOUND,                 NgosStatus::ASSERTION);                                // Colorize: green
        // COMMON_TEST_ASSERT(sExtendedCpuidLevel                            == CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES,                                     NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        COMMON_TEST_ASSERT(static_cast<good_Enum_t>(sExtendedCpuidLevel)     >= EXT_CPUID_LEVEL_LOWER_BOUND && static_cast<good_Enum_t>(sExtendedCpuidLevel) <= EXT_CPUID_LEVEL_UPPER_BOUND, NgosStatus::ASSERTION);                                // Colorize: green
        // COMMON_TEST_ASSERT(sCpuVendor                                     == CpuVendor::INTEL,                                                                  NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFamily                                        == CpuFamily::INTEL_FAMILY_6,                                                         NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sModel                                         == 94,                                                                                NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sStepping                                      == 3,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sMicrocodeRevision                             == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sNumberOfApicIdsPerPackage                     == 4,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sX86CoreIdBits                                 == 1,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        COMMON_TEST_ASSERT(sCacheLineFlushSize                               == 64,                                                                                NgosStatus::ASSERTION);                                // Colorize: green
        COMMON_TEST_ASSERT(sCacheAlignment                                   == 64,                                                                                NgosStatus::ASSERTION);                                // Colorize: green
        COMMON_TEST_ASSERT(sCacheMaxRmid                                     == -1,                                                                                NgosStatus::ASSERTION);                                // Colorize: green
        COMMON_TEST_ASSERT(sCacheOccScale                                    == -1,                                                                                NgosStatus::ASSERTION);                                // Colorize: green
        // COMMON_TEST_ASSERT(sPower                                         == 0,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sPhysicalBits                                  == 40,                                                                                NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sVirtualBits                                   == 57,                                                                                NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sNumberOfCores                                 == 2,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sNumberOfThreads                               == 4,                                                                                 NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        COMMON_TEST_ASSERT(static_cast<good_Enum_t>(x86FeatureWord::MAXIMUM) == 16,                                                                                NgosStatus::ASSERTION);               // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[0]                                   == 0x82D82203,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[1]                                   == 0x178BFBFD,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[2]                                   == 0x00000004,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[3]                                   == 0x00184389,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[4]                                   == 0x00010000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[5]                                   == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[6]                                   == 0x00000005,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[7]                                   == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[8]                                   == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[9]                                   == 0x00000021,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[10]                                  == 0x28100800,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[11]                                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[12]                                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[13]                                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[14]                                  == 0x00000000,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // COMMON_TEST_ASSERT(sFeatures[15]                                  == 0x0000000D,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        COMMON_TEST_ASSERT(static_cast<good_Enum_t>(x86BugWord::MAXIMUM)     == 1,                                                                                 NgosStatus::ASSERTION);               // Colorize: green
        // COMMON_TEST_ASSERT(sBugs[0]                                       == 0x0000003E,                                                                        NgosStatus::ASSERTION); // Commented due to value variation // Colorize: green
        // Ignore CppAlignmentVerifier [END]                                                                                                                                                             // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::toString(good_Char8 *buffer, good_I64 size)                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | buffer = 0x%p, size = %d", buffer, size));                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(buffer != nullptr, "buffer is null",  NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
    COMMON_ASSERT(size > 0,          "size is invalid", NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_I64 res;                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Fill buffer with CPU info                                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                           // Colorize: green
        res = sprintf(buffer,                                                                                                                                                                            // Colorize: green
                "CPU info:\n"                                                                                                                                                                            // Colorize: green
                "           Vendor:                %.12s\n"                                                                                                                                              // Colorize: green
                "           CPU Family:            %u\n"                                                                                                                                                 // Colorize: green
                "           Model:                 %u\n"                                                                                                                                                 // Colorize: green
                "           Model name:            %.48s\n"                                                                                                                                              // Colorize: green
                "           Stepping:              %u\n"                                                                                                                                                 // Colorize: green
                "           Microcode:             0x%08X\n"                                                                                                                                             // Colorize: green
                "           CPUID level:           %u\n"                                                                                                                                                 // Colorize: green
                "           Cache line flush size: %u\n"                                                                                                                                                 // Colorize: green
                "           Cache alignment:       %u\n"                                                                                                                                                 // Colorize: green
                "           Address sizes:         %u bits physical, %u bits virtual"                                                                                                                    // Colorize: green
                    , sVendor.chars                                                                                                                                                                      // Colorize: green
                    , sFamily                                                                                                                                                                            // Colorize: green
                    , sModel                                                                                                                                                                             // Colorize: green
                    , sModelName.chars                                                                                                                                                                   // Colorize: green
                    , sStepping                                                                                                                                                                          // Colorize: green
                    , sMicrocodeRevision                                                                                                                                                                 // Colorize: green
                    , sCpuidLevel                                                                                                                                                                        // Colorize: green
                    , sCacheLineFlushSize                                                                                                                                                                // Colorize: green
                    , sCacheAlignment                                                                                                                                                                    // Colorize: green
                    , sPhysicalBits                                                                                                                                                                      // Colorize: green
                    , sVirtualBits);                                                                                                                                                                     // Colorize: green
        // Ignore CppAlignmentVerifier [END]                                                                                                                                                             // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        AVOID_UNUSED(res);                                                                                                                                                                               // Colorize: green
        AVOID_UNUSED(size);                                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_LVVV(("res  = %d", res));                                                                                                                                                                 // Colorize: green
        COMMON_LVVV(("size = %d", size));                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(res < size, NgosStatus::ASSERTION);                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::featuresToString(good_Char8 *buffer, good_I64 size)                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | buffer = 0x%p, size = %d", buffer, size));                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(buffer != nullptr, "buffer is null",  NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
    COMMON_ASSERT(size > 0,          "size is invalid", NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    AVOID_UNUSED(size);                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_I64 currentIndex = 0;                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Fill buffer with features                                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        for (good_I64 i = 0; i < static_cast<i64>(x86FeatureWord::MAXIMUM); ++i)                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U32 featureWord = sFeatures[i];                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 j = 0; j < 32; ++j)                                                                                                                                                            // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if ((featureWord & (1ULL << j)) != 0)                                                                                                                                                    // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    const good_Char8 *featureName = x86FeaturesNames[WORD_BIT(i, j)];                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (featureName[0] != 0) // featureName != ""                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        // Split features with space                                                                                                                                                     // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            if (currentIndex > 0)                                                                                                                                                        // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                buffer[currentIndex] = ' ';                                                                                                                                              // Colorize: green
                                ++currentIndex;                                                                                                                                                          // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Append feature name to buffer                                                                                                                                                 // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            while (*featureName != 0)                                                                                                                                                    // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                buffer[currentIndex] = *featureName;                                                                                                                                     // Colorize: green
                                ++currentIndex;                                                                                                                                                          // Colorize: green
                                ++featureName;                                                                                                                                                           // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("currentIndex = %d", currentIndex));                                                                                                                                                // Colorize: green
        COMMON_LVVV(("size         = %d", size));                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    buffer[currentIndex] = 0;                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::bugsToString(good_Char8 *buffer, good_I64 size)                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | buffer = 0x%p, size = %d", buffer, size));                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(buffer != nullptr, "buffer is null",  NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
    COMMON_ASSERT(size > 0,          "size is invalid", NgosStatus::ASSERTION);                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    AVOID_UNUSED(size);                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_I64 currentIndex = 0;                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Fill buffer with bugs                                                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        for (good_I64 i = 0; i < static_cast<i64>(x86BugWord::MAXIMUM); ++i)                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U32 bugWord = sBugs[i];                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 j = 0; j < 32; ++j)                                                                                                                                                            // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if ((bugWord & (1ULL << j)) != 0)                                                                                                                                                        // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    const good_Char8 *bugName = x86BugsNames[WORD_BIT(i, j)];                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (bugName[0] != 0) // bugName != ""                                                                                                                                                // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        // Split bugs with space                                                                                                                                                         // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            if (currentIndex > 0)                                                                                                                                                        // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                buffer[currentIndex] = ' ';                                                                                                                                              // Colorize: green
                                ++currentIndex;                                                                                                                                                          // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Append bug name to buffer                                                                                                                                                     // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            while (*bugName != 0)                                                                                                                                                        // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                buffer[currentIndex] = *bugName;                                                                                                                                         // Colorize: green
                                ++currentIndex;                                                                                                                                                          // Colorize: green
                                ++bugName;                                                                                                                                                               // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("currentIndex = %d", currentIndex));                                                                                                                                                // Colorize: green
        COMMON_LVVV(("size         = %d", size));                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_TEST_ASSERT(currentIndex < size, NgosStatus::ASSERTION);                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    buffer[currentIndex] = 0;                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::check(const good_Char8 **wantedFeature)                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | wantedFeature = 0x%p", wantedFeature));                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(wantedFeature != nullptr, "wantedFeature is null", NgosStatus::ASSERTION);                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    X86Feature features[] =                                                                                                                                                                              // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        X86Feature::CPUID           // CPU has CPUID instruction itself                                                                                                                                      // Colorize: green
        , X86Feature::FPU           // Onboard FPU                                                                                                                                                           // Colorize: green
        , X86Feature::LM            // Long Mode (x86-64, 64-bit support)                                                                                                                                    // Colorize: green
        , X86Feature::MSR           // Model-Specific Registers                                                                                                                                              // Colorize: green
        , X86Feature::PAE           // Physical Address Extensions                                                                                                                                           // Colorize: green
        , X86Feature::NX            // Execute Disable                                                                                                                                                       // Colorize: green
        , X86Feature::TSC           // Time Stamp Counter                                                                                                                                                    // Colorize: green
        , X86Feature::FXSR          // FXSAVE/FXRSTOR, CR4.OSFXSR                                                                                                                                            // Colorize: green
        , X86Feature::XSAVE         // XSAVE/XRSTOR/XSETBV/XGETBV instructions                                                                                                                               // Colorize: green
        , X86Feature::AES           // AES instructions                                                                                                                                                      // Colorize: green
        , X86Feature::CX8           // CMPXCHG8 instruction                                                                                                                                                  // Colorize: green
        , X86Feature::CMOV          // CMOV instructions (plus FCMOVcc, FCOMI with FPU)                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES                                                                                                                                                              // Colorize: green
        , X86Feature::LA57          // 5-level page tables                                                                                                                                                   // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        , X86Feature::XMM           // "sse"                                                                                                                                                                 // Colorize: green
        , X86Feature::XMM2          // "sse2"                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_SSE3                                                                                                                        // Colorize: green
        , X86Feature::XMM3          // "sse3" SSE-3                                                                                                                                                          // Colorize: green
        , X86Feature::SSSE3         // Supplemental SSE-3                                                                                                                                                    // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_SSE4                                                                                                                        // Colorize: green
        , X86Feature::XMM4_1        // "sse4_1" SSE-4.1                                                                                                                                                      // Colorize: green
        , X86Feature::XMM4_2        // "sse4_2" SSE-4.2                                                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX                                                                                                                         // Colorize: green
        , X86Feature::AVX           // Advanced Vector Extensions                                                                                                                                            // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX2                                                                                                                        // Colorize: green
        , X86Feature::AVX2          // AVX2 instructions                                                                                                                                                 // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1                                                                                                                  // Colorize: green
        , X86Feature::AVX512F       // AVX-512 Foundation                                                                                                                                                // Colorize: green
        , X86Feature::AVX512CD      // AVX-512 Conflict Detection                                                                                                                                        // Colorize: green
        , X86Feature::AVX512ER      // AVX-512 Exponential and Reciprocal                                                                                                                                // Colorize: green
        , X86Feature::AVX512PF      // AVX-512 Prefetch                                                                                                                                                  // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2                                                                                                                  // Colorize: green
        , X86Feature::AVX512F       // AVX-512 Foundation                                                                                                                                                // Colorize: green
        , X86Feature::AVX512CD      // AVX-512 Conflict Detection                                                                                                                                        // Colorize: green
        , X86Feature::AVX512BW      // AVX-512 BW (Byte/Word granular) Instructions                                                                                                                      // Colorize: green
        , X86Feature::AVX512DQ      // AVX-512 DQ (Double/Quad granular) Instructions                                                                                                                    // Colorize: green
        , X86Feature::AVX512VL      // AVX-512 VL (128/256 Vector Length) Extensions                                                                                                                     // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE == OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3                                                                                                                  // Colorize: green
        , X86Feature::AVX512F       // AVX-512 Foundation                                                                                                                                                // Colorize: green
        , X86Feature::AVX512CD      // AVX-512 Conflict Detection                                                                                                                                        // Colorize: green
        , X86Feature::AVX512BW      // AVX-512 BW (Byte/Word granular) Instructions                                                                                                                      // Colorize: green
        , X86Feature::AVX512DQ      // AVX-512 DQ (Double/Quad granular) Instructions                                                                                                                    // Colorize: green
        , X86Feature::AVX512VL      // AVX-512 VL (128/256 Vector Length) Extensions                                                                                                                     // Colorize: green
        , X86Feature::AVX512IFMA    // AVX-512 Integer Fused Multiply-Add instructions                                                                                                                   // Colorize: green
        , X86Feature::AVX512VBMI    // AVX-512 Vector Bit Manipulation instructions                                                                                                                      // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE > OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3                                                                                                                   // Colorize: green
#error Unexpected value for NGOS_BUILD_X86_64_VECTORIZATION_MODE parameter                                                                                                                               // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4                                                                                                                        // Colorize: green
        , X86Feature::FMA4          // 4 operands MAC instructions                                                                                                                                       // Colorize: green
#elif NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3                                                                                                                      // Colorize: green
        , X86Feature::FMA           // Fused multiply-add                                                                                                                                                // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that we have all required features                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        good_I64 featuresCount = ARRAY_COUNT(features);                                                                                                                                                  // Colorize: green
        COMMON_LVVV(("featuresCount = %d", featuresCount));                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (good_I64 i = 0; i < featuresCount; ++i)                                                                                                                                                     // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            X86Feature feature = features[i];                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (!hasFeature(feature))                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                *wantedFeature = x86FeaturesNames[static_cast<good_Enum_t>(feature)];                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return NgosStatus::NOT_SUPPORTED;                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (isOutdated())                                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return NgosStatus::NOT_SUPPORTED;                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool CPU::isOutdated()                                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (sCpuVendor)                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuVendor::INTEL:                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (                                                                                                                                                                                         // Colorize: green
                static_cast<good_U16>(sFamily) != INTEL_MINIMAL_FAMILY                                                                                                                                   // Colorize: green
                ||                                                                                                                                                                                       // Colorize: green
                sModel < INTEL_MINIMAL_MODEL                                                                                                                                                             // Colorize: green
               )                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                return true;                                                                                                                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        case CpuVendor::AMD:                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (                                                                                                                                                                                         // Colorize: green
                static_cast<good_U16>(sFamily) < AMD_MINIMAL_FAMILY                                                                                                                                      // Colorize: green
                ||                                                                                                                                                                                       // Colorize: green
                (                                                                                                                                                                                        // Colorize: green
                 static_cast<good_U16>(sFamily) == AMD_MINIMAL_FAMILY                                                                                                                                    // Colorize: green
                 &&                                                                                                                                                                                      // Colorize: green
                 sModel < AMD_MINIMAL_MODEL                                                                                                                                                              // Colorize: green
                )                                                                                                                                                                                        // Colorize: green
               )                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                return true;                                                                                                                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        case CpuVendor::NONE:                                                                                                                                                                            // Colorize: green
        case CpuVendor::UNKNOWN:                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("Unexpected CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default:                                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("Unknown CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return false;                                                                                                                                                                                        // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CpuVendor CPU::getCpuVendor()                                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sCpuVendor;                                                                                                                                                                                   // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_Char8* CPU::getModelName()                                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sModelName.chars;                                                                                                                                                                             // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CpuFamily CPU::getFamily()                                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sFamily;                                                                                                                                                                                      // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_U8 CPU::getModel()                                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sModel;                                                                                                                                                                                       // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_U8 CPU::getStepping()                                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sStepping;                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_U32 CPU::getMicrocodeRevision()                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sMicrocodeRevision;                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_U32 CPU::getNumberOfCores()                                                                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sNumberOfCores;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_U32 CPU::getNumberOfThreads()                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return sNumberOfThreads;                                                                                                                                                                             // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::setFeature(X86Feature feature)                                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | feature = 0x%04X", feature));                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT((static_cast<good_Enum_t>(feature) / 32) < static_cast<good_Enum_t>(x86FeatureWord::MAXIMUM), "feature is invalid", NgosStatus::ASSERTION);                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(BitUtils::set(reinterpret_cast<good_U8 *>(sFeatures), static_cast<good_Enum_t>(feature)), NgosStatus::ASSERTION);                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::clearFeature(X86Feature feature)                                                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | feature = 0x%04X", feature));                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT((static_cast<good_Enum_t>(feature) / 32) < static_cast<good_Enum_t>(x86FeatureWord::MAXIMUM), "feature is invalid", NgosStatus::ASSERTION);                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(BitUtils::clear(reinterpret_cast<good_U8 *>(sFeatures), static_cast<good_Enum_t>(feature)), NgosStatus::ASSERTION);                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool CPU::hasFeature(X86Feature feature)                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | feature = 0x%04X", feature)); // Commented to avoid bad looking logs                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT((static_cast<good_Enum_t>(feature) / 32) < static_cast<good_Enum_t>(x86FeatureWord::MAXIMUM), "feature is invalid", false);                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return BitUtils::test(reinterpret_cast<good_U8 *>(sFeatures), static_cast<good_Enum_t>(feature));                                                                                                                                 // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::setBug(X86Bug bug)                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | bug = 0x%04X", bug));                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT((static_cast<good_Enum_t>(bug) / 32) < static_cast<good_Enum_t>(x86BugWord::MAXIMUM), "bug is invalid", NgosStatus::ASSERTION);                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(BitUtils::set(reinterpret_cast<good_U8 *>(sBugs), static_cast<good_Enum_t>(bug)), NgosStatus::ASSERTION);                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::clearBug(X86Bug bug)                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | bug = 0x%04X", bug));                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT((static_cast<good_Enum_t>(bug) / 32) < static_cast<good_Enum_t>(x86BugWord::MAXIMUM), "bug is invalid", NgosStatus::ASSERTION);                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(BitUtils::clear(reinterpret_cast<good_U8 *>(sBugs), static_cast<good_Enum_t>(bug)), NgosStatus::ASSERTION);                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool CPU::hasBug(X86Bug bug)                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | bug = 0x%04X", bug));                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT((static_cast<good_Enum_t>(bug) / 32) < static_cast<good_Enum_t>(x86BugWord::MAXIMUM), "bug is invalid", false);                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return BitUtils::test(reinterpret_cast<good_U8 *>(sBugs), static_cast<good_Enum_t>(bug));                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool CPU::isCpuIdLevelSupported(CpuidLeaf cpuidLevel)                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | cpuidLevel = %s", enumToFullString(cpuidLevel))); // Commented to avoid bad looking logs                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (static_cast<good_Enum_t>(cpuidLevel) >= CPUID_LEVEL_LOWER_BOUND && static_cast<good_Enum_t>(cpuidLevel) <= CPUID_LEVEL_UPPER_BOUND)                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return sCpuidLevel >= cpuidLevel;                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (static_cast<good_Enum_t>(cpuidLevel) >= EXT_CPUID_LEVEL_LOWER_BOUND && static_cast<good_Enum_t>(cpuidLevel) <= EXT_CPUID_LEVEL_UPPER_BOUND)                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return sExtendedCpuidLevel >= cpuidLevel;                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_LE(("Unexpected CPUID level provided: %s", enumToFullString(cpuidLevel)));                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return false;                                                                                                                                                                                        // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool CPU::hasX86Flags(X86Flags flags)                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | flags = %s", flagsToFullString(flags)));                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(flags != FLAGS(X86Flag::NONE), "flags is invalid", false);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    X86Flags f0 = FLAGS(X86Flag::NONE);                                                                                                                                                                  // Colorize: green
    X86Flags f1 = FLAGS(X86Flag::NONE);                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get original RFLAGS and RFLAGS after applying flags if successful                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                           // Colorize: green
        asm volatile(                                                                                                                                                                                    // Colorize: green
            "pushfq"            "\n\t"    // pushfq             # Push RFLAGS to the stack                                                                                                               // Colorize: green
            "pushfq"            "\n\t"    // pushfq             # Push RFLAGS to the stack                                                                                                               // Colorize: green
            "popq   %0"         "\n\t"    // popq   %rbp        # Get RFLAGS from the stack to f0. %rbp == f0                                                                                            // Colorize: green
            "movq   %0, %1"     "\n\t"    // movq   %rbp, %r12  # Store f0 to f1. %rbp == f0. %r12 == f1                                                                                                 // Colorize: green
            "xorq   %2, %1"     "\n\t"    // xorq   %rdi, %r12  # Xor f1 with flags. %rdi == flags. %r12 == f1                                                                                           // Colorize: green
            "pushq  %1"         "\n\t"    // pushq  %r12        # Push new value for RFLAGS to stack                                                                                                     // Colorize: green
            "popfq"             "\n\t"    // popfq              # Set new value for RFLAGS from the stack. If RFLAGS did't support some flags they stay zero                                             // Colorize: green
            "pushfq"            "\n\t"    // pushfq             # Push RFLAGS to the stack                                                                                                               // Colorize: green
            "popq   %1"         "\n\t"    // popq   %r12        # Get RFLAGS from the stack to f1. %r12 == f1                                                                                            // Colorize: green
            "popfq"                       // popfq              # Restore RFLAGS from the stack                                                                                                          // Colorize: green
                :                         // Output parameters                                                                                                                                           // Colorize: green
                    "=&r" (f0.flags),     // 'r' - any general register, '=' - write only, '&' - operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands // Colorize: green
                    "=&r" (f1.flags)      // 'r' - any general register, '=' - write only, '&' - operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands // Colorize: green
                :                         // Input parameters                                                                                                                                            // Colorize: green
                    "ri" (flags.flags)    // 'r' - any general register, or 'i' - immediate integer operand is allowed                                                                                   // Colorize: green
        );                                                                                                                                                                                               // Colorize: green
        // Ignore CppAlignmentVerifier [END]                                                                                                                                                             // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Validation                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVVV(("f0    = %s", flagsToFullString(f0)));                                                                                                                                              // Colorize: green
        COMMON_LVVV(("f1    = %s", flagsToFullString(f1)));                                                                                                                                              // Colorize: green
        COMMON_LVVV(("flags = %s", flagsToFullString(flags)));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // COMMON_TEST_ASSERT(f0 == 0x0000000000000202, false); // Commented due to value variation                                                                                                      // Colorize: green
        // COMMON_TEST_ASSERT(f1 == 0x0000000000200202, false); // Commented due to value variation                                                                                                      // Colorize: green
        COMMON_TEST_ASSERT(flags == 0x0000000000200000, false);                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return flags == (f0 ^ f1);                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::cpuid(CpuidLeaf leaf, CpuidSubLeaf subLeaf, good_U32 *a, good_U32 *b, good_U32 *c, good_U32 *d)                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | leaf = %s, subLeaf = %s, a = 0x%p, b = 0x%p, c = 0x%p, d = 0x%p", enumToFullString(leaf), enumToFullString(subLeaf), a, b, c, d));                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(a != nullptr, "a is null", NgosStatus::ASSERTION);                                                                                                                                     // Colorize: green
    COMMON_ASSERT(b != nullptr, "b is null", NgosStatus::ASSERTION);                                                                                                                                     // Colorize: green
    COMMON_ASSERT(c != nullptr, "c is null", NgosStatus::ASSERTION);                                                                                                                                     // Colorize: green
    COMMON_ASSERT(d != nullptr, "d is null", NgosStatus::ASSERTION);                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Perform cpuid and get values of eax, ebx, ecx, edx                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                           // Colorize: green
        asm volatile(                                                                                                                                                                                    // Colorize: green
            "cpuid"               // cpuid  # Gets information about CPU to eax, ebx, ecx, edx                                                                                                           // Colorize: green
                :                 // Output parameters                                                                                                                                                   // Colorize: green
                    "=a" (*a),    // 'a' - EAX, '=' - write only                                                                                                                                         // Colorize: green
                    "=b" (*b),    // 'b' - EBX, '=' - write only                                                                                                                                         // Colorize: green
                    "=c" (*c),    // 'c' - ECX, '=' - write only                                                                                                                                         // Colorize: green
                    "=d" (*d)     // 'd' - EDX, '=' - write only                                                                                                                                         // Colorize: green
                :                 // Input parameters                                                                                                                                                    // Colorize: green
                    "a" (leaf),   // 'a' - EAX // Ignore CppSingleCharVerifier                                                                                                                           // Colorize: green
                    "c" (subLeaf) // 'c' - ECX // Ignore CppSingleCharVerifier                                                                                                                           // Colorize: green
        );                                                                                                                                                                                               // Colorize: green
        // Ignore CppAlignmentVerifier [END]                                                                                                                                                             // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::initCpuFeatures()                                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    u32 ignored;                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get largest standard function and vendor ID                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Cpuid00000000Eax cpuid00000000Eax;                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Call cpuid                                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                               // Colorize: green
                                        CpuidLeaf::VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION,                                                                                                              // Colorize: green
                                        CpuidSubLeaf::NONE,                                                                                                                                              // Colorize: green
                                        &cpuid00000000Eax.value32,                                                                                                                                       // Colorize: green
                                        &sVendor.uints[0],                                                                                                                                               // Colorize: green
                                        &sVendor.uints[2],                                                                                                                                               // Colorize: green
                                        &sVendor.uints[1]                                                                                                                                                // Colorize: green
                                    ), NgosStatus::ASSERTION);                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Validation                                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("cpuid00000000Eax.largestFunction = 0x%08X", cpuid00000000Eax.largestFunction));                                                                                            // Colorize: green
                COMMON_LVVV(("cpuid00000000Eax.value32         = 0x%08X", cpuid00000000Eax.value32));                                                                                                    // Colorize: green
                COMMON_LVVV(("sVendor.uints[0]                 = 0x%08X", sVendor.uints[0]));                                                                                                            // Colorize: green
                COMMON_LVVV(("sVendor.uints[1]                 = 0x%08X", sVendor.uints[1]));                                                                                                            // Colorize: green
                COMMON_LVVV(("sVendor.uints[2]                 = 0x%08X", sVendor.uints[2]));                                                                                                            // Colorize: green
                COMMON_LVVV(("sVendor.chars                    = %.12s",  sVendor.chars));                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_TEST_ASSERT(cpuid00000000Eax.largestFunction           == 0x0000000D, NgosStatus::ASSERTION);                                                                      // Colorize: green
                COMMON_TEST_ASSERT(cpuid00000000Eax.value32                   == 0x0000000D, NgosStatus::ASSERTION);                                                                      // Colorize: green
                COMMON_TEST_ASSERT(sVendor.uints[0]                           == 0x756E6547, NgosStatus::ASSERTION);                                                                      // Colorize: green
                COMMON_TEST_ASSERT(sVendor.uints[1]                           == 0x49656E69, NgosStatus::ASSERTION);                                                                      // Colorize: green
                COMMON_TEST_ASSERT(sVendor.uints[2]                           == 0x6C65746E, NgosStatus::ASSERTION);                                                                      // Colorize: green
                COMMON_TEST_ASSERT(strncmp(sVendor.chars, "GenuineIntel", 12) == 0,          NgosStatus::ASSERTION);                                                                      // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Get sCpuidLevel                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            sCpuidLevel = static_cast<CpuidLeaf>(cpuid00000000Eax.largestFunction);                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Validation                                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("sCpuidLevel = %s", enumToFullString(sCpuidLevel)));                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_TEST_ASSERT(sCpuidLevel == CpuidLeaf::XSAVE_FEATURES, NgosStatus::ASSERTION);                                                                                                     // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Detect CPU vendor base on Vendor ID                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (sVendor.isIntel())                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("Intel CPU detected"));                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            sCpuVendor = CpuVendor::INTEL;                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        if (sVendor.isAMD())                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("AMD CPU detected"));                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            sCpuVendor = CpuVendor::AMD;                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LW(("Unknown CPU detected"));                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            sCpuVendor = CpuVendor::UNKNOWN;                                                                                                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Validation                                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVVV(("sCpuVendor = %s", enumToFullString(sCpuVendor)));                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_TEST_ASSERT(sCpuVendor == CpuVendor::INTEL, NgosStatus::ASSERTION);                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Do preprocessing here in order to remove MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT and get non-limited sCpuidLevel                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_ASSERT_EXECUTION(doPreprocessing(), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Handle general CPUID levels                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        do                                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            // Handle CPUID 0x00000001 == CpuidLeaf::FEATURE_INFORMATION                                                                                                                                 // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sCpuidLevel >= CpuidLeaf::FEATURE_INFORMATION)                                                                                                                                       // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    Cpuid00000001Eax cpuid00000001Eax;                                                                                                                                                   // Colorize: green
                    Cpuid00000001Ebx cpuid00000001Ebx;                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::FEATURE_INFORMATION,                                                                                                                      // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &cpuid00000001Eax.value32,                                                                                                                           // Colorize: green
                                                    &cpuid00000001Ebx.value32,                                                                                                                           // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000001_ECX)],                                                                            // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000001_EDX)]                                                                             // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.stepping                     = %u",     cpuid00000001Eax.stepping));                                                                          // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.model                        = %u",     cpuid00000001Eax.model));                                                                             // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.modelReal()                  = %u",     cpuid00000001Eax.modelReal()));                                                                       // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.family                       = %u",     cpuid00000001Eax.family));                                                                            // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.familyReal()                 = %u",     cpuid00000001Eax.familyReal()));                                                                      // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.processorType                = %u",     cpuid00000001Eax.processorType));                                                                     // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax._reserved                    = %u",     cpuid00000001Eax._reserved));                                                                         // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.extendedModel                = %u",     cpuid00000001Eax.extendedModel));                                                                     // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.extendedFamily               = %u",     cpuid00000001Eax.extendedFamily));                                                                    // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax._reserved2                   = %u",     cpuid00000001Eax._reserved2));                                                                        // Colorize: green
                            COMMON_LVVV(("cpuid00000001Eax.value32                      = 0x%08X", cpuid00000001Eax.value32));                                                                           // Colorize: green
                            COMMON_LVVV(("cpuid00000001Ebx.brandIndex                   = %u",     cpuid00000001Ebx.brandIndex));                                                                        // Colorize: green
                            COMMON_LVVV(("cpuid00000001Ebx.cacheLineFlushSize           = %u",     cpuid00000001Ebx.cacheLineFlushSize));                                                                // Colorize: green
                            COMMON_LVVV(("cpuid00000001Ebx.cacheLineFlushSizeReal()     = %u",     cpuid00000001Ebx.cacheLineFlushSizeReal()));                                                          // Colorize: green
                            COMMON_LVVV(("cpuid00000001Ebx.numberOfApicIdsPerPackage    = %u",     cpuid00000001Ebx.numberOfApicIdsPerPackage));                                                         // Colorize: green
                            COMMON_LVVV(("cpuid00000001Ebx.localApicId                  = %u",     cpuid00000001Ebx.localApicId));                                                                       // Colorize: green
                            COMMON_LVVV(("cpuid00000001Ebx.value32                      = 0x%08X", cpuid00000001Ebx.value32));                                                                           // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_00000001_ECX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000001_ECX)]));                            // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_00000001_EDX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000001_EDX)]));                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.stepping                                               == 3,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.model                                                  == 14,                                                                                 NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.modelReal()                                            == 94,                                                                                 NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.family                                                 == 6,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.familyReal()                                           == 6,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.processorType                                          == static_cast<good_Enum_t>(CpuidProcessorType::ORIGINAL_EQUIPMENT_MANUFACTURER_PROCESSOR), NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax._reserved                                              == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.extendedModel                                          == 5,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.extendedFamily                                         == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax._reserved2                                             == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Eax.value32                                                == 0x000506E3,                                                                         NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Ebx.brandIndex                                             == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Ebx.cacheLineFlushSize                                     == 8,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Ebx.cacheLineFlushSizeReal()                               == 64,                                                                                 NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Ebx.numberOfApicIdsPerPackage                              == 4,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Ebx.localApicId                                            == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid00000001Ebx.value32                                                == 0x00040800,                                                                         NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000001_ECX)] == 0xD7FA2223,                                                                         NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000001_EDX)] == 0x178BFBFF,                                                                         NgosStatus::ASSERTION); // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Get family / model / stepping                                                                                                                                                     // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        sFamily   = static_cast<CpuFamily>(cpuid00000001Eax.familyReal());                                                                                                               // Colorize: green
                        sModel    = cpuid00000001Eax.modelReal();                                                                                                                                        // Colorize: green
                        sStepping = cpuid00000001Eax.stepping;                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sFamily   = %s", enumToFullString(sCpuVendor, sFamily)));                                                                                                      // Colorize: green
                            COMMON_LVVV(("sModel    = %s", enumToFullString(sCpuVendor, sFamily, sModel)));                                                                                              // Colorize: green
                            COMMON_LVVV(("sStepping = %u", sStepping));                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sFamily   == CpuFamily::INTEL_FAMILY_6,                                          NgosStatus::ASSERTION);                                                  // Colorize: green
                            COMMON_TEST_ASSERT(sModel    == static_cast<good_Enum_t>(IntelCpuModel::FAMILY_6_SKYLAKE_CLIENT_H), NgosStatus::ASSERTION);                                                  // Colorize: green
                            COMMON_TEST_ASSERT(sStepping == 3,                                                                  NgosStatus::ASSERTION);                                                  // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Get cache line flush size                                                                                                                                                         // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        if (hasFeature(X86Feature::CLFLUSH))                                                                                                                                             // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVV(("X86Feature::CLFLUSH supported"));                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            sCacheLineFlushSize = cpuid00000001Ebx.cacheLineFlushSizeReal();                                                                                                             // Colorize: green
                            sCacheAlignment     = sCacheLineFlushSize;                                                                                                                                   // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sCacheLineFlushSize = %u", sCacheLineFlushSize));                                                                                                              // Colorize: green
                            COMMON_LVVV(("sCacheAlignment     = %u", sCacheAlignment));                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sCacheLineFlushSize == 64, NgosStatus::ASSERTION);                                                                                                        // Colorize: green
                            COMMON_TEST_ASSERT(sCacheAlignment     == 64, NgosStatus::ASSERTION);                                                                                                        // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Get number of APIC IDs per package                                                                                                                                                // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        if (hasFeature(X86Feature::HT))                                                                                                                                                  // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVV(("X86Feature::HT supported"));                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            sNumberOfApicIdsPerPackage = cpuid00000001Ebx.numberOfApicIdsPerPackage;                                                                                                     // Colorize: green
                            sX86CoreIdBits             = BitUtils::getCountOrder16(sNumberOfApicIdsPerPackage);                                                                                          // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sNumberOfApicIdsPerPackage = %u", sNumberOfApicIdsPerPackage));                                                                                                // Colorize: green
                            COMMON_LVVV(("sX86CoreIdBits             = %d", sX86CoreIdBits));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sNumberOfApicIdsPerPackage == 4, NgosStatus::ASSERTION);                                                                                                  // Colorize: green
                            COMMON_TEST_ASSERT(sX86CoreIdBits             == 2, NgosStatus::ASSERTION);                                                                                                  // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x00000006 == CpuidLeaf::DIGITAL_THERMAL_SENSOR_AND_POWER_MANAGEMENT_PARAMETERS                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sCpuidLevel >= CpuidLeaf::DIGITAL_THERMAL_SENSOR_AND_POWER_MANAGEMENT_PARAMETERS)                                                                                                    // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::DIGITAL_THERMAL_SENSOR_AND_POWER_MANAGEMENT_PARAMETERS,                                                                                   // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000006_EAX)],                                                                            // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored                                                                                                                                             // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_00000006_EAX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000006_EAX)]));                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000006_EAX)] == 0x00000004, NgosStatus::ASSERTION);                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x00000007 == CpuidLeaf::STRUCTURED_EXTENDED_FEATURE_FLAGS_ENUMERATION                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sCpuidLevel >= CpuidLeaf::STRUCTURED_EXTENDED_FEATURE_FLAGS_ENUMERATION)                                                                                                             // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::STRUCTURED_EXTENDED_FEATURE_FLAGS_ENUMERATION,                                                                                            // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_EBX)],                                                                                                 // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_ECX)],                                                                                                 // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_EDX)]                                                                                                  // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                        // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_00000007_EBX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_EBX)]));                            // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_00000007_ECX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_ECX)]));                            // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_00000007_EDX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_EDX)]));                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_EBX)] == 0x00840423, NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_ECX)] == 0x00000004, NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_00000007_EDX)] == 0x20000400, NgosStatus::ASSERTION);                                            // Colorize: green
                        }                                                                                                                                                                                    // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x0000000D == CpuidLeaf::XSAVE_FEATURES                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sCpuidLevel >= CpuidLeaf::XSAVE_FEATURES)                                                                                                                                            // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::XSAVE_FEATURES,                                                                                                                           // Colorize: green
                                                    CpuidSubLeaf::XSAVE_FEATURES_PROCESSOR_EXTENDED_STATE_ENUMERATION_1,                                                                                 // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000D_1_EAX)],                                                                                               // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored                                                                                                                                             // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                        // Colorize: green
                        {                                                                                                                                                                                    // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_0000000D_1_EAX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000D_1_EAX)]));                            // Colorize: green
                                                                                                                                                                                                             // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000D_1_EAX)] == 0x00000000, NgosStatus::ASSERTION);                                              // Colorize: green
                        }                                                                                                                                                                                    // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x0000000F == CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sCpuidLevel >= CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING)                                                                                                                              // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    Cpuid0000000FEbx0 cpuid0000000FEbx0;                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING,                                                                                                             // Colorize: green
                                                    CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING,                                                                                               // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &cpuid0000000FEbx0.value32,                                                                                                                          // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000F_0_EDX)]                                                                                                // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("cpuid0000000FEbx0.cacheMaxRmid                  = %u",     cpuid0000000FEbx0.cacheMaxRmid));                                                                   // Colorize: green
                            COMMON_LVVV(("cpuid0000000FEbx0.value32                       = 0x%08X", cpuid0000000FEbx0.value32));                                                                        // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_0000000F_0_EDX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000F_0_EDX)]));                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(cpuid0000000FEbx0.cacheMaxRmid                                            == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(cpuid0000000FEbx0.value32                                                 == 0x00040800,                                                                         NgosStatus::ASSERTION); // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000F_0_EDX)] == 0xD7FA2223,                                                                         NgosStatus::ASSERTION); // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Get sCacheMaxRmid and sCacheOccScale                                                                                                                                              // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        if (hasFeature(X86Feature::CQM_LLC))                                                                                                                                             // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVV(("X86Feature::CQM_LLC supported"));                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            sCacheMaxRmid = cpuid0000000FEbx0.cacheMaxRmid;                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            Cpuid0000000FEbx1 cpuid0000000FEbx1;                                                                                                                                         // Colorize: green
                            Cpuid0000000FEcx1 cpuid0000000FEcx1;                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            // Call cpuid                                                                                                                                                                // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                           // Colorize: green
                                                            CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING,                                                                                                     // Colorize: green
                                                            CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING_L3_CACHE,                                                                                         // Colorize: green
                                                            &ignored,                                                                                                                                    // Colorize: green
                                                            &cpuid0000000FEbx1.value32,                                                                                                                  // Colorize: green
                                                            &cpuid0000000FEcx1.value32,                                                                                                                  // Colorize: green
                                                            &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000F_1_EDX)]                                                                                        // Colorize: green
                                                        ), NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                // Validation                                                                                                                                                            // Colorize: green
                                {                                                                                                                                                                        // Colorize: green
                                    COMMON_LVVV(("cpuid0000000FEbx1.cacheOccScale                 = %u",     cpuid0000000FEbx1.cacheOccScale));                                                          // Colorize: green
                                    COMMON_LVVV(("cpuid0000000FEbx1.value32                       = 0x%08X", cpuid0000000FEbx1.value32));                                                                // Colorize: green
                                    COMMON_LVVV(("cpuid0000000FEcx1.cacheMaxRmid                  = %u",     cpuid0000000FEcx1.cacheMaxRmid));                                                           // Colorize: green
                                    COMMON_LVVV(("cpuid0000000FEcx1.value32                       = 0x%08X", cpuid0000000FEcx1.value32));                                                                // Colorize: green
                                    COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_0000000F_1_EDX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000F_1_EDX)]));                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                    COMMON_TEST_ASSERT(cpuid0000000FEbx1.cacheOccScale                                           == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                                    COMMON_TEST_ASSERT(cpuid0000000FEbx1.value32                                                 == 0x00040800,                                                                         NgosStatus::ASSERTION); // Colorize: green
                                    COMMON_TEST_ASSERT(cpuid0000000FEcx1.cacheMaxRmid                                            == 0,                                                                                  NgosStatus::ASSERTION); // Colorize: green
                                    COMMON_TEST_ASSERT(cpuid0000000FEcx1.value32                                                 == 0x00040800,                                                                         NgosStatus::ASSERTION); // Colorize: green
                                    COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_0000000F_1_EDX)] == 0xD7FA2223,                                                                         NgosStatus::ASSERTION); // Colorize: green
                                }                                                                                                                                                                        // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            if (                                                                                                                                                                         // Colorize: green
                                hasFeature(X86Feature::CQM_OCCUP_LLC)                                                                                                                                    // Colorize: green
                                ||                                                                                                                                                                       // Colorize: green
                                hasFeature(X86Feature::CQM_MBM_TOTAL)                                                                                                                                    // Colorize: green
                                ||                                                                                                                                                                       // Colorize: green
                                hasFeature(X86Feature::CQM_MBM_LOCAL)                                                                                                                                    // Colorize: green
                               )                                                                                                                                                                         // Colorize: green
                            {                                                                                                                                                                            // Colorize: green
                                COMMON_LVV(("X86Feature::CQM_OCCUP_LLC, X86Feature::CQM_MBM_TOTAL or X86Feature::CQM_MBM_LOCAL supported"));                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                sCacheMaxRmid  = cpuid0000000FEcx1.cacheMaxRmid;                                                                                                                         // Colorize: green
                                sCacheOccScale = cpuid0000000FEbx1.cacheOccScale;                                                                                                                        // Colorize: green
                            }                                                                                                                                                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sCacheMaxRmid  = %d", sCacheMaxRmid));                                                                                                // Colorize: green
                            COMMON_LVVV(("sCacheOccScale = %d", sCacheOccScale));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sCacheMaxRmid  == 0, NgosStatus::ASSERTION);                                                                                                  // Colorize: green
                            COMMON_TEST_ASSERT(sCacheOccScale == 0, NgosStatus::ASSERTION);                                                                                                  // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        } while(true);                                                                                                                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get largest extended function                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Cpuid80000000Eax cpuid80000000Eax;                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Call cpuid                                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                               // Colorize: green
                                        CpuidLeaf::LARGEST_EXTENDED_FUNCTION,                                                                                                                            // Colorize: green
                                        CpuidSubLeaf::NONE,                                                                                                                                              // Colorize: green
                                        &cpuid80000000Eax.value32,                                                                                                                                       // Colorize: green
                                        &ignored,                                                                                                                                                        // Colorize: green
                                        &ignored,                                                                                                                                                        // Colorize: green
                                        &ignored                                                                                                                                                         // Colorize: green
                                    ), NgosStatus::ASSERTION);                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Validation                                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("cpuid80000000Eax.largestFunction = 0x%08X", cpuid80000000Eax.largestFunction));                                                                                            // Colorize: green
                COMMON_LVVV(("cpuid80000000Eax.value32         = 0x%08X", cpuid80000000Eax.value32));                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_TEST_ASSERT(cpuid80000000Eax.largestFunction == 0x80000008, NgosStatus::ASSERTION);                                                                      // Colorize: green
                COMMON_TEST_ASSERT(cpuid80000000Eax.value32         == 0x80000008, NgosStatus::ASSERTION);                                                                      // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        // Get sExtendedCpuidLevel                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            sExtendedCpuidLevel = static_cast<CpuidLeaf>(cpuid80000000Eax.largestFunction);                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Validation                                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LVVV(("sExtendedCpuidLevel = %s", enumToFullString(sExtendedCpuidLevel)));                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_TEST_ASSERT(sExtendedCpuidLevel == CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES, NgosStatus::ASSERTION);                                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Handle extended CPUID levels                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        do                                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            // Handle CPUID 0x80000001 == CpuidLeaf::EXTENDED_FEATURE_BITS                                                                                                                               // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sExtendedCpuidLevel >= CpuidLeaf::EXTENDED_FEATURE_BITS)                                                                                                                             // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::EXTENDED_FEATURE_BITS,                                                                                                                    // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000001_ECX)],                                                                                                 // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000001_EDX)]                                                                                                  // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_80000001_ECX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000001_ECX)]));                            // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_80000001_EDX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000001_EDX)]));                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000001_ECX)] == 0x00000121, NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000001_EDX)] == 0x2C100800, NgosStatus::ASSERTION);                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x80000002 - 0x80000004 == CpuidLeaf::PROCESSOR_BRAND_STRING_1 - CpuidLeaf::PROCESSOR_BRAND_STRING_3                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sExtendedCpuidLevel >= CpuidLeaf::PROCESSOR_BRAND_STRING_3)                                                                                                                          // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(CpuidLeaf::PROCESSOR_BRAND_STRING_1, CpuidSubLeaf::NONE, &sModelName.uints[0], &sModelName.uints[1], &sModelName.uints[2],  &sModelName.uints[3]),  NgosStatus::ASSERTION); // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(CpuidLeaf::PROCESSOR_BRAND_STRING_2, CpuidSubLeaf::NONE, &sModelName.uints[4], &sModelName.uints[5], &sModelName.uints[6],  &sModelName.uints[7]),  NgosStatus::ASSERTION); // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(CpuidLeaf::PROCESSOR_BRAND_STRING_3, CpuidSubLeaf::NONE, &sModelName.uints[8], &sModelName.uints[9], &sModelName.uints[10], &sModelName.uints[11]), NgosStatus::ASSERTION); // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sModelName.uints[0]  = 0x%08X", sModelName.uints[0]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[1]  = 0x%08X", sModelName.uints[1]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[2]  = 0x%08X", sModelName.uints[2]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[3]  = 0x%08X", sModelName.uints[3]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[4]  = 0x%08X", sModelName.uints[4]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[5]  = 0x%08X", sModelName.uints[5]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[6]  = 0x%08X", sModelName.uints[6]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[7]  = 0x%08X", sModelName.uints[7]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[8]  = 0x%08X", sModelName.uints[8]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[9]  = 0x%08X", sModelName.uints[9]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[10] = 0x%08X", sModelName.uints[10]));                                                                                                        // Colorize: green
                            COMMON_LVVV(("sModelName.uints[11] = 0x%08X", sModelName.uints[11]));                                                                                                        // Colorize: green
                            COMMON_LVVV(("sModelName.chars     = %.48s",  sModelName.chars));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[0]                                             == 0x65746E49, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[1]                                             == 0x6F43206C, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[2]                                             == 0x50206572, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[3]                                             == 0x65636F72, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[4]                                             == 0x726F7373, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[5]                                             == 0x6B532820, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[6]                                             == 0x6B616C79, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[7]                                             == 0x00002965, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[8]                                             == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[9]                                             == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[10]                                            == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[11]                                            == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(strncmp(sModelName.chars, "Intel Core Processor (Skylake)", 48) == 0,          NgosStatus::ASSERTION);                                                    // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Simplify model name                                                                                                                                                               // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(simplifyModelName(sModelName.chars), NgosStatus::ASSERTION);                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sModelName.uints[0]  = 0x%08X", sModelName.uints[0]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[1]  = 0x%08X", sModelName.uints[1]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[2]  = 0x%08X", sModelName.uints[2]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[3]  = 0x%08X", sModelName.uints[3]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[4]  = 0x%08X", sModelName.uints[4]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[5]  = 0x%08X", sModelName.uints[5]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[6]  = 0x%08X", sModelName.uints[6]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[7]  = 0x%08X", sModelName.uints[7]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[8]  = 0x%08X", sModelName.uints[8]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[9]  = 0x%08X", sModelName.uints[9]));                                                                                                         // Colorize: green
                            COMMON_LVVV(("sModelName.uints[10] = 0x%08X", sModelName.uints[10]));                                                                                                        // Colorize: green
                            COMMON_LVVV(("sModelName.uints[11] = 0x%08X", sModelName.uints[11]));                                                                                                        // Colorize: green
                            COMMON_LVVV(("sModelName.chars     = %.48s",  sModelName.chars));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[0]                                             == 0x65746E49, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[1]                                             == 0x6F43206C, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[2]                                             == 0x50206572, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[3]                                             == 0x65636F72, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[4]                                             == 0x726F7373, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[5]                                             == 0x6B532820, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[6]                                             == 0x6B616C79, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[7]                                             == 0x00002965, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[8]                                             == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[9]                                             == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[10]                                            == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(sModelName.uints[11]                                            == 0x00000000, NgosStatus::ASSERTION);                                                    // Colorize: green
                            COMMON_TEST_ASSERT(strncmp(sModelName.chars, "Intel Core Processor (Skylake)", 48) == 0,          NgosStatus::ASSERTION);                                                    // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x80000007 == CpuidLeaf::ADVANCED_POWER_MANAGEMENT                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sExtendedCpuidLevel >= CpuidLeaf::ADVANCED_POWER_MANAGEMENT)                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    Cpuid80000007Edx cpuid80000007Edx;                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::ADVANCED_POWER_MANAGEMENT,                                                                                                                // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000007_EBX)],                                                                                                 // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &cpuid80000007Edx.value32                                                                                                                            // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_80000007_EBX]    = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000007_EBX)]));                         // Colorize: green
                            COMMON_LVVV(("cpuid80000007Edx.advancedPowerManagementFeatures = %s",     flagsToFullString(cpuid80000007Edx.advancedPowerManagementFeatures)));                             // Colorize: green
                            COMMON_LVVV(("cpuid80000007Edx.value32                         = 0x%08X", cpuid80000007Edx.value32));                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000007_EBX)] == 0x2C100800, NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(cpuid80000007Edx.advancedPowerManagementFeatures                        == 0,          NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(cpuid80000007Edx.value32                                                == 0x000506E3, NgosStatus::ASSERTION);                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Get sPower                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        sPower = cpuid80000007Edx.advancedPowerManagementFeatures;                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sPower = %s", flagsToFullString(sPower)));                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sPower == 0, NgosStatus::ASSERTION);                                                                                                                      // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x80000008 == CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sExtendedCpuidLevel >= CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES)                                                                                                                // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    Cpuid80000008Eax cpuid80000008Eax;                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES,                                                                                                       // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &cpuid80000008Eax.value32,                                                                                                                           // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000008_EBX)],                                                                                                 // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored                                                                                                                                             // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("cpuid80000008Eax.physicalAddressBits             = %u",     cpuid80000008Eax.physicalAddressBits));                                                            // Colorize: green
                            COMMON_LVVV(("cpuid80000008Eax.virtualAddressBits              = %u",     cpuid80000008Eax.virtualAddressBits));                                                             // Colorize: green
                            COMMON_LVVV(("cpuid80000008Eax.guestPhysicalAddressBits        = %u",     cpuid80000008Eax.guestPhysicalAddressBits));                                                       // Colorize: green
                            COMMON_LVVV(("cpuid80000008Eax.value32                         = 0x%08X", cpuid80000008Eax.value32));                                                                        // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_80000008_EBX]    = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000008_EBX)]));                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(cpuid80000008Eax.physicalAddressBits                                    == 0,          NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(cpuid80000008Eax.virtualAddressBits                                     == 0,          NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(cpuid80000008Eax.guestPhysicalAddressBits                               == 0,          NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(cpuid80000008Eax.value32                                                == 0x000506E3, NgosStatus::ASSERTION);                                            // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_80000008_EBX)] == 0x2C100800, NgosStatus::ASSERTION);                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Get sPhysicalBits and sVirtualBits                                                                                                                                                // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        sPhysicalBits = cpuid80000008Eax.physicalAddressBits;                                                                                                                            // Colorize: green
                        sVirtualBits  = cpuid80000008Eax.virtualAddressBits;                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sPhysicalBits = %u", sPhysicalBits));                                                                                                                          // Colorize: green
                            COMMON_LVVV(("sVirtualBits  = %u", sVirtualBits));                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sPhysicalBits == 0, NgosStatus::ASSERTION);                                                                                                               // Colorize: green
                            COMMON_TEST_ASSERT(sVirtualBits  == 0, NgosStatus::ASSERTION);                                                                                                               // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Handle CPUID 0x8000000A == CpuidLeaf::SVM_FEATURES                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (sExtendedCpuidLevel >= CpuidLeaf::SVM_FEATURES)                                                                                                                                  // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    // Call cpuid                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                   // Colorize: green
                                                    CpuidLeaf::SVM_FEATURES,                                                                                                                         // Colorize: green
                                                    CpuidSubLeaf::NONE,                                                                                                                                  // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &ignored,                                                                                                                                            // Colorize: green
                                                    &sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_8000000A_EDX)]                                                                                                  // Colorize: green
                                                ), NgosStatus::ASSERTION);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        // Validation                                                                                                                                                                    // Colorize: green
                        {                                                                                                                                                                                // Colorize: green
                            COMMON_LVVV(("sFeatures[x86FeatureWord::CPUID_8000000A_EDX] = 0x%08X", sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_8000000A_EDX)]));                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                            COMMON_TEST_ASSERT(sFeatures[static_cast<good_Enum_t>(x86FeatureWord::CPUID_8000000A_EDX)] == 0x2C100800, NgosStatus::ASSERTION);                                            // Colorize: green
                        }                                                                                                                                                                                // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        } while(true);                                                                                                                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::doPreprocessing()                                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Perform preprocessing base on CPU vendor                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        switch (sCpuVendor)                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            case CpuVendor::INTEL:                                                                                                                                                                       // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_ASSERT_EXECUTION(doIntelPreprocessing(), NgosStatus::ASSERTION);                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            case CpuVendor::AMD:                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_ASSERT_EXECUTION(doAmdPreprocessing(), NgosStatus::ASSERTION);                                                                                                                    // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            case CpuVendor::NONE:                                                                                                                                                                        // Colorize: green
            case CpuVendor::UNKNOWN:                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LF(("Unexpected CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            default:                                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LF(("Unknown CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));                                                                                           // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(doCommonPreprocessing(), NgosStatus::ASSERTION);                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::doIntelPreprocessing()                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Clear MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        NgosStatus status = MSR::clearBit(MSR_IA32_MISC_ENABLE, MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT);                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (status == NgosStatus::OK)                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT successfully cleared"));                                                                                                                    // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        if (status == NgosStatus::NO_EFFECT)                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT already cleared"));                                                                                                                         // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("Failed to reset MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT"));                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return NgosStatus::FAILED;                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Clear MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        NgosStatus status = MSR::clearBit(MSR_IA32_MISC_ENABLE, MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT);                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (status == NgosStatus::OK)                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT successfully cleared"));                                                                                                                   // Colorize: green
            COMMON_LVV(("Updating CPUID level"));                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            // Get largest standard function                                                                                                                                                             // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                Cpuid00000000Eax cpuid00000000Eax;                                                                                                                                                       // Colorize: green
                u32              ignored;                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                // Call cpuid                                                                                                                                                                            // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                       // Colorize: green
                                                CpuidLeaf::VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION,                                                                                                      // Colorize: green
                                                CpuidSubLeaf::NONE,                                                                                                                                      // Colorize: green
                                                &cpuid00000000Eax.value32,                                                                                                                               // Colorize: green
                                                &ignored,                                                                                                                                                // Colorize: green
                                                &ignored,                                                                                                                                                // Colorize: green
                                                &ignored                                                                                                                                                 // Colorize: green
                                            ), NgosStatus::ASSERTION);                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Validation                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("cpuid00000000Eax.largestFunction = 0x%08X", cpuid00000000Eax.largestFunction));                                                                                    // Colorize: green
                        COMMON_LVVV(("cpuid00000000Eax.value32         = 0x%08X", cpuid00000000Eax.value32));                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        COMMON_TEST_ASSERT(cpuid00000000Eax.largestFunction == 0x0000000D, NgosStatus::ASSERTION);                                                                        // Colorize: green
                        COMMON_TEST_ASSERT(cpuid00000000Eax.value32         == 0x0000000D, NgosStatus::ASSERTION);                                                                        // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                // Get sCpuidLevel                                                                                                                                                                       // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    sCpuidLevel = static_cast<CpuidLeaf>(cpuid00000000Eax.largestFunction);                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    // Validation                                                                                                                                                                        // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        COMMON_LVVV(("sCpuidLevel = %s", enumToFullString(sCpuidLevel)));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        COMMON_TEST_ASSERT(sCpuidLevel == CpuidLeaf::XSAVE_FEATURES, NgosStatus::ASSERTION);                                                                                             // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        if (status == NgosStatus::NO_EFFECT)                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT already cleared"));                                                                                                                        // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("Failed to reset MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT"));                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return NgosStatus::FAILED;                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::doAmdPreprocessing()                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::doCommonPreprocessing()                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::initScatteredFeatures()                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::APERFMPERF,    CpuidLeaf::DIGITAL_THERMAL_SENSOR_AND_POWER_MANAGEMENT_PARAMETERS, CpuidSubLeaf::NONE,                                             CPUID_ECX, 0),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::EPB,           CpuidLeaf::DIGITAL_THERMAL_SENSOR_AND_POWER_MANAGEMENT_PARAMETERS, CpuidSubLeaf::NONE,                                             CPUID_ECX, 3),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CAT_L3,        CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,                CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,          CPUID_EBX, 1),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CAT_L2,        CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,                CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,          CPUID_EBX, 2),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::MBA,           CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,                CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,          CPUID_EBX, 3),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CDP_L3,        CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,                CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION_L3_CACHE, CPUID_ECX, 2),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CDP_L2,        CpuidLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION,                CpuidSubLeaf::RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION_L2_CACHE, CPUID_ECX, 2),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::HW_PSTATE,     CpuidLeaf::ADVANCED_POWER_MANAGEMENT,                              CpuidSubLeaf::NONE,                                             CPUID_EDX, 7),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::CPB,           CpuidLeaf::ADVANCED_POWER_MANAGEMENT,                              CpuidSubLeaf::NONE,                                             CPUID_EDX, 9),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::PROC_FEEDBACK, CpuidLeaf::ADVANCED_POWER_MANAGEMENT,                              CpuidSubLeaf::NONE,                                             CPUID_EDX, 11), NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::SME,           CpuidLeaf::ENCRYPTED_MEMORY_CAPABILITIES,                          CpuidSubLeaf::NONE,                                             CPUID_EAX, 0),  NgosStatus::ASSERTION); // Colorize: green
    COMMON_ASSERT_EXECUTION(setScatteredFeature(X86Feature::SEV,           CpuidLeaf::ENCRYPTED_MEMORY_CAPABILITIES,                          CpuidSubLeaf::NONE,                                             CPUID_EAX, 1),  NgosStatus::ASSERTION); // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::setScatteredFeature(X86Feature feature, CpuidLeaf leaf, CpuidSubLeaf subLeaf, good_U8 registerId, good_U8 bit)                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | feature = %s, leaf = %s, subLeaf = %s, registerId = %u, bit = %u", enumToFullString(feature), enumToFullString(leaf), enumToFullString(leaf, subLeaf), registerId, bit));             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(registerId < 4, "registerId is invalid", NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
    COMMON_ASSERT(bit < 32,       "bit is invalid",        NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    CpuidLeaf maximumLevel;                                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get maximum level                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (static_cast<good_Enum_t>(leaf) >= CPUID_LEVEL_LOWER_BOUND && static_cast<good_Enum_t>(leaf) <= CPUID_LEVEL_UPPER_BOUND)                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            maximumLevel = sCpuidLevel;                                                                                                                                                                  // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        if (static_cast<good_Enum_t>(leaf) >= EXT_CPUID_LEVEL_LOWER_BOUND && static_cast<good_Enum_t>(leaf) <= EXT_CPUID_LEVEL_UPPER_BOUND)                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            maximumLevel = sExtendedCpuidLevel;                                                                                                                                                          // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LE(("Unexpected leaf = %s", enumToString(leaf)));                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return NgosStatus::INVALID_DATA;                                                                                                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (maximumLevel >= leaf)                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        good_U32 registers[4];                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(cpuid(                                                                                                                                                                   // Colorize: green
                                    leaf,                                                                                                                                                                // Colorize: green
                                    subLeaf,                                                                                                                                                             // Colorize: green
                                    &registers[0],                                                                                                                                                       // Colorize: green
                                    &registers[1],                                                                                                                                                       // Colorize: green
                                    &registers[2],                                                                                                                                                       // Colorize: green
                                    &registers[3]                                                                                                                                                        // Colorize: green
                                ), NgosStatus::ASSERTION);                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if ((registers[registerId] & (1ULL << bit)) != 0)                                                                                                                                                // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_ASSERT_EXECUTION(setFeature(feature), NgosStatus::ASSERTION);                                                                                                                         // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::initSpeculationControl()                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::SPEC_CTRL))                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::SPEC_CTRL supported"));                                                                                                                                                 // Colorize: green
        COMMON_LVV(("X86Feature::IBRS set because X86Feature::SPEC_CTRL supported"));                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::IBPB set because X86Feature::SPEC_CTRL supported"));                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::SPEC_CTRL supported"));                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBRS),          NgosStatus::ASSERTION);                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBPB),          NgosStatus::ASSERTION);                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::INTEL_STIBP))                                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::INTEL_STIBP supported"));                                                                                                                                               // Colorize: green
        COMMON_LVV(("X86Feature::STIBP set because X86Feature::INTEL_STIBP supported"));                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::STIBP), NgosStatus::ASSERTION);                                                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::SPEC_CTRL_SSBD) || hasFeature(X86Feature::VIRT_SSBD))                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::SPEC_CTRL_SSBD or X86Feature::VIRT_SSBD supported"));                                                                                                                   // Colorize: green
        COMMON_LVV(("X86Feature::SSBD set because X86Feature::SPEC_CTRL_SSBD supported"));                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::SSBD), NgosStatus::ASSERTION);                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::AMD_IBRS))                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::AMD_IBRS supported"));                                                                                                                                                  // Colorize: green
        COMMON_LVV(("X86Feature::IBRS set because X86Feature::AMD_IBRS supported"));                                                                                                                     // Colorize: green
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_IBRS supported"));                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBRS),          NgosStatus::ASSERTION);                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::AMD_IBPB))                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::AMD_IBPB supported"));                                                                                                                                                  // Colorize: green
        COMMON_LVV(("X86Feature::IBPB set because X86Feature::AMD_IBPB supported"));                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::IBPB), NgosStatus::ASSERTION);                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::AMD_STIBP))                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::AMD_STIBP supported"));                                                                                                                                                 // Colorize: green
        COMMON_LVV(("X86Feature::STIBP set because X86Feature::AMD_STIBP supported"));                                                                                                                   // Colorize: green
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_STIBP supported"));                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::STIBP),         NgosStatus::ASSERTION);                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (hasFeature(X86Feature::AMD_SSBD))                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::AMD_SSBD supported"));                                                                                                                                                  // Colorize: green
        COMMON_LVV(("X86Feature::SSBD set because X86Feature::AMD_SSBD supported"));                                                                                                                     // Colorize: green
        COMMON_LVV(("X86Feature::MSR_SPEC_CTRL set because X86Feature::AMD_SSBD supported"));                                                                                                            // Colorize: green
        COMMON_LVV(("X86Feature::VIRT_SSBD resetted because X86Feature::AMD_SSBD supported"));                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::SSBD),          NgosStatus::ASSERTION);                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::MSR_SPEC_CTRL), NgosStatus::ASSERTION);                                                                                                           // Colorize: green
        COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::VIRT_SSBD),   NgosStatus::ASSERTION);                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::doPostprocessing()                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (sCpuVendor)                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuVendor::INTEL:                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_ASSERT_EXECUTION(doIntelPostprocessing(), NgosStatus::ASSERTION);                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        case CpuVendor::AMD:                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_ASSERT_EXECUTION(doAmdPostprocessing(), NgosStatus::ASSERTION);                                                                                                                       // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        case CpuVendor::NONE:                                                                                                                                                                            // Colorize: green
        case CpuVendor::UNKNOWN:                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("Unexpected CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default:                                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LF(("Unknown CPU vendor %s, %s:%u", enumToFullString(sCpuVendor), __FILE__, __LINE__));                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT_EXECUTION(doCommonPostprocessing(), NgosStatus::ASSERTION);                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::doIntelPostprocessing()                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // All Intel CPUs support constant TSC                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LVV(("X86Feature::CONSTANT_TSC supported"));                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_ASSERT_EXECUTION(setFeature(X86Feature::CONSTANT_TSC), NgosStatus::ASSERTION);                                                                                                            // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
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



    // CpuidPowerFlag::TSC_INVARIANT means that TSC runs at constant rate with P/T states and does not stop in deep C-states.
    if ((sPower & FLAGS(CpuidPowerFlag::TSC_INVARIANT)) != 0)
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



    if (sCpuidLevel >= CpuidLeaf::X2APIC_FEATURES_AND_PROCESSOR_TOPOLOGY)
    {
        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(
                                    CpuidLeaf::X2APIC_FEATURES_AND_PROCESSOR_TOPOLOGY,
                                    CpuidSubLeaf::X2APIC_FEATURES_AND_PROCESSOR_TOPOLOGY_THREAD,
                                    &ignored,
                                    &sNumberOfCores,
                                    &ignored,
                                    &ignored),
                                    NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(cpuid(
                                    CpuidLeaf::X2APIC_FEATURES_AND_PROCESSOR_TOPOLOGY,
                                    CpuidSubLeaf::X2APIC_FEATURES_AND_PROCESSOR_TOPOLOGY_CORE,
                                    &ignored,
                                    &sNumberOfThreads,
                                    &ignored,
                                    &ignored),
                                    NgosStatus::ASSERTION);

        COMMON_TEST_ASSERT(sNumberOfThreads % sNumberOfCores == 0, NgosStatus::ASSERTION);

        sNumberOfCores = sNumberOfThreads / sNumberOfCores;
    }
    else
    if (sCpuidLevel >= CpuidLeaf::DETERMINISTIC_CACHE_PARAMETERS)
    {
        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(
                                    CpuidLeaf::DETERMINISTIC_CACHE_PARAMETERS,
                                    CpuidSubLeaf::NONE,
                                    &sNumberOfCores,
                                    &ignored,
                                    &ignored,
                                    &ignored
                                ), NgosStatus::ASSERTION);

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



    if (sExtendedCpuidLevel >= CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES)
    {
        u32 ignored;
        u32 ecx;

        COMMON_ASSERT_EXECUTION(cpuid(
                                    CpuidLeaf::VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES,
                                    CpuidSubLeaf::NONE,
                                    &ignored,
                                    &ignored,
                                    &ecx,
                                    &ignored
                                ), NgosStatus::ASSERTION);



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

    COMMON_TEST_ASSERT(sNumberOfThreads % sNumberOfCores == 0, NgosStatus::ASSERTION);



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
                                                                                                                                                                                                         // Colorize: green
NgosStatus CPU::filterFeaturesDependentOnCpuid()                                                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((""));                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Reset X86Feature::MWAIT if sCpuidLevel < 0x00000005                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (hasFeature(X86Feature::MWAIT) && sCpuidLevel < CpuidLeaf::MONITOR_AND_MWAIT_PARAMETERS)                                                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LW(("X86Feature::MWAIT resetted because sCpuidLevel < 0x00000005"));                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::MWAIT), NgosStatus::ASSERTION);                                                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Reset X86Feature::DCA if sCpuidLevel < 0x00000009                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (hasFeature(X86Feature::DCA) && sCpuidLevel < CpuidLeaf::DIRECT_CACHE_ACCESS_PARAMETERS)                                                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LW(("X86Feature::DCA resetted because sCpuidLevel < 0x00000009"));                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::DCA), NgosStatus::ASSERTION);                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Reset X86Feature::XSAVE if sCpuidLevel < 0x0000000D                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (hasFeature(X86Feature::XSAVE) && sCpuidLevel < CpuidLeaf::XSAVE_FEATURES)                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LW(("X86Feature::XSAVE resetted because sCpuidLevel < 0x0000000D"));                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            COMMON_ASSERT_EXECUTION(clearFeature(X86Feature::XSAVE), NgosStatus::ASSERTION);                                                                                                             // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
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



    COMMON_ASSERT_EXECUTION(MSR::write(MSR_IA32_MICROCODE_REV, 0), NgosStatus::ASSERTION);



    // Call cpuid with 0x00000001 to trigger microcode revision refresh
    {
        u32 ignored;

        COMMON_ASSERT_EXECUTION(cpuid(
                                    CpuidLeaf::FEATURE_INFORMATION,
                                    CpuidSubLeaf::NONE,
                                    &ignored,
                                    &ignored,
                                    &ignored,
                                    &ignored
                                ), NgosStatus::ASSERTION);
    }



    sMicrocodeRevision = (u32)(MSR::read(MSR_IA32_MICROCODE_REV) >> 32);



    return NgosStatus::OK;
}

NgosStatus CPU::simplifyModelName(good_Char8 modelName[48])                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | modelName = %p", modelName));                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(modelName != nullptr, "modelName is null", NgosStatus::ASSERTION);                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_I64 length = strnlen(modelName, sizeof(sModelName));                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Trim spaces on the right                                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        while (length > 0 && modelName[length - 1] == ' ')                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            modelName[length - 1] = 0;                                                                                                                                                                   // Colorize: green
            --length;                                                                                                                                                                                    // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Trim spaces on the left                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (modelName[0] == ' ')                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_I64 offset = 1;                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            while (modelName[offset] == ' ')                                                                                                                                                             // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                ++offset;                                                                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (good_I64 i = offset; i < length; ++i)                                                                                                                                                   // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                modelName[i - offset] = modelName[i];                                                                                                                                                    // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            memcpy(&modelName[0], &modelName[offset], length - offset);                                                                                                                                  // Colorize: green
            modelName[length - offset] = 0;                                                                                                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return NgosStatus::OK;                                                                                                                                                                               // Colorize: green
}                                                                                                                                                                                                        // Colorize: green

bool CPU::isIntelBadSpectreMicrocode()
{
    COMMON_LT((""));



    // Hypervisor lie to us on the microcode version so
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
