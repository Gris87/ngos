#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBCJDECODER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBCJDECODER_H



#include <buildconfig.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbuffer.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct XzBcjDecoder
{
    // x86 filter state
    u32 x86PreviousMask;
};



NgosStatus runXzBcjDecoder(XzBcjDecoder *decoder, XzBuffer *buffer); // TEST: NO



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBCJDECODER_H
