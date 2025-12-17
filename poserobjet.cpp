#include "poserobjet.h"
#include <iostream>

PoserObjet::PoserObjet(double p_finX,double p_finY,double p_finZ)
{
    m_finX = p_finX;
    m_finY = p_finY;
    m_finZ = p_finZ;
}

void PoserObjet::executer(ContexteRobot& ctx){
    ctx.deplacerVers(m_finX,m_finY,m_finZ);
    ctx.deplacerVers(m_finX,m_finY,(m_finZ-m_finZ));
    ctx.ouvrirPince();
    ctx.deplacerVers(m_finX,m_finY,m_finZ);
    afficherNom();

}

void PoserObjet::afficherNom() const {
    std::cout << "Action: PoserObject "<< m_finX << " " << m_finY << " " << m_finZ<< std::endl;
}
