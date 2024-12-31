#include "partie.h"

int main(){
    char mot1[MAX_MOT];
    char mot2[MAX_MOT];
    Partie p;
    initialiserPartie(&p);
    demanderMot(&p,mot1);
    printf("ca marche");
    return 0;
}