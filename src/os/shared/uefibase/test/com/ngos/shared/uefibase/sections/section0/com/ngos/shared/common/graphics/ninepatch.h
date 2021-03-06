#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H



#include <buildconfig.h>
#include <com/ngos/shared/common/graphics/ninepatch.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_graphics_ninepatch);
{
    TEST_CASE("NinePatch()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail, nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail, nullptr);
        TEST_ASSERT_EQUALS(temp.mPaddingLeft,          0);
        TEST_ASSERT_EQUALS(temp.mPaddingTop,           0);
        TEST_ASSERT_EQUALS(temp.mPaddingRight,         0);
        TEST_ASSERT_EQUALS(temp.mPaddingBottom,        0);



        TEST_ASSERT_EQUALS(temp.addStretchRangeX(StretchRange(10, 20)), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.addStretchRangeY(StretchRange(20, 30)), NgosStatus::OK);

        temp.mPaddingLeft   = 5;
        temp.mPaddingTop    = 15;
        temp.mPaddingRight  = 50;
        temp.mPaddingBottom = 25;



        NinePatch temp2(temp);



        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesX.mHead,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mHead->mData.mFrom, 10);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mHead->mData.mTo,   20);
        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesY.mHead,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mHead->mData.mFrom, 20);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mHead->mData.mTo,   30);
        TEST_ASSERT_EQUALS(temp.mPaddingLeft,                       5);
        TEST_ASSERT_EQUALS(temp.mPaddingTop,                        15);
        TEST_ASSERT_EQUALS(temp.mPaddingRight,                      50);
        TEST_ASSERT_EQUALS(temp.mPaddingBottom,                     25);

        TEST_ASSERT_NOT_EQUALS(temp2.mStretchRangesX.mHead,          nullptr);
        TEST_ASSERT_EQUALS(temp2.mStretchRangesX.mHead->mData.mFrom, 10);
        TEST_ASSERT_EQUALS(temp2.mStretchRangesX.mHead->mData.mTo,   20);
        TEST_ASSERT_NOT_EQUALS(temp2.mStretchRangesY.mHead,          nullptr);
        TEST_ASSERT_EQUALS(temp2.mStretchRangesY.mHead->mData.mFrom, 20);
        TEST_ASSERT_EQUALS(temp2.mStretchRangesY.mHead->mData.mTo,   30);
        TEST_ASSERT_EQUALS(temp2.mPaddingLeft,                       5);
        TEST_ASSERT_EQUALS(temp2.mPaddingTop,                        15);
        TEST_ASSERT_EQUALS(temp2.mPaddingRight,                      50);
        TEST_ASSERT_EQUALS(temp2.mPaddingBottom,                     25);



        TEST_ASSERT_NOT_EQUALS(temp2.mStretchRangesX.mHead, temp.mStretchRangesX.mHead);
        TEST_ASSERT_NOT_EQUALS(temp2.mStretchRangesY.mHead, temp.mStretchRangesY.mHead);
    }
    TEST_CASE_END();



    TEST_CASE("addStretchRangeX()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.addStretchRangeX(StretchRange(10, 20)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesX.mTail,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail->mData.mFrom, 10);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail->mData.mTo,   20);



        TEST_ASSERT_EQUALS(temp.addStretchRangeX(StretchRange(30, 40)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesX.mTail,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail->mData.mFrom, 30);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail->mData.mTo,   40);



        TEST_ASSERT_EQUALS(temp.addStretchRangeX(StretchRange(50, 75)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesX.mTail,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail->mData.mFrom, 50);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mTail->mData.mTo,   75);
    }
    TEST_CASE_END();



    TEST_CASE("addStretchRangeY()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.addStretchRangeY(StretchRange(10, 20)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesY.mTail,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail->mData.mFrom, 10);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail->mData.mTo,   20);



        TEST_ASSERT_EQUALS(temp.addStretchRangeY(StretchRange(30, 40)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesY.mTail,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail->mData.mFrom, 30);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail->mData.mTo,   40);



        TEST_ASSERT_EQUALS(temp.addStretchRangeY(StretchRange(50, 75)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesY.mTail,          nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail->mData.mFrom, 50);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mTail->mData.mTo,   75);
    }
    TEST_CASE_END();



    TEST_CASE("setPaddingLeft()/getPaddingLeft()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mPaddingLeft,     0);
        TEST_ASSERT_EQUALS(temp.getPaddingLeft(), 0);

        TEST_ASSERT_EQUALS(temp.setPaddingLeft(10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPaddingLeft,     10);
        TEST_ASSERT_EQUALS(temp.getPaddingLeft(), 10);
    }
    TEST_CASE_END();



    TEST_CASE("setPaddingTop()/getPaddingTop()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mPaddingTop,     0);
        TEST_ASSERT_EQUALS(temp.getPaddingTop(), 0);

        TEST_ASSERT_EQUALS(temp.setPaddingTop(10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPaddingTop,     10);
        TEST_ASSERT_EQUALS(temp.getPaddingTop(), 10);
    }
    TEST_CASE_END();



    TEST_CASE("setPaddingRight()/getPaddingRight()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mPaddingRight,     0);
        TEST_ASSERT_EQUALS(temp.getPaddingRight(), 0);

        TEST_ASSERT_EQUALS(temp.setPaddingRight(10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPaddingRight,     10);
        TEST_ASSERT_EQUALS(temp.getPaddingRight(), 10);
    }
    TEST_CASE_END();



    TEST_CASE("setPaddingBottom()/getPaddingBottom()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mPaddingBottom,     0);
        TEST_ASSERT_EQUALS(temp.getPaddingBottom(), 0);

        TEST_ASSERT_EQUALS(temp.setPaddingBottom(10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPaddingBottom,     10);
        TEST_ASSERT_EQUALS(temp.getPaddingBottom(), 10);
    }
    TEST_CASE_END();



    TEST_CASE("getStretchRangesX()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mHead,     nullptr);
        TEST_ASSERT_EQUALS(temp.getStretchRangesX().mHead, nullptr);

        TEST_ASSERT_EQUALS(temp.addStretchRangeX(StretchRange(10, 20)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesX.mHead,     nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.getStretchRangesX().mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesX.mHead,         temp.getStretchRangesX().mHead);
    }
    TEST_CASE_END();



    TEST_CASE("getStretchRangesY()");
    {
        NinePatch temp;

        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mHead,     nullptr);
        TEST_ASSERT_EQUALS(temp.getStretchRangesY().mHead, nullptr);

        TEST_ASSERT_EQUALS(temp.addStretchRangeY(StretchRange(10, 20)), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mStretchRangesY.mHead,     nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.getStretchRangesY().mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mStretchRangesY.mHead,         temp.getStretchRangesY().mHead);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H
