#include "pioche.h"
#include <time.h>
#include <stdlib.h>




void remplirChevalet(Pioche* p) {
    vecteurInitialiser(&p->chevalet,LETTRETOTAL);
    p->nbPioche = 0;
    char lettres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                      'U', 'V'};
    int frequences[] = {9, 1, 2, 3, 14, 1, 1, 1, 7, 1,
                        0, 5, 3, 6, 5, 2, 1, 6, 7, 6,
                        5, 2};

    for (int i = 0; i < sizeof(lettres) / sizeof(lettres[0]); i++) {
        for (int j = 0; j < frequences[i]; j++) {
            vecteurAjouterFin(&p->chevalet, lettres[i]);
            ++p->nbPioche;
        }
    }
}

void melangerPioche(Pioche* p) {
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    for (int i = p->nbPioche - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = p->chevalet.donnees[i];
        p->chevalet.donnees[i] = p->chevalet.donnees[j];
        p->chevalet.donnees[j] = temp;
    }
}

char piocher(Pioche* pioche) {
    return vecteurSupprimerFin(&pioche->chevalet);
}

void initPioche(Pioche* p) {
    remplirChevalet(p);
    melangerPioche(p);
}

