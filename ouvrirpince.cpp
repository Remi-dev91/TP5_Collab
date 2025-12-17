#include <iostream>
#include "ouvrirpince.h"

OuvrirPince::OuvrirPince()
{

}

void OuvrirPince::executer(ContexteRobot& ctx) {
    afficherNom();
    ctx.ouvrirPince();
}

void OuvrirPince::afficherNom() const {
    std::cout << "Action: OuvrirPince"<< std::endl;
}
