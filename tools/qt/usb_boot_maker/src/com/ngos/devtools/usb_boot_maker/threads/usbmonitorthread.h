#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_USBMONITORTHREAD_H
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_USBMONITORTHREAD_H



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
    void usbStatusChanged(quint16); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_USBMONITORTHREAD_H
