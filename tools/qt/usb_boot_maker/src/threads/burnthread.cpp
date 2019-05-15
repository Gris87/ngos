#include "burnthread.h"



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
