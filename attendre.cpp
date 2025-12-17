#include "attendre.h"

Attendre::Attendre(int p_duree)
{
    duree = p_duree;
}

void Attendre::executer(ContexteRobot& ctx){
    afficherNom();
    ctx.attendre(duree);
}

void Attendre::afficherNom() const {
    std::cout << "Attente de "<< duree << std::endl;
}
