#include "joueur.h"

#include <stdio.h>

void remplirJoueur(Joueur* joueur,Pioche* p, const int id) {
    initialiserVecteur(&joueur->main,LETTREJOUEUR);
    joueur->tailleMain=0;
    joueur->idJoueur=id;
    for (int i = 0; i < LETTREJOUEUR; i++) {
        ajouterAuVecteur(&joueur->main,piocher(p));
        ++joueur->tailleMain;
    }
    trierMain(joueur);
}

void afficherJoueur(const Joueur* joueur) {
    printf("%d : ",joueur->idJoueur+1);
    for (int i = 0; i < joueur->tailleMain; i++) {
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

void supprimerLettre (Joueur *joueur,const char *mot) {
    for (int i = 0; mot[i]!= '\0'; i++) {
        for (int j = 0; j<joueur->tailleMain; j++) {
            if (joueur->main.donnees[j] == mot[i]) {
                supprimerA(&joueur->main,j);
                --joueur->tailleMain;
                break;
            }
            }
        }
    trierMain(joueur);
}

int verifierMotDansMain(const Vecteur main, const char* mot) {
    Vecteur copieMain;
    initialiserVecteur(&copieMain,main.taille);
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

void donnerLettres(Joueur* j,char expulse) {
    for (int i = 0; i < j->tailleMain; i++) {
        ajouterAuVecteur(&j->main,expulse);
        j->tailleMain++;
    }
}
