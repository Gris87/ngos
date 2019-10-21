#include "cputest.h"

#include <common/src/bits64/cpu/cpu.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus CpuTest::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initCpuCaches(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTest::initCpuCaches()
{
    UEFI_LT((""));



    return NgosStatus::OK;
}
