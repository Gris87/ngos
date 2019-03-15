#include "mainwindow.h"



#ifdef Q_OS_WIN

#include <QDebug>
#include <Windows.h>
#include <SetupAPI.h>
#include <cfgmgr32.h>

#include "src/other/usbproperties.h"



#define UASPSTOR_INDEX 4
#define SD_INDEX       1



const GUID USB_HUB_GUID = { 0xF18A0E88, 0xC30C, 0x11D0, {0x88, 0x15, 0x00, 0xA0, 0xC9, 0x06, 0xBE, 0xD8} };
const GUID DISK_GUID    = { 0x53F56307, 0xB6BF, 0x11D0, {0x94, 0xF2, 0x00, 0xA0, 0xC9, 0x1E, 0xFB, 0x8B} };

const QStringList usbStorageDrivers = QStringList()
        // Standard MS USB storage driver
        << "USBSTOR"
        // USB card readers, with proprietary drivers (Realtek, etc...)
        // Mostly "guessed" from http://www.carrona.org/dvrref.php
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
        // Also http://www.carrona.org/dvrref.php.
        << "SD" << "PCISTOR" << "RTSOR" << "JMCR" << "JMCF" << "RIMMPTSK" << "RIMSPTSK" << "RIXDPTSK" << "TI21SONY" << "ESD7SK" << "ESM7SK" << "O2MD" << "O2SD" << "VIACR"
    ;



