#ifndef CPUTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_SECTIONS_SECTION1_TESTCASE_H
#define CPUTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>

#include "test/com/ngos/bootloader_tools/cputest/sections/section1/com/ngos/bootloader_tools/cputest/types.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_bootloader_tools_cputest_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // CPUTEST_TEST_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_SECTIONS_SECTION1_TESTCASE_H
