#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_CPU_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_CPU_H



#include <common/src/bits64/cpu/cpubugs.h>
#include <common/src/bits64/cpu/cpufeatures.h>
#include <common/src/bits64/cpu/cpuvendor.h>
#include <ngos/status.h>
#include <ngos/types.h>



class CPU
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus toString(char *buffer, u16 size); // TEST: NO
    static NgosStatus flagsToString(char *buffer, u16 size); // TEST: NO
    static NgosStatus bugsToString(char *buffer, u16 size); // TEST: NO
    static NgosStatus check(const char **wantedFlag); // TEST: NO

    static NgosStatus setFlag(X86Feature flag); // TEST: NO
    static NgosStatus clearFlag(X86Feature flag); // TEST: NO
    static bool hasFlag(X86Feature flag); // TEST: NO

    static NgosStatus setBug(X86Bug bug); // TEST: NO
    static NgosStatus clearBug(X86Bug bug); // TEST: NO
    static bool hasBug(X86Bug bug); // TEST: NO

    static bool isCpuIdLevelSupported(u32 cpuidLevel); // TEST: NO

    static bool hasEFlag(u64 mask); // TEST: NO
    static NgosStatus cpuid(u32 id, u32 count, u32 *a, u32 *b, u32 *c, u32 *d); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initCpuFeatures(); // TEST: NO
    static NgosStatus doPreprocessing(); // TEST: NO
    static NgosStatus doIntelPreprocessing(); // TEST: NO
    static NgosStatus doAmdPreprocessing(); // TEST: NO
    static NgosStatus initScatteredFeatures(); // TEST: NO
    static NgosStatus setScatteredFeature(X86Feature feature, u8 registerId, u8 bit, u32 level, u32 count); // TEST: NO
    static NgosStatus initSpeculationControl(); // TEST: NO
    static NgosStatus doPostprocessing(); // TEST: NO
    static NgosStatus doIntelPostprocessing(); // TEST: NO
    static NgosStatus doAmdPostprocessing(); // TEST: NO
    static NgosStatus filterFeaturesDependentOnCpuid(); // TEST: NO
    static NgosStatus initCpuBugs(); // TEST: NO
    static NgosStatus getIntelMicrocodeRevision(); // TEST: NO
    static bool isIntelBadSpectreMicrocode(); // TEST: NO
    static bool isCpuNoSpeculation(); // TEST: NO
    static bool isCpuNoMeltdown(); // TEST: NO
    static bool isCpuNoSpecStoreBypass(); // TEST: NO
    static bool isCpuNoL1TF(); // TEST: NO

    static u32       sVendor[3];
    static CpuVendor sCpuVendor;
    static u32       sModelName[12];
    static u32       sCpuidLevel;
    static u32       sExtendedCpuidLevel;
    static u16       sFamily;
    static u8        sModel;
    static u8        sStepping;
    static u32       sMicrocodeRevision;
    static i8        sX86CoreIdBits;
    static u16       sCacheLineFlushSize;
    static u16       sCacheAlignment;
    static i32       sCacheMaxRmid;
    static i32       sCacheOccScale;
    static u32       sPower;
    static u8        sPhysicalBits;
    static u8        sVirtualBits;
    static u32       sFlags[AMOUNT_OF_WORDS_FOR_X86_FEATURES];
    static u32       sBugs[AMOUNT_OF_WORDS_FOR_X86_BUGS];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_CPU_H