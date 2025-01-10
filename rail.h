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
void afficherRail(const Rail* rail);


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
void retournerRailVerso(Rail* r);

/**
 * @brief Génère le recto du rail en inversant l'ordre des lettres du verso.
 *
 * @param[in,out] r Pointeur vers la structure Rail dont le verso sera généré.
 *
 * @pre 'r' doit être un pointeur valide non nul.
 * @pre Le champ 'recto' de la structure 'Rail' doit contenir une chaîne de caractères
 *      null-terminée, avec sa longueur définie par le champ 'tailleRail'.
 * @pre La valeur de 'tailleRail' doit être correcte (i.e de 8).
 */
void retournerRailRecto(Rail* r);


/**
 * @brief Teste les fonctions associées à la gestion des rails
 * @pre La constante 'TAILLE_RAIL' doit être définie et cohérente avec la taille des champs
 * @pre 'recto' et 'verso' de la structure 'Rail'.
 * */
void testRail();

/**
 * @brief Vérifie si un mot est présent dans le rail, soit dans le recto, soit dans le verso.
 *
 * @param r [in] Pointeur vers la structure 'Rail' à vérifier.
 * @param mot [in] Mot original, potentiellement entouré de parenthèses, utilisé pour
 *                 déterminer où chercher ('début' ou 'fin').
 * @param motParanthese [in] Version du mot sans parenthèses à rechercher dans le rail.
 * @param input [in] Caractère déterminant la direction de la recherche :
 *                   - `'R'` pour chercher dans le recto du rail.
 *                   - `'V'` pour chercher dans le verso.
 * @return Retourne 1 si le mot est trouvé dans le rail selon les critères, 0 sinon.
 *
 * @pre 'r' doit être un pointeur valide et initialisé.
 * @pre 'mot', 'motParanthese', et 'input' doivent être des chaînes de caractères valides.
 * @pre La longueur de `motParanthese` ne doit pas dépasser la taille actuelle du rail (`r->tailleRail`).
 */
int verifMotRail(const Rail* r,const char* mot,const char* motParanthese,const char* input);


/**
 * @brief Insère un mot dans le rail rotatif tout en expulsant une partie existante.
 *
 * Cette fonction insère le mot spécifié ('motHorsParanthese') dans le recto ou le verso du rail,
 * en fonction de la direction spécifiée par 'input'. Les lettres expulsées sont stockées
 * dans le tableau 'expulse'.
 *
 * @param r [in, out] Pointeur vers la structure 'Rail' à modifier.
 * @param mot [in] Mot complet à insérer, incluant potentiellement des parenthèses.
 * @param motHorsParanthese [in] Version du mot sans parenthèses à insérer dans le rail.
 * @param input [in] Caractère déterminant la direction de l'insertion :
 *                   - `'R'` pour insérer dans le recto du rail.
 *                   - Tout autre caractère pour insérer dans le verso.
 * @param expulse [out] Tableau destiné à stocker les lettres expulsées lors de l'insertion.
 *
 * @pre 'r' doit être un pointeur valide et initialisé.
 * @pre 'mot', 'motHorsParanthese', et 'input' doivent être des chaînes de caractères valides.
 * @pre 'expulse' doit être un tableau pré-alloué capable de stocker au moins 'TAILLE_RAIL - 1' caractères.
 * @pre 'r->tailleRail' doit être cohérent avec la longueur des chaînes 'recto' et 'verso' du rail.
 */
void inserer_mots(Rail* r, const char* mot, const char* motHorsParanthese, const char* input,char* expulse);


#endif //RAIL_H
