//
// Created by antho on 08/01/2025.
//

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

// Fonction pour ajouter un mot au tableau dynamique
    void ajouterMotStockage(Stockage *t,char *mot) {
        // Vérifier les paramètres
        if (t == NULL || mot == NULL) {
            return;
        }
        // Si la capacité actuelle est atteinte, doubler la capacité
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

        // Allouer et copier le mot dans le tableau
        t->mots[t->taille++] = strdup(mot);
        if (t->mots[t->taille] == NULL) {
            perror("Erreur d'allocation mémoire pour le mot");
            exit(EXIT_FAILURE);
        }
    }

// Fonction pour libérer la mémoire allouée pour le tableau
void libererStockage(Stockage *t) {
    for (size_t i = 0; i < t->taille; i++) {
        free(t->mots[i]); // Libérer chaque mot
    }
    free(t->mots); // Libérer le tableau lui-même
    t->mots = NULL;
    t->taille = 0;
    t->capacite = 0;
}

// Fonction pour vérifier si un mot est dans le tableau
int motDansStockage(Stockage *t, const char *mot) {
    for (size_t i = 0; i < t->taille; i++) {
        if (strcmp(t->mots[i], mot) == 0) {
            return 0; // Le mot a été trouvé
        }
    }
    return 1; // Le mot n'a pas été trouvé
}