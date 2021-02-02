#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciHyperTransportLinkControl
{
    union
    {
        struct
        {
            bad_uint16 enableSourceId:               1;
            bad_uint16 enableCrcFlood:               1;
            bad_uint16 crcStartTest:                 1;
            bad_uint16 crcForceError:                1;
            bad_uint16 linkFailure:                  1;
            bad_uint16 initializationComplete:       1;
            bad_uint16 endOfChain:                   1;
            bad_uint16 transmitterOff:               1;
            bad_uint16 crcError:                     4;
            bad_uint16 enableIsochronousFlowControl: 1;
            bad_uint16 enableLdtStopTristate:        1;
            bad_uint16 extendedCtlTime:              1;
            bad_uint16 enable64BitAddressing:        1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONTROL_H
