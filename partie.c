#include "partie.h"
#include <assert.h>
void initialiserPartie(Partie* p){
    initPioche(&p->pioche);
    initJoueurs(p,&p->pioche);
    p->rail.tailleRail=0;
    p->joueurActuelle=J1;
}

void initJoueurs(Partie* p,Pioche* v) {
    remplirJoueur(&p->joueur[J1],v,J1);
    remplirJoueur(&p->joueur[J2],v,J2);
    for (int i=0;i<NBJOUEURS;i++) {
        afficherJoueur(&p->joueur[i]);
    }
    printf("\n");
}

void demanderMot(Partie* p,char mot[MAX_MOT]){
    do{
        printf("%d> ",p->joueurActuelle+1);
        scanf("%s",mot);
    }while(strlen(mot)!=MAX_MOT-1 || !verifierLettresDansMain(p->joueur[p->joueurActuelle].main,mot) || !motDansStockage(&p->stockage,mot) || !estDansDictionnaire(mot));
}

void joueurSuivant(Partie* p) {
    ++p->joueurActuelle;
    p->joueurActuelle%=2;
}



void savoirQuiJoue(Partie* p,const char* mot1,const char* mot2) {
    if (strcmp(mot1,mot2)<0) {
        p->joueurActuelle=J1;
    }
    else
        p->joueurActuelle=J2;
}

void tourDeJeu(Partie* p) {
    char input[TAILLE_INPUT];
    char mot[TAILLE_MOT];
    char motParanthese[TAILLE_MOT_VIDE];
    char motVide[TAILLE_MOT_VIDE+1];
    char motHorsParanthese[TAILLE_MOT_VIDE-1];
    char expluse[TAILLE_MOT_VIDE-1];
    do {
        printf("%d> ",p->joueurActuelle+1);
        scanf("%s",input);
        scanf("%s",&mot);
        enleverParentheses(mot,motVide);
        extraireEntreParentheses(mot,motParanthese);
        enleverEntreParentheses(mot,motHorsParanthese);
    }while (!verifTailleMot(motVide,motParanthese) || !motDansStockage(&p->stockage,motVide) || !verifierLettresDansMain(p->joueur[p->joueurActuelle].main,motHorsParanthese) || !verifMotRail(&p->rail,mot,motParanthese,input) || !estDansDictionnaire(motVide));
    printf("\n");
    inserer_mots(&p->rail,mot,motHorsParanthese,input,expluse);
    expluse[strlen(motHorsParanthese)]='\0';
    ajouterMotStockage(&p->stockage,motVide);
    joueurSuivant(p);
    donnerLettres(&p->joueur[p->joueurActuelle],expluse);
    joueurSuivant(p);
    supprimerLettre(&p->joueur[p->joueurActuelle],motHorsParanthese);
    joueurSuivant(p);
    trierMain(&p->joueur[p->joueurActuelle]);
    joueurSuivant(p);
    trierMain(&p->joueur[p->joueurActuelle]);
    printf("\n");
    afficherJoueur(&p->joueur[J1]);
    afficherJoueur(&p->joueur[J2]);
    afficherRail(&p->rail);
    printf("\n");
    joueurSuivant(p);
}

void enleverParentheses(char* mot, char* motVide) {
    int j = 0;

    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] != '(' && mot[i] != ')') {
            motVide[j++] = mot[i];
        }
    }
    motVide[j] = '\0';
}

void extraireEntreParentheses(const char* mot, char* motParanthese) {
    int j = 0;
    int dansParentheses = 0;

    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == '(') {
            dansParentheses = 1;
        } else if (mot[i] == ')') {
            dansParentheses = 0;
        } else if (dansParentheses) {
            motParanthese[j++] = mot[i];
        }
    }

    motParanthese[j] = '\0';
}

void enleverEntreParentheses(char* mot, char* motParanthese) {
    int inParentheses = 0;
    int j = 0;

    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == '(') {
            inParentheses = 1;
        } else if (mot[i] == ')') {
            inParentheses = 0;
        } else if (!inParentheses) {
            motParanthese[j++] = mot[i];
        }
    }
    motParanthese[j] = '\0';
}

int verifTailleMot(char* motVide,char* motParanthese) {
    if (strlen(motVide)>TAILLE_MOT_VIDE)
        return 0;
    if (strlen(motParanthese)<TAILLE_INPUT)
        return 0;
    return 1;
}





void testPartie(){
    testJoueur();
    testPioche();
    testVecteur();
    testRail();
}



