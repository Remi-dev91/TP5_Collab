#include <iostream>
#include "fermerpince.h"

FermerPince::FermerPince()
{

}

void FermerPince::executer(ContexteRobot& ctx) {
    afficherNom();
    ctx.fermerPince();
}

void FermerPince::afficherNom() const {
    std::cout << "Action: FermerPince"<< std::endl;
}
