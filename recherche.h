#ifndef RECHERCHE_H_INCLUDED
#define RECHERCHE_H_INCLUDED
#include "functions.h"
struct Maillon{
    Individu * individu;
    Individu * suivant;

};
typedef struct Maillon Maillon;


struct Liste {
    Maillon * premier;
    Maillon *dernier ;
};
typedef struct Liste Liste;

Maillon * creerMaillon(Individu * ind,Maillon *suivant);

int comparerMaillon(Maillon * m1,Maillon * m2);

Liste * trierParDate(Arbre * racine,int type);

void insererTriDate(Liste * liste,Individu * individu);


#endif // RECHERCHE_H_INCLUDED
