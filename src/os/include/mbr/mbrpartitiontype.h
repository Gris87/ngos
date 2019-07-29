#ifndef MBR_MBRPARTITIONTYPE_H
#define MBR_MBRPARTITIONTYPE_H



#include <ngos/types.h>



enum class MbrPartitionType: u8
{
    NONE                              = 0,
    FAT12                             = 0x01,
    XENIX_ROOT                        = 0x02,
    XENIX_USER                        = 0x03,
    FAT16                             = 0x04,
    EXTENDED_WITH_CHS                 = 0x05,
    FAT16B                            = 0x06,
    NTFS                              = 0x07,
    AIX_BOOT_SPLIT                    = 0x08,
    AIX_DATA_BOOT                     = 0x09,
    OS_2_BOOT_MANAGER                 = 0x0A,
    FAT32                             = 0x0B,
    FAT32X                            = 0x0C,
    RESERVED_0D                       = 0x0D,
    FAT16X                            = 0x0E,
    EXTENDED_WITH_LBA                 = 0x0F,
    OPUS                              = 0x10,
    HIDDEN_FAT12                      = 0x11,
    SERVICE_PARTITION                 = 0x12,
    RESERVED_13                       = 0x13,
    HIDDEN_FAT16                      = 0x14,
    HIDDEN_EXTENDED_WITH_CHS          = 0x15,
    HIDDEN_FAT16B                     = 0x16,
    HIDDEN_NTFS                       = 0x17,
    AST_SMARTSLEEP                    = 0x18,
    OFS1_1                            = 0x19,
    RESERVED_1A                       = 0x1A,
    HIDDEN_FAT32                      = 0x1B,
    HIDDEN_FAT32X                     = 0x1C,
    RESERVED_1D                       = 0x1D,
    HIDDEN_FAT16X                     = 0x1E,
    HIDDEN_EXTENDED_WITH_LBA          = 0x1F,
    OFS1_2                            = 0x20,
    FSO2                              = 0x21,
    EXTENDED_FSO2                     = 0x22,
    WINDOWS_MOBILE_BOOT_XIP           = 0x23,
    NEC_DOS                           = 0x24,
    WINDOWS_MOBILE_IMGFS              = 0x25,
    RESERVED_26                       = 0x26,
    WINDOWS_RECOVERY_ENVIRONMENT      = 0x27,
    RESERVED_28                       = 0x28,
    RESERVED_29                       = 0x29,
    AFS                               = 0x2A,
    SYLLABLE_SECURE                   = 0x2B,
    RESERVED_2C                       = 0x2C,
    RESERVED_2D                       = 0x2D,
    RESERVED_2E                       = 0x2E,
    RESERVED_2F                       = 0x2F,
    RESERVED_30                       = 0x30,
    RESERVED_31                       = 0x31,
    NOS                               = 0x32,
    RESERVED_33                       = 0x33,
    RESERVED_34                       = 0x34,
    JFS                               = 0x35,
    RESERVED_36                       = 0x36,
    RESERVED_37                       = 0x37,
    THEOS_3_2                         = 0x38,
    PLAN_9                            = 0x39,
    THEOS_4                           = 0x3A,
    EXTENDED_THEOS_4                  = 0x3B,
    PARTITION_MAGIC                   = 0x3C,
    HIDDEN_NETWARE                    = 0x3D,
    RESERVED_3E                       = 0x3E,
    RESERVED_3F                       = 0x3F,
    PICK_R83                          = 0x40,
    OLD_LINUX_MINIX                   = 0x41,
    OLD_LINUX_SWAP                    = 0x42,
    OLD_LINUX_NATIVE                  = 0x43,
    GOBACK                            = 0x44,
    EUMEL_ELAN_1                      = 0x45,
    EUMEL_ELAN_2                      = 0x46,
    EUMEL_ELAN_3                      = 0x47,
    EUMEL_ELAN_4                      = 0x48,
    RESERVED_49                       = 0x49,
    ALFS                              = 0x4A,
    RESERVED_4B                       = 0x4B,
    AOS                               = 0x4C,
    QNX_PRIMARY                       = 0x4D,
    QNX_SECONDARY                     = 0x4E,
    QNX_TERTIARY                      = 0x4F,
    ONTRACK_DM                        = 0x50,
    ONTRACK_DM6                       = 0x51,
    CP_M_80                           = 0x52,
    ONTRACK_DM6_AUXILIARY_3           = 0x53,
    ONTRACK_DM6_DDO                   = 0x54,
    EZ_DRIVE                          = 0x55,
    GOLDEN_BOW                        = 0x56,
    VNDI                              = 0x57,
    RESERVED_58                       = 0x58,
    RESERVED_59                       = 0x59,
    RESERVED_5A                       = 0x5A,
    RESERVED_5B                       = 0x5B,
    PRIAM_EDISK                       = 0x5C,
    RESERVED_5D                       = 0x5D,
    RESERVED_5E                       = 0x5E,
    RESERVED_5F                       = 0x5F,
    RESERVED_60                       = 0x60,
    SPEEDSTOR_HIDDEN_FAT12            = 0x61,
    RESERVED_62                       = 0x62,
    UNIX                              = 0x63,
    NETWARE_1                         = 0x64,
    NETWARE_2                         = 0x65,
    NETWARE_3                         = 0x66,
    NETWARE_4                         = 0x67,
    NETWARE_5                         = 0x68,
    NETWARE_6                         = 0x69,
    RESERVED_6A                       = 0x6A,
    RESERVED_6B                       = 0x6B,
    BSD_SLICE                         = 0x6C,
    RESERVED_6D                       = 0x6D,
    RESERVED_6E                       = 0x6E,
    RESERVED_6F                       = 0x6F,
    DISKSECURE_MULTIBOOT              = 0x70,
    RESERVED_71                       = 0x71,
    APTI_ALTERNATIVE_FAT12            = 0x72,
    RESERVED_73                       = 0x73,
    SPEEDSTOR_HIDDEN_FAT16B           = 0x74,
    PC_IX                             = 0x75,
    SPEEDSTOR_HIDDEN_READ_ONLY_FAT16B = 0x76,
    M2FS                              = 0x77,
    XOSL                              = 0x78,
    APTI_ALTERNATIVE_FAT16            = 0x79,
    APTI_ALTERNATIVE_FAT16X           = 0x7A,
    APTI_ALTERNATIVE_FAT16B           = 0x7B,
    APTI_ALTERNATIVE_FAT32            = 0x7C,
    APTI_ALTERNATIVE_FAT32X           = 0x7D,
    LEVEL_2_CACHE                     = 0x7E,
    EXPERIMENTAL                      = 0x7F,
    OLD_MINIX                         = 0x80,
    MINIX                             = 0x81,
    LINUX_SWAP                        = 0x82,
    LINUX                             = 0x83,
    APM_HIBERNATION                   = 0x84,
    LINUX_EXTENDED                    = 0x85,
    FAT16B_MIRRORED_VOLUME_SET        = 0x86,
    NTFS_MIRRORED_VOLUME_SET          = 0x87,
    LINUX_PLAINTEXT_TABLE             = 0x88,
    RESERVED_89                       = 0x89,
    LINUX_KERNEL_IMAGE                = 0x8A,
    FAT32_MIRRORED_VOLUME_SET         = 0x8B,
    FAT32X_MIRRORED_VOLUME_SET        = 0x8C,
    FDISK_HIDDEN_FAT12                = 0x8D,
    LINUX_LVM                         = 0x8E,
    RESERVED_8F                       = 0x8F,
    FDISK_HIDDEN_FAT16                = 0x90,
    FDISK_HIDDEN_EXTENDED_WITH_CHS    = 0x91,
    FDISK_HIDDEN_FAT16B               = 0x92,
    HIDDEN_LINUX                      = 0x93,
    AMOEBA_BAD_BLOCK_TABLE            = 0x94,
    EXOPC                             = 0x95,
    ISO_9660                          = 0x96,
    FDISK_HIDDEN_FAT32                = 0x97,
    FDISK_HIDDEN_FAT32X               = 0x98,
    EARLY_UNIX                        = 0x99,
    FDISK_HIDDEN_FAT16X               = 0x9A,
    FDISK_HIDDEN_EXTENDED_WITH_LBA    = 0x9B,
    RESERVED_9C                       = 0x9C,
    RESERVED_9D                       = 0x9D,
    FORTHOS                           = 0x9E,
    BSDI                              = 0x9F,
    HIBERNATE_PARTITION               = 0xA0,
    HP_VOLUME_EXPANSION_1             = 0xA1,
    HP_VOLUME_EXPANSION_2             = 0xA2,
    HP_VOLUME_EXPANSION_3             = 0xA3,
    HP_VOLUME_EXPANSION_4             = 0xA4,
    FREEBSD                           = 0xA5,
    OPENBSD                           = 0xA6,
    NEXTSTEP                          = 0xA7,
    MAC_OS_X_UFS                      = 0xA8,
    NETBSD                            = 0xA9,
    OLIVETTI_MS_DOS_FAT12             = 0xAA,
    MAC_OS_X_BOOT                     = 0xAB,
    MAC_OS_X_RAID                     = 0xAC,
    ADFS                              = 0xAD,
    SHAGOS                            = 0xAE,
    MAC_OS_X_HFS                      = 0xAF,
    BOOT_STAR_DUMMY                   = 0xB0,
    QNX_NEUTRINO_1                    = 0xB1,
    QNX_NEUTRINO_2                    = 0xB2,
    QNX_NEUTRINO_3                    = 0xB3,
    HP_VOLUME_EXPANSION_5             = 0xB4,
    RESERVED_B5                       = 0xB5,
    FAT16B_MIRRORED_MASTER_VOLUME     = 0xB6,
    NTFS_MIRRORED_MASTER_VOLUME       = 0xB7,
    BSDI_SWAP                         = 0xB8,
    RESERVED_B9                       = 0xB9,
    RESERVED_BA                       = 0xBA,
    FAT32_MIRRORED_MASTER_VOLUME      = 0xBB,
    FAT32X_MIRRORED_MASTER_VOLUME     = 0xBC,
    BONNYDOS                          = 0xBD,
    SOLARIS_8_BOOT                    = 0xBE,
    SOLARIS                           = 0xBF,
    SECURED_FAT                       = 0xC0,
    SECURED_FAT12                     = 0xC1,
    HIDDEN_LINUX_NATIVE               = 0xC2,
    HIDDEN_LINUX_SWAP                 = 0xC3,
    SECURED_FAT16                     = 0xC4,
    SECURED_EXTENDED_WITH_CHS         = 0xC5,
    FAT16B_MIRRORED_SLABE_VOLUME      = 0xC6,
    NTFS_MIRRORED_SLABE_VOLUME        = 0xC7,
    RESERVED_C8                       = 0xC8,
    RESERVED_C9                       = 0xC9,
    RESERVED_CA                       = 0xCA,
    FAT32_MIRRORED_SLAVE_VOLUME       = 0xCB,
    FAT32X_MIRRORED_SLAVE_VOLUME      = 0xCC,
    MEMORY_DUMP                       = 0xCD,
    SECURED_FAT16B                    = 0xCE,
    SECURED_EXTENDED_WITH_LBA         = 0xCF,
    NOVELL_SECURED_FAT                = 0xD0,
    NOVELL_SECURED_FAT12              = 0xD1,
    RESERVED_D2                       = 0xD2,
    RESERVED_D3                       = 0xD3,
    NOVELL_SECURED_FAT16              = 0xD4,
    NOVELL_SECURED_EXTENDED_WITH_CHS  = 0xD5,
    NOVELL_SECURED_FAT16B             = 0xD6,
    RESERVED_D7                       = 0xD7,
    CP_M_86                           = 0xD8,
    RESERVED_D9                       = 0xD9,
    NON_FS                            = 0xDA,
    FAT32_SYSTEM_RESTORE              = 0xDB,
    RESERVED_DC                       = 0xDC,
    HIDDEN_MEMORY_DUMP                = 0xDD,
    FAT16_UTILITY                     = 0xDE,
    DG_UX_VIRTUAL_DISK_MANAGER        = 0xDF,
    AVFS                              = 0xE0,
    SPEEDSTOR_FAT12                   = 0xE1,
    RESERVED_E2                       = 0xE2,
    SPEEDSTOR_READ_ONLY_FAT12         = 0xE3,
    SPEEDSTOR_FAT16                   = 0xE4,
    TANDY_FAT                         = 0xE5,
    SPEEDSTOR_READ_ONLY_FAT16         = 0xE6,
    RESERVED_E7                       = 0xE7,
    LINUX_UNIFIED_KEY_SETUP           = 0xE8,
    RESERVED_E9                       = 0xE9,
    RESERVED_EA                       = 0xEA,
    BFS                               = 0xEB,
    SKYFS                             = 0xEC,
    GPT_HYBRID_MBR                    = 0xED,
    GPT_PROTECTIVE_MBR                = 0xEE,
    UEFI_SYSTEM_PARTITION             = 0xEF,
    PA_RISC_LINUX_BOOT_LOADER         = 0xF0,
    RESERVED_F1                       = 0xF1,
    SPERRY_FAT                        = 0xF2,
    RESERVED_F3                       = 0xF3,
    SPEEDSTOR_FAT16B                  = 0xF4,
    MULTI_VOLUME                      = 0xF5,
    SPEEDSTOR_READ_ONLY_FAT16B        = 0xF6,
    EFAT                              = 0xF7,
    RESERVED_F8                       = 0xF8,
    EXT2_EXT3_PERSISTENT_CACHE        = 0xF9,
    RESERVED_FA                       = 0xFA,
    VMFS                              = 0xFB,
    VMFS_SWAP                         = 0xFC,
    LINUX_RAID_SUPERBLOCK             = 0xFD,
    LANSTEP                           = 0xFE,
    XENIX_BAD_BLOCK_TABLE             = 0xFF
};



