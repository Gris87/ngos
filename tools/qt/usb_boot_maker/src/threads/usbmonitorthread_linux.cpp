#include "usbmonitorthread.h"



#ifdef Q_OS_LINUX



#include <QDebug>
#include <libudev.h>



UsbMonitorThread::UsbMonitorThread()
    : QThread()
    , mIsRunning(true)
{
    // Nothing
}

void UsbMonitorThread::stop()
{
    mIsRunning = false;
}

void UsbMonitorThread::run()
{
    udev *udev = udev_new();

    if (!udev)
    {
        qCritical() << "udev_new failed";

        return;
    }



    udev_monitor *monitor = udev_monitor_new_from_netlink(udev, "udev");

    udev_monitor_filter_add_match_subsystem_devtype(monitor, "usb", nullptr);
    udev_monitor_enable_receiving(monitor);

    qint64 fd = udev_monitor_get_fd(monitor);



    timeval timeout;
    timeout.tv_sec  = 1;
    timeout.tv_usec = 0;



    while (mIsRunning)
    {
        fd_set fds;

        FD_ZERO(&fds);
        FD_SET(fd, &fds);



        select(fd + 1, &fds, nullptr, nullptr, &timeout);

        if (FD_ISSET(fd, &fds))
        {
            udev_device *dev = udev_monitor_receive_device(monitor);
            QString action(udev_device_get_action(dev));
            udev_device_unref(dev);



            if (action == "add")
            {
                emit usbStatusChanged(3000);
            }
            else
            {
                emit usbStatusChanged(1000);
            }
        }
    }



    udev_unref(udev);
}



#endif
