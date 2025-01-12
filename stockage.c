

#include "stockage.h"

#include <assert.h>

void initialiserStockage(Stockage *t, size_t capaciteInitiale) {
    assert(capaciteInitiale > 0);
    t->capacite = capaciteInitiale;
    t->taille = 0;
    t->mots = (char**)malloc(sizeof(char*) * capaciteInitiale);
    if (t->mots == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
}


    void ajouterMotStockage(Stockage *t,char *mot) {

        if (t == NULL || mot == NULL) {
            return;
        }

        if (t->taille >= t->capacite) {
            size_t nouvelleCapacite = t->capacite * 2;  // Doubler la capacité
            char **nouveauTableau = realloc(t->mots, nouvelleCapacite * sizeof(char *));
            if (nouveauTableau == NULL) {
                perror("Erreur de réallocation mémoire");
                exit(EXIT_FAILURE);
            }
            t->mots = nouveauTableau;
            t->capacite = nouvelleCapacite;
        }


        t->mots[t->taille++] = strdup(mot);
        if (t->mots[t->taille] == NULL) {
            perror("Erreur d'allocation mémoire pour le mot");
            exit(EXIT_FAILURE);
        }
    }


void libererStockage(Stockage *t) {
    for (size_t i = 0; i < t->taille; i++) {
        free(t->mots[i]);
    }
    free(t->mots);
    t->mots = NULL;
    t->taille = 0;
    t->capacite = 0;
}


int motDansStockage(Stockage *t, const char *mot) {
    for (size_t i = 0; i < t->taille; i++) {
        if (strcmp(t->mots[i], mot) == 0) {
            return 0;
        }
    }
    return 1;
}