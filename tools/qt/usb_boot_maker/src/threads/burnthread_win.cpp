#include "burnthread.h"



#ifdef Q_OS_WIN



#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <Windows.h>



#define ZERO_SIZE 0

#define DISK_ACCESS_RETRIES 150
#define DISK_ACCESS_TIMEOUT 100

#define WRITE_RETRIES 100
#define WRITE_TIMEOUT 100

#define MAX_GPT_PARTITIONS   128
#define DEFAULT_CLUSTER_SIZE 4096

#define MBR_RESERVED 0x01B8



#define CHECK_IF_THREAD_TERMINATED(thread) \
    if (!thread->isWorking()) \
    { \
        goto out; \
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



enum class FILE_SYSTEM_CALLBACK_COMMAND: quint8
{
    FCC_PROGRESS,
    FCC_DONE_WITH_STRUCTURE,
    FCC_UNKNOWN2,
    FCC_INCOMPATIBLE_FILE_SYSTEM,
    FCC_UNKNOWN4,
    FCC_UNKNOWN5,
    FCC_ACCESS_DENIED,
    FCC_MEDIA_WRITE_PROTECTED,
    FCC_VOLUME_IN_USE,
    FCC_CANT_QUICK_FORMAT,
    FCC_UNKNOWNA,
    FCC_DONE,
    FCC_BAD_LABEL,
    FCC_UNKNOWND,
    FCC_OUTPUT,
    FCC_STRUCTURE_PROGRESS,
    FCC_CLUSTER_SIZE_TOO_SMALL,
    FCC_CLUSTER_SIZE_TOO_BIG,
    FCC_VOLUME_TOO_SMALL,
    FCC_VOLUME_TOO_BIG,
    FCC_NO_MEDIA_IN_DRIVE,
    FCC_UNKNOWN15,
    FCC_UNKNOWN16,
    FCC_UNKNOWN17,
    FCC_DEVICE_NOT_READY,
    FCC_CHECKDISK_PROGRESS,
    FCC_UNKNOWN1A,
    FCC_UNKNOWN1B,
    FCC_UNKNOWN1C,
    FCC_UNKNOWN1D,
    FCC_UNKNOWN1E,
    FCC_UNKNOWN1F,
    FCC_READ_ONLY_MODE
};



typedef bool (__stdcall *FILE_SYSTEM_CALLBACK)(
    FILE_SYSTEM_CALLBACK_COMMAND command,
    ULONG                        action,
    PVOID                        pData
);



typedef void (WINAPI *FormatEx_t)(
    WCHAR*               driveRoot,
    MEDIA_TYPE           mediaType,
    WCHAR*               fileSystemTypeName,
    WCHAR*               label,
    BOOL                 quickFormat,
    ULONG                desiredUnitAllocationSize,
    FILE_SYSTEM_CALLBACK callback
);



const GUID PARTITION_BASIC_DATA_GUID = { 0xEBD0A0A2L, 0xB9E5, 0x4433, {0x87, 0xC0, 0x68, 0xB6, 0xB7, 0x26, 0x99, 0xC7} };



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

void waitForLogical(BurnThread *thread)
{
    Q_ASSERT(thread);



    QThread::msleep(200);

    while (thread->isWorking())
    {
        if (getLogicalName(thread) != "")
        {
            break;
        }

        QThread::msleep(DISK_ACCESS_TIMEOUT);
    }
}

void refreshDiskLayout(BurnThread *thread, HANDLE diskHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    DWORD size;

    if (!DeviceIoControl(diskHandle, IOCTL_DISK_UPDATE_PROPERTIES, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
    {
        qCritical() << "Could not refresh disk layout:" << GetLastError();

        thread->stop();
    }
}

QByteArray readSectors(HANDLE diskHandle, quint64 startSector, quint64 numberOfSectors)
{
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    LARGE_INTEGER ptr;
    ptr.QuadPart = startSector << 9; // "<< 9" == "* 512"

    if (!SetFilePointerEx(diskHandle, ptr, nullptr, FILE_BEGIN))
    {
        qCritical() << "SetFilePointerEx failed:" << GetLastError();

        return QByteArray();
    }



    DWORD size = numberOfSectors << 9; // "<< 9" == "* 512"
    QByteArray buffer(size, 0);

    if (!ReadFile(diskHandle, buffer.data(), size, &size, nullptr))
    {
        qCritical() << "ReadFile failed:" << GetLastError();

        return QByteArray();
    }



    return buffer;
}

qint64 writeSectors(HANDLE diskHandle, quint64 startSector, quint64 numberOfSectors, const QByteArray &buffer)
{
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    LARGE_INTEGER ptr;
    ptr.QuadPart = startSector << 9; // "<< 9" == "* 512"

    if (!SetFilePointerEx(diskHandle, ptr, nullptr, FILE_BEGIN))
    {
        qCritical() << "SetFilePointerEx failed:" << GetLastError();

        return -1;
    }



    DWORD size = numberOfSectors << 9; // "<< 9" == "* 512"
    Q_ASSERT(buffer.size() == size);

    if (!WriteFile(diskHandle, buffer.constData(), size, &size, nullptr))
    {
        qCritical() << "WriteFile failed:" << GetLastError();

        return -1;
    }



    return size;
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

quint8 currentStep;

void notifyNextStep(BurnThread *thread)
{
    Q_ASSERT(thread);



    ++currentStep;

    Q_ASSERT(currentStep <= 11);
    thread->notifyProgress(currentStep, 11);
}

void unmountVolumes(BurnThread *thread, QString *targetDiskLetter)
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

            thread->addLog(QCoreApplication::translate("BurnThread", "Unmounting disk volume %1").arg(diskPath));

            if (!DeleteVolumeMountPoint(diskPath))
            {
                qCritical() << "DeleteVolumeMountPoint failed:" << GetLastError();

                thread->stop();

                break;
            }
        }

        *targetDiskLetter = QString("%1:\\").arg(diskLetters.at(0));
    }
    else
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "There is no any mounted disk volume"));

        *targetDiskLetter = QString("%1:\\").arg(getUnusedDiskLetter());
    }

    qDebug().nospace() << "Disk will be mounted to " << targetDiskLetter->toLatin1().data();



    unlockAndCloseHandle(thread, diskHandle);
}

