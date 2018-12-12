#include "qemureaderthread.h"

#include <QDebug>



QemuReaderThread::QemuReaderThread(QemuProcess *qemuProcess)
    : QThread()
    , mIsRunning(true)
    , mQemuProcess(qemuProcess)
{
    // Nothing
}

void QemuReaderThread::stop()
{
    mIsRunning = false;
}

void QemuReaderThread::run()
{
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



        if (line.contains("Boot parameters allocated in space"))
        {
            parseBootParamsAllocated(line);
        }
        else
        if (line.contains("Kernel allocated in space"))
        {
            parseKernelAllocated(line);
        }
        else
        if (line.contains("Kernel relocated to address"))
        {
            parseKernelRelocated(line);
        }
    }
}

void QemuReaderThread::parseBootParamsAllocated(const QString &line)
{
    qint64 index = line.lastIndexOf('(');

    if (index >= 0)
    {
        QString space = line.mid(index + 1);

        if (space.endsWith(')'))
        {
            space.remove(space.length() - 1, 1);
        }

        QStringList spaceParts = space.split(',');

        if (spaceParts.length() == 2)
        {
            QString size    = spaceParts.at(0).trimmed();
            QString address = spaceParts.at(1).trimmed();

            if (address.startsWith("0x"))
            {
                address.remove(0, 2);
            }

            bool ok1 = false;
            bool ok2 = false;

            quint64 addressInt = address.toULongLong(&ok1, 16);
            quint64 sizeInt    = size.toULongLong(&ok2, 10);

            if (ok1 && ok2)
            {
                emit bootParamsAllocated(addressInt, sizeInt);
            }
        }
    }
}

void QemuReaderThread::parseKernelAllocated(const QString &line)
{
    qint64 index = line.lastIndexOf('(');

    if (index >= 0)
    {
        QString space = line.mid(index + 1);

        if (space.endsWith(')'))
        {
            space.remove(space.length() - 1, 1);
        }

        QStringList spaceParts = space.split(',');

        if (spaceParts.length() == 2)
        {
            QString size    = spaceParts.at(0).trimmed();
            QString address = spaceParts.at(1).trimmed();

            if (address.startsWith("0x"))
            {
                address.remove(0, 2);
            }

            bool ok1 = false;
            bool ok2 = false;

            quint64 addressInt = address.toULongLong(&ok1, 16);
            quint64 sizeInt    = size.toULongLong(&ok2, 10);

            if (ok1 && ok2)
            {
                emit kernelAllocated(addressInt, sizeInt);
            }
        }
    }
}

void QemuReaderThread::parseKernelRelocated(const QString &line)
{
    qint64 index = line.lastIndexOf("0x");

    if (index >= 0)
    {
        bool ok = false;

        quint64 address = line.mid(index + 2).toULongLong(&ok, 16);

        if (ok)
        {
            emit kernelRelocated(address);
        }
    }
}
