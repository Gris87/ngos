#include "usbmonitorthread.h"                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#ifdef Q_OS_LINUX                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDebug>                                                                                                                                                                                        // Colorize: green
#include <libudev.h>                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define NO_DEVICE_TYPE   nullptr                                                                                                                                                                         // Colorize: green
#define NO_WRITE_FD_SET  nullptr                                                                                                                                                                         // Colorize: green
#define NO_EXCEPT_FD_SET nullptr                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
UsbMonitorThread::UsbMonitorThread()                                                                                                                                                                     // Colorize: green
    : QThread()                                                                                                                                                                                          // Colorize: green
    , mIsRunning(true)                                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void UsbMonitorThread::stop()                                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    mIsRunning = false;                                                                                                                                                                                  // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void UsbMonitorThread::run()                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    udev *udev = udev_new();                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (udev == nullptr)                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        qCritical() << "udev_new failed";                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return;                                                                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    udev_monitor *monitor = udev_monitor_new_from_netlink(udev, "udev");                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    udev_monitor_filter_add_match_subsystem_devtype(monitor, "usb", NO_DEVICE_TYPE);                                                                                                                     // Colorize: green
    udev_monitor_enable_receiving(monitor);                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    qint64 fd = udev_monitor_get_fd(monitor);                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    timeval timeout;                                                                                                                                                                                     // Colorize: green
    timeout.tv_sec  = 1;                                                                                                                                                                                 // Colorize: green
    timeout.tv_usec = 0;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    while (mIsRunning)                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        fd_set fds;                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        FD_ZERO(&fds);                                                                                                                                                                                   // Colorize: green
        FD_SET(fd, &fds);                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        select(fd + 1, &fds, NO_WRITE_FD_SET, NO_EXCEPT_FD_SET, &timeout);                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (FD_ISSET(fd, &fds))                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            udev_device *dev    = udev_monitor_receive_device(monitor);                                                                                                                                  // Colorize: green
            QString      action = QString::fromLatin1(udev_device_get_action(dev));                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            udev_device_unref(dev);                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (action == "add")                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                emit usbStatusChanged(3000);                                                                                                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                emit usbStatusChanged(1000);                                                                                                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    udev_unref(udev);                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // Q_OS_LINUX                                                                                                                                                                                     // Colorize: green
