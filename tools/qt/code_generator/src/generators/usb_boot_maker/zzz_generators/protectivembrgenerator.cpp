#include "protectivembrgenerator.h"

#include <QFile>
#include <QProcess>
#include <QTemporaryFile>
#include <console/console.h>



#define ASM_PATH  "/assets/binaries/protective_mbr.S"
#define FILE_PATH "/assets/binaries/protective_mbr.bin"



ProtectiveMbrGenerator::ProtectiveMbrGenerator()
    : UsbBootMakerGenerator()
{
    // Nothing
}

bool ProtectiveMbrGenerator::generate(const QString &path)
{
    QTemporaryFile tempFile1;
    QTemporaryFile tempFile2;

    tempFile1.open();
    QString tempFile1Path = tempFile1.fileName();
    tempFile1.close();

    tempFile2.open();
    QString tempFile2Path = tempFile2.fileName();
    tempFile2.close();



    QString asmPath = path + ASM_PATH;

    if (!QFile(asmPath).exists())
    {
        Console::err(QString("File %1 not found").arg(asmPath));

        return false;
    }



    QProcess process;
    process.start("gcc", QStringList() << "-c" << asmPath << "-o" << tempFile1Path);
    process.waitForFinished(-1);

    if (process.exitCode() != 0)
    {
        Console::err(QString("Failed to compile %1").arg(asmPath));

        return false;
    }



    process.start("objcopy", QStringList() << "-O" << "binary" << tempFile1Path << tempFile2Path);
    process.waitForFinished(-1);

    if (process.exitCode() != 0)
    {
        Console::err(QString("Failed to compile %1").arg(asmPath));

        return false;
    }



    tempFile2.open();
    QByteArray data = tempFile2.readAll();
    tempFile2.close();



    return save(path + FILE_PATH, data);
}



ProtectiveMbrGenerator protectiveMbrGeneratorInstance;
