#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_ABOUTDIALOG_H                                                                                                                                              // Colorize: green
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_ABOUTDIALOG_H                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDialog>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
namespace Ui                                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    class AboutDialog;                                                                                                                                                                                   // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class AboutDialog: public QDialog                                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_OBJECT                                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    explicit AboutDialog(QWidget *parent = nullptr); // TEST: NO                                                                                                                                         // Colorize: green
    ~AboutDialog(); // TEST: NO                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private slots:                                                                                                                                                                                           // Colorize: green
    void on_closeButton_clicked(); // TEST: NO                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    Ui::AboutDialog *ui;                                                                                                                                                                                 // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_MAIN_ABOUTDIALOG_H                                                                                                                                            // Colorize: green
