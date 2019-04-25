#ifndef USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H
#define USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H



#include <QThread>

#include "src/other/usbdeviceinfo.h"



class BurnThread: public QThread
{
    Q_OBJECT

public:
    BurnThread(UsbDeviceInfo *deviceInfo, const QString binariesPath); // TEST: NO

    void stop(); // TEST: NO

    void addLog(const QString &text); // TEST: NO
    void notifyProgress(quint8 current, quint8 maximum); // TEST: NO

    const UsbDeviceInfo& getSelectedUsb() const; // TEST: NO
    const QString& getBinariesPath() const; // TEST: NO
    bool isWorking() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool          mIsRunning;
    UsbDeviceInfo mSelectedUsb;
    QString       mBinariesPath;

signals:
    void logAdded(const QString &text); // TEST: NO
    void progress(quint8 current, quint8 maximum); // TEST: NO
};



#endif // USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H
