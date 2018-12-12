#ifndef GDB_DEBUG_SRC_MAIN_ABOUTDIALOG_H
#define GDB_DEBUG_SRC_MAIN_ABOUTDIALOG_H



#include <QDialog>



namespace Ui
{
    class AboutDialog;
}



class AboutDialog : public QDialog
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



#endif // GDB_DEBUG_SRC_MAIN_ABOUTDIALOG_H
