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



// Redefine VOLUME_DISK_EXTENTS from winioctl.h with the more space for Extents
struct VOLUME_DISK_EXTENTS_REDEF
{
    DWORD       numberOfDiskExtents;
    DISK_EXTENT extents[8];
};



QString getPhysicalName(BurnThread *thread)
{
    Q_ASSERT(thread);



    return "\\\\.\\PhysicalDrive" + QString::number(thread->getSelectedUsb().diskNumber);
}

QString getLogicalName(BurnThread *thread)
{
    Q_ASSERT(thread);



    QString res;

    char volumeName[MAX_PATH];
    HANDLE volumeHandle = INVALID_HANDLE_VALUE;

    do
    {
        if (volumeHandle == INVALID_HANDLE_VALUE)
        {
            volumeHandle = FindFirstVolumeA(volumeName, sizeof(volumeName));

            if (volumeHandle == INVALID_HANDLE_VALUE)
            {
                qCritical() << "FindFirstVolume failed:" << GetLastError();

                thread->stop();

                break;
            }
        }
        else
        {
            if (!FindNextVolumeA(volumeHandle, volumeName, sizeof(volumeName)))
            {
                qCritical() << "FindNextVolume failed:" << GetLastError();

                thread->stop();

                break;
            }
        }



        size_t len = strlen(volumeName);
        volumeName[len - 1] = 0;



        HANDLE deviceHandle = CreateFileA(volumeName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

        if (deviceHandle == INVALID_HANDLE_VALUE)
        {
            qCritical() << "CreateFile failed:" << GetLastError();

            continue;
        }



        VOLUME_DISK_EXTENTS_REDEF diskExtents;
        DWORD                     size;

        if (DeviceIoControl(deviceHandle, IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS, nullptr, ZERO_SIZE, &diskExtents, sizeof(diskExtents), &size, nullptr))
        {
            if ((diskExtents.numberOfDiskExtents >= 1) && (diskExtents.extents[0].DiskNumber == thread->getSelectedUsb().diskNumber))
            {
                res = volumeName;
            }
        }
        else
        {
            qCritical() << "DeviceIoControl failed:" << GetLastError();
        }



        if (!CloseHandle(deviceHandle))
        {
            qCritical() << "CloseHandle failed:" << GetLastError();

            continue;
        }



        if (res != "")
        {
            break;
        }
    } while(true);



    if (volumeHandle != INVALID_HANDLE_VALUE)
    {
        if (!FindVolumeClose(volumeHandle))
        {
            qCritical() << "FindVolumeClose failed:" << GetLastError();

            thread->stop();
        }
    }



    return res;
}

HANDLE getHandle(BurnThread *thread, const QString &path, LockDisk lockDisk, Access writeAccess, ShareWrite shareWrite)
{
    Q_ASSERT(thread);



    HANDLE res = INVALID_HANDLE_VALUE;



    for (qint64 i = 0; i < DISK_ACCESS_RETRIES && thread->isWorking(); ++i)
    {
        res = CreateFileA(path.toLatin1().data()
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

        thread->stop();

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

        thread->stop();
    }



    return res;
}

HANDLE getPhysicalHandle(BurnThread *thread, LockDisk lockDisk, Access writeAccess, ShareWrite shareWrite)
{
    Q_ASSERT(thread);



    return getHandle(thread, getPhysicalName(thread), lockDisk, writeAccess, shareWrite);
}

HANDLE getLogicalHandle(BurnThread *thread, LockDisk lockDisk, Access writeAccess, ShareWrite shareWrite)
{
    Q_ASSERT(thread);



    return getHandle(thread, getLogicalName(thread), lockDisk, writeAccess, shareWrite);
}

void unlockAndCloseHandle(BurnThread *thread, HANDLE handle)
{
    Q_ASSERT(thread);
    Q_ASSERT(handle != INVALID_HANDLE_VALUE);



    DWORD size;

    if (!DeviceIoControl(handle, FSCTL_UNLOCK_VOLUME, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
    {
        qCritical() << "Could not unlock disk:" << GetLastError();

        thread->stop();
    }

    if (!CloseHandle(handle))
    {
        qCritical() << "CloseHandle failed:" << GetLastError();

        thread->stop();
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

QString partitionSizeHumanReadable(quint64 partitionSize)
{
    if (partitionSize >= 1000000000000)
    {
        return QString::number((quint64)floor(partitionSize / 1000000000000.0)) + "TB";
    }

    if (partitionSize >= 1000000000)
    {
        return QString::number((quint64)floor(partitionSize / 1000000000.0)) + "GB";
    }

    return QString::number((quint64)floor(partitionSize / 1000000.0)) + "MB";
}

void unmountVolumes(BurnThread *thread, QChar *targetDiskLetter)
{
    Q_ASSERT(thread);
    Q_ASSERT(targetDiskLetter);



    HANDLE diskHandle = getPhysicalHandle(thread, LockDisk::YES, Access::READ_ONLY, ShareWrite::NO);

    if (diskHandle == INVALID_HANDLE_VALUE)
    {
        thread->stop();

        return;
    }



    if (!thread->isWorking())
    {
        unlockAndCloseHandle(thread, diskHandle);

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
                thread->addLog(QCoreApplication::translate("BurnThread", "Unmounted disk volume %1").arg(diskPath));
            }
            else
            {
                qCritical() << "DeleteVolumeMountPoint failed:" << GetLastError();

                thread->stop();

                break;
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



    unlockAndCloseHandle(thread, diskHandle);
}

bool handleVdsDisk(BurnThread *thread, IUnknown *vdsDiskUnknown)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsDiskUnknown);



    // Get the disk interface.
    IVdsDisk *vdsDisk;
    HRESULT   status = vdsDiskUnknown->QueryInterface(IID_IVdsDisk, (void **) &vdsDisk);

    if (status != S_OK)
    {
        qCritical() << "vdsDiskUnknown->QueryInterface failed:" << status;

        thread->stop();

        return false;
    }



    // Get the disk properties
    VDS_DISK_PROP vdsDiskProp;
    status = vdsDisk->GetProperties(&vdsDiskProp);

    if (status != S_OK)
    {
        qCritical() << "vdsDisk->GetProperties failed:" << status;

        thread->stop();

        return false;
    }



    // Isolate the disk we want
    if (("\\\\?\\PhysicalDrive" + QString::number(thread->getSelectedUsb().diskNumber)) != QString::fromWCharArray(vdsDiskProp.pwszName))
    {
        vdsDisk->Release();

        return false;
    }



    // Instantiate the AdvanceDisk interface for our disk.
    IVdsAdvancedDisk *vdsAdvancedDisk;
    status = vdsDisk->QueryInterface(IID_IVdsAdvancedDisk, (void **) &vdsAdvancedDisk);

    vdsDisk->Release();

    if (status != S_OK)
    {
        qCritical() << "vdsDisk->QueryInterface failed:" << status;

        thread->stop();

        return false;
    }



    // Query the partition data, so we can get the start offset, which we need for deletion
    VDS_PARTITION_PROP *partionsPropArray;
    LONG                numberOfPartitions;
    status = vdsAdvancedDisk->QueryPartitions(&partionsPropArray, &numberOfPartitions);

    if (status != S_OK || !numberOfPartitions) // numberOfPartitions == 0
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "There is no partitions on the disk"));

        return true;
    }



    thread->addLog(QCoreApplication::translate("BurnThread", "Deleting partitions on the disk"));



    for (qint64 i = 0; i < numberOfPartitions; ++i)
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "Deleting partition %1 (offset: %2, size: %3)").arg(partionsPropArray[i].ulPartitionNumber).arg(partionsPropArray[i].ullOffset).arg(partitionSizeHumanReadable(partionsPropArray[i].ullSize)));

        status = vdsAdvancedDisk->DeletePartition(partionsPropArray[i].ullOffset, true, true);

        if (status != S_OK)
        {
            thread->addLog(QCoreApplication::translate("BurnThread", "Failed to delete partition"));

            thread->stop();

            return false;
        }
    }



    CoTaskMemFree(partionsPropArray);
    vdsAdvancedDisk->Release();



    return true;
}