void clearGpt(BurnThread *thread, HANDLE diskHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    QByteArray buffer(512, 0);

    thread->addLog(QCoreApplication::translate("BurnThread", "Clearing GPT"));



    qint64 sectorsCount = thread->getSelectedUsb().diskSize >> 9; // ">> 9" == "/ 512"

    for (qint64 i = 0; i < 34 && thread->isWorking(); ++i)
    {
        for (qint64 j = 0; j < WRITE_RETRIES && thread->isWorking(); ++j)
        {
            if (writeSectors(diskHandle, i, 1, buffer) == 512)
            {
                break;
            }
            else
            {
                QThread::msleep(WRITE_TIMEOUT);
            }
        }
    }

    for (qint64 i = sectorsCount - 33; i < sectorsCount && thread->isWorking(); ++i)
    {
        for (qint64 j = 0; j < WRITE_RETRIES && thread->isWorking(); ++j)
        {
            if (writeSectors(diskHandle, i, 1, buffer) == 512)
            {
                break;
            }
            else
            {
                QThread::msleep(WRITE_TIMEOUT);
            }
        }
    }
}

void initializeDisk(BurnThread *thread, HANDLE diskHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    CREATE_DISK createDisk = { PARTITION_STYLE_RAW, {{ 0 }} };
    DWORD       size       = sizeof(createDisk);

    thread->addLog(QCoreApplication::translate("BurnThread", "Initializing disk"));



    if (!DeviceIoControl(diskHandle, IOCTL_DISK_CREATE_DISK, (BYTE *) &createDisk, size, nullptr, ZERO_SIZE, &size, nullptr))
    {
        qCritical() << "Could not delete disk layout:" << GetLastError();

        thread->stop();
    }



    refreshDiskLayout(thread, diskHandle);
}

