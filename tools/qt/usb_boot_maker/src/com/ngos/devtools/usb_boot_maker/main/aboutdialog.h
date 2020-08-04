#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_ABOUTDIALOG_H
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_ABOUTDIALOG_H



#include <QDialog>



namespace Ui
{
    class AboutDialog;
}



class AboutDialog: public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0); // TEST: NO
    ~AboutDialog(); // TEST: NO

private slots:
    void on_closeButton_clicked(); // TEST: NO

private:
    Ui::AboutDialog *ui;
};



#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_ABOUTDIALOG_H
