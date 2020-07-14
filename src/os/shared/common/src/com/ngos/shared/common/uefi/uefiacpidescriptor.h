#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIDESCRIPTOR_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiAcpiDescriptor: u8
{
    NONE                       = 0,
    IRQ_NOFLAG                 = 0x22,
    IRQ                        = 0x23,
    DMA                        = 0x2A,
    START_DEPENDENT            = 0x30,
    START_DEPENDENT_EX         = 0x31,
    END_DEPENDENT              = 0x38,
    IO_PORT                    = 0x47,
    FIXED_LOCATION_IO_PORT     = 0x4B,
    END_TAG                    = 0x79,
    _24_BIT_MEMORY_RANGE       = 0x81,
    _32_BIT_MEMORY_RANGE       = 0x85,
    _32_BIT_FIXED_MEMORY_RANGE = 0x86,
    DWORD_ADDRESS_SPACE        = 0x87,
    WORD_ADDRESS_SPACE         = 0x88,
    EXTENDED_INTERRUPT         = 0x89,
    ADDRESS_SPACE              = 0x8A
};



inline const char8* enumToString(UefiAcpiDescriptor descriptor) // TEST: NO
{
    // COMMON_LT((" | descriptor = %u", descriptor)); // Commented to avoid bad looking logs



    switch (descriptor)
    {
        case UefiAcpiDescriptor::NONE:                       return "NONE";
        case UefiAcpiDescriptor::IRQ_NOFLAG:                 return "IRQ_NOFLAG";
        case UefiAcpiDescriptor::IRQ:                        return "IRQ";
        case UefiAcpiDescriptor::DMA:                        return "DMA";
        case UefiAcpiDescriptor::START_DEPENDENT:            return "START_DEPENDENT";
        case UefiAcpiDescriptor::START_DEPENDENT_EX:         return "START_DEPENDENT_EX";
        case UefiAcpiDescriptor::END_DEPENDENT:              return "END_DEPENDENT";
        case UefiAcpiDescriptor::IO_PORT:                    return "IO_PORT";
        case UefiAcpiDescriptor::FIXED_LOCATION_IO_PORT:     return "FIXED_LOCATION_IO_PORT";
        case UefiAcpiDescriptor::END_TAG:                    return "END_TAG";
        case UefiAcpiDescriptor::_24_BIT_MEMORY_RANGE:       return "_24_BIT_MEMORY_RANGE";
        case UefiAcpiDescriptor::_32_BIT_MEMORY_RANGE:       return "_32_BIT_MEMORY_RANGE";
        case UefiAcpiDescriptor::_32_BIT_FIXED_MEMORY_RANGE: return "_32_BIT_FIXED_MEMORY_RANGE";
        case UefiAcpiDescriptor::DWORD_ADDRESS_SPACE:        return "DWORD_ADDRESS_SPACE";
        case UefiAcpiDescriptor::WORD_ADDRESS_SPACE:         return "WORD_ADDRESS_SPACE";
        case UefiAcpiDescriptor::EXTENDED_INTERRUPT:         return "EXTENDED_INTERRUPT";
        case UefiAcpiDescriptor::ADDRESS_SPACE:              return "ADDRESS_SPACE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiAcpiDescriptor descriptor) // TEST: NO
{
    // COMMON_LT((" | descriptor = %u", descriptor)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", descriptor, enumToString(descriptor));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIDESCRIPTOR_H
