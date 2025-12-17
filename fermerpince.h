#ifndef FERMERPINCE_H
#define FERMERPINCE_H
#include "actionrobot.h"

class FermerPince : public ActionRobot
{
public:
    FermerPince();
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // FERMERPINCE_H
