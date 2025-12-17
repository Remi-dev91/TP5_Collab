#ifndef ATTENDRE_H
#define ATTENDRE_H
#include "actionrobot.h"

class Attendre : public ActionRobot
{
private:
    int duree;
public:
    Attendre(int p_duree);
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // ATTENDRE_H
