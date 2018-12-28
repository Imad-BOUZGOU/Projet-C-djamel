#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "Interface.h"
#include "functions.h"
#include "partie2.h"
#include "recherche.h"



int main()
{
    char * command=malloc(100);
    char *fName,*argm;
        Individu* personne;
    int fin=0;
    Arbre *liste=malloc(sizeof(Arbre));
    liste->individu=NULL;
    liste->next=NULL;
    intro();

    ListePays pays= chargerOrigine("iso2.csv");


    while(!fin){
        Color(2,16);//green

    printf("Projet@root> ");
    Color(15,16);//white
    scanf("%s",command);
    fName=strtok (command, "(");
    printf("%s \n",fName);
    printf("commande = %s\n ",command);


    /** load(NomFichier) ***/
    if(!strcasecmp(fName, "load")){
            printf("Loading\n");
            argm=strtok (NULL, ")");
            liste=load(argm);
             //printArbre(liste);
             printf("\n");

    };

    /*** save ***/
    if(!strcasecmp(fName, "save")){
            printf("Saving");
            strtok (command, "(");
            save(argm,liste);
    };

    if(!strcasecmp(fName, "view")){
        printf("Choisissez Le mode d'affichage : \n");
        printf("1- Tri par Date de naissance \n");
        printf("2- Tri par Age \n");
        printf("3- Tri par Ordre alphabétique  \n");
        printf("4- Affichage Aléatoire \n");
        int choix;
        scanf("%d",&choix);
        printListe(TrierListe(liste,1));
        printf("\n");
    };

     /** exit ****/
    if(!strcasecmp(fName, "exit")){
            fin=1;


    };

    /** info(prenom) ****/
    if(!strcasecmp(fName, "info")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne!=NULL) {
               printf("\n%s: %c , ",personne->prenom,personne->sexe);
               if(personne->pere!=NULL) printf("%s , ",personne->pere->prenom);
               else printf(" , ");
                if(personne->mere!=NULL) printf("%s  ",personne->mere->prenom);

                    }

            else printf("Oops! %s n'existe pas ",argm);


             printf("\n");



    };
    /** mere(prenom) ****/
    if(!strcasecmp(fName, "mere")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
              if(personne==NULL) printf("La personne n'existe pas !!");
              else {

            if(personne->mere!=NULL) {
               printf("\nLa mere de %s est  %s\n",personne->prenom,personne->mere->prenom);

                    }else printf("\nOops!La mere de %s n'existe pas \n",argm);

              }





             printf("\n");



    };



        /** pere(prenom) ****/
    if(!strcasecmp(fName, "pere")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne==NULL) printf("La personne n'existe pas !!");
            else{
                if(personne->pere!=NULL) {
               printf("\nLe pere de %s est  %s\n",personne->prenom,personne->pere->prenom);

                    }else printf("Le pere de %s n'existe pas \n",argm);



              }






             printf("\n");



    };




        /** parents(prenom) ****/
    if(!strcasecmp(fName, "parents")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne==NULL) printf("La personne n'existe pas !!");
            else{
                if(personne->pere!=NULL) {
               printf("\nLe pere de %s est  %s\n",personne->prenom,personne->pere->prenom);

                    }else printf("\nOops!Le pere de %s n'existe pas \n",argm);
                     if(personne->mere!=NULL) {
               printf("La mere de %s est  %s\n",personne->prenom,personne->mere->prenom);

                    }else printf("La mere de %s n'existe pas \n",argm);
            }





             printf("\n");



    };



    /** gdmeres(prenom) ****/
    if(!strcasecmp(fName, "gdmeres")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne==NULL) printf("La personne n'existe pas !!");
            else{

                     if(personne->mere!=NULL) {

                      if(personne->mere->mere!=NULL) printf("La grande mere de %s est  %s\n",personne->prenom,personne->mere->mere->prenom);
                     else printf("La grande mere de %s n'existe pas \n",argm);

                    }else printf("La grande mere de %s n'existe pas \n",argm);

                     if(personne->pere!=NULL) {

                      if(personne->pere->mere!=NULL) printf("La grande mere de %s est  %s\n",personne->prenom,personne->pere->mere->prenom);
                     else printf("La grande mere de %s n'existe pas \n",argm);

                    }else printf("La grande mere de %s n'existe pas \n",argm);
            }





             printf("\n");



    };

        /** gdperes(prenom) ****/
    if(!strcasecmp(fName, "gdperes")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne==NULL) printf("La personne n'existe pas !!");
            else{

                     if(personne->mere!=NULL) {

                      if(personne->mere->pere!=NULL) printf("Le grand pere de %s est  %s\n",personne->prenom,personne->mere->pere->prenom);
                     else printf("Le grand pere de %s n'existe pas \n",argm);
                      if(personne->mere->mere!=NULL) printf("La grande mere de %s est  %s\n",personne->prenom,personne->mere->mere->prenom);
                     else printf("La grande mere de %s n'existe pas \n",argm);

                    }else printf("Le grand pere de %s n'existe pas \n",argm);

                     if(personne->pere!=NULL) {

                      if(personne->pere->pere!=NULL) printf("Le grand pere de %s est  %s\n",personne->prenom,personne->pere->pere->prenom);
                     else printf("Le grand pere de %s n'existe pas \n",argm);

                    }else printf("Le grand pere de %s n'existe pas \n",argm);
            }





             printf("\n");



    };

            /** gdparents(prenom) ****/
    if(!strcasecmp(fName, "gdparents")){

            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne==NULL) printf("La personne n'existe pas !!");
            else{

                     if(personne->mere!=NULL) {

                      if(personne->mere->pere!=NULL) printf("Le grand pere de %s est  %s\n",personne->prenom,personne->mere->pere->prenom);


                    }

                     if(personne->pere!=NULL) {

                      if(personne->pere->pere!=NULL) printf("Le grand pere de %s est  %s\n",personne->prenom,personne->pere->pere->prenom);

                        if(personne->pere->mere!=NULL) printf("La grande mere de %s est  %s\n",personne->prenom,personne->pere->mere->prenom);


                    }
            }





             printf("\n");



    };


            /** ascendants(prenom) ****/
    if(!strcasecmp(fName, "ascendance")){
            printf("Ascendants");
            argm=strtok(NULL, ")");
            personne=info(argm,liste);
            if(personne==NULL) printf("La personne n'existe pas !!");
            else{
                    printf("Ascendande de %s = %d \n",argm,ascendance(liste,personne));
            }



             printf("\n");



    };
    /**
     taille_arbre() : donne le nombre de générations max contenu dans l’arbre
    **/
       if(!strcasecmp(fName, "taille_arbre")){
            printf("Taille de l'arbre ");
                    printf("Le nombre de generations est = %d \n",tailleArbre(liste));




             printf("\n");



    };

                /** new(prenom,sexe,pere,mere)  ****/
        if(!strcasecmp(fName, "new")){
            printf("Ajouter un individu\n");
            char *date=malloc(50);



            argm=strtok(NULL, ")");
            printf("%s\n",argm);
           char* prenom=strtok (argm, ":");
            char*    sexe=strtok (NULL, ",");
            char*    pere=strtok (NULL, ",");
            char*    mere=strtok (NULL, ",");
            char* dateNaissance=malloc(10);
            char * dateDeces= malloc(10);

            printf("Veuillez saisir la date de naissance : \n");
            scanf("%s",dateNaissance);
            printf("Veuillez saisir la date de Déces (0 s'il est encore en vie): \n");
            scanf("%s",dateDeces);
            printf("%s:::%s:::%s:::%s:::%s::::%s\n",prenom,sexe,pere,mere,dateNaissance,dateDeces);

                New(liste,prenom,sexe,pere,mere,dateNaissance,dateDeces);


                printArbre(liste);





             printf("\n");



    };
    if(!strcasecmp(fName, "lien")){
            argm=strtok(NULL, ")");
            char * p1=strtok(argm,",");
            char * p2=strtok(NULL,",");
            printf("Verification de lien de parente entre %s ; %s \n",p1,p2);
            Individu  * ind1,* ind2;
            ind1=info(p1,liste);
            ind2=info(p2,liste);

            if(p1==NULL || p2==NULL) printf("La personne n'existe pas !!");
            else{
                if(lienParente(ind1,ind2))  printf("%s et %s ont un lien de parenté \n",p1,p2);
                else printf("%s et %s n'ont pas un lien de parenté ",p1,p2);
            }



             printf("\n");



    };
               /** new(prenom,sexe,pere,mere)  ****/
    if(!strcasecmp(fName, "deces")){
            printf("deces d'in individu \n");
            argm=strtok(NULL, ")");
            printf("%s\n",argm);
           char* prenom=strtok (argm, ",");
            char*    date =strtok (NULL, ",");
            Individu * individu=findIndividu(prenom,liste);
            if(individu!=NULL) {
                    Date * d=nouvelleDate(date);
                    individu->dateDeces=d;
                    printDate(individu,1);
            }else{
                printf("Cette personne nexiste pas \n");
            }

             printf("\n");



    };

  if(!strcasecmp(fName, "aines")){
            printf("Afficher les aines \n");
            argm=strtok(NULL, ")");
            printf("%s\n",argm);
            int ageLimite=atoi(argm);
            printf("Age limite  = = %d \n",ageLimite);
            Liste * l =TrierListe(liste,0);
            printListe(l);
    };


    if(!strcasecmp(fName, "codeiso")){
            printf("Afficher les Pays  \n");
            int x=0;
            while(x<pays.taille){
                printf("Pays : %s == %s  \n",pays.pays[x]->code,pays.pays[x]->nomPays);
                x++;
            }
                printf("\n");

    };

    }


    return 0;
}



