#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QNetworkRequest>
#include <QUrl>
#include <QSettings>

#include "src/main/aboutdialog.h"



#define MASTER_SERVER "10.83.230.9"



const QStringList servers = { MASTER_SERVER, "10.83.230.40", "10.83.230.42", "10.83.230.43", "10.83.230.41", "10.83.230.44" };



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow())
    , mTranslator(new QTranslator(this))
    , mUpdateTimer(new QTimer(this))
    , mManager(new QNetworkAccessManager(this))
    , mState(State::INITIAL)
    , mLanguage()
    , mLanguageActions()
{
    ui->setupUi(this);



    mTranslator = new QTranslator(this);
    prepareLanguages();



    mUpdateTimer->setSingleShot(true);
    connect(mUpdateTimer, SIGNAL(timeout()), this, SLOT(updateUsbDevices()));



    mManager = new QNetworkAccessManager(this);
    connect(mManager, SIGNAL(sslErrors(QNetworkReply *, const QList<QSslError> &)), this, SLOT(ignoreSslErrors(QNetworkReply *, const QList<QSslError> &)));



    loadWindowState();
    updateUsbDevices();
}

MainWindow::~MainWindow()
{
    saveWindowState();

    delete ui;
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

void MainWindow::on_startButton_clicked()
{
    if (QMessageBox::warning(this, tr("Format disk"), tr("Do you really want to format disk \"%1\"?\nAll data on the device will be destroyed!").arg(ui->deviceComboBox->currentText()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Ok)
    {
        ui->startButton->setIcon(QIcon(":/assets/images/stop.png")); // Ignore CppPunctuationVerifier



        for (qint64 i = 0; i < servers.length(); ++i)
        {
            QNetworkRequest request(QUrl("https://" + servers.at(i) + "/rest/app_versions.php?codename=com.ngos.installer&version=latest&include_files=false"));
            QNetworkReply *reply = mManager->get(request);

            connect(reply, SIGNAL(finished()), this, SLOT(latestVersionReplyFinished()));
        }
    }
}

void MainWindow::languageToggled(bool checked)
{
    if (checked)
    {
        QAction *action = (QAction *)sender();



        mLanguage = action->data().toString();

        qDebug() << "Switching to language:" << mLanguage;



        mTranslator->load(":/assets/translations/language_" + mLanguage); // Ignore CppPunctuationVerifier
        QApplication::installTranslator(mTranslator);

        ui->retranslateUi(this);



        addLog(tr("Language switched to %1").arg(action->text()));
    }
}

void MainWindow::updateUsbDevices()
{
    mUpdateTimer->stop();



    QList<UsbDeviceInfo *> usbDevices = getUsbDevices();

    qDebug() << "";
    qDebug() << "Found devices:" << usbDevices.length();

    addLog(tr("Found devices: %1").arg(usbDevices.length()));



    for (qint64 i = 0; i < ui->deviceComboBox->count(); ++i)
    {
        delete ui->deviceComboBox->itemData(i).value<UsbDeviceInfo *>();
    }

    ui->deviceComboBox->clear();



    for (qint64 i = 0; i < usbDevices.length(); ++i)
    {
        UsbDeviceInfo *usbDevice = usbDevices.at(i);

        QVariant data;
        data.setValue(usbDevice);

        ui->deviceComboBox->addItem(usbDevice->title, data);
    }



    ui->startButton->setEnabled(usbDevices.length()); // usbDevices.length() > 0
}

void MainWindow::ignoreSslErrors(QNetworkReply *reply, const QList<QSslError> &/*errors*/)
{
    reply->ignoreSslErrors();
}

void MainWindow::latestVersionReplyFinished()
{
    QNetworkReply *reply = (QNetworkReply *)sender();

    if (!reply->error())
    {
        addLog("Nice");
    }
    else
    {
        addLog(tr("Failed to get information about latest version from server %1: %2").arg(reply->url().host()).arg(reply->errorString()));
    }
}

void MainWindow::prepareLanguages()
{
    QActionGroup *group = new QActionGroup(this);



    QStringList languages = QDir(":/assets/translations").entryList(); // Ignore CppPunctuationVerifier

    for (qint64 i = 0; i < languages.length(); ++i)
    {
        QString language = languages.at(i);

        if (language.endsWith(".qm"))
        {
            language.remove(language.length() - 3, 3);
        }
        else
        {
            qFatal("Invalid file located in assets/translations folder: %s", language.toLocal8Bit().constData());
        }

        if (language.startsWith("language_"))
        {
            language.remove(0, 9);
        }
        else
        {
            qFatal("Invalid file located in assets/translations folder: %s", language.toLocal8Bit().constData());
        }



        QString languageName = QLocale(language).nativeLanguageName();
        languageName[0]      = languageName.at(0).toUpper();

        qDebug() << "Adding language:" << language << '|' << languageName;



        QAction *languageItem = new QAction(languageName, this);

        languageItem->setCheckable(true);
        languageItem->setActionGroup(group);
        languageItem->setData(language);

        connect(languageItem, SIGNAL(toggled(bool)), this, SLOT(languageToggled(bool)));

        ui->menuLanguage->addAction(languageItem);



        mLanguageActions.insert(language, languageItem);
    }
}

void MainWindow::addLog(const QString &text)
{
    ui->logTextEdit->append(text);
}

void MainWindow::saveWindowState()
{
    QSettings settings("NGOS", "usb_boot_maker");

    settings.setValue("Language",               mLanguage);
    settings.setValue("MainWindow/geometry",    saveGeometry());
    settings.setValue("MainWindow/windowState", saveState());
}

void MainWindow::loadWindowState()
{
    QSettings settings("NGOS", "usb_boot_maker");

    // Ignore CppAlignmentVerifier [BEGIN]
    mLanguage =     settings.value("Language", QLocale::system().name()).toString(); // Ignore CppEqualAlignmentVerifier
    restoreGeometry(settings.value("MainWindow/geometry").toByteArray());
    restoreState(   settings.value("MainWindow/windowState").toByteArray());
    // Ignore CppAlignmentVerifier [END]



    mLanguage = mLanguage.left(mLanguage.indexOf('_'));

    if (!mLanguageActions.contains(mLanguage))
    {
        mLanguage = "en";
    }

    mLanguageActions.value(mLanguage)->setChecked(true);
}
