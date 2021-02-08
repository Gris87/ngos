#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGMAXNOSNOOPLATENCYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGMAXNOSNOOPLATENCYREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpresslatencytolerancereportinglatencyscale.h>



struct PciExpressLatencyToleranceReportingMaxNoSnoopLatencyRegister
{
    union
    {
        struct
        {
            u16 latencyValue : 10;
            u16 latencyScale : 3; // TODO: Use enum PciExpressLatencyToleranceReportingLatencyScale
            u16 __reserved   : 3;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGMAXNOSNOOPLATENCYREGISTER_H
