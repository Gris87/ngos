#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_cpu_cpu);
{
    TEST_CASE("setFlag()/clearFlag()/hasFlag()");
    {
        u32 temp = CPU::sFlags[CPU_FEATURES_NGOS_OTHER_FLAGS];

        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),           true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),      false);
        TEST_ASSERT_EQUALS(CPU::sFlags[CPU_FEATURES_NGOS_OTHER_FLAGS], temp);

        TEST_ASSERT_EQUALS(CPU::setFlag(X86Feature::ALWAYS_ZERO),      NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),           true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),      true);
        TEST_ASSERT_EQUALS(CPU::sFlags[CPU_FEATURES_NGOS_OTHER_FLAGS], temp | 0x02);

        TEST_ASSERT_EQUALS(CPU::clearFlag(X86Feature::ALWAYS_ZERO),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),           true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),      false);
        TEST_ASSERT_EQUALS(CPU::sFlags[CPU_FEATURES_NGOS_OTHER_FLAGS], temp);
    }
    TEST_CASE_END();



    TEST_CASE("setBug()/clearBug()/hasBug()");
    {
        u32 temp = CPU::sBugs[CPU_BUGS_NGOS_COMMON_FLAGS];

        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),              false);
        TEST_ASSERT_EQUALS(CPU::sBugs[CPU_BUGS_NGOS_COMMON_FLAGS], temp);

        TEST_ASSERT_EQUALS(CPU::setBug(X86Bug::TEST),              NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),              true);
        TEST_ASSERT_EQUALS(CPU::sBugs[CPU_BUGS_NGOS_COMMON_FLAGS], temp | 0x01);

        TEST_ASSERT_EQUALS(CPU::clearBug(X86Bug::TEST),            NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),              false);
        TEST_ASSERT_EQUALS(CPU::sBugs[CPU_BUGS_NGOS_COMMON_FLAGS], temp);
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



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H
