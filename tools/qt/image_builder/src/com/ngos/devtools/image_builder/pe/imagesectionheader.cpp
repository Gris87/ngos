#include "imagesectionheader.h"

#include <src/com/ngos/devtools/shared/console/console.h>



void ImageSectionHeader::print()
{
    Console::out("Image Section Header:");

    Console::out(QString("    name:                 %1").arg(name));
    Console::out(QString("    misc.virtualSize:     0x%1").arg(misc.virtualSize,     8, 16, QChar('0')));
    Console::out(QString("    virtualAddress:       0x%1").arg(virtualAddress,       8, 16, QChar('0')));
    Console::out(QString("    sizeOfRawData:        0x%1").arg(sizeOfRawData,        8, 16, QChar('0')));
    Console::out(QString("    pointerToRawData:     0x%1").arg(pointerToRawData,     8, 16, QChar('0')));
    Console::out(QString("    pointerToRelocations: 0x%1").arg(pointerToRelocations, 8, 16, QChar('0')));
    Console::out(QString("    pointerToLinenumbers: 0x%1").arg(pointerToLinenumbers, 8, 16, QChar('0')));
    Console::out(QString("    numberOfRelocations:  0x%1").arg(numberOfRelocations,  4, 16, QChar('0')));
    Console::out(QString("    numberOfLineNumbers:  0x%1").arg(numberOfLineNumbers,  4, 16, QChar('0')));
    Console::out(QString("    characteristics:      0x%1").arg(characteristics,      8, 16, QChar('0')));

    Console::out("");
}

