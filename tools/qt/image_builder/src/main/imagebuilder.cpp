#include "imagebuilder.h"

#include <QFile>
#include <QIODevice>
#include <buildconfig.h>
#include <console/console.h>
#include <src/bits64/other/kerneldescriptor.h>



#define RELOC_SECTION_SIZE 0x40

#define TEXT_SECTION_NAME 0x000000747865742E



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ
#define COMPRESSED_EXTENSION ".xz"
#elif NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP
#define COMPRESSED_EXTENSION ".gz"
#else
#define COMPRESSED_EXTENSION ""
#endif



ImageBuilder::ImageBuilder(const QString &bootElfPath, const QString &configureElfPath, const QString &kernelElfPath, const QString &installerElfPath, const QString &textElfPath, const QString &resultImagePath)
    : mBootElfPath(bootElfPath)
    , mConfigureElfPath(configureElfPath)
    , mKernelElfPath(kernelElfPath)
    , mInstallerElfPath(installerElfPath)
    , mTextElfPath(textElfPath)
    , mResultImagePath(resultImagePath)
    , mBootElfObject()
    , mConfigureElfObject()
    , mKernelElfObject()
    , mInstallerElfObject()
    , mKernelElf()
    , mInstallerElf()
    , mRelocSection(RELOC_SECTION_SIZE, (char)0)
    , mPEHeader(0)
    , mBootStart(-1)
    , mBootEnd(-1)
    , mRelocStart(-1)
    , mRelocEnd(-1)
    , mConfigStart(-1)
    , mConfigEnd(-1)
    , mKernelStart(-1)
    , mKernelEnd(-1)
{
    // Nothing
}

qint64 ImageBuilder::process()
{
    if (!mBootElfObject.read(mBootElfPath))
    {
        Console::err(QString("Failed to read %1 file").arg(mBootElfPath));

        return 2;
    }



    if (mTextElfPath == "")
    {
        if (!mConfigureElfObject.read(mConfigureElfPath))
        {
            Console::err(QString("Failed to read %1 file").arg(mConfigureElfPath));

            return 3;
        }



        if (mKernelElfPath != "")
        {
            if (!mKernelElfObject.read(mKernelElfPath))
            {
                Console::err(QString("Failed to read %1 file").arg(mKernelElfPath));

                return 4;
            }



            QFile file(mKernelElfPath + COMPRESSED_EXTENSION);

            if (!file.open(QIODevice::ReadOnly))
            {
                Console::err(QString("Failed to read %1 file").arg(mKernelElfPath + COMPRESSED_EXTENSION));

                return 5;
            }

            mKernelElf = file.readAll();
            file.close();
        }



        if (mInstallerElfPath != "")
        {
            if (!mInstallerElfObject.read(mInstallerElfPath))
            {
                Console::err(QString("Failed to read %1 file").arg(mInstallerElfPath));

                return 6;
            }



            QFile file(mInstallerElfPath + COMPRESSED_EXTENSION);

            if (!file.open(QIODevice::ReadOnly))
            {
                Console::err(QString("Failed to read %1 file").arg(mInstallerElfPath + COMPRESSED_EXTENSION));

                return 7;
            }

            mInstallerElf = file.readAll();
            file.close();
        }
    }
    else
    {
        if (!mConfigureElfObject.read(mTextElfPath))
        {
            Console::err(QString("Failed to read %1 file").arg(mTextElfPath));

            return 3;
        }
    }



    ElfSectionHeaderTableEntry *bssSection = mConfigureElfObject.getSection(".bss");

    if (bssSection) // bssSection != 0
    {
        if (mTextElfPath == "")
        {
            Console::err("Configure part image should not contain .bss section. Try to use __attribute__ ((section (\".noinit\"))) for your variables");
        }
        else
        {
            Console::err("Text section should not contain .bss section. Try to use __attribute__ ((section (\".noinit\"))) for your variables");
        }

        return 8;
    }



    mResultImage.append(mBootElfObject.getProgramBytes());

    mBootStart = 0;
    mBootEnd   = mResultImage.size();

    mResultImage.append(mRelocSection);

    mRelocStart = mBootEnd;
    mRelocEnd   = mResultImage.size();

    mResultImage.append(mConfigureElfObject.getProgramBytes());

    mConfigStart = mRelocEnd;
    mConfigEnd   = mResultImage.size();



    if (mTextElfPath == "")
    {
        if (mKernelElfPath != "")
        {
            KernelDescriptor kernelDescriptor;

            kernelDescriptor.imageSize   = mKernelElfObject.getFileSize();
            kernelDescriptor.contentSize = mKernelElf.size();

            mResultImage.append((char *)&kernelDescriptor, sizeof(kernelDescriptor));
            mResultImage.append(mKernelElf);
        }



        if (mInstallerElfPath != "")
        {
            KernelDescriptor kernelDescriptor;

            kernelDescriptor.imageSize   = mInstallerElfObject.getFileSize();
            kernelDescriptor.contentSize = mInstallerElf.size();

            mResultImage.append((char *)&kernelDescriptor, sizeof(kernelDescriptor));
            mResultImage.append(mInstallerElf);
        }



        mKernelStart = mConfigEnd;
        mKernelEnd   = mResultImage.size();
    }



    if (
        readUInt16(0)      != 0x5A4D // MZ
        ||
        readUInt16(0x01FE) != 0xAA55 // Magic number for bootsector
       )
    {
        Console::err("Invalid Boot part image");

        return 9;
    }



    qint64 peHeaderLocation = getPeHeaderLocation();

    if (peHeaderLocation < 0)
    {
        Console::err("Failed to find PE Header");

        return 10;
    }

    Console::out(QString("PE Header location: 0x%1").arg(peHeaderLocation, 8, 16, QChar('0')));

    mPEHeader = getPeHeader(peHeaderLocation);



    if (!updatePEOptHeader())
    {
        Console::err("Failed to update PE Optional Header");

        return 11;
    }



    if (!updateRelocSection())
    {
        Console::err("Failed to update .reloc section");

        return 12;
    }



    if (!updateConfigSection())
    {
        Console::err("Failed to update .config section");

        return 13;
    }



    if (!updateKernelSection())
    {
        Console::err("Failed to update .kernel section");

        return 14;
    }



    Console::out("");
    mPEHeader->print();



    if (!mPEHeader->verify())
    {
        Console::err("Invalid PE Header");

        return 15;
    }



    if (!writeResultImage())
    {
        Console::err("Failed to write disk image");

        return 16;
    }



    return 0;
}

