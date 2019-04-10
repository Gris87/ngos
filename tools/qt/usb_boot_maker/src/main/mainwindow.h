#ifndef USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
#define USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H



#include <QMainWindow>

#include <QList>
#include <QTimer>
#include <QTranslator>

#include "src/other/usbdeviceinfo.h"
#include "src/other/usbspeed.h"



namespace Ui
{
    class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // TEST: NO
    ~MainWindow(); // TEST: NO

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result); // Ignore CppTypesVerifier

private slots:
    void on_actionExit_triggered(); // TEST: NO
    void on_actionAbout_triggered(); // TEST: NO
    void on_startButton_clicked(); // TEST: NO

    void languageToggled(bool checked); // TEST: NO
    void updateUsbDevices(); // TEST: NO

private:
    void prepareLanguages(); // TEST: NO
    QList<UsbDeviceInfo *> getUsbDevices(); // TEST: NO
    void addLog(const QString &text); // TEST: NO

    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO

    Ui::MainWindow            *ui;
    QTranslator               *mTranslator;
    QString                    mLanguage;
    QHash<QString, QAction *>  mLanguageActions;
    QTimer                     mUpdateTimer;
};



#endif // USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
