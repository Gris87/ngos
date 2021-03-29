#include "usbmonitorthread.h"



#ifdef Q_OS_WIN



UsbMonitorThread::UsbMonitorThread()
    : QThread()
    , mIsRunning(true)
{
    // Nothing
}

void UsbMonitorThread::stop()
{
    mIsRunning = false;
}

void UsbMonitorThread::run()
{
    // Nothing
}



#endif // Q_OS_WIN
