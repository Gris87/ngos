#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_MAINWINDOW_H
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_MAINWINDOW_H



#include <QMainWindow>

#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTemporaryDir>
#include <QTimer>
#include <QTranslator>

#include <com/ngos/devtools/usb_boot_maker/other/fileinfo.h>
#include <com/ngos/devtools/usb_boot_maker/other/usbbootmakerstate.h>
#include <com/ngos/devtools/usb_boot_maker/other/usbdeviceinfo.h>
#include <com/ngos/devtools/usb_boot_maker/other/usbspeed.h>
#include <com/ngos/devtools/usb_boot_maker/other/versioninfo.h>
#include <com/ngos/devtools/usb_boot_maker/threads/burnthread.h>
#include <com/ngos/devtools/usb_boot_maker/threads/usbmonitorthread.h>



namespace Ui
{
    class MainWindow;
}



class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // TEST: NO
    ~MainWindow(); // TEST: NO

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result); // TEST: NO // Ignore CppTypesVerifier

private slots:
    void on_actionExit_triggered(); // TEST: NO
    void on_actionAbout_triggered(); // TEST: NO
    void on_startButton_clicked(); // TEST: NO

    void languageToggled(bool checked); // TEST: NO
    void updateUsbDevices(); // TEST: NO
    void usbStatusChanged(quint16 delay); // TEST: NO
    void ignoreSslErrors(QNetworkReply *reply, const QList<QSslError> &errors); // TEST: NO
    void latestVersionReplyFinished(); // TEST: NO
    void fileListReplyFinished(); // TEST: NO
    void downloadReplyFinished(); // TEST: NO
    void burnFinished(); // TEST: NO
    void addLog(const QString &text); // TEST: NO
    void burnProgress(quint8 current, quint8 maximum); // TEST: NO

private:
    void prepareLanguages(); // TEST: NO
    QList<UsbDeviceInfo *> getUsbDevices(); // TEST: NO
    void switchToState(UsbBootMakerState state); // TEST: NO
    void handleGetLatestVersionState(); // TEST: NO
    void handleGetFileListState(); // TEST: NO
    void handleDownloadState(); // TEST: NO
    void handleBurningState(); // TEST: NO
    void resetToInitialState(); // TEST: NO
    void abortReplies(); // TEST: NO
    void switchToInitialState(); // TEST: NO

    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO

    Ui::MainWindow                  *ui;
    QTranslator                     *mTranslator;
    QTimer                          *mUpdateTimer;
    QNetworkAccessManager           *mManager;
    QTemporaryDir                   *mTemporaryDir;
    BurnThread                      *mBurnThread;

#ifdef Q_OS_LINUX
    UsbMonitorThread                *mUsbMonitorThread;
#endif

    UsbBootMakerState                mState;
    qint64                           mRequestTime;
    QHash<QString, QNetworkReply *>  mReplies;
    QHash<QString, VersionInfo>      mLatestVersions;
    VersionInfo                      mSelectedVersionInfo;
    qint64                           mCurrentApplication;
    QList<FileInfo>                  mVersionFiles;
    QString                          mLanguage;
    QHash<QString, QAction *>        mLanguageActions;
};



#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_MAINWINDOW_H
