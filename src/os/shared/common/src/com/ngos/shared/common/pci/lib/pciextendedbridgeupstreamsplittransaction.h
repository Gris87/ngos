#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGEUPSTREAMSPLITTRANSACTION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGEUPSTREAMSPLITTRANSACTION_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExtendedBridgeUpstreamSplitTransaction
{
    bad_uint16 splitTransactionCommitmentLimit;
    bad_uint16 splitTransactionCapacity;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGEUPSTREAMSPLITTRANSACTION_H
