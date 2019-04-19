#include "mainwindow.h"



#ifdef Q_OS_LINUX



bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result) // Ignore CppTypesVerifier
{
    return QMainWindow::nativeEvent(eventType, message, result);
}

QList<UsbDeviceInfo *> MainWindow::getUsbDevices()
{
    QList<UsbDeviceInfo *> res;

    qFatal("Implement");
    // TODO: Implement

    return res;
}



#endif
