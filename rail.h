#ifndef RAIL_H
#define RAIL_H


#include "vecteur.h"
#include "stdio.h"
#include "string.h"

enum{TAILLE_RAIL=9};

/* *
* Représente un rail (i.e la chaine de caractère qui la compose, sa taille qui est fixe).
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
 * Le champ 'recto' contiendra la concaténation des deux mots
 * dans l'ordre alphabétique, et le champ `tailleRail` sera mis
 * à jour pour refléter la longueur totale du recto.
 * @param mot1 [in] Premier mot à comparer et concaténer. Utilisé uniquement en lecture.
 * @param mot2 [in] Deuxième mot à comparer et concaténer. Utilisé uniquement en lecture.
 *
 * @pre 'r' doit être un pointeur valide non nul.
 * @pre 'mot1' et 'mot2' doivent être des chaînes de caractères null-terminées.
 * @pre La longueur totale de 'mot1' + 'mot2' ne doit pas excéder 'TAILLE_RAIL - 1' (i.e., 8 caractères).
 */
void initRail(Rail* r, const char* mot1, const char* mot2);

/**
 * @brief Affiche le contenu d'un recto dans deux ordres : normal et inversé.
 *
 * @param rail [in] Pointeur vers la structure 'Rail' à afficher.
 *
 * @pre 'rail' doit être un pointeur valide non nul.
 * @pre 'rail->tailleRail' doit être correcte et ne pas dépasser 'TAILLE_RAIL - 1'.
 * @pre Les champs 'recto' et 'verso' de 'rail' doivent être correctement initialisés.
 */
void afficherRail(Rail* rail);


/**
 * @brief Génère le verso du rail en inversant l'ordre des lettres du recto.
 *
 * @param[in,out] r Pointeur vers la structure Rail dont le verso sera généré.
 *
 * @pre 'r' doit être un pointeur valide non nul.
 * @pre Le champ 'recto' de la structure 'Rail' doit contenir une chaîne de caractères
 *      null-terminée, avec sa longueur définie par le champ 'tailleRail'.
 * @pre La valeur de 'tailleRail' doit être correcte (i.e de 8).
 */
void retournerRail(Rail* r);

/**
 * @brief Teste les fonctions associées à la gestion des rails
 * @pre La constante 'TAILLE_RAIL' doit être définie et cohérente avec la taille des champs
 * @pre 'recto' et 'verso' de la structure 'Rail'.
 * */
void testRail();

int verifMotRail(Rail* r,char* mot,char* motParanthese,char* input);
#endif //RAIL_H
