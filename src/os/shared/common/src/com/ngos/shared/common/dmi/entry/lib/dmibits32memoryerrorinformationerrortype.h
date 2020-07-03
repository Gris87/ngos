#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERRORTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERRORTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



enum class DmiBits32MemoryErrorInformationErrorType: u8
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



inline const char8* enumToString(DmiBits32MemoryErrorInformationErrorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiBits32MemoryErrorInformationErrorType::NONE:                       return "NONE";
        case DmiBits32MemoryErrorInformationErrorType::OTHER:                      return "OTHER";
        case DmiBits32MemoryErrorInformationErrorType::UNKNOWN:                    return "UNKNOWN";
        case DmiBits32MemoryErrorInformationErrorType::OK:                         return "OK";
        case DmiBits32MemoryErrorInformationErrorType::BAD_READ:                   return "BAD_READ";
        case DmiBits32MemoryErrorInformationErrorType::PARITY_ERROR:               return "PARITY_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::SINGLE_BIT_ERROR:           return "SINGLE_BIT_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::DOUBLE_BIT_ERROR:           return "DOUBLE_BIT_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::MULTI_BIT_ERROR:            return "MULTI_BIT_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::NIBBLE_ERROR:               return "NIBBLE_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::CHECKSUM_ERROR:             return "CHECKSUM_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::CRC_ERROR:                  return "CRC_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::CORRECTED_SINGLE_BIT_ERROR: return "CORRECTED_SINGLE_BIT_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::CORRECTED_ERROR:            return "CORRECTED_ERROR";
        case DmiBits32MemoryErrorInformationErrorType::UNCORRECTABLE_ERROR:        return "UNCORRECTABLE_ERROR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBits32MemoryErrorInformationErrorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBITS32MEMORYERRORINFORMATIONERRORTYPE_H
