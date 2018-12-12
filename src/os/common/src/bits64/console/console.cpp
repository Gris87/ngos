#include "console.h"

#include <src/bits64/assets/assets.h>
#include <src/bits64/console/lib/glyphdata.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/memory/memory.h>
#include <src/bits64/printf/printf.h>



#define CHAR_HEIGHT   20
#define BOTTOM_MARGIN 5



ScreenInfo *Console::sScreenInfo;
u16         Console::sScreenPosX;
u16        *Console::sGlyphOffsets;



NgosStatus Console::init(BootParams *params)
{
    COMMON_LT((" | params = 0x%p", params));

    COMMON_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);



    sScreenInfo   = &params->screenInfo;
    sScreenPosX   = 0;
    sGlyphOffsets = (u16 *)asset->content;



    return NgosStatus::OK;
}

void Console::print(char ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs

    COMMON_ASSERT(sScreenInfo, "sScreenInfo is null");



    if (ch == '\n')
    {
        newLineWithoutCaretReturn();
    }
    else
    if (ch == '\r')
    {
        sScreenPosX = 0;
    }
    else
    {
        if (ch >= 0x20 && ch < 0x7F)
        {
            GlyphData *glyphData = (GlyphData *)((u64)sGlyphOffsets + sGlyphOffsets[ch - 0x20]);



            if (sScreenPosX + glyphData->width > sScreenInfo->width)
            {
                newLine();
            }



            u16 charPosX      = sScreenPosX + glyphData->bitmapLeft;
            u16 charPosY      = sScreenInfo->height - BOTTOM_MARGIN - glyphData->bitmapTop;
            u8  bytesPerPixel = sScreenInfo->depth >> 3; // ">> 3" == "/ 8"



            for (i64 i = 0; i < glyphData->bitmapHeight; ++i)
            {
                for (i64 j = 0; j < glyphData->bitmapWidth; ++j)
                {
                    u8 greyColor = glyphData->bitmap[i * glyphData->bitmapWidth + j];

                    u8 *frameBufferPixel = (u8 *)((u64)sScreenInfo->frameBufferBase + (charPosY + i) * sScreenInfo->lineLength + (charPosX + j) * bytesPerPixel);

                    frameBufferPixel[0] = greyColor;
                    frameBufferPixel[1] = greyColor;
                    frameBufferPixel[2] = greyColor;
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

void Console::print(const char *str)
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

void Console::println(char ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    print(ch);
    newLine();
}

void Console::println(const char *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null");



    print(str);
    newLine();
}

NgosStatus Console::noMorePrint()
{
    COMMON_LT((""));

    COMMON_ASSERT(sScreenInfo, "sScreenInfo is null", NgosStatus::ASSERTION);



    sScreenInfo = 0;



    return NgosStatus::OK;
}

bool Console::canPrint()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sScreenInfo;
}

void Console::newLineWithoutCaretReturn()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    u32 lineByteSize = sScreenInfo->lineLength * CHAR_HEIGHT;

    memcpy((void *)sScreenInfo->frameBufferBase, (void *)(sScreenInfo->frameBufferBase + lineByteSize), sScreenInfo->frameBufferSize - lineByteSize);
    memzero((void *)(sScreenInfo->frameBufferBase + sScreenInfo->frameBufferSize - lineByteSize), lineByteSize);
}

void Console::newLine()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    newLineWithoutCaretReturn();

    sScreenPosX = 0;
}
