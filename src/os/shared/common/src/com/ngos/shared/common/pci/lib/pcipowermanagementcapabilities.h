#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCAPABILITIES_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCAPABILITIES_H



#include <com/ngos/shared/common/pci/lib/pcipowermanagementauxcurrent.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementsupportpmeflags.h>



struct PciPowerManagementCapabilities
{
    union
    {
        struct
        {
            u16 version:                      3;
            u16 pmeClock:                     1;
            u16 __reserved:                   1;
            u16 deviceSpecificInitialization: 1;
            u16 auxCurrent:                   3; // TODO: Use enum PciPowerManagementAuxCurrent
            u16 supportD1:                    1;
            u16 supportD2:                    1;
            u16 supportPme:                   5; // TODO: Use flags PciPowerManagementSupportPmeFlags
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCAPABILITIES_H
