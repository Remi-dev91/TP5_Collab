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
#include <limits>
using namespace std;

int main() {
    ifstream fichier("data/plan.txt");
    if (!fichier.is_open()){
        cout << "Erreur : impossible d'ouvrir le fichier plan.txt " << endl;
        return 1;
    }

    ofstream journal("data/journal.txt");
    if (!journal.is_open()){
        cout << "Erreur : impossible d'ouvrir le fichier journal.txt " << endl;
        return 1;
    }

    ContexteRobot ctx(0,0,0,false);
    SequenceActions plan;
    string commande;

    // Boucle de lecture
    cout << "------- Debut du plan d'execution ------"<<endl;
    journal << "============================================" <<endl;
    journal << "Format : Action + Paramètres "<<endl;
    journal << "============================================" <<endl;
    while (fichier >> commande){

        if (commande == "DEPLACER"){
            double dx, dy, dz;

            if (!(fichier >> dx >> dy >> dz)) {
                std::cerr << "Erreur : paramètres invalides pour DEPLACER\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            plan.ajouter(new Deplacer(dx,dy,dz));
            journal << commande << endl;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande << "  " << "dx : "<< dx << "dy : " << dy << "dz : " << dz<<endl;

        } else if (commande == "OUVRIR_PINCE"){
            plan.ajouter(new OuvrirPince());
            journal << commande << endl;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande<<endl;

        } else if(commande == "FERMER_PINCE"){
            plan.ajouter(new FermerPince());
            journal << commande << endl;

        } else if (commande == "ALLER_A") {
            double dx, dy, dz;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande<<endl;

            if (!(fichier >> dx >> dy >> dz)) {
                std::cerr << "Erreur : paramètres invalides pour ALLER_A\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            plan.ajouter(new AllerA(dx,dy,dz));
            journal << commande << endl;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande << "  " << "dx : "<< dx << "dy : " << dy << "dz : " << dz<<endl;

        } else if (commande == "POSEROBJET") {
            double dx, dy, dz;

            if (!(fichier >> dx >> dy >> dz)) {
                std::cerr << "Erreur : paramètres invalides pour POSEROBJET\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            plan.ajouter(new PoserObjet(dx,dy,dz));
            journal << commande << endl;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande << "  " << "dx : "<< dx << "dy : " << dy << "dz : " << dz<<endl;

        } else if (commande == "ATTENDRE_2") {
            plan.ajouter(new Attendre(2));
            journal << commande << endl;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande<<endl;

        } else if (commande == "ROTATION") {
            int angleRobot;

            if (!(fichier >> angleRobot)) {
                std::cerr << "Erreur : paramètre invalide pour ROTATION\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            plan.ajouter(new Rotation(angleRobot));
            journal << commande << endl;
            journal.seekp(0, ios::end);
            journal << "Action ecécutée : ";
            journal<<commande << "  " << "angle de rotation : "<< angleRobot <<endl;

        } else {
            cout << "Commande inconnue : " << commande << endl;

            fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    journal.close();

    plan.executer(ctx);
    cout << "-------- Fin du plan d'execution --------"<<endl;

    cout << "\n======== Etat du robot ========"<<endl;
    ctx.afficherPosition();
    plan.nettoyer();

    cout << "==============================="<<endl;
    return 0;
}
