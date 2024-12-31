#include "joueur.h"

void remplirJoueur(Joueur* joueur,Pioche* p, const int id) {
    vecteurInitialiser(&joueur->main,LETTREJOUEUR);
    joueur->tailleMain=0;
    joueur->idJoueur=id;
    for (int i = 0; i < LETTREJOUEUR; i++) {
        vecteurAjouterFin(&joueur->main,piocher(p));
        ++joueur->tailleMain;
    }
    trierMain(joueur);
}

void afficherJoueur(const Joueur* joueur) {
    printf("%d : ",joueur->idJoueur+1);
    for (int i = 0; i < LETTREJOUEUR; i++) {
        printf("%c",joueur->main.donnees[i]);
    }
    printf("\n");
}

void trierMain(Joueur *joueur) {
    for (int i = 0; i < joueur->tailleMain - 1; i++) {
        for (int j = 0; j <joueur->tailleMain  - i - 1; j++) {
            if (joueur->main.donnees[j] > joueur->main.donnees[j + 1]) {
                char temp = joueur->main.donnees[j];
                joueur->main.donnees[j] = joueur->main.donnees[j + 1];
                joueur->main.donnees[j + 1] = temp;
            }
        }
    }
}

