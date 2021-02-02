#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERLZMA2_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERLZMA2_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define XZ_FILTER_LZMA2 0x21



NgosStatus filterLZMA2(bad_uint8 *compressedAddress, bad_uint8 *decompressedAddress, bad_uint64 sizeOfProperties, bad_uint8 *filterProperties, bad_uint64 *compressedSize, bad_uint64 *uncompressedSize); // TEST: NO



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZFILTERLZMA2_H
