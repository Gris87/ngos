#ifndef AMDCPUIDSPECVERIFIER_H                                                                                                                                                                           // Colorize: green
#define AMDCPUIDSPECVERIFIER_H                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class AmdCpuidSpecVerifier: public SpecVerifier                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    AmdCpuidSpecVerifier(); // TEST: NO                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(SpecVerifyThread *thread) override; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    bool downloadSpecification(SpecVerifyThread *thread, const QString &url, QString &specContent); // TEST: NO                                                                                                                           // Colorize: green
    void checkWithSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkAmdSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                        // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // AMDCPUIDSPECVERIFIER_H                                                                                                                                                                         // Colorize: green