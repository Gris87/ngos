#ifndef TEST_VERIFIER_SRC_OTHER_TESTSTRUCTUREENTRY_H
#define TEST_VERIFIER_SRC_OTHER_TESTSTRUCTUREENTRY_H



#include <QString>



class TestStructureEntry
{
public:
    TestStructureEntry(const QString &path, qint64 line, const QString &name); // TEST: NO

    bool operator<(const TestStructureEntry &another) const; // TEST: NO

    QString getPath() const; // TEST: NO
    QString getName() const; // TEST: NO

    QString toString() const; // TEST: NO

private:
    QString mPath;
    qint64  mLine;
    QString mName;
};



#endif // TEST_VERIFIER_SRC_OTHER_TESTSTRUCTUREENTRY_H
