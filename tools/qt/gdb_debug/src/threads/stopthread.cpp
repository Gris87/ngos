#include "stopthread.h"

#include <QDebug>



StopThread::StopThread(GdbProcess *gdbProcess)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
{
    // Nothing
}

void StopThread::stop()
{
    mIsRunning = false;
}

void StopThread::run()
{
    mGdbProcess->lock();

    try
    {
        mGdbProcess->terminateExecution();
        mGdbProcess->updateCurrentPositionFromOutput(mGdbProcess->readOutput());
    }
    catch (...)
    {
        qDebug() << "Error happened";
    }

    mGdbProcess->unlock();
}
