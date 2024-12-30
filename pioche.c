#include "pioche.h"
#include <time.h>
#include <stdlib.h>




void remplirChevalet(Pioche* p) {
    p->nbPioche = 0;
    char lettres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                      'U', 'V'};
    int frequences[] = {9, 1, 2, 3, 14, 1, 1, 1, 7, 1,
                        0, 5, 3, 6, 5, 2, 1, 6, 7, 6,
                        5, 2};

    for (int i = 0; i < sizeof(lettres) / sizeof(lettres[0]); i++) {
        for (int j = 0; j < frequences[i]; j++) {
            p->chevalet[p->nbPioche++] = lettres[i];
        }
    }
}

void melangerPioche(Pioche* p) {
    if (estVide(p)) return; // Pas de mélange si la pioche est vide

    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    for (int i = p->nbPioche - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = p->chevalet[i];
        p->chevalet[i] = p->chevalet[j];
        p->chevalet[j] = temp;
    }
}



char piocher(Pioche* pioche) {
    if (!estVide(pioche)) {
        return pioche->chevalet[--pioche->nbPioche];
    }
    return '\0'; // Pioche vide
}

int estVide(const Pioche* pioche) {
    return (pioche->nbPioche == 0);
}

void initPioche(Pioche* p) {
    if (estVide(p)) {
        remplirChevalet(p);
    }
    melangerPioche(p);
}
//
// Created by selyan on 26/12/2024.
//
