#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_OPERATINGSYSTEM_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_OPERATINGSYSTEM_H



#include <buildconfig.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



enum class OperatingSystem: u8
{
    FAT_FILESYSTEM  = 0,
    AMIGA           = 1,
    VMS             = 2,
    UNIX            = 3,
    VM_CMS          = 4,
    ATARI_TOS       = 5,
    HPFS_FILESYSTEM = 6,
    MACINTOSH       = 7,
    Z_SYSTEM        = 8,
    CP_M            = 9,
    TOPS_20         = 10,
    NTFS_FILESYSTEM = 11,
    QDOS            = 12,
    ACORN_RISCOS    = 13,
    UNKNOWN         = 255
};



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_OPERATINGSYSTEM_H
