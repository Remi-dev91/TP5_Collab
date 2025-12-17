#include "sequenceactions.h"

void SequenceActions::ajouter(ActionRobot* p_action) {
    m_actions.push_back(p_action);
}

void SequenceActions::executer(ContexteRobot& ctx) {
    for (std::size_t i = 0; i < m_actions.size(); ++i) {
        m_actions[i]->executer(ctx);
    }
}

void SequenceActions::nettoyer() {
    for (std::size_t i = 0; i < m_actions.size(); ++i) {
        delete m_actions[i];
    }
    m_actions.clear();
}
