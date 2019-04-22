#include "burnthread.h"



#ifdef Q_OS_WIN



#include <QCoreApplication>
#include <QDebug>
#include <Windows.h>
#include <initguid.h>
#include <objbase.h>
#include <vds.h>



#define ZERO_SIZE          0
#define AUTO_AUTH_SERVICES -1

#define DISK_ACCESS_RETRIES 150
#define DISK_ACCESS_TIMEOUT 100



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



enum class LockDisk: quint8
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



HANDLE getDiskHandle(BurnThread *thread, LockDisk lockDisk, Access writeAccess, ShareWrite shareWrite)
{
    Q_ASSERT(thread);



    HANDLE res = INVALID_HANDLE_VALUE;



    QString diskPath = "\\\\.\\PhysicalDrive" + QString::number(thread->getSelectedUsb().diskNumber);

    for (qint64 i = 0; i < DISK_ACCESS_RETRIES && thread->isWorking(); ++i)
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
            i > DISK_ACCESS_RETRIES / 3
           )
        {
            qWarning() << "Could not obtain exclusive rights. Retrying with write sharing enabled...";

            shareWrite = ShareWrite::YES;
        }



        QThread::msleep(DISK_ACCESS_TIMEOUT);
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



    if (lockDisk == LockDisk::YES)
    {
        DWORD size;

        if (DeviceIoControl(res, FSCTL_ALLOW_EXTENDED_DASD_IO, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
        {
            qDebug() << "I/O boundary checks disabled";
        }



        for (qint64 i = 0; i < DISK_ACCESS_RETRIES && thread->isWorking(); ++i)
        {
            if (DeviceIoControl(res, FSCTL_LOCK_VOLUME, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
            {
                return res;
            }



            QThread::msleep(DISK_ACCESS_TIMEOUT);
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

QChar getUnusedDiskLetter()
{
    QChar res = 0;



    QString drivesString;

    char drives[128];
    DWORD size = GetLogicalDriveStringsA(sizeof(drives), drives);

    if (size > 0 && size <= sizeof(drives))
    {
        for (char *drive = drives; *drive; drive += strlen(drive) + 1)
        {
            drive[0] = QChar::toUpper(drive[0]);

            if (drive[0] < 'A' || drive[0] > 'Z')
            {
                continue;
            }

            drivesString += drive[0];
        }
    }
    else
    {
        qCritical() << "size is invalid";
    }



    for (qint64 i = 'C'; i <= 'Z'; ++i)
    {
        if (!drivesString.contains((char) i))
        {
            res = (char) i;

            break;
        }
    }



    return res;
}

void unmountVolumes(BurnThread *thread, QChar *targetDiskLetter)
{
    Q_ASSERT(thread);
    Q_ASSERT(targetDiskLetter);



    HANDLE diskHandle = getDiskHandle(thread, LockDisk::YES, Access::READ_ONLY, ShareWrite::NO);

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



    QString diskLetters = thread->getSelectedUsb().letters;

    if (diskLetters != "")
    {
        for (qint64 i = 0; i < diskLetters.length(); ++i)
        {
            wchar_t diskPath[] = { diskLetters.at(i).unicode(), ':', '\\', 0 };

            if (DeleteVolumeMountPoint(diskPath))
            {
                thread->addLog(QCoreApplication::translate("BurnThread", "Unmounted disk volume at %1").arg(diskPath));
            }
            else
            {
                qCritical() << "DeleteVolumeMountPoint failed:" << GetLastError();
            }
        }

        *targetDiskLetter = diskLetters.at(0);
    }
    else
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "There is no any mounted volume"));

        *targetDiskLetter = getUnusedDiskLetter();
    }

    qDebug().nospace() << "Disk will be mounted to " << targetDiskLetter->toLatin1() << ':';



    unlockAndCloseHandle(diskHandle);
}

void handleVdsSoftwareProviderPack(BurnThread *thread, IUnknown *vdsSoftwareProviderPackUnknown)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsSoftwareProviderPackUnknown);



    // Get VDS Pack
    IVdsPack *vdsPack;
    HRESULT   status = vdsSoftwareProviderPackUnknown->QueryInterface(IID_IVdsPack, (void **) &vdsPack);

    vdsSoftwareProviderPackUnknown->Release();

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsSoftwareProviderPackUnknown->QueryInterface failed:" << status;

        thread->stop();

        return;
    }


    // Use the pack interface to access the disks
    IEnumVdsObject *vdsDisks;
    status = vdsPack->QueryDisks(&vdsDisks);

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsPack->QueryDisks failed:" << status;

        thread->stop();

        return;
    }
}

