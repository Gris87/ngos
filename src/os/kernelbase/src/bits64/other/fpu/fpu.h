#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H



#include <ngos/status.h>
#include <src/bits64/other/fpu/fpustate.h>



class FPU
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initMxcsrMask(); // TEST: NO
    static NgosStatus initFXState(); // TEST: NO
    static NgosStatus initXState(); // TEST: NO
    static NgosStatus initStateSizes(); // TEST: NO
    static NgosStatus initXFeaturesOffsetsAndSizes(); // TEST: NO
    static const char* getFeatureName(u8 xFeature); // TEST: NO
    static u32 xFeatureSize(u8 xFeature); // TEST: NO
    static u32 xFeatureOffset(u8 xFeature); // TEST: NO
    static bool isXFeatureSupervisor(u8 xFeature); // TEST: NO
    static bool isXFeatureUser(u8 xFeature); // TEST: NO
    static bool isXFeatureAligned(u8 xFeature); // TEST: NO
    static u32 expectedStateSize(); // TEST: NO

    static FpuState   sState;
    static u32        sStateKernelSize;
    static u32        sStateUserSize;
    static u32        sMxcsrMask;
    static x_features sXFeaturesMask;
    static u32        sXFeaturesOffsets[XFEATURE_MAX];
    static u32        sXFeaturesSizes[XFEATURE_MAX];
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H
