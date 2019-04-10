#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QProcess>
#include <QQueue>
#include <console/console.h>

#include "src/other/codeverificationfiletype.h"
#include "src/threads/codeworkerthread.h"
#include "src/verifiers/basecodeverifier.h"



#define WORKERS_COUNT 8



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

    for (qint64 i = 0; i < WORKERS_COUNT; ++i)
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
        QString filename = file.fileName();



        if (!isGitIgnored(file.dir().absolutePath(), path))
        {
            if (file.isDir())
            {
                if (filename != ".git" && !path.contains("tools/tracers/assets"))
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
                if (filename.endsWith(".cpp"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::CPP);
                }
                else
                if (filename.endsWith(".h"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::H);
                }
                else
                if (filename.endsWith(".S"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::S);
                }
                else
                if (filename.endsWith(".php"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::PHP);
                }
                else
                if (filename == "Makefile")
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::MAKEFILE);
                }
                else
                if (filename.endsWith(".pro"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::PRO);
                }
                else
                if (filename.endsWith(".pri"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::PRI);
                }
                else
                if (filename.endsWith(".ld"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::LD);
                }
                else
                if (filename.endsWith(".sh"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::SH);
                }
                else
                if (filename.endsWith(".includes"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::INCLUDES);
                }
                else
                if (
                    filename.endsWith(".xml")
                    ||
                    filename.endsWith(".ts")
                    ||
                    filename.endsWith(".vbox")
                    ||
                    filename.endsWith(".creator.shared")
                   )
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::XML);
                }
                else
                if (filename.endsWith(".ui"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::UI);
                }
                else
                if (filename.endsWith(".qrc"))
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::QRC);
                }
                else
                if (
                    filename.endsWith(".txt")
                    ||
                    filename.endsWith(".md")
                    ||
                    filename.endsWith(".sql")
                    ||
                    filename.endsWith(".rc")
                    ||
                    filename.endsWith(".config")
                    ||
                    filename.endsWith(".files")
                   )
                {
                    CodeWorkerThread::pushFile(path, VerificationFileType::TEXT);
                }
                else
                if (
                    !filename.endsWith(".creator")
                    &&
                    !filename.endsWith(".creator.user")
                    &&
                    !filename.endsWith(".patch")
                    &&
                    !filename.endsWith(".qm")
                    &&
                    !filename.endsWith(".bin")
                    &&
                    !filename.endsWith(".hex")
                    &&
                    !filename.endsWith(".ttf")
                    &&
                    !filename.endsWith(".ico")
                    &&
                    !filename.endsWith(".png")
                    &&
                    !filename.endsWith(".gif")
                    &&
                    !filename.endsWith(".svg")
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



    if (warnings.length()) // warnings.length() > 0
    {
        qSort(warnings.begin(), warnings.end());



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



    if (errors.length()) // errors.length() > 0
    {
        qSort(errors.begin(), errors.end());



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



    if (!warnings.length()) // warnings.length() == 0
    {
        Console::out("");
        Console::out("Everything is OK");
    }

    Console::out("");



    return 0;
}
