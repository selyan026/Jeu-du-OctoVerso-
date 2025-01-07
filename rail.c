#include "rail.h"


void initRail(Rail* r,const char* mot1,const char* mot2) {
    r->tailleRail=0;
    if (strcmp(mot1,mot2)<0) {
        strcpy(r->rail, mot1);
        strcat(r->rail, mot2);
        r->tailleRail=strlen(r->rail);
    }
    if (strcmp(mot1,mot2)>0) {
        strcpy(r->rail, mot2);
        strcat(r->rail, mot1);
        r->tailleRail=strlen(r->rail);
    }
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
