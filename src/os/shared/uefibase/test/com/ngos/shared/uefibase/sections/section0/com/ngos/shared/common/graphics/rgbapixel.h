#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H



#include <buildconfig.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_graphics_rgbapixel);
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



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H
