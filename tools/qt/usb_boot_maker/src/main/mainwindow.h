#ifndef USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
#define USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H



#include <QMainWindow>



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

private:
    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO

    Ui::MainWindow *ui;
};



#endif // USB_BOOT_MAKER_SRC_MAIN_MAINWINDOW_H
