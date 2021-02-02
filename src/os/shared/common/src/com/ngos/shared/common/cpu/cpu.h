#ifndef COM_NGOS_SHARED_COMMON_CPU_CPU_H
#define COM_NGOS_SHARED_COMMON_CPU_CPU_H



#include <com/ngos/shared/common/cpu/cpufamily.h>
#include <com/ngos/shared/common/cpu/cpuvendor.h>
#include <com/ngos/shared/common/cpu/x86bug.h>
#include <com/ngos/shared/common/cpu/x86feature.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



class CPU
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus toString(char8 *buffer, bad_uint16 size); // TEST: NO
    static NgosStatus flagsToString(char8 *buffer, bad_uint16 size); // TEST: NO
    static NgosStatus bugsToString(char8 *buffer, bad_uint16 size); // TEST: NO
    static NgosStatus check(const char8 **wantedFlag); // TEST: NO

    static bool isOutdated(); // TEST: NO

    static CpuVendor getVendor(); // TEST: NO
    static char8* getModelName(); // TEST: NO
    static CpuFamily getFamily(); // TEST: NO
    static bad_uint8 getModel(); // TEST: NO
    static bad_uint8 getStepping(); // TEST: NO
    static bad_uint32 getMicrocodeRevision(); // TEST: NO
    static bad_uint32 getNumberOfCores(); // TEST: NO
    static bad_uint32 getNumberOfThreads(); // TEST: NO

    static NgosStatus setFlag(X86Feature flag);
    static NgosStatus clearFlag(X86Feature flag);
    static bool hasFlag(X86Feature flag);

    static NgosStatus setBug(X86Bug bug);
    static NgosStatus clearBug(X86Bug bug);
    static bool hasBug(X86Bug bug);

    static bool isCpuIdLevelSupported(bad_uint32 cpuidLevel);

    static bool hasEFlag(bad_uint64 mask); // TEST: NO
    static NgosStatus cpuid(bad_uint32 id, bad_uint32 count, bad_uint32 *a, bad_uint32 *b, bad_uint32 *c, bad_uint32 *d); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initCpuFeatures(); // TEST: NO
    static NgosStatus doPreprocessing(); // TEST: NO
    static NgosStatus doIntelPreprocessing(); // TEST: NO
    static NgosStatus doAmdPreprocessing(); // TEST: NO
    static NgosStatus doCommonPreprocessing(); // TEST: NO
    static NgosStatus initScatteredFeatures(); // TEST: NO
    static NgosStatus setScatteredFeature(X86Feature feature, bad_uint8 registerId, bad_uint8 bit, bad_uint32 level, bad_uint32 count); // TEST: NO
    static NgosStatus initSpeculationControl(); // TEST: NO
    static NgosStatus doPostprocessing(); // TEST: NO
    static NgosStatus doIntelPostprocessing(); // TEST: NO
    static NgosStatus doAmdPostprocessing(); // TEST: NO
    static NgosStatus doCommonPostprocessing(); // TEST: NO
    static NgosStatus filterFeaturesDependentOnCpuid(); // TEST: NO
    static NgosStatus initCpuBugs(); // TEST: NO
    static NgosStatus initIntelMicrocodeRevision(); // TEST: NO
    static bool isIntelBadSpectreMicrocode(); // TEST: NO
    static bool isCpuNoSpeculation(); // TEST: NO
    static bool isCpuNoMeltdown(); // TEST: NO
    static bool isCpuNoSpecStoreBypass(); // TEST: NO
    static bool isCpuNoL1TF(); // TEST: NO

    static bad_uint32       sVendor[3];
    static CpuVendor sCpuVendor;
    static bad_uint32       sModelName[12];
    static bad_uint32       sCpuidLevel;
    static bad_uint32       sExtendedCpuidLevel;
    static CpuFamily sFamily;
    static bad_uint8        sModel;
    static bad_uint8        sStepping;
    static bad_uint32       sMicrocodeRevision;
    static bad_uint32       sNumberOfCores;
    static bad_uint32       sNumberOfThreads;
    static bad_uint8        sNumberOfApicIdsPerPackage;
    static bad_int8        sX86CoreIdBits;
    static bad_uint16       sCacheLineFlushSize;
    static bad_uint16       sCacheAlignment;
    static bad_int32       sCacheMaxRmid;
    static bad_int32       sCacheOccScale;
    static bad_uint32       sPower;
    static bad_uint8        sPhysicalBits;
    static bad_uint8        sVirtualBits;
    static bad_uint32       sFlags[(bad_uint64)x86FeatureWord::MAXIMUM];
    static bad_uint32       sBugs[(bad_uint64)x86BugWord::MAXIMUM];
};



#endif // COM_NGOS_SHARED_COMMON_CPU_CPU_H
