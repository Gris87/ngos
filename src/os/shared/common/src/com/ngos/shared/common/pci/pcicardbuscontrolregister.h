#ifndef COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSCONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcicardbuscontrolflags.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>



struct PciCardBusControlRegister
{
    bad_uint32                    cardBusSocket;
    bad_uint8                     capabilitiesPointer;
    bad_uint8                     __reserved;
    PciStatus              secondaryStatus;
    bad_uint8                     pciBusNumber;
    bad_uint8                     cardBusBusNumber;
    bad_uint8                     subordinateBusNumber;
    bad_uint8                     cardBusLatencyTimer;
    bad_uint32                    memoryBase0;
    bad_uint32                    memoryLimit0;
    bad_uint32                    memoryBase1;
    bad_uint32                    memoryLimit1;
    bad_uint32                    ioBase0;
    bad_uint32                    ioLimit0;
    bad_uint32                    ioBase1;
    bad_uint32                    ioLimit1;
    bad_uint8                     interruptLine;
    bad_uint8                     interruptPin;
    PciCardBusControlFlags bridgeControl;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSCONTROLREGISTER_H
