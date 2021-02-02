#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIBRIDGECONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIBRIDGECONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcibridgecontrolflags.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>



struct PciBridgeControlRegister
{
    bad_uint32                   baseAddressRegisters[2];
    bad_uint8                    primaryBus;
    bad_uint8                    secondaryBus;
    bad_uint8                    subordinateBus;
    bad_uint8                    secondaryLatencyTimer;
    bad_uint8                    ioBase;
    bad_uint8                    ioLimit;
    PciStatus             secondaryStatus;
    bad_uint16                   memoryBase;
    bad_uint16                   memoryLimit;
    bad_uint16                   prefetchableMemoryBase;
    bad_uint16                   prefetchableMemoryLimit;
    bad_uint32                   prefetchableBaseUpper32;
    bad_uint32                   prefetchableLimitUpper32;
    bad_uint16                   ioBaseUpper16;
    bad_uint16                   ioLimitUpper16;
    bad_uint8                    capabilitiesPointer;
    bad_uint8                    __reserved[3];
    bad_uint32                   expansionRomBaseAddress;
    bad_uint8                    interruptLine;
    bad_uint8                    interruptPin;
    PciBridgeControlFlags bridgeControl;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIBRIDGECONTROLREGISTER_H
