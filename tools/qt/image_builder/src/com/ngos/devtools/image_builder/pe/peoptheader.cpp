#include "peoptheader.h"

#include <src/com/ngos/devtools/shared/console/console.h>



void PEOptHeader::print()
{
    Console::out("PE Optional Header:");
    Console::out(QString("    signature:               0x%1").arg(signature,               4,  16, QChar('0')));
    Console::out(QString("    majorLinkerVersion:      0x%1").arg(majorLinkerVersion,      2,  16, QChar('0')));
    Console::out(QString("    minorLinkerVersion:      0x%1").arg(minorLinkerVersion,      2,  16, QChar('0')));
    Console::out(QString("    sizeOfCode:              0x%1").arg(sizeOfCode,              8,  16, QChar('0')));
    Console::out(QString("    sizeOfInitializedData:   0x%1").arg(sizeOfInitializedData,   8,  16, QChar('0')));
    Console::out(QString("    sizeOfUninitializedData: 0x%1").arg(sizeOfUninitializedData, 8,  16, QChar('0')));
    Console::out(QString("    addressOfEntryPoint:     0x%1").arg(addressOfEntryPoint,     8,  16, QChar('0')));
    Console::out(QString("    baseOfCode:              0x%1").arg(baseOfCode,              8,  16, QChar('0')));
    Console::out(QString("    imageBase:               0x%1").arg(imageBase,               16, 16, QChar('0')));
    Console::out(QString("    sectionAlignment:        0x%1").arg(sectionAlignment,        8,  16, QChar('0')));
    Console::out(QString("    fileAlignment:           0x%1").arg(fileAlignment,           8,  16, QChar('0')));
    Console::out(QString("    majorOSVersion:          0x%1").arg(majorOSVersion,          4,  16, QChar('0')));
    Console::out(QString("    minorOSVersion:          0x%1").arg(minorOSVersion,          4,  16, QChar('0')));
    Console::out(QString("    majorImageVersion:       0x%1").arg(majorImageVersion,       4,  16, QChar('0')));
    Console::out(QString("    minorImageVersion:       0x%1").arg(minorImageVersion,       4,  16, QChar('0')));
    Console::out(QString("    majorSubsystemVersion:   0x%1").arg(majorSubsystemVersion,   4,  16, QChar('0')));
    Console::out(QString("    minorSubsystemVersion:   0x%1").arg(minorSubsystemVersion,   4,  16, QChar('0')));
    Console::out(QString("    win32VersionValue:       0x%1").arg(win32VersionValue,       8,  16, QChar('0')));
    Console::out(QString("    sizeOfImage:             0x%1").arg(sizeOfImage,             8,  16, QChar('0')));
    Console::out(QString("    sizeOfHeaders:           0x%1").arg(sizeOfHeaders,           8,  16, QChar('0')));
    Console::out(QString("    checksum:                0x%1").arg(checksum,                8,  16, QChar('0')));
    Console::out(QString("    subsystem:               0x%1").arg(subsystem,               4,  16, QChar('0')));
    Console::out(QString("    dllCharacteristics:      0x%1").arg(dllCharacteristics,      4,  16, QChar('0')));
    Console::out(QString("    sizeOfStackReserve:      0x%1").arg(sizeOfStackReserve,      16, 16, QChar('0')));
    Console::out(QString("    sizeOfStackCommit:       0x%1").arg(sizeOfStackCommit,       16, 16, QChar('0')));
    Console::out(QString("    sizeOfHeapReserve:       0x%1").arg(sizeOfHeapReserve,       16, 16, QChar('0')));
    Console::out(QString("    sizeOfHeapCommit:        0x%1").arg(sizeOfHeapCommit,        16, 16, QChar('0')));
    Console::out(QString("    loaderFlags:             0x%1").arg(loaderFlags,             8,  16, QChar('0')));
    Console::out(QString("    numberOfRvaAndSizes:     0x%1").arg(numberOfRvaAndSizes,     8,  16, QChar('0')));
    Console::out("");



    for (qint64 i = 0; i < NUMBER_OF_RVA_AND_SIZES; ++i)
    {
        dataDirectories[i].print();
    }
}

