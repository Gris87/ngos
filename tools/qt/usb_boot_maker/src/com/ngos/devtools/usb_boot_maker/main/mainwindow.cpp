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

#include <com/ngos/devtools/usb_boot_maker/main/aboutdialog.h>



#define MASTER_SERVER "cps-etl-srv.northeurope.cloudapp.azure.com"



const QStringList servers =
{
    MASTER_SERVER
};

const QStringList applications =
{
    "com.ngos.bootloader",
    "com.ngos.installer"
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow())
    , mTranslator(new QTranslator(this))
    , mUpdateTimer(new QTimer(this))
    , mManager(new QNetworkAccessManager(this))
    , mTemporaryDir(0)
    , mBurnThread(0)
#ifdef Q_OS_LINUX
    , mUsbMonitorThread(0)
#endif
    , mState(UsbBootMakerState::INITIAL)
    , mRequestTime(0)
    , mReplies()
    , mLatestVersions()
    , mSelectedVersionInfo()
    , mCurrentApplication(0)
    , mVersionFiles()
    , mLanguage()
    , mLanguageActions()
{
    ui->setupUi(this);



    mUpdateTimer->setSingleShot(true);
    connect(mUpdateTimer, SIGNAL(timeout()), this, SLOT(updateUsbDevices()));



    connect(mManager, SIGNAL(sslErrors(QNetworkReply *, const QList<QSslError> &)), this, SLOT(ignoreSslErrors(QNetworkReply *, const QList<QSslError> &)));



#ifdef Q_OS_LINUX
    mUsbMonitorThread = new UsbMonitorThread();
    mUsbMonitorThread->start();

    connect(mUsbMonitorThread, SIGNAL(usbStatusChanged(quint16)), this, SLOT(usbStatusChanged(quint16)));
#endif



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

    if (mBurnThread)
    {
        mBurnThread->blockSignals(true);
        mBurnThread->stop();
        mBurnThread->wait();

        delete mBurnThread;
    }



#ifdef Q_OS_LINUX
    mUsbMonitorThread->stop();
    mUsbMonitorThread->wait();

    delete mUsbMonitorThread;
#endif



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
    if (mState == UsbBootMakerState::INITIAL)
    {
        if (QMessageBox::warning(this, tr("Format disk"), tr("Do you really want to format disk \"%1\"?\nAll data on the device will be destroyed!").arg(ui->deviceComboBox->currentText()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Ok)
        {
            if (mTemporaryDir)
            {
                delete mTemporaryDir;
            }



            mTemporaryDir = new QTemporaryDir();

            if (!mTemporaryDir->isValid())
            {
                addLog(tr("Failed to create temporary directory"));

                delete mTemporaryDir;
                mTemporaryDir = 0;

                return;
            }

            qDebug() << "Downloading to temporary folder:" << mTemporaryDir->path();



            ui->deviceComboBox->setEnabled(false);
            ui->startButton->setIcon(QIcon(":/assets/images/stop.png")); // Ignore CppPunctuationVerifier

            mCurrentApplication = 0;

            switchToState(UsbBootMakerState::GET_LATEST_VERSION);
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

void MainWindow::usbStatusChanged(quint16 delay)
{
    if (!mUpdateTimer->isActive())
    {
        mUpdateTimer->start(delay);
    }
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



    if (mReplies.size() == 0)
    {
        switchToState(UsbBootMakerState::GET_FILE_LIST);
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
                switchToState(UsbBootMakerState::GET_FILE_LIST);

                return;
            }
            else
            if (files.isUndefined())
            {
                addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("files field absent")));

                abortReplies();
                switchToState(UsbBootMakerState::GET_FILE_LIST);

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
                    switchToState(UsbBootMakerState::GET_FILE_LIST);

                    return;
                }
                else
                if (versionCode.isUndefined())
                {
                    addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("version field absent")));

                    abortReplies();
                    switchToState(UsbBootMakerState::GET_FILE_LIST);

                    return;
                }
                else
                if (versionHash.isUndefined())
                {
                    addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(tr("hash field absent")));

                    abortReplies();
                    switchToState(UsbBootMakerState::GET_FILE_LIST);

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
                        switchToState(UsbBootMakerState::GET_FILE_LIST);

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
                            switchToState(UsbBootMakerState::GET_FILE_LIST);

                            return;
                        }



                        resultHash[0] ^= ((quint64 *)fileHashBytes.data())[0];
                        resultHash[1] ^= ((quint64 *)fileHashBytes.data())[1];
                    }



                    if (mSelectedVersionInfo.hash != QString::fromLatin1(QByteArray((char *)resultHash, 16).toHex()))
                    {
                        addLog(tr("File list received from server %1 did't match with stored value").arg(server));

                        abortReplies();
                        switchToState(UsbBootMakerState::GET_FILE_LIST);

                        return;
                    }



                    mVersionFiles.clear();

                    for (qint64 i = 0; i < filesArray.size(); ++i)
                    {
                        QJsonValue file = filesArray.at(i);

                        QJsonValue fileDownloadName = file["download_name"];
                        QJsonValue fileFileName     = file["filename"];
                        QJsonValue fileHash         = file["hash"];



                        if (
                            fileDownloadName.isUndefined()
                            ||
                            fileFileName.isUndefined()
                            ||
                            fileHash.isUndefined()
                           )
                        {
                            addLog(tr("File list received from server %1 did't match with stored value").arg(server));

                            abortReplies();
                            switchToState(UsbBootMakerState::GET_FILE_LIST);

                            return;
                        }



                        FileInfo fileInfo;

                        fileInfo.downloadName = fileDownloadName.toString("");
                        fileInfo.fileName     = fileFileName.toString("");
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
            switchToState(UsbBootMakerState::GET_FILE_LIST);

            return;
        }
    }
    else
    {
        addLog(tr("Failed to get file list from server %1: %2").arg(server).arg(reply->errorString()));

        abortReplies();
        switchToState(UsbBootMakerState::GET_FILE_LIST);

        return;
    }



    if (mReplies.size() == 0)
    {
        switchToState(UsbBootMakerState::DOWNLOAD);
    }
}