bool handleVdsDisks(BurnThread *thread, IEnumVdsObject *vdsDisks)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsDisks);



    IUnknown *vdsDiskUnknown;
    ULONG     fetched;

    while (vdsDisks->Next(1, &vdsDiskUnknown, &fetched) == S_OK)
    {
        if (handleVdsDisk(thread, vdsDiskUnknown))
        {
            return true;
        }
    }

    return false;
}

bool handleVdsSoftwareProviderPack(BurnThread *thread, IUnknown *vdsSoftwareProviderPackUnknown)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsSoftwareProviderPackUnknown);



    // Get VDS Pack
    IVdsPack *vdsPack;
    HRESULT   status = vdsSoftwareProviderPackUnknown->QueryInterface(IID_IVdsPack, (void **) &vdsPack);

    vdsSoftwareProviderPackUnknown->Release();

    if (status != S_OK)
    {
        qCritical() << "vdsSoftwareProviderPackUnknown->QueryInterface failed:" << status;

        thread->stop();

        return false;
    }



    // Use the pack interface to access the disks
    IEnumVdsObject *vdsDisks;
    status = vdsPack->QueryDisks(&vdsDisks);

    if (status != S_OK)
    {
        qCritical() << "vdsPack->QueryDisks failed:" << status;

        thread->stop();

        return false;
    }



    return handleVdsDisks(thread, vdsDisks);
}

