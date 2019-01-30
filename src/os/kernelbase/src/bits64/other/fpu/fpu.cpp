#include "fpu.h"

#include <asm/instructions.h>
#include <src/bits64/cpu/cpu.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/other/fpu/macros.h>



#define XSTATE_CPUID 0x0000000D



FpuState   FPU::sState;
u32        FPU::sMxcsrMask;
x_features FPU::sXFeaturesMask;



NgosStatus FPU::init()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(fninit(), NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(initMxcsrMask(), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initFXState(),   NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initXState(),    NgosStatus::ASSERTION);



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

    COMMON_LVVV(("sState.xsave.header.xFeatures   = 0x%08X",   sState.xsave.header.xFeatures));
    COMMON_LVVV(("sState.xsave.header.xComponents = 0x%08X",   sState.xsave.header.xComponents));
    COMMON_LVVV(("sMxcsrMask                      = 0x%08X",   sMxcsrMask));
    COMMON_LVVV(("sXFeaturesMask                  = 0x%016lX", sXFeaturesMask));



    return NgosStatus::OK;
}

NgosStatus FPU::initMxcsrMask()
{
    COMMON_LT((""));



    // Static because GCC does not get 16-byte stack alignment right
    static FXSaveState fxsaveState;

    COMMON_ASSERT_EXECUTION(fxsave((u8 *)&fxsaveState), NgosStatus::ASSERTION);



    sMxcsrMask = fxsaveState.mxcsrMask;

    if (!sMxcsrMask) // sMxcsrMask == 0
    {
        sMxcsrMask = MXCSR_MASK_DEFAULT;
    }



    return NgosStatus::OK;
}

NgosStatus FPU::initFXState()
{
    COMMON_LT((""));



    sState.fxsave.cwd   = CWD_DEFAULT;
    sState.fxsave.mxcsr = MXCSR_DEFAULT;



    return NgosStatus::OK;
}

NgosStatus FPU::initXState()
{
    COMMON_LT((""));



    if (CPU::hasFlag(X86Feature::XSAVES))
    {
        COMMON_LVV(("X86Feature::XSAVES supported"));

        sState.xsave.header.xComponents = XCOMPONENTS_COMPACTED_FORMAT;
    }



    if (!CPU::isCpuIdLevelSupported(XSTATE_CPUID))
    {
        COMMON_LW(("XSTATE_CPUID not supported"));

        return NgosStatus::NOT_SUPPORTED;
    }



    u32 ignored;
    u32 eax;
    u32 edx;

    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, 0, &eax, &ignored, &ignored, &edx), NgosStatus::ASSERTION);
    sXFeaturesMask = eax | ((u64)edx << 32);

    COMMON_TEST_ASSERT((sXFeaturesMask & XFEATURE_MASK_FPU_SSE) == XFEATURE_MASK_FPU_SSE, NgosStatus::ASSERTION);



    // Disabling X features if CPU doesn't support necessary flags
    {
        if (
            !CPU::hasFlag(X86Feature::AVX)
            &&
            (sXFeaturesMask & (x_features)XFeature::AVX)
           )
        {
            COMMON_LVV(("Disabling XFeature::AVX since X86Feature::AVX not supported"));

            sXFeaturesMask &= ~(x_features)XFeature::AVX;
        }



        if (
            !CPU::hasFlag(X86Feature::MPX)
            &&
            (sXFeaturesMask & ((x_features)XFeature::MPX_BNDREGS | (x_features)XFeature::MPX_BNDCSR))
           )
        {
            COMMON_LVV(("Disabling XFeature::MPX_BNDREGS and XFeature::MPX_BNDCSR since X86Feature::MPX not supported"));

            sXFeaturesMask &= ~((x_features)XFeature::MPX_BNDREGS | (x_features)XFeature::MPX_BNDCSR);
        }



        if (
            !CPU::hasFlag(X86Feature::AVX512F)
            &&
            (sXFeaturesMask & ((x_features)XFeature::AVX512_OPMASK | (x_features)XFeature::AVX512_ZMM_HI_256 | (x_features)XFeature::AVX512_HI_16_ZMM))
           )
        {
            COMMON_LVV(("Disabling XFeature::AVX512_OPMASK, XFeature::AVX512_ZMM_HI_256 and XFeature::AVX512_HI_16_ZMM since X86Feature::AVX512F not supported"));

            sXFeaturesMask &= ~((x_features)XFeature::AVX512_OPMASK | (x_features)XFeature::AVX512_ZMM_HI_256 | (x_features)XFeature::AVX512_HI_16_ZMM);
        }



        if (
            !CPU::hasFlag(X86Feature::INTEL_PT)
            &&
            (sXFeaturesMask & (x_features)XFeature::PT)
           )
        {
            COMMON_LVV(("Disabling XFeature::PT since X86Feature::INTEL_PT not supported"));

            sXFeaturesMask &= ~(x_features)XFeature::PT;
        }



        if (
            !CPU::hasFlag(X86Feature::PKU)
            &&
            (sXFeaturesMask & (x_features)XFeature::PKRU)
           )
        {
            COMMON_LVV(("Disabling XFeature::PKRU since X86Feature::PKU not supported"));

            sXFeaturesMask &= ~(x_features)XFeature::PKRU;
        }
    }



    if (sXFeaturesMask & XFEATURE_MASK_SUPERVISOR)
    {
        COMMON_LVV(("Disabling X features that required in supervisor"));

        sXFeaturesMask &= ~XFEATURE_MASK_SUPERVISOR;
    }



    COMMON_ASSERT_EXECUTION(xsetbv(XCR_XFEATURES, sXFeaturesMask), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
