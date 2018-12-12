#include "restartthread.h"

#include <QDebug>



RestartThread::RestartThread()
    : QThread()
    , mIsRunning(true)
    , mQemuProcess(0)
    , mGdbProcess(0)
{
    // Nothing
}

RestartThread::~RestartThread()
{
    if (mQemuProcess)
    {
        delete mQemuProcess;
    }

    if (mGdbProcess)
    {
        delete mGdbProcess;
    }
}

void RestartThread::stop()
{
    mIsRunning = false;
}

QemuProcess* RestartThread::takeQemuProcess()
{
    QemuProcess *res = mQemuProcess;

    mQemuProcess = 0;

    return res;
}

GdbProcess* RestartThread::takeGdbProcess()
{
    GdbProcess *res = mGdbProcess;

    mGdbProcess = 0;

    return res;
}

void RestartThread::run()
{
    mQemuProcess = new QemuProcess();

    if (!mQemuProcess->start())
    {
        qDebug() << "Failed to start qemu";

        return;
    }



    QStringList lines;

    while (mIsRunning)
    {
        bool ok = false;



        QString line = mQemuProcess->readLine(&ok);

        if (!ok)
        {
            msleep(100);

            continue;
        }

        qDebug() << line.toUtf8().constData();
        lines.append(line);



        if (line.contains("gdb_debug is ready to go"))
        {
            mGdbProcess = new GdbProcess(lines);

            mGdbProcess->start(&mIsRunning);

            return;
        }
    }
}
