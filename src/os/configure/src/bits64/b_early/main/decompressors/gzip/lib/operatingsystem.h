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



inline const char* operatingSystemToString(OperatingSystem system) // TEST: NO
{
    // EARLY_LT((" | system = %u", system)); // Commented to avoid bad looking logs



    switch (system)
    {
        case OperatingSystem::FAT_FILESYSTEM:  return "FAT_FILESYSTEM";
        case OperatingSystem::AMIGA:           return "AMIGA";
        case OperatingSystem::VMS:             return "VMS";
        case OperatingSystem::UNIX:            return "UNIX";
        case OperatingSystem::VM_CMS:          return "VM_CMS";
        case OperatingSystem::ATARI_TOS:       return "ATARI_TOS";
        case OperatingSystem::HPFS_FILESYSTEM: return "HPFS_FILESYSTEM";
        case OperatingSystem::MACINTOSH:       return "MACINTOSH";
        case OperatingSystem::Z_SYSTEM:        return "Z_SYSTEM";
        case OperatingSystem::CP_M:            return "CP_M";
        case OperatingSystem::TOPS_20:         return "TOPS_20";
        case OperatingSystem::NTFS_FILESYSTEM: return "NTFS_FILESYSTEM";
        case OperatingSystem::QDOS:            return "QDOS";
        case OperatingSystem::ACORN_RISCOS:    return "ACORN_RISCOS";
        case OperatingSystem::UNKNOWN:         return "UNKNOWN";

        default: return "UNKNOWN";
    }
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_OPERATINGSYSTEM_H
