#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_FPU_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_FPU_H



#include <common/src/bits64/fpu/fpustate.h>
#include <ngos/status.h>



class FPU
{
public:
    static NgosStatus init(); 

private:
    static NgosStatus initMxcsrMask(); 
    static NgosStatus initFXState(); 
    static NgosStatus initXState(); 
    static NgosStatus initXFeaturesOffsetsAndSizes(); 
    static NgosStatus initStateSizes(); 
    static NgosStatus copyStateFromFPU(); 
    static NgosStatus copyStateToFPU(); 
    static const char* getFeatureName(u8 xFeature); 
    static bool isXFeatureSupervisor(u8 xFeature); 
    static bool isXFeatureUser(u8 xFeature); 
    static bool isXFeatureAligned(u8 xFeature); 

#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES // Ignore CppReleaseUsageVerifier
    static u32 expectedStateSize(); 
#endif

    static FpuState              sState;
    static u32                   sStateKernelSize;
    static u32                   sStateUserSize;
    static u32                   sMxcsrMask;
    static x_features_type_flags sXFeaturesMask;
    static u32                   sXFeaturesOffsets[XFEATURE_MAX];
    static u32                   sXFeaturesCompactedOffsets[XFEATURE_MAX];
    static u32                   sXFeaturesSizes[XFEATURE_MAX];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_FPU_H
