#include "mainwindow.h"



#ifdef Q_OS_WIN

#include <QDebug>
#include <Windows.h>
#include <SetupAPI.h>
#include <cfgmgr32.h>



void updateUsbs()
{
    const GUID USB_HUB_GUID = { 0xF18A0E88, 0xC30C, 0x11D0, {0x88, 0x15, 0x00, 0xA0, 0xC9, 0x06, 0xBE, 0xD8} };



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
                                            qCritical() << "CM_Get_Device_ID failed:" << ret;
                                        }
                                    }
                                }
                                else
                                {
                                    qCritical() << "CM_Get_Device_ID failed:" << ret;
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



        SetupDiDestroyDeviceInfoList(deviceInfoSet);
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



    for (qint64 i = 0; i < usbStorageDrivers.length(); ++i)
    {

    }
}

void MainWindow::updateUsbDevices()
{
    updateUsbs();
    updateDisks();
}



#endif
