#ifndef VECTOR_H
#define VECTOR_H

#include "itemvecteur.h"

enum { FACTEUR = 2 };

typedef struct {
	int taille;
	int capacite;
	ItemV* donnees;
} Vecteur;

int initialiserVecteur(Vecteur* v, int capacite);
int taille(const Vecteur* v);
int ajouterAuVecteur(Vecteur* v, ItemV it);
ItemV obtenir(const Vecteur* v, int i);
void modifier(Vecteur* v, int i, ItemV it);
void supprimerA(Vecteur* v, int i);
int redimensionner(Vecteur* v, int taille);
void libererVecteur(Vecteur* v);
char vecteurSupprimerFin(Vecteur* v);

#endif