void updateUsbs()
{
    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&USB_HUB_GUID, 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

    if (deviceInfoSet != INVALID_HANDLE_VALUE)
    {
        SP_DEVINFO_DATA deviceInfoData;
        deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);



        DWORD memberIndex = 0;

        while (SetupDiEnumDeviceInfo(deviceInfoSet, memberIndex, &deviceInfoData))
        {
            qDebug() << "USB Hub #" << memberIndex << "found";



            SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
            deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);



            if (SetupDiEnumDeviceInterfaces(deviceInfoSet, &deviceInfoData, &USB_HUB_GUID, 0, &deviceInterfaceData))
            {
                DWORD requiredSize;

                if (
                    !SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, 0, 0, &requiredSize, 0)
                    &&
                    GetLastError() == ERROR_INSUFFICIENT_BUFFER
                   )
                {
                    SP_DEVICE_INTERFACE_DETAIL_DATA_W *deviceInterfaceDetailData = (SP_DEVICE_INTERFACE_DETAIL_DATA_W *)malloc(requiredSize);

                    if (deviceInterfaceDetailData)
                    {
                        deviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W);

                        if (SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, deviceInterfaceDetailData, requiredSize, 0, 0))
                        {
                            DEVINST deviceInstance;

                            if (CM_Get_Child(&deviceInstance, deviceInfoData.DevInst, 0) == CR_SUCCESS)
                            {
                                QString deviceInterfacePath = QString::fromWCharArray(deviceInterfaceDetailData->DevicePath);
                                qDebug() << "    USB Hub path =" << deviceInterfacePath;



                                wchar_t   deviceId[MAX_PATH];
                                CONFIGRET ret = CM_Get_Device_ID(deviceInstance, deviceId, MAX_PATH, 0);

                                if (ret == CR_SUCCESS)
                                {
                                    QString deviceIdString = QString::fromWCharArray(deviceId);
                                    qDebug() << "        USB found:" << deviceIdString;

                                    while (CM_Get_Sibling(&deviceInstance, deviceInstance, 0) == CR_SUCCESS)
                                    {
                                        ret = CM_Get_Device_ID(deviceInstance, deviceId, MAX_PATH, 0);

                                        if (ret == CR_SUCCESS)
                                        {
                                            QString deviceIdString = QString::fromWCharArray(deviceId);
                                            qDebug() << "        USB found:" << deviceIdString;
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
            else
            {
                qCritical() << "SetupDiEnumDeviceInterfaces failed:" << GetLastError();
            }



            ++memberIndex;
        }



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

void handleDiskEnumeratorName(const QString &enumeratorName, UsbProperties *props)
{
    qint64 index = usbStorageDrivers.indexOf(enumeratorName);

    if (index >= 0)
    {
        props->isUSB = true;

        if (index > 0 && index < UASPSTOR_INDEX)
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
    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_ENUMERATOR_NAME, 0, 0, 0, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_ENUMERATOR_NAME, &propertyRegDataType, buffer, requiredSize, 0))
            {
                QString enumeratorName = QString::fromWCharArray((wchar_t *)buffer);
                qDebug() << "    Disk enumerator:" << enumeratorName;



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
    checkDiskIsVHDFromHardwareId(hardwareId, props);
    checkDiskIsCardFromHardwareId(hardwareId, props);
}

void handleDiskHardwareId(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_HARDWAREID, 0, 0, 0, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_HARDWAREID, &propertyRegDataType, buffer, requiredSize, 0))
            {
                QString hardwareId = QString::fromWCharArray((wchar_t *)buffer);
                qDebug() << "    Hardware ID:" << hardwareId;



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
    props->isRemovable = removalPolicy == CM_REMOVAL_POLICY_EXPECT_ORDERLY_REMOVAL
                        ||
                        removalPolicy  == CM_REMOVAL_POLICY_EXPECT_SURPRISE_REMOVAL;
}

void handleDiskRemovalPolicy(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_REMOVAL_POLICY, 0, 0, 0, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_REMOVAL_POLICY, &propertyRegDataType, buffer, requiredSize, 0))
            {
                DWORD removalPolicy = *((DWORD*)buffer);
                qDebug() << "    Removal policy:" << removalPolicy;



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

void handleDiskFriendlyName(const HDEVINFO &deviceInfoSet, SP_DEVINFO_DATA &deviceInfoData, UsbProperties *props)
{
    DWORD requiredSize;

    if (
        !SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_FRIENDLYNAME, 0, 0, 0, &requiredSize)
        &&
        GetLastError() == ERROR_INSUFFICIENT_BUFFER
       )
    {
        BYTE *buffer = (BYTE *)malloc(requiredSize);

        if (buffer)
        {
            DWORD propertyRegDataType;

            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_FRIENDLYNAME, &propertyRegDataType, buffer, requiredSize, 0))
            {
                QString friendlyName = QString::fromWCharArray((wchar_t *)buffer);
                qDebug() << "    Friendly name:" << friendlyName;



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


void updateDisks()
{
    Q_ASSERT(UASPSTOR_INDEX == usbStorageDrivers.indexOf("UASPSTOR"));
    Q_ASSERT(SD_INDEX       == genericStorageDrivers.indexOf("SD"));



    QList<ULONG> listSizes;

    for (qint64 i = 0; i < usbStorageDrivers.length(); ++i)
    {
        ULONG listSize;



        CONFIGRET ret = CM_Get_Device_ID_List_SizeA(&listSize, usbStorageDrivers.at(i).toLatin1().constData(), CM_GETIDLIST_FILTER_SERVICE | CM_GETIDLIST_FILTER_PRESENT);

        if (ret == CR_SUCCESS)
        {
            listSizes.append(listSize);
        }
        else
        {
            qWarning() << "CM_Get_Device_ID_List_SizeA failed:" << ret;

            listSizes.append(0);
        }
    }



    QList<QStringList> deviceIdList;

    for (qint64 i = 0; i < usbStorageDrivers.length(); ++i)
    {
        QString usbStorageDriver = usbStorageDrivers.at(i);
        ULONG   listSize         = listSizes.at(i);

        QStringList deviceIds;



        if (listSize > 1)
        {
            char *buffer = (char *)malloc(listSize);

            if (buffer)
            {
                CONFIGRET ret = CM_Get_Device_ID_ListA(usbStorageDriver.toLatin1().constData(), buffer, listSize, CM_GETIDLIST_FILTER_SERVICE | CM_GETIDLIST_FILTER_PRESENT);

                if (ret == CR_SUCCESS)
                {
                    qDebug() << "IDs belonging to" << usbStorageDriver;



                    char *deviceId = buffer;

                    while (*deviceId)
                    {
                        qDebug() << deviceId;

                        deviceIds.append(QString(deviceId));
                        deviceId += strlen(deviceId) + 1;
                    }
                }
                else
                {
                    qWarning() << "CM_Get_Device_ID_ListA failed:" << ret;
                }



                free(buffer);
            }
            else
            {
                qCritical() << "malloc failed";
            }
        }



        deviceIdList.append(deviceIds);
    }



    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&DISK_GUID, 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

    if (deviceInfoSet != INVALID_HANDLE_VALUE)
    {
        SP_DEVINFO_DATA deviceInfoData;
        deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);



        DWORD memberIndex = 0;

        while (SetupDiEnumDeviceInfo(deviceInfoSet, memberIndex, &deviceInfoData))
        {
            qDebug() << "Disk #" << memberIndex << "found";



            UsbProperties props;
            memset(&props, 0, sizeof(UsbProperties));



            handleDiskEnumeratorName(deviceInfoSet, deviceInfoData, &props);

            if (props.isUSB || props.isSCSI)
            {
                handleDiskHardwareId(deviceInfoSet, deviceInfoData, &props);
                handleDiskRemovalPolicy(deviceInfoSet, deviceInfoData, &props);
                handleDiskFriendlyName(deviceInfoSet, deviceInfoData, &props);
            }
            else
            {
                qDebug() << "    Ignoring this disk since it is not USB/SCSI disk";
            }



            ++memberIndex;
        }



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

void MainWindow::updateUsbDevices()
{
    updateUsbs();
    updateDisks();
}



#endif
