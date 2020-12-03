#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddresscontrol.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressresizablebaseaddresscontrol);
{
    TEST_CASE("barOffset()");
    {
        PciExpressResizableBaseAddressControl temp;



        temp.barIndex = 0;

        TEST_ASSERT_EQUALS(temp.barOffset(), 16);



        temp.barIndex = 1;

        TEST_ASSERT_EQUALS(temp.barOffset(), 20);



        temp.barIndex = 2;

        TEST_ASSERT_EQUALS(temp.barOffset(), 24);



        temp.barIndex = 3;

        TEST_ASSERT_EQUALS(temp.barOffset(), 28);



        temp.barIndex = 4;

        TEST_ASSERT_EQUALS(temp.barOffset(), 32);



        temp.barIndex = 5;

        TEST_ASSERT_EQUALS(temp.barOffset(), 36);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCONTROL_H
