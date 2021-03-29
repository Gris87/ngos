#include "mainwindow.h"



#ifdef Q_OS_WIN



#include <QDebug>
#include <QRegularExpression>
#include <QSettings>
#include <QTimer>
#include <Windows.h>
#include <cfgmgr32.h>
#include <Dbt.h>
#include <SetupAPI.h>
#include <usbioctl.h>

#include <com/ngos/devtools/usb_boot_maker/other/defines.h>
#include <com/ngos/devtools/usb_boot_maker/other/usbproperties.h>



#define NO_FLAGS           0
#define ZERO_SIZE          0
#define MEMBER_INDEX_FIRST 0

#define USB_CARD_READER_INDEX 1
#define UASPSTOR_INDEX        4
#define SD_INDEX              1



#ifndef CM_GETIDLIST_FILTER_PRESENT
#define CM_GETIDLIST_FILTER_PRESENT 0x00000100
#endif



const GUID USB_HUB_GUID = { 0xF18A0E88, 0xC30C, 0x11D0, { 0x88, 0x15, 0x00, 0xA0, 0xC9, 0x06, 0xBE, 0xD8 } };
const GUID DISK_GUID    = { 0x53F56307, 0xB6BF, 0x11D0, { 0x94, 0xF2, 0x00, 0xA0, 0xC9, 0x1E, 0xFB, 0x8B } };

const QStringList usbStorageDrivers = QStringList()
        // Standard MS USB storage driver
        << "USBSTOR"
        // USB card readers, with proprietary drivers (Realtek, etc...)
        // Mostly "guessed" from https://carrona.org/dvrref.php // Ignore LinksVerifier
        << "RTSUER" << "CMIUCR" << "EUCR"
        // UASP Drivers *MUST* be listed after this, starting with "UASPSTOR"
        // (which is Microsoft's native UASP driver for Windows 8 and later)
        // as we use "UASPSTOR" as a delimiter
        << "UASPSTOR" << "VUSBSTOR" << "ETRONSTOR" << "ASUSSTPT"
    ;

const QStringList genericStorageDrivers = QStringList()
        // Generic storage drivers (Careful now!)
        << "SCSI" // << "STORAGE"   // "STORAGE" is used by 'Storage Spaces" and stuff => DANGEROUS!
        // Non-USB card reader drivers - This list *MUST* start with "SD" (delimiter)
        // See http://itdoc.hitachi.co.jp/manuals/3021/30213B5200e/DMDS0094.HTM
        // Also https://carrona.org/dvrref.php // Ignore LinksVerifier
        << "SD" << "PCISTOR" << "RTSOR" << "JMCR" << "JMCF" << "RIMMPTSK" << "RIMSPTSK" << "RIXDPTSK" << "TI21SONY" << "ESD7SK" << "ESM7SK" << "O2MD" << "O2SD" << "VIACR"
    ;

const QRegularExpression vidPidRegExp("^.+\\\\VID_([0-9a-fA-F]+)&PID_([0-9a-fA-F]+)\\\\.+$");



// Redefine VOLUME_DISK_EXTENTS from winioctl.h with the more space for Extents
struct VOLUME_DISK_EXTENTS_REDEF
{
    DWORD       numberOfDiskExtents;
    DISK_EXTENT extents[8];
};



bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) // Ignore CppTypesVerifier
{
    MSG *msg = (MSG *)message;

    switch (msg->message)
    {
        case WM_DEVICECHANGE:
        {
            switch (msg->wParam)
            {
                case DBT_DEVICEARRIVAL:
                case DBT_DEVICEREMOVECOMPLETE:
                case DBT_DEVNODES_CHANGED:
                {
                    usbStatusChanged(1000);
                }
                break;

                default:
                {
                    qCritical() << "Unexpected wParam:" << msg->wParam;
                }
                break;
            }
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }

    return QMainWindow::nativeEvent(eventType, message, result);
}

void handleUsbHubChildren(const SP_DEVINFO_DATA &deviceInfoData, const QString &deviceInterfacePath, QHash<QString, QString> *deviceIdToDeviceInterfacePathHash)
{
    Q_ASSERT(deviceIdToDeviceInterfacePathHash);



    DEVINST deviceInstance;

    if (CM_Get_Child(&deviceInstance, deviceInfoData.DevInst, NO_FLAGS) == CR_SUCCESS)
    {
        wchar_t   deviceId[MAX_PATH];
        CONFIGRET ret = CM_Get_Device_ID(deviceInstance, deviceId, MAX_PATH, NO_FLAGS);

        if (ret == CR_SUCCESS)
        {
            QString deviceIdString = QString::fromWCharArray(deviceId);
            qDebug() << "        USB found:" << deviceIdString; // Ignore CppAlignmentVerifier

            deviceIdToDeviceInterfacePathHash->insert(deviceIdString, deviceInterfacePath);



            while (CM_Get_Sibling(&deviceInstance, deviceInstance, NO_FLAGS) == CR_SUCCESS)
            {
                ret = CM_Get_Device_ID(deviceInstance, deviceId, MAX_PATH, NO_FLAGS);

                if (ret == CR_SUCCESS)
                {
                    QString deviceIdString = QString::fromWCharArray(deviceId);
                    qDebug() << "        USB found:" << deviceIdString; // Ignore CppAlignmentVerifier

                    deviceIdToDeviceInterfacePathHash->insert(deviceIdString, deviceInterfacePath);
                }
                else
                {
                    qWarning() << "CM_Get_Device_ID failed:" << ret;
                }
            }
        }
        else
        {
            qWarning() << "CM_Get_Device_ID failed:" << ret;
        }
    }
    else
    {
        // qWarning() << "CM_Get_Child failed"; // Commented to avoid not interesting warnings
    }
}

void handleUsbHubInterfaceData(const HDEVINFO &deviceInfoSet, const SP_DEVINFO_DATA &deviceInfoData, SP_DEVICE_INTERFACE_DATA &deviceInterfaceData, QHash<QString, QString> *deviceIdToDeviceInterfacePathHash)
{
    Q_ASSERT(deviceInfoSet != INVALID_HANDLE_VALUE);
    Q_ASSERT(deviceIdToDeviceInterfacePathHash);



    DWORD requiredSize;

    if (
        !SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, nullptr, ZERO_SIZE, &requiredSize, nullptr)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        SP_DEVICE_INTERFACE_DETAIL_DATA_W *deviceInterfaceDetailData = (SP_DEVICE_INTERFACE_DETAIL_DATA_W *)malloc(requiredSize);

        if (deviceInterfaceDetailData)
        {
            deviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W);

            if (SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, deviceInterfaceDetailData, requiredSize, nullptr, nullptr))
            {
                QString deviceInterfacePath = QString::fromWCharArray(deviceInterfaceDetailData->DevicePath);
                qDebug() << "    USB Hub path:" << deviceInterfacePath; // Ignore CppAlignmentVerifier



                handleUsbHubChildren(deviceInfoData, deviceInterfacePath, deviceIdToDeviceInterfacePathHash);
            }
            else
            {
                qCritical() << "SetupDiGetDeviceInterfaceDetail failed:" << GetLastError();
            }



            free(deviceInterfaceDetailData);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }
    else
    {
        qCritical() << "SetupDiGetDeviceInterfaceDetail failed:" << GetLastError();
    }
}

void handleUsbHub(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, QHash<QString, QString> *deviceIdToDeviceInterfacePathHash)
{
    Q_ASSERT(deviceInfoSet != INVALID_HANDLE_VALUE);
    Q_ASSERT(deviceIdToDeviceInterfacePathHash);



    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);



    if (SetupDiEnumDeviceInterfaces(deviceInfoSet, &deviceInfoData, &USB_HUB_GUID, MEMBER_INDEX_FIRST, &deviceInterfaceData))
    {
        handleUsbHubInterfaceData(deviceInfoSet, deviceInfoData, deviceInterfaceData, deviceIdToDeviceInterfacePathHash);
    }
    else
    {
        qCritical() << "SetupDiEnumDeviceInterfaces failed:" << GetLastError();
    }
}

void handleUsbHubs(const HDEVINFO &deviceInfoSet, QHash<QString, QString> *deviceIdToDeviceInterfacePathHash)
{
    Q_ASSERT(deviceInfoSet != INVALID_HANDLE_VALUE);
    Q_ASSERT(deviceIdToDeviceInterfacePathHash);



    SP_DEVINFO_DATA deviceInfoData;
    deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);



    DWORD memberIndex = 0;

    while (SetupDiEnumDeviceInfo(deviceInfoSet, memberIndex, &deviceInfoData))
    {
        qDebug().nospace() << "USB Hub #" << memberIndex << " found";



        handleUsbHub(deviceInfoSet, deviceInfoData, deviceIdToDeviceInterfacePathHash);

        ++memberIndex;
    }
}

void updateUsbs(QHash<QString, QString> *deviceIdToDeviceInterfacePathHash)
{
    Q_ASSERT(deviceIdToDeviceInterfacePathHash);



    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&USB_HUB_GUID, nullptr, nullptr, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

    if (deviceInfoSet != INVALID_HANDLE_VALUE)
    {
        handleUsbHubs(deviceInfoSet, deviceIdToDeviceInterfacePathHash);



        if (!SetupDiDestroyDeviceInfoList(deviceInfoSet))
        {
            qCritical() << "SetupDiDestroyDeviceInfoList failed:" << GetLastError();
        }
    }
    else
    {
        qCritical() << "SetupDiGetClassDevs failed:" << GetLastError();
    }
}

void handleUsbStorageDriverDeviceIds(const QString &usbStorageDriver, char *buffer, QStringList &deviceIds)
{
    Q_ASSERT(buffer);



    qDebug() << "";
    qDebug() << "IDs belonging to" << usbStorageDriver;



    char *deviceId = buffer;

    while (*deviceId)
    {
        qDebug() << deviceId;



        QString deviceIdString = QString::fromLatin1(deviceId);

        deviceIds.append(deviceIdString);
        deviceId += deviceIdString.length() + 1;
    }
}

