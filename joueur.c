#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void remplirJoueur(Joueur* joueur,Pioche* p, const int id) {
    vecteurInitialiser(&joueur->main,CARTEJOUEUR);
    joueur->idJoueur=id;
    for (int i = 0; i < CARTEJOUEUR; i++) {
        vecteurAjouterFin(&joueur->main,piocher(p));
        ++joueur->tailleMain;
    }
    trierMain(joueur);
}

void afficherJoueur(const Joueur* joueur) {
    printf("%d : ",joueur->idJoueur+1);
    for (int i = 0; i < CARTEJOUEUR; i++) {
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