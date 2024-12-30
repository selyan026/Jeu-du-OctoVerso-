#include "vecteur.h"
#include <string.h>
#include <stdlib.h>

void vecteurInitialiser(Vecteur* v, size_t capaciteInitiale) {
    v->donnees = malloc(capaciteInitiale * sizeof(char));
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
    char supprime = v->donnees[index];
    memmove(&v->donnees[index], &v->donnees[index + 1], (v->taille - index - 1) * sizeof(char));
    v->taille--;
    return supprime;
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

    char supprime = v->donnees[v->taille - 1];
    v->taille--;
    v->donnees = realloc(v->donnees, --v->capacite * sizeof(char)); // Ajuster la mémoire si nécessaire
    return supprime;
}

void vecteurLiberer(Vecteur* v) {
    free(v->donnees);
    v->donnees = NULL;
    v->taille = 0;
    v->capacite = 0;
}