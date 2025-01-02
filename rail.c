#include "rail.h"


int verifierMotDansMain(const Vecteur main, const char* mot) {
    Vecteur copieMain;
    vecteurInitialiser(&copieMain,main.taille);
    copieMain.taille=main.taille;
    for (int i=0; i < main.taille; i++) {
        copieMain.donnees[i]=main.donnees[i];
    }
    // Parcourir chaque lettre du mot
    for (int i = 0; mot[i]!= '\0'; i++) {
        int lettreTrouvee = 0;
        for (int j = 0; j<copieMain.taille; j++) {
            if (copieMain.donnees[j] == mot[i]) {
                lettreTrouvee = 1;
                copieMain.donnees[j] = ' '; // Remplace la lettre pour éviter les doublons
                break;
            }
        }
        if (lettreTrouvee==0) {
            return 0;
        }
    }
    return 1;
}

void afficherRail(Rail* rail) {
    printf("r> ");
    for (int i=0;i< rail->tailleRail;++i) {
        printf("%c",rail->rail[i]);
    }
    printf("\n");
    printf("v> ");
    for (int i=rail->tailleRail-1;i>=0;--i) {
        printf("%c",rail->rail[i]);
    }
    printf("\n");
}
