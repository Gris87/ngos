#include "fpu.h"

#include <asm/instructions.h>
#include <src/bits64/cpu/cpu.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/other/fpu/macros.h>
#include <src/bits64/other/fpu/xfeatures/xfeatureavx512opmaskstate.h>
#include <src/bits64/other/fpu/xfeatures/xfeatureavx512zmmfrom0to15state.h>
#include <src/bits64/other/fpu/xfeatures/xfeatureavx512zmmfrom16to31state.h>
#include <src/bits64/other/fpu/xfeatures/xfeatureavxstate.h>
#include <src/bits64/other/fpu/xfeatures/xfeaturempxboundconfigandstatusregistersstate.h>
#include <src/bits64/other/fpu/xfeatures/xfeaturempxboundregistersstate.h>
#include <src/bits64/other/fpu/xfeatures/xfeaturepkrustate.h>



#define XSTATE_CPUID 0x0000000D



FpuState   FPU::sState;
u32        FPU::sStateKernelSize;
u32        FPU::sStateUserSize;
u32        FPU::sMxcsrMask;
x_features FPU::sXFeaturesMask;
u32        FPU::sXFeaturesOffsets[XFEATURE_MAX];
u32        FPU::sXFeaturesSizes[XFEATURE_MAX];



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
        COMMON_LVVV(("sState.fxsave.xmm[%d][0] = 0x%016lX", i, sState.fxsave.xmm[i][0]));
        COMMON_LVVV(("sState.fxsave.xmm[%d][1] = 0x%016lX", i, sState.fxsave.xmm[i][1]));
    }

    COMMON_LVVV(("sState.xsave.header.xFeatures   = 0x%08X",   sState.xsave.header.xFeatures));
    COMMON_LVVV(("sState.xsave.header.xComponents = 0x%08X",   sState.xsave.header.xComponents));
    COMMON_LVVV(("sStateKernelSize                = %u",       sStateKernelSize));
    COMMON_LVVV(("sStateUserSize                  = %u",       sStateUserSize));
    COMMON_LVVV(("sMxcsrMask                      = 0x%08X",   sMxcsrMask));
    COMMON_LVVV(("sXFeaturesMask                  = 0x%016lX", sXFeaturesMask));

    for (i64 i = 0; i < XFEATURE_MAX; ++i)
    {
        COMMON_LVVV(("sXFeaturesOffsets[%d] = 0x%08X", i, sXFeaturesOffsets[i]));
        COMMON_LVVV(("sXFeaturesSizes[%d]   = 0x%08X", i, sXFeaturesSizes[i]));
    }



    COMMON_TEST_ASSERT(sState.fxsave.cwd               == 0x037F,             NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.swd               == 0x0000,             NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.twd               == 0x0000,             NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.fop               == 0x0000,             NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.fip               == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.fcs               == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.foo               == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.fos               == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.mxcsr             == 0x00001F80,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.mxcsrMask         == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[0]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[1]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[2]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[3]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[4]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[5]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[6]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[7]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[8]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[9]          == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[10]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[11]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[12]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[13]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[14]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.stack[15]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[0][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[0][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[1][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[1][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[2][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[2][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[3][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[3][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[4][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[4][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[5][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[5][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[6][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[6][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[7][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[7][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[8][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[8][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[9][0]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[9][1]         == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[10][0]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[10][1]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[11][0]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[11][1]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[12][0]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[12][1]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[13][0]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[13][1]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[14][0]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[14][1]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[15][0]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.fxsave.xmm[15][1]        == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.xsave.header.xFeatures   == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sState.xsave.header.xComponents == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sStateKernelSize                == 2696,               NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sStateUserSize                  == 2696,               NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sMxcsrMask                      == 0x0000FFFF,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesMask                  == 0x000000000000021B, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[0]            == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[0]              == 0x00000100,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[1]            == 0x00000100,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[1]              == 0x00000100,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[2]            == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[2]              == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[3]            == 0x000003C0,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[3]              == 0x00000040,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[4]            == 0x00000400,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[4]              == 0x00000040,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[5]            == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[5]              == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[6]            == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[6]              == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[7]            == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[7]              == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[8]            == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[8]              == 0x00000000,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesOffsets[9]            == 0x00000A80,         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sXFeaturesSizes[9]              == 0x00000008,         NgosStatus::ASSERTION);



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
            (sXFeaturesMask & ((x_features)XFeature::MPX_BOUND_REGISTERS | (x_features)XFeature::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS))
           )
        {
            COMMON_LVV(("Disabling XFeature::MPX_BOUND_REGISTERS and XFeature::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS since X86Feature::MPX not supported"));

            sXFeaturesMask &= ~((x_features)XFeature::MPX_BOUND_REGISTERS | (x_features)XFeature::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS);
        }



        if (
            !CPU::hasFlag(X86Feature::AVX512F)
            &&
            (sXFeaturesMask & ((x_features)XFeature::AVX512_OPMASK | (x_features)XFeature::AVX512_ZMM_FROM_0_TO_15 | (x_features)XFeature::AVX512_ZMM_FROM_16_TO_31))
           )
        {
            COMMON_LVV(("Disabling XFeature::AVX512_OPMASK, XFeature::AVX512_ZMM_FROM_0_TO_15 and XFeature::AVX512_ZMM_FROM_16_TO_31 since X86Feature::AVX512F not supported"));

            sXFeaturesMask &= ~((x_features)XFeature::AVX512_OPMASK | (x_features)XFeature::AVX512_ZMM_FROM_0_TO_15 | (x_features)XFeature::AVX512_ZMM_FROM_16_TO_31);
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

    COMMON_ASSERT_EXECUTION(initStateSizes(),               NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initXFeaturesOffsetsAndSizes(), NgosStatus::ASSERTION);



    if (CPU::hasFlag(X86Feature::XSAVES))
    {
        COMMON_LVV(("X86Feature::XSAVES supported"));

        sState.xsave.header.xComponents = XCOMPONENTS_COMPACTED_FORMAT | sXFeaturesMask;
    }



    return NgosStatus::OK;
}

NgosStatus FPU::initStateSizes()
{
    COMMON_LT((""));



    u32 ignored;

    // CPUID 0x0000000D, sub-function 0:
    // EBX enumerates the size (in bytes) required by he XSAVE instruction for an XSAVE area
    // containing all the *user* state components corresponding to bits currently set in XCR0
    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, 0, &ignored, &sStateUserSize, &ignored, &ignored), NgosStatus::ASSERTION);

    if (CPU::hasFlag(X86Feature::XSAVES))
    {
        COMMON_LVV(("X86Feature::XSAVES supported"));

        // CPUID 0x0000000D, sub-function 1:
        // EBX enumerates the size (in bytes) required by the XSAVES instruction for an XSAVE area
        // containing all the state components corresponding to bits currently set in XCR0 | IA32_XSS
        COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, 1, &ignored, &sStateKernelSize, &ignored, &ignored), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_LVV(("X86Feature::XSAVES not supported"));

        sStateKernelSize = sStateUserSize;
    }



    COMMON_TEST_ASSERT(sStateKernelSize <= sizeof(sState), NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sStateUserSize   <= sizeof(sState), NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sStateKernelSize >= sStateUserSize, NgosStatus::ASSERTION);

    COMMON_TEST_ASSERT(expectedStateSize() == sStateKernelSize, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus FPU::initXFeaturesOffsetsAndSizes()
{
    COMMON_LT((""));



#if NGOS_BUILD_TEST_MODE == OPTION_YES
    u32 lastGoodOffset = sizeof(FXSaveState) + sizeof(XStateHeader);
#endif

    sXFeaturesOffsets[XFEATURE_FPU] = 0;
    sXFeaturesSizes[XFEATURE_FPU]   = sizeof(FXSaveState) - sizeof(FXSaveState::xmm);

    sXFeaturesOffsets[XFEATURE_SSE] = sXFeaturesSizes[XFEATURE_FPU];
    sXFeaturesSizes[XFEATURE_SSE]   = sizeof(FXSaveState::xmm);



    for (i64 i = XFEATURE_SSE + 1; i < XFEATURE_MAX; ++i)
    {
        if (sXFeaturesMask & (1ULL << i))
        {
            u32 ignored;

            COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, i, &sXFeaturesSizes[i], &sXFeaturesOffsets[i], &ignored, &ignored), NgosStatus::ASSERTION);



            if (!isXFeatureUser(i))
            {
                COMMON_LF(("Can't get offset of X feature %s", getFeatureName(i)));

                sXFeaturesOffsets[i] = 0;
            }



#if NGOS_BUILD_TEST_MODE == OPTION_YES
            COMMON_TEST_ASSERT(sXFeaturesOffsets[i] > lastGoodOffset, NgosStatus::ASSERTION);

            lastGoodOffset = sXFeaturesOffsets[i];
#endif
        }
    }



    return NgosStatus::OK;
}

const char* FPU::getFeatureName(u8 xFeature)
{
    COMMON_LT((" | xFeature = %u", xFeature));

    COMMON_ASSERT(xFeature < XFEATURE_MAX, "xFeature is invalid", 0);



    switch (xFeature)
    {
        case XFEATURE_FPU:                                   return "XFEATURE_FPU";
        case XFEATURE_SSE:                                   return "XFEATURE_SSE";
        case XFEATURE_AVX:                                   return "XFEATURE_AVX";
        case XFEATURE_MPX_BOUND_REGISTERS:                   return "XFEATURE_MPX_BOUND_REGISTERS";
        case XFEATURE_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS: return "XFEATURE_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS";
        case XFEATURE_AVX512_OPMASK:                         return "XFEATURE_AVX512_OPMASK";
        case XFEATURE_AVX512_ZMM_FROM_0_TO_15:               return "XFEATURE_AVX512_ZMM_FROM_0_TO_15";
        case XFEATURE_AVX512_ZMM_FROM_16_TO_31:              return "XFEATURE_AVX512_ZMM_FROM_16_TO_31";
        case XFEATURE_PT:                                    return "XFEATURE_PT";
        case XFEATURE_PKRU:                                  return "XFEATURE_PKRU";

        default: return "UNKNOWN";
    }
}

u32 FPU::xFeatureSize(u8 xFeature)
{
    COMMON_LT((" | xFeature = %u", xFeature));

    COMMON_ASSERT(xFeature < XFEATURE_MAX, "xFeature is invalid", 0);



    u32 eax;
    u32 ignored;

    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, xFeature, &eax, &ignored, &ignored, &ignored), 0);

    return eax;
}

u32 FPU::xFeatureOffset(u8 xFeature)
{
    COMMON_LT((" | xFeature = %u", xFeature));

    COMMON_ASSERT(xFeature < XFEATURE_MAX,                          "xFeature is invalid",    0);
    COMMON_ASSERT(!((1ULL << xFeature) & XFEATURE_MASK_SUPERVISOR), "xFeature is supervisor", 0);



    u32 ebx;
    u32 ignored;

    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, xFeature, &ignored, &ebx, &ignored, &ignored), 0);

    return ebx;
}

bool FPU::isXFeatureSupervisor(u8 xFeature)
{
    COMMON_LT((" | xFeature = %u", xFeature));

    COMMON_ASSERT(xFeature < XFEATURE_MAX, "xFeature is invalid", 0);



    u32 ecx;
    u32 ignored;

    // if xFeature is supervisor state then ECX[0] = 1, otherwise ECX[0] = 0
    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, xFeature, &ignored, &ignored, &ecx, &ignored), 0);



    bool res = !!(ecx & 0x01);

    COMMON_TEST_ASSERT(!!((1ULL << xFeature) & XFEATURE_MASK_SUPERVISOR) == res, false);

    return res;
}

bool FPU::isXFeatureUser(u8 xFeature)
{
    COMMON_LT((" | xFeature = %u", xFeature));

    COMMON_ASSERT(xFeature < XFEATURE_MAX, "xFeature is invalid", 0);



    u32 ecx;
    u32 ignored;

    // if xFeature is supervisor state then ECX[0] = 1, otherwise ECX[0] = 0
    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, xFeature, &ignored, &ignored, &ecx, &ignored), 0);



    bool res = !(ecx & 0x01);

    COMMON_TEST_ASSERT(!!((1ULL << xFeature) & XFEATURE_MASK_SUPERVISOR) != res, false);

    return res;
}

bool FPU::isXFeatureAligned(u8 xFeature)
{
    COMMON_LT((" | xFeature = %u", xFeature));

    COMMON_ASSERT(xFeature < XFEATURE_MAX, "xFeature is invalid", 0);



    u32 ecx;
    u32 ignored;

    // The value returned by ECX[1] indicates the alignment of xFeature
    // when the compacted format of the extended region of an XSAVE area is used
    COMMON_ASSERT_EXECUTION(CPU::cpuid(XSTATE_CPUID, xFeature, &ignored, &ignored, &ecx, &ignored), 0);



    return ecx & 0x02;
}

u32 FPU::expectedStateSize()
{
    COMMON_LT((""));



    u32 res = sizeof(FXSaveState) + sizeof(XStateHeader);

    for (i64 i = XFEATURE_SSE + 1; i < XFEATURE_MAX; ++i)
    {
        if (sXFeaturesMask & (1ULL << i))
        {
            u32 featureSize = xFeatureSize(i);
            u32 featureStructSize;



            switch (i)
            {
                case XFEATURE_AVX:                                   featureStructSize = sizeof(XFeatureAvxState);                              break;
                case XFEATURE_MPX_BOUND_REGISTERS:                   featureStructSize = sizeof(XFeatureMpxBoundRegistersState);                break;
                case XFEATURE_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS: featureStructSize = sizeof(XFeatureMpxBoundConfigAndStatusRegistersState); break;
                case XFEATURE_AVX512_OPMASK:                         featureStructSize = sizeof(XFeatureAvx512OpmaskState);                     break;
                case XFEATURE_AVX512_ZMM_FROM_0_TO_15:               featureStructSize = sizeof(XFeatureAvx512ZmmFrom0To15State);               break;
                case XFEATURE_AVX512_ZMM_FROM_16_TO_31:              featureStructSize = sizeof(XFeatureAvx512ZmmFrom16To31State);              break;
                case XFEATURE_PKRU:                                  featureStructSize = sizeof(XFeaturePkruState);                             break;

                case XFEATURE_FPU:
                case XFEATURE_SSE:
                case XFEATURE_PT:
                {
                    COMMON_LF(("Unsupported X feature: %s", getFeatureName(i)));

                    return 0;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown X feature: %s", getFeatureName(i)));

                    return 0;
                }
                break;
            }



            COMMON_LVVV(("X feature %s: featureSize = %u, featureStructSize = %u", getFeatureName(i), featureSize, featureStructSize));

            COMMON_TEST_ASSERT(featureSize == featureStructSize, 0);



            if (
                !CPU::hasFlag(X86Feature::XSAVES)
                &&
                isXFeatureSupervisor(i)
               )
            {
                COMMON_LF(("X feature %s is supervisor, but X86Feature::XSAVES not supported", getFeatureName(i)));
            }



            if (isXFeatureAligned(i))
            {
                COMMON_LVV(("X feature %s should be aligned to 64 bytes", getFeatureName(i)));

                res = ROUND_UP(res, 64);
            }



            if (!CPU::hasFlag(X86Feature::XSAVES))
            {
                res = xFeatureOffset(i);
            }



            res += featureSize;
        }
    }



    return res;
}
