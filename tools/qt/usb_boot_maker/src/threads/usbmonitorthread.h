#ifndef USB_BOOT_MAKER_SRC_THREADS_USBMONITORTHREAD_H
#define USB_BOOT_MAKER_SRC_THREADS_USBMONITORTHREAD_H



#include <QThread>



class UsbMonitorThread: public QThread
{
    Q_OBJECT

public:
    UsbMonitorThread(); // TEST: NO

    void stop(); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool mIsRunning;

signals:
    void usbStatusChanged(); // TEST: NO
};



#endif // USB_BOOT_MAKER_SRC_THREADS_USBMONITORTHREAD_H