void handleUsbStorageDriverList(const QString &usbStorageDriver, ULONG listSize, QList<QStringList> *deviceIdList)
{
    Q_ASSERT(deviceIdList);



    QStringList deviceIds;



    if (listSize > 1)
    {
        char *buffer = (char *)malloc(listSize);

        if (buffer)
        {
            CONFIGRET ret = CM_Get_Device_ID_ListA(usbStorageDriver.toLatin1().constData(), buffer, listSize, CM_GETIDLIST_FILTER_SERVICE | CM_GETIDLIST_FILTER_PRESENT);

            if (ret == CR_SUCCESS)
            {
                handleUsbStorageDriverDeviceIds(usbStorageDriver, buffer, deviceIds);
            }
            else
            {
                qWarning() << "CM_Get_Device_ID_List failed:" << ret;
            }



            free(buffer);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }



    deviceIdList->append(deviceIds);
}

void getDeviceIdList(QList<QStringList> *deviceIdList)
{
    Q_ASSERT(deviceIdList);



    for (qint64 i = 0; i < usbStorageDrivers.length(); ++i)
    {
        const QString &usbStorageDriver = usbStorageDrivers.at(i);
        ULONG          listSize;



        CONFIGRET ret = CM_Get_Device_ID_List_SizeA(&listSize, usbStorageDriver.toLatin1().constData(), CM_GETIDLIST_FILTER_SERVICE | CM_GETIDLIST_FILTER_PRESENT);

        if (ret == CR_SUCCESS)
        {
            handleUsbStorageDriverList(usbStorageDriver, listSize, deviceIdList);
        }
        else
        {
            qWarning() << "CM_Get_Device_ID_List_Size failed:" << ret;
        }
    }
}

void handleDiskEnumeratorName(const QString &enumeratorName, UsbProperties *props)
{
    Q_ASSERT(props);



    qint64 index = usbStorageDrivers.indexOf(enumeratorName);

    if (index >= 0)
    {
        props->isUSB = true;

        if (index >= USB_CARD_READER_INDEX && index < UASPSTOR_INDEX)
        {
            props->isCARD = true;
        }
    }



    index = genericStorageDrivers.indexOf(enumeratorName);

    if (index >= 0)
    {
        props->isSCSI = true;

        if (index >= SD_INDEX)
        {
            props->isCARD = true;
        }
    }
}

void handleDiskEnumeratorName(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    Q_ASSERT(props);



    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_ENUMERATOR_NAME, nullptr, nullptr, ZERO_SIZE, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_ENUMERATOR_NAME, &propertyRegDataType, buffer, requiredSize, nullptr))
            {
                QString enumeratorName = QString::fromWCharArray((wchar_t *)buffer);
                qDebug() << "    Disk enumerator:" << enumeratorName; // Ignore CppAlignmentVerifier



                handleDiskEnumeratorName(enumeratorName, props);
            }
            else
            {
                qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
            }



            free(buffer);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }
    else
    {
        qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
    }
}

void checkDiskIsVHDFromHardwareId(const QString &hardwareId, UsbProperties *props)
{
    Q_ASSERT(props);



    props->isVHD = hardwareId.contains("Arsenal_________Virtual_")
                    ||
                    hardwareId.contains("KernSafeVirtual_________")
                    ||
                    hardwareId.contains("Msft____Virtual_Disk____")
                    ||
                    hardwareId.contains("VMware__VMware_Virtual_S");
}

void checkDiskIsCardFromHardwareId(const QString &hardwareId, UsbProperties *props)
{
    Q_ASSERT(props);



    if (
        !props->isCARD
        &&
        hardwareId.startsWith("SCSI\\Disk")
        &&
        (
         hardwareId.contains("_SD_")
         ||
         hardwareId.contains("_SD&")
         ||
         hardwareId.contains("_SDHC_")
         ||
         hardwareId.contains("_SDHC&")
         ||
         hardwareId.contains("_MMC_")
         ||
         hardwareId.contains("_MMC&")
         ||
         hardwareId.contains("_MS_")
         ||
         hardwareId.contains("_MS&")
         ||
         hardwareId.contains("_MSPro_")
         ||
         hardwareId.contains("_MSPro&")
         ||
         hardwareId.contains("_xDPicture_")
         ||
         hardwareId.contains("_xDPicture&")
         ||
         hardwareId.contains("_O2Media_")
         ||
         hardwareId.contains("_O2Media&")
        )
       )
    {
        props->isCARD = true;
    }
}

void handleDiskHardwareId(const QString &hardwareId, UsbProperties *props)
{
    Q_ASSERT(props);



    checkDiskIsVHDFromHardwareId(hardwareId, props);
    checkDiskIsCardFromHardwareId(hardwareId, props);
}

