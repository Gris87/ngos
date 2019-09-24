#include "burnthread.h"

#include <QDir>
#include <QFile>
#include <QSettings>



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



    if (!QDir().mkpath(diskPath + "/EFI/BOOT"))
    {
        addLog(tr("Failed to create folder %1").arg(diskPath + "/EFI/BOOT"));

        stop();

        return;
    }



    if (!QDir().mkpath(diskPath + "/EFI/NGOS"))
    {
        addLog(tr("Failed to create folder %1").arg(diskPath + "/EFI/NGOS"));

        stop();

        return;
    }



    if (!QFile(getBinariesPath() + "/kernel.efi").copy(diskPath + "/EFI/NGOS/kernel.efi"))
    {
        addLog(tr("Failed to copy file %1").arg("kernel.efi"));

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

const QString& BurnThread::getBinariesPath() const
{
    return mBinariesPath;
}

bool BurnThread::isWorking() const
{
    return mIsRunning;
}