bool ImageSectionHeader::verify()
{
    if (QString(name) == ".reloc")
    {
        if (misc.virtualSize <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 misc.virtualSize: 0x%2").arg(name).arg(misc.virtualSize, 8, 16, QChar('0')));

            return false;
        }

        if (virtualAddress <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 virtualAddress: 0x%2").arg(name).arg(virtualAddress, 8, 16, QChar('0')));

            return false;
        }

        if (sizeOfRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 sizeOfRawData: 0x%2").arg(name).arg(sizeOfRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRawData: 0x%2").arg(name).arg(pointerToRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRelocations: 0x%2").arg(name).arg(pointerToRelocations, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToLinenumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToLinenumbers: 0x%2").arg(name).arg(pointerToLinenumbers, 8, 16, QChar('0')));

            return false;
        }

        if (numberOfRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfRelocations: 0x%2").arg(name).arg(numberOfRelocations, 4, 16, QChar('0')));

            return false;
        }

        if (numberOfLineNumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfLineNumbers: 0x%2").arg(name).arg(numberOfLineNumbers, 4, 16, QChar('0')));

            return false;
        }

        if (
            characteristics != (IMAGE_SCN_MEM_READ
                                | IMAGE_SCN_MEM_DISCARDABLE
                                | IMAGE_SCN_ALIGN_1BYTES
                                | IMAGE_SCN_CNT_INITIALIZED_DATA)
           )
        {
            Console::err(QString("Wrong Image Section Header %1 characteristics: 0x%2").arg(name).arg(characteristics, 8, 16, QChar('0')));

            return false;
        }
    }
    else
    if (QString(name) == ".config")
    {
        if (misc.virtualSize <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 misc.virtualSize: 0x%2").arg(name).arg(misc.virtualSize, 8, 16, QChar('0')));

            return false;
        }

        if (virtualAddress <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 virtualAddress: 0x%2").arg(name).arg(virtualAddress, 8, 16, QChar('0')));

            return false;
        }

        if (sizeOfRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 sizeOfRawData: 0x%2").arg(name).arg(sizeOfRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRawData: 0x%2").arg(name).arg(pointerToRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRelocations: 0x%2").arg(name).arg(pointerToRelocations, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToLinenumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToLinenumbers: 0x%2").arg(name).arg(pointerToLinenumbers, 8, 16, QChar('0')));

            return false;
        }

        if (numberOfRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfRelocations: 0x%2").arg(name).arg(numberOfRelocations, 4, 16, QChar('0')));

            return false;
        }

        if (numberOfLineNumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfLineNumbers: 0x%2").arg(name).arg(numberOfLineNumbers, 4, 16, QChar('0')));

            return false;
        }

        if (
            characteristics != (IMAGE_SCN_MEM_READ
                                | IMAGE_SCN_MEM_EXECUTE
                                | IMAGE_SCN_ALIGN_16BYTES
                                | IMAGE_SCN_CNT_CODE)
           )
        {
            Console::err(QString("Wrong Image Section Header %1 characteristics: 0x%2").arg(name).arg(characteristics, 8, 16, QChar('0')));

            return false;
        }
    }
    else
    if (QString(name) == ".kernel")
    {
        if (misc.virtualSize <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 misc.virtualSize: 0x%2").arg(name).arg(misc.virtualSize, 8, 16, QChar('0')));

            return false;
        }

        if (virtualAddress <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 virtualAddress: 0x%2").arg(name).arg(virtualAddress, 8, 16, QChar('0')));

            return false;
        }

        if (sizeOfRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 sizeOfRawData: 0x%2").arg(name).arg(sizeOfRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRawData: 0x%2").arg(name).arg(pointerToRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRelocations: 0x%2").arg(name).arg(pointerToRelocations, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToLinenumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToLinenumbers: 0x%2").arg(name).arg(pointerToLinenumbers, 8, 16, QChar('0')));

            return false;
        }

        if (numberOfRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfRelocations: 0x%2").arg(name).arg(numberOfRelocations, 4, 16, QChar('0')));

            return false;
        }

        if (numberOfLineNumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfLineNumbers: 0x%2").arg(name).arg(numberOfLineNumbers, 4, 16, QChar('0')));

            return false;
        }

        if (
            characteristics != (IMAGE_SCN_MEM_READ
                                | IMAGE_SCN_MEM_EXECUTE
                                | IMAGE_SCN_ALIGN_1BYTES
                                | IMAGE_SCN_CNT_CODE)
           )
        {
            Console::err(QString("Wrong Image Section Header %1 characteristics: 0x%2").arg(name).arg(characteristics, 8, 16, QChar('0')));

            return false;
        }
    }
    else
    if (QString(name) == ".text")
    {
        if (misc.virtualSize <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 misc.virtualSize: 0x%2").arg(name).arg(misc.virtualSize, 8, 16, QChar('0')));

            return false;
        }

        if (virtualAddress <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 virtualAddress: 0x%2").arg(name).arg(virtualAddress, 8, 16, QChar('0')));

            return false;
        }

        if (sizeOfRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 sizeOfRawData: 0x%2").arg(name).arg(sizeOfRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRawData <= 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRawData: 0x%2").arg(name).arg(pointerToRawData, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToRelocations: 0x%2").arg(name).arg(pointerToRelocations, 8, 16, QChar('0')));

            return false;
        }

        if (pointerToLinenumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 pointerToLinenumbers: 0x%2").arg(name).arg(pointerToLinenumbers, 8, 16, QChar('0')));

            return false;
        }

        if (numberOfRelocations != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfRelocations: 0x%2").arg(name).arg(numberOfRelocations, 4, 16, QChar('0')));

            return false;
        }

        if (numberOfLineNumbers != 0)
        {
            Console::err(QString("Wrong Image Section Header %1 numberOfLineNumbers: 0x%2").arg(name).arg(numberOfLineNumbers, 4, 16, QChar('0')));

            return false;
        }

        if (
            characteristics != (IMAGE_SCN_MEM_READ
                                | IMAGE_SCN_MEM_EXECUTE
                                | IMAGE_SCN_ALIGN_16BYTES
                                | IMAGE_SCN_CNT_CODE)
           )
        {
            Console::err(QString("Wrong Image Section Header %1 characteristics: 0x%2").arg(name).arg(characteristics, 8, 16, QChar('0')));

            return false;
        }
    }
    else
    {
        Console::err(QString("Wrong Image Section Header name: %1").arg(name));

        return false;
    }

    return true;
}
