#ifndef CONTEXTEROBOT_H
#define CONTEXTEROBOT_H
#include <iostream>

class ContexteRobot {
private:
    double m_x, m_y, m_z;
    bool m_pince_ouverte;
    int m_angle_robot;

public:
    // Constructeur
    ContexteRobot(double p_x, double p_y, double p_z, bool p_pince_ouverte);

    // Accès lecture
    double getX();
    double getY();
    double getZ();
    bool PinceEstOuverte();

    // Actions
    void deplacerVers(double p_x, double p_y, double p_z);
    void ouvrirPince();
    void fermerPince();
    void attendre(int p_duree);
    void rotation(int p_angle);

    // Affichage
    void afficherPosition();
};

#endif // CONTEXTEROBOT_H
