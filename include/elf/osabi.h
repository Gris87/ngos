#ifndef ELF_OSABI_H
#define ELF_OSABI_H



#include <ngos/types.h>



enum class ElfOsAbi: u8
{
    SYSTEM_V         = 0x00,
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



inline const char* elfOsAbiToString(ElfOsAbi abi) // TEST: NO
{
    switch (abi)
    {
        case ElfOsAbi::SYSTEM_V: return "SYSTEM_V";
        case ElfOsAbi::HP_UX:    return "HP_UX";
        case ElfOsAbi::NETBSD:    return "NETBSD";
        case ElfOsAbi::LINUX:    return "LINUX";
        case ElfOsAbi::GNU_HURD:    return "GNU_HURD";
        case ElfOsAbi::SOLARIS:    return "SOLARIS";
        case ElfOsAbi::AIX:    return "AIX";
        case ElfOsAbi::IRIX:    return "IRIX";
        case ElfOsAbi::FREEBSD:    return "FREEBSD";
        case ElfOsAbi::TRU64:    return "TRU64";
        case ElfOsAbi::NOVELL_MODESTO:    return "NOVELL_MODESTO";
        case ElfOsAbi::OPENBSD:    return "OPENBSD";

        default: return "UNKNOWN";
    }
}



#endif // ELF_OSABI_H
