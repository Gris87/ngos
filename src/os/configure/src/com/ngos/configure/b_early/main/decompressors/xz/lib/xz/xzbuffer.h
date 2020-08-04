#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBUFFER_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBUFFER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct XzBuffer
{
    u8 *in;
    u64 inPosition;
    u64 inSize;

    u8 *out;
    u64 outPosition;
    u64 outSize;
};



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBUFFER_H
