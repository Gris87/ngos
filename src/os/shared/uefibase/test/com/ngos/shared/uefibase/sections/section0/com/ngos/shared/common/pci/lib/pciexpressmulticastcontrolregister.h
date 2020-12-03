#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastcontrolregister.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressmulticastcontrolregister);
{
    TEST_CASE("mcNumGroupReal()");
    {
        PciExpressMulticastControlRegister temp;



        temp.mcNumGroup = 0;

        TEST_ASSERT_EQUALS(temp.mcNumGroupReal(), 1);



        temp.mcNumGroup = 1;

        TEST_ASSERT_EQUALS(temp.mcNumGroupReal(), 2);



        temp.mcNumGroup = 2;

        TEST_ASSERT_EQUALS(temp.mcNumGroupReal(), 3);



        temp.mcNumGroup = 3;

        TEST_ASSERT_EQUALS(temp.mcNumGroupReal(), 4);



        temp.mcNumGroup = 4;

        TEST_ASSERT_EQUALS(temp.mcNumGroupReal(), 5);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H
