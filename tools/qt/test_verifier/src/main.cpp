#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QProcess>
#include <QQueue>
#include <console/console.h>

#include "src/threads/testverifythread.h"
#include "src/threads/testworkerthread.h"



#define WORKERS_COUNT 8



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: test_verifier PATH\n"
                "    * PATH - path to folder"
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



    Console::out("Test verifier started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH = %1").arg(targetPath));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    QList<TestWorkerThread *> workers;

    for (qint64 i = 0; i < WORKERS_COUNT; ++i)
    {
        TestWorkerThread *worker = new TestWorkerThread();
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
                if (filename != ".git" && filename != "test")
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
                if (filename.endsWith(".h"))
                {
                    TestWorkerThread::pushFile(path);
                }
            }
        }
    }



    TestWorkerThread::noMoreFiles();



    QList<TestVerifyThread *> verifiers;

    for (qint64 i = 0; i < WORKERS_COUNT; ++i)
    {
        TestVerifyThread *verifier = new TestVerifyThread();
        verifier->start();

        verifiers.append(verifier);
    }



    QList<TestEntry> testEntries;

    for (qint64 i = 0; i < workers.length(); ++i)
    {
        TestWorkerThread *worker = workers.at(i);

        worker->wait();
        TestVerifyThread::pushTestEntries(worker->getTestEntries());
        testEntries.append(worker->getTestEntries());
        delete worker;
    }



    TestVerifyThread::noMoreTestEntries();



    Console::out(QString("%1 files verifed in %2 ms").arg(TestWorkerThread::getAmountOfFiles()).arg(QDateTime::currentMSecsSinceEpoch() - startTime));



    qSort(testEntries.begin(), testEntries.end());

    Console::out("");
    Console::out("Found entries for testing:");

    for (qint64 i = 0; i < testEntries.length(); ++i)
    {
        Console::out(testEntries.at(i).toString());
    }

    Console::out("");
    Console::out(QString("Entries for testing: %1").arg(testEntries.length()));



    QList<TestMessageInfo> messages;

    for (qint64 i = 0; i < verifiers.length(); ++i)
    {
        TestVerifyThread *verifier = verifiers.at(i);

        verifier->wait();
        messages.append(verifier->getMessages());
        delete verifier;
    }



    if (messages.length()) // messages.length() > 0
    {
        qSort(messages.begin(), messages.end());



        Console::err("");
        Console::err("Errors:");

        for (qint64 i = 0; i < messages.length(); ++i)
        {
            Console::err(messages.at(i).toString());
        }



        Console::err("");
        Console::err(QString("Tests covered on %1 %").arg(100 - messages.length() * 100.0 / testEntries.length()));
        Console::err("");

        return 1;
    }



    Console::out("");
    Console::out("Tests covered on 100 %");
    Console::out("");



    return 0;
}
