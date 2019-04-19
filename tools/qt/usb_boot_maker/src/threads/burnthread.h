#ifndef USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H
#define USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H



#include <QThread>

#include "src/other/usbdeviceinfo.h"



class BurnThread: public QThread
{
public:
    BurnThread(UsbDeviceInfo *deviceInfo); // TEST: NO

    void stop(); // TEST: NO

    const UsbDeviceInfo& getSelectedUsb() const; // TEST: NO
    bool isWorking() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool          mIsRunning;
    UsbDeviceInfo mSelectedUsb;
};



#endif // USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H
