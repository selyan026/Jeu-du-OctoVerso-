#include "rail.h"


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
    retorunerRail(r);
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

void retorunerRail(Rail* r){
    for (int i=0,j=r->tailleRail-1;i<r->tailleRail;++i,--j){
        r->verso[i]=r->recto[j];
    }
    r->verso[r->tailleRail]='\0';
}