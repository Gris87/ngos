#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H



#include <buildconfig.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceextendedsize.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmimemorydeviceextendedsize);
{
    TEST_CASE("size()");
    {
        DmiMemoryDeviceExtendedSize temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.size(), MB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.size(), 64 * MB);



        temp.value = 16383;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * MB);



        temp.value = 916383;

        TEST_ASSERT_EQUALS(temp.size(), 916383 * MB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H