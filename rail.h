#ifndef RAIL_H
#define RAIL_H


#include "vecteur.h"
#include "stdio.h"
#include "string.h"

enum{TAILLE_RAIL=8,MAX_MOT=5};

typedef struct{
  char rail[TAILLE_RAIL];
  int tailleRail;
}Rail;

int verifierMotDansMain(Vecteur main, const char* mot);


#endif //RAIL_H
