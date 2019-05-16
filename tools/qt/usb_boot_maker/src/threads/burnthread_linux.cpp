#include "burnthread.h"



#ifdef Q_OS_LINUX



#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include <QRegularExpression>
#include <QTemporaryFile>



#define MBR_RESERVED 0x01B8



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

void execWithSu(BurnThread *thread, QProcess *suProcess, QString command)
{
    Q_ASSERT(thread);
    Q_ASSERT(suProcess);



    QTemporaryFile tempFile;

    tempFile.open();
    QString tempFilePath = tempFile.fileName();
    tempFile.close();



    suProcess->write(QString(command + " > " + tempFilePath + "\n").toUtf8());
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



    tempFile.open();
    qDebug() << "";
    qDebug() << tempFile.readAll().data();
    tempFile.close();
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



            execWithSu(thread, suProcess, "umount " + mountPoint);

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



    execWithSu(thread, suProcess, "sgdisk --zap-all /dev/" + thread->getSelectedUsb().deviceName);
}

void createPartition(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Creating GPT partition for UEFI"));



    execWithSu(thread, suProcess, "sgdisk --new 1::-0 --typecode=1:EF00 --change-name=1:\"EFI System\" /dev/" + thread->getSelectedUsb().deviceName);
}

void formatPartition(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Formatting partition to FAT32"));



    execWithSu(thread, suProcess, "mkfs.fat -F32 -s2 /dev/" + thread->getSelectedUsb().deviceName + "1");
}

void writeProtectiveMbr(BurnThread *thread, QProcess *suProcess)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Writing protective MBR"));



    QTemporaryFile tempFile;

    tempFile.open();
    QString tempFilePath = tempFile.fileName();
    tempFile.close();



    execWithSu(thread, suProcess, "dd if=/dev/" + thread->getSelectedUsb().deviceName + " of=" + tempFilePath + " bs=512 count=1");



    tempFile.open();
    QByteArray originalBuffer = tempFile.readAll();
    tempFile.close();



    if (originalBuffer.size() == 512)
    {
        QFile file(":/assets/binaries/protective_mbr.bin");

        if (!file.open(QIODevice::ReadOnly))
        {
            qCritical() << "Failed to open :/assets/binaries/protective_mbr.bin";

            thread->stop();

            return;
        }

        QByteArray buffer = file.readAll();

        file.close();



        buffer.replace(MBR_RESERVED, 512 - MBR_RESERVED, originalBuffer.mid(MBR_RESERVED));
        buffer.replace(510, 2, "\x55\xAA");



        tempFile.open();
        tempFile.write(buffer);
        tempFile.close();



        execWithSu(thread, suProcess, "dd if=" + tempFilePath + " of=/dev/" + thread->getSelectedUsb().deviceName);
    }
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

    formatPartition(thread, suProcess);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    writeProtectiveMbr(thread, suProcess);
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
