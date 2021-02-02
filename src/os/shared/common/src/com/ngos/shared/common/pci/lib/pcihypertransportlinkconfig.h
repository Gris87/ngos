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
            bad_uint16 maximumLinkWidthIn:             3; // TODO: Use enum PciHyperTransportLinkWidth
            bad_uint16 doublewordFlowControlIn:        1;
            bad_uint16 maximumLinkWidthOut:            3; // TODO: Use enum PciHyperTransportLinkWidth
            bad_uint16 doublewordFlowControlOut:       1;
            bad_uint16 linkWidthIn:                    3; // TODO: Use enum PciHyperTransportLinkWidth
            bad_uint16 enableDoublewordFlowControlIn:  1;
            bad_uint16 linkWidthOut:                   3; // TODO: Use enum PciHyperTransportLinkWidth
            bad_uint16 enableDoublewordFlowControlOut: 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKCONFIG_H
