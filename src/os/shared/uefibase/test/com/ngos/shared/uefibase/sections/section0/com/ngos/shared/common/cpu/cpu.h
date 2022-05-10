#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CPU_CPU_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CPU_CPU_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_cpu_cpu);
{
    TEST_CASE("setFeature()/clearFeature()/hasFeature()");
    {
        u32 temp = CPU::sFeatures[(u64)x86FeatureWord::NGOS_OTHER_FEATURES];

        TEST_ASSERT_EQUALS(CPU::hasFeature(X86Feature::CPUID),                       true);
        TEST_ASSERT_EQUALS(CPU::hasFeature(X86Feature::ALWAYS_ZERO),                 false);
        TEST_ASSERT_EQUALS(CPU::sFeatures[(u64)x86FeatureWord::NGOS_OTHER_FEATURES], temp);

        TEST_ASSERT_EQUALS(CPU::setFeature(X86Feature::ALWAYS_ZERO),                 NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFeature(X86Feature::CPUID),                       true);
        TEST_ASSERT_EQUALS(CPU::hasFeature(X86Feature::ALWAYS_ZERO),                 true);
        TEST_ASSERT_EQUALS(CPU::sFeatures[(u64)x86FeatureWord::NGOS_OTHER_FEATURES], temp | 0x01);

        TEST_ASSERT_EQUALS(CPU::clearFeature(X86Feature::ALWAYS_ZERO),               NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFeature(X86Feature::CPUID),                       true);
        TEST_ASSERT_EQUALS(CPU::hasFeature(X86Feature::ALWAYS_ZERO),                 false);
        TEST_ASSERT_EQUALS(CPU::sFeatures[(u64)x86FeatureWord::NGOS_OTHER_FEATURES], temp);
    }
    TEST_CASE_END();



    TEST_CASE("setBug()/clearBug()/hasBug()");
    {
        u32 temp = CPU::sBugs[(u64)x86BugWord::NGOS_COMMON_BUGS];

        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),                     false);
        TEST_ASSERT_EQUALS(CPU::sBugs[(u64)x86BugWord::NGOS_COMMON_BUGS], temp);

        TEST_ASSERT_EQUALS(CPU::setBug(X86Bug::TEST),                     NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),                     true);
        TEST_ASSERT_EQUALS(CPU::sBugs[(u64)x86BugWord::NGOS_COMMON_BUGS], temp | 0x01);

        TEST_ASSERT_EQUALS(CPU::clearBug(X86Bug::TEST),                   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),                     false);
        TEST_ASSERT_EQUALS(CPU::sBugs[(u64)x86BugWord::NGOS_COMMON_BUGS], temp);
    }
    TEST_CASE_END();



    TEST_CASE("isCpuIdLevelSupported()");
    {
        u32 temp         = CPU::sCpuidLevel;
        CPU::sCpuidLevel = 5;

        TEST_ASSERT_EQUALS(CPU::isCpuIdLevelSupported(1), true);
        TEST_ASSERT_EQUALS(CPU::isCpuIdLevelSupported(5), true);
        TEST_ASSERT_EQUALS(CPU::isCpuIdLevelSupported(6), false);

        CPU::sCpuidLevel = temp;
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CPU_CPU_H
