#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_DECOMPRESS_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_DECOMPRESS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize); // TEST: NO



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_DECOMPRESS_H
