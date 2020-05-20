#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H



#include <buildconfig.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsize.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmibiosextendedromsize);
{
    TEST_CASE("size()");
    {
        DmiBiosExtendedRomSize temp;



        temp.value = 1;
        temp.unit  = (u16)DmiBiosExtendedRomSizeUnit::MEGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), MB);



        temp.value = 64;
        temp.unit  = (u16)DmiBiosExtendedRomSizeUnit::MEGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 64 * MB);



        temp.value = 16383;
        temp.unit  = (u16)DmiBiosExtendedRomSizeUnit::MEGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * MB);



        temp.value = 1;
        temp.unit  = (u16)DmiBiosExtendedRomSizeUnit::GIGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), GB);



        temp.value = 64;
        temp.unit  = (u16)DmiBiosExtendedRomSizeUnit::GIGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 64 * GB);



        temp.value = 16383;
        temp.unit  = (u16)DmiBiosExtendedRomSizeUnit::GIGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * GB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
