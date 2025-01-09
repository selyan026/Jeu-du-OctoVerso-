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
    retournerRail(r);
}

void afficherRail(Rail* rail) {
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

void retournerRail(Rail* r){
    for (int i=0,j=r->tailleRail-1;i<r->tailleRail;++i,--j){
        r->verso[i]=r->recto[j];
    }
    r->verso[r->tailleRail]='\0';
}

void testRail() {
    Rail rail;

    // Test de initRail avec deux mots de 4 lettres
    initRail(&rail, "CHAT", "LION");
    assert(rail.tailleRail == TAILLE_RAIL -1);
    assert(strcmp(rail.recto, "CHATLION") == 0);
    assert(strcmp(rail.verso, "NOILTAHC") == 0);

    initRail(&rail, "LION", "CHAT");
    assert(rail.tailleRail == TAILLE_RAIL - 1);
    assert(strcmp(rail.recto, "CHATLION") == 0);
    assert(strcmp(rail.verso, "NOILTAHC") == 0);

    // Test de retournerRail
    strcpy(rail.recto, "TESTCASE"); // Changement manuel du recto
    rail.tailleRail = TAILLE_RAIL - 1;
    retournerRail(&rail);
    assert(strcmp(rail.verso, "ESACTSET") == 0); // Verso doit être "ESACTSET"

    // Cas limites avec un mot de 4 lettres et un mot de 5 lettres
    initRail(&rail, "LUNE", "SOLEIL");
    assert(rail.tailleRail == TAILLE_RAIL - 1); // Vérifie la taille correcte
    assert(strcmp(rail.recto, "LUNESOLE") == 0); // Recto est limité par `TAILLE_RAIL`

    // Test de chaînes égales
    initRail(&rail, "CHAT", "CHAT");
    assert(rail.tailleRail == TAILLE_RAIL - 1);
    assert(strcmp(rail.recto, "CHATCHAT") == 0);
    assert(strcmp(rail.verso, "TAHCTAHC") == 0);
}