void createPartition(BurnThread *thread, HANDLE diskHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    thread->addLog(QCoreApplication::translate("BurnThread", "Creating GPT partition for UEFI"));



    DRIVE_LAYOUT_INFORMATION_EX driveLayout = { 0 };

    driveLayout.PartitionStyle = PARTITION_STYLE_GPT;
    driveLayout.PartitionCount = 1;

    driveLayout.PartitionEntry[0].PartitionStyle           = PARTITION_STYLE_GPT;
    driveLayout.PartitionEntry[0].StartingOffset.QuadPart  = 1 << 20; // 1 MB
    driveLayout.PartitionEntry[0].PartitionLength.QuadPart = thread->getSelectedUsb().diskSize - driveLayout.PartitionEntry[0].StartingOffset.QuadPart - (33 << 9); // "<< 9" == "* 512" // Last 33 sectors reserved for Secondary GPT header
    driveLayout.PartitionEntry[0].PartitionNumber          = 1;
    driveLayout.PartitionEntry[0].RewritePartition         = true;

    driveLayout.PartitionEntry[0].Gpt.PartitionType = PARTITION_BASIC_DATA_GUID;
    CoCreateGuid(&driveLayout.PartitionEntry[0].Gpt.PartitionId);
    QString("Microsoft Basic Data").toWCharArray(driveLayout.PartitionEntry[0].Gpt.Name);



    CREATE_DISK createDisk = { PARTITION_STYLE_GPT, {{ 0 }} };

    CoCreateGuid(&createDisk.Gpt.DiskId);
    createDisk.Gpt.MaxPartitionCount = MAX_GPT_PARTITIONS;

    driveLayout.Gpt.DiskId                        = createDisk.Gpt.DiskId;
    driveLayout.Gpt.StartingUsableOffset.QuadPart = 34 << 9;                                              // "<< 9" == "* 512" // First 34 sectors reserved for Protective MBR and Primary GPT header
    driveLayout.Gpt.UsableLength.QuadPart         = thread->getSelectedUsb().diskSize - ((34 + 33) << 9); // "<< 9" == "* 512" // Last 33 sectors reserved for Secondary GPT header
    driveLayout.Gpt.MaxPartitionCount             = MAX_GPT_PARTITIONS;



    DWORD size = sizeof(createDisk);

    if (!DeviceIoControl(diskHandle, IOCTL_DISK_CREATE_DISK, (BYTE *) &createDisk, size, nullptr, ZERO_SIZE, &size, nullptr))
    {
        qCritical() << "Could not reset disk layout:" << GetLastError();

        thread->stop();
    }



    size = sizeof(driveLayout);

    if (!DeviceIoControl(diskHandle, IOCTL_DISK_SET_DRIVE_LAYOUT_EX, (BYTE *) &driveLayout, size, nullptr, 0, &size, nullptr))
    {
        qCritical() << "Could not set disk layout:" << GetLastError();

        thread->stop();
    }



    refreshDiskLayout(thread, diskHandle);
}

bool formatSuccessful;

bool __stdcall formatExCallback(FILE_SYSTEM_CALLBACK_COMMAND command, DWORD /*action*/, PVOID /*pData*/)
{
    switch (command)
    {
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_PROGRESS:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_STRUCTURE_PROGRESS:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_DONE:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_DONE_WITH_STRUCTURE:
        {
            return true;
        }
        break;

        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN2:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_INCOMPATIBLE_FILE_SYSTEM:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN4:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN5:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_ACCESS_DENIED:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_MEDIA_WRITE_PROTECTED:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_VOLUME_IN_USE:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_CANT_QUICK_FORMAT:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWNA:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_BAD_LABEL:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWND:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_OUTPUT:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_CLUSTER_SIZE_TOO_SMALL:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_CLUSTER_SIZE_TOO_BIG:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_VOLUME_TOO_SMALL:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_VOLUME_TOO_BIG:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_NO_MEDIA_IN_DRIVE:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN15:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN16:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN17:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_DEVICE_NOT_READY:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_CHECKDISK_PROGRESS:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN1A:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN1B:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN1C:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN1D:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN1E:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_UNKNOWN1F:
        case FILE_SYSTEM_CALLBACK_COMMAND::FCC_READ_ONLY_MODE:
        {
            qCritical() << "Unexpected command:" << (quint8) command;
        }
        break;

        default:
        {
            qCritical() << "Unknown command:" << (quint8) command;
        }
        break;
    }

    formatSuccessful = false;

    return false;
}

