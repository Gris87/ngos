#ifndef OS_COMMON_SRC_BITS64_FPU_XFEATURES_EXTENDEDREGISTERS_H
#define OS_COMMON_SRC_BITS64_FPU_XFEATURES_EXTENDEDREGISTERS_H



#include <ngos/types.h>



struct Register128Bit
{
    u8 bytes[128 >> 3]; // ">> 3" == "/ 8"
};



struct Register256Bit
{
    u8 bytes[256 >> 3]; // ">> 3" == "/ 8"
};



struct Register512Bit
{
    u8 bytes[512 >> 3]; // ">> 3" == "/ 8"
};



#endif // OS_COMMON_SRC_BITS64_FPU_XFEATURES_EXTENDEDREGISTERS_H