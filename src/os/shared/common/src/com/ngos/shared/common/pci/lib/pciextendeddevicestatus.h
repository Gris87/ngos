#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicecomplexity.h>



struct PciExtendedDeviceStatus
{
    bad_uint16 designedMaximumMemoryReadByteCountReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 512ULL << designedMaximumMemoryReadByteCount;
    }

    bad_uint8 designedMaximumOutstandingSplitTransactionsReal()
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

    bad_uint16 designedMaximumCumulativeReadSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return 8ULL << designedMaximumCumulativeReadSize;
    }



    union
    {
        struct
        {
            bad_uint32 functionNumber:                              3;
            bad_uint32 deviceNumber:                                5;
            bad_uint32 busNumber:                                   8;
            bad_uint32 is64BitDevice:                               1;
            bad_uint32 support133MHz:                               1;
            bad_uint32 splitCompletionDiscarded:                    1;
            bad_uint32 unexpectedSplitCompletion:                   1;
            bad_uint32 deviceComplexity:                            1; // TODO: Use enum PciExtendedDeviceComplexity
            bad_uint32 designedMaximumMemoryReadByteCount:          2;
            bad_uint32 designedMaximumOutstandingSplitTransactions: 3;
            bad_uint32 designedMaximumCumulativeReadSize:           3;
            bad_uint32 receivedSplitCompletionErrorMessage:         1;
            bad_uint32 __reserved:                                  2;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H
