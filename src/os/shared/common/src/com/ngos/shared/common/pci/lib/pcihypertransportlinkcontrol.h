#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciHyperTransportLinkControl
{
    union
    {
        struct
        {
            u16 enableSourceID:               1;
            u16 enableCrcFlood:               1;
            u16 crcStartTest:                 1;
            u16 crcForceError:                1;
            u16 linkFailure:                  1;
            u16 initializationComplete:       1;
            u16 endOfChain:                   1;
            u16 transmitterOff:               1;
            u16 crcError:                     4;
            u16 enableIsochronousFlowControl: 1;
            u16 enableLdtStopTristate:        1;
            u16 extendedCtlTime:              1;
            u16 enable64BitAddressing:        1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONTROL_H
