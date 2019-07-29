#ifndef TEST_VERIFIER_SRC_THREADS_TESTVERIFYTHREAD_H
#define TEST_VERIFIER_SRC_THREADS_TESTVERIFYTHREAD_H



#include <QThread>

#include <QMutex>
#include <QSemaphore>

#include "src/other/testentry.h"
#include "src/other/testmessageinfo.h"
#include "src/other/teststructureentry.h"



class TestVerifyThread: public QThread
{
public:
    TestVerifyThread(); // TEST: NO

    static void pushTestEntries(const QList<TestEntry> &entries); // TEST: NO
    static void pushTestStructureEntries(const QList<TestStructureEntry> &entries); // TEST: NO
    static TestEntry popTestEntry(); // TEST: NO
    static TestStructureEntry popTestStructureEntry(); // TEST: NO
    static void noMoreTestEntries(); // TEST: NO
    static void noMoreTestStructureEntries(); // TEST: NO

    const QList<TestMessageInfo>& getMessages() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void processTestEntry(const TestEntry &entry); // TEST: NO
    bool processTestEntryWithTestModule(const TestEntry &entry, const QString &path); // TEST: NO
    void processTestStructureEntry(const TestStructureEntry &entry); // TEST: NO
    bool processTestStructureEntryWithTestModule(const TestStructureEntry &entry, const QString &path); // TEST: NO

    void addMessage(const QString &path, const QString &message); // TEST: NO

    static QList<TestEntry>          sTestEntries;
    static QMutex                    sTestEntriesMutex;
    static QSemaphore                sTestEntriesSemaphore;
    static QList<TestStructureEntry> sTestStructureEntries;
    static QMutex                    sTestStructureEntriesMutex;
    static QSemaphore                sTestStructureEntriesSemaphore;

    QList<TestMessageInfo> mMessages;
};



#endif // TEST_VERIFIER_SRC_THREADS_TESTVERIFYTHREAD_H
