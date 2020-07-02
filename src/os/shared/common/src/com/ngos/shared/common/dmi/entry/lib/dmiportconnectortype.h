#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTCONNECTORTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTCONNECTORTYPE_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiPortConnectorType: u8
{
    NONE                    = 0,
    CENTRONICS              = 0x01,
    MINI_CENTRONICS         = 0x02,
    PROPRIETARY             = 0x03,
    DB25_MALE               = 0x04,
    DB25_FEMALE             = 0x05,
    DB15_MALE               = 0x06,
    DB15_FEMALE             = 0x07,
    DB9_MALE                = 0x08,
    DB9_FEMALE              = 0x09,
    RJ11                    = 0x0A,
    RJ45                    = 0x0B,
    _50_PIN_MINI_SCSI       = 0x0C,
    MINI_DIN                = 0x0D,
    MICRO_DIN               = 0x0E,
    PS2                     = 0x0F,
    INFRARED                = 0x10,
    HP_HIL                  = 0x11,
    USB                     = 0x12,
    SSA_SCSI                = 0x13,
    CIRCULAR_DIN_8_MALE     = 0x14,
    CIRCULAR_DIN_8_FEMALE   = 0x15,
    ONBOARD_IDE             = 0x16,
    ONBOARD_FLOPPY          = 0x17,
    _9_PIN_DUAL_INLINE      = 0x18,
    _25_PIN_DUAL_INLINE     = 0x19,
    _50_PIN_DUAL_INLINE     = 0x1A,
    _68_PIN_DUAL_INLINE     = 0x1B,
    ONBOARD_SOUND_INPUT     = 0x1C,
    MINI_CENTRONICS_TYPE_14 = 0x1D,
    MINI_CENTRONICS_TYPE_26 = 0x1E,
    HEADPHONE_MINI_JACK     = 0x1F,
    BNC                     = 0x20,
    IEEE_1394               = 0x21,
    SAS_SATA                = 0x22,
    USB_TYPE_C              = 0x23,
    PC98                    = 0xA0,
    PC98_HI_RESO            = 0xA1,
    PCH98                   = 0xA2,
    PC98_NOTE               = 0xA3,
    PC98_FULL               = 0xA4,
    OTHER                   = 0xFF
};



inline const char8* enumToString(DmiPortConnectorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiPortConnectorType::NONE:                    return "NONE";
        case DmiPortConnectorType::CENTRONICS:              return "CENTRONICS";
        case DmiPortConnectorType::MINI_CENTRONICS:         return "MINI_CENTRONICS";
        case DmiPortConnectorType::PROPRIETARY:             return "PROPRIETARY";
        case DmiPortConnectorType::DB25_MALE:               return "DB25_MALE";
        case DmiPortConnectorType::DB25_FEMALE:             return "DB25_FEMALE";
        case DmiPortConnectorType::DB15_MALE:               return "DB15_MALE";
        case DmiPortConnectorType::DB15_FEMALE:             return "DB15_FEMALE";
        case DmiPortConnectorType::DB9_MALE:                return "DB9_MALE";
        case DmiPortConnectorType::DB9_FEMALE:              return "DB9_FEMALE";
        case DmiPortConnectorType::RJ11:                    return "RJ11";
        case DmiPortConnectorType::RJ45:                    return "RJ45";
        case DmiPortConnectorType::_50_PIN_MINI_SCSI:       return "_50_PIN_MINI_SCSI";
        case DmiPortConnectorType::MINI_DIN:                return "MINI_DIN";
        case DmiPortConnectorType::MICRO_DIN:               return "MICRO_DIN";
        case DmiPortConnectorType::PS2:                     return "PS2";
        case DmiPortConnectorType::INFRARED:                return "INFRARED";
        case DmiPortConnectorType::HP_HIL:                  return "HP_HIL";
        case DmiPortConnectorType::USB:                     return "USB";
        case DmiPortConnectorType::SSA_SCSI:                return "SSA_SCSI";
        case DmiPortConnectorType::CIRCULAR_DIN_8_MALE:     return "CIRCULAR_DIN_8_MALE";
        case DmiPortConnectorType::CIRCULAR_DIN_8_FEMALE:   return "CIRCULAR_DIN_8_FEMALE";
        case DmiPortConnectorType::ONBOARD_IDE:             return "ONBOARD_IDE";
        case DmiPortConnectorType::ONBOARD_FLOPPY:          return "ONBOARD_FLOPPY";
        case DmiPortConnectorType::_9_PIN_DUAL_INLINE:      return "_9_PIN_DUAL_INLINE";
        case DmiPortConnectorType::_25_PIN_DUAL_INLINE:     return "_25_PIN_DUAL_INLINE";
        case DmiPortConnectorType::_50_PIN_DUAL_INLINE:     return "_50_PIN_DUAL_INLINE";
        case DmiPortConnectorType::_68_PIN_DUAL_INLINE:     return "_68_PIN_DUAL_INLINE";
        case DmiPortConnectorType::ONBOARD_SOUND_INPUT:     return "ONBOARD_SOUND_INPUT";
        case DmiPortConnectorType::MINI_CENTRONICS_TYPE_14: return "MINI_CENTRONICS_TYPE_14";
        case DmiPortConnectorType::MINI_CENTRONICS_TYPE_26: return "MINI_CENTRONICS_TYPE_26";
        case DmiPortConnectorType::HEADPHONE_MINI_JACK:     return "HEADPHONE_MINI_JACK";
        case DmiPortConnectorType::BNC:                     return "BNC";
        case DmiPortConnectorType::IEEE_1394:               return "IEEE_1394";
        case DmiPortConnectorType::SAS_SATA:                return "SAS_SATA";
        case DmiPortConnectorType::USB_TYPE_C:              return "USB_TYPE_C";
        case DmiPortConnectorType::PC98:                    return "PC98";
        case DmiPortConnectorType::PC98_HI_RESO:            return "PC98_HI_RESO";
        case DmiPortConnectorType::PCH98:                   return "PCH98";
        case DmiPortConnectorType::PC98_NOTE:               return "PC98_NOTE";
        case DmiPortConnectorType::PC98_FULL:               return "PC98_FULL";
        case DmiPortConnectorType::OTHER:                   return "OTHER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiPortConnectorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[31];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTCONNECTORTYPE_H
