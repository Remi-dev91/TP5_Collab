#ifndef POSEROBJET_H
#define POSEROBJET_H
#include "actionrobot.h"

class PoserObjet : public ActionRobot
{
private:
    double m_finX,m_finY,m_finZ;
public:
    PoserObjet(double p_finX,double p_finY,double p_finZ);
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};


#endif // POSEROBJET_H
