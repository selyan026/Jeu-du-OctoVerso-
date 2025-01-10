#include <assert.h>
#include <stdio.h>
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

void testVecteur() {
    Vecteur v;

    // Test de l'initialisation
    assert(initialiserVecteur(&v, 5) == 1);

    // Test de l'ajout d'éléments
    assert(ajouterAuVecteur(&v, 'A') == 1);
    assert(ajouterAuVecteur(&v, 'B') == 1);
    assert(ajouterAuVecteur(&v, 'C') == 1);

    // Test d'accès aux éléments
    assert(obtenir(&v, 0) == 'A');
    assert(obtenir(&v, 1) == 'B');

    // Test de modification d'un élément
    modifier(&v, 2, 'Z'); // Remplace 'C' par 'Z'
    assert(obtenir(&v, 2) == 'Z');

    // Test de suppression d'un élément à une position donnée
    supprimerA(&v, 1); // Supprime 'B'
    assert(obtenir(&v, 1) == 'Z');

    // Test de redimensionnement automatique
    for (int i = 0; i < 5; i++) {
        assert(ajouterAuVecteur(&v, 'X') == 1);
    }
    assert(v.capacite > 5); // Vérification que la capacité a augmenté

    // Libération de la mémoire
    libererVecteur(&v);
}
