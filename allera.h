#ifndef ALLERA_H
#define ALLERA_H
#include "actionrobot.h"

class AllerA : public ActionRobot
{
private:
    double m_finX,m_finY,m_finZ;
public:
    AllerA(double p_finX,double p_finY,double p_finZ);
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // ALLERA_H
