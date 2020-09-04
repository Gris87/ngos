#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTERRORHANDLINGFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTERRORHANDLINGFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_hyper_transport_error_handling_flags;

enum class PciHyperTransportErrorHandlingFlag: pci_hyper_transport_error_handling_flags
{
    NONE                               = 0,
    ENABLE_PROTOCOL_ERROR_FLOOD        = (1ULL << 0),
    ENABLE_OVERFLOW_ERROR_FLOOD        = (1ULL << 1),
    ENABLE_PROTOCOL_ERROR_FATAL        = (1ULL << 2),
    ENABLE_OVERFLOW_ERROR_FATAL        = (1ULL << 3),
    ENABLE_END_OF_CHAIN_ERROR_FATAL    = (1ULL << 4),
    ENABLE_RESPONSE_ERROR_FATAL        = (1ULL << 5),
    ENABLE_CRC_ERROR_FATAL             = (1ULL << 6),
    ENABLE_SYSTEM_ERROR_FATAL          = (1ULL << 7),
    CHAIN_FAIL                         = (1ULL << 8),
    RESPONSE_ERROR                     = (1ULL << 9),
    ENABLE_PROTOCOL_ERROR_NONFATAL     = (1ULL << 10),
    ENABLE_OVERFLOW_ERROR_NONFATAL     = (1ULL << 11),
    ENABLE_END_OF_CHAIN_ERROR_NONFATAL = (1ULL << 12),
    ENABLE_RESPONSE_ERROR_NONFATAL     = (1ULL << 13),
    ENABLE_CRC_ERROR_NONFATAL          = (1ULL << 14),
    ENABLE_SYSTEM_ERROR_NONFATAL       = (1ULL << 15)
};

DEFINE_FLAGS(PciHyperTransportErrorHandlingFlags, pci_hyper_transport_error_handling_flags); // TEST: NO



inline const char8* flagToString(PciHyperTransportErrorHandlingFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciHyperTransportErrorHandlingFlag::NONE:                               return "NONE";
        case PciHyperTransportErrorHandlingFlag::ENABLE_PROTOCOL_ERROR_FLOOD:        return "ENABLE_PROTOCOL_ERROR_FLOOD";
        case PciHyperTransportErrorHandlingFlag::ENABLE_OVERFLOW_ERROR_FLOOD:        return "ENABLE_OVERFLOW_ERROR_FLOOD";
        case PciHyperTransportErrorHandlingFlag::ENABLE_PROTOCOL_ERROR_FATAL:        return "ENABLE_PROTOCOL_ERROR_FATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_OVERFLOW_ERROR_FATAL:        return "ENABLE_OVERFLOW_ERROR_FATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_END_OF_CHAIN_ERROR_FATAL:    return "ENABLE_END_OF_CHAIN_ERROR_FATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_RESPONSE_ERROR_FATAL:        return "ENABLE_RESPONSE_ERROR_FATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_CRC_ERROR_FATAL:             return "ENABLE_CRC_ERROR_FATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_SYSTEM_ERROR_FATAL:          return "ENABLE_SYSTEM_ERROR_FATAL";
        case PciHyperTransportErrorHandlingFlag::CHAIN_FAIL:                         return "CHAIN_FAIL";
        case PciHyperTransportErrorHandlingFlag::RESPONSE_ERROR:                     return "RESPONSE_ERROR";
        case PciHyperTransportErrorHandlingFlag::ENABLE_PROTOCOL_ERROR_NONFATAL:     return "ENABLE_PROTOCOL_ERROR_NONFATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_OVERFLOW_ERROR_NONFATAL:     return "ENABLE_OVERFLOW_ERROR_NONFATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_END_OF_CHAIN_ERROR_NONFATAL: return "ENABLE_END_OF_CHAIN_ERROR_NONFATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_RESPONSE_ERROR_NONFATAL:     return "ENABLE_RESPONSE_ERROR_NONFATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_CRC_ERROR_NONFATAL:          return "ENABLE_CRC_ERROR_NONFATAL";
        case PciHyperTransportErrorHandlingFlag::ENABLE_SYSTEM_ERROR_NONFATAL:       return "ENABLE_SYSTEM_ERROR_NONFATAL";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciHyperTransportErrorHandlingFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[44];

    sprintf(res, "0x%04X (%s)", (pci_hyper_transport_error_handling_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciHyperTransportErrorHandlingFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[475];

    FLAGS_TO_STRING(res, flags.flags, PciHyperTransportErrorHandlingFlag);

    return res;
}



inline const char8* flagsToFullString(const PciHyperTransportErrorHandlingFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[484];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciHyperTransportErrorHandlingFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTERRORHANDLINGFLAGS_H
