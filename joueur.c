#include "joueur.h"
#include <stdio.h>


void remplirJoueur(Joueur* joueur,Pioche* p, const int id) {
    joueur->idJoueur=id;
    for (int i = 0; i < CARTEJOUEUR; i++) {
        joueur->main[i]=piocher(p);
        ++joueur->tailleMain;
    }
}

void afficherJoueur(const Joueur* joueur) {
    printf("%d : ",joueur->idJoueur+1);
    for (int i = 0; i < CARTEJOUEUR; i++) {
        printf("%c",joueur->main[i]);
    }
    printf("\n");
}
//
// Created by selyan on 26/12/2024.
//
