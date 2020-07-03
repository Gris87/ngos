#ifndef DEVICEMANAGER_TEST_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SECTIONS_SECTION1_TESTCASE_H
#define DEVICEMANAGER_TEST_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>

#include "test/com/ngos/bootloader_tools/devicemanager/sections/section1/com/ngos/bootloader_tools/devicemanager/types.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_bootloader_tools_devicemanager_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // DEVICEMANAGER_TEST_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SECTIONS_SECTION1_TESTCASE_H
