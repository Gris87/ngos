#include "testworkerthread.h"

#include <QFile>



quint64     TestWorkerThread::sAmountOfFiles = 0;
QStringList TestWorkerThread::sFiles;
QMutex      TestWorkerThread::sFilesMutex;
QSemaphore  TestWorkerThread::sFilesSemaphore;



TestWorkerThread::TestWorkerThread()
    : QThread()
    , mTestStructureEntries()
    , mTestEntries()
    , mDefineRegexp("^#define +(\\w+)\\(([^)]*)\\) +(.+)$")
    , mFunctionRegexp("^(?:(?:static|const|inline) +)*(?:\\w[\\w<,>*& ]* )?(~?\\w+|operator.+)\\([^)]*\\).*$")
    , mDefinitionRegExp("^(?:struct|class|union|enum(?: class)?) +(\\w+).*$")
    , mBitsDefinitionRegExp("^ *\\w+ +\\w+ *: *\\d+;.*$")
{
    // Nothing
}

quint64 TestWorkerThread::getAmountOfFiles()
{
    return sAmountOfFiles - 1;
}

void TestWorkerThread::pushFile(const QString &path)
{
    QMutexLocker lock(&sFilesMutex);

    ++sAmountOfFiles;
    sFiles.append(path);
    sFilesSemaphore.release();
}

QString TestWorkerThread::popFile()
{
    sFilesSemaphore.acquire();

    {
        QMutexLocker lock(&sFilesMutex);



        QString res = sFiles.constFirst();

        if (res == "")
        {
            sFilesSemaphore.release();
        }
        else
        {
            sFiles.removeFirst();
        }

        return res;
    }
}

void TestWorkerThread::noMoreFiles()
{
    pushFile("");
}

const QList<TestStructureEntry>& TestWorkerThread::getTestStructureEntries() const
{
    return mTestStructureEntries;
}

const QList<TestEntry>& TestWorkerThread::getTestEntries() const
{
    return mTestEntries;
}

void TestWorkerThread::run()
{
    do
    {
        QString path = popFile();

        if (path == "")
        {
            break;
        }

        processFile(path);
    } while(true);
}

void TestWorkerThread::processFile(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        lines[i] = lines.at(i).trimmed();
    }

    processLines(path, lines);
}

void TestWorkerThread::processLines(const QString &path, const QStringList &lines)
{
    QString testModule = path.mid(path.lastIndexOf('/') + 1);



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line == '{')
        {
            if (i > 0)
            {
                QString prevLine1 = lines.at(i - 1);
                QString prevLine2 = (i >= 2) ? lines.at(i - 2) : "";

                if (
                    !prevLine1.startsWith("#define ")
                    &&
                    !prevLine1.endsWith('\\')
                    &&
                    !prevLine1.startsWith("namespace")
                    &&
                    !prevLine1.startsWith("enum")
                    &&
                    !prevLine1.startsWith("union")
                    &&
                    !prevLine1.startsWith("struct")
                    &&
                    !prevLine1.startsWith("class")
                   )
                {
                    qint64 lineNum = i - 1;



                    quint64 level = 1;

                    do
                    {
                        ++i;

                        if (i >= lines.length())
                        {
                            break;
                        }

                        QString anotherLine = lines.at(i);

                        if (anotherLine == '{')
                        {
                            ++level;
                        }
                        else
                        if (anotherLine == '}')
                        {
                            --level;

                            if (level <= 0)
                            {
                                break;
                            }
                        }
                    } while(true);



                    QRegularExpressionMatch match = mFunctionRegexp.match(prevLine1);

                    if (match.hasMatch())
                    {
                        QString name = match.captured(1);

                        addTestEntry(TestEntryType::INTERNAL_FUNCTION, path, lineNum, name, testModule, prevLine1, prevLine2);
                    }
                }
            }
        }
        else
        if (line.startsWith("#define "))
        {
            QRegularExpressionMatch match = mDefineRegexp.match(line);

            if (match.hasMatch())
            {
                QString prevLine = (i >= 1) ? lines.at(i - 1) : "";

                QString name       = match.captured(1);
                QString parameters = match.captured(2);
                QString value      = match.captured(3);

                qint64 lineNum = i;



                if (line.endsWith('\\'))
                {
                    do
                    {
                        ++i;

                        if (i >= lines.length())
                        {
                            break;
                        }

                        QString anotherLine = lines.at(i);

                        value += '\n';
                        value += anotherLine;

                        if (!anotherLine.endsWith('\\'))
                        {
                            break;
                        }
                    } while(true);
                }



                if (
                    parameters != "..."
                    &&
                    !value.contains(';')
                    &&
                    !value.contains('{')
                    &&
                    !value.contains('}')
                    &&
                    value.contains('(')
                    &&
                    value.contains(')')
                   )
                {
                    addTestEntry(TestEntryType::DEFINE, path, lineNum, name, testModule, line, prevLine);
                }
            }
            else
            {
                if (line.endsWith('\\'))
                {
                    do
                    {
                        ++i;

                        if (i >= lines.length())
                        {
                            break;
                        }

                        QString anotherLine = lines.at(i);

                        if (!anotherLine.endsWith('\\'))
                        {
                            break;
                        }
                    } while(true);
                }
            }
        }
        else
        if (line.contains(';'))
        {
            QRegularExpressionMatch match = mFunctionRegexp.match(line);

            if (match.hasMatch())
            {
                QString prevLine = (i >= 1) ? lines.at(i - 1) : "";

                QString name = match.captured(1);

                addTestEntry(TestEntryType::FUNCTION, path, i, name, testModule, line, prevLine);
            }
        }
        else
        {
            if (!path.contains("/tools/qt/"))
            {
                QRegularExpressionMatch match = mDefinitionRegExp.match(line);

                if (match.hasMatch())
                {
                    QString name = match.captured(1);



                    bool bitsDefined = false;

                    for (qint64 j = i + 1; j < lines.length(); ++j)
                    {
                        QRegularExpressionMatch match2 = mBitsDefinitionRegExp.match(lines.at(j));

                        if (match2.hasMatch())
                        {
                            bitsDefined = true;

                            break;
                        }
                    }



                    addTestStructureEntry(path, i, name, bitsDefined);
                }
            }
        }
    }
}

void TestWorkerThread::addTestStructureEntry(const QString &path, qint64 lineNum, const QString &name, bool bitsDefined)
{
    mTestStructureEntries.append(TestStructureEntry(path, lineNum, name, bitsDefined));
}

void TestWorkerThread::addTestEntry(TestEntryType type, const QString &path, qint64 lineNum, const QString &name, QString testModule, const QString &line, const QString &prevLine)
{
    if (
        !line.contains("// TEST: NO")
        &&
        !prevLine.startsWith("// TEST: NO")
       )
    {
        qint64 index = line.lastIndexOf("// TEST: MODULE=");

        if (index >= 0)
        {
            testModule = line.mid(index + 16);
        }
        else
        {
            index = prevLine.lastIndexOf("// TEST: MODULE=");

            if (index >= 0)
            {
                testModule = prevLine.mid(index + 16);
            }
        }

        mTestEntries.append(TestEntry(type, path, lineNum, name + "()", testModule));
    }
}