bool handleVdsSoftwareProviderPacks(BurnThread *thread, IEnumVdsObject *vdsSoftwareProviderPacks)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsSoftwareProviderPacks);



    IUnknown *vdsSoftwareProviderPackUnknown;
    ULONG     fetched;

    while (vdsSoftwareProviderPacks->Next(1, &vdsSoftwareProviderPackUnknown, &fetched) == S_OK)
    {
        if (handleVdsSoftwareProviderPack(thread, vdsSoftwareProviderPackUnknown))
        {
            return true;
        }
    }

    return false;
}

bool handleVdsProvider(BurnThread *thread, IUnknown *vdsProviderUnknown)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsProviderUnknown);



    // Get VDS Provider
    IVdsProvider *vdsProvider;
    HRESULT       status = vdsProviderUnknown->QueryInterface(IID_IVdsProvider, (void **) &vdsProvider);

    vdsProviderUnknown->Release();

    if (status != S_OK)
    {
        qCritical() << "vdsProviderUnknown->QueryInterface failed:" << status;

        thread->stop();

        return false;
    }



    // Get VDS Software Provider
    IVdsSwProvider *vdsSoftwareProvider;
    status = vdsProvider->QueryInterface(IID_IVdsSwProvider, (void **) &vdsSoftwareProvider);

    vdsProvider->Release();

    if (status != S_OK)
    {
        qCritical() << "vdsProvider->QueryInterface failed:" << status;

        thread->stop();

        return false;
    }



    // Get VDS Software Provider Packs
    IEnumVdsObject *vdsSoftwareProviderPacks;
    status = vdsSoftwareProvider->QueryPacks(&vdsSoftwareProviderPacks);

    vdsSoftwareProvider->Release();

    if (status != S_OK)
    {
        qCritical() << "vdsSoftwareProvider->QueryPacks failed:" << status;

        thread->stop();

        return false;
    }



    return handleVdsSoftwareProviderPacks(thread, vdsSoftwareProviderPacks);
}

bool handleVdsProviders(BurnThread *thread, IEnumVdsObject *vdsProviders)
{
    Q_ASSERT(thread);
    Q_ASSERT(vdsProviders);



    IUnknown *vdsProviderUnknown;
    ULONG     fetched;

    while (vdsProviders->Next(1, &vdsProviderUnknown, &fetched) == S_OK)
    {
        if (handleVdsProvider(thread, vdsProviderUnknown))
        {
            return true;
        }
    }

    return false;
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

    if (status != S_OK)
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

    if (status != S_OK)
    {
        qCritical() << "vdsLoader->LoadService failed:" << status;

        thread->stop();

        return;
    }



    // Query the VDS Service Providers
    IEnumVdsObject *vdsProviders;
    status = vdsService->QueryProviders(VDS_QUERY_SOFTWARE_PROVIDERS, &vdsProviders);

    if (status != S_OK)
    {
        qCritical() << "vdsService->QueryProviders failed:" << status;

        thread->stop();

        return;
    }



    handleVdsProviders(thread, vdsProviders);
}

void dismountVolume(BurnThread *thread, HANDLE volumeHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(volumeHandle != INVALID_HANDLE_VALUE);



    DWORD size;

    if (!DeviceIoControl(volumeHandle, FSCTL_DISMOUNT_VOLUME, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
    {
        qCritical() << "DeviceIoControl failed:" << GetLastError();

        thread->stop();

        return;
    }
}

void doSomething(BurnThread *thread)
{
    Q_ASSERT(thread);



    HANDLE volumeHandle = getLogicalHandle(thread, LockDisk::YES, Access::READ_ONLY, ShareWrite::NO);

    if (volumeHandle == INVALID_HANDLE_VALUE)
    {
        thread->stop();

        return;
    }

    dismountVolume(thread, volumeHandle);

    unlockAndCloseHandle(thread, volumeHandle);
}

void BurnThread::run()
{
    QChar targetDiskLetter;

    unmountVolumes(this, &targetDiskLetter);
    CHECK_IF_TERMINATED();

    deletePartitions(this);
    CHECK_IF_TERMINATED();

    doSomething(this);
    CHECK_IF_TERMINATED();
}



#endif
