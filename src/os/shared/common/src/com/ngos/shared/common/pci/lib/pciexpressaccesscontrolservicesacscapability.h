#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H



#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportarbitrationselect.h>



struct PciExpressAccessControlServicesAcsCapability
{
    u16 egressControlVectorSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return egressControlVectorSize == 0 ? 256 : egressControlVectorSize;
    }

    u16 egressControlVectorSizeNumberOfWords()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return DIV_UP(egressControlVectorSizeReal(), sizeof(u32) * 8);
    }



    union
    {
        struct
        {
            u16 acsSourceValidation      : 1;
            u16 acsTranslationBlocking   : 1;
            u16 acsP2pRequestRedirect    : 1;
            u16 acsP2pCompletionRedirect : 1;
            u16 acsUpstreamForwarding    : 1;
            u16 acsP2pEgressControl      : 1;
            u16 acsDirectTranslatedP2p   : 1;
            u16 __reserved               : 1;
            u16 egressControlVectorSize  : 8;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H
