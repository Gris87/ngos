#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_USBMONITORTHREAD_H                                                                                                                                      // Colorize: green
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_USBMONITORTHREAD_H                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#ifdef Q_OS_LINUX                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QThread>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class UsbMonitorThread: public QThread                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_OBJECT                                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    UsbMonitorThread(); // TEST: NO                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void stop(); // TEST: NO                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
protected:                                                                                                                                                                                               // Colorize: green
    void run() override; // TEST: NO                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    bool mIsRunning;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
signals:                                                                                                                                                                                                 // Colorize: green
    void usbStatusChanged(quint16); // TEST: NO                                                                                                                                                          // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // Q_OS_LINUX                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_THREADS_USBMONITORTHREAD_H                                                                                                                                    // Colorize: green