bool PEOptHeader::verify()
{
    if (signature != IMAGE_NT_OPTIONAL_HDR64_MAGIC)
    {
        Console::err(QString("Wrong PE Optional Header signature: 0x%1").arg(signature, 4, 16, QChar('0')));

        return false;
    }

    if (majorLinkerVersion != 0x0E)
    {
        Console::err(QString("Wrong PE Optional Header majorLinkerVersion: 0x%1").arg(majorLinkerVersion, 2, 16, QChar('0')));

        return false;
    }

    if (minorLinkerVersion != 0x0A)
    {
        Console::err(QString("Wrong PE Optional Header minorLinkerVersion: 0x%1").arg(minorLinkerVersion, 2, 16, QChar('0')));

        return false;
    }

    if (sizeOfCode != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfCode: 0x%1").arg(sizeOfCode, 8, 16, QChar('0')));

        return false;
    }

    if (sizeOfInitializedData != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfInitializedData: 0x%1").arg(sizeOfInitializedData, 8, 16, QChar('0')));

        return false;
    }

    if (sizeOfUninitializedData != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfUninitializedData: 0x%1").arg(sizeOfUninitializedData, 8, 16, QChar('0')));

        return false;
    }

    if (addressOfEntryPoint <= 0)
    {
        Console::err(QString("Wrong PE Optional Header addressOfEntryPoint: 0x%1").arg(addressOfEntryPoint, 8, 16, QChar('0')));

        return false;
    }

    if (baseOfCode != 0)
    {
        Console::err(QString("Wrong PE Optional Header baseOfCode: 0x%1").arg(baseOfCode, 8, 16, QChar('0')));

        return false;
    }

    if (imageBase != 0)
    {
        Console::err(QString("Wrong PE Optional Header imageBase: 0x%1").arg(imageBase, 16, 16, QChar('0')));

        return false;
    }

    if (sectionAlignment != 0x40)
    {
        Console::err(QString("Wrong PE Optional Header sectionAlignment: 0x%1").arg(sectionAlignment, 8, 16, QChar('0')));

        return false;
    }

    if (fileAlignment != 0x40)
    {
        Console::err(QString("Wrong PE Optional Header fileAlignment: 0x%1").arg(fileAlignment, 8, 16, QChar('0')));

        return false;
    }

    if (majorOSVersion != 0)
    {
        Console::err(QString("Wrong PE Optional Header majorOSVersion: 0x%1").arg(majorOSVersion, 4, 16, QChar('0')));

        return false;
    }

    if (minorOSVersion != 0)
    {
        Console::err(QString("Wrong PE Optional Header minorOSVersion: 0x%1").arg(minorOSVersion, 4, 16, QChar('0')));

        return false;
    }

    if (majorImageVersion != 0)
    {
        Console::err(QString("Wrong PE Optional Header majorImageVersion: 0x%1").arg(majorImageVersion, 4, 16, QChar('0')));

        return false;
    }

    if (minorImageVersion != 0)
    {
        Console::err(QString("Wrong PE Optional Header minorImageVersion: 0x%1").arg(minorImageVersion, 4, 16, QChar('0')));

        return false;
    }

    if (majorSubsystemVersion != 0)
    {
        Console::err(QString("Wrong PE Optional Header majorSubsystemVersion: 0x%1").arg(majorSubsystemVersion, 4, 16, QChar('0')));

        return false;
    }

    if (minorSubsystemVersion != 0)
    {
        Console::err(QString("Wrong PE Optional Header minorSubsystemVersion: 0x%1").arg(minorSubsystemVersion, 4, 16, QChar('0')));

        return false;
    }

    if (win32VersionValue != 0)
    {
        Console::err(QString("Wrong PE Optional Header win32VersionValue: 0x%1").arg(win32VersionValue, 8, 16, QChar('0')));

        return false;
    }

    if (sizeOfImage <= 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfImage: 0x%1").arg(sizeOfImage, 8, 16, QChar('0')));

        return false;
    }

    if (sizeOfHeaders != 0x0200)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfHeaders: 0x%1").arg(sizeOfHeaders, 8, 16, QChar('0')));

        return false;
    }

    if (checksum != 0)
    {
        Console::err(QString("Wrong PE Optional Header checksum: 0x%1").arg(checksum, 8, 16, QChar('0')));

        return false;
    }

    if (subsystem != IMAGE_SUBSYSTEM_UEFI_APPLICATION)
    {
        Console::err(QString("Wrong PE Optional Header subsystem: 0x%1").arg(subsystem, 4, 16, QChar('0')));
        return false;
    }

    if (dllCharacteristics != 0)
    {
        Console::err(QString("Wrong PE Optional Header dllCharacteristics: 0x%1").arg(dllCharacteristics, 4, 16, QChar('0')));

        return false;
    }

    if (sizeOfStackReserve != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfStackReserve: 0x%1").arg(sizeOfStackReserve, 16, 16, QChar('0')));

        return false;
    }

    if (sizeOfStackCommit != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfStackCommit: 0x%1").arg(sizeOfStackCommit, 16, 16, QChar('0')));

        return false;
    }

    if (sizeOfHeapReserve != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfHeapReserve: 0x%1").arg(sizeOfHeapReserve, 16, 16, QChar('0')));

        return false;
    }

    if (sizeOfHeapCommit != 0)
    {
        Console::err(QString("Wrong PE Optional Header sizeOfHeapCommit: 0x%1").arg(sizeOfHeapCommit, 16, 16, QChar('0')));

        return false;
    }

    if (loaderFlags != 0)
    {
        Console::err(QString("Wrong PE Optional Header loaderFlags: 0x%1").arg(loaderFlags, 8, 16, QChar('0')));

        return false;
    }

    if (numberOfRvaAndSizes != NUMBER_OF_RVA_AND_SIZES)
    {
        Console::err(QString("Wrong PE Optional Header numberOfRvaAndSizes: 0x%1").arg(numberOfRvaAndSizes, 8, 16, QChar('0')));

        return false;
    }



    for (qint64 i = 0; i < NUMBER_OF_RVA_AND_SIZES; ++i)
    {
        if (!dataDirectories[i].verify())
        {
            return false;
        }
    }

    return true;
}
