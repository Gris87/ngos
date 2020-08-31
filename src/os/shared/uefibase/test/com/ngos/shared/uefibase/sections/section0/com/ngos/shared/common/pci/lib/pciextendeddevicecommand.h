#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicecommand.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciextendeddevicecommand);
{
    TEST_CASE("maximumMemoryReadByteCountReal()");
    {
        PciExtendedDeviceCommand temp;



        temp.maximumMemoryReadByteCount = 0;

        TEST_ASSERT_EQUALS(temp.maximumMemoryReadByteCountReal(), 512);



        temp.maximumMemoryReadByteCount = 1;

        TEST_ASSERT_EQUALS(temp.maximumMemoryReadByteCountReal(), 1024);



        temp.maximumMemoryReadByteCount = 2;

        TEST_ASSERT_EQUALS(temp.maximumMemoryReadByteCountReal(), 2048);



        temp.maximumMemoryReadByteCount = 3;

        TEST_ASSERT_EQUALS(temp.maximumMemoryReadByteCountReal(), 4096);
    }
    TEST_CASE_END();



    TEST_CASE("maximumOutstandingSplitTransactionsReal()");
    {
        PciExtendedDeviceCommand temp;



        temp.maximumOutstandingSplitTransactions = 0;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 1);



        temp.maximumOutstandingSplitTransactions = 1;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 2);



        temp.maximumOutstandingSplitTransactions = 2;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 3);



        temp.maximumOutstandingSplitTransactions = 3;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 4);



        temp.maximumOutstandingSplitTransactions = 4;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 8);



        temp.maximumOutstandingSplitTransactions = 5;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 12);



        temp.maximumOutstandingSplitTransactions = 6;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 16);



        temp.maximumOutstandingSplitTransactions = 7;

        TEST_ASSERT_EQUALS(temp.maximumOutstandingSplitTransactionsReal(), 32);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMMAND_H
