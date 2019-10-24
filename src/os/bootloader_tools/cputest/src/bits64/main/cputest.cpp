#include "cputest.h"

#include <common/src/bits64/cpu/cpu.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#define CACHE_INFO_CPUID 0x00000002



NgosStatus CpuTest::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initCpuCaches(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTest::initCpuCaches()
{
    UEFI_LT((""));



    if (CPU::isCpuIdLevelSupported(CACHE_INFO_CPUID))
    {
        u32 registers[4];

        UEFI_ASSERT_EXECUTION(CPU::cpuid(CACHE_INFO_CPUID, 0, &registers[0], &registers[1], &registers[2], &registers[3]), NgosStatus::ASSERTION);



        u8 *registerByte = (u8 *)&registers[0];

        for (i64 i = 0; i < (i64)sizeof(registers); ++i)
        {
            UEFI_LVVV(("registerByte[%d] = 0x%02X", i, registerByte[i]));
        }
    }
    else
    {
        UEFI_LW(("CACHE_INFO_CPUID not supported"));
    }


    return NgosStatus::OK;
}
