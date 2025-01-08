//
// Created by antho on 08/01/2025.
//

#ifndef STOCKAGE_H
#define STOCKAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure pour le tableau dynamique
typedef struct {
    char **mots;       // Tableau de chaînes de caractères
    size_t taille;     // Nombre actuel de mots dans le tableau
    size_t capacite;   // Capacité maximale du tableau
} Stockage;

void initialiserStockage(Stockage *t, size_t capaciteInitiale);
void ajouterMotStockage(Stockage *t,char *mot);
void libererStockage(Stockage *t);
int motDansStockage(Stockage *t, const char *mot);
#endif //STOCKAGE_H
