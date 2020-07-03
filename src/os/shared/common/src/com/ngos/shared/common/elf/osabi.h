#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_OSABI_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_OSABI_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfOsAbi: u8
{
    SYSTEM_V         = 0,
    HP_UX            = 0x01,
    NETBSD           = 0x02,
    LINUX            = 0x03,
    GNU_HURD         = 0x04,
    SOLARIS          = 0x06,
    AIX              = 0x07,
    IRIX             = 0x08,
    FREEBSD          = 0x09,
    TRU64            = 0x0A,
    NOVELL_MODESTO   = 0x0B,
    OPENBSD          = 0x0C,
    OPENVMS          = 0x0D,
    NONSTOP_KERNEL   = 0x0E,
    AROS             = 0x0F,
    FENIX_OS         = 0x10,
    CLOUD_ABI        = 0x11,
    SORTIX           = 0x53
};



inline const char8* enumToString(ElfOsAbi abi) // TEST: NO
{
    // COMMON_LT((" | abi = %u", abi)); // Commented to avoid bad looking logs



    switch (abi)
    {
        case ElfOsAbi::SYSTEM_V:       return "SYSTEM_V";
        case ElfOsAbi::HP_UX:          return "HP_UX";
        case ElfOsAbi::NETBSD:         return "NETBSD";
        case ElfOsAbi::LINUX:          return "LINUX";
        case ElfOsAbi::GNU_HURD:       return "GNU_HURD";
        case ElfOsAbi::SOLARIS:        return "SOLARIS";
        case ElfOsAbi::AIX:            return "AIX";
        case ElfOsAbi::IRIX:           return "IRIX";
        case ElfOsAbi::FREEBSD:        return "FREEBSD";
        case ElfOsAbi::TRU64:          return "TRU64";
        case ElfOsAbi::NOVELL_MODESTO: return "NOVELL_MODESTO";
        case ElfOsAbi::OPENBSD:        return "OPENBSD";
        case ElfOsAbi::OPENVMS:        return "OPENVMS";
        case ElfOsAbi::NONSTOP_KERNEL: return "NONSTOP_KERNEL";
        case ElfOsAbi::AROS:           return "AROS";
        case ElfOsAbi::FENIX_OS:       return "FENIX_OS";
        case ElfOsAbi::CLOUD_ABI:      return "CLOUD_ABI";
        case ElfOsAbi::SORTIX:         return "SORTIX";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfOsAbi abi) // TEST: NO
{
    // COMMON_LT((" | abi = %u", abi)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%02X (%s)", abi, enumToString(abi));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_OSABI_H
