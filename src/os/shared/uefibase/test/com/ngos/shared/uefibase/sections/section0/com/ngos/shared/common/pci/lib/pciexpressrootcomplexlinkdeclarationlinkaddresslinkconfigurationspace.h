#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkaddresslinkconfigurationspace.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressrootcomplexlinkdeclarationlinkaddresslinkconfigurationspace);
{
    TEST_CASE("encodedNumberOfBusNumberBitsReal()");
    {
        PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace temp;



        temp.encodedNumberOfBusNumberBits = 0;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 8);



        temp.encodedNumberOfBusNumberBits = 1;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 1);



        temp.encodedNumberOfBusNumberBits = 2;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 2);



        temp.encodedNumberOfBusNumberBits = 3;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 3);



        temp.encodedNumberOfBusNumberBits = 4;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 4);



        temp.encodedNumberOfBusNumberBits = 5;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 5);



        temp.encodedNumberOfBusNumberBits = 6;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 6);



        temp.encodedNumberOfBusNumberBits = 7;

        TEST_ASSERT_EQUALS(temp.encodedNumberOfBusNumberBitsReal(), 7);
    }
    TEST_CASE_END();



    TEST_CASE("busNumberReal()");
    {
        PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace temp;

        temp.value64 = 0xBADABADABADABADA;



        temp.encodedNumberOfBusNumberBits = 0;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 173);



        temp.encodedNumberOfBusNumberBits = 1;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 1);



        temp.encodedNumberOfBusNumberBits = 2;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 1);



        temp.encodedNumberOfBusNumberBits = 3;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 5);



        temp.encodedNumberOfBusNumberBits = 4;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 13);



        temp.encodedNumberOfBusNumberBits = 5;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 13);



        temp.encodedNumberOfBusNumberBits = 6;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 45);



        temp.encodedNumberOfBusNumberBits = 7;

        TEST_ASSERT_EQUALS(temp.busNumberReal(), 45);
    }
    TEST_CASE_END();



    TEST_CASE("configurationSpaceBaseAddressReal()");
    {
        PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace temp;

        temp.value64 = 0xBADABADABADABADA;



        temp.encodedNumberOfBusNumberBits = 0;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x0000000BADABADAB);



        temp.encodedNumberOfBusNumberBits = 1;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x000005D6D5D6D5D6);



        temp.encodedNumberOfBusNumberBits = 2;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x000002EB6AEB6AEB);



        temp.encodedNumberOfBusNumberBits = 3;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x00000175B575B575);



        temp.encodedNumberOfBusNumberBits = 4;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x000000BADABADABA);



        temp.encodedNumberOfBusNumberBits = 5;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x0000005D6D5D6D5D);



        temp.encodedNumberOfBusNumberBits = 6;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x0000002EB6AEB6AE);



        temp.encodedNumberOfBusNumberBits = 7;

        TEST_ASSERT_EQUALS(temp.configurationSpaceBaseAddressReal(), 0x000000175B575B57);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H
