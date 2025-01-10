#ifndef JOUEUR_H
#define JOUEUR_H

#include "pioche.h"
#include "vecteur.h"



enum{J1=0,J2=1};

/* *
* Représente un joueur (i.e son identifiant, sa main, le nombre de chevalets qu'il lui reste).
*/
typedef struct{
    int idJoueur;
    Vecteur main;
    int tailleMain;
}Joueur;

/**
 * @brief Rempli la main d'un joueur.
 *
 * @param[in] joueur Adresse du joueur dont le deck va être remplis.
 * @param[in] p Adresse de la pioche qui va être retirée les cartes.
 * @param[in] id L'id du joueur auquel on va remplir sa main.
 *
 * @pre Le pointeur 'joueur' doit être non nul.
 * @pre La pioche 'p' doit être initialisée et contenir suffisamment de lettres pour remplir la main du joueur.
 *
 * @sa Fonction char pioche
 */
void remplirJoueur(Joueur* joueur,Pioche* p,int id);

/**
 * @brief Permet d'afficher un joueur avec sa main et son id.
 *
 * @param[in] joueur Adresse du joueur dont les informations vont être affichés.
 *
 * @pre Le pointeur 'joueur' doit être non nul.
 * @pre La main du joueur doit être initialisée.
 *
 * @sa Structure Joueur
 */
void afficherJoueur(const Joueur* joueur);

/**
 * @brief Trie dans l'ordre alphabétique la main d'un joueur.
 *
 * @param[in] j Adresse du joueur dont la main doit être triée.
 *
 * @pre Le pointeur 'j' doit être non nul,
 * @pre La main du joueur doit être initialisée et contenir des lettres valides.
 */
void trierMain(Joueur* j);

/**
 * @brief Vérifie si un mot est composé des lettres disponibles dans une main donnée.
 *
 * @param main [in] Le vecteur représentant la main contenant les lettres disponibles.
 * Chaque élément du vecteur correspond à une lettre (type 'char').
 * @param mot [in] Le mot à vérifier (chaîne de caractères).
 *
 * @pre La main doit être initialisée et contenir des lettres valides.
 * @pre La chaîne 'mot' doit être non nulle et terminée par un caractère nul.
 *
 * @return  1 si le mot peut être formé à partir des lettres de la main. 0 si le mot ne peut pas être formé.
 */
int verifierLettresDansMain(const Vecteur main, const char* mot);

/**
 * @brief Supprime les lettres d'un mot de la main d'un joueur.
 *
 * @param joueur [in, out] Pointeur vers le joueur dont la main doit être modifiée.
 * La main du joueur est mise à jour en supprimant les lettres
 * du mot et en ajustant sa taille.
 * @param mot [in] Le mot contenant les lettres à supprimer de la main du joueur.
 *
 * @pre Le pointeur 'joueur' doit être non nul, et la main du joueur doit être initialisée
 * avec des lettres valides.
 * @pre La chaîne 'mot' doit être non nulle et terminée par un caractère nul.
 */
void supprimerLettre(Joueur *joueur, const char *mot);

/**
 * @brief Ajoute une lettre à la main d'un joueur.
 *
 * @param[in, out] j Pointeur vers le joueur dont la main doit être modifiée.
 * @param[in] expulse Lettre à ajouter à la main du joueur.
 *
 * @pre Le pointeur 'j' doit être non nul et la main du joueur doit être initialisée.
 */
void donnerLettres(Joueur* j,char expulse);


/**
 * @brief Teste les fonctions associées à la structure 'Joueur' pour vérifier leur bon fonctionnement.
 *
 * Cette fonction réalise une série de tests unitaires à l'aide d'assertions sur les fonctions suivantes :
 * - 'remplirJoueur'
 * - 'afficherJoueur'
 * - 'verifierLettresDansMain'
 * - 'supprimerLettre'
 * - 'donnerLettres'
 *
 * @pre Aucune précondition particulière.
 *
 * @sa 'remplirJoueur', 'afficherJoueur', 'verifierLettresDansMain', 'supprimerLettre', 'donnerLettres'
 */
void testJoueur();


#endif //JOUEUR_H
