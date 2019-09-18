#include "console.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/printf/printf.h>



#define CHAR_HEIGHT   20
#define SIDE_MARGIN   1
#define BOTTOM_MARGIN 5



UefiGraphicsOutputProtocol *Console::sScreenGop;
RgbaPixel                  *Console::sDoubleBuffer;
RgbaPixel                  *Console::sLastLineBuffer;
u64                         Console::sLastLineBufferSize;
u16                         Console::sScreenPosX;
u16                        *Console::sGlyphOffsets;



NgosStatus Console::init(BootParams *params, RgbaPixel *doubleBuffer, u64 doubleBufferSize)
{
    COMMON_LT((" | params = 0x%p, doubleBuffer = 0x%p, doubleBufferSize = %u", params, doubleBuffer, doubleBufferSize));

    COMMON_ASSERT(params,               "params is null",           NgosStatus::ASSERTION);
    COMMON_ASSERT(doubleBuffer,         "doubleBuffer is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(doubleBufferSize > 0, "doubleBufferSize is zero", NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    sScreenGop          = params->screens[0];
    sDoubleBuffer       = doubleBuffer;
    sLastLineBufferSize = sScreenGop->mode->info->horizontalResolution * (CHAR_HEIGHT + BOTTOM_MARGIN) * sizeof(RgbaPixel);
    sLastLineBuffer     = (RgbaPixel *)((u64)sDoubleBuffer + doubleBufferSize - sLastLineBufferSize);
    sScreenPosX         = SIDE_MARGIN;
    sGlyphOffsets       = (u16 *)asset->content;



    memzero(sLastLineBuffer, sLastLineBufferSize);

    COMMON_ASSERT_EXECUTION(sScreenGop->blt(sScreenGop,
                                            (UefiGraphicsOutputBltPixel *)sLastLineBuffer,
                                            UefiGraphicsOutputBltOperation::VIDEO_FILL,
                                            0, 0,
                                            0, 0,
                                            sScreenGop->mode->info->horizontalResolution,
                                            sScreenGop->mode->info->verticalResolution,
                                            0),
                            UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Console::init()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(sScreenGop,                 NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sDoubleBuffer,              NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sLastLineBuffer,            NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sLastLineBufferSize > 0,    NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sScreenPosX == SIDE_MARGIN, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sGlyphOffsets,              NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);

    sGlyphOffsets = (u16 *)asset->content;



    return NgosStatus::OK;
}

NgosStatus Console::print(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs

    COMMON_ASSERT(sScreenGop, "sScreenGop is null", NgosStatus::ASSERTION);



    if (ch == '\n')
    {
        COMMON_ASSERT_EXECUTION(newLineWithoutCaretReturn(), NgosStatus::ASSERTION);
    }
    else
    if (ch == '\r')
    {
        sScreenPosX = SIDE_MARGIN;
    }
    else
    {
        if (ch >= 0x20 && ch < 0x7F)
        {
            GlyphData *glyphData = (GlyphData *)((u64)sGlyphOffsets + sGlyphOffsets[ch - 0x20]);



            if (sScreenPosX + glyphData->width > sScreenGop->mode->info->horizontalResolution - SIDE_MARGIN)
            {
                COMMON_ASSERT_EXECUTION(newLine(), NgosStatus::ASSERTION);
            }



            i16  charPosX   = sScreenPosX + glyphData->bitmapLeft;
            i16  charPosY   = CHAR_HEIGHT - glyphData->bitmapTop;
            u8  *bitmapByte = glyphData->bitmap;

            COMMON_TEST_ASSERT(charPosX                           >= 0,                                                 NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(charPosX + glyphData->bitmapWidth  <= (i64)sScreenGop->mode->info->horizontalResolution, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(charPosY                           >= 0,                                                 NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(charPosY + glyphData->bitmapHeight <= CHAR_HEIGHT + BOTTOM_MARGIN,                       NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(glyphData->bitmapHeight            <= CHAR_HEIGHT,                                       NgosStatus::ASSERTION);



            for (i64 i = 0; i < glyphData->bitmapHeight; ++i)
            {
                for (i64 j = 0; j < glyphData->bitmapWidth; ++j)
                {
                    RgbaPixel *pixel = &sLastLineBuffer[(charPosY + i) * sScreenGop->mode->info->horizontalResolution + charPosX + j];

                    COMMON_TEST_ASSERT((u64)pixel >= (u64)sLastLineBuffer
                                        &&
                                        (u64)pixel <= (u64)sLastLineBuffer + sLastLineBufferSize - sizeof(RgbaPixel), NgosStatus::ASSERTION);



                    u8 greyColor = *bitmapByte;

                    pixel->red   = greyColor;
                    pixel->green = greyColor;
                    pixel->blue  = greyColor;
                    pixel->alpha = 0xFF;

                    ++bitmapByte;
                }
            }

            sScreenPosX += glyphData->width;
        }
        else
        {
            COMMON_LW(("Non-printable character found: 0x%02X", (u8)ch));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
    }



    return NgosStatus::OK;
}

NgosStatus Console::print(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    while (*str)
    {
        if (*str == '\n')
        {
            COMMON_ASSERT_EXECUTION(print('\r'), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(print(*str), NgosStatus::ASSERTION);

        ++str;
    }



    return NgosStatus::OK;
}

NgosStatus Console::println()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(newLine(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Console::println(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(print(ch), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(newLine(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Console::println(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(print(str), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(newLine(),  NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Console::noMorePrint()
{
    COMMON_LT((""));

    COMMON_ASSERT(sScreenGop, "sScreenGop is null", NgosStatus::ASSERTION);



    sScreenGop = 0;



    return NgosStatus::OK;
}

bool Console::canPrint()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sScreenGop;
}

NgosStatus Console::newLineWithoutCaretReturn()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs

    COMMON_ASSERT(sScreenGop, "sScreenGop is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(sScreenGop->blt(sScreenGop,
                                            0,
                                            UefiGraphicsOutputBltOperation::VIDEO_TO_VIDEO,
                                            0, CHAR_HEIGHT + BOTTOM_MARGIN,
                                            0, 0,
                                            sScreenGop->mode->info->horizontalResolution,
                                            sScreenGop->mode->info->verticalResolution - CHAR_HEIGHT - BOTTOM_MARGIN,
                                            0),
                            UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(sScreenGop->blt(sScreenGop,
                                            (UefiGraphicsOutputBltPixel *)sLastLineBuffer,
                                            UefiGraphicsOutputBltOperation::BLT_BUFFER_TO_VIDEO,
                                            0, 0,
                                            0, sScreenGop->mode->info->verticalResolution - CHAR_HEIGHT - BOTTOM_MARGIN,
                                            sScreenGop->mode->info->horizontalResolution,
                                            CHAR_HEIGHT + BOTTOM_MARGIN,
                                            0),
                            UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    memzero(sLastLineBuffer, sLastLineBufferSize);



    return NgosStatus::OK;
}

NgosStatus Console::newLine()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(newLineWithoutCaretReturn(), NgosStatus::ASSERTION);

    sScreenPosX = SIDE_MARGIN;



    return NgosStatus::OK;
}
