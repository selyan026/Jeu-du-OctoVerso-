#include "rail.h"
#include <assert.h>


void initRail(Rail* r,const char* mot1,const char* mot2) {
    r->tailleRail=0;
    if (strcmp(mot1,mot2)<0) {
        strcpy(r->recto, mot1);
        strcat(r->recto, mot2);
        r->tailleRail=strlen(r->recto);
    }
    if (strcmp(mot1,mot2)>0) {
        strcpy(r->recto, mot2);
        strcat(r->recto, mot1);
        r->tailleRail=strlen(r->recto);
    }
    retournerRailVerso(r);
}

void afficherRail(const Rail* rail) {
    printf("r> ");
    for (int i=0;i< rail->tailleRail;++i) {
        printf("%c",rail->recto[i]);
    }
    printf("\n");
    printf("v> ");
    for (int i=0;i< rail->tailleRail;++i) {
        printf("%c",rail->verso[i]);
    }
    printf("\n");
}

void retournerRailVerso(Rail* r){
    for (int i=0,j=r->tailleRail-1;i<r->tailleRail;++i,--j){
        r->verso[i]=r->recto[j];
    }
    r->verso[r->tailleRail]='\0';
}
void retournerRailRecto(Rail* r){
    for (int i=0,j=r->tailleRail-1;i<r->tailleRail;++i,--j){
        r->recto[i]=r->verso[j];
    }
    r->recto[r->tailleRail]='\0';
}


int verifMotRail(const Rail* r,const char* mot,const char* motParanthese,const char* input) {
    int trouve=0;
    if (input[0]=='V') {
        if (mot[0]=='(') {
            for (int i=r->tailleRail-1,j=strlen(motParanthese)-1; j>=0; i--,j--) {
                if (r->verso[i]==motParanthese[j]) {
                    trouve=1;
                }
                else {
                    trouve=0;
                    break;
                }
            }
        }
        else {
            for (int i=0; i<strlen(motParanthese); i++) {
                if (r->verso[i]==motParanthese[i]) {
                    trouve=1;
                }
                else {
                    trouve=0;
                    break;
                }
            }
        }
    }
    if (input[0]=='R') {
        if (mot[0]=='(') {
            for (int i=r->tailleRail-1,j=strlen(motParanthese)-1; j>=0; i--,j--) {
                if (r->recto[i]==motParanthese[j]) {
                    trouve=1;
                }
                else {
                    trouve=0;
                    break;
                }
            }
        }
        else {
            for (int i=0; i<strlen(motParanthese); i++) {
                if (r->recto[i]==motParanthese[i]) {
                    trouve=1;
                }
                else {
                    trouve=0;
                    break;
                }
            }
        }
    }
    return trouve;
}

