#include "setupcr4shadow.h"

#include <asm/instructions.h>
#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/cpu/percpu.h>



NgosStatus setupCr4Shadow()
{
    EARLY_LT((""));



    PERCPU::cr4 = readCr4();

    EARLY_LVVV(("PERCPU::cr4 = 0x%016lX", PERCPU::cr4));

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_TEST_ASSERT(PERCPU::cr4 == 0x000416E8, NgosStatus::ASSERTION);
#else
    EARLY_TEST_ASSERT(PERCPU::cr4 == 0x000406E8, NgosStatus::ASSERTION);
#endif



    return NgosStatus::OK;
}