void handleDiskHardwareId(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    Q_ASSERT(props);



    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_HARDWAREID, nullptr, nullptr, ZERO_SIZE, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_HARDWAREID, &propertyRegDataType, buffer, requiredSize, nullptr))
            {
                QString hardwareId = QString::fromWCharArray((wchar_t *)buffer);
                qDebug() << "    Hardware ID:" << hardwareId; // Ignore CppAlignmentVerifier



                handleDiskHardwareId(hardwareId, props);
            }
            else
            {
                qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
            }



            free(buffer);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }
    else
    {
        qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
    }
}

void handleDiskRemovalPolicy(DWORD removalPolicy, UsbProperties *props)
{
    Q_ASSERT(props);



    props->isRemovable = removalPolicy == CM_REMOVAL_POLICY_EXPECT_ORDERLY_REMOVAL
                        ||
                        removalPolicy == CM_REMOVAL_POLICY_EXPECT_SURPRISE_REMOVAL;
}

void handleDiskRemovalPolicy(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    Q_ASSERT(props);



    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_REMOVAL_POLICY, nullptr, nullptr, ZERO_SIZE, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_REMOVAL_POLICY, &propertyRegDataType, buffer, requiredSize, nullptr))
            {
                DWORD removalPolicy = *(DWORD *)buffer;
                qDebug() << "    Removal policy:" << removalPolicy; // Ignore CppAlignmentVerifier



                handleDiskRemovalPolicy(removalPolicy, props);
            }
            else
            {
                qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
            }



            free(buffer);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }
    else
    {
        qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
    }
}

void handleDiskFriendlyName(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData)
{
    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_FRIENDLYNAME, nullptr, nullptr, ZERO_SIZE, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_FRIENDLYNAME, &propertyRegDataType, buffer, requiredSize, nullptr))
            {
                QString friendlyName = QString::fromWCharArray((wchar_t *)buffer);
                qDebug() << "    Friendly name:" << friendlyName; // Ignore CppAlignmentVerifier
            }
            else
            {
                qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
            }



            free(buffer);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }
    else
    {
        qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
    }
}

void getVidPidFromDeviceId(const QString &deviceId, UsbProperties *props)
{
    Q_ASSERT(props);



    QRegularExpressionMatch match = vidPidRegExp.match(deviceId);

    if (match.hasMatch())
    {
        QString vid = match.captured(1);
        QString pid = match.captured(2);



        bool ok;

        props->vid = vid.toUInt(&ok, 16);
        Q_ASSERT(ok);

        props->pid = pid.toUInt(&ok, 16);
        Q_ASSERT(ok);



        qDebug() << "    VID:" << vid << '(' << props->vid << ')';
        qDebug() << "    PID:" << pid << '(' << props->pid << ')';
    }
    else
    {
        qWarning() << "Failed to find VID/PID for device id:" << deviceId;
    }
}

bool getUsbConnectionInfoV1(const HANDLE &deviceHandle, UsbProperties *props)
{
    Q_ASSERT(props);



    USB_NODE_CONNECTION_INFORMATION_EX connectionInfoEx;

    DWORD size = sizeof(connectionInfoEx);
    memset(&connectionInfoEx, 0, size);

    connectionInfoEx.ConnectionIndex = (ULONG)props->port;



    if (DeviceIoControl(deviceHandle, IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX, &connectionInfoEx, size, &connectionInfoEx, size, &size, nullptr))
    {
        if (
            connectionInfoEx.DeviceDescriptor.idVendor != 0
            ||
            connectionInfoEx.DeviceDescriptor.idProduct != 0
           )
        {
            props->vid   = connectionInfoEx.DeviceDescriptor.idVendor;
            props->pid   = connectionInfoEx.DeviceDescriptor.idProduct;
            props->speed = (UsbSpeed)(connectionInfoEx.Speed + 1);

            qDebug() << "    VID:"   << props->vid;
            qDebug() << "    PID:"   << props->pid;
            qDebug() << "    Speed:" << (quint64)props->speed;



            return true;
        }
    }
    else
    {
        qCritical() << "DeviceIoControl failed:" << GetLastError();
    }



    return false;
}

void getUsbConnectionInfoV2(const HANDLE &deviceHandle, UsbProperties *props)
{
    Q_ASSERT(props != nullptr);



    USB_NODE_CONNECTION_INFORMATION_EX_V2 connectionInfoExV2;

    DWORD size = sizeof(connectionInfoExV2);
    memset(&connectionInfoExV2, 0, size);

    connectionInfoExV2.ConnectionIndex              = (ULONG)props->port;
    connectionInfoExV2.Length                       = size;
    connectionInfoExV2.SupportedUsbProtocols.Usb300 = true;



    if (DeviceIoControl(deviceHandle, IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2, &connectionInfoExV2, size, &connectionInfoExV2, size, &size, nullptr))
    {
        if (connectionInfoExV2.Flags.DeviceIsOperatingAtSuperSpeedOrHigher)
        {
            props->speed = UsbSpeed::SUPER_OR_LATER;
        }
        else
        if (connectionInfoExV2.Flags.DeviceIsSuperSpeedCapableOrHigher)
        {
            props->isLowerSpeed = true;
        }
    }
    else
    {
        qCritical() << "DeviceIoControl failed:" << GetLastError();
    }
}

