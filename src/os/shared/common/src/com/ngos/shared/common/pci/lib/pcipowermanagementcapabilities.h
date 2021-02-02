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
            bad_uint16 version:                      3;
            bad_uint16 pmeClock:                     1;
            bad_uint16 __reserved:                   1;
            bad_uint16 deviceSpecificInitialization: 1;
            bad_uint16 auxCurrent:                   3; // TODO: Use enum PciPowerManagementAuxCurrent
            bad_uint16 supportD1:                    1;
            bad_uint16 supportD2:                    1;
            bad_uint16 supportPme:                   5; // TODO: Use flags PciPowerManagementSupportPmeFlags
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCAPABILITIES_H
