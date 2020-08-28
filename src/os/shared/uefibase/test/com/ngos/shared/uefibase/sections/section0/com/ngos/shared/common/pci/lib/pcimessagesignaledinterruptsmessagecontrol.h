#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pcimessagesignaledinterruptsmessagecontrol);
{
    TEST_CASE("supportMultipleMessageReal()");
    {
        PciMessageSignaledInterruptsMessageControl temp;



        temp.supportMultipleMessage = 0;

        TEST_ASSERT_EQUALS(temp.supportMultipleMessageReal(), 1);



        temp.supportMultipleMessage = 1;

        TEST_ASSERT_EQUALS(temp.supportMultipleMessageReal(), 2);



        temp.supportMultipleMessage = 2;

        TEST_ASSERT_EQUALS(temp.supportMultipleMessageReal(), 4);



        temp.supportMultipleMessage = 3;

        TEST_ASSERT_EQUALS(temp.supportMultipleMessageReal(), 8);
    }
    TEST_CASE_END();



    TEST_CASE("enableMultipleMessageReal()");
    {
        PciMessageSignaledInterruptsMessageControl temp;



        temp.enableMultipleMessage = 0;

        TEST_ASSERT_EQUALS(temp.enableMultipleMessageReal(), 1);



        temp.enableMultipleMessage = 1;

        TEST_ASSERT_EQUALS(temp.enableMultipleMessageReal(), 2);



        temp.enableMultipleMessage = 2;

        TEST_ASSERT_EQUALS(temp.enableMultipleMessageReal(), 4);



        temp.enableMultipleMessage = 3;

        TEST_ASSERT_EQUALS(temp.enableMultipleMessageReal(), 8);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H
