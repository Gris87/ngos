#ifndef COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTWORKERTHREAD_H                                                                                                                                       // Colorize: green
#define COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTWORKERTHREAD_H                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QThread>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QMutex>                                                                                                                                                                                        // Colorize: green
#include <QRegularExpression>                                                                                                                                                                            // Colorize: green
#include <QSemaphore>                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/test_verifier/other/testentry.h>                                                                                                                                             // Colorize: green
#include <com/ngos/devtools/test_verifier/other/teststructureentry.h>                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class TestWorkerThread: public QThread                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    TestWorkerThread(); // TEST: NO                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static qint64 getAmountOfFiles(); // TEST: NO                                                                                                                                                        // Colorize: green
    static void pushFile(const QString &path); // TEST: NO                                                                                                                                               // Colorize: green
    static QString popFile(); // TEST: NO                                                                                                                                                                // Colorize: green
    static void noMoreFiles(); // TEST: NO                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    const QList<TestStructureEntry>& getTestStructureEntries() const; // TEST: NO                                                                                                                        // Colorize: green
    const QList<TestEntry>& getTestEntries() const; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
protected:                                                                                                                                                                                               // Colorize: green
    void run() override; // TEST: NO                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    void processFile(const QString &path); // TEST: NO                                                                                                                                                   // Colorize: green
    void processLines(const QString &path, const QStringList &lines); // TEST: NO                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void addTestStructureEntry(const QString &path, qint64 lineNum, const QString &name, bool bitsDefined); // TEST: NO                                                                                  // Colorize: green
    void addTestEntry(TestEntryType type, const QString &path, qint64 lineNum, const QString &name, QString testModule, const QString &line, const QString &prevLine); // TEST: NO                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static qint64             sAmountOfFiles;                                                                                                                                                            // Colorize: green
    static QStringList        sFiles;                                                                                                                                                                    // Colorize: green
    static QMutex             sFilesMutex;                                                                                                                                                               // Colorize: green
    static QSemaphore         sFilesSemaphore;                                                                                                                                                           // Colorize: green
    static QRegularExpression sDefineRegexp;                                                                                                                                                             // Colorize: green
    static QRegularExpression sFunctionRegexp;                                                                                                                                                           // Colorize: green
    static QRegularExpression sDefinitionRegExp;                                                                                                                                                         // Colorize: green
    static QRegularExpression sBitsDefinitionRegExp;                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QList<TestStructureEntry> mTestStructureEntries;                                                                                                                                                     // Colorize: green
    QList<TestEntry>          mTestEntries;                                                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_TEST_VERIFIER_THREADS_TESTWORKERTHREAD_H                                                                                                                                     // Colorize: green