void getUsbConnectionInfo(const HANDLE &deviceHandle, UsbProperties *props)
{
    Q_ASSERT(props != nullptr);



    if (getUsbConnectionInfoV1(deviceHandle, props))
    {
        getUsbConnectionInfoV2(deviceHandle, props);
    }
    else
    {
        qCritical() << "getUsbConnectionInfoV1 failed";
    }
}

void getUsbProperties(const QString &deviceInterfacePath, const QString &deviceID, UsbProperties *props)
{
    Q_ASSERT(props != nullptr);



    DEVINST deviceInstance;

    CONFIGRET ret = CM_Locate_DevNodeA(&deviceInstance, deviceID.toLatin1().data(), CM_LOCATE_DEVNODE_NORMAL);

    if (ret == CR_SUCCESS)
    {
        props->port = 0;

        DWORD size = sizeof(props->port);
        ret        = CM_Get_DevNode_Registry_Property(deviceInstance, CM_DRP_ADDRESS, nullptr, &props->port, &size, NO_FLAGS);

        if (ret == CR_SUCCESS)
        {
            HANDLE deviceHandle = CreateFileA(deviceInterfacePath.toLatin1().constData(), GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);

            if (deviceHandle != INVALID_HANDLE_VALUE)
            {
                getUsbConnectionInfo(deviceHandle, props);



                if (!CloseHandle(deviceHandle))
                {
                    qCritical() << "CloseHandle failed:" << GetLastError();
                }
            }
            else
            {
                qCritical() << "CreateFile failed:" << GetLastError();
            }
        }
        else
        {
            qCritical() << "CM_Get_DevNode_Registry_Property failed:" << ret;
        }
    }
    else
    {
        qCritical() << "CM_Locate_DevNode failed:" << ret;
    }
}

bool handleDeviceId(const QHash<QString, QString> &deviceIdToDeviceInterfacePathHash, QString deviceId, qint64 usbDriverIndex, const SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    Q_ASSERT(props != nullptr);



    DEVINST   parentDeviceInstance;
    CONFIGRET ret = CM_Locate_DevNodeA(&parentDeviceInstance, deviceId.toLatin1().data(), CM_LOCATE_DEVNODE_NORMAL);

    if (ret == CR_SUCCESS)
    {
        DEVINST deviceInstance;

        ret = CM_Get_Child(&deviceInstance, parentDeviceInstance, NO_FLAGS);

        if (ret == CR_SUCCESS)
        {
            if (deviceInstance != deviceInfoData.DevInst)
            {
                while (CM_Get_Sibling(&deviceInstance, deviceInstance, 0) == CR_SUCCESS)
                {
                    if (deviceInstance == deviceInfoData.DevInst)
                    {
                        break;
                    }
                }

                if (deviceInstance != deviceInfoData.DevInst)
                {
                    qCritical() << "Failed to find child device in parent";

                    return false;
                }
            }



            props->isUASP = (usbDriverIndex >= UASPSTOR_INDEX);

            getVidPidFromDeviceId(deviceId, props);



            QString deviceInterfacePath = deviceIdToDeviceInterfacePathHash.value(deviceId, "");
            qDebug() << "    Device interface path:" << deviceInterfacePath; // Ignore CppAlignmentVerifier



            if (deviceInterfacePath == "")
            {
                DEVINST grandparentDeviceInstance;
                ret = CM_Get_Parent(&grandparentDeviceInstance, parentDeviceInstance, 0);

                if (ret == CR_SUCCESS)
                {
                    wchar_t grandparentDeviceId[MAX_PATH];
                    ret = CM_Get_Device_ID(grandparentDeviceInstance, grandparentDeviceId, MAX_PATH, NO_FLAGS);

                    if (ret == CR_SUCCESS)
                    {
                        deviceId            = QString::fromWCharArray(grandparentDeviceId);
                        deviceInterfacePath = deviceIdToDeviceInterfacePathHash.value(deviceId, "");
                    }
                    else
                    {
                        qCritical() << "CM_Get_Device_ID failed:" << ret;
                    }
                }
                else
                {
                    qCritical() << "CM_Get_Parent failed:" << ret;
                }
            }



            if (deviceInterfacePath != "")
            {
                getUsbProperties(deviceInterfacePath, deviceId, props);
            }
            else
            {
                qWarning() << "Failed to get USB properties";
            }



            return true;
        }
        else
        {
            qCritical() << "CM_Get_Child failed:" << ret;
        }
    }
    else
    {
        qCritical() << "CM_Locate_DevNode failed:" << ret;
    }



    return false;
}

