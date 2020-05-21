#include "guiglyphgenerator.h"

#include <QDataStream>
#include <QFile>
#include <console/console.h>
#include <ft2build.h>
#include FT_FREETYPE_H



#define FILE_PATH "assets/glyphs/gui.bin"

#define FONT_SIZE   50
#define START_INDEX 0x20
#define END_INDEX   0x7F



GuiGlyphGenerator::GuiGlyphGenerator()
    : AssetsGenerator()
{
    // Nothing
}

bool GuiGlyphGenerator::generate(const QString &path)
{
    QFile fontFile(":/assets/fonts/gui.ttf"); // Ignore CppPunctuationVerifier

    if (!fontFile.open(QIODevice::ReadOnly))
    {
        Console::err("Failed to open file assets/fonts/gui.ttf");

        return false;
    }

    QByteArray fontBytes = fontFile.readAll();
    fontFile.close();



    FT_Library library;
    FT_Face    face;



    FT_Error error = FT_Init_FreeType(&library);

    if (error)
    {
        Console::err(QString("Failed to initialize FreeType library. Error: %1").arg(error));

        return false;
    }



    error = FT_New_Memory_Face(library, (FT_Byte *)fontBytes.data(), fontBytes.size(), 0, &face);

    if (error)
    {
        Console::err(QString("Failed to load face from memory. Error: %1").arg(error));

        return false;
    }



    error = FT_Set_Char_Size(face, 0, FONT_SIZE * 64, 0, 0);

    if (error)
    {
        Console::err(QString("Failed to change font size. Error: %1").arg(error));

        return false;
    }



    QByteArray offsets((END_INDEX - START_INDEX) * 2, 0);



    QByteArray  glyphData;
    QDataStream glyphDataStream(&glyphData, QIODevice::WriteOnly);

    glyphDataStream.setByteOrder(QDataStream::LittleEndian);



    FT_GlyphSlot slot = face->glyph;

    for (qint64 i = START_INDEX; i < END_INDEX; ++i)
    {
        quint64 offset = offsets.size() + glyphData.size();

        if (offset > 65535)
        {
            Console::err(QString("quint16 is not enough for offsets"));

            return false;
        }

        *(quint16 *)((quint64)offsets.data() + ((i - START_INDEX) * 2)) = offset;



        FT_UInt glyphIndex = FT_Get_Char_Index(face, i);



        error = FT_Load_Glyph(face, glyphIndex, FT_LOAD_DEFAULT);

        if (error)
        {
            Console::err(QString("Failed to load glyph for char 0x%1. Error: %2").arg(i, 2, 16, QChar('0')).arg(error));

            continue;
        }



        error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

        if (error)
        {
            Console::err(QString("Failed to render glyph for char 0x%1. Error: %2").arg(i, 2, 16, QChar('0')).arg(error));

            continue;
        }



        glyphDataStream << (quint8)(slot->advance.x / 64);
        glyphDataStream << (qint8)slot->bitmap_left;
        glyphDataStream << (qint8)slot->bitmap_top;
        glyphDataStream << (quint8)slot->bitmap.width;
        glyphDataStream << (quint8)slot->bitmap.rows;
        glyphDataStream.writeRawData((char *)slot->bitmap.buffer, slot->bitmap.rows * slot->bitmap.pitch);
    }



    error = FT_Done_Face(face);

    if (error)
    {
        Console::err(QString("Failed to free face. Error: %1").arg(error));

        return false;
    }



    error = FT_Done_FreeType(library);

    if (error)
    {
        Console::err(QString("Failed to free FreeType library. Error: %1").arg(error));

        return false;
    }



    QByteArray data = offsets + glyphData;

    return save(path  + "/bootloader/"                       + FILE_PATH, data)
            &&
            save(path + "/bootloader_tools/cputest/"         + FILE_PATH, data)
            &&
            save(path + "/bootloader_tools/devicemanager/"   + FILE_PATH, data)
            &&
            save(path + "/bootloader_tools/hddtest/"         + FILE_PATH, data)
            &&
            save(path + "/bootloader_tools/memorytest/"      + FILE_PATH, data)
            &&
            save(path + "/bootloader_tools/networktest/"     + FILE_PATH, data)
            &&
            save(path + "/bootloader_tools/partitionwizard/" + FILE_PATH, data);
}



GuiGlyphGenerator guiGlyphGeneratorInstance;
