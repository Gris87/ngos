#include "interpretthread.h"

#include <QDebug>



InterpretThread::InterpretThread(GdbProcess *gdbProcess, quint64 position)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
    , mPosition(position)
    , mResult()
{
    // Nothing
}

void InterpretThread::stop()
{
    mIsRunning = false;
}

void InterpretThread::run()
{
    QString output;



    mGdbProcess->lock();

    try
    {
        output = mGdbProcess->executeCommand("x/80i 0x" + QString("%1").arg(mPosition, 16, 16, QChar('0')));
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



    QStringList lines = output.split('\n');

    for (qint64 i = 0; i < lines.length() && mIsRunning; ++i)
    {
        QStringList row;
        QString     line = lines.at(i);



        qint64 index = line.indexOf(":\t", 3);

        if (index < 0)
        {
            qDebug() << ":\\t not found"; // Ignore CppPunctuationVerifier

            continue;
        }

        qint64 index2 = line.indexOf('#', index + 2);



        row.append(line.left(3).trimmed());
        row.append(line.mid(3, index - 3).trimmed());

        if (index2 >= 0)
        {
            row.append(line.mid(index + 2, index2 - index - 2).trimmed());
            row.append(line.mid(index2).trimmed());
        }
        else
        {
            row.append(line.mid(index + 2).trimmed());
            row.append("");
        }

        mResult.append(row);
    }
}

quint64 InterpretThread::getPosition() const
{
    return mPosition;
}

QList<QStringList> InterpretThread::getResult() const
{
    return mResult;
}
