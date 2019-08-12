#include "testverifythread.h"

#include <QDir>
#include <QQueue>



QList<TestEntry>          TestVerifyThread::sTestEntries;
QMutex                    TestVerifyThread::sTestEntriesMutex;
QSemaphore                TestVerifyThread::sTestEntriesSemaphore;
QList<TestStructureEntry> TestVerifyThread::sTestStructureEntries;
QMutex                    TestVerifyThread::sTestStructureEntriesMutex;
QSemaphore                TestVerifyThread::sTestStructureEntriesSemaphore;
QRegularExpression        TestVerifyThread::sStructureSizeTestRegExp("^TEST_ASSERT_EQUALS\\(sizeof\\((?:.*::)?(\\w+)(?:<.*)?\\), +\\d+\\);$");



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

void TestVerifyThread::pushTestStructureEntries(const QList<TestStructureEntry> &entries)
{
    QMutexLocker lock(&sTestStructureEntriesMutex);

    sTestStructureEntries.append(entries);
    sTestStructureEntriesSemaphore.release(entries.length());
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

TestStructureEntry TestVerifyThread::popTestStructureEntry()
{
    sTestStructureEntriesSemaphore.acquire();

    {
        QMutexLocker lock(&sTestStructureEntriesMutex);



        TestStructureEntry res = sTestStructureEntries.constFirst();

        if (res.getPath() == "")
        {
            sTestStructureEntriesSemaphore.release();
        }
        else
        {
            sTestStructureEntries.removeFirst();
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

void TestVerifyThread::noMoreTestStructureEntries()
{
    QList<TestStructureEntry> temp;
    temp.append(TestStructureEntry("", -1, ""));

    pushTestStructureEntries(temp);
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



    do
    {
        TestStructureEntry entry = popTestStructureEntry();

        if (entry.getPath() == "")
        {
            break;
        }

        processTestStructureEntry(entry);
    } while(true);
}

void TestVerifyThread::processTestEntry(const TestEntry &entry)
{
    QString testFolder;



    qint64 index = entry.getPath().lastIndexOf("/src/os/include/");

    if (index < 0)
    {
        index = entry.getPath().lastIndexOf("/src/os/shared/common/src/");

        if (index < 0)
        {
            index = entry.getPath().lastIndexOf("/include/");
        }
    }



    if (index >= 0)
    {
        QString parentFolder = entry.getPath().left(index);

        do
        {
            if (QFile::exists(parentFolder + "/ngos.files"))
            {
                break;
            }



            index = parentFolder.lastIndexOf('/');

            if (index < 0)
            {
                addMessage(entry.getPath(), "Failed to get relative path");

                return;
            }

            parentFolder = parentFolder.left(index);
        } while(true);



        testFolder = parentFolder + "/src/os/shared/uefibase/test";
    }
    else
    {
        index = entry.getPath().lastIndexOf("/src/");

        if (index < 0)
        {
            addMessage(entry.getPath(), QString("Failed to get src folder for %1: %2").arg(entry.getFunctionOrMacro()).arg(entry.getName()));

            return;
        }



        testFolder = entry.getPath().left(index) + "/test";
    }



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
            line.startsWith("TEST_CASE(\"")
            &&
            line.contains(entry.getName())
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

void TestVerifyThread::processTestStructureEntry(const TestStructureEntry &entry)
{
    QString testFolder;



    qint64 index = entry.getPath().lastIndexOf("/src/os/include/");

    if (index < 0)
    {
        index = entry.getPath().lastIndexOf("/src/os/shared/common/src/");

        if (index < 0)
        {
            index = entry.getPath().lastIndexOf("/include/");
        }
    }



    if (index >= 0)
    {
        QString parentFolder = entry.getPath().left(index);

        do
        {
            if (QFile::exists(parentFolder + "/ngos.files"))
            {
                break;
            }



            index = parentFolder.lastIndexOf('/');

            if (index < 0)
            {
                addMessage(entry.getPath(), "Failed to get relative path");

                return;
            }

            parentFolder = parentFolder.left(index);
        } while(true);



        testFolder = parentFolder + "/src/os/shared/uefibase/test";
    }
    else
    {
        index = entry.getPath().lastIndexOf("/src/");

        if (index < 0)
        {
            addMessage(entry.getPath(), QString("Failed to get src folder for structure %1").arg(entry.getName()));

            return;
        }



        testFolder = entry.getPath().left(index) + "/test";
    }



    if (!QDir(testFolder).exists())
    {
        addMessage(entry.getPath(), QString("Failed to get test folder for structure %1").arg(entry.getName()));

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
            if (filename == "types.h")
            {
                if (processTestStructureEntryWithTestModule(entry, path))
                {
                    good = true;

                    break;
                }
            }
        }
    }



    if (!good)
    {
        addMessage(entry.getPath(), QString("Test not found for size of structure: %1").arg(entry.getName()));
    }
}

bool TestVerifyThread::processTestStructureEntryWithTestModule(const TestStructureEntry &entry, const QString &path)
{
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

        QRegularExpressionMatch match = sStructureSizeTestRegExp.match(line);

        if (match.hasMatch())
        {
            QString structureName = match.captured(1);

            if (structureName == entry.getName())
            {
                return true;
            }
        }
    }



    return false;
}

void TestVerifyThread::addMessage(const QString &path, const QString &message)
{
    mMessages.append(TestMessageInfo(path, message));
}
