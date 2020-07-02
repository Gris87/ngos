#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_PNG_PNG_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_PNG_PNG_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/graphics/png/png.h>
#include <common/src/com/ngos/shared/common/memory/memory.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_graphics_png_png);
{
    TEST_CASE("unfilterLine()");
    {
        u8 temp1[] = { 13, 97, 32, 14, 65, 24, 21, 97 };
        u8 temp2[] = { 32, 13, 17, 31, 73, 72, 13, 48 };
        u8 res[8];

        memzero(res, sizeof(res));



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::NONE, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 32);
        TEST_ASSERT_EQUALS(res[3], 14);
        TEST_ASSERT_EQUALS(res[4], 65);
        TEST_ASSERT_EQUALS(res[5], 24);
        TEST_ASSERT_EQUALS(res[6], 21);
        TEST_ASSERT_EQUALS(res[7], 97);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::NONE, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 32);
        TEST_ASSERT_EQUALS(res[3], 14);
        TEST_ASSERT_EQUALS(res[4], 65);
        TEST_ASSERT_EQUALS(res[5], 24);
        TEST_ASSERT_EQUALS(res[6], 21);
        TEST_ASSERT_EQUALS(res[7], 97);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::SUB, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 110);
        TEST_ASSERT_EQUALS(res[2], 142);
        TEST_ASSERT_EQUALS(res[3], 156);
        TEST_ASSERT_EQUALS(res[4], 221);
        TEST_ASSERT_EQUALS(res[5], 245);
        TEST_ASSERT_EQUALS(res[6], 10);
        TEST_ASSERT_EQUALS(res[7], 107);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::SUB, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 110);
        TEST_ASSERT_EQUALS(res[2], 142);
        TEST_ASSERT_EQUALS(res[3], 156);
        TEST_ASSERT_EQUALS(res[4], 221);
        TEST_ASSERT_EQUALS(res[5], 245);
        TEST_ASSERT_EQUALS(res[6], 10);
        TEST_ASSERT_EQUALS(res[7], 107);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::UP, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 32);
        TEST_ASSERT_EQUALS(res[3], 14);
        TEST_ASSERT_EQUALS(res[4], 65);
        TEST_ASSERT_EQUALS(res[5], 24);
        TEST_ASSERT_EQUALS(res[6], 21);
        TEST_ASSERT_EQUALS(res[7], 97);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::UP, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 45);
        TEST_ASSERT_EQUALS(res[1], 110);
        TEST_ASSERT_EQUALS(res[2], 49);
        TEST_ASSERT_EQUALS(res[3], 45);
        TEST_ASSERT_EQUALS(res[4], 138);
        TEST_ASSERT_EQUALS(res[5], 96);
        TEST_ASSERT_EQUALS(res[6], 34);
        TEST_ASSERT_EQUALS(res[7], 145);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::AVERAGE, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 103);
        TEST_ASSERT_EQUALS(res[2], 83);
        TEST_ASSERT_EQUALS(res[3], 55);
        TEST_ASSERT_EQUALS(res[4], 92);
        TEST_ASSERT_EQUALS(res[5], 70);
        TEST_ASSERT_EQUALS(res[6], 56);
        TEST_ASSERT_EQUALS(res[7], 125);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::AVERAGE, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 29);
        TEST_ASSERT_EQUALS(res[1], 118);
        TEST_ASSERT_EQUALS(res[2], 99);
        TEST_ASSERT_EQUALS(res[3], 79);
        TEST_ASSERT_EQUALS(res[4], 141);
        TEST_ASSERT_EQUALS(res[5], 130);
        TEST_ASSERT_EQUALS(res[6], 92);
        TEST_ASSERT_EQUALS(res[7], 167);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::PAETH, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 110);
        TEST_ASSERT_EQUALS(res[2], 142);
        TEST_ASSERT_EQUALS(res[3], 156);
        TEST_ASSERT_EQUALS(res[4], 221);
        TEST_ASSERT_EQUALS(res[5], 245);
        TEST_ASSERT_EQUALS(res[6], 10);
        TEST_ASSERT_EQUALS(res[7], 107);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::PAETH, 1, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 45);
        TEST_ASSERT_EQUALS(res[1], 129);
        TEST_ASSERT_EQUALS(res[2], 161);
        TEST_ASSERT_EQUALS(res[3], 175);
        TEST_ASSERT_EQUALS(res[4], 240);
        TEST_ASSERT_EQUALS(res[5], 8);
        TEST_ASSERT_EQUALS(res[6], 29);
        TEST_ASSERT_EQUALS(res[7], 145);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::NONE, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 32);
        TEST_ASSERT_EQUALS(res[3], 14);
        TEST_ASSERT_EQUALS(res[4], 65);
        TEST_ASSERT_EQUALS(res[5], 24);
        TEST_ASSERT_EQUALS(res[6], 21);
        TEST_ASSERT_EQUALS(res[7], 97);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::NONE, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 32);
        TEST_ASSERT_EQUALS(res[3], 14);
        TEST_ASSERT_EQUALS(res[4], 65);
        TEST_ASSERT_EQUALS(res[5], 24);
        TEST_ASSERT_EQUALS(res[6], 21);
        TEST_ASSERT_EQUALS(res[7], 97);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::SUB, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 45);
        TEST_ASSERT_EQUALS(res[3], 111);
        TEST_ASSERT_EQUALS(res[4], 110);
        TEST_ASSERT_EQUALS(res[5], 135);
        TEST_ASSERT_EQUALS(res[6], 131);
        TEST_ASSERT_EQUALS(res[7], 232);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::SUB, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 45);
        TEST_ASSERT_EQUALS(res[3], 111);
        TEST_ASSERT_EQUALS(res[4], 110);
        TEST_ASSERT_EQUALS(res[5], 135);
        TEST_ASSERT_EQUALS(res[6], 131);
        TEST_ASSERT_EQUALS(res[7], 232);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::UP, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 32);
        TEST_ASSERT_EQUALS(res[3], 14);
        TEST_ASSERT_EQUALS(res[4], 65);
        TEST_ASSERT_EQUALS(res[5], 24);
        TEST_ASSERT_EQUALS(res[6], 21);
        TEST_ASSERT_EQUALS(res[7], 97);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::UP, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 45);
        TEST_ASSERT_EQUALS(res[1], 110);
        TEST_ASSERT_EQUALS(res[2], 49);
        TEST_ASSERT_EQUALS(res[3], 45);
        TEST_ASSERT_EQUALS(res[4], 138);
        TEST_ASSERT_EQUALS(res[5], 96);
        TEST_ASSERT_EQUALS(res[6], 34);
        TEST_ASSERT_EQUALS(res[7], 145);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::AVERAGE, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 38);
        TEST_ASSERT_EQUALS(res[3], 62);
        TEST_ASSERT_EQUALS(res[4], 84);
        TEST_ASSERT_EQUALS(res[5], 55);
        TEST_ASSERT_EQUALS(res[6], 63);
        TEST_ASSERT_EQUALS(res[7], 124);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::AVERAGE, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 29);
        TEST_ASSERT_EQUALS(res[1], 103);
        TEST_ASSERT_EQUALS(res[2], 55);
        TEST_ASSERT_EQUALS(res[3], 81);
        TEST_ASSERT_EQUALS(res[4], 129);
        TEST_ASSERT_EQUALS(res[5], 100);
        TEST_ASSERT_EQUALS(res[6], 92);
        TEST_ASSERT_EQUALS(res[7], 171);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, 0, PngFilterType::PAETH, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 97);
        TEST_ASSERT_EQUALS(res[2], 45);
        TEST_ASSERT_EQUALS(res[3], 111);
        TEST_ASSERT_EQUALS(res[4], 110);
        TEST_ASSERT_EQUALS(res[5], 135);
        TEST_ASSERT_EQUALS(res[6], 131);
        TEST_ASSERT_EQUALS(res[7], 232);



        TEST_ASSERT_EQUALS(Png::unfilterLine(temp1, res, temp2, PngFilterType::PAETH, 2, sizeof(res)), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 45);
        TEST_ASSERT_EQUALS(res[1], 110);
        TEST_ASSERT_EQUALS(res[2], 64);
        TEST_ASSERT_EQUALS(res[3], 124);
        TEST_ASSERT_EQUALS(res[4], 138);
        TEST_ASSERT_EQUALS(res[5], 148);
        TEST_ASSERT_EQUALS(res[6], 94);
        TEST_ASSERT_EQUALS(res[7], 245);
    }
    TEST_CASE_END();



    TEST_CASE("removePaddingBits()");
    {
        u8 temp1[] = { 13, 64, 67, 21, 34, 69, 10, 53 };
        u8 res[8];

        memzero(res, sizeof(res));



        TEST_ASSERT_EQUALS(Png::removePaddingBits(temp1, res, 16, 14, 4), NgosStatus::OK);

        TEST_ASSERT_EQUALS(res[0], 13);
        TEST_ASSERT_EQUALS(res[1], 65);
        TEST_ASSERT_EQUALS(res[2], 12);
        TEST_ASSERT_EQUALS(res[3], 82);
        TEST_ASSERT_EQUALS(res[4], 36);
        TEST_ASSERT_EQUALS(res[5], 66);
        TEST_ASSERT_EQUALS(res[6], 141);
        TEST_ASSERT_EQUALS(res[7], 0);
    }
    TEST_CASE_END();



    TEST_CASE("checkColorTypeAndBitDepth()");
    {
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE, 1),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE, 2),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE, 4),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE, 8),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE, 16), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE, 32), NgosStatus::INVALID_DATA);

        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGB, 1),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGB, 2),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGB, 4),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGB, 8),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGB, 16), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGB, 32), NgosStatus::INVALID_DATA);

        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::PALETTE, 1),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::PALETTE, 2),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::PALETTE, 4),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::PALETTE, 8),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::PALETTE, 16), NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::PALETTE, 32), NgosStatus::INVALID_DATA);

        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE_AND_ALPHA, 1),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE_AND_ALPHA, 2),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE_AND_ALPHA, 4),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE_AND_ALPHA, 8),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE_AND_ALPHA, 16), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::GREYSCALE_AND_ALPHA, 32), NgosStatus::INVALID_DATA);

        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGBA, 1),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGBA, 2),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGBA, 4),  NgosStatus::INVALID_DATA);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGBA, 8),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGBA, 16), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Png::checkColorTypeAndBitDepth(PngColorType::RGBA, 32), NgosStatus::INVALID_DATA);
    }
    TEST_CASE_END();



    TEST_CASE("paethPredictor()");
    {
        TEST_ASSERT_EQUALS(Png::paethPredictor(0,  36, 0),  36);
        TEST_ASSERT_EQUALS(Png::paethPredictor(63, 0,  0),  63);
        TEST_ASSERT_EQUALS(Png::paethPredictor(10, 34, 97), 10);
        TEST_ASSERT_EQUALS(Png::paethPredictor(31, 14, 35), 14);
        TEST_ASSERT_EQUALS(Png::paethPredictor(54, 23, 23), 54);
        TEST_ASSERT_EQUALS(Png::paethPredictor(29, 49, 79), 29);
        TEST_ASSERT_EQUALS(Png::paethPredictor(95, 10, 13), 95);
        TEST_ASSERT_EQUALS(Png::paethPredictor(24, 16, 20), 20);
    }
    TEST_CASE_END();



    TEST_CASE("readBitFromReversedStream()");
    {
        u8  temp1[]    = { 13, 47 };
        i64 bitPointer = 0;

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         1);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         2);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         3);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         4);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         5);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         6);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         7);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         8);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         9);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         10);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         11);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 0);
        TEST_ASSERT_EQUALS(bitPointer,                                         12);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         13);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         14);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         15);

        TEST_ASSERT_EQUALS(Png::readBitFromReversedStream(&bitPointer, temp1), 1);
        TEST_ASSERT_EQUALS(bitPointer,                                         16);
    }
    TEST_CASE_END();



    TEST_CASE("setBitOfReversedStream()");
    {
        u8  res[]      = { 0, 0 };
        i64 bitPointer = 0;

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       1);
        TEST_ASSERT_EQUALS(res[0],                                           128);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       2);
        TEST_ASSERT_EQUALS(res[0],                                           128);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       3);
        TEST_ASSERT_EQUALS(res[0],                                           160);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       4);
        TEST_ASSERT_EQUALS(res[0],                                           160);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       5);
        TEST_ASSERT_EQUALS(res[0],                                           160);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       6);
        TEST_ASSERT_EQUALS(res[0],                                           164);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       7);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       8);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       9);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           0);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       10);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           64);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       11);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           96);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       12);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           96);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       13);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           104);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       14);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           108);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 0), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       15);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           108);

        TEST_ASSERT_EQUALS(Png::setBitOfReversedStream(&bitPointer, res, 1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(bitPointer,                                       16);
        TEST_ASSERT_EQUALS(res[0],                                           166);
        TEST_ASSERT_EQUALS(res[1],                                           109);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_PNG_PNG_H
