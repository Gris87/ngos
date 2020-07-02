#include "setupcr4shadow.h"

#include <asm/instructions.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>

#include <src/com/ngos/kernel/other/cpu/percpu.h>



NgosStatus setupCr4Shadow()
{
    EARLY_LT((""));



    PERCPU::cr4 = readCr4();



    // Validation
    {
        EARLY_LVVV(("PERCPU::cr4 = 0x%016lX", PERCPU::cr4));



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        EARLY_TEST_ASSERT(PERCPU::cr4 == 0x000416E8, NgosStatus::ASSERTION);
#else
        EARLY_TEST_ASSERT(PERCPU::cr4 == 0x000406E8, NgosStatus::ASSERTION);
#endif
    }



    return NgosStatus::OK;
}
