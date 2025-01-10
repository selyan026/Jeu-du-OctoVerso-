#include "partie.h"

int main(){
    char mot1[MAX_MOT];
    char mot2[MAX_MOT];
    Partie p;
    initialiserStockage(&p.stockage,1);
    initialiserPartie(&p);
    testPartie();
    demanderMot(&p,mot1);
    ajouterMotStockage(&p.stockage,mot1);
    supprimerLettre(&p.joueur[p.joueurActuelle],mot1);
    joueurSuivant(&p);
    demanderMot(&p,mot2);
    ajouterMotStockage(&p.stockage,mot2);
    supprimerLettre(&p.joueur[p.joueurActuelle],mot2);
    initRail(&p.rail,mot1,mot2);
    afficherRail(&p.rail);
    afficherJoueur(&p.joueur[J1]);
    afficherJoueur(&p.joueur[J2]);
    savoirQuiJoue(&p,mot1,mot2);
    tourDeJeu(&p);
    afficherRail(&p.rail);
    return 0;
}