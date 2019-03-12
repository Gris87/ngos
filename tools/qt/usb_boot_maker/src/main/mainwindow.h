#ifndef USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
#define USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H



#include <QMainWindow>

#include <QTranslator>



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

private slots:
    void on_actionExit_triggered(); // TEST: NO
    void on_actionAbout_triggered(); // TEST: NO

    void languageToggled(bool checked); // TEST: NO

private:
    void prepareLanguages(); // TEST: NO
    void updateUsbDevices(); // TEST: NO
    void addLog(const QString &text); // TEST: NO

    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO

    Ui::MainWindow            *ui;
    QTranslator               *mTranslator;
    QString                    mLanguage;
    QHash<QString, QAction *>  mLanguageActions;
};



#endif // USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
