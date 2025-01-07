#include <assert.h>
#include <stdlib.h>
#include "vecteur.h"

int initialiserVecteur(Vecteur* v, int capacite) {
    assert(capacite > 0);
    v->capacite = capacite;
    v->taille = 0;
    v->donnees = (ItemV*)malloc(sizeof(ItemV) * capacite);
    return v->donnees != NULL;
}

int taille(const Vecteur* v) {
    return v->taille;
}

int ajouterAuVecteur(Vecteur* v, ItemV it) {
    if (v->taille == v->capacite) {
        ItemV* tab = (ItemV*)realloc(v->donnees, sizeof(ItemV) * v->capacite * FACTEUR);
        if (tab == NULL)
            return 0;
        v->capacite *= FACTEUR;
        v->donnees = tab;
    }
    v->donnees[v->taille++] = it;
    return 1;
}

ItemV obtenir(const Vecteur* v, int i) {
    assert(i >= 0 && i < v->taille);
    return v->donnees[i];
}

void modifier(Vecteur* v, int i, ItemV it) {
    assert(i >= 0 && i < v->taille);
    v->donnees[i] = it;
}

void supprimerA(Vecteur* v, int i) {
    assert(i >= 0 && i < v->taille);
    for (++i; i < v->taille; ++i)
        v->donnees[i - 1] = v->donnees[i];
    --v->taille;
}

int redimensionner(Vecteur* v, int taille) {
    assert(taille > 0);
    ItemV* tab = (ItemV*)realloc(v->donnees, sizeof(ItemV) * taille);
    if (tab == NULL)
        return 0;
    v->donnees = tab;
    v->capacite = taille;
    if (v->taille > taille)
        v->taille = taille;
    return 1;
}

void libererVecteur(Vecteur* v) {
    free(v->donnees);
}

char vecteurSupprimerFin(Vecteur* v) {
    return v->donnees[--v->taille];
}