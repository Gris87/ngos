#ifndef PESPECVERIFIER_H                                                                                                                                                                                 // Colorize: green
#define PESPECVERIFIER_H                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class PESpecVerifier: public SpecVerifier                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    PESpecVerifier(); // TEST: NO                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(SpecVerifyThread *thread) override; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    void checkWithSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkPeSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                         // Colorize: green
    void checkPeHeader(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                         // Colorize: green
    void checkPeHeaderSignature(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                         // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // PESPECVERIFIER_H                                                                                                                                                                               // Colorize: green
