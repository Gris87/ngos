#ifndef ELFSPECVERIFIER_H
#define ELFSPECVERIFIER_H



#include <com/ngos/devtools/specs_verifier/specs/specverifier.h>



class ElfSpecVerifier: public SpecVerifier
{
public:
    ElfSpecVerifier();

    void verify(const QString &path) override;
};



#endif // ELFSPECVERIFIER_H
