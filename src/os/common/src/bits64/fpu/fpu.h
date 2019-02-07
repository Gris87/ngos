#ifndef OS_COMMON_SRC_BITS64_FPU_FPU_H
#define OS_COMMON_SRC_BITS64_FPU_FPU_H



#include <ngos/status.h>
#include <src/bits64/fpu/fpustate.h>



class FPU
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initMxcsrMask(); // TEST: NO
    static NgosStatus initFXState(); // TEST: NO
    static NgosStatus initXState(); // TEST: NO
    static NgosStatus initXFeaturesOffsetsAndSizes(); // TEST: NO
    static NgosStatus initStateSizes(); // TEST: NO
    static NgosStatus copyStateFromFPU(); // TEST: NO
    static NgosStatus copyStateToFPU(); // TEST: NO
    static const char* getFeatureName(u8 xFeature); // TEST: NO
    static bool isXFeatureSupervisor(u8 xFeature); // TEST: NO
    static bool isXFeatureUser(u8 xFeature); // TEST: NO
    static bool isXFeatureAligned(u8 xFeature); // TEST: NO

#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES // Ignore CppReleaseUsageVerifier
    static u32 expectedStateSize(); // TEST: NO
#endif

    static FpuState   sState;
    static u32        sStateKernelSize;
    static u32        sStateUserSize;
    static u32        sMxcsrMask;
    static x_features sXFeaturesMask;
    static u32        sXFeaturesOffsets[XFEATURE_MAX];
    static u32        sXFeaturesCompactedOffsets[XFEATURE_MAX];
    static u32        sXFeaturesSizes[XFEATURE_MAX];
};



#endif // OS_COMMON_SRC_BITS64_FPU_FPU_H
