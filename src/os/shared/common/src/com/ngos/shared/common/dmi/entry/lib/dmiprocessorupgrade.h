#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORUPGRADE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORUPGRADE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiProcessorUpgrade: u8
{
    NULL                   = 0,
    OTHER                  = 0x01,
    UNKNOWN                = 0x02,
    DAUGHTER_BOARD         = 0x03,
    ZIF_SOCKET             = 0x04,
    REPLACEABLE_PIGGY_BACK = 0x05,
    NONE                   = 0x06,
    LIF_SOCKET             = 0x07,
    SLOT_1                 = 0x08,
    SLOT_2                 = 0x09,
    _370_PIN_SOCKET        = 0x0A,
    SLOT_A                 = 0x0B,
    SLOT_M                 = 0x0C,
    SOCKET_423             = 0x0D,
    SOCKET_A               = 0x0E,
    SOCKET_478             = 0x0F,
    SOCKET_754             = 0x10,
    SOCKET_940             = 0x11,
    SOCKET_939             = 0x12,
    SOCKET_MPGA604         = 0x13,
    SOCKET_LGA771          = 0x14,
    SOCKET_LGA775          = 0x15,
    SOCKET_S1              = 0x16,
    SOCKET_AM2             = 0x17,
    SOCKET_F               = 0x18,
    SOCKET_LGA1366         = 0x19,
    SOCKET_G34             = 0x1A,
    SOCKET_AM3             = 0x1B,
    SOCKET_C32             = 0x1C,
    SOCKET_LGA1156         = 0x1D,
    SOCKET_LGA1567         = 0x1E,
    SOCKET_PGA988A         = 0x1F,
    SOCKET_BGA1288         = 0x20,
    SOCKET_RPGA988B        = 0x21,
    SOCKET_BGA1023         = 0x22,
    SOCKET_BGA1224         = 0x23,
    SOCKET_LGA1155         = 0x24,
    SOCKET_LGA1356         = 0x25,
    SOCKET_LGA2011         = 0x26,
    SOCKET_FS1             = 0x27,
    SOCKET_FS2             = 0x28,
    SOCKET_FM1             = 0x29,
    SOCKET_FM2             = 0x2A,
    SOCKET_LGA2011_3       = 0x2B,
    SOCKET_LGA1356_3       = 0x2C,
    SOCKET_LGA1150         = 0x2D,
    SOCKET_BGA1168         = 0x2E,
    SOCKET_BGA1234         = 0x2F,
    SOCKET_BGA1364         = 0x30,
    SOCKET_AM4             = 0x31,
    SOCKET_LGA1151         = 0x32,
    SOCKET_BGA1356         = 0x33,
    SOCKET_BGA1440         = 0x34,
    SOCKET_BGA1515         = 0x35,
    SOCKET_LGA3647_1       = 0x36,
    SOCKET_SP3             = 0x37,
    SOCKET_SP3R2           = 0x38,
    SOCKET_LGA2066         = 0x39,
    SOCKET_BGA1392         = 0x3A,
    SOCKET_BGA1510         = 0x3B,
    SOCKET_BGA1528         = 0x3C
};



