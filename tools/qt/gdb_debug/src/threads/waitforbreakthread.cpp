#include "waitforbreakthread.h"

#include <QDebug>



WaitForBreakThread::WaitForBreakThread(GdbProcess *gdbProcess)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
{
    // Nothing
}

void WaitForBreakThread::stop()
{
    mIsRunning = false;
}

void WaitForBreakThread::run()
{
    QString output;



    mGdbProcess->lock();

    try
    {
        output = mGdbProcess->readOutput(&mIsRunning);
    }
    catch (...)
    {
        qDebug() << "Error happened";
    }

    mGdbProcess->unlock();



    if (!mIsRunning)
    {
        return;
    }



    mGdbProcess->updateCurrentPositionFromOutput(output);
}
