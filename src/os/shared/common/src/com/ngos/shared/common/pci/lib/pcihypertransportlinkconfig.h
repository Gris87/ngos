#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONFIG_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONFIG_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkwidth.h>



struct PciHyperTransportLinkConfig
{
    union
    {
        struct
        {
            u16 maximumLinkWidthIn:             3; // TODO: Use enum PciHyperTransportLinkWidth
            u16 doublewordFlowControlIn:        1;
            u16 maximumLinkWidthOut:            3; // TODO: Use enum PciHyperTransportLinkWidth
            u16 doublewordFlowControlOut:       1;
            u16 linkWidthIn:                    3; // TODO: Use enum PciHyperTransportLinkWidth
            u16 enableDoublewordFlowControlIn:  1;
            u16 linkWidthOut:                   3; // TODO: Use enum PciHyperTransportLinkWidth
            u16 enableDoublewordFlowControlOut: 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONFIG_H