void formatPartitionWithFmifs(BurnThread *thread, HMODULE moduleHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(moduleHandle);



    FormatEx_t pfFormatEx = (FormatEx_t) GetProcAddress(moduleHandle, "FormatEx");

    if (!pfFormatEx)
    {
        qCritical() << "GetProcAddress failed:" << GetLastError();

        thread->stop();

        return;
    }



    wchar_t volumeName[MAX_PATH] = { 0 };
    wchar_t fsType[8]            = { 0 };
    wchar_t label[16]            = { 0 };

    getLogicalName(thread).toWCharArray(volumeName);
    QString("FAT32").toWCharArray(fsType);
    QString("NGOS BOOT").toWCharArray(label);



    formatSuccessful = true;

    pfFormatEx(volumeName, RemovableMedia, fsType, label, true, DEFAULT_CLUSTER_SIZE, formatExCallback);

    if (!formatSuccessful)
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "Disk formatting failed"));

        thread->stop();

        return;
    }
}

void formatPartition(BurnThread *thread, HANDLE diskHandle)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Formatting partition to FAT32"));



    HMODULE moduleHandle = LoadLibraryA("fmifs.dll");

    if (moduleHandle != nullptr)
    {
        formatPartitionWithFmifs(thread, moduleHandle);

        if (!FreeLibrary(moduleHandle))
        {
            qCritical() << "FreeLibrary failed:" << GetLastError();

            thread->stop();
        }
    }
    else
    {
        qCritical() << "LoadLibrary failed:" << GetLastError();

        thread->stop();
    }



    refreshDiskLayout(thread, diskHandle);
}

void writeProtectiveMbr(BurnThread *thread, HANDLE diskHandle)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskHandle != INVALID_HANDLE_VALUE);



    thread->addLog(QCoreApplication::translate("BurnThread", "Writing protective MBR"));



    QByteArray originalBuffer;

    for (qint64 i = 0; i < WRITE_RETRIES && thread->isWorking(); ++i)
    {
        originalBuffer = readSectors(diskHandle, 0, 1);

        if (originalBuffer.size() == 512)
        {
            break;
        }
        else
        {
            QThread::msleep(WRITE_TIMEOUT);
        }
    }



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



        for (qint64 i = 0; i < WRITE_RETRIES && thread->isWorking(); ++i)
        {
            if (writeSectors(diskHandle, 0, 1, buffer) == 512)
            {
                break;
            }
            else
            {
                QThread::msleep(WRITE_TIMEOUT);
            }
        }



        refreshDiskLayout(thread, diskHandle);
    }
}

void formatDisk(BurnThread *thread)
{
    Q_ASSERT(thread);



    HANDLE diskHandle = getPhysicalHandle(thread, LockDisk::YES, Access::READ_WRITE, ShareWrite::NO);

    if (diskHandle == INVALID_HANDLE_VALUE)
    {
        thread->stop();

        return;
    }



    HANDLE volumeHandle = getLogicalHandle(thread, LockDisk::YES, Access::READ_ONLY, ShareWrite::NO);

    if (volumeHandle == INVALID_HANDLE_VALUE)
    {
        unlockAndCloseHandle(thread, diskHandle);

        thread->stop();

        return;
    }



    clearGpt(thread, diskHandle);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    initializeDisk(thread, diskHandle);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    createPartition(thread, diskHandle);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);



    unlockAndCloseHandle(thread, volumeHandle);
    volumeHandle = INVALID_HANDLE_VALUE;

    waitForLogical(thread);
    CHECK_IF_THREAD_TERMINATED(thread);



    formatPartition(thread, diskHandle);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    writeProtectiveMbr(thread, diskHandle);
    notifyNextStep(thread);
    CHECK_IF_THREAD_TERMINATED(thread);

    waitForLogical(thread);
    CHECK_IF_THREAD_TERMINATED(thread);



