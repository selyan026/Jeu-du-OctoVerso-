#ifndef PIOCHE_H
#define PIOCHE_H

#include "vecteur.h"

enum {
    LETTREJOUEUR=12, // Nombre de chevalets contenu par un joueur au début de la partie
    LETTRETOTAL=88// Nombre de chevalets dans le jeu au total
    };

/* *
* Représente une pioche (i.e les chevalets qui la composent ainsi que leur nombre).
*/
typedef struct{
    Vecteur chevalet;
    int nbPioche;
}Pioche;

/**
 * @brief Remplit une pioche de chevalet avec leurs fréquences correspondantes.
 *
 * @param[in] p Adresse de la Pioche qui doit être remplie.
 *
 * @pre
 *      'p != NULL' : Le pointeur de la pioche ne doit pas être nul.
 *      'p->chevalet' doit être correctement initialisé.
 *      'LETTRETOTAL' doit être défini et supérieur à zéro.
 */
void remplirChevalet(Pioche* p);

/**
 * @brief Mélange une pioche remplie de chevalet.
 *
 * @param[out] p Adresse de la Pioche qui doit être mélangée.
 *
 * @pre
 *      'p != NULL' : Le pointeur de la pioche ne doit pas être nul.
 *      'p->chevalet' doit être initialisé.
 *      'p->nbPioche > 0' : La pioche doit contenir au moins un élément.
 *      Les données dans 'p->chevalet.donnees' doivent être valides.
 */
void melangerPioche(Pioche* p);


/**
 * @brief Permet de piocher une lettre de la pioche. Réduit la taille de la pioche de 1 après l'extraction.
 *
 * @param[in] pioche Adresse de la pioche dont on va extraire une lettre.
 *
 * @pre
 *      'pioche != NULL' : Le pointeur de la pioche ne doit pas être nul.
 *      'pioche->chevalet' doit être initialisé.
 *      'pioche->nbPioche > 0' : La pioche ne doit pas être vide.
 *       La fonction `vecteurSupprimerFin` doit être définie et retourner un caractère valide.
 *
 * @return Retourne la lettre piochée ou '\0' si la pioche est vide.
 */
char piocher(Pioche* pioche);

/**
 * @brief Permet d'initialiser une pioche (i.e la remplit de chevalet et la mélange).
 *
 * @param[in] p Adresse de la Pioche à initialiser.
 *
 * @pre
 *      'p->chevalet' doit être initialisé et prêt à recevoir des éléments.
 *      'LETTRETOTAL' doit être défini et valide.
 *
 * @sa Fonction remplirChevalet et melangerPioche.
 */
void initPioche(Pioche* p);

/**
 * @brief Fonction de test pour les fonctions de gestion de la pioche.
 *
 * Cette fonction teste les opérations sur la pioche : initialisation,
 * mélange et pioche de lettres. Elle vérifie également les préconditions et le comportement
 * attendu lors de la pioche et du mélange.
 */
void TestPioche(Pioche* p);

#endif //PIOCHE_H
