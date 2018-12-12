#include "deletebreakpointthread.h"

#include <QDebug>



DeleteBreakpointThread::DeleteBreakpointThread(GdbProcess *gdbProcess, QString address, quint64 breakpointId)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
    , mAddress(address)
    , mBreakpointId(breakpointId)
{
    // Nothing
}

void DeleteBreakpointThread::stop()
{
    mIsRunning = false;
}

const QString& DeleteBreakpointThread::getAddress() const
{
    return mAddress;
}

void DeleteBreakpointThread::run()
{
    mGdbProcess->lock();

    try
    {
        mGdbProcess->executeCommand("delete breakpoints " + QString::number(mBreakpointId));
    }
    catch (...)
    {
        qDebug() << "Error happened";
    }

    mGdbProcess->unlock();
}
