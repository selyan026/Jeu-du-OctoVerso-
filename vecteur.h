#ifndef VECTOR_H
#define VECTOR_H

#include "itemvecteur.h"

enum { FACTEUR = 2 };

typedef struct{
	int taille;
	int capacite;
	ItemV* donnees;
} Vecteur;


/**
 * @brief Modifie un élément du vecteur à l'index spécifié.
 *
 * @param[in, out] v Pointeur vers le vecteur à modifier.
 * @param[in] i Index de l'élément à modifier (doit être valide).
 * @param[in] it Nouvel élément à insérer à l'index spécifié.
 *
 * @pre `i` doit être un index valide entre `0` et `taille - 1` du vecteur.
 */
int initialiserVecteur(Vecteur* v, int capacite);

/**
 * @brief Retourne la taille actuelle du vecteur.
 *
 * @param[in] v Pointeur constant vers le vecteur dont on veut connaître la taille.
 *
 * @return La taille actuelle du vecteur (nombre d'éléments stockés).
 */
int taille(const Vecteur* v);

/**
 * @brief Ajoute un élément à la fin du vecteur.Si le vecteur atteint sa capacité maximale,
 * il est redimensionné dynamiquement pour accueillir davantage d'éléments.
 *
 * @param[in, out] v Pointeur vers le vecteur auquel ajouter l'élément.
 * @param[in] it L'élément de type `ItemV` à ajouter.
 *
 * @return 1 si l'élément a été ajouté avec succès, 0 en cas d'échec (par exemple, si `realloc` échoue).
 */
int ajouterAuVecteur(Vecteur* v, ItemV it);

/**
 * @brief Récupère l'élément du vecteur à une position donnée.
 *
 * @param[in] v Pointeur constant vers le vecteur contenant l'élément.
 * @param[in] i Index de l'élément à obtenir (doit être valide).
 *
 * @return L'élément situé à l'index spécifié dans le vecteur.
 *
 * @pre 'i' doit être un index valide entre '0' et 'taille - 1' du vecteur.
 */
ItemV obtenir(const Vecteur* v, int i);

/**
 * @brief Modifie un élément du vecteur à un index donné.
 *
 * @param[in, out] v Pointeur vers le vecteur contenant l'élément à modifier.
 * @param[in] i Index de l'élément à modifier (doit être valide).
 * @param[in] it Nouvel élément de type `ItemV` à insérer à l'index spécifié.
 *
 * @pre `i` doit être un index valide entre `0` et `taille - 1` du vecteur.
 */
void modifier(Vecteur* v, int i, ItemV it);

/**
 * @brief Supprime un élément du vecteur à l'index spécifié.
 * Les éléments suivants sont décalés pour combler l'espace laissé par l'élément supprimé.
 *
 * @param[in, out] v Pointeur vers le vecteur à modifier.
 * @param[in] i Index de l'élément à supprimer (doit être valide).
 *
 * @pre `i` doit être un index valide entre `0` et `taille - 1` du vecteur.
 */
void supprimerA(Vecteur* v, int i);

/**
 * @brief Redimensionne la capacité du vecteur à une nouvelle taille.
 *
 * @param[in, out] v Pointeur vers le vecteur à redimensionner.
 * @param[in] taille Nouvelle capacité souhaitée (doit être positive).
 *
 * @pre `taille` doit être strictement positive.
 *
 * @return 1 si l'opération a réussi, 0 sinon (en cas d'échec de `realloc`).
 */
int redimensionner(Vecteur* v, int taille);

/**
 * @brief Libère la mémoire allouée au vecteur.
 *
 * @param[in, out] v Pointeur vers le vecteur à libérer.
 */
void libererVecteur(Vecteur* v);

/**
 * @brief Supprime le dernier élément du vecteur et le retourne.
 *
 * @param[in, out] v Pointeur vers le vecteur à modifier.
 *
 * @pre Le vecteur doit contenir au moins un élément.
 *
 * @return Le dernier élément supprimé du vecteur.
 */
char vecteurSupprimerFin(Vecteur* v);

/**
 * @brief Teste les fonctionnalités principales de la structure Vecteur.
 *
 * Cette fonction exécute une série de tests pour valider les opérations suivantes :
 * - Initialisation d'un vecteur.
 * - Ajout d'éléments au vecteur.
 * - Accès aux éléments du vecteur.
 * - Modification d'un élément spécifique.
 * - Suppression d'un élément à une position donnée.
 * - Redimensionnement lorsque la capacité est atteinte.
 * - Libération de la mémoire allouée.
 *
 * @pre La structure `Vecteur` et ses fonctions associées doivent être correctement implémentées.
 */
void testVecteur() ;

#endif