void inserer_mots(Rail* r, const char* mot, const char* motHorsParanthese, const char* input,char* expulse) {
    int len_mot = strlen(motHorsParanthese);
    char tmp[r->tailleRail-len_mot+1];
    char nouveauRail[9];
    if (input[0]=='R') {
        if (mot[0]=='(') {
            for (int i=len_mot,j=0;i<r->tailleRail;++i,++j) {
                tmp[j]=r->recto[i];
            }
            tmp[r->tailleRail-len_mot+1]='\0';
            strcpy(nouveauRail,tmp);
            for (int i=0;i<len_mot;++i) {
                expulse[i]=r->recto[i];
            }
            for (int i=strlen(tmp),j=0;i<r->tailleRail;++i,++j)
                nouveauRail[i]=motHorsParanthese[j];
            for (int i=0; i<r->tailleRail;++i) {
                r->recto[i]=nouveauRail[i];
            }
        }
        else {
            for (int i=0;i<r->tailleRail-len_mot;++i) {
                tmp[i]=r->recto[i];
            }
            tmp[r->tailleRail-len_mot]='\0';
            strcpy(nouveauRail,motHorsParanthese);
            for (int i=r->tailleRail-len_mot,j=0;i<r->tailleRail;++i,++j) {
                expulse[j]=r->recto[i];
            }
            for (int i=len_mot,j=0;i<r->tailleRail;++i,++j)
                nouveauRail[i]=tmp[j];
            for (int i=0; i<r->tailleRail;++i) {
                r->recto[i]=nouveauRail[i];
            }
        }
        retournerRailVerso(r);
    }
    else {
        if (mot[0]=='(') {
            for (int i=len_mot,j=0;i<r->tailleRail;++i,++j) {
                tmp[j]=r->verso[i];
            }
            tmp[r->tailleRail-len_mot+1]='\0';
            strcpy(nouveauRail,tmp);
            for (int i=0;i<len_mot;++i) {
                expulse[i]=r->verso[i];
            }
            for (int i=strlen(tmp),j=0;i<r->tailleRail;++i,++j)
                nouveauRail[i]=motHorsParanthese[j];
            for (int i=0; i<r->tailleRail;++i) {
                r->verso[i]=nouveauRail[i];
            }
        }
        else {
            for (int i=0;i<r->tailleRail-len_mot;++i) {
                tmp[i]=r->verso[i];
            }
            tmp[r->tailleRail-len_mot]='\0';
            strcpy(nouveauRail,motHorsParanthese);
            for (int i=r->tailleRail-len_mot,j=0;i<r->tailleRail;++i,++j) {
                expulse[j]=r->verso[i];
            }
            for (int i=len_mot,j=0;i<r->tailleRail;++i,++j)
                nouveauRail[i]=tmp[j];
            for (int i=0; i<r->tailleRail;++i) {
                r->verso[i]=nouveauRail[i];
            }
        }
        retournerRailRecto(r);
    }
}


void testRail() {
    Rail rail;
    char expulse[TAILLE_RAIL];
    char motParanthese[5];
    char input[2];

    // Test de initRail avec deux mots de 4 lettres
    initRail(&rail, "CHAT", "LION");
    assert(rail.tailleRail == TAILLE_RAIL - 1);
    assert(strcmp(rail.recto, "CHATLION") == 0);
    assert(strcmp(rail.verso, "NOILTAHC") == 0);

    initRail(&rail, "LION", "CHAT");
    assert(rail.tailleRail == TAILLE_RAIL - 1);
    assert(strcmp(rail.recto, "CHATLION") == 0);
    assert(strcmp(rail.verso, "NOILTAHC") == 0);

    // Test de retournerRail
    strcpy(rail.recto, "TESTCASE"); // Changement manuel du recto
    rail.tailleRail = TAILLE_RAIL - 1;
    retournerRailVerso(&rail);
    assert(strcmp(rail.verso, "ESACTSET") == 0); // Verso doit être "ESACTSET"

    // Test de inserer_mots : Ajout d'un mot sans parenthèses dans le recto
    strcpy(input, "R");
    inserer_mots(&rail, "CHAT", "CHAT", input, expulse);
    assert(strcmp(rail.recto, "ESTSECHA") == 0);
    assert(strcmp(expulse, "TEST") == 0); // Les lettres "TEST" ont été expulsées

    // Test de inserer_mots : Ajout d'un mot avec parenthèses dans le verso
    strcpy(input, "V");
    inserer_mots(&rail, "(CHAT)", "CHAT", input, expulse);
    assert(strcmp(rail.verso, "SETCHAES") == 0);
    assert(strcmp(expulse, "TEST") == 0); // Les lettres "TEST" ont été expulsées

    // Test de verifMotRail : Vérification au début du recto
    strcpy(motParanthese, "CHA");
    assert(verifMotRail(&rail, "CHAT", motParanthese, "R") == 1);

    // Test de verifMotRail : Vérification à la fin du verso
    strcpy(motParanthese, "ES");
    assert(verifMotRail(&rail, "(CHAT)", motParanthese, "V") == 1);

    // Test de verifMotRail : Vérification d'un mot non présent
    strcpy(motParanthese, "DOG");
    assert(verifMotRail(&rail, "DOG", motParanthese, "R") == 0);

    printf("Tous les tests pour Rail ont réussi !\n");
}