void handleDeviceIds(const QHash<QString, QString> &deviceIdToDeviceInterfacePathHash, const QList<QStringList> &deviceIdList, const SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    Q_ASSERT(props != nullptr);



    if (!props->isVHD)
    {
        for (qint64 i = 0; i < deviceIdList.length(); ++i)
        {
            const QStringList &deviceIds = deviceIdList.at(i);

            for (qint64 j = 0; j < deviceIds.length(); ++j)
            {
                if (handleDeviceId(deviceIdToDeviceInterfacePathHash, deviceIds.at(j), i, deviceInfoData, props))
                {
                    return;
                }
            }
        }
    }
}

bool checkDeviceType(UsbProperties *props)
{
    Q_ASSERT(props != nullptr);



    qDebug() << "";

    if (props->isVHD)
    {
        qDebug() << "    Found VHD device";
    }
    else
    if (
        props->isCARD
        &&
        (
         !props->isUSB
         ||
         (
          props->vid == 0
          &&
          props->pid == 0
         )
        )
       )
    {
        qDebug() << "    Found card reader device";
    }
    else
    if (
        !props->isUSB
        &&
        !props->isUASP
        &&
        props->isRemovable
       )
    {
        qDebug() << "    Found non-USB removable device";

        return false;
    }
    else
    {
        if (
            !props->isUSB
            &&
            props->vid == 0
            &&
            props->pid == 0
           )
        {
            qDebug() << "    Found non-USB non-removable device";

            return false;
        }



        qDebug().nospace() << "    Found " << (props->isUASP ? "UAS (" : "") << enumToHumanString(props->speed) << (props->isUASP ? ")" : "") << " device"; // Ignore CppSingleCharVerifier

        if (props->isLowerSpeed)
        {
            qDebug() << "    NOTE: This device is an USB 3.0 device operating at lower speed...";
        }
    }



    return true;
}

DWORD getDiskNumber(const HANDLE &deviceHandle)
{
    VOLUME_DISK_EXTENTS_REDEF diskExtents;
    STORAGE_DEVICE_NUMBER     deviceNumber;
    DWORD                     size;



    if (DeviceIoControl(deviceHandle, IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS, nullptr, ZERO_SIZE, &diskExtents, sizeof(diskExtents), &size, nullptr))
    {
        // qDebug() << "        NumberOfDiskExtents:" << diskExtents.NumberOfDiskExtents;

        if (diskExtents.numberOfDiskExtents == 1)
        {
            return diskExtents.extents[0].DiskNumber;
        }
        else
        {
            qWarning() << "Ignoring disk since it belongs to RAID array";
        }
    }
    else
    if (DeviceIoControl(deviceHandle, IOCTL_STORAGE_GET_DEVICE_NUMBER, nullptr, ZERO_SIZE, &deviceNumber, sizeof(deviceNumber), &size, nullptr))
    {
        return deviceNumber.DeviceNumber;
    }
    else
    {
        qCritical() << "Failed to get device number";
    }



    return -1;
}

