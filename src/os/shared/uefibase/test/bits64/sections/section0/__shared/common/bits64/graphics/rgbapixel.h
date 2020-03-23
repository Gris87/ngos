#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_RGBAPIXEL_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_RGBAPIXEL_H



#include <buildconfig.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/memory/memory.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_graphics_rgbapixel);
{
    TEST_CASE("RgbaPixel()");
    {
        RgbaPixel temp;

        TEST_ASSERT_EQUALS(temp.red,     0x00);
        TEST_ASSERT_EQUALS(temp.green,   0x00);
        TEST_ASSERT_EQUALS(temp.blue,    0x00);
        TEST_ASSERT_EQUALS(temp.alpha,   0x00);
        TEST_ASSERT_EQUALS(temp.value32, 0x00000000);



        RgbaPixel temp2(1, 2, 3, 4);

        TEST_ASSERT_EQUALS(temp2.red,     0x01);
        TEST_ASSERT_EQUALS(temp2.green,   0x02);
        TEST_ASSERT_EQUALS(temp2.blue,    0x03);
        TEST_ASSERT_EQUALS(temp2.alpha,   0x04);
        TEST_ASSERT_EQUALS(temp2.value32, 0x04010203);



        RgbaPixel temp3(0x04010203);

        TEST_ASSERT_EQUALS(temp3.red,     0x01);
        TEST_ASSERT_EQUALS(temp3.green,   0x02);
        TEST_ASSERT_EQUALS(temp3.blue,    0x03);
        TEST_ASSERT_EQUALS(temp3.alpha,   0x04);
        TEST_ASSERT_EQUALS(temp3.value32, 0x04010203);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_RGBAPIXEL_H
