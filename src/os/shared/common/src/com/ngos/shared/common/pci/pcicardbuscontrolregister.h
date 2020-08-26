#ifndef COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSCONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>



struct PciCardBusControlRegister
{
    u32       cardBusSocket;
    u8        capabilitiesPointer;
    u8        __reserved;
    PciStatus secondaryStatus;
    u8        pciBusNumber;
    u8        cardBusBusNumber;
    u8        subordinateBusNumber;
    u8        cardBusLatencyTimer;
    u32       memoryBase0;
    u32       memoryLimit0;
    u32       memoryBase1;
    u32       memoryLimit1;
    u32       ioBase0;
    u32       ioLimit0;
    u32       ioBase1;
    u32       ioLimit1;
    u8        interruptLine;
    u8        interruptPin;
    u16       bridgeControl;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSCONTROLREGISTER_H
