#ifndef OS_COMMON_SRC_BITS64_CPU_CPU_H
#define OS_COMMON_SRC_BITS64_CPU_CPU_H



#include <ngos/status.h>
#include <ngos/types.h>
#include <src/bits64/cpu/models/amd.h>
#include <src/bits64/cpu/models/intel.h>
#include <src/bits64/cpu/cpufeatures.h>
#include <src/bits64/cpu/cpuvendor.h>



class CPU
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus toString(char *buffer, u16 size); // TEST: NO
    static NgosStatus flagsToString(char *buffer, u16 size); // TEST: NO
    static NgosStatus check(const char **wantedFlag); // TEST: NO

    static NgosStatus setFlag(X86Feature flag); // TEST: NO
    static NgosStatus clearFlag(X86Feature flag); // TEST: NO
    static bool hasFlag(X86Feature flag); // TEST: NO

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
    static NgosStatus getIntelMicrocodeRevision(); // TEST: NO
    static bool isIntelBadSpectreMicrocode(); // TEST: NO
    static bool hasEFlag(u64 mask); // TEST: NO
    static NgosStatus cpuid(u32 id, u32 count, u32 *a, u32 *b, u32 *c, u32 *d); // TEST: NO

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
};



#endif // OS_COMMON_SRC_BITS64_CPU_CPU_H
