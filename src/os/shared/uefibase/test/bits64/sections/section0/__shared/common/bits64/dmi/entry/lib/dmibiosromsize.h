#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmibiosromsize.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmibiosromsize);
{
    TEST_CASE("size()");
    {
        DmiBiosRomSize temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.size(), 128 * KB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.size(), 4160 * KB);



        temp.value = 255;

        TEST_ASSERT_EQUALS(temp.size(), 16384 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
