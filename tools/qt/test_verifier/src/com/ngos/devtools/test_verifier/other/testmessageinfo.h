#ifndef COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTMESSAGEINFO_H                                                                                                                                          // Colorize: green
#define COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTMESSAGEINFO_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QString>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class TestMessageInfo                                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    TestMessageInfo(const QString &path, const QString &message); // TEST: NO                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    bool operator<(const TestMessageInfo &another) const; // TEST: NO                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString toString() const; // TEST: NO                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    QString mPath;                                                                                                                                                                                       // Colorize: green
    QString mMessage;                                                                                                                                                                                    // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTMESSAGEINFO_H                                                                                                                                        // Colorize: green
