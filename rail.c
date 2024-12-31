#include "rail.h"


int avoirLettre(Vecteur main, const char mot[MAX_MOT]) {
    Vecteur copieMain;
    vecteurInitialiser(&copieMain,main.taille);
    for(int i=0;i<main.taille;i++){
        copieMain.donnees[i] = main.donnees[i];
    }
    for(int i = 0; mot[i]; i++) {
        int trouver = 0;
        for(int j = 0; j < copieMain.taille; j++) {
            if(mot[i] == copieMain.donnees[j]) {
                copieMain.donnees[j] = '*';
                trouver = 1;
                break;
            }
        }
        if(trouver==0){
            return 0;
        }
    }
    return 1;
}