#ifndef PARTIE2_H_INCLUDED
#define PARTIE2_H_INCLUDED

#include "functions.h"




int calculerAge(Date * naissance,Date * actuel);
int comparer(Date * d1, Date * d2);
int comparerAgeIndividu(Individu * ind1,Individu * ind2);
int comparerNomIndividu(Individu * ind1,Individu * ind2);
ListePays chargerOrigine(char * nomFichier);
#endif // PARTIE2_H_INCLUDED
