#ifndef PARTITIONWIZARD_TEST_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_SECTIONS_SECTION1_TESTCASE_H
#define PARTITIONWIZARD_TEST_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <com/ngos/shared/uefibase/testengine.h>

#include "com/ngos/bootloader_tools/partitionwizard/sections/section1/com/ngos/bootloader_tools/partitionwizard/types.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_bootloader_tools_partitionwizard_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // PARTITIONWIZARD_TEST_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_SECTIONS_SECTION1_TESTCASE_H
