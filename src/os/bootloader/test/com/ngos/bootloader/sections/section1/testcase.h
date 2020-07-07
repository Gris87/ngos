#ifndef BOOTLOADER_TEST_COM_NGOS_BOOTLOADER_SECTIONS_SECTION1_TESTCASE_H
#define BOOTLOADER_TEST_COM_NGOS_BOOTLOADER_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <com/ngos/bootloader/sections/section1/com/ngos/bootloader/main/bootloader.h>
#include <com/ngos/bootloader/sections/section1/com/ngos/bootloader/types.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_bootloader_main_bootloader);
    CALL_TEST_CASES(section1, com_ngos_bootloader_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // BOOTLOADER_TEST_COM_NGOS_BOOTLOADER_SECTIONS_SECTION1_TESTCASE_H
