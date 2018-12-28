#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "partie2.h"



Arbre* load(char* fileName){
        char line[100];
        FILE* fichier=NULL;
        char *prenom,*sexe,*infos,*dates,*pere,*mere,*dateNaissance,*dateDeces;
        Arbre *racine=NULL;


        fichier=fopen(fileName,"r");/*ouvrir le fichier*/


         if (fichier)
           {

           /* on mit tout les individus dans la liste*/
            while(fgets(line,100,fichier)!=NULL)/*on teste et on récupère la ligne en mème temp.
           */ {

                line[strlen(line)-1]='\0';/* delete '\n'*/

                prenom=strtok (line, ":");
		infos=strtok(NULL,"!");
		dates=strtok(NULL,"!");
	        sexe=strtok (infos, ",");
                pere=strtok (NULL, ",");
                mere=strtok (NULL, ",");
                dateNaissance=strtok (dates, "-");
                dateDeces=strtok (NULL, "-");
                New(racine,prenom,sexe,pere,mere,dateNaissance,dateDeces);

            }




    }else printf("Ce fichier n'existe pas !");




            fclose(fichier);
            return racine;


}






int save(char* fileName,Arbre *racine){
        Arbre *pere;
        Arbre *mere;
        FILE* fichier=NULL;
        fichier=fopen(fileName,"w");
        if(fichier==NULL) return -1;
        while(racine!=NULL){
            ecrireDansFichier(racine->individu,fichier);
            racine=racine->next;
        }

    return 0;
}

void ecrireDansFichier(Individu *individu,FILE *fichier){
    if(individu!=NULL){
        printf("kayen ");
        char * mere = malloc(30);
        char * pere = malloc(30);
        mere= individu->mere ==NULL ? "" : individu->mere;
        pere= individu->pere ==NULL ? "" : individu->pere;
        fprintf(fichier,"%s:%s%,%s,%s!%s-%s\n",individu->prenom,individu->sexe,pere,mere,dateNaissance(individu),dateDeces(individu));
        ecrireDansFichier(pere,fichier);
        ecrireDansFichier(mere,fichier);
    }
}



Individu* findMother(char *name,Arbre *arbre){

    Individu *result=NULL;
    Individu *personne;
  /** on parcourt les racines **/
    while(arbre&&!result){
        personne=&(arbre->individu);

      /** on parcourt les noeuds de chaque racine**/
        while(!result&&personne){
                if(personne->sexe=='f'&&strcmp(personne->prenom,name)) result=personne;
                else personne=personne->mere;

        }
        arbre=arbre->next;

    }

    return result;

}







/******* isMother ********/

int putChild(Arbre* arbre,Individu *personne){

    Individu *noeud;

    int parent=0;
  /** on parcourt les racines **/
    while(arbre){
      noeud=arbre->individu;
      /** on parcourt les noeuds de chaque racine**/
      if(personne->sexe=='f')       parent+=isMother(noeud,personne);
      else                        parent+=isFather(noeud,personne);

        arbre=arbre->next;

    }

    return parent;
}

int isMother(Individu *noeud,Individu *personne){

    if(noeud){

        if(!strcmp(personne->prenom,noeud->prenomMere)){
                noeud->mere=personne;
                return 1;

        }else{

           return isMother(noeud->mere,personne) || isMother(noeud->pere,personne);



        }

    }else return 0;


}


int isFather(Individu *noeud,Individu *personne){

    if(noeud){

        if(!strcmp(personne->prenom,noeud->prenomPere)){
                noeud->pere=personne;
                return 1;

        }else{

           return isFather(noeud->mere,personne)|| isFather(noeud->pere,personne);



        }

    }else return 0;


}


int  New(Arbre* racine,char* prenom,char* sexe,char* pere,char* mere,char* dateNaissance,char * dateDeces){



        if(sexe[0]!='m' && sexe[0]!='f')
    {
        printf("Sexe invalide ...\n");
        return -1;
    }
    Individu  * elementMere=findIndividu(mere,racine);
    Individu * elementPere=findIndividu(pere,racine);
    if(pere!=NULL && !elementPere ) {
            printf("Pere existe pas...\n");
        return -1;
    }
            if(mere!=NULL && !elementMere ) {
            printf("Mere existe pas...\n");
        return -1;
    }

    Individu *personne=nouvellePersonne(prenom,sexe[0],elementPere,elementMere,dateNaissance,dateDeces);
     if(dateNaissance!=NULL){
            personne->dateNaissance=nouvelleDate(dateNaissance);

    }
    if(strcmp(dateDeces,"0")){
            personne->dateDeces=nouvelleDate(dateDeces);

    }else personne->dateDeces=NULL;
    ajouterDansListe(racine,personne);
    retirerDepuisListe(racine,elementMere);
    retirerDepuisListe(racine,elementPere);





    }






void printArbre(Arbre *racine)
{

    Individu *noeud;
    Arbre *liste;
    liste=racine;


  /** on parcourt les racines **/
    while(liste!=NULL){
      noeud=liste->individu;
      /** on parcourt les noeuds de chaque racine**/

        print(noeud);

        liste=liste->next;

    }

}

void print(Individu* pPersonne){
    Individu *pere=NULL,*mere=NULL;
    Individu* personne=pPersonne;


    if(personne!=NULL) {
               printf("\n%s: %c , ",personne->prenom,personne->sexe);
               if(personne->pere!=NULL){
                pere=personne->pere;
                printf("%s , ",personne->pere->prenom);
               }
               else printf(" , ");
                if(personne->mere!=NULL) {
                        printf("%s  ",personne->mere->prenom);
                        mere=personne->mere;
                }else printf(" , ");
                if(personne->dateNaissance!=NULL) printDate(personne,0);
                if(estDecede(personne)) printDate(personne,1);
                else printf(" -Encore en vie.");
     personne=NULL;
    }


}


