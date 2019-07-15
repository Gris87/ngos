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
    static NgosStatus init(); 

    static NgosStatus toString(char *buffer, u16 size); 
    static NgosStatus flagsToString(char *buffer, u16 size); 
    static NgosStatus bugsToString(char *buffer, u16 size); 
    static NgosStatus check(const char **wantedFlag); 

    static NgosStatus setFlag(X86Feature flag); 
    static NgosStatus clearFlag(X86Feature flag); 
    static bool hasFlag(X86Feature flag); 

    static NgosStatus setBug(X86Bug bug); 
    static NgosStatus clearBug(X86Bug bug); 
    static bool hasBug(X86Bug bug); 

    static bool isCpuIdLevelSupported(u32 cpuidLevel); 

    static bool hasEFlag(u64 mask); 
    static NgosStatus cpuid(u32 id, u32 count, u32 *a, u32 *b, u32 *c, u32 *d); 

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initCpuFeatures(); 
    static NgosStatus doPreprocessing(); 
    static NgosStatus doIntelPreprocessing(); 
    static NgosStatus doAmdPreprocessing(); 
    static NgosStatus initScatteredFeatures(); 
    static NgosStatus setScatteredFeature(X86Feature feature, u8 registerId, u8 bit, u32 level, u32 count); 
    static NgosStatus initSpeculationControl(); 
    static NgosStatus doPostprocessing(); 
    static NgosStatus doIntelPostprocessing(); 
    static NgosStatus doAmdPostprocessing(); 
    static NgosStatus filterFeaturesDependentOnCpuid(); 
    static NgosStatus initCpuBugs(); 
    static NgosStatus getIntelMicrocodeRevision(); 
    static bool isIntelBadSpectreMicrocode(); 
    static bool isCpuNoSpeculation(); 
    static bool isCpuNoMeltdown(); 
    static bool isCpuNoSpecStoreBypass(); 
    static bool isCpuNoL1TF(); 

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
