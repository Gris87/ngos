#ifndef INTELCPUIDSPECVERIFIER_H                                                                                                                                                                           // Colorize: green
#define INTELCPUIDSPECVERIFIER_H                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class IntelCpuidSpecVerifier: public SpecVerifier                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    IntelCpuidSpecVerifier(); // TEST: NO                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(SpecVerifyThread *thread) override; // TEST: NO                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    void checkWithSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                       // Colorize: green
    void checkIntelSpecification(SpecVerifyThread *thread, const QString &specContent); // TEST: NO                                                                                                        // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // INTELCPUIDSPECVERIFIER_H                                                                                                                                                                         // Colorize: green
