#include "burnthread.h"



#ifdef Q_OS_WIN



#include <QDebug>
#include <Windows.h>



#define ZERO_SIZE 0

#define DRIVE_ACCESS_RETRIES 150
#define DRIVE_ACCESS_TIMEOUT 100



#define CHECK_IF_THREAD_TERMINATED(thread) \
    if (!thread->isWorking()) \
    { \
        return; \
    }



#define CHECK_IF_TERMINATED() \
    if (!mIsRunning) \
    { \
        return; \
    }



enum class LockDrive: quint8
{
    NO,
    YES
};



enum class Access: quint8
{
    READ_ONLY,
    READ_WRITE
};



enum class ShareWrite: quint8
{
    NO,
    YES
};



HANDLE getDiskHandle(BurnThread *thread, LockDrive lockDrive, Access writeAccess, ShareWrite shareWrite)
{
    Q_ASSERT(thread);



    HANDLE res = INVALID_HANDLE_VALUE;



    QString diskPath = "\\\\.\\PhysicalDrive" + QString::number(thread->getSelectedUsb().diskNumber);

    for (qint64 i = 0; i < DRIVE_ACCESS_RETRIES && thread->isWorking(); ++i)
    {
        res = CreateFileA(diskPath.toLatin1().data()
                          , GENERIC_READ    | (writeAccess == Access::READ_WRITE ? GENERIC_WRITE    : 0)
                          , FILE_SHARE_READ | (shareWrite  == ShareWrite::YES    ? FILE_SHARE_WRITE : 0)
                          , nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);



        if (res != INVALID_HANDLE_VALUE)
        {
            break;
        }



        if (
            GetLastError() != ERROR_ACCESS_DENIED
            &&
            GetLastError() != ERROR_SHARING_VIOLATION
           )
        {
            break;
        }



        if (i == 0)
        {
            qDebug() << "Waiting for access to disk";
        }
        else
        if (
            shareWrite == ShareWrite::NO
            &&
            i > DRIVE_ACCESS_RETRIES / 3
           )
        {
            qWarning() << "Could not obtain exclusive rights. Retrying with write sharing enabled...";

            shareWrite = ShareWrite::YES;
        }



        QThread::msleep(DRIVE_ACCESS_TIMEOUT);
    }



    if (res == INVALID_HANDLE_VALUE)
    {
        qCritical() << "Could not open disk:" << GetLastError();

        return res;
    }



    if (writeAccess == Access::READ_WRITE)
    {
        qDebug().nospace() << "Disk opened for " << (shareWrite == ShareWrite::YES ? "shared" : "exclusive") << " write access";
    }
    else
    {
        qDebug() << "Disk opened for read-only access";
    }



    if (lockDrive == LockDrive::YES)
    {
        DWORD size;

        if (DeviceIoControl(res, FSCTL_ALLOW_EXTENDED_DASD_IO, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
        {
            qDebug() << "I/O boundary checks disabled";
        }



        for (qint64 i = 0; i < DRIVE_ACCESS_RETRIES && thread->isWorking(); ++i)
        {
            if (DeviceIoControl(res, FSCTL_LOCK_VOLUME, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
            {
                return res;
            }



            QThread::msleep(DRIVE_ACCESS_TIMEOUT);
        }



        qCritical() << "Could not lock disk:" << GetLastError();
    }



    return res;
}

void unlockAndCloseHandle(HANDLE handle)
{
    Q_ASSERT(handle != INVALID_HANDLE_VALUE);



    DWORD size;

    if (!DeviceIoControl(handle, FSCTL_UNLOCK_VOLUME, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
    {
        qCritical() << "Could not unlock disk:" << GetLastError();
    }

    if (!CloseHandle(handle))
    {
        qCritical() << "CloseHandle failed:" << GetLastError();
    }
}

void unmountVolumes(BurnThread *thread)
{
    Q_ASSERT(thread);



    HANDLE diskHandle = getDiskHandle(thread, LockDrive::YES, Access::READ_ONLY, ShareWrite::NO);

    if (diskHandle == INVALID_HANDLE_VALUE)
    {
        thread->stop();

        return;
    }



    if (!thread->isWorking())
    {
        unlockAndCloseHandle(diskHandle);

        return;
    }



    unlockAndCloseHandle(diskHandle);
}

void BurnThread::run()
{
    unmountVolumes(this);
    CHECK_IF_TERMINATED();
}



#endif
