#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicecomplexity.h>



struct PciExtendedDeviceStatus
{
    u16 designedMaximumMemoryReadByteCountReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 512ULL << designedMaximumMemoryReadByteCount;
    }

    u8 designedMaximumOutstandingSplitTransactionsReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        if (designedMaximumOutstandingSplitTransactions >= 7)
        {
            return 32;
        }

        if (designedMaximumOutstandingSplitTransactions >= 4)
        {
            return 8 + (designedMaximumOutstandingSplitTransactions - 4) * 4;
        }

        return designedMaximumOutstandingSplitTransactions + 1;
    }

    u16 designedMaximumCumulativeReadSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 8ULL << designedMaximumCumulativeReadSize;
    }



    union
    {
        struct
        {
            u32 functionNumber:                              3;
            u32 deviceNumber:                                5;
            u32 busNumber:                                   8;
            u32 is64BitDevice:                               1;
            u32 support133MHz:                               1;
            u32 splitCompletionDiscarded:                    1;
            u32 unexpectedSplitCompletion:                   1;
            u32 deviceComplexity:                            1; // TODO: Use enum PciExtendedDeviceComplexity
            u32 designedMaximumMemoryReadByteCount:          2;
            u32 designedMaximumOutstandingSplitTransactions: 3;
            u32 designedMaximumCumulativeReadSize:           3;
            u32 receivedSplitCompletionErrorMessage:         1;
            u32 __reserved:                                  2;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H
