#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QProcess>
#include <QQueue>

#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>
#include <com/ngos/devtools/docs_verifier/threads/docsworkerthread.h>
#include <com/ngos/devtools/docs_verifier/verifiers/basedocsverifier.h>
#include <com/ngos/devtools/shared/console/console.h>
#include <com/ngos/devtools/shared/utils/git.h>



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: docs_verifier PATH\n"
                "    * PATH - path to file or folder"
                );
    // Ignore CppAlignmentVerifier [END]
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    const QStringList &arguments = app.arguments();

    if (arguments.size() != 2)
    {
        usage();

        return 2;
    }



    QString targetPath = arguments.at(1);



    Console::out("Docs verifier started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH = %1").arg(targetPath));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    QList<DocsWorkerThread *> workers;

    for (qint64 i = 0; i < QThread::idealThreadCount(); ++i)
    {
        DocsWorkerThread *worker = new DocsWorkerThread();
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



        if (!GIT::isIgnored(file.dir().absolutePath(), path))
        {
            if (file.isDir())
            {
                if (fileName != ".git" && !path.contains("tools/tracers/assets") && !path.contains("scripts/prerequisites"))
                {
                    QFileInfoList filesInfo = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

                    for (qint64 i = 0; i < filesInfo.size(); ++i)
                    {
                        files.enqueue(filesInfo.at(i));
                    }
                }
            }
            else
            {
                if (fileName.endsWith(".md"))
                {
                    DocsWorkerThread::pushFile(path, DocsVerificationFileType::MD);
                }
                else
                if (
                    fileName.endsWith(".cpp")
                    ||
                    fileName.endsWith(".h")
                    ||
                    fileName.endsWith(".S")
                    ||
                    fileName.endsWith(".php")
                    ||
                    fileName == "Makefile"
                    ||
                    fileName.endsWith(".pro")
                    ||
                    fileName.endsWith(".pri")
                    ||
                    fileName.endsWith(".ld")
                    ||
                    fileName.endsWith(".sh")
                    ||
                    fileName.endsWith(".includes")
                    ||
                    fileName.endsWith(".xml")
                    ||
                    fileName.endsWith(".ts")
                    ||
                    fileName.endsWith(".vbox")
                    ||
                    fileName.endsWith(".creator.shared")
                    ||
                    fileName.endsWith(".ui")
                    ||
                    fileName.endsWith(".qrc")
                    ||
                    fileName.endsWith(".txt")
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
                    DocsWorkerThread::pushFile(path, DocsVerificationFileType::TEXT);
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



    DocsWorkerThread::noMoreFiles();



    QList<DocsMessageInfo> warnings;
    QList<DocsMessageInfo> errors;

    for (qint64 i = 0; i < workers.size(); ++i)
    {
        DocsWorkerThread *worker = workers.at(i);



        worker->wait();

        warnings.append(worker->getWarnings());
        errors.append(worker->getErrors());

        delete worker;
    }



    Console::out(QString("%1 files verified with %2 verifications in %3 ms").arg(DocsWorkerThread::getAmountOfFiles()).arg(BaseDocsVerifier::getAmountOfVerifications()).arg(QDateTime::currentMSecsSinceEpoch() - startTime));



    if (!warnings.isEmpty())
    {
        std::sort(warnings.begin(), warnings.end());



        for (qint64 i = warnings.size() - 2; i >= 0; --i)
        {
            if (warnings.at(i) == warnings.at(i + 1))
            {
                warnings.removeAt(i);
            }
        }



        Console::out("");
        Console::out("Warnings:");

        for (qint64 i = 0; i < warnings.size(); ++i)
        {
            Console::out(warnings.at(i).toString());
        }
    }



    if (!errors.isEmpty())
    {
        std::sort(errors.begin(), errors.end());



        for (qint64 i = errors.size() - 2; i >= 0; --i)
        {
            if (errors.at(i) == errors.at(i + 1))
            {
                errors.removeAt(i);
            }
        }



        Console::err("");
        Console::err("Errors:");

        for (qint64 i = 0; i < errors.size(); ++i)
        {
            Console::err(errors.at(i).toString());
        }



        Console::err("");
        Console::err(QString("%1 warnings. %2 errors").arg(warnings.size()).arg(errors.size()));
        Console::err("");

        return 1;
    }



    Console::out("");
    Console::out(QString("%1 warnings. %2 errors").arg(warnings.size()).arg(errors.size()));



    if (warnings.isEmpty())
    {
        Console::out("");
        Console::out("Everything is OK");
    }

    Console::out("");



    return 0;
}
