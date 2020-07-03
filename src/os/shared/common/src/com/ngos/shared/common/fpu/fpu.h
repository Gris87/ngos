#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_FPU_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_FPU_H



#include <common/src/com/ngos/shared/common/fpu/fpustate.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>



class FPU
{
public:
    static NgosStatus initForBootStrapProcessor(); // TEST: NO
    static NgosStatus initForApplicationProcessor(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initMxcsrMask(); // TEST: NO
    static NgosStatus initFXState(); // TEST: NO
    static NgosStatus initXState(); // TEST: NO
    static NgosStatus initXFeaturesOffsetsAndSizes(); // TEST: NO
    static NgosStatus initStateSizes(); // TEST: NO
    static NgosStatus copyStateFromFPU(); // TEST: NO
    static NgosStatus copyStateToFPU(); // TEST: NO
    static bool isXFeatureSupervisor(XFeature xFeature); // TEST: NO
    static bool isXFeatureUser(XFeature xFeature); // TEST: NO
    static bool isXFeatureAligned(XFeature xFeature); // TEST: NO

    static NgosStatus setFeature(XFeature xFeature);
    static NgosStatus clearFeature(XFeature xFeature);
    static bool hasFeature(XFeature xFeature);

    static NgosStatus setFlag(XFeatureTypeFlag flag);
    static NgosStatus clearFlag(XFeatureTypeFlag flag);
    static bool hasFlag(XFeatureTypeFlag flag);

#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES // Ignore CppReleaseUsageVerifier
    static u32 expectedStateSize(); // TEST: NO
#endif

    static FpuState          sState;
    static u32               sStateKernelSize;
    static u32               sStateUserSize;
    static u32               sMxcsrMask;
    static XFeatureTypeFlags sXFeatures;
    static u32               sXFeaturesOffsets[(u64)XFeature::MAXIMUM];
    static u32               sXFeaturesCompactedOffsets[(u64)XFeature::MAXIMUM];
    static u32               sXFeaturesSizes[(u64)XFeature::MAXIMUM];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_FPU_H
