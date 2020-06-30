#ifndef TEST_VERIFIER_SRC_OTHER_TESTENTRY_H
#define TEST_VERIFIER_SRC_OTHER_TESTENTRY_H



#include <QString>

#include "src/other/testentrytype.h"



class TestEntry
{
public:
    TestEntry(TestEntryType type, const QString &path, qint64 line, const QString &name, const QString &testModule); // TEST: NO

    bool operator<(const TestEntry &another) const; // TEST: NO

    QString getFunctionOrMacro() const; // TEST: NO

    TestEntryType getType() const; // TEST: NO
    QString getPath() const; // TEST: NO
    QString getName() const; // TEST: NO
    QString getTestModule() const; // TEST: NO

    QString toString() const; // TEST: NO

private:
    TestEntryType mType;
    QString       mPath;
    qint64        mLine;
    QString       mName;
    QString       mTestModule;
};



#endif // TEST_VERIFIER_SRC_OTHER_TESTENTRY_H
