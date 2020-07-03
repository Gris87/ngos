#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSTYPE_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiSystemSlotsType: u8
{
    NONE                                 = 0,
    OTHER                                = 0x01,
    UNKNOWN                              = 0x02,
    ISA                                  = 0x03,
    MCA                                  = 0x04,
    EISA                                 = 0x05,
    PCI                                  = 0x06,
    PCMCIA                               = 0x07,
    VL_VESA                              = 0x08,
    PROPRIETARY                          = 0x09,
    PROCESSOR_CARD_SLOT                  = 0x0A,
    PROPRIETARY_MEMORY_CARD_SLOT         = 0x0B,
    IO_RISER_CARD_SLOT                   = 0x0C,
    NU_BUS                               = 0x0D,
    PCI_66_MHZ_CAPABLE                   = 0x0E,
    AGP                                  = 0x0F,
    APG_2X                               = 0x10,
    AGP_4X                               = 0x11,
    PCI_X                                = 0x12,
    AGP_8X                               = 0x13,
    M2_SOCKET_1_DP                       = 0x14,
    M2_SOCKET_1_SD                       = 0x15,
    M2_SOCKET_2                          = 0x16,
    M2_SOCKET_3                          = 0x17,
    MXM_TYPE_I                           = 0x18,
    MXM_TYPE_II                          = 0x19,
    MXM_TYPE_III_STANDARD                = 0x1A,
    MXM_TYPE_III_HE                      = 0x1B,
    MXM_TYPE_IV                          = 0x1C,
    MXM_3_0_TYPE_A                       = 0x1D,
    MXM_3_0_TYPE_B                       = 0x1E,
    PCI_EXPRESS_GEN_2_SFF_8639           = 0x1F,
    PCI_EXPRESS_GEN_3_SFF_8639           = 0x20,
    PCI_EXPRESS_MINI_52_PIN_WITH_BSKO    = 0x21,
    PCI_EXPRESS_MINI_52_PIN_WITHOUT_BSKO = 0x22,
    PCI_EXPRESS_MINI_76_PIN              = 0x23,
    CXL_FLEXBUS_1_0                      = 0x30,
    PC_98_C20                            = 0xA0,
    PC_98_C24                            = 0xA1,
    PC_98_E                              = 0xA2,
    PC_98_LOCAL_BUS                      = 0xA3,
    PC_98_CARD                           = 0xA4,
    PCI_EXPRESS                          = 0xA5,
    PCI_EXPRESS_X1                       = 0xA6,
    PCI_EXPRESS_X2                       = 0xA7,
    PCI_EXPRESS_X4                       = 0xA8,
    PCI_EXPRESS_X8                       = 0xA9,
    PCI_EXPRESS_X16                      = 0xAA,
    PCI_EXPRESS_GEN_2                    = 0xAB,
    PCI_EXPRESS_GEN_2_X1                 = 0xAC,
    PCI_EXPRESS_GEN_2_X2                 = 0xAD,
    PCI_EXPRESS_GEN_2_X4                 = 0xAE,
    PCI_EXPRESS_GEN_2_X8                 = 0xAF,
    PCI_EXPRESS_GEN_2_X16                = 0xB0,
    PCI_EXPRESS_GEN_3                    = 0xB1,
    PCI_EXPRESS_GEN_3_X1                 = 0xB2,
    PCI_EXPRESS_GEN_3_X2                 = 0xB3,
    PCI_EXPRESS_GEN_3_X4                 = 0xB4,
    PCI_EXPRESS_GEN_3_X8                 = 0xB5,
    PCI_EXPRESS_GEN_3_X16                = 0xB6,
    PCI_EXPRESS_GEN_4                    = 0xB8,
    PCI_EXPRESS_GEN_4_X1                 = 0xB9,
    PCI_EXPRESS_GEN_4_X2                 = 0xBA,
    PCI_EXPRESS_GEN_4_X4                 = 0xBB,
    PCI_EXPRESS_GEN_4_X8                 = 0xBC,
    PCI_EXPRESS_GEN_4_X16                = 0xBD
};



