#include "dumpmemorythread.h"

#include <QDebug>
#include <QTemporaryFile>

#include "src/other/defines.h"



DumpMemoryThread::DumpMemoryThread(GdbProcess *gdbProcess)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
    , mResult()
{
    // Nothing
}

void DumpMemoryThread::stop()
{
    mIsRunning = false;
}

QByteArray DumpMemoryThread::getResult() const
{
    return mResult;
}

void DumpMemoryThread::run()
{
    QTemporaryFile tempFile;

    tempFile.open();
    QString tempFilePath = tempFile.fileName();
    tempFile.close();



    if (!mIsRunning)
    {
        return;
    }



    mGdbProcess->lock();

    try
    {
        mGdbProcess->executeCommand("dump binary memory " + tempFilePath + " 0x0000000000000000 0x" + QString("%1").arg(MEMORY_SIZE_MB * MB_SIZE, 16, 16, QChar('0')), &mIsRunning);

        if (!mIsRunning)
        {
            mGdbProcess->terminateExecution();
            mGdbProcess->readOutput();
        }
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



    QFile file(tempFilePath);

    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd() && mIsRunning)
        {
            mResult.append(file.read(4096));
        }

        file.close();
    }
}
