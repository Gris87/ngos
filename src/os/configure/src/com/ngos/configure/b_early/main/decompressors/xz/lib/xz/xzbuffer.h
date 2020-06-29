#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBUFFER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBUFFER_H



#include <buildconfig.h>
#include <ngos/types.h>



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



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBUFFER_H
