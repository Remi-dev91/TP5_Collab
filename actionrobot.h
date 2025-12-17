#ifndef ACTIONROBOT_H
#define ACTIONROBOT_H
#include "contexterobot.h"

class ActionRobot {
public:
    virtual ~ActionRobot() = default;
    virtual void executer(ContexteRobot& ctx) = 0;
    virtual void afficherNom() const;

};


#endif // ACTIONROBOT_H
