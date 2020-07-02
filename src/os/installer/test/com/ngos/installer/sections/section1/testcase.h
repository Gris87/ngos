#ifndef INSTALLER_TEST_COM_NGOS_INSTALLER_SECTIONS_SECTION1_TESTCASE_H
#define INSTALLER_TEST_COM_NGOS_INSTALLER_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "test/com/ngos/installer/sections/section1/com/ngos/installer/types.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_installer_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // INSTALLER_TEST_COM_NGOS_INSTALLER_SECTIONS_SECTION1_TESTCASE_H
