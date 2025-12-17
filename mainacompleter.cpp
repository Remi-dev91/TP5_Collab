#include "contexterobot.h"
#include "sequenceactions.h"
#include "deplacer.h"
#include "ouvrirpince.h"
#include "fermerpince.h"
#include "allera.h"
#include "poserobjet.h"
#include "attendre.h"
#include "rotation.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    /*
    ContexteRobot ctx(0, 0, 100, true);

    SequenceActions plan;
    plan.ajouter(new Deplacer(100, 0, 0));
    plan.ajouter(new FermerPince());
    plan.ajouter(new OuvrirPince());
    plan.ajouter(new Deplacer(0, 100, 0));
    plan.ajouter(new Deplacer(0, 0, 100));
    plan.ajouter(new AllerA(250,250,250));
    plan.ajouter(new PoserObjet(250,250,250));

    plan.executer(ctx);
    ctx.afficherPosition();
    plan.nettoyer();*/

    ifstream fichier("data/plan.txt");
    if (!fichier.is_open()){
        cout << "Erreur : impossible d'ouvrir le fichier plan.txt " << std::endl;
        return 1;
    }

    ofstream journal("data/journal.txt");
    if (!fichier.is_open()){
        cout << "Erreur : impossible d'ouvrir le fichier journal.txt " << std::endl;
        return 1;
    }

    ContexteRobot ctx(0,0,0,false);
    SequenceActions plan;
    string commande;
    while (fichier >> commande){
        if (commande == "DEPLACER"){
            double dx, dy ,dz;
            fichier >> dx >> dy >> dz;
            plan.ajouter(new Deplacer(dx,dy,dz));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else if (commande == "OUVRIR_PINCE"){
            plan.ajouter(new OuvrirPince());
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else if(commande == "FERMER_PINCE"){
            plan.ajouter(new FermerPince());
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else if (commande == "ALLER_A") {
            double dx, dy ,dz;
            fichier >> dx >> dy >> dz;
            plan.ajouter(new AllerA(dx,dy,dz));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else if (commande == "POSEROBJET") {
            double dx, dy ,dz;
            fichier >> dx >> dy >> dz;
            plan.ajouter(new PoserObjet(dx,dy,dz));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else if (commande == "ATTENDRE_2") {
            plan.ajouter(new Attendre(2));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else if (commande == "ROTATION") {
            int angleRobot;
            fichier >> angleRobot;
            plan.ajouter(new Rotation(angleRobot));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;

        }else {
            cout << "Commande inconnue : " << commande << std::endl;
        }
    }
    journal.close();
    plan.executer(ctx);
    ctx.afficherPosition();
    plan.nettoyer();
    return 0;
}
