#ifndef TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTSTRUCTUREENTRY_H
#define TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTSTRUCTUREENTRY_H



#include <QString>



class TestStructureEntry
{
public:
    TestStructureEntry(const QString &path, qint64 line, const QString &name, bool bitsDefined); // TEST: NO

    bool operator<(const TestStructureEntry &another) const; // TEST: NO

    QString getPath() const; // TEST: NO
    QString getName() const; // TEST: NO
    bool isBitsDefined() const; // TEST: NO

    QString toString() const; // TEST: NO

private:
    QString mPath;
    qint64  mLine;
    QString mName;
    bool    mBitsDefined;
};



#endif // TEST_VERIFIER_SRC_COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTSTRUCTUREENTRY_H