#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



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
    IORISER_CARD_SLOT                    = 0x0C,
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
    MXM_30_TYPE_A                        = 0x1D,
    MXM_30_TYPE_B                        = 0x1E,
    PCI_EXPRESS_GEN_2_SFF_8639           = 0x1F,
    PCI_EXPRESS_GEN_3_SFF_8639           = 0x20,
    PCI_EXPRESS_MINI_52_PIN_WITH_BSKO    = 0x21,
    PCI_EXPRESS_MINI_52_PIN_WITHOUT_BSKO = 0x22,
    PCI_EXPRESS_MINI_76_PIN              = 0x23,
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
    PCI_EXPRESS_GEN_3_X16                = 0xB6
};



inline const char8* enumToString(DmiSystemSlotsType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiSystemSlotsType::NONE:              return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSTYPE_H
