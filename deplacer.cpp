#include <iostream>
#include "deplacer.h"

Deplacer::Deplacer(double p_dx,double p_dy, double p_dz)
{
    m_dx = p_dx;
    m_dy = p_dy;
    m_dz = p_dz;
}

void Deplacer::executer(ContexteRobot& ctx) {

    double nouveau_x = ctx.getX() + m_dx;
    double nouveau_y = ctx.getY() + m_dy;
    double nouveau_z = ctx.getZ() + m_dz;

    afficherNom();

    ctx.deplacerVers(nouveau_x, nouveau_y, nouveau_z);
}

void Deplacer::afficherNom() const {
    std::cout << "Action: Deplacer (dx="<<m_dx<< ", dy=" << m_dy << ", dz=" << m_dz << ")"<< std::endl;
}
