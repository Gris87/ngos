#include "testverifythread.h"

#include <QDir>
#include <QQueue>



QList<TestEntry> TestVerifyThread::sTestEntries;
QMutex           TestVerifyThread::sTestEntriesMutex;
QSemaphore       TestVerifyThread::sTestEntriesSemaphore;



TestVerifyThread::TestVerifyThread()
    : QThread()
    , mMessages()
{
    // Nothing
}

void TestVerifyThread::pushTestEntries(const QList<TestEntry> &entries)
{
    QMutexLocker lock(&sTestEntriesMutex);

    sTestEntries.append(entries);
    sTestEntriesSemaphore.release(entries.length());
}

TestEntry TestVerifyThread::popTestEntry()
{
    sTestEntriesSemaphore.acquire();

    {
        QMutexLocker lock(&sTestEntriesMutex);



        TestEntry res = sTestEntries.constFirst();

        if (res.getPath() == "")
        {
            sTestEntriesSemaphore.release();
        }
        else
        {
            sTestEntries.removeFirst();
        }

        return res;
    }
}

void TestVerifyThread::noMoreTestEntries()
{
    QList<TestEntry> temp;
    temp.append(TestEntry(TestEntryType::DEFINE, "", -1, "", ""));

    pushTestEntries(temp);
}

const QList<TestMessageInfo>& TestVerifyThread::getMessages() const
{
    return mMessages;
}

void TestVerifyThread::run()
{
    do
    {
        TestEntry entry = popTestEntry();

        if (entry.getPath() == "")
        {
            break;
        }

        processTestEntry(entry);
    } while(true);
}

void TestVerifyThread::processTestEntry(const TestEntry &entry)
{
    qint64 index = entry.getPath().lastIndexOf("/src/");

    if (index < 0)
    {
        addMessage(entry.getPath(), QString("Failed to get src folder for %1: %2").arg(entry.getFunctionOrMacro()).arg(entry.getName()));

        return;
    }



    QString testFolder = entry.getPath().left(index) + "/test";

    if (!QDir(testFolder).exists())
    {
        addMessage(entry.getPath(), QString("Failed to get test folder for %1: %2").arg(entry.getFunctionOrMacro()).arg(entry.getName()));

        return;
    }



    bool good = false;



    QQueue<QFileInfo> files;
    files.enqueue(QFileInfo(testFolder));

    while (!files.isEmpty())
    {
        QFileInfo file = files.dequeue();

        QString path     = file.absoluteFilePath();
        QString filename = file.fileName();



        if (file.isDir())
        {
            QFileInfoList filesInfo = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

            for (qint64 i = 0; i < filesInfo.length(); ++i)
            {
                files.enqueue(filesInfo.at(i));
            }
        }
        else
        {
            if (filename == entry.getTestModule())
            {
                if (processTestEntryWithTestModule(entry, path))
                {
                    good = true;

                    break;
                }
            }
        }
    }



    if (!good)
    {
        addMessage(entry.getPath(), QString("Test not found for %1: %2").arg(entry.getFunctionOrMacro()).arg(entry.getName()));
    }
}

bool TestVerifyThread::processTestEntryWithTestModule(const TestEntry &entry, const QString &path)
{
    QString expectedPath;



    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i).trimmed();

        if (line.startsWith("TEST_CASES("))
        {
            QString testCasesPath = line.mid(11).trimmed();

            testCasesPath = testCasesPath.mid(testCasesPath.lastIndexOf(',') + 1).trimmed();
            testCasesPath = testCasesPath.left(testCasesPath.lastIndexOf(')')).trimmed();



            expectedPath = path.mid(path.lastIndexOf("/test/") + 6);

            qint64 index = expectedPath.indexOf("sections/");

            if (index >= 0)
            {
                expectedPath = expectedPath.mid(expectedPath.indexOf('/', index + 9) + 1);
            }

            if (expectedPath.endsWith(".h"))
            {
                expectedPath.remove(expectedPath.length() - 2, 2);
            }

            expectedPath = expectedPath.replace('/', '_');



            if (testCasesPath == expectedPath)
            {
                expectedPath = "";
            }
        }

        if (
            line.startsWith("TEST_CASE(\"" + entry.getName() + '\"')
            ||
            line.startsWith("TEST_CASE(\"" + entry.getName() + '.')
           )
        {
            if (expectedPath != "")
            {
                addMessage(entry.getPath(), QString("Test found for %1 \"%2\", but the path in TEST_CASES macro is invalid. Expected path: %3").arg(entry.getFunctionOrMacro()).arg(entry.getName()).arg(expectedPath));
            }

            return true;
        }
    }



    return false;
}

void TestVerifyThread::addMessage(const QString &path, const QString &message)
{
    mMessages.append(TestMessageInfo(path, message));
}
