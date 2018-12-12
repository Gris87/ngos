#include "datadirectory.h"

#include <console/console.h>



void DataDirectory::print()
{
    Console::out("Data Directory:");

    Console::out(QString("    virtualAddress: 0x%1").arg(virtualAddress, 8, 16, QChar('0')));
    Console::out(QString("    size:           0x%1").arg(size,           8, 16, QChar('0')));

    Console::out("");
}

bool DataDirectory::verify()
{
    if (virtualAddress) // virtualAddress != 0
    {
        Console::err(QString("Wrong Data Directory virtualAddress: 0x%1").arg(virtualAddress, 8, 16, QChar('0')));

        return false;
    }

    if (size) // size != 0
    {
        Console::err(QString("Wrong Data Directory size: 0x%1").arg(size, 8, 16, QChar('0')));

        return false;
    }

    return true;
}
