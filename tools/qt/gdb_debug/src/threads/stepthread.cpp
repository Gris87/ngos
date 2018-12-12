#include "stepthread.h"

#include <QDebug>



StepThread::StepThread(GdbProcess *gdbProcess)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
{
    // Nothing
}

void StepThread::stop()
{
    mIsRunning = false;
}

void StepThread::run()
{
    mGdbProcess->lock();

    try
    {
        mGdbProcess->updateCurrentPositionFromOutput(mGdbProcess->executeCommand("nexti"));
    }
    catch (...)
    {
        qDebug() << "Error happened";
    }

    mGdbProcess->unlock();
}
