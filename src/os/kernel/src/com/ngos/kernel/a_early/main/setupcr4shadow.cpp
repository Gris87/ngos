#include "setupcr4shadow.h"

#include <com/ngos/kernel/other/cpu/percpu.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus setupCr4Shadow()
{
    EARLY_LT((""));



    PERCPU::cr4 = AsmUtils::readCr4();



    // Validation
    {
        EARLY_LVVV(("PERCPU::cr4 = %s", flagsToFullString(PERCPU::cr4)));



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        EARLY_TEST_ASSERT(PERCPU::cr4 == 0x000416E8, NgosStatus::ASSERTION);
#else
        EARLY_TEST_ASSERT(PERCPU::cr4 == 0x000406E8, NgosStatus::ASSERTION);
#endif
    }



    return NgosStatus::OK;
}
