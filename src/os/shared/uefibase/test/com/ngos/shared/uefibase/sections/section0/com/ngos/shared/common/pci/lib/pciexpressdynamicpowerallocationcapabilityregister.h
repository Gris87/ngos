#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationcapabilityregister.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressdynamicpowerallocationcapabilityregister);
{
    TEST_CASE("substateMaximumReal()");
    {
        PciExpressDynamicPowerAllocationCapabilityRegister temp;



        temp.substateMaximum = 0;

        TEST_ASSERT_EQUALS(temp.substateMaximumReal(), 1);



        temp.substateMaximum = 1;

        TEST_ASSERT_EQUALS(temp.substateMaximumReal(), 2);



        temp.substateMaximum = 2;

        TEST_ASSERT_EQUALS(temp.substateMaximumReal(), 3);



        temp.substateMaximum = 3;

        TEST_ASSERT_EQUALS(temp.substateMaximumReal(), 4);



        temp.substateMaximum = 4;

        TEST_ASSERT_EQUALS(temp.substateMaximumReal(), 5);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITYREGISTER_H
