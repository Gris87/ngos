#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressaccesscontrolservicesacscapability.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressaccesscontrolservicesacscapability);
{
    TEST_CASE("egressControlVectorSizeReal()");
    {
        PciExpressAccessControlServicesAcsCapability temp;



        temp.egressControlVectorSize = 0;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeReal(), 256);



        temp.egressControlVectorSize = 1;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeReal(), 1);



        temp.egressControlVectorSize = 5;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeReal(), 5);



        temp.egressControlVectorSize = 32;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeReal(), 32);



        temp.egressControlVectorSize = 60;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeReal(), 60);
    }
    TEST_CASE_END();



    TEST_CASE("egressControlVectorSizeNumberOfWords()");
    {
        PciExpressAccessControlServicesAcsCapability temp;



        temp.egressControlVectorSize = 0;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeNumberOfWords(), 8);



        temp.egressControlVectorSize = 1;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeNumberOfWords(), 1);



        temp.egressControlVectorSize = 5;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeNumberOfWords(), 1);



        temp.egressControlVectorSize = 32;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeNumberOfWords(), 1);



        temp.egressControlVectorSize = 60;

        TEST_ASSERT_EQUALS(temp.egressControlVectorSizeNumberOfWords(), 2);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCAPABILITY_H
