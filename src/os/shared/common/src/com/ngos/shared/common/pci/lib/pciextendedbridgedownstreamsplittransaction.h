#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGEDOWNSTREAMSPLITTRANSACTION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGEDOWNSTREAMSPLITTRANSACTION_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExtendedBridgeDownstreamSplitTransaction
{
    bad_uint16 splitTransactionCommitmentLimit;
    bad_uint16 splitTransactionCapacity;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGEDOWNSTREAMSPLITTRANSACTION_H
