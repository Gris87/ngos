#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XFEATURE_EXTENDEDREGISTERS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XFEATURE_EXTENDEDREGISTERS_H



#include <com/ngos/shared/common/ngos/types.h>



struct Register128Bit
{
    u8 bytes[128 / 8];
};



struct Register256Bit
{
    u8 bytes[256 / 8];
};



struct Register512Bit
{
    u8 bytes[512 / 8];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XFEATURE_EXTENDEDREGISTERS_H
