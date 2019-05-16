#include "mainwindow.h"



#ifdef Q_OS_LINUX



#include <QDebug>
#include <QProcess>
#include <QRegularExpression>
#include <QSettings>
#include <QtMath>



#define MIN_DISK_SIZE (8 << 20) // "<< 20" == "* 1024 * 1024"



const QRegularExpression mountPointRegExp("^.+ on (.+) type .+$");



bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result) // Ignore CppTypesVerifier
{
    return QMainWindow::nativeEvent(eventType, message, result);
}

QString diskSizeHumanReadable(quint64 diskSize)
{
    if (diskSize >= 1000000000000)
    {
        return QString::number((quint64)floor(diskSize / 1000000000000.0)) + "TB";
    }

    if (diskSize >= 1000000000)
    {
        return QString::number((quint64)floor(diskSize / 1000000000.0)) + "GB";
    }

    return QString::number((quint64)floor(diskSize / 1000000.0)) + "MB";
}

QString getDiskLabel(const QString &deviceName)
{
    quint8 partitionNumber = 0;

    while (partitionNumber < 255)
    {
        ++partitionNumber;



        QProcess process;
        process.start("sh", QStringList() << "-c" << "mount | grep /dev/" + deviceName + QString::number(partitionNumber));
        process.waitForFinished(-1);



        QRegularExpressionMatch match = mountPointRegExp.match(process.readLine().trimmed());

        if (match.hasMatch())
        {
            QString mountPoint = match.captured(1);



            QSettings settings(mountPoint + "/autorun.inf", QSettings::IniFormat);

            settings.beginGroup("autorun");
            QString res = settings.value("label", "").toString();
            settings.endGroup();



            return res;
        }



        QProcess process2;
        process2.start("udevadm", QStringList() << "info" << "--query=property" << "/dev/" + deviceName + QString::number(partitionNumber));
        process2.waitForFinished(-1);



        QString res;

        while (process2.canReadLine())
        {
            QString line = process2.readLine().simplified();

            if (line.startsWith("ID_FS_LABEL_ENC="))
            {
                res = line.mid(16);
            }
            else
            if (line.startsWith("ID_FS_LABEL="))
            {
                if (res == "")
                {
                    res = line.mid(12);
                }
            }
        }

        if (res != "")
        {
            return res;
        }
    }



    return "NO_LABEL";
}

void handleDisk(const QString &deviceName, quint64 diskSize, QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(diskSize >= MIN_DISK_SIZE);
    Q_ASSERT(usbDevices);



    QProcess process;
    process.start("udevadm", QStringList() << "info" << "--query=property" << "/dev/" + deviceName);
    process.waitForFinished(-1);



    bool good = false;

    while (process.canReadLine())
    {
        QString line = process.readLine().simplified();

        if (line.startsWith("ID_BUS="))
        {
            QString bus = line.mid(7).toUpper();
            qDebug() << "    Disk bus:" << bus; // Ignore CppAlignmentVerifier

            if (bus == "USB")
            {
                good = true;
            }

            break;
        }
    }



    if (good)
    {
        QString diskLabel = getDiskLabel(deviceName);
        qDebug() << "    Disk label:" << diskLabel; // Ignore CppAlignmentVerifier



        UsbDeviceInfo *deviceInfo = new UsbDeviceInfo();

        deviceInfo->title      = QString("%1 (/dev/%2) [%3]").arg(diskLabel).arg(deviceName).arg(diskSizeHumanReadable(diskSize));
        deviceInfo->diskNumber = 0;
        deviceInfo->diskSize   = diskSize;
        deviceInfo->letters    = "";
        deviceInfo->deviceName = deviceName;

        usbDevices->append(deviceInfo);



        qDebug() << "";
        qDebug() << "    Found USB device";
    }
    else
    {
        qDebug() << "";
        qDebug() << "    Found non-USB non-removable device";
    }
}

void updateDisks(QList<UsbDeviceInfo *> *usbDevices)
{
    Q_ASSERT(usbDevices);



    QProcess process;
    process.start("lsblk", QStringList() << "--noheadings" << "--nodeps" << "--bytes");
    process.waitForFinished(-1);



    while (process.canReadLine())
    {
        QString     line  = process.readLine().simplified();
        QStringList parts = line.split(' ');

        if (parts.length() > 5 && parts.at(5) == "disk")
        {
            bool    ok;
            quint64 diskSize = parts.at(3).toULongLong(&ok);

            if (ok)
            {
                QString deviceName = parts.at(0);

                qDebug() << "";
                qDebug().nospace() << "Disk found /dev/" << deviceName.toUtf8().data() << ' ' << diskSizeHumanReadable(diskSize).toUtf8().data();



                if (diskSize >= MIN_DISK_SIZE)
                {
                    handleDisk(deviceName, diskSize, usbDevices);
                }
                else
                {
                    qCritical() << "Disk is too small:" << line;
                }
            }
            else
            {
                qCritical() << "Failed to get size for disk:" << line;
            }
        }
    }
}

QList<UsbDeviceInfo *> MainWindow::getUsbDevices()
{
    QList<UsbDeviceInfo *> res;

    updateDisks(&res);

    return res;
}



#endif
