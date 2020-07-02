#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_CPU_CPUMASK_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_CPU_CPUMASK_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/memory/memory.h>

#include <src/com/ngos/kernel/other/cpu/cpumask.h>
#include <test/com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_other_cpu_cpumask);
{
    TEST_CASE("setCpuOnline()");
    {
        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(0, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[0],     0x0000000000000001);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(5, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[0],     0x0000000000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(40, true),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[0],     0x0000010000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(100, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[1],     0x0000001000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(0, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[0],     0x0000010000000020);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(5, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[0],     0x0000010000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(40, false),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[0],     0x0000000000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuOnline(100, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sOnlineCpus.mBits[1],     0x0000000000000000);
    }
    TEST_CASE_END();



    TEST_CASE("setCpuActive()");
    {
        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(0, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[0],     0x0000000000000001);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(5, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[0],     0x0000000000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(40, true),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[0],     0x0000010000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(100, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[1],     0x0000001000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(0, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[0],     0x0000010000000020);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(5, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[0],     0x0000010000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(40, false),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[0],     0x0000000000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuActive(100, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sActiveCpus.mBits[1],     0x0000000000000000);
    }
    TEST_CASE_END();



    TEST_CASE("setCpuPresent()");
    {
        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(0, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[0],     0x0000000000000001);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(5, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[0],     0x0000000000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(40, true),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[0],     0x0000010000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(100, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[1],     0x0000001000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(0, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[0],     0x0000010000000020);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(5, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[0],     0x0000010000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(40, false),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[0],     0x0000000000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPresent(100, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPresentCpus.mBits[1],     0x0000000000000000);
    }
    TEST_CASE_END();



    TEST_CASE("setCpuPossible()");
    {
        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(0, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[0],     0x0000000000000001);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(5, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[0],     0x0000000000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(40, true),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[0],     0x0000010000000021);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(100, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[1],     0x0000001000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(0, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[0],     0x0000010000000020);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(5, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[0],     0x0000010000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(40, false),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[0],     0x0000000000000000);

        TEST_ASSERT_EQUALS(CpuMask::setCpuPossible(100, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(CpuMask::sPossibleCpus.mBits[1],     0x0000000000000000);
    }
    TEST_CASE_END();



    TEST_CASE("setCpuMask()");
    {
        CpuMask cpuMask;

        memzero(cpuMask.mBits, sizeof(cpuMask.mBits));

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(0, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[0],               0x0000000000000001);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(5, true),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[0],               0x0000000000000021);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(40, true),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[0],               0x0000010000000021);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(100, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[1],               0x0000001000000000);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(0, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[0],               0x0000010000000020);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(5, false),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[0],               0x0000010000000000);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(40, false),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[0],               0x0000000000000000);

        TEST_ASSERT_EQUALS(cpuMask.setCpuMask(100, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(cpuMask.mBits[1],               0x0000000000000000);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_CPU_CPUMASK_H
