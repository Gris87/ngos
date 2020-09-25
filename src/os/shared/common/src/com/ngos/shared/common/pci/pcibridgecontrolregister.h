#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIBRIDGECONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIBRIDGECONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcibridgecontrolflags.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>



struct PciBridgeControlRegister
{
    u32                   baseAddressRegisters[2];
    u8                    primaryBus;
    u8                    secondaryBus;
    u8                    subordinateBus;
    u8                    secondaryLatencyTimer;
    u8                    ioBase;
    u8                    ioLimit;
    PciStatus             secondaryStatus;
    u16                   memoryBase;
    u16                   memoryLimit;
    u16                   prefetchableMemoryBase;
    u16                   prefetchableMemoryLimit;
    u32                   prefetchableBaseUpper32;
    u32                   prefetchableLimitUpper32;
    u16                   ioBaseUpper16;
    u16                   ioLimitUpper16;
    u8                    capabilitiesPointer;
    u8                    __reserved[3];
    u32                   expansionRomBaseAddress;
    u8                    interruptLine;
    u8                    interruptPin;
    PciBridgeControlFlags bridgeControl;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIBRIDGECONTROLREGISTER_H
