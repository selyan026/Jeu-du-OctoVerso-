#ifndef VECTEUR_H
#define VECTEUR_H

#include <stddef.h>

typedef struct {
	char* donnees;
	size_t taille;
	size_t capacite;
} Vecteur;

void vecteurInitialiser(Vecteur* v, size_t capaciteInitiale);
void vecteurAjouterFin(Vecteur* v, char element);
char vecteurSupprimerFin(Vecteur* v);
void vecteurInsererA(Vecteur* v, size_t index, char element);
void vecteurSupprimerA(Vecteur* v, size_t index);
void vecteurLiberer(Vecteur* v);
int retailler(Vecteur* v, int taille);
#endif
