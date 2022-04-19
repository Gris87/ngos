#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_IMAGE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_IMAGE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_graphics_image);
{
    TEST_CASE("Image()");
    {
        Image temp(10, 20, true, true);
        Image temp2(temp);

        TEST_ASSERT_EQUALS(temp.mNinePatch,     nullptr);
        TEST_ASSERT_EQUALS(temp.mWidth,         10);
        TEST_ASSERT_EQUALS(temp.mHeight,        20);
        TEST_ASSERT_EQUALS(temp.mBytesPerPixel, 4);
        TEST_ASSERT_EQUALS(temp.mIsOpaque,      true);
        TEST_ASSERT_EQUALS(temp.mStride,        40);
        TEST_ASSERT_EQUALS(temp.mBufferSize,    800);
        TEST_ASSERT_NOT_EQUALS(temp.mBuffer,    nullptr);

        TEST_ASSERT_EQUALS(temp2.mNinePatch,     nullptr);
        TEST_ASSERT_EQUALS(temp2.mWidth,         10);
        TEST_ASSERT_EQUALS(temp2.mHeight,        20);
        TEST_ASSERT_EQUALS(temp2.mBytesPerPixel, 4);
        TEST_ASSERT_EQUALS(temp2.mIsOpaque,      true);
        TEST_ASSERT_EQUALS(temp2.mStride,        40);
        TEST_ASSERT_EQUALS(temp2.mBufferSize,    800);
        TEST_ASSERT_NOT_EQUALS(temp2.mBuffer,    nullptr);

        TEST_ASSERT_NOT_EQUALS(temp2.mBuffer, temp.mBuffer);
    }
    TEST_CASE_END();



    TEST_CASE("clearBuffer()");
    {
        Image temp(10, 20, true, true);

        temp.mBuffer[0] = 50;

        TEST_ASSERT_EQUALS(memempty(temp.mBuffer, temp.mBufferSize), false);
        TEST_ASSERT_EQUALS(temp.clearBuffer(),                       NgosStatus::OK);
        TEST_ASSERT_EQUALS(memempty(temp.mBuffer, temp.mBufferSize), true);
    }
    TEST_CASE_END();



    TEST_CASE("fill()");
    {
        Image temp(10, 20,  true,  true);
        Image temp2(10, 20, false, true);

        TEST_ASSERT_EQUALS(temp.clearBuffer(),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.clearBuffer(), NgosStatus::OK);

        TEST_ASSERT_EQUALS(memempty(temp.mBuffer,  temp.mBufferSize),  true);
        TEST_ASSERT_EQUALS(memempty(temp2.mBuffer, temp2.mBufferSize), true);



        RgbaPixel color;

        color.blue  = 1;
        color.green = 2;
        color.red   = 3;
        color.alpha = 4;



        TEST_ASSERT_EQUALS(temp.fill(color),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp2.fill(color), NgosStatus::OK);



        for (good_I64 i = 0; i < (i64)temp.mBufferSize; ++i)
        {
            TEST_ASSERT_EQUALS(temp.mBuffer[i], (i % 4) + 1);
        }

        for (good_I64 i = 0; i < (i64)temp2.mBufferSize; ++i)
        {
            TEST_ASSERT_EQUALS(temp2.mBuffer[i], (i % 3) + 1);
        }
    }
    TEST_CASE_END();



    TEST_CASE("createNinePatch()");
    {
        Image temp(10, 20, true, true);

        TEST_ASSERT_EQUALS(temp.mNinePatch,        nullptr);
        TEST_ASSERT_EQUALS(temp.createNinePatch(), NgosStatus::OK);
        TEST_ASSERT_NOT_EQUALS(temp.mNinePatch,    nullptr);

        TEST_ASSERT_EQUALS(temp.mNinePatch->addStretchRangeX(StretchRange(5, 10)), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.mNinePatch->setPaddingLeft(20),                    NgosStatus::OK);



        Image temp2(temp);

        TEST_ASSERT_NOT_EQUALS(temp.mNinePatch->mStretchRangesX.mHead,          nullptr);
        TEST_ASSERT_EQUALS(temp.mNinePatch->mStretchRangesX.mHead->mData.mFrom, 5);
        TEST_ASSERT_EQUALS(temp.mNinePatch->mStretchRangesX.mHead->mData.mTo,   10);
        TEST_ASSERT_EQUALS(temp.mNinePatch->mPaddingLeft,                       20);

        TEST_ASSERT_NOT_EQUALS(temp2.mNinePatch, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp2.mNinePatch, temp.mNinePatch);

        TEST_ASSERT_EQUALS(temp2.mNinePatch->mStretchRangesX.mHead->mData.mFrom, 5);
        TEST_ASSERT_EQUALS(temp2.mNinePatch->mStretchRangesX.mHead->mData.mTo,   10);
        TEST_ASSERT_EQUALS(temp2.mNinePatch->mPaddingLeft,                       20);
    }
    TEST_CASE_END();



    TEST_CASE("setOpaque()/isOpaque()");
    {
        Image temp(10, 20, true, true);

        TEST_ASSERT_EQUALS(temp.isOpaque(),       true);
        TEST_ASSERT_EQUALS(temp.setOpaque(false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.isOpaque(),       false);
    }
    TEST_CASE_END();



    TEST_CASE("getNinePatch()");
    {
        Image temp(10, 20, true, true);

        TEST_ASSERT_EQUALS(temp.mNinePatch,     nullptr);
        TEST_ASSERT_EQUALS(temp.getNinePatch(), nullptr);

        TEST_ASSERT_EQUALS(temp.createNinePatch(), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mNinePatch,     nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.getNinePatch(), nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("getWidth()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.getWidth(),  10);
        TEST_ASSERT_EQUALS(temp2.getWidth(), 30);
    }
    TEST_CASE_END();



    TEST_CASE("getHeight()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.getHeight(),  20);
        TEST_ASSERT_EQUALS(temp2.getHeight(), 40);
    }
    TEST_CASE_END();



    TEST_CASE("getBytesPerPixel()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.getBytesPerPixel(),  4);
        TEST_ASSERT_EQUALS(temp2.getBytesPerPixel(), 3);
    }
    TEST_CASE_END();



    TEST_CASE("isRgba()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.isRgba(),  true);
        TEST_ASSERT_EQUALS(temp2.isRgba(), false);
    }
    TEST_CASE_END();



    TEST_CASE("isRgb()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.isRgb(),  false);
        TEST_ASSERT_EQUALS(temp2.isRgb(), true);
    }
    TEST_CASE_END();



    TEST_CASE("getStride()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.getStride(),  40);
        TEST_ASSERT_EQUALS(temp2.getStride(), 90);
    }
    TEST_CASE_END();



    TEST_CASE("getBufferSize()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_EQUALS(temp.getBufferSize(),  800);
        TEST_ASSERT_EQUALS(temp2.getBufferSize(), 3600);
    }
    TEST_CASE_END();



    TEST_CASE("getBuffer()");
    {
        Image temp(10, 20, true, true);
        Image temp2(30, 40, false, true);

        TEST_ASSERT_NOT_EQUALS(temp.getBuffer(),  nullptr);
        TEST_ASSERT_NOT_EQUALS(temp2.getBuffer(), nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.getBuffer(),  temp2.getBuffer());
    }
    TEST_CASE_END();



    TEST_CASE("getRgbBuffer()");
    {
        Image temp(10, 20, false, true);

        TEST_ASSERT_NOT_EQUALS(temp.getRgbBuffer(), nullptr);
        TEST_ASSERT_EQUALS((u8 *)temp.getRgbBuffer(), temp.getBuffer());
    }
    TEST_CASE_END();



    TEST_CASE("getRgbaBuffer()");
    {
        Image temp(10, 20, true, true);

        TEST_ASSERT_NOT_EQUALS(temp.getRgbaBuffer(), nullptr);
        TEST_ASSERT_EQUALS((u8 *)temp.getRgbaBuffer(), temp.getBuffer());
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_IMAGE_H
