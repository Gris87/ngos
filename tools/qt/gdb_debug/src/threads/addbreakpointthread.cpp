#include "addbreakpointthread.h"

#include <QDebug>



AddBreakpointThread::AddBreakpointThread(GdbProcess *gdbProcess, QString address)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
    , mAddress(address)
    , mBreakpointId(0)
{
    // Nothing
}

void AddBreakpointThread::stop()
{
    mIsRunning = false;
}

const QString& AddBreakpointThread::getAddress() const
{
    return mAddress;
}

quint64 AddBreakpointThread::getBreakpointId() const
{
    return mBreakpointId;
}

void AddBreakpointThread::run()
{
    QString output;



    mGdbProcess->lock();

    try
    {
        output = mGdbProcess->executeCommand("break *" + mAddress);
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



    qint64 index = output.lastIndexOf("Breakpoint");

    if (index >= 0)
    {
        qint64 index2 = output.indexOf("at", index + 10);

        if (index2 >= 0)
        {
            mBreakpointId = output.mid(index + 10, index2 - index - 10).trimmed().toULongLong();
        }
    }
}
