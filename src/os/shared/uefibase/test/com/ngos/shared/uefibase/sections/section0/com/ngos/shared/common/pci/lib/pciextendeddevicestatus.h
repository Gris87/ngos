#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicestatus.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciextendeddevicestatus);
{
    TEST_CASE("designedMaximumMemoryReadByteCountReal()");
    {
        PciExtendedDeviceStatus temp;



        temp.designedMaximumMemoryReadByteCount = 0;

        TEST_ASSERT_EQUALS(temp.designedMaximumMemoryReadByteCountReal(), 512);



        temp.designedMaximumMemoryReadByteCount = 1;

        TEST_ASSERT_EQUALS(temp.designedMaximumMemoryReadByteCountReal(), 1024);



        temp.designedMaximumMemoryReadByteCount = 2;

        TEST_ASSERT_EQUALS(temp.designedMaximumMemoryReadByteCountReal(), 2048);



        temp.designedMaximumMemoryReadByteCount = 3;

        TEST_ASSERT_EQUALS(temp.designedMaximumMemoryReadByteCountReal(), 4096);
    }
    TEST_CASE_END();



    TEST_CASE("designedMaximumOutstandingSplitTransactionsReal()");
    {
        PciExtendedDeviceStatus temp;



        temp.designedMaximumOutstandingSplitTransactions = 0;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 1);



        temp.designedMaximumOutstandingSplitTransactions = 1;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 2);



        temp.designedMaximumOutstandingSplitTransactions = 2;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 3);



        temp.designedMaximumOutstandingSplitTransactions = 3;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 4);



        temp.designedMaximumOutstandingSplitTransactions = 4;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 8);



        temp.designedMaximumOutstandingSplitTransactions = 5;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 12);



        temp.designedMaximumOutstandingSplitTransactions = 6;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 16);



        temp.designedMaximumOutstandingSplitTransactions = 7;

        TEST_ASSERT_EQUALS(temp.designedMaximumOutstandingSplitTransactionsReal(), 32);
    }
    TEST_CASE_END();



    TEST_CASE("designedMaximumCumulativeReadSizeReal()");
    {
        PciExtendedDeviceStatus temp;



        temp.designedMaximumCumulativeReadSize = 0;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 8);



        temp.designedMaximumCumulativeReadSize = 1;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 16);



        temp.designedMaximumCumulativeReadSize = 2;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 32);



        temp.designedMaximumCumulativeReadSize = 3;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 64);



        temp.designedMaximumCumulativeReadSize = 4;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 128);



        temp.designedMaximumCumulativeReadSize = 5;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 256);



        temp.designedMaximumCumulativeReadSize = 6;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 512);



        temp.designedMaximumCumulativeReadSize = 7;

        TEST_ASSERT_EQUALS(temp.designedMaximumCumulativeReadSizeReal(), 1024);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICESTATUS_H
