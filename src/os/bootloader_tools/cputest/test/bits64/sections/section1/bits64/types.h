#ifndef CPUTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
#define CPUTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/main/cputest.h"
#include "src/bits64/main/cputestgui.h"
#include "src/bits64/other/cacheinfo.h"
#include "src/bits64/other/testtype.h"
#include "src/bits64/tests/testaes.h"
#include "src/bits64/tests/testavx.h"
#include "src/bits64/tests/testavx2.h"
#include "src/bits64/tests/testavx512bw.h"
#include "src/bits64/tests/testavx512cd.h"
#include "src/bits64/tests/testavx512dq.h"
#include "src/bits64/tests/testavx512f.h"
#include "src/bits64/tests/testavx512vl.h"
#include "src/bits64/tests/testbase.h"
#include "src/bits64/tests/testbitwise.h"
#include "src/bits64/tests/testdouble.h"
#include "src/bits64/tests/testfloat.h"
#include "src/bits64/tests/testfma3.h"
#include "src/bits64/tests/testinteger.h"
#include "src/bits64/tests/testlogical.h"
#include "src/bits64/tests/testsse.h"
#include "src/bits64/tests/testsse2.h"
#include "src/bits64/tests/testsse3.h"
#include "src/bits64/tests/testsse41.h"
#include "src/bits64/tests/testsse42.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_types);
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



#endif // CPUTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
