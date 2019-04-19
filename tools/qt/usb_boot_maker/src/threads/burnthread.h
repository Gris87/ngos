#ifndef USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H
#define USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H



#include <QThread>



class BurnThread: public QThread
{
public:
    BurnThread(); // TEST: NO

    void stop(); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool mIsRunning;
};



#endif // USB_BOOT_MAKER_SRC_THREADS_BURNTHREAD_H
