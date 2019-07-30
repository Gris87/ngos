#ifndef X86FEATURESNAMES_H
#define X86FEATURESNAMES_H



#include <common/src/bits64/cpu/x86featureword.h>
#include <ngos/status.h>



extern const char8* x86FeaturesNames[(u64)x86FeatureWord::MAXIMUM << 5]; // x86FeaturesNames declared in x86featuresnames.cpp file // "<< 5" == "* 32"



NgosStatus initX86FeaturesNames(); // TEST: NO



#endif // X86FEATURESNAMES_H
