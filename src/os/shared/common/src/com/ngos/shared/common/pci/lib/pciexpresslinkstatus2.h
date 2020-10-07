#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdeemphasis.h>



struct PciExpressLinkStatus2
{
    union
    {
        struct
        {
            u16 currentDeemphasisLevel       : 1; // TODO: Use enum PciExpressDeemphasis
            u16 equalizationComplete         : 1;
            u16 equalizationPhase1Successful : 1;
            u16 equalizationPhase2Successful : 1;
            u16 equalizationPhase3Successful : 1;
            u16 linkEqualizationRequest      : 1;
            u16 __reserved                   : 10;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS2_H
