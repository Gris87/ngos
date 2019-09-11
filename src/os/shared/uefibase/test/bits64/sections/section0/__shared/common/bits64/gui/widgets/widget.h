#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GUI_WIDGETS_WIDGET_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GUI_WIDGETS_WIDGET_H



#include <buildconfig.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_gui_widgets_widget);
{
    TEST_CASE("hasIntersection()");
    {
        Widget temp;
        Widget temp2;

        TEST_ASSERT_EQUALS(temp.setPosition(0, 0),    NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.setSize(30, 40),      NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.setSize(10, 20),     NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp2.setPosition(30, 10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), false);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), false);



        TEST_ASSERT_EQUALS(temp2.setPosition(29, 10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), true);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), true);



        TEST_ASSERT_EQUALS(temp2.setPosition(-10, -10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), false);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), false);



        TEST_ASSERT_EQUALS(temp2.setPosition(-9, -10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), true);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), true);



        TEST_ASSERT_EQUALS(temp2.setPosition(0, 40), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), false);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), false);



        TEST_ASSERT_EQUALS(temp2.setPosition(0, 39), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), true);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), true);



        TEST_ASSERT_EQUALS(temp2.setPosition(10, -20), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), false);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), false);



        TEST_ASSERT_EQUALS(temp2.setPosition(10, -19), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.hasIntersection(&temp2), true);
        TEST_ASSERT_EQUALS(temp2.hasIntersection(&temp), true);



        TEST_ASSERT_EQUALS(temp.hasIntersection(30,  10,  10, 20), false);
        TEST_ASSERT_EQUALS(temp.hasIntersection(29,  10,  10, 20), true);
        TEST_ASSERT_EQUALS(temp.hasIntersection(-10, -10, 10, 20), false);
        TEST_ASSERT_EQUALS(temp.hasIntersection(-9,  -10, 10, 20), true);
        TEST_ASSERT_EQUALS(temp.hasIntersection(0,   40,  10, 20), false);
        TEST_ASSERT_EQUALS(temp.hasIntersection(0,   39,  10, 20), true);
        TEST_ASSERT_EQUALS(temp.hasIntersection(10,  -20, 10, 20), false);
        TEST_ASSERT_EQUALS(temp.hasIntersection(10,  -19, 10, 20), true);
    }
    TEST_CASE_END();



    TEST_CASE("setPosition()/getPositionX()/getPositionY()");
    {
        Widget temp;

        TEST_ASSERT_EQUALS(temp.mPositionX,     0);
        TEST_ASSERT_EQUALS(temp.mPositionY,     0);
        TEST_ASSERT_EQUALS(temp.getPositionX(), 0);
        TEST_ASSERT_EQUALS(temp.getPositionY(), 0);

        TEST_ASSERT_EQUALS(temp.setPosition(10, 20), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPositionX,     10);
        TEST_ASSERT_EQUALS(temp.mPositionY,     20);
        TEST_ASSERT_EQUALS(temp.getPositionX(), 10);
        TEST_ASSERT_EQUALS(temp.getPositionY(), 20);
    }
    TEST_CASE_END();



    TEST_CASE("setSize()/getWidth()/getHeight()");
    {
        Widget temp;

        TEST_ASSERT_EQUALS(temp.mWidth,      0);
        TEST_ASSERT_EQUALS(temp.mHeight,     0);
        TEST_ASSERT_EQUALS(temp.getWidth(),  0);
        TEST_ASSERT_EQUALS(temp.getHeight(), 0);

        TEST_ASSERT_EQUALS(temp.setSize(30, 40), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mWidth,      30);
        TEST_ASSERT_EQUALS(temp.mHeight,     40);
        TEST_ASSERT_EQUALS(temp.getWidth(),  30);
        TEST_ASSERT_EQUALS(temp.getHeight(), 40);
    }
    TEST_CASE_END();



    TEST_CASE("setVisible()/isVisible()");
    {
        Widget temp;

        TEST_ASSERT_EQUALS(temp.mVisible,    true);
        TEST_ASSERT_EQUALS(temp.isVisible(), true);

        TEST_ASSERT_EQUALS(temp.setVisible(false), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mVisible,    false);
        TEST_ASSERT_EQUALS(temp.isVisible(), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GUI_WIDGETS_WIDGET_H
