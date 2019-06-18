#include "coffheader.h"

#include <console/console.h>

#include "src/pe/peoptheader.h"



void COFFHeader::print()
{
    Console::out("COFF Header:");

    Console::out(QString("    machine:              0x%1").arg(machine,              4, 16, QChar('0')));
    Console::out(QString("    numberOfSections:     0x%1").arg(numberOfSections,     4, 16, QChar('0')));
    Console::out(QString("    timeDateStamp:        0x%1").arg(timeDateStamp,        8, 16, QChar('0')));
    Console::out(QString("    pointerToSymbolTable: 0x%1").arg(pointerToSymbolTable, 8, 16, QChar('0')));
    Console::out(QString("    numberOfSymbols:      0x%1").arg(numberOfSymbols,      8, 16, QChar('0')));
    Console::out(QString("    sizeOfOptionalHeader: 0x%1").arg(sizeOfOptionalHeader, 4, 16, QChar('0')));
    Console::out(QString("    characteristics:      0x%1").arg(characteristics,      4, 16, QChar('0')));

    Console::out("");
}

bool COFFHeader::verify()
{
    if (machine != IMAGE_MACHINE_X64)
    {
        Console::err(QString("Wrong COFF Header machine: 0x%1").arg(machine, 4, 16, QChar('0')));

        return false;
    }

    if (
        numberOfSections != NUMBER_OF_SECTIONS
        &&
        numberOfSections != NUMBER_OF_SECTIONS - 1
       )
    {
        Console::err(QString("Wrong COFF Header numberOfSections: 0x%1").arg(numberOfSections, 4, 16, QChar('0')));

        return false;
    }

    if (timeDateStamp) // timeDateStamp != 0
    {
        Console::err(QString("Wrong COFF Header timeDateStamp: 0x%1").arg(timeDateStamp, 8, 16, QChar('0')));

        return false;
    }

    if (pointerToSymbolTable) // pointerToSymbolTable != 0
    {
        Console::err(QString("Wrong COFF Header pointerToSymbolTable: 0x%1").arg(pointerToSymbolTable, 8, 16, QChar('0')));

        return false;
    }

    if (numberOfSymbols) // numberOfSymbols != 0
    {
        Console::err(QString("Wrong COFF Header numberOfSymbols: 0x%1").arg(numberOfSymbols, 8, 16, QChar('0')));

        return false;
    }

    if (sizeOfOptionalHeader != sizeof(PEOptHeader))
    {
        Console::err(QString("Wrong COFF Header sizeOfOptionalHeader: 0x%1").arg(sizeOfOptionalHeader, 4, 16, QChar('0')));

        return false;
    }

    if (
        characteristics != (IMAGE_FILE_DEBUG_STRIPPED
                            | IMAGE_FILE_LINE_NUMS_STRIPPED
                            | IMAGE_FILE_EXECUTABLE_IMAGE)
       )
    {
        Console::err(QString("Wrong COFF Header characteristics: 0x%1").arg(characteristics, 4, 16, QChar('0')));

        return false;
    }

    return true;
}
