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

/**
 * @brief Initialise une structure de stockage dynamique pour l'historique des mots déjà utilisés.
 *
 * @param[in,out] t Pointeur vers la structure Stockage à initialiser.
 * @param[in] capaciteInitiale Capacité initiale du stockage (nombre maximum de mots pouvant être stockés).
 *
 * @pre 'capaciteInitiale' doit être strictement supérieur à 0.
 */
void initialiserStockage(Stockage *t, size_t capaciteInitiale) ;

/**
 * @brief Ajoute un mot à une structure de stockage dynamique qui sert d'historique.
 *
 * @param[in,out] t Pointeur vers la structure Stockage où le mot sera ajouté.
 * @param[in] mot Pointeur vers une chaîne de caractères représentant le mot à ajouter.
 *
 * @pre 't' doit être initialisé avec une capacité valide via 'initialiserStockage'.
 *      'mot' doit être une chaîne de caractères valide (non nulle et null-terminée).
 */
void ajouterMotStockage(Stockage *t,char *mot);

/**
 * @brief Libère la mémoire allouée pour une structure de stockage dynamique.
 *
 * @param[in,out] t Pointeur vers la structure Stockage à libérer.
 *
 * @pre 't' doit avoir été initialisé avec une capacité valide via 'initialiserStockage'.
 */
void libererStockage(Stockage *t);

/**
 * @brief Vérifie si un mot est présent dans une structure de stockage dynamique.
 *
 * @param[in] t Pointeur vers la structure Stockage contenant les mots à vérifier.
 * @param[in] mot Pointeur vers une chaîne de caractères représentant le mot à rechercher.
 *
 * @pre `t` doit être initialisé et contenir une liste de mots valide.
 *      `mot` doit être une chaîne de caractères valide (non nulle et null-terminée).
 *
 * @return 0 si le mot est trouvé, 1 sinon.
 *
 */
int motDansStockage(Stockage *t, const char *mot);


#endif //STOCKAGE_H
