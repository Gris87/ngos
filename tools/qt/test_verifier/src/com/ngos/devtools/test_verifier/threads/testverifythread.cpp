#include "testverifythread.h"

#include <QDir>
#include <QQueue>



QList<TestStructureEntry> TestVerifyThread::sTestStructureEntries;
QMutex                    TestVerifyThread::sTestStructureEntriesMutex;
QSemaphore                TestVerifyThread::sTestStructureEntriesSemaphore;
QList<TestEntry>          TestVerifyThread::sTestEntries;
QMutex                    TestVerifyThread::sTestEntriesMutex;
QSemaphore                TestVerifyThread::sTestEntriesSemaphore;
QRegularExpression        TestVerifyThread::sStructureSizeTestRegExp("^TEST_ASSERT_EQUALS\\(sizeof\\((?:.*::)?(\\w+)(?:<.*)?\\), +\\d+\\);$");



TestVerifyThread::TestVerifyThread()
    : QThread()
    , mMessages()
{
    // Nothing
}

void TestVerifyThread::pushTestStructureEntries(const QList<TestStructureEntry> &entries)
{
    QMutexLocker lock(&sTestStructureEntriesMutex);

    sTestStructureEntries.append(entries);
    sTestStructureEntriesSemaphore.release(entries.size());
}

void TestVerifyThread::pushTestEntries(const QList<TestEntry> &entries)
{
    QMutexLocker lock(&sTestEntriesMutex);

    sTestEntries.append(entries);
    sTestEntriesSemaphore.release(entries.size());
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

void TestVerifyThread::noMoreTestStructureEntries()
{
    QList<TestStructureEntry> temp;
    temp.append(TestStructureEntry("", -1, "", false));

    pushTestStructureEntries(temp);
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
        TestStructureEntry entry = popTestStructureEntry();

        if (entry.getPath() == "")
        {
            break;
        }

        processTestStructureEntry(entry);
    } while(true);



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

void TestVerifyThread::processTestStructureEntry(const TestStructureEntry &entry)
{
    QString testFolder;



    qint64 index = entry.getPath().lastIndexOf("/src/os/shared/common/src/");

    if (index < 0)
    {
        index = entry.getPath().lastIndexOf("/include/");
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



    bool good  = false;
    bool good2 = !entry.isBitsDefined();



    QQueue<QFileInfo> files;
    files.enqueue(QFileInfo(testFolder));

    while (!files.isEmpty())
    {
        QFileInfo file = files.dequeue();

        QString path     = file.absoluteFilePath();
        QString fileName = file.fileName();



        if (file.isDir())
        {
            QFileInfoList filesInfo = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

            for (qint64 i = 0; i < filesInfo.size(); ++i)
            {
                files.enqueue(filesInfo.at(i));
            }
        }
        else
        {
            if (fileName == "types.h")
            {
                QFile file(path);

                if (!file.open(QIODevice::ReadOnly))
                {
                    continue;
                }

                QString content = QString::fromUtf8(file.readAll());
                file.close();



                QStringList lines = content.split('\n');



                if (!good)
                {
                    for (qint64 i = 0; i < lines.size(); ++i)
                    {
                        QString line = lines.at(i).trimmed();

                        QRegularExpressionMatch match = sStructureSizeTestRegExp.match(line);

                        if (match.hasMatch())
                        {
                            QString structureName = match.captured(1);

                            if (structureName == entry.getName())
                            {
                                good = true;

                                break;
                            }
                        }
                    }
                }



                if (!good2)
                {
                    QString searchLine = "    TEST_CASE(\"" + entry.getName() + "\");";

                    for (qint64 i = 0; i < lines.size(); ++i)
                    {
                        if (lines.at(i) == searchLine)
                        {
                            good2 = true;

                            break;
                        }
                    }
                }



                if (good && good2)
                {
                    break;
                }
            }
        }
    }



    if (!good)
    {
        addMessage(entry.getPath(), QString("Test not found for size of structure: %1").arg(entry.getName()));
    }

    if (!good2)
    {
        addMessage(entry.getPath(), QString("Test not found for bits of structure: %1").arg(entry.getName()));
    }
}

void TestVerifyThread::processTestEntry(const TestEntry &entry)
{
    QString testFolder;



    qint64 index = entry.getPath().lastIndexOf("/src/os/shared/common/src/");

    if (index < 0)
    {
        index = entry.getPath().lastIndexOf("/include/");
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
        QString fileName = file.fileName();



        if (file.isDir())
        {
            QFileInfoList filesInfo = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

            for (qint64 i = 0; i < filesInfo.size(); ++i)
            {
                files.enqueue(filesInfo.at(i));
            }
        }
        else
        {
            if (fileName == entry.getTestModule())
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

    for (qint64 i = 0; i < lines.size(); ++i)
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
        else
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

void TestVerifyThread::addMessage(const QString &path, const QString &message)
{
    mMessages.append(TestMessageInfo(path, message));
}
