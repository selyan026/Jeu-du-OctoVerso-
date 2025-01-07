#ifndef RAIL_H
#define RAIL_H


#include "vecteur.h"
#include "stdio.h"
#include "string.h"

enum{TAILLE_RAIL=9};

typedef struct{
  char rail[TAILLE_RAIL];
  int tailleRail;
}Rail;


void initRail(Rail* r,const char* mot1,const char* mot2);
void afficherRail(Rail* rail);

#endif //RAIL_H
