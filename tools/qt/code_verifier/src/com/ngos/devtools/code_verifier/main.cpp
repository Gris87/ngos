#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QProcess>
#include <QQueue>
#include <com/ngos/devtools/shared/console/console.h>

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"
#include "com/ngos/devtools/code_verifier/threads/codeworkerthread.h"
#include "com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: code_verifier PATH\n"
                "    * PATH - path to file or folder"
                );
    // Ignore CppAlignmentVerifier [END]
}

bool isGitIgnored(const QString &workingDirectory, const QString &path)
{
    QProcess git;

    git.setWorkingDirectory(workingDirectory);
    git.start("git", QStringList() << "check-ignore" << path);

    if (!git.waitForFinished(-1))
    {
        return false;
    }

    return git.readAll().length(); // git.readAll().length() > 0
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    QStringList arguments = app.arguments();

    if (arguments.length() != 2)
    {
        usage();

        return 2;
    }



    QString targetPath = arguments.at(1);



    Console::out("Code verifier started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH = %1").arg(targetPath));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    QList<CodeWorkerThread *> workers;

    for (qint64 i = 0; i < QThread::idealThreadCount(); ++i)
    {
        CodeWorkerThread *worker = new CodeWorkerThread();
        worker->start();

        workers.append(worker);
    }



    QQueue<QFileInfo> files;
    files.enqueue(QFileInfo(targetPath));

    while (!files.isEmpty())
    {
        QFileInfo file = files.dequeue();

        QString path     = file.absoluteFilePath();
        QString fileName = file.fileName();



        if (!isGitIgnored(file.dir().absolutePath(), path))
        {
            if (file.isDir())
            {
                if (fileName != ".git" && !path.contains("tools/tracers/assets"))
                {
                    QFileInfoList filesInfo = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

                    for (qint64 i = 0; i < filesInfo.length(); ++i)
                    {
                        files.enqueue(filesInfo.at(i));
                    }
                }
            }
            else
            {
                if (fileName.endsWith(".cpp"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::CPP);
                }
                else
                if (fileName.endsWith(".h"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::H);
                }
                else
                if (fileName.endsWith(".S"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::S);
                }
                else
                if (fileName.endsWith(".php"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::PHP);
                }
                else
                if (fileName == "Makefile")
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::MAKEFILE);
                }
                else
                if (fileName.endsWith(".pro"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::PRO);
                }
                else
                if (fileName.endsWith(".pri"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::PRI);
                }
                else
                if (fileName.endsWith(".ld"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::LD);
                }
                else
                if (fileName.endsWith(".sh"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::SH);
                }
                else
                if (fileName.endsWith(".includes"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::INCLUDES);
                }
                else
                if (
                    fileName.endsWith(".xml")
                    ||
                    fileName.endsWith(".ts")
                    ||
                    fileName.endsWith(".vbox")
                    ||
                    fileName.endsWith(".creator.shared")
                   )
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::XML);
                }
                else
                if (fileName.endsWith(".ui"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::UI);
                }
                else
                if (fileName.endsWith(".qrc"))
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::QRC);
                }
                else
                if (
                    fileName.endsWith(".txt")
                    ||
                    fileName.endsWith(".md")
                    ||
                    fileName.endsWith(".sql")
                    ||
                    fileName.endsWith(".rc")
                    ||
                    fileName.endsWith(".config")
                    ||
                    fileName.endsWith(".files")
                   )
                {
                    CodeWorkerThread::pushFile(path, CodeVerificationFileType::TEXT);
                }
                else
                if (
                    !fileName.endsWith(".creator")
                    &&
                    !fileName.endsWith(".creator.user")
                    &&
                    !fileName.endsWith(".patch")
                    &&
                    !fileName.endsWith(".qm")
                    &&
                    !fileName.endsWith(".bin")
                    &&
                    !fileName.endsWith(".dll")
                    &&
                    !fileName.endsWith(".exe")
                    &&
                    !fileName.endsWith(".hex")
                    &&
                    !fileName.endsWith(".gpg")
                    &&
                    !fileName.endsWith(".pem")
                    &&
                    !fileName.endsWith(".auth")
                    &&
                    !fileName.endsWith(".ttf")
                    &&
                    !fileName.endsWith(".ico")
                    &&
                    !fileName.endsWith(".png")
                    &&
                    !fileName.endsWith(".jpg")
                    &&
                    !fileName.endsWith(".gif")
                    &&
                    !fileName.endsWith(".svg")
                    &&
                    !file.isExecutable()
                   )
                {
                    Console::err(QString("Unexpected file extension: %1").arg(path));
                }
            }
        }
    }



    CodeWorkerThread::noMoreFiles();



    QList<CodeMessageInfo> warnings;
    QList<CodeMessageInfo> errors;

    for (qint64 i = 0; i < workers.length(); ++i)
    {
        CodeWorkerThread *worker = workers.at(i);



        worker->wait();

        warnings.append(worker->getWarnings());
        errors.append(worker->getErrors());

        delete worker;
    }



    Console::out(QString("%1 files verified with %2 verifications in %3 ms").arg(CodeWorkerThread::getAmountOfFiles()).arg(BaseCodeVerifier::getAmountOfVerifications()).arg(QDateTime::currentMSecsSinceEpoch() - startTime));



    if (warnings.length() > 0)
    {
        std::sort(warnings.begin(), warnings.end());



        for (qint64 i = warnings.length() - 2; i >= 0; --i)
        {
            if (warnings.at(i) == warnings.at(i + 1))
            {
                warnings.removeAt(i);
            }
        }



        Console::out("");
        Console::out("Warnings:");

        for (qint64 i = 0; i < warnings.length(); ++i)
        {
            Console::out(warnings.at(i).toString());
        }
    }



    if (errors.length() > 0)
    {
        std::sort(errors.begin(), errors.end());



        for (qint64 i = errors.length() - 2; i >= 0; --i)
        {
            if (errors.at(i) == errors.at(i + 1))
            {
                errors.removeAt(i);
            }
        }



        Console::err("");
        Console::err("Errors:");

        for (qint64 i = 0; i < errors.length(); ++i)
        {
            Console::err(errors.at(i).toString());
        }



        Console::err("");
        Console::err(QString("%1 warnings. %2 errors").arg(warnings.length()).arg(errors.length()));
        Console::err("");

        return 1;
    }



    Console::out("");
    Console::out(QString("%1 warnings. %2 errors").arg(warnings.length()).arg(errors.length()));



    if (warnings.length() == 0)
    {
        Console::out("");
        Console::out("Everything is OK");
    }

    Console::out("");



    return 0;
}
