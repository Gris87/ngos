#include "burnthread.h"



BurnThread::BurnThread(UsbDeviceInfo *deviceInfo)
    : QThread()
    , mIsRunning(true)
{
    mSelectedUsb.diskNumber = deviceInfo->diskNumber;
    mSelectedUsb.diskSize   = deviceInfo->diskSize;
    mSelectedUsb.letters    = deviceInfo->letters;
}

void BurnThread::stop()
{
    mIsRunning = false;
}

const UsbDeviceInfo& BurnThread::getSelectedUsb() const
{
    return mSelectedUsb;
}

bool BurnThread::isWorking() const
{
    return mIsRunning;
}