HANDLE getDiskHandle(DWORD diskNumber)
{
    QString diskPath = "\\\\.\\PhysicalDrive" + QString::number(diskNumber);

    return CreateFileA(diskPath.toLatin1().constData(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
}

qint64 getDiskSize(DWORD diskNumber)
{
    qint64 res = 0;



    HANDLE diskHandle = getDiskHandle(diskNumber);

    if (diskHandle != INVALID_HANDLE_VALUE)
    {
        DWORD size;
        BYTE  geometry[256];

        if (
            DeviceIoControl(diskHandle, IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, nullptr, ZERO_SIZE, geometry, sizeof(geometry), &size, nullptr)
            &&
            size > 0
           )
        {
            res = ((DISK_GEOMETRY_EX *)geometry)->DiskSize.QuadPart;
        }



        if (!CloseHandle(diskHandle))
        {
            qCritical() << "CloseHandle failed:" << GetLastError();
        }
    }



    return res;
}

QString diskSizeHumanReadable(qint64 diskSize)
{
    if (diskSize >= 1000000000000)
    {
        return QString::number(diskSize / 1000000000000) + "TB";
    }

    if (diskSize >= 1000000000)
    {
        return QString::number(diskSize / 1000000000) + "GB";
    }

    return QString::number(diskSize / 1000000) + "MB";
}

void getDiskLetters(DWORD diskNumber, char *letters)
{
    Q_ASSERT(letters);



    char *curLetter = &letters[0];



    char  drives[128];
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



            UINT driveType = GetDriveTypeA(drive);

            if (
                driveType != DRIVE_REMOVABLE
                &&
                driveType != DRIVE_FIXED
               )
            {
                continue;
            }



            QString logicalDrivePath = QString("\\\\.\\%1:").arg(drive[0]);

            HANDLE driveHandle = CreateFileA(logicalDrivePath.toLatin1().constData(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

            if (driveHandle != INVALID_HANDLE_VALUE)
            {
                if (getDiskNumber(driveHandle) == diskNumber)
                {
                    *curLetter = drive[0];
                    ++curLetter;
                }



                if (!CloseHandle(driveHandle))
                {
                    qCritical() << "CloseHandle failed:" << GetLastError();
                }
            }
        }
    }
    else
    {
        qCritical() << "size is invalid";
    }



    *curLetter = 0;
}

QString diskLettersHumanReadable(DWORD diskNumber, char *letters)
{
    if (letters[0] == 0)
    {
        return "Disk " + QString::number(diskNumber);
    }



    QString res;

    for (char *letter = letters; *letter; ++letter)
    {
        if (letter != letters)
        {
            res += ' ';
        }

        res += QString("%1:").arg(*letter);
    }

    return res;
}

QString getDiskLabel(DWORD diskNumber, char *letters)
{
    if (letters[0] != 0)
    {
        QString autorunLabel;



        HANDLE diskHandle = getDiskHandle(diskNumber);

        if (diskHandle != INVALID_HANDLE_VALUE)
        {
            DWORD size;

            if (DeviceIoControl(diskHandle, IOCTL_STORAGE_CHECK_VERIFY, nullptr, ZERO_SIZE, nullptr, ZERO_SIZE, &size, nullptr))
            {
                QSettings settings(QString("%1:/autorun.inf").arg(letters[0]), QSettings::IniFormat); // Ignore CppPunctuationVerifier

                settings.beginGroup("autorun");
                autorunLabel = settings.value("label", "").toString();
                settings.endGroup();
            }
            else
            {
                qWarning() << "DeviceIoControl failed:" << GetLastError();
            }



            if (!CloseHandle(diskHandle))
            {
                qCritical() << "CloseHandle failed:" << GetLastError();
            }
        }



        if (autorunLabel != "")
        {
            return autorunLabel;
        }



        wchar_t volumeLabel[MAX_PATH];
        wchar_t diskPath[] = { (wchar_t)letters[0], ':', '\\', 0 };

        if (GetVolumeInformation(diskPath, volumeLabel, sizeof(volumeLabel), nullptr, nullptr, nullptr, nullptr, ZERO_SIZE))
        {
            QString volumeLabelString = QString::fromWCharArray(volumeLabel);

            if (volumeLabelString != "")
            {
                return volumeLabelString;
            }
        }
        else
        {
            qWarning() << "DeviceIoControl failed:" << GetLastError();
        }
    }



    return "NO_LABEL";
}

void handleDiskDeviceHandle(const HANDLE &deviceHandle, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(deviceHandle != INVALID_HANDLE_VALUE);
    Q_ASSERT(usbDevices);



    DWORD diskNumber = getDiskNumber(deviceHandle);
    qDebug() << "        Disk number:" << diskNumber; // Ignore CppAlignmentVerifier



    qint64 diskSize = getDiskSize(diskNumber);
    qDebug() << "        Disk size:" << (diskSize / 1000000) << "MB"; // Ignore CppAlignmentVerifier

    if (diskSize == 0)
    {
        qCritical() << "Device without media";

        return;
    }

    if (diskSize < MIN_DISK_SIZE)
    {
        qCritical() << "Disk is too small";

        return;
    }



    char diskLetters[27];

    getDiskLetters(diskNumber, diskLetters);
    qDebug() << "        Disk letters:" << diskLetters; // Ignore CppAlignmentVerifier



    QString diskLabel = getDiskLabel(diskNumber, diskLetters);
    qDebug() << "        Disk label:" << diskLabel; // Ignore CppAlignmentVerifier



    UsbDeviceInfo *deviceInfo = new UsbDeviceInfo();

    deviceInfo->title      = QString("%1 (%2) [%3]").arg(diskLabel).arg(diskLettersHumanReadable(diskNumber, diskLetters)).arg(diskSizeHumanReadable(diskSize));
    deviceInfo->diskNumber = diskNumber;
    deviceInfo->diskSize   = diskSize;
    deviceInfo->letters    = diskLetters;
    deviceInfo->deviceName = "";

    usbDevices->append(deviceInfo);
}

void handleDiskDeviceInterfacePath(const QString &deviceInterfacePath, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(usbDevices);



    HANDLE deviceHandle = CreateFileA(deviceInterfacePath.toLatin1().constData(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (deviceHandle != INVALID_HANDLE_VALUE)
    {
        handleDiskDeviceHandle(deviceHandle, usbDevices);



        if (!CloseHandle(deviceHandle))
        {
            qCritical() << "CloseHandle failed:" << GetLastError();
        }
    }
    else
    {
        qCritical() << "CreateFile failed:" << GetLastError();
    }
}

void handleDiskInterfaceData(const HDEVINFO &deviceInfoSet, SP_DEVICE_INTERFACE_DATA &deviceInterfaceData, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(deviceInfoSet != INVALID_HANDLE_VALUE);
    Q_ASSERT(usbDevices    != nullptr);



    DWORD requiredSize;

    if (
        !SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, nullptr, ZERO_SIZE, &requiredSize, nullptr)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        SP_DEVICE_INTERFACE_DETAIL_DATA_W *deviceInterfaceDetailData = (SP_DEVICE_INTERFACE_DETAIL_DATA_W *)malloc(requiredSize);

        if (deviceInterfaceDetailData)
        {
            deviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W);

            if (SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, deviceInterfaceDetailData, requiredSize, nullptr, nullptr))
            {
                QString deviceInterfacePath = QString::fromWCharArray(deviceInterfaceDetailData->DevicePath);
                qDebug() << "        Disk path:" << deviceInterfacePath; // Ignore CppAlignmentVerifier



                handleDiskDeviceInterfacePath(deviceInterfacePath, usbDevices);
            }
            else
            {
                qCritical() << "SetupDiGetDeviceInterfaceDetail failed:" << GetLastError();
            }



            free(deviceInterfaceDetailData);
        }
        else
        {
            qCritical() << "malloc failed";
        }
    }
    else
    {
        qCritical() << "SetupDiGetDeviceInterfaceDetail failed:" << GetLastError();
    }
}

void handleDiskInterfaces(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(deviceInfoSet != INVALID_HANDLE_VALUE);
    Q_ASSERT(usbDevices);



    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);



    DWORD memberIndex = 0;

    do
    {
        if (!SetupDiEnumDeviceInterfaces(deviceInfoSet, &deviceInfoData, &DISK_GUID, memberIndex, &deviceInterfaceData))
        {
            if (GetLastError() == ERROR_NO_MORE_ITEMS)
            {
                qWarning() << "Device interface not found for the disk";
            }
            else
            {
                qCritical() << "SetupDiEnumDeviceInterfaces failed:" << GetLastError();
            }

            break;
        }



        qDebug() << "";
        qDebug().nospace() << "    Disk interface #" << memberIndex << " found";



        handleDiskInterfaceData(deviceInfoSet, deviceInterfaceData, usbDevices);

        ++memberIndex;
    } while(true);
}