bool ImageBuilder::writeResultImage()
{
    QFile file(mResultImagePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        Console::err(QString("Failed to open file \"%1\"").arg(mResultImagePath));

        return false;
    }

    file.write(mResultImage);
    file.close();



    return true;
}

qint64 ImageBuilder::getPeHeaderLocation()
{
    quint32 peHeaderLocation = readUInt32(0x3C);

    if (peHeaderLocation < (quint32)mResultImage.length())
    {
        if (readUInt32(peHeaderLocation) == PE_HEADER_SIGNATURE)
        {
            return peHeaderLocation;
        }
    }

    return -1;
}

PEHeader* ImageBuilder::getPeHeader(qint64 offset)
{
    return (PEHeader *)((quint64)mResultImage.data() + offset);
}

bool ImageBuilder::updatePEOptHeader()
{
    mPEHeader->optHeader.addressOfEntryPoint = mConfigStart;
    mPEHeader->optHeader.sizeOfImage         = mResultImage.size();

    return true;
}

bool ImageBuilder::updateRelocSection()
{
    quint32 offset = mRelocStart;
    quint32 size   = mRelocEnd - mRelocStart;

    writeUInt32(offset,     offset + 4);
    writeUInt32(offset + 4, 123456789);



    ImageSectionHeader &section = mPEHeader->sections[SECTION_RELOC];

    section.misc.virtualSize = size;
    section.virtualAddress   = offset;
    section.sizeOfRawData    = size;
    section.pointerToRawData = offset;



    return true;
}

bool ImageBuilder::updateConfigSection()
{
    quint32 offset = mConfigStart;
    quint32 size   = mConfigEnd - mConfigStart;



    ImageSectionHeader &section = mPEHeader->sections[SECTION_CONFIG];

    section.misc.virtualSize = size;
    section.virtualAddress   = offset;
    section.sizeOfRawData    = size;
    section.pointerToRawData = offset;



    if (mTextElfPath != "")
    {
        *((quint64 *)&section.name) = TEXT_SECTION_NAME;
    }



    return true;
}

bool ImageBuilder::updateKernelSection()
{
    ImageSectionHeader &section = mPEHeader->sections[SECTION_KERNEL];



    if (mTextElfPath == "")
    {
        quint32 offset = mKernelStart;
        quint32 size   = mKernelEnd - mKernelStart;

        section.misc.virtualSize = size;
        section.virtualAddress   = offset;
        section.sizeOfRawData    = size;
        section.pointerToRawData = offset;
    }
    else
    {
        memset(&section, 0, sizeof(ImageSectionHeader));

        --mPEHeader->coffHeader.numberOfSections;
    }



    return true;
}

quint8 ImageBuilder::readUInt8(qint64 offset)
{
    return *((quint8 *)((quint64)mResultImage.data() + offset));
}

quint16 ImageBuilder::readUInt16(qint64 offset)
{
    return *((quint16 *)((quint64)mResultImage.data() + offset));
}

quint32 ImageBuilder::readUInt32(qint64 offset)
{
    return *((quint32 *)((quint64)mResultImage.data() + offset));
}

quint64 ImageBuilder::readUInt64(qint64 offset)
{
    return *((quint64 *)((quint64)mResultImage.data() + offset));
}

void ImageBuilder::writeUInt8(qint64 offset, quint8 value)
{
    *((quint8 *)((quint64)mResultImage.data() + offset)) = value;
}

void ImageBuilder::writeUInt16(qint64 offset, quint16 value)
{
    *((quint16 *)((quint64)mResultImage.data() + offset)) = value;
}

void ImageBuilder::writeUInt32(qint64 offset, quint32 value)
{
    *((quint32 *)((quint64)mResultImage.data() + offset)) = value;
}

void ImageBuilder::writeUInt64(qint64 offset, quint64 value)
{
    *((quint64 *)((quint64)mResultImage.data() + offset)) = value;
}
