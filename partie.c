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

void initRail(Partie* p,const char* mot1,const char* mot2) {
    p->rail.tailleRail=0;
    if (strcmp(mot1,mot2)==0 || strcmp(mot1,mot2)>0) {
        strcpy(p->rail.rail, mot1);
        strcat(p->rail.rail, mot2);
        p->rail.tailleRail=strlen(p->rail.rail);
    }
    if (strcmp(mot1,mot2)<0) {
            strcpy(p->rail.rail, mot2);
            strcat(p->rail.rail, mot1);
        p->rail.tailleRail=strlen(p->rail.rail);
        }
    }
void demanderMot(Partie* p,char mot[MAX_MOT]){
    do{
        printf("%d> ",p->joueurActuelle+1);
        fflush(stdout);
        scanf("%s",mot);
    }while(strlen(mot)!=MAX_MOT-1 || !verifierMotDansMain(p->joueur[p->joueurActuelle].main,mot) || !estDansDictionnaire(mot));
}

void joueurSuivant(Partie* p) {
    ++p->joueurActuelle;
    p->joueurActuelle%=2;
}





