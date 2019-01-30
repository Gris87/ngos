#include "fpu.h"

#include <asm/instructions.h>
#include <src/bits64/cpu/cpu.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/other/fpu/macros.h>



FpuState FPU::sState;
u32      FPU::sMxcsrMask;



NgosStatus FPU::init()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(fninit(), NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(initState(),     NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initMxcsrMask(), NgosStatus::ASSERTION);



    COMMON_LVVV(("sState.fxsave.cwd       = 0x%04X", sState.fxsave.cwd));
    COMMON_LVVV(("sState.fxsave.swd       = 0x%04X", sState.fxsave.swd));
    COMMON_LVVV(("sState.fxsave.twd       = 0x%04X", sState.fxsave.twd));
    COMMON_LVVV(("sState.fxsave.fop       = 0x%04X", sState.fxsave.fop));
    COMMON_LVVV(("sState.fxsave.fip       = 0x%08X", sState.fxsave.fip));
    COMMON_LVVV(("sState.fxsave.fcs       = 0x%08X", sState.fxsave.fcs));
    COMMON_LVVV(("sState.fxsave.foo       = 0x%08X", sState.fxsave.foo));
    COMMON_LVVV(("sState.fxsave.fos       = 0x%08X", sState.fxsave.fos));
    COMMON_LVVV(("sState.fxsave.mxcsr     = 0x%08X", sState.fxsave.mxcsr));
    COMMON_LVVV(("sState.fxsave.mxcsrMask = 0x%08X", sState.fxsave.mxcsrMask));

    for (i64 i = 0; i < 16; ++i)
    {
        COMMON_LVVV(("sState.fxsave.stack[%d] = 0x%016lX", i, sState.fxsave.stack[i]));
    }

    for (i64 i = 0; i < 16; ++i)
    {
        COMMON_LVVV(("sState.fxsave.xmms[%d][0] = 0x%016lX", i, sState.fxsave.xmms[i][0]));
        COMMON_LVVV(("sState.fxsave.xmms[%d][1] = 0x%016lX", i, sState.fxsave.xmms[i][1]));
    }

    COMMON_LVVV(("sMxcsrMask = 0x%08X", sMxcsrMask));



    return NgosStatus::OK;
}

NgosStatus FPU::initState()
{
    COMMON_LT((""));



    if (CPU::hasFlag(X86Feature::XSAVES))
    {
        COMMON_ASSERT_EXECUTION(initXState(), NgosStatus::ASSERTION);
    }

    COMMON_ASSERT_EXECUTION(initFXState(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus FPU::initXState()
{
    COMMON_LT((""));



    sState.xsave.header.xComponents = XCOMPONENTS_COMPACTED_FORMAT;



    return NgosStatus::OK;
}

NgosStatus FPU::initFXState()
{
    COMMON_LT((""));



    sState.fxsave.cwd   = CWD_DEFAULT;
    sState.fxsave.mxcsr = MXCSR_DEFAULT;



    return NgosStatus::OK;
}

NgosStatus FPU::initMxcsrMask()
{
    COMMON_LT((""));



    // Static because GCC does not get 16-byte stack alignment right
    static FXSaveState fxsaveState;

    COMMON_ASSERT_EXECUTION(fxsave((u8 *)&fxsaveState), NgosStatus::ASSERTION);



    sMxcsrMask = fxsaveState.mxcsrMask;

    if (sMxcsrMask == 0)
    {
        sMxcsrMask = MXCSR_MASK_DEFAULT;
    }



    return NgosStatus::OK;
}
