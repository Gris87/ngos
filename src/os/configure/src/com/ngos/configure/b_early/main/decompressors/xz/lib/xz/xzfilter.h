#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTER_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct XzFilter
{
    u64  id;
    u64  sizeOfProperties;
    u8  *properties;
};



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTER_H
