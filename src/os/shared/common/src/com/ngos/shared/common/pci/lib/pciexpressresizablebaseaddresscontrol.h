#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddressbarsize.h>



struct PciExpressResizableBaseAddressControl
{
    u8 barOffset()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 16 + barIndex * 4;
    }



    union
    {
        struct
        {
            u32 barIndex              : 3;
            u32 __reserved            : 2;
            u32 numberOfResizableBars : 3;
            u32 barSize               : 5; // TODO: Use enum PciExpressResizableBaseAddressBarSize
            u32 __reserved2           : 19;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H
