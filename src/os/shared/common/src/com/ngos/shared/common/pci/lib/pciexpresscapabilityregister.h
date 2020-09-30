#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCAPABILITYREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdeviceporttype.h>



struct PciExpressCapabilityRegister
{
    union
    {
        struct
        {
            u16 capabilityVersion      : 4;
            u16 devicePortType         : 4; // TODO: Use enum PciExpressDevicePortType
            u16 slotImplemented        : 1;
            u16 interruptMessageNumber : 5;
            u16 undefined              : 1;
            u16 __reserved             : 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCAPABILITYREGISTER_H
