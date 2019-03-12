#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSettings>

#include "src/main/aboutdialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadWindowState();
}

MainWindow::~MainWindow()
{
    saveWindowState();

    delete ui;
}

void MainWindow::saveWindowState()
{
    QSettings settings("NGOS", "usb_boot_maker");

    settings.setValue("MainWindow/geometry",    saveGeometry());
    settings.setValue("MainWindow/windowState", saveState());
}

void MainWindow::loadWindowState()
{
    QSettings settings("NGOS", "usb_boot_maker");

    // Ignore CppAlignmentVerifier [BEGIN]
    restoreGeometry(settings.value("MainWindow/geometry").toByteArray());
    restoreState(   settings.value("MainWindow/windowState").toByteArray());
    // Ignore CppAlignmentVerifier [END]
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog(this);
    dialog.exec();
}
