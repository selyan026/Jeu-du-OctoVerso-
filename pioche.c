#include "pioche.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void remplirChevalet(Pioche* p) {
    initialiserVecteur(&p->chevalet,LETTRETOTAL);
    p->nbPioche = 0;
    char lettres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                      'U', 'V'};
    int frequences[] = {9, 1, 2, 3, 14, 1, 1, 1, 7, 1,
                        0, 5, 3, 6, 5, 2, 1, 6, 7, 6,
                        5, 2};

    for (int i = 0; i < sizeof(lettres) / sizeof(lettres[0]); i++) {
        for (int j = 0; j < frequences[i]; j++) {
            ajouterAuVecteur(&p->chevalet, lettres[i]);
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
        int j = rand()%(i + 1);
        char temp = p->chevalet.donnees[i];
        p->chevalet.donnees[i] = p->chevalet.donnees[j];
        p->chevalet.donnees[j] = temp;
    }
}

char piocher(Pioche* pioche) {
    // Vérifie s'il reste des éléments dans la pioche
    if (pioche->nbPioche > 0) {
        // Supprime une lettre à la fin du vecteur et décrémente nbPioche
        char lettre = vecteurSupprimerFin(&pioche->chevalet);
        pioche->nbPioche--;  // Réduit le nombre de pioches disponibles
        return lettre;
    } else {
        return '\0';  // Si la pioche est vide, retourne '\0'
    }
}

void initPioche(Pioche* p) {
    remplirChevalet(p);
    melangerPioche(p);
}

void testPioche() {
    Pioche p;
    initPioche(&p);

    // Vérifie si la pioche a été correctement remplie avec le bon nombre d'éléments
    assert(p.nbPioche == LETTRETOTAL);

    // Sauvegarde de la première lettre avant mélange
    Vecteur chevaletAvantMelange = p.chevalet;

    // Mélange la pioche
    melangerPioche(&p);

    // Vérifie que le mélange a modifié au moins un élément dans le vecteur
    int changement = 0;
    for (int i = 0; i < LETTRETOTAL; i++) {
        if (chevaletAvantMelange.donnees[i] != p.chevalet.donnees[i]) {
            changement = 1;
            break;
        }
    }

    // Teste la pioche d'une lettre
    char lettrePiochee = piocher(&p);
    assert(lettrePiochee != '\0');  // Vérifie qu'une lettre valide a été piochée
    printf("%d",p.nbPioche);
    printf("%c", lettrePiochee);
    assert(p.nbPioche == LETTRETOTAL - 1);  // Vérifie que le nombre de pioches a diminué de 1

    // Teste la pioche quand la pioche est vide
    Pioche vide;
    initPioche(&vide);
    while (vide.nbPioche > 0) {
        piocher(&vide);  // Vide la pioche
    }
    assert(piocher(&vide) == '\0');  // Vérifie qu'une pioche vide retourne '\0'
}

