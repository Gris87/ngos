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
            bad_uint16 capabilityVersion      : 4;
            bad_uint16 devicePortType         : 4; // TODO: Use enum PciExpressDevicePortType
            bad_uint16 slotImplemented        : 1;
            bad_uint16 interruptMessageNumber : 5;
            bad_uint16 undefined              : 1;
            bad_uint16 __reserved             : 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCAPABILITYREGISTER_H
