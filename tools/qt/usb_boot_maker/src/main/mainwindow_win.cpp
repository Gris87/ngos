#include "mainwindow.h"



#ifdef Q_OS_WIN

#include <QDebug>
#include <Windows.h>
#include <SetupAPI.h>
#include <cfgmgr32.h>

#include "src/other/usbproperties.h"



const GUID USB_HUB_GUID = { 0xF18A0E88, 0xC30C, 0x11D0, {0x88, 0x15, 0x00, 0xA0, 0xC9, 0x06, 0xBE, 0xD8} };
const GUID DISK_GUID    = { 0x53F56307, 0xB6BF, 0x11D0, {0x94, 0xF2, 0x00, 0xA0, 0xC9, 0x1E, 0xFB, 0x8B} };



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

                        if (SetupDiGetDeviceInterfaceDetail(deviceInfoSet, &deviceInterfaceData, deviceInterfaceDetailData, requiredSize, &requiredSize, 0))
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

void updateDisks()
{
    QStringList usbStorageDrivers = QStringList()
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

    QStringList genericStorageDrivers = QStringList()
            // Generic storage drivers (Careful now!)
            << "SCSI" // << "STORAGE"   // "STORAGE" is used by 'Storage Spaces" and stuff => DANGEROUS!
            // Non-USB card reader drivers - This list *MUST* start with "SD" (delimiter)
            // See http://itdoc.hitachi.co.jp/manuals/3021/30213B5200e/DMDS0094.HTM
            // Also http://www.carrona.org/dvrref.php.
            << "SD" << "PCISTOR" << "RTSOR" << "JMCR" << "JMCF" << "RIMMPTSK" << "RIMSPTSK" << "RIXDPTSK" << "TI21SONY" << "ESD7SK" << "ESM7SK" << "O2MD" << "O2SD" << "VIACR"
        ;



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



    quint8 uasptorIndex = 4;
    quint8 sdIndex      = 1;

    Q_ASSERT(uasptorIndex == usbStorageDrivers.indexOf("UASPSTOR"));
    Q_ASSERT(sdIndex      == genericStorageDrivers.indexOf("SD"));



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


            SetupDiGetDeviceRegistryPropertyW(
                _In_ HDEVINFO DeviceInfoSet,
                _In_ PSP_DEVINFO_DATA DeviceInfoData,
                _In_ DWORD Property,
                _Out_opt_ PDWORD PropertyRegDataType,
                _Out_writes_bytes_to_opt_(PropertyBufferSize, *RequiredSize) PBYTE PropertyBuffer,
                _In_ DWORD PropertyBufferSize,
                _Out_opt_ PDWORD RequiredSize
                );



            if (SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_ENUMERATOR_NAME, &datatype, buffer, sizeof(buffer), &size))
            {

            }
            else
            {
                qCritical() << "SetupDiGetDeviceRegistryProperty failed:" << GetLastError();
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
