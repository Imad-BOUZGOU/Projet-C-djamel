#include "recherche.h"
#include <stdio.h>


Maillon * creerMaillon(Individu * ind,Maillon *suivant){
    Maillon * m =malloc(sizeof(Maillon));
    m->individu=ind;
    m->suivant=suivant;
    return m;

}
Liste *  TrierListe(Arbre * racine,int type){

    Liste * liste=malloc(sizeof(Liste));
    liste->premier=NULL;
    liste->dernier=NULL;

    while(racine!=NULL){
        insererTriDate(liste,racine->individu);
        racine=racine->next;
    }
    return liste;
}
Liste * triParSexe(Arbre * racine,char sexe){
    Liste * liste=malloc(sizeof(Liste));
    liste->premier=NULL;
    liste->dernier=NULL;
	while(racine!=NULL){
		insererTriSexe(liste,racine->individu,sexe);
		racine=racine->next;
	}
	return liste;

}
void insererTriSexe(Liste * liste,Individu * ind,char sexe){
	
	if(ind==NULL) return;
	if(ind->sexe==sexe) {
	 Maillon * tete=liste->premier;
    	Maillon * nouveau= creerMaillon(ind,NULL);
    	 /* Si c'est le premier element a inserer*/
    	if(tete==NULL){
        /* La tete est egale a la queue*/
        liste->premier=nouveau;
        liste->dernier=nouveau;
	 }else{
	while(tete!=liste->dernier  &&   comparerNomIndividu(tete->individu,nouveau->individu)<=   0){
	tete=tete->suivant;
	}
	if(comparerNomIndividu(tete->individu,nouveau->individu)==0){
		return ;}
	tete->suivant=nouveau;
liste->dernier=nouveau;
	}
	}
	insererTriSexe(liste,ind->pere, sexe);
        insererTriSexe(liste,ind->mere, sexe);

}



Liste * trierParDate(Arbre * racine,int type){



}

/* Insertion dans la liste de maillon en triant les elements*/
void insererTriDate(Liste * liste,Individu * individu){
   if(individu!=NULL){
     Maillon * tete=liste->premier;
     Maillon * nouveau= creerMaillon(individu,NULL);
     /* Si c'est le premier element a inserer*/
    if(tete==NULL){
        /* La tete est egale a la queue*/
        liste->premier=nouveau;
        liste->dernier=nouveau;
    /* Inserer le pere et la mere de cette individu*/
        insererTriDate(liste,individu->pere);
        insererTriDate(liste,individu->mere);
/*Quitter la procedure*/
        return ;
    }

    Maillon * precedent=liste->premier;
    /* Parcourir jusqu'a trouver la position exacte de cette individu*/
    while(tete!=liste->dernier && comparerNomIndividu(tete->individu,nouveau->individu)<=   0 ){
          precedent=tete;
          tete=tete->suivant;
    }
    /* Si l'element existe deja pas la peine de l'inserer*/
    if(comparerNomIndividu(tete->individu,nouveau->individu)==0) {
        printf("L'element existe deja ...\n");
        return ;

    }
    /* si on est arrivé a la fin de la liste*/
    if(tete==liste->dernier && precedent!=tete ){
            /* Le nouveau individu est le dernier*/
        tete->suivant=nouveau;
        liste->dernier=nouveau;
    }else{
    /* Sinon on l'insere entre deux elements*/
       if(precedent==tete) {
            liste->premier=nouveau;
            nouveau->suivant=tete;
       }else{
        precedent->suivant=nouveau;
        nouveau->suivant=tete;}
    }
    insererTriDate(liste,individu->pere);
    insererTriDate(liste,individu->mere);

   }


}


 /* Comparer deux maillon par l'age de l'individu*/
int comparerMaillon(Maillon * m1,Maillon * m2){
    return comparer(m1->individu->dateNaissance,m2->individu->dateNaissance);

}


void printListe(Liste * liste){
    Maillon *debut=liste->premier;
    while(debut!=NULL && debut!=liste->dernier){
        print(debut->individu);
        debut=debut->suivant;
    }
 /* pour afficher le dernier element de la liste*/
    if(debut!=NULL) print(debut->individu);
}
