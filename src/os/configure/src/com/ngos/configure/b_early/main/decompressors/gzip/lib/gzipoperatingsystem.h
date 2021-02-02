#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPOPERATINGSYSTEM_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPOPERATINGSYSTEM_H



#include <buildconfig.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



enum class GzipOperatingSystem: bad_uint8
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



inline const char8* enumToString(GzipOperatingSystem system) // TEST: NO
{
    // EARLY_LT((" | system = %u", system)); // Commented to avoid bad looking logs



    switch (system)
    {
        case GzipOperatingSystem::FAT_FILESYSTEM:  return "FAT_FILESYSTEM";
        case GzipOperatingSystem::AMIGA:           return "AMIGA";
        case GzipOperatingSystem::VMS:             return "VMS";
        case GzipOperatingSystem::UNIX:            return "UNIX";
        case GzipOperatingSystem::VM_CMS:          return "VM_CMS";
        case GzipOperatingSystem::ATARI_TOS:       return "ATARI_TOS";
        case GzipOperatingSystem::HPFS_FILESYSTEM: return "HPFS_FILESYSTEM";
        case GzipOperatingSystem::MACINTOSH:       return "MACINTOSH";
        case GzipOperatingSystem::Z_SYSTEM:        return "Z_SYSTEM";
        case GzipOperatingSystem::CP_M:            return "CP_M";
        case GzipOperatingSystem::TOPS_20:         return "TOPS_20";
        case GzipOperatingSystem::NTFS_FILESYSTEM: return "NTFS_FILESYSTEM";
        case GzipOperatingSystem::QDOS:            return "QDOS";
        case GzipOperatingSystem::ACORN_RISCOS:    return "ACORN_RISCOS";
        case GzipOperatingSystem::UNKNOWN:         return "UNKNOWN";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(GzipOperatingSystem system) // TEST: NO
{
    // EARLY_LT((" | system = %u", system)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", (bad_uint8)system, enumToString(system));

    return res;
}



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPOPERATINGSYSTEM_H
