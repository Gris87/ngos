#ifndef COM_NGOS_SHARED_COMMON_CPU_CPU_H
#define COM_NGOS_SHARED_COMMON_CPU_CPU_H



#include <com/ngos/shared/common/cpu/lib/cpufamily.h>
#include <com/ngos/shared/common/cpu/lib/cpuvendor.h>
#include <com/ngos/shared/common/cpu/lib/x86bug.h>
#include <com/ngos/shared/common/cpu/lib/x86feature.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuidmodelname.h>
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuidvendor.h>
#include <com/ngos/shared/common/cpu/lib/registers/x86flags.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



class CPU
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus toString(good_Char8 *buffer, u16 size); // TEST: NO
    static NgosStatus featuresToString(good_Char8 *buffer, u16 size); // TEST: NO
    static NgosStatus bugsToString(good_Char8 *buffer, u16 size); // TEST: NO
    static NgosStatus check(const good_Char8 **wantedFeature); // TEST: NO

    static bool isOutdated(); // TEST: NO

    static CpuVendor getVendor(); // TEST: NO
    static good_Char8* getModelName(); // TEST: NO
    static CpuFamily getFamily(); // TEST: NO
    static u8 getModel(); // TEST: NO
    static u8 getStepping(); // TEST: NO
    static u32 getMicrocodeRevision(); // TEST: NO
    static u32 getNumberOfCores(); // TEST: NO
    static u32 getNumberOfThreads(); // TEST: NO

    static NgosStatus setFeature(X86Feature feature);
    static NgosStatus clearFeature(X86Feature feature);
    static bool hasFeature(X86Feature feature);

    static NgosStatus setBug(X86Bug bug);
    static NgosStatus clearBug(X86Bug bug);
    static bool hasBug(X86Bug bug);

    static bool isCpuIdLevelSupported(u32 cpuidLevel);

    static bool hasX86Flags(X86Flags flags); // TEST: NO
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
    static NgosStatus doCommonPreprocessing(); // TEST: NO
    static NgosStatus initScatteredFeatures(); // TEST: NO
    static NgosStatus setScatteredFeature(X86Feature feature, u8 registerId, u8 bit, u32 level, u32 count); // TEST: NO
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

    static CpuidVendor    sVendor;
    static CpuVendor      sCpuVendor;
    static CpuidModelName sModelName;
    static u32            sCpuidLevel;
    static u32            sExtendedCpuidLevel;
    static CpuFamily      sFamily;
    static u8             sModel;
    static u8             sStepping;
    static u32            sMicrocodeRevision;
    static u32            sNumberOfCores;
    static u32            sNumberOfThreads;
    static u8             sNumberOfApicIdsPerPackage;
    static i8             sX86CoreIdBits;
    static u16            sCacheLineFlushSize;
    static u16            sCacheAlignment;
    static i32            sCacheMaxRmid;
    static i32            sCacheOccScale;
    static u32            sPower;
    static u8             sPhysicalBits;
    static u8             sVirtualBits;
    static good_U32       sFeatures[(enum_t)x86FeatureWord::MAXIMUM];
    static good_U32       sBugs[(enum_t)x86BugWord::MAXIMUM];
};



#endif // COM_NGOS_SHARED_COMMON_CPU_CPU_H
