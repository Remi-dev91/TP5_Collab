#ifndef SEQUENCEACTIONS_H
#define SEQUENCEACTIONS_H

#include <vector>
#include "actionrobot.h"

class SequenceActions {
private:
    std::vector<ActionRobot*> m_actions;
public:
    SequenceActions() = default;
    ~SequenceActions() = default;

    void ajouter(ActionRobot* action);
    void executer(ContexteRobot& ctx);
    void nettoyer(); // delete et clear
};


#endif // SEQUENCEACTIONS_H
