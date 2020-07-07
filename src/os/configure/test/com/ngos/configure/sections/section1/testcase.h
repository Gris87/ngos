#ifndef CONFIGURE_TEST_COM_NGOS_CONFIGURE_SECTIONS_SECTION1_TESTCASE_H
#define CONFIGURE_TEST_COM_NGOS_CONFIGURE_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <com/ngos/configure/sections/section1/com/ngos/configure/types.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, com_ngos_configure_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // CONFIGURE_TEST_COM_NGOS_CONFIGURE_SECTIONS_SECTION1_TESTCASE_H