void MainWindow::downloadReplyFinished()
{
    QNetworkReply *reply    = (QNetworkReply *)sender();
    QString        server   = reply->url().host();
    FileInfo      *fileInfo = reply->property("fileinfo").value<FileInfo *>();



    reply->deleteLater();

    if (mReplies.remove(fileInfo->fileName) != 1)
    {
        qFatal("Unknown reply");
    }



    if (!reply->error())
    {
        addLog(tr("Downloaded file %1 from server %2").arg(fileInfo->fileName).arg(server));



        QString applicationDir = mTemporaryDir->path() + '/' + applications.at(mCurrentApplication);



        qint64 index = fileInfo->fileName.lastIndexOf('/');

        if (index < 0)
        {
            index = 0;
        }

        if (!QDir().mkpath(applicationDir + '/' + fileInfo->fileName.left(index)))
        {
            addLog(tr("Failed to store file %1").arg(fileInfo->fileName));

            abortReplies();
            switchToState(UsbBootMakerState::GET_FILE_LIST);

            return;
        }



        QByteArray content = reply->readAll();



        QString filePath = applicationDir + '/' + fileInfo->fileName;
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly))
        {
            if (file.write(content) != content.length())
            {
                file.close();

                addLog(tr("Failed to store file %1").arg(fileInfo->fileName));

                abortReplies();
                switchToState(UsbBootMakerState::GET_FILE_LIST);

                return;
            }

            file.close();
        }
        else
        {
            addLog(tr("Failed to store file %1").arg(fileInfo->fileName));

            abortReplies();
            switchToState(UsbBootMakerState::GET_FILE_LIST);

            return;
        }



        if (fileInfo->downloadName.endsWith(".xz"))
        {
            QProcess process;

            process.start("xzcat", QStringList() << filePath, QIODevice::ReadOnly);
            process.waitForFinished(-1);



            if (process.exitCode() == 0)
            {
                content = process.readAllStandardOutput();



                QFile file(filePath);

                if (file.open(QIODevice::WriteOnly))
                {
                    if (file.write(content) != content.length())
                    {
                        file.close();

                        addLog(tr("Failed to store file %1").arg(fileInfo->fileName));

                        abortReplies();
                        switchToState(UsbBootMakerState::GET_FILE_LIST);

                        return;
                    }

                    file.close();
                }
                else
                {
                    addLog(tr("Failed to store file %1").arg(fileInfo->fileName));

                    abortReplies();
                    switchToState(UsbBootMakerState::GET_FILE_LIST);

                    return;
                }
            }
            else
            {
                addLog(tr("Failed to decompress file %1").arg(fileInfo->fileName));

                abortReplies();
                switchToState(UsbBootMakerState::GET_FILE_LIST);

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
            addLog(tr("Failed to store file %1").arg(fileInfo->fileName));

            abortReplies();
            switchToState(UsbBootMakerState::GET_FILE_LIST);

            return;
        }
    }
    else
    {
        addLog(tr("Failed to download file %1 from server %2: %3").arg(fileInfo->fileName).arg(server).arg(reply->errorString()));

        abortReplies();
        switchToState(UsbBootMakerState::GET_FILE_LIST);

        return;
    }



    if (mReplies.size() == 0)
    {
        ++mCurrentApplication;

        if ((i64)mCurrentApplication >= applications.length())
        {
            switchToState(UsbBootMakerState::BURNING);
        }
        else
        {
            switchToState(UsbBootMakerState::GET_LATEST_VERSION);
        }
    }
}

void MainWindow::burnFinished()
{
    delete mBurnThread;
    mBurnThread = 0;



    switchToInitialState();
    addLog(tr("Done"));
}

void MainWindow::addLog(const QString &text)
{
    ui->logTextEdit->append(text);
}

void MainWindow::burnProgress(quint8 current, quint8 maximum)
{
    ui->statusProgressBar->setValue(40 + 60 * current / maximum);
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

void MainWindow::switchToState(UsbBootMakerState state)
{
    mState = state;

    switch (mState)
    {
        case UsbBootMakerState::GET_LATEST_VERSION: handleGetLatestVersionState(); break;
        case UsbBootMakerState::GET_FILE_LIST:      handleGetFileListState();      break;
        case UsbBootMakerState::DOWNLOAD:           handleDownloadState();         break;
        case UsbBootMakerState::BURNING:            handleBurningState();          break;

        case UsbBootMakerState::INITIAL:
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
    ui->statusProgressBar->setValue(5 + 35 * (0 + mCurrentApplication * 3) / applications.length() / 3);



    QString application = applications.at(mCurrentApplication);

    addLog("");
    addLog(tr("Getting information about latest version of %1 from servers").arg(application));

    mRequestTime = QDateTime::currentMSecsSinceEpoch();



    for (qint64 i = 0; i < servers.length(); ++i)
    {
        const QString &server = servers.at(i);



        QNetworkRequest request;
        request.setUrl(QUrl(QString("https://%1/rest/app_versions.php?codename=%2&version=latest&include_files=false")
                            .arg(server)
                            .arg(application)));

        QNetworkReply *reply = mManager->get(request);

        connect(reply, SIGNAL(finished()), this, SLOT(latestVersionReplyFinished()));



        mReplies.insert(server, reply);
    }
}

void MainWindow::handleGetFileListState()
{
    ui->statusProgressBar->setValue(5 + 35 * (1 + mCurrentApplication * 3) / applications.length() / 3);



    if (mLatestVersions.size() == 0)
    {
        switchToInitialState();

        addLog(tr("Latest version is unavailable"));



        return;
    }



    QHash<quint64, QList<const VersionInfo *>> versionGroups;

    // Fill versionGroups
    {
        QHashIterator<QString, VersionInfo> it(mLatestVersions);

        while (it.hasNext())
        {
            it.next();



            const VersionInfo *versionInfo = &it.value();

            versionGroups[versionInfo->version].append(versionInfo);
        }
    }



    QList<const VersionInfo *> *generalGroup = nullptr;

    // Find version that more spread among servers
    {
        qint64 max = 0;



        QHashIterator<quint64, QList<const VersionInfo *>> it(versionGroups);

        while (it.hasNext())
        {
            it.next();



            const QList<const VersionInfo *> &versions = it.value();



            const VersionInfo *firstVersionInfo = versions.constFirst();

            for (qint64 j = 1; j < versions.length(); ++j)
            {
                const VersionInfo *versionInfo = versions.at(j);

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



            if (versions.length() > max)
            {
                max          = versions.length();
                generalGroup = (QList<const VersionInfo *> *)&versions;
            }
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
    request.setUrl(QUrl(QString("https://%1/rest/app_versions.php?codename=%2&version=%3&include_files=true")
                        .arg(mSelectedVersionInfo.server)
                        .arg(applications.at(mCurrentApplication))
                        .arg(mSelectedVersionInfo.version)));

    QNetworkReply *reply = mManager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(fileListReplyFinished()));



    mReplies.insert(mSelectedVersionInfo.server, reply);
}

void MainWindow::handleDownloadState()
{
    ui->statusProgressBar->setValue(5 + 35 * (2 + mCurrentApplication * 3) / applications.length() / 3);



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



        mReplies.insert(fileInfo->fileName, reply);
    }
}

void MainWindow::handleBurningState()
{
    ui->statusProgressBar->setValue(40);



    addLog("");
    addLog(tr("Making bootable USB flash drive on disk \"%1\"").arg(ui->deviceComboBox->currentText()));



    mBurnThread = new BurnThread(ui->deviceComboBox->currentData().value<UsbDeviceInfo *>(), mTemporaryDir->path());
    mBurnThread->start();

    connect(mBurnThread, SIGNAL(logAdded(const QString &)), this, SLOT(addLog(const QString &)));
    connect(mBurnThread, SIGNAL(progress(quint8, quint8)),  this, SLOT(burnProgress(quint8, quint8)));
    connect(mBurnThread, SIGNAL(finished()),                this, SLOT(burnFinished()));
}

void MainWindow::resetToInitialState()
{
    addLog(tr("Operation terminated by user"));



    switch (mState)
    {
        case UsbBootMakerState::GET_LATEST_VERSION:
        case UsbBootMakerState::GET_FILE_LIST:
        case UsbBootMakerState::DOWNLOAD:
        {
            abortReplies();
        }
        break;

        case UsbBootMakerState::BURNING:
        {
            mBurnThread->blockSignals(true);
            mBurnThread->stop();
            mBurnThread->wait();

            delete mBurnThread;
            mBurnThread = 0;
        }
        break;

        case UsbBootMakerState::INITIAL:
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



    switchToInitialState();
}

void MainWindow::abortReplies()
{
    QHashIterator<QString, QNetworkReply *> it(mReplies);

    while (it.hasNext())
    {
        it.next();



        QNetworkReply *reply = it.value();

        reply->blockSignals(true);
        reply->abort();

        reply->deleteLater();
    }

    mReplies.clear();
}

void MainWindow::switchToInitialState()
{
    mState = UsbBootMakerState::INITIAL;
    ui->statusProgressBar->setValue(0);

    ui->deviceComboBox->setEnabled(true);
    ui->startButton->setIcon(QIcon(":/assets/images/start.png")); // Ignore CppPunctuationVerifier
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
