#ifndef COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_TYPES_H
#define COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_TYPES_H



#include <buildconfig.h>
#include <com/ngos/bootloader_tools/hddtest/main/hddtest.h>
#include <com/ngos/bootloader_tools/hddtest/main/hddtestgui.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_tools_hddtest_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(HddTest),    1);
        TEST_ASSERT_EQUALS(sizeof(HddTestGUI), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_HDDTEST_TYPES_H
