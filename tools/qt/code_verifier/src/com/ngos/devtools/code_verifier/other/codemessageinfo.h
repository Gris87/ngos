#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEMESSAGEINFO_H                                                                                                                                          // Colorize: green
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEMESSAGEINFO_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QString>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class CodeMessageInfo                                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    CodeMessageInfo(const QString &path, qint64 line, const QString &message); // TEST: NO                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    bool operator<(const CodeMessageInfo &another) const; // TEST: NO                                                                                                                                    // Colorize: green
    bool operator==(const CodeMessageInfo &another) const; // TEST: NO                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString toString() const; // TEST: NO                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    QString mPath;                                                                                                                                                                                       // Colorize: green
    qint64  mLine;                                                                                                                                                                                       // Colorize: green
    QString mMessage;                                                                                                                                                                                    // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_OTHER_CODEMESSAGEINFO_H                                                                                                                                        // Colorize: green