inline const char8* enumToString(DmiSystemSlotsType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiSystemSlotsType::NONE:                                 return "NONE";
        case DmiSystemSlotsType::OTHER:                                return "OTHER";
        case DmiSystemSlotsType::UNKNOWN:                              return "UNKNOWN";
        case DmiSystemSlotsType::ISA:                                  return "ISA";
        case DmiSystemSlotsType::MCA:                                  return "MCA";
        case DmiSystemSlotsType::EISA:                                 return "EISA";
        case DmiSystemSlotsType::PCI:                                  return "PCI";
        case DmiSystemSlotsType::PCMCIA:                               return "PCMCIA";
        case DmiSystemSlotsType::VL_VESA:                              return "VL_VESA";
        case DmiSystemSlotsType::PROPRIETARY:                          return "PROPRIETARY";
        case DmiSystemSlotsType::PROCESSOR_CARD_SLOT:                  return "PROCESSOR_CARD_SLOT";
        case DmiSystemSlotsType::PROPRIETARY_MEMORY_CARD_SLOT:         return "PROPRIETARY_MEMORY_CARD_SLOT";
        case DmiSystemSlotsType::IO_RISER_CARD_SLOT:                   return "IO_RISER_CARD_SLOT";
        case DmiSystemSlotsType::NU_BUS:                               return "NU_BUS";
        case DmiSystemSlotsType::PCI_66_MHZ_CAPABLE:                   return "PCI_66_MHZ_CAPABLE";
        case DmiSystemSlotsType::AGP:                                  return "AGP";
        case DmiSystemSlotsType::APG_2X:                               return "APG_2X";
        case DmiSystemSlotsType::AGP_4X:                               return "AGP_4X";
        case DmiSystemSlotsType::PCI_X:                                return "PCI_X";
        case DmiSystemSlotsType::AGP_8X:                               return "AGP_8X";
        case DmiSystemSlotsType::M2_SOCKET_1_DP:                       return "M2_SOCKET_1_DP";
        case DmiSystemSlotsType::M2_SOCKET_1_SD:                       return "M2_SOCKET_1_SD";
        case DmiSystemSlotsType::M2_SOCKET_2:                          return "M2_SOCKET_2";
        case DmiSystemSlotsType::M2_SOCKET_3:                          return "M2_SOCKET_3";
        case DmiSystemSlotsType::MXM_TYPE_I:                           return "MXM_TYPE_I";
        case DmiSystemSlotsType::MXM_TYPE_II:                          return "MXM_TYPE_II";
        case DmiSystemSlotsType::MXM_TYPE_III_STANDARD:                return "MXM_TYPE_III_STANDARD";
        case DmiSystemSlotsType::MXM_TYPE_III_HE:                      return "MXM_TYPE_III_HE";
        case DmiSystemSlotsType::MXM_TYPE_IV:                          return "MXM_TYPE_IV";
        case DmiSystemSlotsType::MXM_3_0_TYPE_A:                       return "MXM_3_0_TYPE_A";
        case DmiSystemSlotsType::MXM_3_0_TYPE_B:                       return "MXM_3_0_TYPE_B";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_SFF_8639:           return "PCI_EXPRESS_GEN_2_SFF_8639";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_SFF_8639:           return "PCI_EXPRESS_GEN_3_SFF_8639";
        case DmiSystemSlotsType::PCI_EXPRESS_MINI_52_PIN_WITH_BSKO:    return "PCI_EXPRESS_MINI_52_PIN_WITH_BSKO";
        case DmiSystemSlotsType::PCI_EXPRESS_MINI_52_PIN_WITHOUT_BSKO: return "PCI_EXPRESS_MINI_52_PIN_WITHOUT_BSKO";
        case DmiSystemSlotsType::PCI_EXPRESS_MINI_76_PIN:              return "PCI_EXPRESS_MINI_76_PIN";
        case DmiSystemSlotsType::CXL_FLEXBUS_1_0:                      return "CXL_FLEXBUS_1_0";
        case DmiSystemSlotsType::PC_98_C20:                            return "PC_98_C20";
        case DmiSystemSlotsType::PC_98_C24:                            return "PC_98_C24";
        case DmiSystemSlotsType::PC_98_E:                              return "PC_98_E";
        case DmiSystemSlotsType::PC_98_LOCAL_BUS:                      return "PC_98_LOCAL_BUS";
        case DmiSystemSlotsType::PC_98_CARD:                           return "PC_98_CARD";
        case DmiSystemSlotsType::PCI_EXPRESS:                          return "PCI_EXPRESS";
        case DmiSystemSlotsType::PCI_EXPRESS_X1:                       return "PCI_EXPRESS_X1";
        case DmiSystemSlotsType::PCI_EXPRESS_X2:                       return "PCI_EXPRESS_X2";
        case DmiSystemSlotsType::PCI_EXPRESS_X4:                       return "PCI_EXPRESS_X4";
        case DmiSystemSlotsType::PCI_EXPRESS_X8:                       return "PCI_EXPRESS_X8";
        case DmiSystemSlotsType::PCI_EXPRESS_X16:                      return "PCI_EXPRESS_X16";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2:                    return "PCI_EXPRESS_GEN_2";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X1:                 return "PCI_EXPRESS_GEN_2_X1";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X2:                 return "PCI_EXPRESS_GEN_2_X2";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X4:                 return "PCI_EXPRESS_GEN_2_X4";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X8:                 return "PCI_EXPRESS_GEN_2_X8";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_2_X16:                return "PCI_EXPRESS_GEN_2_X16";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3:                    return "PCI_EXPRESS_GEN_3";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X1:                 return "PCI_EXPRESS_GEN_3_X1";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X2:                 return "PCI_EXPRESS_GEN_3_X2";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X4:                 return "PCI_EXPRESS_GEN_3_X4";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X8:                 return "PCI_EXPRESS_GEN_3_X8";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_3_X16:                return "PCI_EXPRESS_GEN_3_X16";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4:                    return "PCI_EXPRESS_GEN_4";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X1:                 return "PCI_EXPRESS_GEN_4_X1";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X2:                 return "PCI_EXPRESS_GEN_4_X2";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X4:                 return "PCI_EXPRESS_GEN_4_X4";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X8:                 return "PCI_EXPRESS_GEN_4_X8";
        case DmiSystemSlotsType::PCI_EXPRESS_GEN_4_X16:                return "PCI_EXPRESS_GEN_4_X16";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[44];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSTYPE_H
