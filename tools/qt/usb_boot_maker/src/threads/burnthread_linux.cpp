#include "burnthread.h"



#ifdef Q_OS_LINUX



#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include <QRegularExpression>



#define CHECK_IF_THREAD_TERMINATED(thread) \
    if (!thread->isWorking()) \
    { \
        return; \
    }



#define CHECK_IF_TERMINATED() \
    if (!mIsRunning) \
    { \
        goto out; \
    }



const QRegularExpression mountPointRegExp("^.+ on (.+) type .+$");



quint8 currentStep;

void notifyNextStep(BurnThread *thread)
{
    Q_ASSERT(thread);



    ++currentStep;

    Q_ASSERT(currentStep <= 6);
    thread->notifyProgress(currentStep, 6);
}

void unmountVolumes(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    bool found = false;

    QProcess process;
    process.start("sh", QStringList() << "-c" << "mount | grep /dev/" + thread->getSelectedUsb().deviceName);
    process.waitForFinished(-1);

    while (process.canReadLine() && thread->isWorking())
    {
        QString line = process.readLine().trimmed();
        qDebug() << line;



        QRegularExpressionMatch match = mountPointRegExp.match(line);

        if (match.hasMatch())
        {
            QString mountPoint = match.captured(1);
            thread->addLog(QCoreApplication::translate("BurnThread", "Unmounting disk volume %1").arg(mountPoint));



            suProcess->write(QString("umount " + mountPoint + "\n").toUtf8());
            suProcess->write("echo \">>>>>> END <<<<<<\"\n");
            suProcess->waitForBytesWritten(-1);
            suProcess->waitForReadyRead(-1);

            while (thread->isWorking())
            {
                QString line = suProcess->readLine().trimmed();

                if (line == ">>>>>> END <<<<<<")
                {
                    break;
                }
            }

            found = true;
        }
    }

    if (!found)
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "There is no any mounted disk volume"));
    }
}

void clearGpt(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Clearing GPT"));



    suProcess->write(QString("sgdisk --zap-all /dev/" + thread->getSelectedUsb().deviceName + " &\n").toUtf8());
    suProcess->write("wait $!\n");
    suProcess->waitForBytesWritten(-1);
    suProcess->waitForReadyRead(-1);
}

void createPartition(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Creating GPT partition for UEFI"));



    suProcess->write(QString("sgdisk --new 1::-0 --typecode=1:EF00 --change-name=1:\"EFI System\" /dev/" + thread->getSelectedUsb().deviceName + " &\n").toUtf8());
    suProcess->write("wait $!\n");
    suProcess->waitForBytesWritten(-1);
    suProcess->waitForReadyRead(-1);
}

void formatPartition(BurnThread *thread)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Formatting partition to FAT32"));
}

void writeProtectiveMbr(BurnThread *thread)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Writing protective MBR"));
}

void formatDisk(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    clearGpt(thread, suProcess);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    createPartition(thread, suProcess);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    formatPartition(thread);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    writeProtectiveMbr(thread);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);
}

void BurnThread::run()
{
    currentStep = 0;



    QProcess suProcess;
    suProcess.start("pkexec", QStringList() << "sh");



    unmountVolumes(this, &suProcess);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();

    formatDisk(this, &suProcess);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();



out:
    suProcess.write(QString("kill -9 " + QString::number(suProcess.processId()) + "\n").toUtf8());
    suProcess.waitForBytesWritten(-1);
    suProcess.waitForReadyRead(-1);
}



#endif
