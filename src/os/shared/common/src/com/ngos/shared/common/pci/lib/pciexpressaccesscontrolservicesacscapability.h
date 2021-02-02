#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H



#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportarbitrationselect.h>



struct PciExpressAccessControlServicesAcsCapability
{
    bad_uint16 egressControlVectorSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return egressControlVectorSize == 0 ? 256 : egressControlVectorSize;
    }

    bad_uint16 egressControlVectorSizeNumberOfWords()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return DIV_UP(egressControlVectorSizeReal(), sizeof(bad_uint32) * 8);
    }



    union
    {
        struct
        {
            bad_uint16 acsSourceValidation      : 1;
            bad_uint16 acsTranslationBlocking   : 1;
            bad_uint16 acsP2pRequestRedirect    : 1;
            bad_uint16 acsP2pCompletionRedirect : 1;
            bad_uint16 acsUpstreamForwarding    : 1;
            bad_uint16 acsP2pEgressControl      : 1;
            bad_uint16 acsDirectTranslatedP2p   : 1;
            bad_uint16 __reserved               : 1;
            bad_uint16 egressControlVectorSize  : 8;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H
