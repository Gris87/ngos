#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestercapabilityregister.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpresstphrequestercapabilityregister);
{
    TEST_CASE("stTableSizeReal()");
    {
        PciExpressTphRequesterCapabilityRegister temp;



        temp.stTableSize = 0;

        TEST_ASSERT_EQUALS(temp.stTableSizeReal(), 1);



        temp.stTableSize = 1;

        TEST_ASSERT_EQUALS(temp.stTableSizeReal(), 2);



        temp.stTableSize = 2;

        TEST_ASSERT_EQUALS(temp.stTableSizeReal(), 3);



        temp.stTableSize = 3;

        TEST_ASSERT_EQUALS(temp.stTableSizeReal(), 4);



        temp.stTableSize = 4;

        TEST_ASSERT_EQUALS(temp.stTableSizeReal(), 5);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H
