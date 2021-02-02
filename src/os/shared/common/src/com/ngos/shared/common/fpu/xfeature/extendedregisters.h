#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_EXTENDEDREGISTERS_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_EXTENDEDREGISTERS_H



#include <com/ngos/shared/common/ngos/types.h>



struct Register128Bit
{
    bad_uint8 bytes[128 / 8];
};



struct Register256Bit
{
    bad_uint8 bytes[256 / 8];
};



struct Register512Bit
{
    bad_uint8 bytes[512 / 8];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_EXTENDEDREGISTERS_H
