#include "peheader.h"

#include <console/console.h>



void PEHeader::print()
{
    Console::out("PE Header:");

    // Ignore CppAlignmentVerifier [BEGIN]
    Console::out(QString("    signature: 0x%1 (%2%3\\%4\\%5)")
                    .arg(       signature,              8, 16, QChar('0'))
                    .arg((char)(signature       & 0xFF))
                    .arg((char)(signature >> 8  & 0xFF))
                    .arg(       signature >> 16 & 0xFF, 0, 16, QChar('0'))
                    .arg(       signature >> 24 & 0xFF, 0, 16, QChar('0'))
                );
    // Ignore CppAlignmentVerifier [END]

    Console::out("");



    coffHeader.print();
    optHeader.print();

    for (qint64 i = 0; i < NUMBER_OF_SECTIONS; ++i)
    {
        if (QString(sections[i].name) != "")
        {
            sections[i].print();
        }
    }
}

bool PEHeader::verify()
{
    if (signature != PE_HEADER_SIGNATURE)
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        Console::err(QString("Wrong PE Header signature: 0x%1 (%2%3\\%4\\%5)")
                        .arg(       signature,              8, 16, QChar('0'))
                        .arg((char)(signature       & 0xFF))
                        .arg((char)(signature >> 8  & 0xFF))
                        .arg(       signature >> 16 & 0xFF, 0, 16, QChar('0'))
                        .arg(       signature >> 24 & 0xFF, 0, 16, QChar('0'))
                    );
        // Ignore CppAlignmentVerifier [END]

        return false;
    }

    if (!coffHeader.verify())
    {
        return false;
    }

    if (!optHeader.verify())
    {
        return false;
    }

    for (qint64 i = 0; i < NUMBER_OF_SECTIONS; ++i)
    {
        if (QString(sections[i].name) != "")
        {
            if (!sections[i].verify())
            {
                return false;
            }
        }
    }

    return true;
}
