#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERLZMA2_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERLZMA2_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define XZ_FILTER_LZMA2 0x21



NgosStatus filterLZMA2(u8 *compressedAddress, u8 *decompressedAddress, u64 sizeOfProperties, u8 *filterProperties, u64 *compressedSize, u64 *uncompressedSize); // TEST: NO



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERLZMA2_H
