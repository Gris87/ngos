#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTCONNECTORPORTTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTCONNECTORPORTTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiPortConnectorPortType: u8
{
    NONE                        = 0,
    PARALLEL_XT_AT_COMPATIBLE   = 0x01,
    PARALLEL_PS2                = 0x02,
    PARALLEL_ECP                = 0x03,
    PARALLEL_EPP                = 0x04,
    PARALLEL_ECP_EPP            = 0x05,
    SERIAL_XT_AT_COMPATIBLE     = 0x06,
    SERIAL_16450_COMPATIBLE     = 0x07,
    SERIAL_16550_COMPATIBLE     = 0x08,
    SERIAL_16550A_COMPATIBLE    = 0x09,
    SCSI                        = 0x0A,
    MIDI                        = 0x0B,
    JOYSTICK                    = 0x0C,
    KEYBOARD                    = 0x0D,
    MOUSE                       = 0x0E,
    SSA_SCSI                    = 0x0F,
    USB                         = 0x10,
    FIREWIRE                    = 0x11,
    PCMCIA_TYPE_I               = 0x12,
    PCMCIA_TYPE_II              = 0x13,
    PCMCIA_TYPE_III             = 0x14,
    CARD_BUS                    = 0x15,
    ACCESS_BUS_PORT             = 0x16,
    SCSI_II                     = 0x17,
    SCSI_WIDE                   = 0x18,
    PC98                        = 0x19,
    PC98_HIRESO                 = 0x1A,
    PCH98                       = 0x1B,
    VIDEO_PORT                  = 0x1C,
    AUDIO_PORT                  = 0x1D,
    MODEM_PORT                  = 0x1E,
    NETWORK_PORT                = 0x1F,
    SATA                        = 0x20,
    SAS                         = 0x21,
    MULTI_FUNCTION_DISPLAY_PORT = 0x22,
    THUNDERBOLT                 = 0x23,
    _8251_COMPATIBLE            = 0xA0,
    _8251_FIFO_COMPATIBLE       = 0xA1,
    OTHER                       = 0xFF
};



inline const char8* enumToString(DmiPortConnectorPortType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiPortConnectorPortType::NONE:                        return "NONE";
        case DmiPortConnectorPortType::PARALLEL_XT_AT_COMPATIBLE:   return "PARALLEL_XT_AT_COMPATIBLE";
        case DmiPortConnectorPortType::PARALLEL_PS2:                return "PARALLEL_PS2";
        case DmiPortConnectorPortType::PARALLEL_ECP:                return "PARALLEL_ECP";
        case DmiPortConnectorPortType::PARALLEL_EPP:                return "PARALLEL_EPP";
        case DmiPortConnectorPortType::PARALLEL_ECP_EPP:            return "PARALLEL_ECP_EPP";
        case DmiPortConnectorPortType::SERIAL_XT_AT_COMPATIBLE:     return "SERIAL_XT_AT_COMPATIBLE";
        case DmiPortConnectorPortType::SERIAL_16450_COMPATIBLE:     return "SERIAL_16450_COMPATIBLE";
        case DmiPortConnectorPortType::SERIAL_16550_COMPATIBLE:     return "SERIAL_16550_COMPATIBLE";
        case DmiPortConnectorPortType::SERIAL_16550A_COMPATIBLE:    return "SERIAL_16550A_COMPATIBLE";
        case DmiPortConnectorPortType::SCSI:                        return "SCSI";
        case DmiPortConnectorPortType::MIDI:                        return "MIDI";
        case DmiPortConnectorPortType::JOYSTICK:                    return "JOYSTICK";
        case DmiPortConnectorPortType::KEYBOARD:                    return "KEYBOARD";
        case DmiPortConnectorPortType::MOUSE:                       return "MOUSE";
        case DmiPortConnectorPortType::SSA_SCSI:                    return "SSA_SCSI";
        case DmiPortConnectorPortType::USB:                         return "USB";
        case DmiPortConnectorPortType::FIREWIRE:                    return "FIREWIRE";
        case DmiPortConnectorPortType::PCMCIA_TYPE_I:               return "PCMCIA_TYPE_I";
        case DmiPortConnectorPortType::PCMCIA_TYPE_II:              return "PCMCIA_TYPE_II";
        case DmiPortConnectorPortType::PCMCIA_TYPE_III:             return "PCMCIA_TYPE_III";
        case DmiPortConnectorPortType::CARD_BUS:                    return "CARD_BUS";
        case DmiPortConnectorPortType::ACCESS_BUS_PORT:             return "ACCESS_BUS_PORT";
        case DmiPortConnectorPortType::SCSI_II:                     return "SCSI_II";
        case DmiPortConnectorPortType::SCSI_WIDE:                   return "SCSI_WIDE";
        case DmiPortConnectorPortType::PC98:                        return "PC98";
        case DmiPortConnectorPortType::PC98_HIRESO:                 return "PC98_HIRESO";
        case DmiPortConnectorPortType::PCH98:                       return "PCH98";
        case DmiPortConnectorPortType::VIDEO_PORT:                  return "VIDEO_PORT";
        case DmiPortConnectorPortType::AUDIO_PORT:                  return "AUDIO_PORT";
        case DmiPortConnectorPortType::MODEM_PORT:                  return "MODEM_PORT";
        case DmiPortConnectorPortType::NETWORK_PORT:                return "NETWORK_PORT";
        case DmiPortConnectorPortType::SATA:                        return "SATA";
        case DmiPortConnectorPortType::SAS:                         return "SAS";
        case DmiPortConnectorPortType::MULTI_FUNCTION_DISPLAY_PORT: return "MULTI_FUNCTION_DISPLAY_PORT";
        case DmiPortConnectorPortType::THUNDERBOLT:                 return "THUNDERBOLT";
        case DmiPortConnectorPortType::_8251_COMPATIBLE:            return "_8251_COMPATIBLE";
        case DmiPortConnectorPortType::_8251_FIFO_COMPATIBLE:       return "_8251_FIFO_COMPATIBLE";
        case DmiPortConnectorPortType::OTHER:                       return "OTHER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiPortConnectorPortType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTCONNECTORPORTTYPE_H
