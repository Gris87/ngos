#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkRequest>
#include <QProcess>
#include <QSettings>
#include <QUrl>

#include "src/main/aboutdialog.h"



#define MASTER_SERVER "10.83.230.9"



const QStringList servers = { MASTER_SERVER, "10.83.230.40", "10.83.230.42", "10.83.230.43", "10.83.230.41", "10.83.230.44" };



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow())
    , mTranslator(new QTranslator(this))
    , mUpdateTimer(new QTimer(this))
    , mManager(new QNetworkAccessManager(this))
    , mTemporaryDir(0)
    , mState(State::INITIAL)
    , mRequestTime(0)
    , mReplies()
    , mLatestVersions()
    , mSelectedVersionInfo()
    , mVersionFiles()
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
    if (mTemporaryDir)
    {
        delete mTemporaryDir;
    }



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
            if (!mTemporaryDir)
            {
                mTemporaryDir = new QTemporaryDir();

                if (!mTemporaryDir->isValid())
                {
                    addLog(tr("Failed to create temporary directory"));

                    delete mTemporaryDir;
                    mTemporaryDir = 0;

                    return;
                }
            }



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



    reply->deleteLater();

    if (mReplies.remove(server) != 1)
    {
        qFatal("Unknown reply");
    }



    if (!reply->error())
    {
        qint64 delay = QDateTime::currentMSecsSinceEpoch() - mRequestTime;

        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject   json         = jsonDocument.object();

        if (json["status"].toString("") == "OK")
        {
            QJsonValue version = json["version"];

            if (version.isUndefined())
            {
                addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("version field absent")));
            }
            else
            {
                QJsonValue versionId   = version["id"];
                QJsonValue versionCode = version["version"];
                QJsonValue versionHash = version["hash"];

                if (versionId.isUndefined())
                {
                    addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("id field absent")));
                }
                else
                if (versionCode.isUndefined())
                {
                    addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("version field absent")));
                }
                else
                if (versionHash.isUndefined())
                {
                    addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(tr("hash field absent")));
                }
                else
                {
                    VersionInfo versionInfo;

                    versionInfo.id      = versionId.toVariant().toULongLong();
                    versionInfo.version = versionCode.toVariant().toULongLong();
                    versionInfo.hash    = versionHash.toString("");
                    versionInfo.server  = server;
                    versionInfo.delay   = delay;

                    mLatestVersions.insert(server, versionInfo);



                    addLog(tr("Response received from server %1 in %2 ms. Version: %3").arg(server).arg(delay).arg(versionInfo.version));
                }
            }
        }
        else
        {
            QJsonValue message = json["message"];
            QJsonValue details = json["details"];

            QString messageStr = message.toString("");
            QString detailsStr = details.toString("");

            addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(messageStr + (detailsStr != "" ? (" (" + detailsStr + ')') : "")));
        }
    }
    else
    {
        addLog(tr("Failed to get information about latest version from server %1: %2").arg(server).arg(reply->errorString()));
    }



    if (!mReplies.size()) // mReplies.size() == 0
    {
        switchToState(State::GET_FILE_LIST);
    }
}

void MainWindow::fileListReplyFinished()
{
    QNetworkReply *reply  = (QNetworkReply *)sender();
    QString        server = reply->url().host();



    reply->deleteLater();

    if (mReplies.remove(server) != 1)
    {
        qFatal("Unknown reply");
    }



    if (!reply->error())
    {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject   json         = jsonDocument.object();

        if (json["status"].toString("") == "OK")
        {
            QJsonValue version = json["version"];
            QJsonValue files   = json["files"];

            if (version.isUndefined())
            {
                addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("version field absent")));

                abortReplies();
                switchToState(State::GET_FILE_LIST);

                return;
            }
            else
            if (files.isUndefined())
            {
                addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("files field absent")));

                abortReplies();
                switchToState(State::GET_FILE_LIST);

                return;
            }
            else
            {
                QJsonValue versionId   = version["id"];
                QJsonValue versionCode = version["version"];
                QJsonValue versionHash = version["hash"];

                if (versionId.isUndefined())
                {
                    addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("id field absent")));

                    abortReplies();
                    switchToState(State::GET_FILE_LIST);

                    return;
                }
                else
                if (versionCode.isUndefined())
                {
                    addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("version field absent")));

                    abortReplies();
                    switchToState(State::GET_FILE_LIST);

                    return;
                }
                else
                if (versionHash.isUndefined())
                {
                    addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("hash field absent")));

                    abortReplies();
                    switchToState(State::GET_FILE_LIST);

                    return;
                }
                else
                {
                    if (
                        mSelectedVersionInfo.id != versionId.toVariant().toULongLong()
                        ||
                        mSelectedVersionInfo.version != versionCode.toVariant().toULongLong()
                        ||
                        mSelectedVersionInfo.hash != versionHash.toString("")
                       )
                    {
                        addLog(tr("File list received from server %1 did't match with stored value").arg(server));

                        abortReplies();
                        switchToState(State::GET_FILE_LIST);

                        return;
                    }



                    quint64    resultHash[2] = { 0, 0 };
                    QJsonArray filesArray    = files.toArray();

                    for (qint64 i = 0; i < filesArray.size(); ++i)
                    {
                        QJsonValue fileHash = filesArray.at(i)["hash"];



                        QByteArray fileHashBytes = QByteArray::fromHex(fileHash.toString("").toLatin1());

                        if (fileHashBytes.length() != 16)
                        {
                            addLog(tr("File list received from server %1 did't match with stored value").arg(server));

                            abortReplies();
                            switchToState(State::GET_FILE_LIST);

                            return;
                        }



                        resultHash[0] ^= ((quint64 *)fileHashBytes.data())[0];
                        resultHash[1] ^= ((quint64 *)fileHashBytes.data())[1];
                    }



                    if (mSelectedVersionInfo.hash != QString::fromLatin1(QByteArray((char *)resultHash, 16).toHex()))
                    {
                        addLog(tr("File list received from server %1 did't match with stored value").arg(server));

                        abortReplies();
                        switchToState(State::GET_FILE_LIST);

                        return;
                    }



                    mVersionFiles.clear();

                    for (qint64 i = 0; i < filesArray.size(); ++i)
                    {
                        QJsonValue file = filesArray.at(i);

                        QJsonValue fileDownloadName = file["download_name"];
                        QJsonValue fileFilename     = file["filename"];
                        QJsonValue fileHash         = file["hash"];



                        if (
                            fileDownloadName.isUndefined()
                            ||
                            fileFilename.isUndefined()
                            ||
                            fileHash.isUndefined()
                           )
                        {
                            addLog(tr("File list received from server %1 did't match with stored value").arg(server));

                            abortReplies();
                            switchToState(State::GET_FILE_LIST);

                            return;
                        }



                        FileInfo fileInfo;

                        fileInfo.downloadName = fileDownloadName.toString("");
                        fileInfo.filename     = fileFilename.toString("");
                        fileInfo.hash         = fileHash.toString("");

                        mVersionFiles.append(fileInfo);
                    }



                    addLog(tr("File list received from server %1").arg(server));
                }
            }
        }
        else
        {
            QJsonValue message = json["message"];
            QJsonValue details = json["details"];

            QString messageStr = message.toString("");
            QString detailsStr = details.toString("");

            addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(messageStr + (detailsStr != "" ? (" (" + detailsStr + ')') : "")));

            abortReplies();
            switchToState(State::GET_FILE_LIST);

            return;
        }
    }
    else
    {
        addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(reply->errorString()));

        abortReplies();
        switchToState(State::GET_FILE_LIST);

        return;
    }



    if (!mReplies.size()) // mReplies.size() == 0
    {
        switchToState(State::DOWNLOAD);
    }
}

void MainWindow::downloadReplyFinished()
{
    QNetworkReply *reply    = (QNetworkReply *)sender();
    QString        server   = reply->url().host();
    FileInfo      *fileInfo = reply->property("fileinfo").value<FileInfo *>();



    reply->deleteLater();

    if (mReplies.remove(fileInfo->filename) != 1)
    {
        qFatal("Unknown reply");
    }



    if (!reply->error())
    {
        addLog(tr("Downloaded file %1 from server %2").arg(fileInfo->filename).arg(server));



        qint64 index = fileInfo->filename.lastIndexOf('/');

        if (index < 0)
        {
            index = 0;
        }

        if (!QDir().mkpath(mTemporaryDir->path() + '/' + QString::number(mSelectedVersionInfo.version) + '/' + fileInfo->filename.left(index)))
        {
            addLog(tr("Failed to store file %1").arg(fileInfo->filename));

            abortReplies();
            switchToState(State::GET_FILE_LIST);

            return;
        }



        QByteArray content = reply->readAll();



        QString filePath = mTemporaryDir->path() + '/' + QString::number(mSelectedVersionInfo.version) + '/' + fileInfo->filename;
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly))
        {
            if (file.write(content) != content.length())
            {
                file.close();

                addLog(tr("Failed to store file %1").arg(fileInfo->filename));

                abortReplies();
                switchToState(State::GET_FILE_LIST);

                return;
            }

            file.close();
        }
        else
        {
            addLog(tr("Failed to store file %1").arg(fileInfo->filename));

            abortReplies();
            switchToState(State::GET_FILE_LIST);

            return;
        }



        if (fileInfo->downloadName.endsWith(".xz"))
        {
            QProcess process;

            process.start("xzdec", QStringList() << filePath, QIODevice::ReadOnly);
            process.waitForFinished(-1);



            if (!process.exitCode()) // process.exitCode() == 0
            {
                content = process.readAllStandardOutput();



                QFile file(filePath);

                if (file.open(QIODevice::WriteOnly))
                {
                    if (file.write(content) != content.length())
                    {
                        file.close();

                        addLog(tr("Failed to store file %1").arg(fileInfo->filename));

                        abortReplies();
                        switchToState(State::GET_FILE_LIST);

                        return;
                    }

                    file.close();
                }
                else
                {
                    addLog(tr("Failed to store file %1").arg(fileInfo->filename));

                    abortReplies();
                    switchToState(State::GET_FILE_LIST);

                    return;
                }
            }
            else
            {
                addLog(tr("Failed to download file %1 from server %2: %3").arg(fileInfo->filename).arg(server).arg(reply->errorString()));

                abortReplies();
                switchToState(State::GET_FILE_LIST);

                return;
            }
        }
        else
        if (!fileInfo->downloadName.endsWith(".raw"))
        {
            qFatal("Unknown file format");
        }



        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(content);

        if (fileInfo->hash != QString::fromLatin1(hash.result().toHex()))
        {
            addLog(tr("Failed to store file %1").arg(fileInfo->filename));

            abortReplies();
            switchToState(State::GET_FILE_LIST);

            return;
        }
    }
    else
    {
        addLog(tr("Failed to download file %1 from server %2: %3").arg(fileInfo->filename).arg(server).arg(reply->errorString()));

        abortReplies();
        switchToState(State::GET_FILE_LIST);

        return;
    }



    if (!mReplies.size()) // mReplies.size() == 0
    {
        switchToState(State::BURNING);
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
    ui->statusProgressBar->setValue((quint8)mState);

    switch (mState)
    {
        case State::GET_LATEST_VERSION: handleGetLatestVersionState(); break;
        case State::GET_FILE_LIST:      handleGetFileListState();      break;
        case State::DOWNLOAD:           handleDownloadState();         break;
        case State::BURNING:            handleBurningState();          break;

        case State::INITIAL:
        {
            qFatal("Unexpected state %u", (quint8)mState);
        }
        break;

        default:
        {
            qFatal("Unknown state %u", (quint8)mState);
        }
        break;
    }
}

void MainWindow::handleGetLatestVersionState()
{
    addLog(tr("Getting information about latest version from servers:"));

    mRequestTime = QDateTime::currentMSecsSinceEpoch();



    for (qint64 i = 0; i < servers.length(); ++i)
    {
        const QString &server = servers.at(i);



        QNetworkRequest request;
        request.setUrl(QUrl(QString("https://%1/rest/app_versions.php?codename=com.ngos.installer&version=latest&include_files=false").arg(server)));

        QNetworkReply *reply = mManager->get(request);

        connect(reply, SIGNAL(finished()), this, SLOT(latestVersionReplyFinished()));



        mReplies.insert(server, reply);
    }
}

