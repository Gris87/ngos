#ifndef USB_BOOT_MAKER_SRC_COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_BURNTHREAD_H
#define USB_BOOT_MAKER_SRC_COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_BURNTHREAD_H



#include <QThread>

#include "src/com/ngos/devtools/usb_boot_maker/other/usbdeviceinfo.h"



class BurnThread: public QThread
{
    Q_OBJECT

public:
    BurnThread(UsbDeviceInfo *deviceInfo, const QString binariesPath); // TEST: NO

    void stop(); // TEST: NO

    void copyFiles(const QString &diskPath); // TEST: NO
    void createAutorun(const QString &diskPath); // TEST: NO

    void addLog(const QString &text); // TEST: NO
    void notifyProgress(quint8 current, quint8 maximum); // TEST: NO

    const UsbDeviceInfo& getSelectedUsb() const; // TEST: NO
    bool isWorking() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool copyFolder(const QString &sourceFolder, const QString &destinationFolder); // TEST: NO

    bool          mIsRunning;
    UsbDeviceInfo mSelectedUsb;
    QString       mBinariesPath;

signals:
    void logAdded(const QString &text); // TEST: NO
    void progress(quint8 current, quint8 maximum); // TEST: NO
};



#endif // USB_BOOT_MAKER_SRC_COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_BURNTHREAD_H
