#ifndef COM_NGOS_SHARED_COMMON_CPU_CPU_H                                                                                                                                                                 // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_CPU_H                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpufamily.h>                                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuidleaf.h>                                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuidsubleaf.h>                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuvendor.h>                                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/cpu/lib/x86bug.h>                                                                                                                                                       // Colorize: green
#include <com/ngos/shared/common/cpu/lib/x86feature.h>                                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuidmodelname.h>                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/cpuidvendor.h>                                                                                                                                            // Colorize: green
#include <com/ngos/shared/common/cpu/lib/registers/x86flags.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/ngos/status.h>                                                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class CPU                                                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    static NgosStatus init(); // TEST: NO                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static NgosStatus toString(good_Char8 *buffer, good_I64 size); // TEST: NO                                                                                                                           // Colorize: green
    static NgosStatus featuresToString(good_Char8 *buffer, good_I64 size); // TEST: NO                                                                                                                   // Colorize: green
    static NgosStatus bugsToString(good_Char8 *buffer, good_I64 size); // TEST: NO                                                                                                                       // Colorize: green
    static NgosStatus check(const good_Char8 **wantedFeature); // TEST: NO                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static bool isOutdated(); // TEST: NO                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static CpuVendor getCpuVendor(); // TEST: NO                                                                                                                                                         // Colorize: green
    static good_Char8* getModelName(); // TEST: NO                                                                                                                                                       // Colorize: green
    static CpuFamily getFamily(); // TEST: NO                                                                                                                                                            // Colorize: green
    static good_U8 getModel(); // TEST: NO                                                                                                                                                               // Colorize: green
    static good_U8 getStepping(); // TEST: NO                                                                                                                                                            // Colorize: green
    static good_U32 getMicrocodeRevision(); // TEST: NO                                                                                                                                                  // Colorize: green
    static good_U32 getNumberOfCores(); // TEST: NO                                                                                                                                                      // Colorize: green
    static good_U32 getNumberOfThreads(); // TEST: NO                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static NgosStatus setFeature(X86Feature feature);                                                                                                                                                    // Colorize: green
    static NgosStatus clearFeature(X86Feature feature);                                                                                                                                                  // Colorize: green
    static bool hasFeature(X86Feature feature);                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static NgosStatus setBug(X86Bug bug);                                                                                                                                                                // Colorize: green
    static NgosStatus clearBug(X86Bug bug);                                                                                                                                                              // Colorize: green
    static bool hasBug(X86Bug bug);                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static bool isCpuIdLevelSupported(CpuidLeaf cpuidLevel);                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static bool hasX86Flags(X86Flags flags); // TEST: NO                                                                                                                                                 // Colorize: green
    static NgosStatus cpuid(CpuidLeaf leaf, CpuidSubLeaf subLeaf, good_U32 *a, good_U32 *b, good_U32 *c, good_U32 *d); // TEST: NO                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
#else                                                                                                                                                                                                    // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
    static NgosStatus initCpuFeatures(); // TEST: NO
    static NgosStatus doPreprocessing(); // TEST: NO
    static NgosStatus doIntelPreprocessing(); // TEST: NO
    static NgosStatus doAmdPreprocessing(); // TEST: NO
    static NgosStatus doCommonPreprocessing(); // TEST: NO
    static NgosStatus initScatteredFeatures(); // TEST: NO
    static NgosStatus setScatteredFeature(X86Feature feature, u8 registerId, u8 bit, CpuidLeaf leaf, CpuidSubLeaf subLeaf); // TEST: NO
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

    static CpuidVendor    sVendor;                                                                                                                                                                       // Colorize: green
    static CpuidModelName sModelName;                                                                                                                                                                    // Colorize: green
    static CpuidLeaf      sCpuidLevel;                                                                                                                                                                   // Colorize: green
    static CpuidLeaf      sExtendedCpuidLevel;                                                                                                                                                           // Colorize: green
    static CpuVendor      sCpuVendor;                                                                                                                                                                    // Colorize: green
    static CpuFamily      sFamily;                                                                                                                                                                       // Colorize: green
    static good_U8        sModel;                                                                                                                                                                        // Colorize: green
    static good_U8        sStepping;                                                                                                                                                                     // Colorize: green
    static good_U32       sMicrocodeRevision;                                                                                                                                                            // Colorize: green
    static good_U32       sNumberOfCores;                                                                                                                                                                // Colorize: green
    static good_U32       sNumberOfThreads;                                                                                                                                                              // Colorize: green
    static u8             sNumberOfApicIdsPerPackage;
    static i8             sX86CoreIdBits;
    static u16            sCacheLineFlushSize;
    static u16            sCacheAlignment;
    static i32            sCacheMaxRmid;
    static i32            sCacheOccScale;
    static u32            sPower;
    static u8             sPhysicalBits;
    static u8             sVirtualBits;
    static good_U32       sFeatures[(enum_t)x86FeatureWord::MAXIMUM];                                                                                                                                    // Colorize: green
    static good_U32       sBugs[(enum_t)x86BugWord::MAXIMUM];                                                                                                                                            // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_CPU_H                                                                                                                                                               // Colorize: green
