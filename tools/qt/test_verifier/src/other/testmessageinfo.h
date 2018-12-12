#ifndef TEST_VERIFIER_SRC_OTHER_TESTMESSAGEINFO_H
#define TEST_VERIFIER_SRC_OTHER_TESTMESSAGEINFO_H



#include <QString>



class TestMessageInfo
{
public:
    TestMessageInfo(const QString &path, const QString &message); // TEST: NO

    bool operator<(const TestMessageInfo &another) const; // TEST: NO

    QString toString() const; // TEST: NO

private:
    QString mPath;
    QString mMessage;
};



#endif // TEST_VERIFIER_SRC_OTHER_TESTMESSAGEINFO_H
