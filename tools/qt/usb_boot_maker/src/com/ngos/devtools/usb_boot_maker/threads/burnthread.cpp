#include "burnthread.h"

#include <QDir>
#include <QFile>
#include <QSettings>

#include <com/ngos/shared/common/macro/applications.h>



BurnThread::BurnThread(UsbDeviceInfo *deviceInfo, const QString binariesPath)
    : QThread()
    , mIsRunning(true)
    , mSelectedUsb()
    , mBinariesPath(binariesPath)
{
    mSelectedUsb.diskNumber = deviceInfo->diskNumber;
    mSelectedUsb.diskSize   = deviceInfo->diskSize;
    mSelectedUsb.letters    = deviceInfo->letters;
    mSelectedUsb.deviceName = deviceInfo->deviceName;
}

void BurnThread::stop()
{
    mIsRunning = false;
}

void BurnThread::copyFiles(const QString &diskPath)
{
    addLog(tr("Copying files to disk"));



    if (!copyFolder(mBinariesPath + "/" + NGOS_APPLICATION_BOOTLOADER, diskPath + "/EFI/BOOT"))
    {
        addLog(tr("Failed to copy folder %1").arg(NGOS_APPLICATION_BOOTLOADER));

        stop();

        return;
    }

    if (!copyFolder(mBinariesPath + "/" + NGOS_APPLICATION_INSTALLER, diskPath + "/EFI/NGOS"))
    {
        addLog(tr("Failed to copy folder %1").arg(NGOS_APPLICATION_INSTALLER));

        stop();

        return;
    }
}

void BurnThread::createAutorun(const QString &diskPath)
{
    addLog(tr("Create autorun.inf file"));



    if (!QFile(":/assets/images/icon.ico").copy(diskPath + "/icon.ico"))
    {
        addLog(tr("Failed to copy file %1").arg(":/assets/images/icon.ico"));

        stop();

        return;
    }



    QSettings settings(diskPath + "/autorun.inf", QSettings::IniFormat);

    settings.beginGroup("autorun");
    settings.setValue("label", "NGOS installer boot flash");
    settings.setValue("icon", "icon.ico");
    settings.endGroup();
}

void BurnThread::addLog(const QString &text)
{
    emit logAdded(text);
}

void BurnThread::notifyProgress(quint8 current, quint8 maximum)
{
    emit progress(current, maximum);
}

const UsbDeviceInfo& BurnThread::getSelectedUsb() const
{
    return mSelectedUsb;
}

bool BurnThread::isWorking() const
{
    return mIsRunning;
}

bool BurnThread::copyFolder(const QString &sourceFolder, const QString &destinationFolder)
{
    if (!QDir().mkpath(destinationFolder))
    {
        addLog(tr("Failed to create folder %1").arg(destinationFolder));

        return false;
    }



    QFileInfoList filesInfo = QDir(sourceFolder).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < filesInfo.length(); ++i)
    {
        const QFileInfo &fileInfo = filesInfo.at(i);

        QString fileName    = fileInfo.fileName();
        QString source      = sourceFolder + '/' + fileName;
        QString destination = destinationFolder + '/' + fileName;

        if (fileInfo.isDir())
        {
            return copyFolder(source, destination);
        }
        else
        {
            if (!QFile(source).copy(destination))
            {
                addLog(tr("Failed to copy file %1").arg(destination));

                return false;
            }
        }
    }



    return true;
}
