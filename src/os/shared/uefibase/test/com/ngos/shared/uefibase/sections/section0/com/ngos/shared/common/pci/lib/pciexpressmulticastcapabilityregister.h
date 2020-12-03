#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastcapabilityregister.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressmulticastcapabilityregister);
{
    TEST_CASE("mcMaxGroupReal()");
    {
        PciExpressMulticastCapabilityRegister temp;



        temp.mcMaxGroup = 0;

        TEST_ASSERT_EQUALS(temp.mcMaxGroupReal(), 1);



        temp.mcMaxGroup = 1;

        TEST_ASSERT_EQUALS(temp.mcMaxGroupReal(), 2);



        temp.mcMaxGroup = 2;

        TEST_ASSERT_EQUALS(temp.mcMaxGroupReal(), 3);



        temp.mcMaxGroup = 3;

        TEST_ASSERT_EQUALS(temp.mcMaxGroupReal(), 4);



        temp.mcMaxGroup = 4;

        TEST_ASSERT_EQUALS(temp.mcMaxGroupReal(), 5);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H
