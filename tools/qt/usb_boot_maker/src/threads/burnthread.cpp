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
}

void BurnThread::stop()
{
    mIsRunning = false;
}

void BurnThread::addLog(const QString &text)
{
    emit logAdded(text);
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
