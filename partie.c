#include "partie.h"

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
}

void demanderMot(Partie* p,char mot[MAX_MOT]){
    do{
        printf("%d> ",p->joueurActuelle+1);
        scanf("%s",mot);
    }while(strlen(mot)!=MAX_MOT-1 || !verifierMotDansMain(p->joueur[p->joueurActuelle].main,mot) || !motDansStockage(&p->stockage,mot) || !estDansDictionnaire(mot));
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
    char input[1];
    char mot[11];
    char motParanthese[8];
    char motVide[9];
    printf("%d> ",p->joueurActuelle+1);
    scanf("%s",input);
    if (input[0]=='V') {
        do {
            scanf("%s",&mot);
            enleverParentheses(mot,motVide);
            extraireEntreParentheses(mot,motParanthese);
        }while (strlen(motVide)<9 || !motDansStockage(&p->stockage,motVide) || !estDansDictionnaire(motVide));

    }
    if (input[0]=='R') {
        do {
            scanf("%s",&mot);
            enleverParentheses(mot,motVide);
            extraireEntreParentheses(mot,motParanthese);
        }while (strlen(motVide)<9 || !motDansStockage(&p->stockage,motVide) || !estDansDictionnaire(motVide));
    }
}

void enleverParentheses(char* mot, char* motVide) {
    int j = 0; // Index pour la chaîne de sortie

    for (int i = 0; mot[i] != '\0'; i++) {
        // Si le caractère n'est pas une parenthèse ouvrante ou fermante, on l'ajoute à la sortie
        if (mot[i] != '(' && mot[i] != ')') {
            motVide[j++] = mot[i];
        }
    }

    // Terminer la chaîne de sortie avec le caractère nul
    motVide[j] = '\0';
}

void extraireEntreParentheses(const char* mot, char* motParanthese) {
    int j = 0; // Index pour la chaîne de sortie
    int dansParentheses = 0; // Indicateur si on est entre parenthèses

    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == '(') {
            // On rencontre une parenthèse ouvrante : on active l'indicateur
            dansParentheses = 1;
        } else if (mot[i] == ')') {
            // On rencontre une parenthèse fermante : on désactive l'indicateur
            dansParentheses = 0;
        } else if (dansParentheses) {
            // Si on est entre parenthèses, on copie le caractère dans la sortie
            motParanthese[j++] = mot[i];
        }
    }

    // Terminer la chaîne de sortie avec le caractère nul
    motParanthese[j] = '\0';
}

void testPartie(){
    testPioche();
    testRail();
}



