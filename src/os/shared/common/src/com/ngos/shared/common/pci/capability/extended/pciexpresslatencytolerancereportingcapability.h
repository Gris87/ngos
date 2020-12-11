#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSLATENCYTOLERANCEREPORTINGCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSLATENCYTOLERANCEREPORTINGCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpresslatencytolerancereportingmaxnosnooplatencyregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslatencytolerancereportingmaxsnooplatencyregister.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressLatencyToleranceReportingCapability
{
    PciExtendedCapabilityHeader                                  header;
    PciExpressLatencyToleranceReportingMaxSnoopLatencyRegister   maxSnoopLatency;
    PciExpressLatencyToleranceReportingMaxNoSnoopLatencyRegister maxNoSnoopLatency;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSLATENCYTOLERANCEREPORTINGCAPABILITY_H
