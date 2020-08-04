#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERBCJ_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERBCJ_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#if NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
#define XZ_FILTER_BCJ 0x04
#endif



NgosStatus filterBCJ(u8 *compressedAddress, u8 *decompressedAddress, u64 sizeOfProperties, u8 *filterProperties, u64 uncompressedSize); // TEST: NO



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERBCJ_H
