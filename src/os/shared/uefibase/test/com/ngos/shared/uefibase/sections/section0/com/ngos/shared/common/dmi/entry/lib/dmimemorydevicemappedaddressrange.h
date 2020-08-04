#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEMAPPEDADDRESSRANGE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEMAPPEDADDRESSRANGE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicemappedaddressrange.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemorydevicemappedaddressrange);
{
    TEST_CASE("address()");
    {
        DmiMemoryDeviceMappedAddressRange temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.address(),  1 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 2 * KB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.address(),  64 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 65 * KB);



        temp.value = 16383;

        TEST_ASSERT_EQUALS(temp.address(),  16383 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 16384 * KB);



        temp.value = 916383;

        TEST_ASSERT_EQUALS(temp.address(),  916383 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 916384 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEMAPPEDADDRESSRANGE_H
