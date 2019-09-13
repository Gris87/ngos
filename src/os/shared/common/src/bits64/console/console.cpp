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
u16                         Console::sScreenPosX;
u16                        *Console::sGlyphOffsets;



NgosStatus Console::init(BootParams *params)
{
    COMMON_LT((" | params = 0x%p", params));

    COMMON_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    sScreenGop    = params->screens[0];
    sScreenPosX   = SIDE_MARGIN;
    sGlyphOffsets = (u16 *)asset->content;



    return NgosStatus::OK;
}

void Console::print(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs

    COMMON_ASSERT(sScreenGop, "sScreenInfo is null");



    if (ch == '\n')
    {
        newLineWithoutCaretReturn();
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
                newLine();
            }



            i16 charPosX   = sScreenPosX + glyphData->bitmapLeft;
            i16 charPosY   = sScreenGop->mode->info->verticalResolution - BOTTOM_MARGIN - glyphData->bitmapTop;
            u8 *bitmapByte = glyphData->bitmap;

            COMMON_TEST_ASSERT(charPosX >= 0);
            COMMON_TEST_ASSERT(charPosY + glyphData->bitmapHeight <= (i64)sScreenGop->mode->info->verticalResolution);
            COMMON_TEST_ASSERT(glyphData->bitmapHeight <= CHAR_HEIGHT);



            for (i64 i = 0; i < glyphData->bitmapHeight; ++i)
            {
                for (i64 j = 0; j < glyphData->bitmapWidth; ++j)
                {
                    RgbaPixel *pixel = &((RgbaPixel *)sScreenGop->mode->frameBufferBase)[(charPosY + i) * sScreenGop->mode->info->horizontalResolution + charPosX + j];

                    COMMON_TEST_ASSERT(
                        (u64)pixel >= (u64)sScreenGop->mode->frameBufferBase + sScreenGop->mode->frameBufferSize - CHAR_HEIGHT * (sScreenGop->mode->info->pixelsPerScanLine << 2)
                        &&
                        (u64)pixel <= (u64)sScreenGop->mode->frameBufferBase + sScreenGop->mode->frameBufferSize - sizeof(RgbaPixel)
                    );



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
        }
    }
}

void Console::print(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null");



    while (*str)
    {
        if (*str == '\n')
        {
            print('\r');
        }

        print(*str);

        ++str;
    }
}

void Console::println()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    newLine();
}

void Console::println(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    print(ch);
    newLine();
}

void Console::println(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null");



    print(str);
    newLine();
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

void Console::newLineWithoutCaretReturn()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs

    COMMON_ASSERT(sScreenGop, "sScreenInfo is null");



    u32 lineByteSize = CHAR_HEIGHT * sScreenGop->mode->info->pixelsPerScanLine << 2;

    memcpy((void *)sScreenGop->mode->frameBufferBase, (void *)(sScreenGop->mode->frameBufferBase + lineByteSize), sScreenGop->mode->frameBufferSize - lineByteSize);
    memzero((void *)(sScreenGop->mode->frameBufferBase + sScreenGop->mode->frameBufferSize - lineByteSize), lineByteSize);
}

void Console::newLine()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    newLineWithoutCaretReturn();

    sScreenPosX = SIDE_MARGIN;
}
