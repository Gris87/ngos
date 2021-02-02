#include "memorytest.h"

#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define CPU_SPEED_TIMEOUT (200 * UEFI_STALL_MILLISECOND)



bad_uint64 MemoryTest::sCpuSpeed;



NgosStatus MemoryTest::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initCpuSpeed(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

bad_uint64 MemoryTest::getCpuSpeed()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sCpuSpeed;
}

NgosStatus MemoryTest::initCpuSpeed()
{
    UEFI_LT((""));



    bad_uint64 startTSC = rdtsc();

    UEFI_ASSERT_EXECUTION(UEFI::stall(CPU_SPEED_TIMEOUT), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    bad_uint64 endTSC = rdtsc();
    bad_uint64 ticks  = endTSC - startTSC;



    UEFI_LVVV(("startTSC = %u", startTSC));
    UEFI_LVVV(("endTSC   = %u", endTSC));
    UEFI_LVVV(("ticks    = %u", ticks));



    sCpuSpeed = ticks * UEFI_STALL_SECOND / CPU_SPEED_TIMEOUT;



    return NgosStatus::OK;
}
