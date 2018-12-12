#include "elfobject.h"

#include <QDebug>
#include <QFile>



ElfObject::ElfObject()
    : mBytes()
    , mHeader(0)
    , mProgramHeaderTableEntries()
    , mSectionHeaderTableEntries()
    , mProgramBytes()
    , mMemorySize(0)
    , mNameToSectionMap()
    , mNameToSymbolMap()
{
    // Nothing
}

bool ElfObject::read(const QString &path, bool *isRunning)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    while (!file.atEnd() && (!isRunning || *isRunning))
    {
        mBytes.append(file.read(4096));
    }

    file.close();



    if (isRunning && !(*isRunning))
    {
        return true;
    }



    if (mBytes.length() < (qint64)sizeof(*mHeader))
    {
        qDebug() << "File is too small";

        return false;
    }

    mHeader = (ElfHeader *)mBytes.data();



    if (!verifyHeader())
    {
        qDebug() << "ELF Header is invalid";

        return false;
    }



    if (isRunning && !(*isRunning))
    {
        return true;
    }



    for (qint64 i = 0; i < mHeader->programHeaderTableEntryCount; ++i)
    {
        mProgramHeaderTableEntries.append((ElfProgramHeaderTableEntry *)((quint64)mBytes.data() + mHeader->programHeaderTableOffset + i * mHeader->programHeaderTableEntrySize));
    }



    if (isRunning && !(*isRunning))
    {
        return true;
    }



    for (qint64 i = 0; i < mHeader->sectionHeaderTableEntryCount; ++i)
    {
        mSectionHeaderTableEntries.append((ElfSectionHeaderTableEntry *)((quint64)mBytes.data() + mHeader->sectionHeaderTableOffset + i * mHeader->sectionHeaderTableEntrySize));
    }



    if (isRunning && !(*isRunning))
    {
        return true;
    }



    for (qint64 i = 0; i < mProgramHeaderTableEntries.length(); ++i)
    {
        ElfProgramHeaderTableEntry *entry = mProgramHeaderTableEntries.at(i);

        mProgramBytes.append((char *)((quint64)mBytes.data() + entry->offset), entry->fileSize);
        mMemorySize += entry->memorySize;
    }



    if (isRunning && !(*isRunning))
    {
        return true;
    }



    ElfSectionHeaderTableEntry *sectionWithNames = mSectionHeaderTableEntries.at(mHeader->sectionHeaderTableNamesIndex);



    for (qint64 i = 0; i < mSectionHeaderTableEntries.length(); ++i)
    {
        ElfSectionHeaderTableEntry *entry = mSectionHeaderTableEntries.at(i);

        mNameToSectionMap.insert(QString((char *)((quint64)mBytes.data() + sectionWithNames->offset + entry->nameOffset)), entry);
    }



    if (isRunning && !(*isRunning))
    {
        return true;
    }



    ElfSectionHeaderTableEntry *stringTable  = getSection(".strtab");
    ElfSectionHeaderTableEntry *symbolsTable = getSection(".symtab");

    if (stringTable && symbolsTable)
    {
        for (qint64 i = 0; i < (qint64)symbolsTable->size; i += sizeof(ElfSymbol))
        {
            ElfSymbol *symbol = (ElfSymbol *)((quint64)mBytes.data() + symbolsTable->offset + i);

            mNameToSymbolMap.insert(QString((char *)((quint64)mBytes.data() + stringTable->offset + symbol->nameOffset)), symbol);
        }



        if (isRunning && !(*isRunning))
        {
            return true;
        }
    }



    return true;
}

const QByteArray& ElfObject::getProgramBytes() const
{
    return mProgramBytes;
}

quint64 ElfObject::getFileSize() const
{
    return mBytes.length();
}

quint64 ElfObject::getMemorySize() const
{
    return mMemorySize;
}

const QList<ElfSectionHeaderTableEntry *>& ElfObject::getSections() const
{
    return mSectionHeaderTableEntries;
}

const QHash<QString, ElfSectionHeaderTableEntry *>& ElfObject::getSectionsMap() const
{
    return mNameToSectionMap;
}

ElfSectionHeaderTableEntry* ElfObject::getSection(QString name)
{
    return mNameToSectionMap.value(name, 0);
}

const QHash<QString, ElfSymbol *>& ElfObject::getSymbolMap() const
{
    return mNameToSymbolMap;
}

ElfSymbol* ElfObject::getSymbol(QString name)
{
    return mNameToSymbolMap.value(name, 0);
}

bool ElfObject::verifyHeader()
{
    if (mHeader->identification.signature != ELF_SIGNATURE)
    {
        qDebug() << "ELF signature is invalid";

        return false;
    }



    if (mHeader->identification.fileClass != ElfClass::CLASS_64)
    {
        qDebug() << "ELF file class is invalid";

        return false;
    }



    if (mHeader->identification.fileData != ElfData::LEAST_SIGNIFICANT_BYTE)
    {
        qDebug() << "ELF file data is invalid";

        return false;
    }



    if (mHeader->identification.version != ElfFileVersion::CURRENT)
    {
        qDebug() << "ELF file version is invalid";

        return false;
    }



    if (mHeader->identification.osAbi != ElfOsAbi::SYSTEM_V)
    {
        qDebug() << "ELF OS ABI is invalid";

        return false;
    }



    if (mHeader->type != ElfType::EXECUTABLE)
    {
        qDebug() << "ELF type is invalid";

        return false;
    }



    if (mHeader->machine != ElfMachine::MACHINE_X86_64)
    {
        qDebug() << "ELF machine is invalid";

        return false;
    }



    if (mHeader->version != ElfVersion::CURRENT)
    {
        qDebug() << "ELF file version is invalid";

        return false;
    }



    if (
        mHeader->entryPoint >= (quint64)mBytes.length()
        &&
        mHeader->entryPoint != 0xFFFFFFFF80000000
       )
    {
        qDebug() << "ELF entry point is invalid";

        return false;
    }



    if (mHeader->programHeaderTableOffset >= (quint64)mBytes.length())
    {
        qDebug() << "ELF program header table offset is invalid";

        return false;
    }



    if (mHeader->sectionHeaderTableOffset >= (quint64)mBytes.length())
    {
        qDebug() << "ELF section header table offset is invalid";

        return false;
    }



    if (mHeader->flags) // mHeader->flags != 0
    {
        qDebug() << "ELF flags is invalid";

        return false;
    }



    if (mHeader->headerSize != 64 || mHeader->headerSize != sizeof(*mHeader))
    {
        qDebug() << "ELF header size is invalid";

        return false;
    }



    if (mHeader->programHeaderTableEntrySize != sizeof(ElfProgramHeaderTableEntry))
    {
        qDebug() << "ELF program header table entry size is invalid";

        return false;
    }



    if (!mHeader->programHeaderTableEntryCount) // mHeader->programHeaderTableEntryCount == 0
    {
        qDebug() << "ELF number of program header table entries is invalid";

        return false;
    }



    if (mHeader->sectionHeaderTableEntrySize != sizeof(ElfSectionHeaderTableEntry))
    {
        qDebug() << "ELF section header table entry size is invalid";

        return false;
    }



    if (!mHeader->sectionHeaderTableEntryCount) // mHeader->sectionHeaderTableEntryCount == 0
    {
        qDebug() << "ELF number of section header table entries is invalid";

        return false;
    }



    if (mHeader->sectionHeaderTableNamesIndex >= mHeader->sectionHeaderTableEntryCount)
    {
        qDebug() << "ELF index of entry with section names is invalid";

        return false;
    }



    return true;
}
