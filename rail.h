#ifndef RAIL_H
#define RAIL_H


#include "vecteur.h"
#include "stdio.h"
#include "string.h"

enum{TAILLE_RAIL=9};

/* *
* Représente un recto (i.e la chaine de caractère qui la compose, sa taille qui est fixe).
*/
typedef struct{
  char recto[TAILLE_RAIL];
  char verso[TAILLE_RAIL];
  int tailleRail;
}Rail;

/**
 * @brief Initialise un recto en combinant deux mots dans un ordre alphabétique.
 *
 * @param r [out] Pointeur vers la structure `Rail` à initialiser.
 * Le champ `recto` contiendra la concaténation des deux mots
 * dans l'ordre alphabétique, et le champ `tailleRail` sera mis
 * à jour pour refléter la longueur totale du recto.
 * @param mot1 [in] Premier mot à comparer et concaténer. Utilisé uniquement en lecture.
 * @param mot2 [in] Deuxième mot à comparer et concaténer. Utilisé uniquement en lecture.
 */
void initRail(Rail* r, const char* mot1, const char* mot2);

/**
 * @brief Affiche le contenu d'un recto dans deux ordres : normal et inversé.
 * @param rail [in] Pointeur vers la structure `Rail` à afficher.
 */
void afficherRail(Rail* rail);

void retorunerRail(Rail* r);


#endif //RAIL_H
