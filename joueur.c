#include "joueur.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

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

void trierMain( Joueur* joueur) {
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

int verifierLettresDansMain(const Vecteur main, const char* mot) {
    Vecteur copieMain;
    initialiserVecteur(&copieMain,main.taille);
    copieMain.taille=main.taille;
    for (int i=0; i < main.taille; i++) {
        copieMain.donnees[i]=main.donnees[i];
    }
    for (int i = 0; mot[i]!= '\0'; i++) {
        int lettreTrouvee = 0;
        for (int j = 0; j<copieMain.taille; j++) {
            if (copieMain.donnees[j] == mot[i]) {
                lettreTrouvee = 1;
                copieMain.donnees[j] = ' ';
                break;
            }
        }
        if (lettreTrouvee==0) {
            return 0;
        }
    }
    return 1;
}

void donnerLettres(Joueur* j,char* expulse) {
    for (int i = 0; expulse[i] != '\0'; i++) {
        if (j->tailleMain<j->main.capacite){
            j->main.donnees[j->tailleMain++] = expulse[i];
            j->main.taille++;
        }
        else {
            ajouterAuVecteur(&j->main,expulse[i]);
            j->tailleMain++;
        }

    }
}

void testJoueur() {
    Joueur joueur1;
    Pioche pioche;
    initPioche(&pioche);
    remplirJoueur(&joueur1, &pioche, J1);
    assert(joueur1.tailleMain == LETTREJOUEUR);
    char mot[] = "ABC";
    int peutFormerMot = verifierLettresDansMain(joueur1.main, mot);
    if (peutFormerMot) {
        int tailleAvantSuppression = joueur1.tailleMain;
        supprimerLettre(&joueur1, mot);
        assert(joueur1.tailleMain == tailleAvantSuppression - (int)strlen(mot));
    } else {
        assert(peutFormerMot == 0);
    }
    char lettreAjoutee[2]= "A\0";
        int tailleAvantAjout = joueur1.tailleMain;
        donnerLettres(&joueur1,lettreAjoutee);
        assert(joueur1.tailleMain == tailleAvantAjout + 1);
        int lettreTrouvee = 0;
        for (int i = 0; i < joueur1.tailleMain; i++) {
            if (joueur1.main.donnees[i] == 'A') {
                lettreTrouvee=1;
            }
        }
        assert(lettreTrouvee > 0);
        libererVecteur(&joueur1.main);
}
