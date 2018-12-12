#include "setupcr4shadow.h"

#include <asm/instructions.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/cpu/percpu.h>



NgosStatus setupCr4Shadow()
{
    EARLY_LT((""));



    PERCPU::cr4 = readCr4();

    EARLY_LVVV(("PERCPU::cr4 = 0x%016lX", PERCPU::cr4));

    EARLY_TEST_ASSERT(PERCPU::cr4 == 0xA0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