inline const char8* enumToString(DmiProcessorUpgrade upgrade) // TEST: NO
{
    // COMMON_LT((" | upgrade = %u", upgrade)); // Commented to avoid bad looking logs



    switch (upgrade)
    {
        case DmiProcessorUpgrade::NULL:                   return "NULL";
        case DmiProcessorUpgrade::OTHER:                  return "OTHER";
        case DmiProcessorUpgrade::UNKNOWN:                return "UNKNOWN";
        case DmiProcessorUpgrade::DAUGHTER_BOARD:         return "DAUGHTER_BOARD";
        case DmiProcessorUpgrade::ZIF_SOCKET:             return "ZIF_SOCKET";
        case DmiProcessorUpgrade::REPLACEABLE_PIGGY_BACK: return "REPLACEABLE_PIGGY_BACK";
        case DmiProcessorUpgrade::NONE:                   return "NONE";
        case DmiProcessorUpgrade::LIF_SOCKET:             return "LIF_SOCKET";
        case DmiProcessorUpgrade::SLOT_1:                 return "SLOT_1";
        case DmiProcessorUpgrade::SLOT_2:                 return "SLOT_2";
        case DmiProcessorUpgrade::_370_PIN_SOCKET:        return "_370_PIN_SOCKET";
        case DmiProcessorUpgrade::SLOT_A:                 return "SLOT_A";
        case DmiProcessorUpgrade::SLOT_M:                 return "SLOT_M";
        case DmiProcessorUpgrade::SOCKET_423:             return "SOCKET_423";
        case DmiProcessorUpgrade::SOCKET_A:               return "SOCKET_A";
        case DmiProcessorUpgrade::SOCKET_478:             return "SOCKET_478";
        case DmiProcessorUpgrade::SOCKET_754:             return "SOCKET_754";
        case DmiProcessorUpgrade::SOCKET_940:             return "SOCKET_940";
        case DmiProcessorUpgrade::SOCKET_939:             return "SOCKET_939";
        case DmiProcessorUpgrade::SOCKET_MPGA604:         return "SOCKET_MPGA604";
        case DmiProcessorUpgrade::SOCKET_LGA771:          return "SOCKET_LGA771";
        case DmiProcessorUpgrade::SOCKET_LGA775:          return "SOCKET_LGA775";
        case DmiProcessorUpgrade::SOCKET_S1:              return "SOCKET_S1";
        case DmiProcessorUpgrade::SOCKET_AM2:             return "SOCKET_AM2";
        case DmiProcessorUpgrade::SOCKET_F:               return "SOCKET_F";
        case DmiProcessorUpgrade::SOCKET_LGA1366:         return "SOCKET_LGA1366";
        case DmiProcessorUpgrade::SOCKET_G34:             return "SOCKET_G34";
        case DmiProcessorUpgrade::SOCKET_AM3:             return "SOCKET_AM3";
        case DmiProcessorUpgrade::SOCKET_C32:             return "SOCKET_C32";
        case DmiProcessorUpgrade::SOCKET_LGA1156:         return "SOCKET_LGA1156";
        case DmiProcessorUpgrade::SOCKET_LGA1567:         return "SOCKET_LGA1567";
        case DmiProcessorUpgrade::SOCKET_PGA988A:         return "SOCKET_PGA988A";
        case DmiProcessorUpgrade::SOCKET_BGA1288:         return "SOCKET_BGA1288";
        case DmiProcessorUpgrade::SOCKET_RPGA988B:        return "SOCKET_RPGA988B";
        case DmiProcessorUpgrade::SOCKET_BGA1023:         return "SOCKET_BGA1023";
        case DmiProcessorUpgrade::SOCKET_BGA1224:         return "SOCKET_BGA1224";
        case DmiProcessorUpgrade::SOCKET_LGA1155:         return "SOCKET_LGA1155";
        case DmiProcessorUpgrade::SOCKET_LGA1356:         return "SOCKET_LGA1356";
        case DmiProcessorUpgrade::SOCKET_LGA2011:         return "SOCKET_LGA2011";
        case DmiProcessorUpgrade::SOCKET_FS1:             return "SOCKET_FS1";
        case DmiProcessorUpgrade::SOCKET_FS2:             return "SOCKET_FS2";
        case DmiProcessorUpgrade::SOCKET_FM1:             return "SOCKET_FM1";
        case DmiProcessorUpgrade::SOCKET_FM2:             return "SOCKET_FM2";
        case DmiProcessorUpgrade::SOCKET_LGA2011_3:       return "SOCKET_LGA2011_3";
        case DmiProcessorUpgrade::SOCKET_LGA1356_3:       return "SOCKET_LGA1356_3";
        case DmiProcessorUpgrade::SOCKET_LGA1150:         return "SOCKET_LGA1150";
        case DmiProcessorUpgrade::SOCKET_BGA1168:         return "SOCKET_BGA1168";
        case DmiProcessorUpgrade::SOCKET_BGA1234:         return "SOCKET_BGA1234";
        case DmiProcessorUpgrade::SOCKET_BGA1364:         return "SOCKET_BGA1364";
        case DmiProcessorUpgrade::SOCKET_AM4:             return "SOCKET_AM4";
        case DmiProcessorUpgrade::SOCKET_LGA1151:         return "SOCKET_LGA1151";
        case DmiProcessorUpgrade::SOCKET_BGA1356:         return "SOCKET_BGA1356";
        case DmiProcessorUpgrade::SOCKET_BGA1440:         return "SOCKET_BGA1440";
        case DmiProcessorUpgrade::SOCKET_BGA1515:         return "SOCKET_BGA1515";
        case DmiProcessorUpgrade::SOCKET_LGA3647_1:       return "SOCKET_LGA3647_1";
        case DmiProcessorUpgrade::SOCKET_SP3:             return "SOCKET_SP3";
        case DmiProcessorUpgrade::SOCKET_SP3R2:           return "SOCKET_SP3R2";
        case DmiProcessorUpgrade::SOCKET_LGA2066:         return "SOCKET_LGA2066";
        case DmiProcessorUpgrade::SOCKET_BGA1392:         return "SOCKET_BGA1392";
        case DmiProcessorUpgrade::SOCKET_BGA1510:         return "SOCKET_BGA1510";
        case DmiProcessorUpgrade::SOCKET_BGA1528:         return "SOCKET_BGA1528";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiProcessorUpgrade upgrade) // TEST: NO
{
    // COMMON_LT((" | upgrade = %u", upgrade)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", upgrade, enumToString(upgrade));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORUPGRADE_H
