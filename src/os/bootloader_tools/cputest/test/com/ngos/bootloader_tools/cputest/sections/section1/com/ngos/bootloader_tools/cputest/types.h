#ifndef COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TYPES_H
#define COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TYPES_H



#include <buildconfig.h>
#include <com/ngos/bootloader_tools/cputest/main/cputest.h>
#include <com/ngos/bootloader_tools/cputest/main/cputestgui.h>
#include <com/ngos/bootloader_tools/cputest/other/cacheinfo.h>
#include <com/ngos/bootloader_tools/cputest/other/testtype.h>
#include <com/ngos/bootloader_tools/cputest/tests/testaes.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx2.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx512bw.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx512cd.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx512dq.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx512f.h>
#include <com/ngos/bootloader_tools/cputest/tests/testavx512vl.h>
#include <com/ngos/bootloader_tools/cputest/tests/testbase.h>
#include <com/ngos/bootloader_tools/cputest/tests/testbitwise.h>
#include <com/ngos/bootloader_tools/cputest/tests/testdouble.h>
#include <com/ngos/bootloader_tools/cputest/tests/testfloat.h>
#include <com/ngos/bootloader_tools/cputest/tests/testfma3.h>
#include <com/ngos/bootloader_tools/cputest/tests/testinteger.h>
#include <com/ngos/bootloader_tools/cputest/tests/testlogical.h>
#include <com/ngos/bootloader_tools/cputest/tests/testsse.h>
#include <com/ngos/bootloader_tools/cputest/tests/testsse2.h>
#include <com/ngos/bootloader_tools/cputest/tests/testsse3.h>
#include <com/ngos/bootloader_tools/cputest/tests/testsse41.h>
#include <com/ngos/bootloader_tools/cputest/tests/testsse42.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_tools_cputest_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(CacheInfo),    8);
        TEST_ASSERT_EQUALS(sizeof(CpuTest),      1);
        TEST_ASSERT_EQUALS(sizeof(CpuTestGUI),   1);
        TEST_ASSERT_EQUALS(sizeof(TestAes),      96);
        TEST_ASSERT_EQUALS(sizeof(TestAvx2),     32);
        TEST_ASSERT_EQUALS(sizeof(TestAvx),      32);
        TEST_ASSERT_EQUALS(sizeof(TestAvx512Bw), 32);
        TEST_ASSERT_EQUALS(sizeof(TestAvx512Cd), 32);
        TEST_ASSERT_EQUALS(sizeof(TestAvx512Dq), 32);
        TEST_ASSERT_EQUALS(sizeof(TestAvx512F),  32);
        TEST_ASSERT_EQUALS(sizeof(TestAvx512Vl), 32);
        TEST_ASSERT_EQUALS(sizeof(TestBase),     32);
        TEST_ASSERT_EQUALS(sizeof(TestBitwise),  32);
        TEST_ASSERT_EQUALS(sizeof(TestDouble),   32);
        TEST_ASSERT_EQUALS(sizeof(TestFloat),    32);
        TEST_ASSERT_EQUALS(sizeof(TestFma3),     32);
        TEST_ASSERT_EQUALS(sizeof(TestInteger),  32);
        TEST_ASSERT_EQUALS(sizeof(TestLogical),  32);
        TEST_ASSERT_EQUALS(sizeof(TestSse2),     32);
        TEST_ASSERT_EQUALS(sizeof(TestSse),      32);
        TEST_ASSERT_EQUALS(sizeof(TestSse3),     32);
        TEST_ASSERT_EQUALS(sizeof(TestSse41),    32);
        TEST_ASSERT_EQUALS(sizeof(TestSse42),    32);
        TEST_ASSERT_EQUALS(sizeof(TestType),     1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TYPES_H