inline const char8* mbrPartitionTypeToString(MbrPartitionType type) // TEST: NO
{
    switch (type)
    {
        case MbrPartitionType::NONE:                              return "NONE";
        case MbrPartitionType::FAT12:                             return "FAT12";
        case MbrPartitionType::XENIX_ROOT:                        return "XENIX_ROOT";
        case MbrPartitionType::XENIX_USER:                        return "XENIX_USER";
        case MbrPartitionType::FAT16:                             return "FAT16";
        case MbrPartitionType::EXTENDED_WITH_CHS:                 return "EXTENDED_WITH_CHS";
        case MbrPartitionType::FAT16B:                            return "FAT16B";
        case MbrPartitionType::NTFS:                              return "NTFS";
        case MbrPartitionType::AIX_BOOT_SPLIT:                    return "AIX_BOOT_SPLIT";
        case MbrPartitionType::AIX_DATA_BOOT:                     return "AIX_DATA_BOOT";
        case MbrPartitionType::OS_2_BOOT_MANAGER:                 return "OS_2_BOOT_MANAGER";
        case MbrPartitionType::FAT32:                             return "FAT32";
        case MbrPartitionType::FAT32X:                            return "FAT32X";
        case MbrPartitionType::RESERVED_0D:                       return "RESERVED_0D";
        case MbrPartitionType::FAT16X:                            return "FAT16X";
        case MbrPartitionType::EXTENDED_WITH_LBA:                 return "EXTENDED_WITH_LBA";
        case MbrPartitionType::OPUS:                              return "OPUS";
        case MbrPartitionType::HIDDEN_FAT12:                      return "HIDDEN_FAT12";
        case MbrPartitionType::SERVICE_PARTITION:                 return "SERVICE_PARTITION";
        case MbrPartitionType::RESERVED_13:                       return "RESERVED_13";
        case MbrPartitionType::HIDDEN_FAT16:                      return "HIDDEN_FAT16";
        case MbrPartitionType::HIDDEN_EXTENDED_WITH_CHS:          return "HIDDEN_EXTENDED_WITH_CHS";
        case MbrPartitionType::HIDDEN_FAT16B:                     return "HIDDEN_FAT16B";
        case MbrPartitionType::HIDDEN_NTFS:                       return "HIDDEN_NTFS";
        case MbrPartitionType::AST_SMARTSLEEP:                    return "AST_SMARTSLEEP";
        case MbrPartitionType::OFS1_1:                            return "OFS1_1";
        case MbrPartitionType::RESERVED_1A:                       return "RESERVED_1A";
        case MbrPartitionType::HIDDEN_FAT32:                      return "HIDDEN_FAT32";
        case MbrPartitionType::HIDDEN_FAT32X:                     return "HIDDEN_FAT32X";
        case MbrPartitionType::RESERVED_1D:                       return "RESERVED_1D";
        case MbrPartitionType::HIDDEN_FAT16X:                     return "HIDDEN_FAT16X";
        case MbrPartitionType::HIDDEN_EXTENDED_WITH_LBA:          return "HIDDEN_EXTENDED_WITH_LBA";
        case MbrPartitionType::OFS1_2:                            return "OFS1_2";
        case MbrPartitionType::FSO2:                              return "FSO2";
        case MbrPartitionType::EXTENDED_FSO2:                     return "EXTENDED_FSO2";
        case MbrPartitionType::WINDOWS_MOBILE_BOOT_XIP:           return "WINDOWS_MOBILE_BOOT_XIP";
        case MbrPartitionType::NEC_DOS:                           return "NEC_DOS";
        case MbrPartitionType::WINDOWS_MOBILE_IMGFS:              return "WINDOWS_MOBILE_IMGFS";
        case MbrPartitionType::RESERVED_26:                       return "RESERVED_26";
        case MbrPartitionType::WINDOWS_RECOVERY_ENVIRONMENT:      return "WINDOWS_RECOVERY_ENVIRONMENT";
        case MbrPartitionType::RESERVED_28:                       return "RESERVED_28";
        case MbrPartitionType::RESERVED_29:                       return "RESERVED_29";
        case MbrPartitionType::AFS:                               return "AFS";
        case MbrPartitionType::SYLLABLE_SECURE:                   return "SYLLABLE_SECURE";
        case MbrPartitionType::RESERVED_2C:                       return "RESERVED_2C";
        case MbrPartitionType::RESERVED_2D:                       return "RESERVED_2D";
        case MbrPartitionType::RESERVED_2E:                       return "RESERVED_2E";
        case MbrPartitionType::RESERVED_2F:                       return "RESERVED_2F";
        case MbrPartitionType::RESERVED_30:                       return "RESERVED_30";
        case MbrPartitionType::RESERVED_31:                       return "RESERVED_31";
        case MbrPartitionType::NOS:                               return "NOS";
        case MbrPartitionType::RESERVED_33:                       return "RESERVED_33";
        case MbrPartitionType::RESERVED_34:                       return "RESERVED_34";
        case MbrPartitionType::JFS:                               return "JFS";
        case MbrPartitionType::RESERVED_36:                       return "RESERVED_36";
        case MbrPartitionType::RESERVED_37:                       return "RESERVED_37";
        case MbrPartitionType::THEOS_3_2:                         return "THEOS_3_2";
        case MbrPartitionType::PLAN_9:                            return "PLAN_9";
        case MbrPartitionType::THEOS_4:                           return "THEOS_4";
        case MbrPartitionType::EXTENDED_THEOS_4:                  return "EXTENDED_THEOS_4";
        case MbrPartitionType::PARTITION_MAGIC:                   return "PARTITION_MAGIC";
        case MbrPartitionType::HIDDEN_NETWARE:                    return "HIDDEN_NETWARE";
        case MbrPartitionType::RESERVED_3E:                       return "RESERVED_3E";
        case MbrPartitionType::RESERVED_3F:                       return "RESERVED_3F";
        case MbrPartitionType::PICK_R83:                          return "PICK_R83";
        case MbrPartitionType::OLD_LINUX_MINIX:                   return "OLD_LINUX_MINIX";
        case MbrPartitionType::OLD_LINUX_SWAP:                    return "OLD_LINUX_SWAP";
        case MbrPartitionType::OLD_LINUX_NATIVE:                  return "OLD_LINUX_NATIVE";
        case MbrPartitionType::GOBACK:                            return "GOBACK";
        case MbrPartitionType::EUMEL_ELAN_1:                      return "EUMEL_ELAN_1";
        case MbrPartitionType::EUMEL_ELAN_2:                      return "EUMEL_ELAN_2";
        case MbrPartitionType::EUMEL_ELAN_3:                      return "EUMEL_ELAN_3";
        case MbrPartitionType::EUMEL_ELAN_4:                      return "EUMEL_ELAN_4";
        case MbrPartitionType::RESERVED_49:                       return "RESERVED_49";
        case MbrPartitionType::ALFS:                              return "ALFS";
        case MbrPartitionType::RESERVED_4B:                       return "RESERVED_4B";
        case MbrPartitionType::AOS:                               return "AOS";
        case MbrPartitionType::QNX_PRIMARY:                       return "QNX_PRIMARY";
        case MbrPartitionType::QNX_SECONDARY:                     return "QNX_SECONDARY";
        case MbrPartitionType::QNX_TERTIARY:                      return "QNX_TERTIARY";
        case MbrPartitionType::ONTRACK_DM:                        return "ONTRACK_DM";
        case MbrPartitionType::ONTRACK_DM6:                       return "ONTRACK_DM6";
        case MbrPartitionType::CP_M_80:                           return "CP_M_80";
        case MbrPartitionType::ONTRACK_DM6_AUXILIARY_3:           return "ONTRACK_DM6_AUXILIARY_3";
        case MbrPartitionType::ONTRACK_DM6_DDO:                   return "ONTRACK_DM6_DDO";
        case MbrPartitionType::EZ_DRIVE:                          return "EZ_DRIVE";
        case MbrPartitionType::GOLDEN_BOW:                        return "GOLDEN_BOW";
        case MbrPartitionType::VNDI:                              return "VNDI";
        case MbrPartitionType::RESERVED_58:                       return "RESERVED_58";
        case MbrPartitionType::RESERVED_59:                       return "RESERVED_59";
        case MbrPartitionType::RESERVED_5A:                       return "RESERVED_5A";
        case MbrPartitionType::RESERVED_5B:                       return "RESERVED_5B";
        case MbrPartitionType::PRIAM_EDISK:                       return "PRIAM_EDISK";
        case MbrPartitionType::RESERVED_5D:                       return "RESERVED_5D";
        case MbrPartitionType::RESERVED_5E:                       return "RESERVED_5E";
        case MbrPartitionType::RESERVED_5F:                       return "RESERVED_5F";
        case MbrPartitionType::RESERVED_60:                       return "RESERVED_60";
        case MbrPartitionType::SPEEDSTOR_HIDDEN_FAT12:            return "SPEEDSTOR_HIDDEN_FAT12";
        case MbrPartitionType::RESERVED_62:                       return "RESERVED_62";
        case MbrPartitionType::UNIX:                              return "UNIX";
        case MbrPartitionType::NETWARE_1:                         return "NETWARE_1";
        case MbrPartitionType::NETWARE_2:                         return "NETWARE_2";
        case MbrPartitionType::NETWARE_3:                         return "NETWARE_3";
        case MbrPartitionType::NETWARE_4:                         return "NETWARE_4";
        case MbrPartitionType::NETWARE_5:                         return "NETWARE_5";
        case MbrPartitionType::NETWARE_6:                         return "NETWARE_6";
        case MbrPartitionType::RESERVED_6A:                       return "RESERVED_6A";
        case MbrPartitionType::RESERVED_6B:                       return "RESERVED_6B";
        case MbrPartitionType::BSD_SLICE:                         return "BSD_SLICE";
        case MbrPartitionType::RESERVED_6D:                       return "RESERVED_6D";
        case MbrPartitionType::RESERVED_6E:                       return "RESERVED_6E";
        case MbrPartitionType::RESERVED_6F:                       return "RESERVED_6F";
        case MbrPartitionType::DISKSECURE_MULTIBOOT:              return "DISKSECURE_MULTIBOOT";
        case MbrPartitionType::RESERVED_71:                       return "RESERVED_71";
        case MbrPartitionType::APTI_ALTERNATIVE_FAT12:            return "APTI_ALTERNATIVE_FAT12";
        case MbrPartitionType::RESERVED_73:                       return "RESERVED_73";
        case MbrPartitionType::SPEEDSTOR_HIDDEN_FAT16B:           return "SPEEDSTOR_HIDDEN_FAT16B";
        case MbrPartitionType::PC_IX:                             return "PC_IX";
        case MbrPartitionType::SPEEDSTOR_HIDDEN_READ_ONLY_FAT16B: return "SPEEDSTOR_HIDDEN_READ_ONLY_FAT16B";
        case MbrPartitionType::M2FS:                              return "M2FS";
        case MbrPartitionType::XOSL:                              return "XOSL";
        case MbrPartitionType::APTI_ALTERNATIVE_FAT16:            return "APTI_ALTERNATIVE_FAT16";
        case MbrPartitionType::APTI_ALTERNATIVE_FAT16X:           return "APTI_ALTERNATIVE_FAT16X";
        case MbrPartitionType::APTI_ALTERNATIVE_FAT16B:           return "APTI_ALTERNATIVE_FAT16B";
        case MbrPartitionType::APTI_ALTERNATIVE_FAT32:            return "APTI_ALTERNATIVE_FAT32";
        case MbrPartitionType::APTI_ALTERNATIVE_FAT32X:           return "APTI_ALTERNATIVE_FAT32X";
        case MbrPartitionType::LEVEL_2_CACHE:                     return "LEVEL_2_CACHE";
        case MbrPartitionType::EXPERIMENTAL:                      return "EXPERIMENTAL";
        case MbrPartitionType::OLD_MINIX:                         return "OLD_MINIX";
        case MbrPartitionType::MINIX:                             return "MINIX";
        case MbrPartitionType::LINUX_SWAP:                        return "LINUX_SWAP";
        case MbrPartitionType::LINUX:                             return "LINUX";
        case MbrPartitionType::APM_HIBERNATION:                   return "APM_HIBERNATION";
        case MbrPartitionType::LINUX_EXTENDED:                    return "LINUX_EXTENDED";
        case MbrPartitionType::FAT16B_MIRRORED_VOLUME_SET:        return "FAT16B_MIRRORED_VOLUME_SET";
        case MbrPartitionType::NTFS_MIRRORED_VOLUME_SET:          return "NTFS_MIRRORED_VOLUME_SET";
        case MbrPartitionType::LINUX_PLAINTEXT_TABLE:             return "LINUX_PLAINTEXT_TABLE";
        case MbrPartitionType::RESERVED_89:                       return "RESERVED_89";
        case MbrPartitionType::LINUX_KERNEL_IMAGE:                return "LINUX_KERNEL_IMAGE";
        case MbrPartitionType::FAT32_MIRRORED_VOLUME_SET:         return "FAT32_MIRRORED_VOLUME_SET";
        case MbrPartitionType::FAT32X_MIRRORED_VOLUME_SET:        return "FAT32X_MIRRORED_VOLUME_SET";
        case MbrPartitionType::FDISK_HIDDEN_FAT12:                return "FDISK_HIDDEN_FAT12";
        case MbrPartitionType::LINUX_LVM:                         return "LINUX_LVM";
        case MbrPartitionType::RESERVED_8F:                       return "RESERVED_8F";
        case MbrPartitionType::FDISK_HIDDEN_FAT16:                return "FDISK_HIDDEN_FAT16";
        case MbrPartitionType::FDISK_HIDDEN_EXTENDED_WITH_CHS:    return "FDISK_HIDDEN_EXTENDED_WITH_CHS";
        case MbrPartitionType::FDISK_HIDDEN_FAT16B:               return "FDISK_HIDDEN_FAT16B";
        case MbrPartitionType::HIDDEN_LINUX:                      return "HIDDEN_LINUX";
        case MbrPartitionType::AMOEBA_BAD_BLOCK_TABLE:            return "AMOEBA_BAD_BLOCK_TABLE";
        case MbrPartitionType::EXOPC:                             return "EXOPC";
        case MbrPartitionType::ISO_9660:                          return "ISO_9660";
        case MbrPartitionType::FDISK_HIDDEN_FAT32:                return "FDISK_HIDDEN_FAT32";
        case MbrPartitionType::FDISK_HIDDEN_FAT32X:               return "FDISK_HIDDEN_FAT32X";
        case MbrPartitionType::EARLY_UNIX:                        return "EARLY_UNIX";
        case MbrPartitionType::FDISK_HIDDEN_FAT16X:               return "FDISK_HIDDEN_FAT16X";
        case MbrPartitionType::FDISK_HIDDEN_EXTENDED_WITH_LBA:    return "FDISK_HIDDEN_EXTENDED_WITH_LBA";
        case MbrPartitionType::RESERVED_9C:                       return "RESERVED_9C";
        case MbrPartitionType::RESERVED_9D:                       return "RESERVED_9D";
        case MbrPartitionType::FORTHOS:                           return "FORTHOS";
        case MbrPartitionType::BSDI:                              return "BSDI";
        case MbrPartitionType::HIBERNATE_PARTITION:               return "HIBERNATE_PARTITION";
        case MbrPartitionType::HP_VOLUME_EXPANSION_1:             return "HP_VOLUME_EXPANSION_1";
        case MbrPartitionType::HP_VOLUME_EXPANSION_2:             return "HP_VOLUME_EXPANSION_2";
        case MbrPartitionType::HP_VOLUME_EXPANSION_3:             return "HP_VOLUME_EXPANSION_3";
        case MbrPartitionType::HP_VOLUME_EXPANSION_4:             return "HP_VOLUME_EXPANSION_4";
        case MbrPartitionType::FREEBSD:                           return "FREEBSD";
        case MbrPartitionType::OPENBSD:                           return "OPENBSD";
        case MbrPartitionType::NEXTSTEP:                          return "NEXTSTEP";
        case MbrPartitionType::MAC_OS_X_UFS:                      return "MAC_OS_X_UFS";
        case MbrPartitionType::NETBSD:                            return "NETBSD";
        case MbrPartitionType::OLIVETTI_MS_DOS_FAT12:             return "OLIVETTI_MS_DOS_FAT12";
        case MbrPartitionType::MAC_OS_X_BOOT:                     return "MAC_OS_X_BOOT";
        case MbrPartitionType::MAC_OS_X_RAID:                     return "MAC_OS_X_RAID";
        case MbrPartitionType::ADFS:                              return "ADFS";
        case MbrPartitionType::SHAGOS:                            return "SHAGOS";
        case MbrPartitionType::MAC_OS_X_HFS:                      return "MAC_OS_X_HFS";
        case MbrPartitionType::BOOT_STAR_DUMMY:                   return "BOOT_STAR_DUMMY";
        case MbrPartitionType::QNX_NEUTRINO_1:                    return "QNX_NEUTRINO_1";
        case MbrPartitionType::QNX_NEUTRINO_2:                    return "QNX_NEUTRINO_2";
        case MbrPartitionType::QNX_NEUTRINO_3:                    return "QNX_NEUTRINO_3";
        case MbrPartitionType::HP_VOLUME_EXPANSION_5:             return "HP_VOLUME_EXPANSION_5";
        case MbrPartitionType::RESERVED_B5:                       return "RESERVED_B5";
        case MbrPartitionType::FAT16B_MIRRORED_MASTER_VOLUME:     return "FAT16B_MIRRORED_MASTER_VOLUME";
        case MbrPartitionType::NTFS_MIRRORED_MASTER_VOLUME:       return "NTFS_MIRRORED_MASTER_VOLUME";
        case MbrPartitionType::BSDI_SWAP:                         return "BSDI_SWAP";
        case MbrPartitionType::RESERVED_B9:                       return "RESERVED_B9";
        case MbrPartitionType::RESERVED_BA:                       return "RESERVED_BA";
        case MbrPartitionType::FAT32_MIRRORED_MASTER_VOLUME:      return "FAT32_MIRRORED_MASTER_VOLUME";
        case MbrPartitionType::FAT32X_MIRRORED_MASTER_VOLUME:     return "FAT32X_MIRRORED_MASTER_VOLUME";
        case MbrPartitionType::BONNYDOS:                          return "BONNYDOS";
        case MbrPartitionType::SOLARIS_8_BOOT:                    return "SOLARIS_8_BOOT";
        case MbrPartitionType::SOLARIS:                           return "SOLARIS";
        case MbrPartitionType::SECURED_FAT:                       return "SECURED_FAT";
        case MbrPartitionType::SECURED_FAT12:                     return "SECURED_FAT12";
        case MbrPartitionType::HIDDEN_LINUX_NATIVE:               return "HIDDEN_LINUX_NATIVE";
        case MbrPartitionType::HIDDEN_LINUX_SWAP:                 return "HIDDEN_LINUX_SWAP";
        case MbrPartitionType::SECURED_FAT16:                     return "SECURED_FAT16";
        case MbrPartitionType::SECURED_EXTENDED_WITH_CHS:         return "SECURED_EXTENDED_WITH_CHS";
        case MbrPartitionType::FAT16B_MIRRORED_SLABE_VOLUME:      return "FAT16B_MIRRORED_SLABE_VOLUME";
        case MbrPartitionType::NTFS_MIRRORED_SLABE_VOLUME:        return "NTFS_MIRRORED_SLABE_VOLUME";
        case MbrPartitionType::RESERVED_C8:                       return "RESERVED_C8";
        case MbrPartitionType::RESERVED_C9:                       return "RESERVED_C9";
        case MbrPartitionType::RESERVED_CA:                       return "RESERVED_CA";
        case MbrPartitionType::FAT32_MIRRORED_SLAVE_VOLUME:       return "FAT32_MIRRORED_SLAVE_VOLUME";
        case MbrPartitionType::FAT32X_MIRRORED_SLAVE_VOLUME:      return "FAT32X_MIRRORED_SLAVE_VOLUME";
        case MbrPartitionType::MEMORY_DUMP:                       return "MEMORY_DUMP";
        case MbrPartitionType::SECURED_FAT16B:                    return "SECURED_FAT16B";
        case MbrPartitionType::SECURED_EXTENDED_WITH_LBA:         return "SECURED_EXTENDED_WITH_LBA";
        case MbrPartitionType::NOVELL_SECURED_FAT:                return "NOVELL_SECURED_FAT";
        case MbrPartitionType::NOVELL_SECURED_FAT12:              return "NOVELL_SECURED_FAT12";
        case MbrPartitionType::RESERVED_D2:                       return "RESERVED_D2";
        case MbrPartitionType::RESERVED_D3:                       return "RESERVED_D3";
        case MbrPartitionType::NOVELL_SECURED_FAT16:              return "NOVELL_SECURED_FAT16";
        case MbrPartitionType::NOVELL_SECURED_EXTENDED_WITH_CHS:  return "NOVELL_SECURED_EXTENDED_WITH_CHS";
        case MbrPartitionType::NOVELL_SECURED_FAT16B:             return "NOVELL_SECURED_FAT16B";
        case MbrPartitionType::RESERVED_D7:                       return "RESERVED_D7";
        case MbrPartitionType::CP_M_86:                           return "CP_M_86";
        case MbrPartitionType::RESERVED_D9:                       return "RESERVED_D9";
        case MbrPartitionType::NON_FS:                            return "NON_FS";
        case MbrPartitionType::FAT32_SYSTEM_RESTORE:              return "FAT32_SYSTEM_RESTORE";
        case MbrPartitionType::RESERVED_DC:                       return "RESERVED_DC";
        case MbrPartitionType::HIDDEN_MEMORY_DUMP:                return "HIDDEN_MEMORY_DUMP";
        case MbrPartitionType::FAT16_UTILITY:                     return "FAT16_UTILITY";
        case MbrPartitionType::DG_UX_VIRTUAL_DISK_MANAGER:        return "DG_UX_VIRTUAL_DISK_MANAGER";
        case MbrPartitionType::AVFS:                              return "AVFS";
        case MbrPartitionType::SPEEDSTOR_FAT12:                   return "SPEEDSTOR_FAT12";
        case MbrPartitionType::RESERVED_E2:                       return "RESERVED_E2";
        case MbrPartitionType::SPEEDSTOR_READ_ONLY_FAT12:         return "SPEEDSTOR_READ_ONLY_FAT12";
        case MbrPartitionType::SPEEDSTOR_FAT16:                   return "SPEEDSTOR_FAT16";
        case MbrPartitionType::TANDY_FAT:                         return "TANDY_FAT";
        case MbrPartitionType::SPEEDSTOR_READ_ONLY_FAT16:         return "SPEEDSTOR_READ_ONLY_FAT16";
        case MbrPartitionType::RESERVED_E7:                       return "RESERVED_E7";
        case MbrPartitionType::LINUX_UNIFIED_KEY_SETUP:           return "LINUX_UNIFIED_KEY_SETUP";
        case MbrPartitionType::RESERVED_E9:                       return "RESERVED_E9";
        case MbrPartitionType::RESERVED_EA:                       return "RESERVED_EA";
        case MbrPartitionType::BFS:                               return "BFS";
        case MbrPartitionType::SKYFS:                             return "SKYFS";
        case MbrPartitionType::GPT_HYBRID_MBR:                    return "GPT_HYBRID_MBR";
        case MbrPartitionType::GPT_PROTECTIVE_MBR:                return "GPT_PROTECTIVE_MBR";
        case MbrPartitionType::UEFI_SYSTEM_PARTITION:             return "UEFI_SYSTEM_PARTITION";
        case MbrPartitionType::PA_RISC_LINUX_BOOT_LOADER:         return "PA_RISC_LINUX_BOOT_LOADER";
        case MbrPartitionType::RESERVED_F1:                       return "RESERVED_F1";
        case MbrPartitionType::SPERRY_FAT:                        return "SPERRY_FAT";
        case MbrPartitionType::RESERVED_F3:                       return "RESERVED_F3";
        case MbrPartitionType::SPEEDSTOR_FAT16B:                  return "SPEEDSTOR_FAT16B";
        case MbrPartitionType::MULTI_VOLUME:                      return "MULTI_VOLUME";
        case MbrPartitionType::SPEEDSTOR_READ_ONLY_FAT16B:        return "SPEEDSTOR_READ_ONLY_FAT16B";
        case MbrPartitionType::EFAT:                              return "EFAT";
        case MbrPartitionType::RESERVED_F8:                       return "RESERVED_F8";
        case MbrPartitionType::EXT2_EXT3_PERSISTENT_CACHE:        return "EXT2_EXT3_PERSISTENT_CACHE";
        case MbrPartitionType::RESERVED_FA:                       return "RESERVED_FA";
        case MbrPartitionType::VMFS:                              return "VMFS";
        case MbrPartitionType::VMFS_SWAP:                         return "VMFS_SWAP";
        case MbrPartitionType::LINUX_RAID_SUPERBLOCK:             return "LINUX_RAID_SUPERBLOCK";
        case MbrPartitionType::LANSTEP:                           return "LANSTEP";
        case MbrPartitionType::XENIX_BAD_BLOCK_TABLE:             return "XENIX_BAD_BLOCK_TABLE";

        default: return "UNKNOWN";
    }
}



#endif // MBR_MBRPARTITIONTYPE_H
