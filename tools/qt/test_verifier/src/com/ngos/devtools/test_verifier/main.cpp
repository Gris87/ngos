#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QProcess>
#include <QQueue>

#include <com/ngos/devtools/shared/console/console.h>
#include <com/ngos/devtools/test_verifier/threads/testverifythread.h>
#include <com/ngos/devtools/test_verifier/threads/testworkerthread.h>



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

    return !git.readAll().isEmpty();
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

    for (qint64 i = 0; i < QThread::idealThreadCount(); ++i)
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
        QString fileName = file.fileName();



        if (!isGitIgnored(file.dir().absolutePath(), path))
        {
            if (file.isDir())
            {
                if (fileName != ".git" && fileName != "test")
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
                if (fileName.endsWith(".h"))
                {
                    TestWorkerThread::pushFile(path);
                }
            }
        }
    }



    TestWorkerThread::noMoreFiles();



    QList<TestVerifyThread *> verifiers;

    for (qint64 i = 0; i < QThread::idealThreadCount(); ++i)
    {
        TestVerifyThread *verifier = new TestVerifyThread();
        verifier->start();

        verifiers.append(verifier);
    }



    QList<TestStructureEntry> testStructureEntries;
    QList<TestEntry>          testEntries;

    for (qint64 i = 0; i < workers.length(); ++i)
    {
        TestWorkerThread *worker = workers.at(i);

        worker->wait();

        TestVerifyThread::pushTestStructureEntries(worker->getTestStructureEntries());
        testStructureEntries.append(worker->getTestStructureEntries());

        TestVerifyThread::pushTestEntries(worker->getTestEntries());
        testEntries.append(worker->getTestEntries());

        delete worker;
    }



    TestVerifyThread::noMoreTestStructureEntries();
    TestVerifyThread::noMoreTestEntries();



    Console::out(QString("%1 files verifed in %2 ms").arg(TestWorkerThread::getAmountOfFiles()).arg(QDateTime::currentMSecsSinceEpoch() - startTime));



    std::sort(testStructureEntries.begin(), testStructureEntries.end());

    Console::out("");
    Console::out("Found structure entries for testing:");

    for (qint64 i = 0; i < testStructureEntries.length(); ++i)
    {
        Console::out(testStructureEntries.at(i).toString());
    }

    Console::out("");
    Console::out(QString("Structure entries for testing: %1").arg(testStructureEntries.length()));



    std::sort(testEntries.begin(), testEntries.end());

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



    if (!messages.isEmpty())
    {
        std::sort(messages.begin(), messages.end());



        Console::err("");
        Console::err("Errors:");

        for (qint64 i = 0; i < messages.length(); ++i)
        {
            Console::err(messages.at(i).toString());
        }



        quint64 amountOfBitsTests = 0;

        for (qint64 i = 0; i < testStructureEntries.length(); ++i)
        {
            if (testStructureEntries.at(i).isBitsDefined())
            {
                ++amountOfBitsTests;
            }
        }



        Console::err("");
        Console::err(QString("Tests covered on %1 %").arg(100 - messages.length() * 100.0 / (testStructureEntries.length() + amountOfBitsTests + testEntries.length())));
        Console::err("");

        return 1;
    }



    Console::out("");
    Console::out("Tests covered on 100 %");
    Console::out("");



    return 0;
}
