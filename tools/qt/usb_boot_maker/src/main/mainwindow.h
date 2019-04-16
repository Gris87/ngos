#ifndef USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
#define USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H



#include <QMainWindow>

#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QTranslator>

#include "src/other/state.h"
#include "src/other/usbdeviceinfo.h"
#include "src/other/usbspeed.h"
#include "src/other/versioninfo.h"



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
    bool nativeEvent(const QByteArray &eventType, void *message, long *result); // TEST: NO // Ignore CppTypesVerifier

private slots:
    void on_actionExit_triggered(); // TEST: NO
    void on_actionAbout_triggered(); // TEST: NO
    void on_startButton_clicked(); // TEST: NO

    void languageToggled(bool checked); // TEST: NO
    void updateUsbDevices(); // TEST: NO
    void ignoreSslErrors(QNetworkReply *reply, const QList<QSslError> &errors); // TEST: NO
    void latestVersionReplyFinished(); // TEST: NO
    void fileListReplyFinished(); // TEST: NO

private:
    void prepareLanguages(); // TEST: NO
    QList<UsbDeviceInfo *> getUsbDevices(); // TEST: NO
    void switchToState(State state); // TEST: NO
    void handleGetLatestVersionState(); // TEST: NO
    void handleGetFileListState(); // TEST: NO
    void handleDownloadState(); // TEST: NO
    void resetToInitialState(); // TEST: NO
    void switchToInitialState(); // TEST: NO
    void addLog(const QString &text); // TEST: NO

    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO

    Ui::MainWindow                 *ui;
    QTranslator                    *mTranslator;
    QTimer                         *mUpdateTimer;
    QNetworkAccessManager          *mManager;
    State                           mState;
    qint64                          mRequestTime;
    QHash<QString, QNetworkReply *> mReplies;
    QHash<QString, VersionInfo>     mLatestVersions;
    VersionInfo                     mSelectedVersionInfo;
    QString                         mLanguage;
    QHash<QString, QAction *>       mLanguageActions;
};



#endif // USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
