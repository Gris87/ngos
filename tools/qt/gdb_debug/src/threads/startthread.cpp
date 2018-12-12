#include "startthread.h"

#include <QDebug>



StartThread::StartThread(GdbProcess *gdbProcess)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
{
    // Nothing
}

void StartThread::stop()
{
    mIsRunning = false;
}

void StartThread::run()
{
    mGdbProcess->lock();

    try
    {
        mGdbProcess->continueExecution();
    }
    catch (...)
    {
        qDebug() << "Error happened";
    }

    mGdbProcess->unlock();
}
