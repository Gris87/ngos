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

    COMMON_ASSERT_EXECUTION(initStateSizes(), NgosStatus::ASSERTION);



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