void handleDisk(const QHash<QString, QString> &deviceIdToDeviceInterfacePathHash, const QList<QStringList> &deviceIdList, const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(usbDevices);



    UsbProperties props;
    memset(&props, 0, sizeof(UsbProperties));



    handleDiskEnumeratorName(deviceInfoSet, deviceInfoData, &props);

    if (props.isUSB || props.isSCSI)
    {
        handleDiskHardwareId(deviceInfoSet, deviceInfoData, &props);
        handleDiskRemovalPolicy(deviceInfoSet, deviceInfoData, &props);
        handleDiskFriendlyName(deviceInfoSet, deviceInfoData);

        handleDeviceIds(deviceIdToDeviceInterfacePathHash, deviceIdList, deviceInfoData, &props);



        if (checkDeviceType(&props))
        {
            handleDiskInterfaces(deviceInfoSet, deviceInfoData, usbDevices);
        }
    }
    else
    {
        qDebug() << "    Ignoring this disk since it is not USB/SCSI disk";
    }
}

void handleDisks(const QHash<QString, QString> &deviceIdToDeviceInterfacePathHash, const QList<QStringList> &deviceIdList, const HDEVINFO &deviceInfoSet, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(deviceInfoSet != INVALID_HANDLE_VALUE);
    Q_ASSERT(usbDevices);



    SP_DEVINFO_DATA deviceInfoData;
    deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);



    DWORD memberIndex = 0;

    while (SetupDiEnumDeviceInfo(deviceInfoSet, memberIndex, &deviceInfoData))
    {
        qDebug() << "";
        qDebug().nospace() << "Disk #" << memberIndex << " found";



        handleDisk(deviceIdToDeviceInterfacePathHash, deviceIdList, deviceInfoSet, deviceInfoData, usbDevices);

        ++memberIndex;
    }
}

void updateDisks(const QHash<QString, QString> &deviceIdToDeviceInterfacePathHash, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(usbDevices);



    QList<QStringList> deviceIdList;

    getDeviceIdList(&deviceIdList);



    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&DISK_GUID, nullptr, nullptr, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

    if (deviceInfoSet != INVALID_HANDLE_VALUE)
    {
        handleDisks(deviceIdToDeviceInterfacePathHash, deviceIdList, deviceInfoSet, usbDevices);



        if (!SetupDiDestroyDeviceInfoList(deviceInfoSet))
        {
            qCritical() << "SetupDiDestroyDeviceInfoList failed:" << GetLastError();
        }
    }
    else
    {
        qCritical() << "SetupDiGetClassDevs failed:" << GetLastError();
    }
}

QList<UsbDeviceInfo *> MainWindow::getUsbDevices()
{
    Q_ASSERT(USB_CARD_READER_INDEX == usbStorageDrivers.indexOf("USBSTOR") + 1);
    Q_ASSERT(UASPSTOR_INDEX        == usbStorageDrivers.indexOf("UASPSTOR"));
    Q_ASSERT(SD_INDEX              == genericStorageDrivers.indexOf("SD"));



    QList<UsbDeviceInfo *> res;



    QHash<QString, QString> deviceIdToDeviceInterfacePathHash;

    updateUsbs(&deviceIdToDeviceInterfacePathHash);
    updateDisks(deviceIdToDeviceInterfacePathHash, &res);



    return res;
}



#endif
