#ifndef TEST_VERIFIER_SRC_THREADS_TESTWORKERTHREAD_H
#define TEST_VERIFIER_SRC_THREADS_TESTWORKERTHREAD_H



#include <QThread>

#include <QMutex>
#include <QRegularExpression>
#include <QSemaphore>

#include "src/other/testentry.h"



class TestWorkerThread: public QThread
{
public:
    TestWorkerThread(); // TEST: NO

    static quint64 getAmountOfFiles(); // TEST: NO
    static void pushFile(const QString &path); // TEST: NO
    static QString popFile(); // TEST: NO
    static void noMoreFiles(); // TEST: NO

    const QList<TestEntry>& getTestEntries() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void processFile(const QString &path); // TEST: NO
    void processLines(const QString &path, const QStringList &lines); // TEST: NO

    void addTestEntry(TestEntryType type, const QString &path, qint64 lineNum, const QString &name, QString testModule, const QString &line, const QString &prevLine); // TEST: NO

    static quint64     sAmountOfFiles;
    static QStringList sFiles;
    static QMutex      sFilesMutex;
    static QSemaphore  sFilesSemaphore;

    QList<TestEntry>   mTestEntries;
    QRegularExpression mDefineRegexp;
    QRegularExpression mFunctionRegexp;
};



#endif // TEST_VERIFIER_SRC_THREADS_TESTWORKERTHREAD_H
