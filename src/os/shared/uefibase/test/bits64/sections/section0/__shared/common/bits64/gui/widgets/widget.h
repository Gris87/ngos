#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GUI_WIDGETS_WIDGET_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GUI_WIDGETS_WIDGET_H



#include <buildconfig.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_gui_widgets_widget);
{
    TEST_CASE("setPosition()");
    {
        Widget temp;

        TEST_ASSERT_EQUALS(temp.mPositionX, 0);
        TEST_ASSERT_EQUALS(temp.mPositionY, 0);

        TEST_ASSERT_EQUALS(temp.setPosition(10, 20), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPositionX, 10);
        TEST_ASSERT_EQUALS(temp.mPositionY, 20);
    }
    TEST_CASE_END();



    TEST_CASE("setSize()");
    {
        Widget temp;

        TEST_ASSERT_EQUALS(temp.mWidth,  0);
        TEST_ASSERT_EQUALS(temp.mHeight, 0);

        TEST_ASSERT_EQUALS(temp.setSize(30, 40), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mWidth,  30);
        TEST_ASSERT_EQUALS(temp.mHeight, 40);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GUI_WIDGETS_WIDGET_H