Individu* findIndividu(char *name,Arbre *arbre){

    Individu *result=NULL;

    Individu *personne;
  /** on parcourt les racines **/
    while(arbre!=NULL  && result==NULL && arbre->individu!=NULL){
        personne=arbre->individu;
      /** on parcourt les noeuds de chaque racine**/
                  parcoursRacine(name,personne,&result);


          arbre=arbre->next;


    }


    return result;

}



void parcoursRacine(char *name,Individu* racine,Individu** result){

    if(racine!=NULL && name!=NULL){

        printf("Nom actuel %s\n",racine->prenom);
        if(!strcasecmp(racine->prenom,name)) *result=racine;


        else{
                parcoursRacine(name,racine->pere,result) ;
                 parcoursRacine(name,racine->mere,result);
                 }

    }


       }



/******************************************************/
/******************************************************/

Individu* info(char* prenom,Arbre* racine) {

    Individu* personne=findIndividu(prenom,racine);

    if(personne!=NULL) return personne;
    else return NULL;




}

Individu * nouvellePersonne(char *prenom,char sexe,Individu *mere,Individu * pere,char * dateNaissance,char * dateDeces){

    Individu * nouveau=malloc(sizeof(Individu));
    nouveau->sexe=sexe;
    nouveau->mere=mere;
    nouveau->pere=pere;
    nouveau->prenom=malloc(strlen(prenom)+1); strcpy(nouveau->prenom,prenom);
    nouveau->dateDeces=dateDeces;
    nouveau->dateNaissance=dateNaissance;
    nouveau->origines=malloc(30*sizeof(char));
    nouveau->naissance=malloc(30*sizeof(char));
    return nouveau;

}

/*
Supprimer un individu de haut de la liste en cas ou il aura des fils

 donc on le fera remonté dans l'arbre

 */
void supprimerIndividu(Arbre * arbre,char *prenom){

        while(arbre->individu!=NULL){
            if(strcasecmp(arbre->individu->prenom,prenom)){
                    if(arbre->next!=NULL){
                        arbre->next=arbre->next->next;
                    }else{
                        arbre->next=NULL;
                    }
                return;

            }
            arbre=arbre->next;
        }

}
Arbre * creerNoeud(Individu * individu,Arbre * suivant){
    Arbre * noeud=malloc(sizeof(Arbre));
    noeud->individu=individu;
    noeud->next=suivant;
    return noeud;
}

void ajouterDansListe(Arbre * racine,Individu * nouveau){
    if(racine->individu==NULL){
            racine->individu=nouveau;
            racine->next=NULL;
    }
    else{
        Arbre * liste= racine;
        while(liste->next!=NULL) {

                liste=liste->next;
        }
        liste->next=creerNoeud(nouveau,NULL);
    }
}

void retirerDepuisListe(Arbre *racine, Individu * element){
    if(element==NULL) return;
    if(racine->next==NULL){
        racine->individu=NULL;
    }else{
        Arbre * precedent=NULL;
        while(racine!=NULL && racine->individu!=element){
                precedent=racine;
                racine=racine->next;
        }
        if(racine!=NULL){
            if(precedent==NULL){
                racine->individu=racine->next->individu;
                racine->next=racine->next->next;
            }else{
            precedent->next=racine->next;
            }
        }



    }
}
char *  dateDeces(Individu * individu){
    if(individu->dateNaissance==NULL) return "";
    char  * date=malloc(10);
    Date * naissance=individu->dateNaissance;
    sprintf(date,"%d/%d/%d",naissance->jour,naissance->mois,naissance->annee);
    return date;
}

char * dateNaissance(Individu * individu){
    if(individu->dateDeces==NULL) return "";
    else {
          char  * date=malloc(10);
    Date * deces=individu->dateDeces;
    sprintf(date,"%d/%d/%d",deces->jour,deces->mois,deces->annee);
    return date;
    }
}
int estDecede(Individu * individu){
    return individu->dateDeces!=NULL;
}



Pays * nouveauPays(char * nom,char * code){
    Pays * p =malloc(sizeof(Pays));
    p->code=malloc(3);strcpy(p->code,code);
    p->nomPays=malloc(strlen(nom)+1);strcpy(p->nomPays,nom);
    return p;

}

char * getNomPays(Pays * listePays,int index,int taille){
   if(index<taille) return listePays[index].nomPays;
    return NULL;
}

int getIndexPays(ListePays listePays,char * nom ){
    int i=0;
    while(i< listePays.taille){

        if(!strcasecmp(listePays.pays[i]->code,nom)){
            return i;
        }
        i++;
    }
    return -1;
}

void ajouterPays(ListePays * liste,Pays  * pays){

    liste->pays[liste->taille]=pays;
    liste->taille=liste->taille+1;
}

int getTaille(ListePays liste){
    return liste.taille;
}
Date * nouvelleDate(char * date){
    int  jour =atoi(strtok(date,"/"));
    int  mois = atoi(strtok(NULL,"/"));
    int annee = atoi(strtok(NULL,"/"));
    Date *d =malloc(sizeof(Date));
    d->annee=annee;
    d->jour=jour;
    d->mois=mois;
    return d;
}


void printDate(Individu * individu ,int i){
    if(i) printf("%2d/%2d%/%4d ",individu->dateDeces->jour,individu->dateDeces->mois,individu->dateDeces->annee);
        else printf("%2d/%2d%/%4d ",individu->dateNaissance->jour,individu->dateNaissance->mois,individu->dateNaissance->annee);
}
