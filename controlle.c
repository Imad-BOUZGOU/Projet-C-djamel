#include "functions.h"
#include "stdio.h"
/**
 ascendance(prenom) :
  donne le nombre de générations dans l’arbre dont
  est issu l’individu prenom (lui ne compte pas)
**/
int ascendance(Arbre * arbre,Individu * individu){
    if(individu==NULL) {
        return -1;
    }else{
        int ascPere=0,ascMere=0;
        ascPere=ascendance(arbre,individu->pere);
        ascMere=ascendance(arbre,individu->mere);
        return 1+(ascMere<ascPere? ascPere:ascMere);

    }

}
/**
 taille_arbre() : donne le nombre de générations max contenu dans l’arbre
**/
int tailleArbre(Arbre * racine){
    int taille=0;
    int maxTaille=-1;
    Arbre * actuel=racine;
    while(actuel!=NULL && actuel->individu!=NULL){
        taille=ascendance(racine,actuel->individu);
        if(taille>maxTaille) maxTaille=taille;
    actuel=actuel->next;
    }
    return maxTaille+1;
}
/**
 recense_genre(sexe) : donne le nom de tous les individus de sexe sexe
**/

int recenser(Arbre * racine,char * genre){
    int nombre=0;
    Arbre * actuel=racine;
    while(actuel!=NULL && actuel->individu!=NULL){
        actuel=actuel->next;
    }
    return nombre;
}



/**
 lien(prenom1,prenom2) : indique si les individus prenom1 et prenom2 ont un lien de parenté.
**/
int lienParente(Individu * ind1,Individu *ind2){
    if(ind1!=NULL){
        if(lienDirecte( ind1,ind2 )) return 1;
        else
            return lienParente(ind1->mere,ind2) || lienParente(ind1->pere,ind2);
    }else{
    return 0;

    }
}
int lienDirecte(Individu * ascendant, Individu * descendant){
    if(descendant!=NULL){
        // Voir si le
        // premier individu est le pere de deuxieme
        printf("individu %s avec %s\n",ascendant->prenom,descendant->prenom);
        if(descendant->pere==ascendant || descendant->mere==ascendant ) return 1;
        // Sinon Voir s'il est11 le pere d'un de ses peres
        return lienDirecte(ascendant,descendant->pere) || lienDirecte(ascendant,descendant->mere);

    }
    return 0;

}



/**
del(prenom) : supprime de l'arbre l'individu prénom. Si prenom a des enfants,
 leur lien parent en question doit être mis à NULL. Si prenom a un ou des parents
 qui du fait de la suppression ne seraient plus reliés à l'arbre, la suppression de prenom doit être empêchée.
**/

int supprimer(Arbre * arbre,Individu * ind){


}

int nombreFils(Arbre * arbre,Individu * ind){
    return 1;
}

Arbre * TriParAge(Arbre * arbre){
    Arbre * arbreTrie=malloc(sizeof(Arbre));
    arbreTrie->individu=NULL;
    arbreTrie->next=NULL;
    while(arbre!=NULL && arbre->individu!=NULL){

    }
}


