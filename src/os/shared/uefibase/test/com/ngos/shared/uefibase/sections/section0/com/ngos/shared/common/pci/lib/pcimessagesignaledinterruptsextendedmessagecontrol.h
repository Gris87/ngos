#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedmessagecontrol.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pcimessagesignaledinterruptsextendedmessagecontrol);
{
    TEST_CASE("tableSizeReal()");
    {
        PciMessageSignaledInterruptsExtendedMessageControl temp;



        temp.tableSize = 0;

        TEST_ASSERT_EQUALS(temp.tableSizeReal(), 1);



        temp.tableSize = 1;

        TEST_ASSERT_EQUALS(temp.tableSizeReal(), 2);



        temp.tableSize = 2;

        TEST_ASSERT_EQUALS(temp.tableSizeReal(), 3);



        temp.tableSize = 3;

        TEST_ASSERT_EQUALS(temp.tableSizeReal(), 4);



        temp.tableSize = 4;

        TEST_ASSERT_EQUALS(temp.tableSizeReal(), 5);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H
