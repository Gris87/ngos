#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddressbarsize.h>



struct PciExpressResizableBaseAddressControl
{
    bad_uint8 barOffset()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 16 + barIndex * 4;
    }



    union
    {
        struct
        {
            bad_uint32 barIndex              : 3;
            bad_uint32 __reserved            : 2;
            bad_uint32 numberOfResizableBars : 3;
            bad_uint32 barSize               : 5; // TODO: Use enum PciExpressResizableBaseAddressBarSize
            bad_uint32 __reserved2           : 19;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H
