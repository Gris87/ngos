#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS64MEMORYERRORINFORMATIONERRORTYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS64MEMORYERRORINFORMATIONERRORTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiBits64MemoryErrorInformationErrorType: bad_uint8
{
    NONE                        = 0,
    OTHER                       = 1,
    UNKNOWN                     = 2,
    OK                          = 3,
    BAD_READ                    = 4,
    PARITY_ERROR                = 5,
    SINGLE_BIT_ERROR            = 6,
    DOUBLE_BIT_ERROR            = 7,
    MULTI_BIT_ERROR             = 8,
    NIBBLE_ERROR                = 9,
    CHECKSUM_ERROR              = 10,
    CRC_ERROR                   = 11,
    CORRECTED_SINGLE_BIT_ERROR  = 12,
    CORRECTED_ERROR             = 13,
    UNCORRECTABLE_ERROR         = 14
};



inline const char8* enumToString(DmiBits64MemoryErrorInformationErrorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiBits64MemoryErrorInformationErrorType::NONE:                       return "NONE";
        case DmiBits64MemoryErrorInformationErrorType::OTHER:                      return "OTHER";
        case DmiBits64MemoryErrorInformationErrorType::UNKNOWN:                    return "UNKNOWN";
        case DmiBits64MemoryErrorInformationErrorType::OK:                         return "OK";
        case DmiBits64MemoryErrorInformationErrorType::BAD_READ:                   return "BAD_READ";
        case DmiBits64MemoryErrorInformationErrorType::PARITY_ERROR:               return "PARITY_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::SINGLE_BIT_ERROR:           return "SINGLE_BIT_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::DOUBLE_BIT_ERROR:           return "DOUBLE_BIT_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::MULTI_BIT_ERROR:            return "MULTI_BIT_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::NIBBLE_ERROR:               return "NIBBLE_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::CHECKSUM_ERROR:             return "CHECKSUM_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::CRC_ERROR:                  return "CRC_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::CORRECTED_SINGLE_BIT_ERROR: return "CORRECTED_SINGLE_BIT_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::CORRECTED_ERROR:            return "CORRECTED_ERROR";
        case DmiBits64MemoryErrorInformationErrorType::UNCORRECTABLE_ERROR:        return "UNCORRECTABLE_ERROR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBits64MemoryErrorInformationErrorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS64MEMORYERRORINFORMATIONERRORTYPE_H
