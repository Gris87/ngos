#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGMAXNOSNOOPLATENCYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGMAXNOSNOOPLATENCYREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpresslatencytolerancereportinglatencyscale.h>



struct PciExpressLatencyToleranceReportingMaxNoSnoopLatencyRegister
{
    union
    {
        struct
        {
            bad_uint16 latencyValue : 10;
            bad_uint16 latencyScale : 3; // TODO: Use enum PciExpressLatencyToleranceReportingLatencyScale
            bad_uint16 __reserved   : 3;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLATENCYTOLERANCEREPORTINGMAXNOSNOOPLATENCYREGISTER_H
