#include "graphicalconsole.h"

#include <com/ngos/shared/common/assets/assets.h>
#include <com/ngos/shared/common/console/lib/glyphdata.h>
#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/graphics/rgbpixel.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/gui/widgets/misc/consolewidget.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/printf/printf.h>



#define CHAR_HEIGHT   20
#define SIDE_MARGIN   1
#define BOTTOM_MARGIN 5



ConsoleWidget *GraphicalConsole::sConsoleWidget;
Image         *GraphicalConsole::sTextImage;
bad_uint16            GraphicalConsole::sPositionX;
bad_uint16            GraphicalConsole::sPaddingLeft;
bad_uint16            GraphicalConsole::sPaddingTop;
bad_uint16           *GraphicalConsole::sGlyphOffsets;



NgosStatus GraphicalConsole::init()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    if (!sConsoleWidget)
    {
        bad_uint16 *temp     = sGlyphOffsets; // To avoid infinite loop
        sGlyphOffsets = 0;             // To avoid infinite loop



        ScreenWidget *screenWidget = GUI::getMainScreenWidget();
        bad_uint64           screenWidth  = screenWidget->getWidth();
        bad_uint64           screenHeight = screenWidget->getHeight();

        bad_int64 consolePositionX = screenWidth  * GRAPHICAL_CONSOLE_POSITION_X_PERCENT / 100;
        bad_int64 consolePositionY = screenHeight * GRAPHICAL_CONSOLE_POSITION_Y_PERCENT / 100;
        bad_uint64 consoleWidth     = screenWidth  * GRAPHICAL_CONSOLE_WIDTH_PERCENT      / 100;
        bad_uint64 consoleHeight    = screenHeight * GRAPHICAL_CONSOLE_HEIGHT_PERCENT     / 100;



        AssetEntry *asset = Assets::getAssetEntry("images/console.9.png");
        COMMON_TEST_ASSERT(asset != 0, NgosStatus::ASSERTION);

        Image *consoleImage;
        COMMON_ASSERT_EXECUTION(Graphics::loadImage(asset->content, asset->contentSize, true, &consoleImage), NgosStatus::ASSERTION);



        sConsoleWidget = new ConsoleWidget(consoleImage, screenWidget);

        COMMON_ASSERT_EXECUTION(sConsoleWidget->setPosition(consolePositionX, consolePositionY), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(sConsoleWidget->setSize(consoleWidth, consoleHeight),            NgosStatus::ASSERTION);



        NinePatch *patch = consoleImage->getNinePatch();

        sPaddingLeft      = patch->getPaddingLeft();
        sPaddingTop       = patch->getPaddingTop();
        bad_uint16 paddingRight  = patch->getPaddingRight();
        bad_uint16 paddingBottom = patch->getPaddingBottom();



        sTextImage = new Image(consoleWidth - sPaddingLeft - paddingRight, consoleHeight - sPaddingTop - paddingBottom, true, false);
        COMMON_ASSERT_EXECUTION(sTextImage->clearBuffer(), NgosStatus::ASSERTION);



        sGlyphOffsets = temp; // To avoid infinite loop
    }



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::readyToPrint()
{
    COMMON_LT((""));



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);



    sPositionX    = SIDE_MARGIN;
    sGlyphOffsets = (bad_uint16 *)asset->content;



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::print(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs

    COMMON_ASSERT(sTextImage, "sTextImage is null", NgosStatus::ASSERTION);



    if (ch == '\n')
    {
        COMMON_ASSERT_EXECUTION(newLineWithoutCaretReturn(), NgosStatus::ASSERTION);
    }
    else
    if (ch == '\r')
    {
        sPositionX = SIDE_MARGIN;
    }
    else
    if (ch >= 0x20 && ch < 0x7F)
    {
        GlyphData *glyphData = (GlyphData *)((bad_uint64)sGlyphOffsets + sGlyphOffsets[ch - 0x20]);



        if (sPositionX + glyphData->width > sTextImage->getWidth() - SIDE_MARGIN)
        {
            COMMON_ASSERT_EXECUTION(newLine(), NgosStatus::ASSERTION);
        }



        bad_int16  charPosX   = sPositionX + glyphData->bitmapLeft;
        bad_int16  charPosY   = sTextImage->getHeight() - BOTTOM_MARGIN - glyphData->bitmapTop;
        bad_uint8  *bitmapByte = glyphData->bitmap;

        COMMON_TEST_ASSERT(charPosX                           >= 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(charPosX + glyphData->bitmapWidth  <= sTextImage->getWidth(),  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(charPosY                           >= 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(charPosY + glyphData->bitmapHeight <= sTextImage->getHeight(), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(glyphData->bitmapHeight            <= CHAR_HEIGHT,             NgosStatus::ASSERTION);



        for (bad_int64 i = 0; i < glyphData->bitmapHeight; ++i)
        {
            for (bad_int64 j = 0; j < glyphData->bitmapWidth; ++j)
            {
                RgbaPixel *pixel = &sTextImage->getRgbaBuffer()[(charPosY + i) * sTextImage->getWidth() + charPosX + j];

                COMMON_TEST_ASSERT((bad_uint64)pixel >= (bad_uint64)sTextImage->getBuffer() + sTextImage->getBufferSize() - (CHAR_HEIGHT + BOTTOM_MARGIN) * sTextImage->getStride()
                                    &&
                                    (bad_uint64)pixel <= (bad_uint64)sTextImage->getBuffer() + sTextImage->getBufferSize() - sizeof(RgbaPixel), NgosStatus::ASSERTION);



                pixel->red   = 0xFF;
                pixel->green = 0xFF;
                pixel->blue  = 0xFF;
                pixel->alpha = *bitmapByte;

                ++bitmapByte;
            }
        }

        sPositionX += glyphData->width;
    }
    else
    {
        COMMON_LW(("Non-printable character found: 0x%02X", (bad_uint8)ch));

        return NgosStatus::UNEXPECTED_BEHAVIOUR;
    }



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::print(const char8 *str)
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

NgosStatus GraphicalConsole::println()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(newLine(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::println(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(print(ch), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(newLine(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::println(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(print(str), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(newLine(),  NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::noMorePrint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(sGlyphOffsets, NgosStatus::ASSERTION);

    sGlyphOffsets = nullptr;



    if (sConsoleWidget)
    {
        COMMON_TEST_ASSERT(sTextImage, NgosStatus::ASSERTION);



        COMMON_ASSERT_EXECUTION(GUI::getMainScreenWidget()->getChildren().remove(sConsoleWidget), NgosStatus::ASSERTION);

        delete sConsoleWidget->getPanelImage();
        delete sConsoleWidget;
        delete sTextImage;



        sConsoleWidget = nullptr;
        sTextImage     = nullptr;
    }



    return NgosStatus::OK;
}

bool GraphicalConsole::canPrint()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sGlyphOffsets;
}

NgosStatus GraphicalConsole::newLineWithoutCaretReturn()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs

    COMMON_ASSERT(sTextImage, "sTextImage is null", NgosStatus::ASSERTION);



    Image *ownResultImage = sConsoleWidget->getOwnResultImage();
    Image *resultImage    = sConsoleWidget->getResultImage();

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                ownResultImage->getBuffer(),
                                resultImage->getBuffer(),
                                ownResultImage->getWidth(),
                                ownResultImage->getHeight(),
                                resultImage->getWidth(),
                                resultImage->getHeight(),
                                ownResultImage->getBytesPerPixel(),
                                resultImage->getBytesPerPixel(),
                                true,
                                0, 0,
                                sPaddingLeft,
                                sPaddingTop,
                                sPaddingLeft + sTextImage->getWidth(),
                                sPaddingTop + sTextImage->getHeight()),
                            NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                sTextImage->getBuffer(),
                                resultImage->getBuffer(),
                                sTextImage->getWidth(),
                                sTextImage->getHeight(),
                                resultImage->getWidth(),
                                resultImage->getHeight(),
                                sTextImage->getBytesPerPixel(),
                                resultImage->getBytesPerPixel(),
                                false,
                                sPaddingLeft,
                                sPaddingTop),
                            NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(sConsoleWidget->update(sPaddingLeft, sPaddingTop, sTextImage->getWidth(), sTextImage->getHeight()), NgosStatus::ASSERTION);



    bad_uint32 lineByteSize = (CHAR_HEIGHT + BOTTOM_MARGIN) * sTextImage->getStride();

    memcpy((void *)sTextImage->getBuffer(), (void *)(sTextImage->getBuffer() + lineByteSize), sTextImage->getBufferSize() - lineByteSize);
    memzero((void *)(sTextImage->getBuffer() + sTextImage->getBufferSize() - lineByteSize), lineByteSize);



    return NgosStatus::OK;
}

NgosStatus GraphicalConsole::newLine()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(newLineWithoutCaretReturn(), NgosStatus::ASSERTION);

    sPositionX = SIDE_MARGIN;



    return NgosStatus::OK;
}
