#include "allera.h"

AllerA::AllerA(double p_finX,double p_finY,double p_finZ)
{
    m_finX = p_finX;
    m_finY = p_finY;
    m_finZ = p_finZ;
}

void AllerA::executer(ContexteRobot& ctx) {
    afficherNom();
    ctx.deplacerVers(m_finX,m_finY,m_finZ);
}

void AllerA::afficherNom() const {
    std::cout << "Aller aux coordonnees =>  "<< m_finX <<" "<< m_finY <<" "<< m_finZ << std::endl;
}


