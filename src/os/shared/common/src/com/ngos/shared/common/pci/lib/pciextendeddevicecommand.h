#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExtendedDeviceCommand
{
    u16 maximumMemoryReadByteCountReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 512ULL << maximumMemoryReadByteCount;
    }

    u8 maximumOutstandingSplitTransactionsReal()
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
            u16 enableDataParityErrorRecovery:       1;
            u16 enableRelaxedOrdering:               1;
            u16 maximumMemoryReadByteCount:          2;
            u16 maximumOutstandingSplitTransactions: 3;
            u16 __reserved:                          9;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H
