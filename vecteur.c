#include "vecteur.h"
#include <string.h>
#include <stdlib.h>

void vecteurInitialiser(Vecteur* v, size_t capaciteInitiale) {
    v->donnees = (char*)malloc(capaciteInitiale * sizeof(char));
    v->taille = 0;
    v->capacite = capaciteInitiale;
}

void vecteurAjouterFin(Vecteur* v, char element) {
    if (v->taille == v->capacite) {
        v->capacite *= 2;
        v->donnees = realloc(v->donnees, v->capacite * sizeof(char));
    }
    v->donnees[v->taille++] = element;
}


char vecteurSupprimerA(Vecteur* v, size_t index) {
    for (++index; index < v->taille; ++index)
        v->donnees[index - 1] = v->donnees[index];
    --v->taille;
}

void vecteurInsererA(Vecteur* v, size_t index, char element) {
    if (v->taille == v->capacite) {
        v->capacite *= 2;
        v->donnees = realloc(v->donnees, v->capacite * sizeof(char));
    }
    memmove(&v->donnees[index + 1], &v->donnees[index], (v->taille - index) * sizeof(char));
    v->donnees[index] = element;
    v->taille++;
}
char vecteurSupprimerFin(Vecteur* v) {
    return v->donnees[--v->taille];
}

int retailler(Vecteur* v, int taille) {
    char* tab = (char*)realloc(v->donnees, sizeof(char) * taille);
    if (tab == NULL)
        return 0;
    v->donnees = tab;
    v->capacite = taille;
    if (v->taille > taille)
        v->taille = taille;
    return 1;
}

void vecteurLiberer(Vecteur* v) {
    free(v->donnees);
    v->donnees = NULL;
    v->taille = 0;
    v->capacite = 0;
}