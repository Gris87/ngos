#ifndef TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTWORKERTHREAD_H
#define TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTWORKERTHREAD_H



#include <QThread>

#include <QMutex>
#include <QRegularExpression>
#include <QSemaphore>

#include "src/com/ngos/devtools/test_verifier/other/testentry.h"
#include "src/com/ngos/devtools/test_verifier/other/teststructureentry.h"



class TestWorkerThread: public QThread
{
public:
    TestWorkerThread(); // TEST: NO

    static quint64 getAmountOfFiles(); // TEST: NO
    static void pushFile(const QString &path); // TEST: NO
    static QString popFile(); // TEST: NO
    static void noMoreFiles(); // TEST: NO

    const QList<TestStructureEntry>& getTestStructureEntries() const; // TEST: NO
    const QList<TestEntry>& getTestEntries() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void processFile(const QString &path); // TEST: NO
    void processLines(const QString &path, const QStringList &lines); // TEST: NO

    void addTestStructureEntry(const QString &path, qint64 lineNum, const QString &name, bool bitsDefined); // TEST: NO
    void addTestEntry(TestEntryType type, const QString &path, qint64 lineNum, const QString &name, QString testModule, const QString &line, const QString &prevLine); // TEST: NO

    static quint64     sAmountOfFiles;
    static QStringList sFiles;
    static QMutex      sFilesMutex;
    static QSemaphore  sFilesSemaphore;

    QList<TestStructureEntry> mTestStructureEntries;
    QList<TestEntry>          mTestEntries;
    QRegularExpression        mDefineRegexp;
    QRegularExpression        mFunctionRegexp;
    QRegularExpression        mDefinitionRegExp;
    QRegularExpression        mBitsDefinitionRegExp;
};



#endif // TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTWORKERTHREAD_H
