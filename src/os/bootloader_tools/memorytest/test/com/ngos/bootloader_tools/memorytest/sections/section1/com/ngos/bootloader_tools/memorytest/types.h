#ifndef MEMORYTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TYPES_H
#define MEMORYTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/com/ngos/bootloader_tools/memorytest/main/memorytest.h"
#include "src/com/ngos/bootloader_tools/memorytest/main/memorytestgui.h"
#include "src/com/ngos/bootloader_tools/memorytest/other/testmode.h"
#include "src/com/ngos/bootloader_tools/memorytest/other/testtype.h"
#include "src/com/ngos/bootloader_tools/memorytest/tests/testbase.h"
#include "src/com/ngos/bootloader_tools/memorytest/tests/testrandomread.h"
#include "src/com/ngos/bootloader_tools/memorytest/tests/testrandomwrite.h"
#include "src/com/ngos/bootloader_tools/memorytest/tests/testsequentialread.h"
#include "src/com/ngos/bootloader_tools/memorytest/tests/testsequentialwrite.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_tools_memorytest_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(MemoryTest),          1);
        TEST_ASSERT_EQUALS(sizeof(MemoryTestGUI),       1);
        TEST_ASSERT_EQUALS(sizeof(TestBase),            88);
        TEST_ASSERT_EQUALS(sizeof(TestMode),            1);
        TEST_ASSERT_EQUALS(sizeof(TestRandomRead),      88);
        TEST_ASSERT_EQUALS(sizeof(TestRandomWrite),     96);
        TEST_ASSERT_EQUALS(sizeof(TestSequentialRead),  88);
        TEST_ASSERT_EQUALS(sizeof(TestSequentialWrite), 96);
        TEST_ASSERT_EQUALS(sizeof(TestType),            1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // MEMORYTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TYPES_H
