#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsize.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmibiosextendedromsize);
{
    TEST_CASE("size()");
    {
        DmiBiosExtendedRomSize temp;



        temp.value = 1;
        temp.unit  = (bad_uint16)DmiBiosExtendedRomSizeUnit::MEGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), MB);



        temp.value = 64;
        temp.unit  = (bad_uint16)DmiBiosExtendedRomSizeUnit::MEGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 64 * MB);



        temp.value = 16383;
        temp.unit  = (bad_uint16)DmiBiosExtendedRomSizeUnit::MEGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * MB);



        temp.value = 1;
        temp.unit  = (bad_uint16)DmiBiosExtendedRomSizeUnit::GIGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), GB);



        temp.value = 64;
        temp.unit  = (bad_uint16)DmiBiosExtendedRomSizeUnit::GIGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 64 * GB);



        temp.value = 16383;
        temp.unit  = (bad_uint16)DmiBiosExtendedRomSizeUnit::GIGABYTES;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * GB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZE_H