void handleVdsSoftwareProviderPacks(BurnThread *thread, IEnumVdsObject *vdsSoftwareProviderPacks)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsSoftwareProviderPacks);



    IUnknown *vdsSoftwareProviderPackUnknown;
    ULONG     fetched;

    while (SUCCEEDED(vdsSoftwareProviderPacks->Next(1, &vdsSoftwareProviderPackUnknown, &fetched)))
    {
        handleVdsSoftwareProviderPack(thread, vdsSoftwareProviderPackUnknown);
    }
}

void handleVdsProvider(BurnThread *thread, IUnknown *vdsProviderUnknown)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsProviderUnknown);



    // Get VDS Provider
    IVdsProvider *vdsProvider;
    HRESULT       status = vdsProviderUnknown->QueryInterface(IID_IVdsProvider, (void **) &vdsProvider);

    vdsProviderUnknown->Release();

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsProviderUnknown->QueryInterface failed:" << status;

        thread->stop();

        return;
    }



    // Get VDS Software Provider
    IVdsSwProvider *vdsSoftwareProvider;
    status = vdsProvider->QueryInterface(IID_IVdsSwProvider, (void **) &vdsSoftwareProvider);

    vdsProvider->Release();

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsProvider->QueryInterface failed:" << status;

        thread->stop();

        return;
    }



    // Get VDS Software Provider Packs
    IEnumVdsObject *vdsSoftwareProviderPacks;
    status = vdsSoftwareProvider->QueryPacks(&vdsSoftwareProviderPacks);

    vdsSoftwareProvider->Release();

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsSoftwareProvider->QueryPacks failed:" << status;

        thread->stop();

        return;
    }



    handleVdsSoftwareProviderPacks(thread, vdsSoftwareProviderPacks);
}

void handleVdsProviders(BurnThread *thread, IEnumVdsObject *vdsProviders)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsProviders);



    IUnknown *vdsProviderUnknown;
    ULONG     fetched;

    while (SUCCEEDED(vdsProviders->Next(1, &vdsProviderUnknown, &fetched)))
    {
        handleVdsProvider(thread, vdsProviderUnknown);
    }
}

void deletePartitions(BurnThread *thread)
{
    Q_ASSERT(thread);



    // Initialize COM
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    CoInitializeSecurity(nullptr, AUTO_AUTH_SERVICES, nullptr, nullptr, RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr);



    // Create a VDS Loader Instance
    IVdsServiceLoader *vdsLoader;
    HRESULT            status = CoCreateInstance(CLSID_VdsLoader, nullptr, CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER, IID_IVdsServiceLoader, (void **) &vdsLoader);

    if (!SUCCEEDED(status))
    {
        qCritical() << "CoCreateInstance failed:" << status;

        thread->stop();

        return;
    }



    // Load the VDS Service
    wchar_t     *machineName = { 0 };
    IVdsService *vdsService;

    status = vdsLoader->LoadService(machineName, &vdsService);

    vdsLoader->Release();

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsLoader->LoadService failed:" << status;

        thread->stop();

        return;
    }



    // Query the VDS Service Providers
    IEnumVdsObject *vdsProviders;
    status = vdsService->QueryProviders(VDS_QUERY_SOFTWARE_PROVIDERS, &vdsProviders);

    if (!SUCCEEDED(status))
    {
        qCritical() << "vdsService->QueryProviders failed:" << status;

        thread->stop();

        return;
    }



    handleVdsProviders(thread, vdsProviders);
}

void BurnThread::run()
{
    QChar targetDiskLetter;

    unmountVolumes(this, &targetDiskLetter);
    CHECK_IF_TERMINATED();

    deletePartitions(this);
    CHECK_IF_TERMINATED();
}



#endif
