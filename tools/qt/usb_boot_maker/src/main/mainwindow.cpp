#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
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
    , mRequestTime(0)
    , mReplies()
    , mLanguage()
    , mLanguageActions()
{
    ui->setupUi(this);



    mUpdateTimer->setSingleShot(true);
    connect(mUpdateTimer, SIGNAL(timeout()), this, SLOT(updateUsbDevices()));



    connect(mManager, SIGNAL(sslErrors(QNetworkReply *, const QList<QSslError> &)), this, SLOT(ignoreSslErrors(QNetworkReply *, const QList<QSslError> &)));



    prepareLanguages();
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
    if (mState == State::INITIAL)
    {
        if (QMessageBox::warning(this, tr("Format disk"), tr("Do you really want to format disk \"%1\"?\nAll data on the device will be destroyed!").arg(ui->deviceComboBox->currentText()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Ok)
        {
            ui->deviceComboBox->setEnabled(false);
            ui->startButton->setIcon(QIcon(":/assets/images/stop.png")); // Ignore CppPunctuationVerifier

            switchToState(State::GET_LATEST_VERSION);
        }
    }
    else
    {
        resetToInitialState();
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
    QNetworkReply *reply  = (QNetworkReply *)sender();
    QString        server = reply->url().host();



    if (!reply->error())
    {
        qint64 delay = QDateTime::currentMSecsSinceEpoch() - mRequestTime;

        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject   json         = jsonDocument.object();

        if (json["status"].toString() == "OK")
        {
            QJsonValue version = json["version"];

            if (version.type() != QJsonValue::Undefined)
            {
                QJsonValue versionId   = version["version"];
                QJsonValue versionHash = version["hash"];

                if (versionId.type() == QJsonValue::Undefined)
                {
                    addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("version field absent")));
                }
                else
                if (versionHash.type() == QJsonValue::Undefined)
                {
                    addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("hash field absent")));
                }
                else
                {
                    addLog(tr("Response received from server %1 in %2 ms. Version: %3").arg(server).arg(delay).arg(versionId.toVariant().toULongLong()));
                }
            }
            else
            {
                addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("version field absent")));
            }
        }
        else
        {
            QJsonValue message = json["message"];
            QJsonValue details = json["details"];

            QString messageStr = message.toString("");
            QString detailsStr = details.toString("");

            addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(messageStr + (detailsStr != "" ? (" (" + detailsStr + ")") : "")));
        }
    }
    else
    {
        addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(reply->errorString()));
    }



    reply->deleteLater();

    if (mReplies.remove(server) != 1)
    {
        qFatal("Unknown reply");
    }



    if (!mReplies.size()) // mReplies.size() == 0
    {
        switchToState(State::GET_FILE_LIST);
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

void MainWindow::switchToState(State state)
{
    mState = state;

    switch (mState)
    {
        case State::GET_LATEST_VERSION: handleGetLatestVersionState(); break;
        case State::GET_FILE_LIST:      handleGetFileListState();      break;

        case State::INITIAL:
        {
            qFatal("Unexpected state %u", mState);
        }
        break;

        default:
        {
            qFatal("Unknown state %u", mState);
        }
        break;
    }
}

void MainWindow::handleGetLatestVersionState()
{
    mRequestTime = QDateTime::currentMSecsSinceEpoch();

    for (qint64 i = 0; i < servers.length(); ++i)
    {
        const QString &server = servers.at(i);



        QNetworkRequest request(QUrl("https://" + server + "/rest/app_versions.php?codename=com.ngos.installer&version=latest&include_files=false"));
        QNetworkReply *reply = mManager->get(request);

        connect(reply, SIGNAL(finished()), this, SLOT(latestVersionReplyFinished()));



        mReplies.insert(server, reply);
    }
}

void MainWindow::handleGetFileListState()
{

}

void MainWindow::resetToInitialState()
{
    if (
        mState == State::GET_LATEST_VERSION
        ||
        mState == State::GET_FILE_LIST
        ||
        mState == State::DOWNLOAD
       )
    {
        for (QHash<QString, QNetworkReply *>::iterator i = mReplies.begin(); i != mReplies.end(); ++i)
        {
            QNetworkReply *reply = i.value();

            reply->blockSignals(true);
            reply->abort();

            reply->deleteLater();
        }

        mReplies.clear();



        mState = State::INITIAL;

        ui->deviceComboBox->setEnabled(true);
        ui->startButton->setIcon(QIcon(":/assets/images/start.png")); // Ignore CppPunctuationVerifier



        addLog(tr("Operation terminated by user"));
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
