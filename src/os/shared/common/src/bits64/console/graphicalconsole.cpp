#include "graphicalconsole.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/misc/consolewidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/printf/printf.h>



#define CHAR_HEIGHT   20
#define BOTTOM_MARGIN 5

#define CONSOLE_POSITION_X_PERCENT 10
#define CONSOLE_POSITION_Y_PERCENT 70

#define CONSOLE_WIDTH_PERCENT  80
#define CONSOLE_HEIGHT_PERCENT 30



ConsoleWidget *GraphicalConsole::sConsoleWidget;
Image         *GraphicalConsole::sTextImage;
u16            GraphicalConsole::sPositionX;
u16           *GraphicalConsole::sGlyphOffsets;



NgosStatus GraphicalConsole::init()
{
    COMMON_LT((""));



    if (!sConsoleWidget)
    {
        u16 *temp     = sGlyphOffsets; // To avoid infinite loop
        sGlyphOffsets = 0;             // To avoid infinite loop



        ScreenWidget *screenWidget = GUI::getMainScreenWidget();
        u64           screenWidth  = screenWidget->getWidth();
        u64           screenHeight = screenWidget->getHeight();

        i64 consolePositionX = screenWidth  * CONSOLE_POSITION_X_PERCENT / 100;
        i64 consolePositionY = screenHeight * CONSOLE_POSITION_Y_PERCENT / 100;
        u64 consoleWidth     = screenWidth  * CONSOLE_WIDTH_PERCENT      / 100;
        u64 consoleHeight    = screenHeight * CONSOLE_HEIGHT_PERCENT     / 100;



        AssetEntry *asset = Assets::getAssetEntry("images/console.9.png");
        COMMON_TEST_ASSERT(asset != 0, NgosStatus::ASSERTION);

        Image *consoleImage;
        COMMON_ASSERT_EXECUTION(Graphics::loadImage(asset->content, asset->contentSize, &consoleImage), NgosStatus::ASSERTION);



        sConsoleWidget = new ConsoleWidget(consoleImage, screenWidget);

        COMMON_ASSERT_EXECUTION(sConsoleWidget->setPosition(consolePositionX, consolePositionY), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(sConsoleWidget->setSize(consoleWidth, consoleHeight),            NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(sConsoleWidget->invalidate(), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(sConsoleWidget->repaint(),    NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(sConsoleWidget->update(),     NgosStatus::ASSERTION);



        sTextImage = (Image *)malloc(sizeof(Image) + consoleWidth * consoleHeight * sizeof(RgbaPixel));

        if (!sTextImage)
        {
            COMMON_LE(("Failed to allocate space for raw image data. Out of space"));

            return NgosStatus::OUT_OF_MEMORY;
        }

        sTextImage->width    = consoleWidth;
        sTextImage->height   = consoleHeight;
        sTextImage->hasAlpha = true;
        sTextImage->isOpaque = false;

        memzero(sTextImage->data, consoleWidth * consoleHeight * sizeof(RgbaPixel));



        sGlyphOffsets = temp; // To avoid infinite loop
    }



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::readyToPrint()
{
    COMMON_LT((""));



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);



    sPositionX    = 0;
    sGlyphOffsets = (u16 *)asset->content;



    return NgosStatus::OK;
}

void GraphicalConsole::print(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    printChar(ch);



    repaint();
}

void GraphicalConsole::print(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null");



    while (*str)
    {
        if (*str == '\n')
        {
            printChar('\r');
        }

        printChar(*str);

        ++str;
    }



    repaint();
}

void GraphicalConsole::println()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    newLine();



    repaint();
}

void GraphicalConsole::println(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    printChar(ch);
    newLine();



    repaint();
}

void GraphicalConsole::println(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null");



    while (*str)
    {
        if (*str == '\n')
        {
            printChar('\r');
        }

        printChar(*str);

        ++str;
    }

    newLine();



    repaint();
}

NgosStatus GraphicalConsole::noMorePrint()
{
    COMMON_LT((""));

    COMMON_ASSERT(sGlyphOffsets, "sGlyphOffsets is null", NgosStatus::ASSERTION);



    sGlyphOffsets = 0;



    return NgosStatus::OK;
}

bool GraphicalConsole::canPrint()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sGlyphOffsets;
}

void GraphicalConsole::printChar(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs

    COMMON_ASSERT(sTextImage, "sTextImage is null");



    if (ch == '\n')
    {
        newLineWithoutCaretReturn();
    }
    else
    if (ch == '\r')
    {
        sPositionX = 0;
    }
    else
    {
        if (ch >= 0x20 && ch < 0x7F)
        {
            GlyphData *glyphData = (GlyphData *)((u64)sGlyphOffsets + sGlyphOffsets[ch - 0x20]);



            if (sPositionX + glyphData->width > sTextImage->width)
            {
                newLine();
            }



            i16 charPosX      = sPositionX + glyphData->bitmapLeft;
            i16 charPosY      = sTextImage->height - BOTTOM_MARGIN - glyphData->bitmapTop;
            u8 *bitmapByte    = glyphData->bitmap;

            COMMON_TEST_ASSERT(charPosX >= 0);
            COMMON_TEST_ASSERT(charPosY + glyphData->bitmapHeight <= sTextImage->height);
            COMMON_TEST_ASSERT(glyphData->bitmapHeight <= CHAR_HEIGHT);



            for (i64 i = 0; i < glyphData->bitmapHeight; ++i)
            {
                for (i64 j = 0; j < glyphData->bitmapWidth; ++j)
                {
                    RgbaPixel *pixel = (RgbaPixel *)((u64)sTextImage->data + ((charPosY + i) * sTextImage->width + charPosX + j) * sizeof(RgbaPixel));

                    COMMON_TEST_ASSERT(
                        (u64)pixel >= (u64)sTextImage->data + sTextImage->width * (sTextImage->height - CHAR_HEIGHT) * sizeof(RgbaPixel)
                        &&
                        (u64)pixel <  (u64)sTextImage->data + sTextImage->width * sTextImage->height * sizeof(RgbaPixel) - 3
                    );



                    u8 greyColor = *bitmapByte;

                    pixel->red   = greyColor;
                    pixel->green = greyColor;
                    pixel->blue  = greyColor;
                    pixel->alpha = 0xFF;

                    ++bitmapByte;
                }
            }

            sPositionX += glyphData->width;
        }
        else
        {
            COMMON_LW(("Non-printable character found: 0x%02X", (u8)ch));
        }
    }
}

void GraphicalConsole::newLineWithoutCaretReturn()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs

    COMMON_ASSERT(sTextImage, "sTextImage is null");



    u32 lineByteSize = sTextImage->width * CHAR_HEIGHT        * sizeof(RgbaPixel);
    u64 bufferSize   = sTextImage->width * sTextImage->height * sizeof(RgbaPixel);

    memcpy((void *)sTextImage->data, (void *)(sTextImage->data + lineByteSize), bufferSize - lineByteSize);
    memzero((void *)(sTextImage->data + bufferSize - lineByteSize), lineByteSize);
}

void GraphicalConsole::newLine()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    newLineWithoutCaretReturn();

    sPositionX = 0;
}

void GraphicalConsole::repaint()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs

    COMMON_ASSERT(sTextImage, "sTextImage is null");



    Image *resizedImage = sConsoleWidget->getResizedImage();
    Image *resultImage  = sConsoleWidget->getResultImage();

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(resizedImage->data, resultImage->data, resizedImage->width, resizedImage->height, resultImage->width, resultImage->height, resizedImage->hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel), resultImage->hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel), true,  0, 0));
    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(sTextImage->data,   resultImage->data, sTextImage->width,   sTextImage->height,   resultImage->width, resultImage->height, sTextImage->hasAlpha   ? sizeof(RgbaPixel) : sizeof(RgbPixel), resultImage->hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel), false, 0, 0));

    COMMON_ASSERT_EXECUTION(sConsoleWidget->update());
}
