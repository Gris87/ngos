#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_WIDGET_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_WIDGET_H



#include <buildconfig.h>
#include <com/ngos/shared/common/gui/widgets/widget.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_gui_widgets_widget);
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



    TEST_CASE("getGlobalPositionX()/getGlobalPositionY()");
    {
        Widget temp1;
        Widget temp2(&temp1);
        Widget temp3(&temp2);



        TEST_ASSERT_EQUALS(temp1.mPositionX,           0);
        TEST_ASSERT_EQUALS(temp1.mPositionY,           0);
        TEST_ASSERT_EQUALS(temp1.getGlobalPositionX(), 0);
        TEST_ASSERT_EQUALS(temp1.getGlobalPositionY(), 0);

        TEST_ASSERT_EQUALS(temp2.mPositionX,           0);
        TEST_ASSERT_EQUALS(temp2.mPositionY,           0);
        TEST_ASSERT_EQUALS(temp2.getGlobalPositionX(), 0);
        TEST_ASSERT_EQUALS(temp2.getGlobalPositionY(), 0);

        TEST_ASSERT_EQUALS(temp3.mPositionX,           0);
        TEST_ASSERT_EQUALS(temp3.mPositionY,           0);
        TEST_ASSERT_EQUALS(temp3.getGlobalPositionX(), 0);
        TEST_ASSERT_EQUALS(temp3.getGlobalPositionY(), 0);



        TEST_ASSERT_EQUALS(temp1.setPosition(30, 40), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.setPosition(10, 20), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp3.setPosition(50, 30), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp1.mPositionX,           30);
        TEST_ASSERT_EQUALS(temp1.mPositionY,           40);
        TEST_ASSERT_EQUALS(temp1.getGlobalPositionX(), 30);
        TEST_ASSERT_EQUALS(temp1.getGlobalPositionY(), 40);

        TEST_ASSERT_EQUALS(temp2.mPositionX,           10);
        TEST_ASSERT_EQUALS(temp2.mPositionY,           20);
        TEST_ASSERT_EQUALS(temp2.getGlobalPositionX(), 40);
        TEST_ASSERT_EQUALS(temp2.getGlobalPositionY(), 60);

        TEST_ASSERT_EQUALS(temp3.mPositionX,           50);
        TEST_ASSERT_EQUALS(temp3.mPositionY,           30);
        TEST_ASSERT_EQUALS(temp3.getGlobalPositionX(), 90);
        TEST_ASSERT_EQUALS(temp3.getGlobalPositionY(), 90);



        TEST_ASSERT_EQUALS(temp1.mChildren.clear(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.mChildren.clear(), NgosStatus::OK);
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



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_WIDGET_H
