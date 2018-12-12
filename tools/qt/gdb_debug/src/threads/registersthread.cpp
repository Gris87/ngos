#include "registersthread.h"

#include <QDebug>



RegistersThread::RegistersThread(GdbProcess *gdbProcess)
    : QThread()
    , mIsRunning(true)
    , mGdbProcess(gdbProcess)
    , mResult()
{
    // Nothing
}

void RegistersThread::stop()
{
    mIsRunning = false;
}

void RegistersThread::run()
{
    QString output;



    mGdbProcess->lock();

    try
    {
        output = mGdbProcess->executeCommand("info all-registers");
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



        qint64 index = line.indexOf(' ');

        if (index < 0)
        {
            qDebug() << "space not found";

            continue;
        }

        qint64 index2 = line.indexOf('\t', index + 1);



        row.append(line.left(index).trimmed());

        if (index2 >= 0)
        {
            QString value1 = line.mid(index, index2 - index).trimmed();
            QString value2 = line.mid(index2 + 1).trimmed();

            if (!value1.contains("0x") && value2.contains("0x"))
            {
                row.append(value2);
                row.append(value1);
            }
            else
            {
                row.append(value1);
                row.append(value2);
            }
        }
        else
        {
            if (i < lines.length() - 3)
            {
                QString u128Value = lines.at(i + 3);

                index = u128Value.indexOf("uint128 = ");

                if (index >= 0)
                {
                    QString value = u128Value.mid(index + 10);

                    if (value.endsWith('}'))
                    {
                        value.remove(value.length() - 1, 1);
                    }

                    row.append(value);
                    row.append("");

                    i += 3;
                }
                else
                {
                    qDebug() << "u128 not found";

                    continue;
                }
            }
        }



        mResult.append(row);
    }
}

QList<QStringList> RegistersThread::getResult() const
{
    return mResult;
}
