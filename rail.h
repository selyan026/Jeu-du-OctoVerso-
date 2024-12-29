#ifndef RAIL_H
#define RAIL_H

#include "partie.h"

enum{TAILLE_RAIL=8};

typedef struct{
  char rail[TAILLE_RAIL];
  int tailleRail;
}Rail;

#endif //RAIL_H
