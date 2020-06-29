#ifndef NETWORKTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_TYPES_H
#define NETWORKTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/com/ngos/bootloader_tools/networktest/main/networktest.h"
#include "src/com/ngos/bootloader_tools/networktest/main/networktestgui.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_tools_networktest_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(NetworkTest),    1);
        TEST_ASSERT_EQUALS(sizeof(NetworkTestGUI), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // NETWORKTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_NETWORKTEST_TYPES_H
