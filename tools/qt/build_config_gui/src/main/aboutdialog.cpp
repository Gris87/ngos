#include "aboutdialog.h"
#include "ui_aboutdialog.h"



AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    setWindowFlags(
                    Qt::Dialog
                    | Qt::CustomizeWindowHint
                    | Qt::WindowTitleHint
                    | Qt::WindowSystemMenuHint
                    | Qt::WindowCloseButtonHint
    );

    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_closeButton_clicked()
{
    reject();
}