void MainWindow::handleGetFileListState()
{
    if (!mLatestVersions.size()) // mLatestVersions.size() == 0
    {
        switchToInitialState();

        addLog(tr("Latest version is unavailable"));



        return;
    }



    QHash<quint64, QList<const VersionInfo *>> versionGroups;

    for (QHash<QString, VersionInfo>::iterator i = mLatestVersions.begin(); i != mLatestVersions.end(); ++i)
    {
        const VersionInfo *versionInfo = &i.value();

        versionGroups[versionInfo->version].append(versionInfo);
    }



    qint64                      max          = 0;
    QList<const VersionInfo *> *generalGroup = 0;

    for (QHash<quint64, QList<const VersionInfo *>>::iterator i = versionGroups.begin(); i != versionGroups.end(); ++i)
    {
        QList<const VersionInfo *> *versions = &i.value();



        const VersionInfo *firstVersionInfo = versions->constFirst();

        for (qint64 j = 1; j < versions->length(); ++j)
        {
            const VersionInfo *versionInfo = versions->at(j);

            if (
                versionInfo->id != firstVersionInfo->id
                ||
                versionInfo->version != firstVersionInfo->version
                ||
                versionInfo->hash != firstVersionInfo->hash
               )
            {
                switchToInitialState();

                addLog(tr("Database is broken"));



                return;
            }
        }



        if (versions->length() > max)
        {
            max          = versions->length();
            generalGroup = versions;
        }
    }



    const VersionInfo *selectedVersionInfo = generalGroup->at(0);
    qint64             min                 = selectedVersionInfo->delay;

    for (qint64 i = 1; i < generalGroup->length(); ++i)
    {
        if (generalGroup->at(i)->delay < min)
        {
            selectedVersionInfo = generalGroup->at(i);
            min                 = selectedVersionInfo->delay;
        }
    }



    mSelectedVersionInfo = *selectedVersionInfo;
    mLatestVersions.remove(selectedVersionInfo->server);



    QNetworkRequest request;
    request.setUrl(QUrl(QString("https://%1/rest/app_versions.php?codename=com.ngos.installer&version=%2&include_files=true").arg(mSelectedVersionInfo.server).arg(mSelectedVersionInfo.version)));

    QNetworkReply *reply = mManager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(fileListReplyFinished()));



    mReplies.insert(mSelectedVersionInfo.server, reply);
}

void MainWindow::handleDownloadState()
{
    for (qint64 i = 0; i < mVersionFiles.length(); ++i)
    {
        FileInfo *fileInfo = &mVersionFiles[i];

        QNetworkRequest request;
        request.setUrl(QUrl(QString("https://%1/downloads/%2").arg(mSelectedVersionInfo.server).arg(fileInfo->downloadName)));

        QNetworkReply *reply = mManager->get(request);



        QVariant data;
        data.setValue(fileInfo);

        reply->setProperty("fileinfo", data);



        connect(reply, SIGNAL(finished()), this, SLOT(downloadReplyFinished()));



        mReplies.insert(fileInfo->filename, reply);
    }
}

void MainWindow::handleBurningState()
{
    addLog(tr("Making bootable USB flash drive"));



    switchToInitialState();

    addLog(tr("Done"));
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
        addLog(tr("Operation terminated by user"));

        abortReplies();
        switchToInitialState();
    }
}

void MainWindow::abortReplies()
{
    for (QHash<QString, QNetworkReply *>::iterator i = mReplies.begin(); i != mReplies.end(); ++i)
    {
        QNetworkReply *reply = i.value();

        reply->blockSignals(true);
        reply->abort();

        reply->deleteLater();
    }

    mReplies.clear();
}

void MainWindow::switchToInitialState()
{
    mState = State::INITIAL;
    ui->statusProgressBar->setValue((quint8)mState);

    ui->deviceComboBox->setEnabled(true);
    ui->startButton->setIcon(QIcon(":/assets/images/start.png")); // Ignore CppPunctuationVerifier
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