out:
    unlockAndCloseHandle(thread, diskHandle);

    if (volumeHandle != INVALID_HANDLE_VALUE)
    {
        unlockAndCloseHandle(thread, volumeHandle);
    }
}

void mountVolumeByGuid(BurnThread *thread, QString *diskPath, const QString &volumeName)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskPath);



    char mountedLetters[27];
    DWORD size;

    if (
        GetVolumePathNamesForVolumeNameA(volumeName.toLatin1().data(), mountedLetters, sizeof(mountedLetters), &size)
        &&
        size > 1
       )
    {
        (*diskPath)[0] = mountedLetters[0];

        thread->addLog(QCoreApplication::translate("BurnThread", "Disk already mounted to %1").arg(*diskPath));

        return;
    }



    if (!SetVolumeMountPointA(diskPath->toLatin1().data(), volumeName.toLatin1().data()))
    {
        qCritical() << "SetVolumeMountPoint failed:" << GetLastError();

        thread->addLog(QCoreApplication::translate("BurnThread", "Failed to mount disk"));

        thread->stop();

        return;
    }
}

void mountVolume(BurnThread *thread, QString *diskPath)
{
    Q_ASSERT(thread);
    Q_ASSERT(diskPath);



    thread->addLog(QCoreApplication::translate("BurnThread", "Mounting disk volume %1").arg(*diskPath));



    mountVolumeByGuid(thread, diskPath, getLogicalName(thread) + "\\");
}

void copyFiles(BurnThread *thread, const QString &diskPath)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Copying files to disk"));



    if (!QDir().mkpath(diskPath + "/EFI/BOOT"))
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "Failed to create folder %1").arg(diskPath + "/EFI/BOOT"));

        thread->stop();

        return;
    }



    if (!QFile(thread->getBinariesPath() + "/NGOS_installer.bin").copy(diskPath + "/EFI/BOOT/bootx64.efi"))
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "Failed to copy file %1").arg("NGOS_installer.bin"));

        thread->stop();

        return;
    }
}

void createAutorun(BurnThread *thread, const QString &diskPath)
{
    Q_ASSERT(thread);



    thread->addLog(QCoreApplication::translate("BurnThread", "Create autorun.inf file"));



    if (!QFile(":/assets/images/icon.ico").copy(diskPath + "icon.ico"))
    {
        thread->addLog(QCoreApplication::translate("BurnThread", "Failed to copy file %1").arg(":/assets/images/icon.ico"));

        thread->stop();

        return;
    }



    QSettings settings(diskPath + "autorun.inf", QSettings::IniFormat);

    settings.beginGroup("autorun");
    settings.setValue("label", "NGOS installer boot flash");
    settings.setValue("icon", "icon.ico");
    settings.endGroup();
}

void remountVolume(BurnThread *thread, const QString &diskPath)
{
    Q_ASSERT(thread);



    if (!DeleteVolumeMountPointA(diskPath.toLatin1().data()))
    {
        qCritical() << "DeleteVolumeMountPoint failed:" << GetLastError();

        thread->stop();

        return;
    }



    mountVolume(thread, (QString *) &diskPath);
}

void BurnThread::run()
{
    currentStep = 0;



    QString diskPath;

    unmountVolumes(this, &diskPath);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();

    formatDisk(this);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();

    mountVolume(this, &diskPath);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();

    copyFiles(this, diskPath);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();

    createAutorun(this, diskPath);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();

    remountVolume(this, diskPath);
    notifyNextStep(this);
    CHECK_IF_TERMINATED();
}



#endif
