#ifndef IMAGE_BUILDER_SRC_COM_NGOS_DEVTOOLS_IMAGE_BUILDER_MAIN_IMAGEBUILDER_H
#define IMAGE_BUILDER_SRC_COM_NGOS_DEVTOOLS_IMAGE_BUILDER_MAIN_IMAGEBUILDER_H



#include <QString>
#include <com/ngos/devtools/shared/elf/elfobject.h>

#include "com/ngos/devtools/image_builder/pe/peheader.h"



class ImageBuilder
{
public:
    ImageBuilder(const QString &bootElfPath, const QString &configureElfPath, const QString &kernelElfPath, const QString &textElfPath, const QString &resultImagePath); // TEST: NO

    qint64 process(); // TEST: NO

private:
    bool writeResultImage(); // TEST: NO
    qint64 getPeHeaderLocation(); // TEST: NO
    PEHeader* getPeHeader(qint64 offset); // TEST: NO
    bool updatePEOptHeader(); // TEST: NO
    bool updateRelocSection(); // TEST: NO
    bool updateConfigSection(); // TEST: NO
    bool updateKernelSection(); // TEST: NO

    quint8 readUInt8(qint64 offset); // TEST: NO
    quint16 readUInt16(qint64 offset); // TEST: NO
    quint32 readUInt32(qint64 offset); // TEST: NO
    quint64 readUInt64(qint64 offset); // TEST: NO

    void writeUInt8(qint64 offset, quint8 value); // TEST: NO
    void writeUInt16(qint64 offset, quint16 value); // TEST: NO
    void writeUInt32(qint64 offset, quint32 value); // TEST: NO
    void writeUInt64(qint64 offset, quint64 value); // TEST: NO

    QString     mBootElfPath;
    QString     mConfigureElfPath;
    QString     mKernelElfPath;
    QString     mTextElfPath;
    QString     mResultImagePath;
    ElfObject   mBootElfObject;
    ElfObject   mConfigureElfObject;
    ElfObject   mKernelElfObject;
    QByteArray  mKernelElf;
    QByteArray  mResultImage;
    QByteArray  mRelocSection;
    PEHeader   *mPEHeader;
    qint64      mBootStart;
    qint64      mBootEnd;
    qint64      mRelocStart;
    qint64      mRelocEnd;
    qint64      mConfigStart;
    qint64      mConfigEnd;
    qint64      mKernelStart;
    qint64      mKernelEnd;
};



#endif // IMAGE_BUILDER_SRC_COM_NGOS_DEVTOOLS_IMAGE_BUILDER_MAIN_IMAGEBUILDER_H
