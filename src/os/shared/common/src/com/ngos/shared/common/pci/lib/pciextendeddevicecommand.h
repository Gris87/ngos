#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExtendedDeviceCommand
{
    bad_uint16 maximumMemoryReadByteCountReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 512ULL << maximumMemoryReadByteCount;
    }

    bad_uint8 maximumOutstandingSplitTransactionsReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        if (maximumOutstandingSplitTransactions >= 7)
        {
            return 32;
        }

        if (maximumOutstandingSplitTransactions >= 4)
        {
            return 8 + (maximumOutstandingSplitTransactions - 4) * 4;
        }

        return maximumOutstandingSplitTransactions + 1;
    }



    union
    {
        struct
        {
            bad_uint16 enableDataParityErrorRecovery:       1;
            bad_uint16 enableRelaxedOrdering:               1;
            bad_uint16 maximumMemoryReadByteCount:          2;
            bad_uint16 maximumOutstandingSplitTransactions: 3;
            bad_uint16 __reserved:                          9;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H
