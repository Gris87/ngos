#include "setupfirstcpu.h"

#include <com/ngos/kernel/other/cpu/cpumask.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus setupFirstCpu()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(CpuMask::setCpuOnline(0,   true), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(CpuMask::setCpuActive(0,   true), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(CpuMask::setCpuPresent(0,  true), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(CpuMask::setCpuPossible(0, true), NgosStatus::ASSERTION);



    // Validation
    {
#if NGOS_BUILD_TEST_MODE == OPTION_YES
        EARLY_LVVV(("CpuMask::sOnlineCpus.mBits[0]   = 0x%016llX", CpuMask::sOnlineCpus.mBits[0]));
        EARLY_LVVV(("CpuMask::sActiveCpus.mBits[0]   = 0x%016llX", CpuMask::sActiveCpus.mBits[0]));
        EARLY_LVVV(("CpuMask::sPresentCpus.mBits[0]  = 0x%016llX", CpuMask::sPresentCpus.mBits[0]));
        EARLY_LVVV(("CpuMask::sPossibleCpus.mBits[0] = 0x%016llX", CpuMask::sPossibleCpus.mBits[0]));
#endif



        EARLY_TEST_ASSERT(CpuMask::sOnlineCpus.mBits[0]   == 0x0000000000000001, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(CpuMask::sActiveCpus.mBits[0]   == 0x0000000000000001, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(CpuMask::sPresentCpus.mBits[0]  == 0x0000000000000001, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(CpuMask::sPossibleCpus.mBits[0] == 0x0000000000000001, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
