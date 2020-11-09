#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcecapability.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pci_lib_pciexpressvirtualchannelvirtualchannelresourcecapability);
{
    TEST_CASE("maximumTimeSlotsReal()");
    {
        PciExpressVirtualChannelVirtualChannelResourceCapability temp;



        temp.maximumTimeSlots = 0;

        TEST_ASSERT_EQUALS(temp.maximumTimeSlotsReal(), 1);



        temp.maximumTimeSlots = 31;

        TEST_ASSERT_EQUALS(temp.maximumTimeSlotsReal(), 32);



        temp.maximumTimeSlots = 63;

        TEST_ASSERT_EQUALS(temp.maximumTimeSlotsReal(), 64);



        temp.maximumTimeSlots = 91;

        TEST_ASSERT_EQUALS(temp.maximumTimeSlotsReal(), 92);



        temp.maximumTimeSlots = 127;

        TEST_ASSERT_EQUALS(temp.maximumTimeSlotsReal(), 128);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECAPABILITY_H
