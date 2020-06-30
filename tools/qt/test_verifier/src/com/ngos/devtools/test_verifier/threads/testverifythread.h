#ifndef TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTVERIFYTHREAD_H
#define TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTVERIFYTHREAD_H



#include <QThread>

#include <QMutex>
#include <QRegularExpression>
#include <QSemaphore>

#include "src/com/ngos/devtools/test_verifier/other/testentry.h"
#include "src/com/ngos/devtools/test_verifier/other/testmessageinfo.h"
#include "src/com/ngos/devtools/test_verifier/other/teststructureentry.h"



class TestVerifyThread: public QThread
{
public:
    TestVerifyThread(); // TEST: NO

    static void pushTestStructureEntries(const QList<TestStructureEntry> &entries); // TEST: NO
    static void pushTestEntries(const QList<TestEntry> &entries); // TEST: NO
    static TestStructureEntry popTestStructureEntry(); // TEST: NO
    static TestEntry popTestEntry(); // TEST: NO
    static void noMoreTestStructureEntries(); // TEST: NO
    static void noMoreTestEntries(); // TEST: NO

    const QList<TestMessageInfo>& getMessages() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void processTestStructureEntry(const TestStructureEntry &entry); // TEST: NO
    void processTestEntry(const TestEntry &entry); // TEST: NO
    bool processTestEntryWithTestModule(const TestEntry &entry, const QString &path); // TEST: NO

    void addMessage(const QString &path, const QString &message); // TEST: NO

    static QList<TestStructureEntry> sTestStructureEntries;
    static QMutex                    sTestStructureEntriesMutex;
    static QSemaphore                sTestStructureEntriesSemaphore;
    static QList<TestEntry>          sTestEntries;
    static QMutex                    sTestEntriesMutex;
    static QSemaphore                sTestEntriesSemaphore;
    static QRegularExpression        sStructureSizeTestRegExp;

    QList<TestMessageInfo> mMessages;
};



#endif // TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTVERIFYTHREAD_H
