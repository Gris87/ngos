#include "setupfirstcpu.h"

#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/cpu/cpumask.h>



NgosStatus setupFirstCpu()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(CpuMask::setCpuOnline(0,   true), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(CpuMask::setCpuActive(0,   true), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(CpuMask::setCpuPresent(0,  true), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(CpuMask::setCpuPossible(0, true), NgosStatus::ASSERTION);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
    EARLY_LVVV(("CpuMask::sOnlineCpus.mBits[0]   = 0x%016lX", CpuMask::sOnlineCpus.mBits[0]));
    EARLY_LVVV(("CpuMask::sActiveCpus.mBits[0]   = 0x%016lX", CpuMask::sActiveCpus.mBits[0]));
    EARLY_LVVV(("CpuMask::sPresentCpus.mBits[0]  = 0x%016lX", CpuMask::sPresentCpus.mBits[0]));
    EARLY_LVVV(("CpuMask::sPossibleCpus.mBits[0] = 0x%016lX", CpuMask::sPossibleCpus.mBits[0]));
#endif

    EARLY_TEST_ASSERT(CpuMask::sOnlineCpus.mBits[0]   == 0x0000000000000001, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(CpuMask::sActiveCpus.mBits[0]   == 0x0000000000000001, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(CpuMask::sPresentCpus.mBits[0]  == 0x0000000000000001, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(CpuMask::sPossibleCpus.mBits[0] == 0x0000000000000001, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
