#ifndef COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_SECTIONS_SECTION1_TESTCASE_H
#define COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <com/ngos/bootloader_tools/memorytest/sections/section1/com/ngos/bootloader_tools/memorytest/types.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_bootloader_tools_memorytest_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_SECTIONS_SECTION1_TESTCASE_H
