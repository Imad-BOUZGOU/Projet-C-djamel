#include "partie2.h"
#include <time.h>
#include "functions.h"
#include <stdio.h>
void ajouterOrigine(char * listeOrigine,int nouveauOrigine){
        int indice=nouveauOrigine/8;
        int position=nouveauOrigine%8;

        listeOrigine[indice]=listeOrigine[indice] | (1<<position);

}

void afficherOrigine(char *liste){

}

ListePays chargerOrigine(char * nomFichier)    {
        FILE * fichier;
        char * line=malloc(100);
        ListePays lpays;
        lpays.taille=0;
        fichier=fopen(nomFichier,"r");
         if (fichier)
           {
               char * nomPays;
               char * codePays;
        fgets(line,100,fichier);
           /* chargement de tous les pays*/
            while(fgets(line,100,fichier)!=NULL)/*on teste et on récupère la ligne en mème temp.*/
            {
                printf("allo  ");
                line[strlen(line)-1]='\0';/*delete '\n'*/

                nomPays=strtok (line, ",");
                codePays=strtok (NULL, ",");
                printf("Pays :%s et code %s \n",nomPays,codePays);
                Pays * pays=nouveauPays(nomPays,codePays);
                ajouterPays(&lpays,pays);

            }

    }else printf("Ce fichier n'existe pas !");




            fclose(fichier);
            return lpays;

}


/*check given year is leap year or not*/
int isLeapYear(int year, int mon)
{
    int flag = 0;
    if (year % 100 == 0)
    {
            if (year % 400 == 0)
            {
                    if (mon == 2)
                    {
                            flag = 1;
                    }
            }
    }
    else if (year % 4 == 0)
    {
            if (mon == 2)
            {
                    flag = 1;
            }
    }
    return (flag);
}


int calculerAge(Date * naissance,Date * actuel){
   int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm *ct;

    /* enter date of birth */
    days=naissance->jour;
    month=naissance->mois;
    year=naissance->annee;
    int jourActuel,moisActuel,anneeActuelle;
    /* Si la date actuelle est null on calcule par rapport a la date de systéme*/
   if(actuel==NULL){
     /*get current date.*/
    ts = time(NULL);
    ct = localtime(&ts);

    jourActuel=ct->tm_mday;
    moisActuel=ct->tm_mon;
    anneeActuelle=ct->tm_year+1900;

    printf("Current Date: %d/%d/%d\n",
            jourActuel, moisActuel+ 1, anneeActuelle);
   }else{

    /* Sinon on calcule par rapport a la date donnée*/
    jourActuel=actuel->jour;
    moisActuel=actuel->mois-1;
    anneeActuelle=actuel->annee;

   }
    days = DaysInMon[month - 1] - days + 1;

    /* leap year checking*/
    if (isLeapYear(year, month))
    {
            days = days + 1;
    }

    /* calculating age in no of days, years and months */
    days = days + jourActuel;
    month = (12 - month) + (moisActuel);
    year = (anneeActuelle) - year - 1;

    /* checking for leap year feb - 29 days */
    if (isLeapYear((anneeActuelle), (moisActuel+1)))
    {
            if (days >= (DaysInMon[moisActuel] + 1))
            {
                    days = days - (DaysInMon[moisActuel] + 1);
                    month = month + 1;
            }
    }
    else if (days >= DaysInMon[moisActuel])
    {
            days = days - (DaysInMon[moisActuel]);
            month = month + 1;
    }

    if (month >= 12)
    {
            year = year + 1;
            month = month - 12;
    }

    /* print age */
    printf("\n## Hey you are  %d years %d months and %d days old. ##\n", year, month, days);


}
int comparer(Date * d1, Date * d2){
    return -1;
    if(d1->annee==d2->annee){
            if(d1->mois==d2->mois){
                if(d1->jour==d2->jour){
                    return 0;
                }else{
                    return d1->jour-d2->jour;
                }

            }else{
                return d1->mois-d2->mois;
            }
    }else{
        return d1->annee-d2->annee;

    }

}
int comparerAgeIndividu(Individu * ind1,Individu * ind2){
    int age1=calculerAge(ind1->dateNaissance,ind1->dateDeces);
    int age2=calculerAge(ind2->dateNaissance,ind2->dateDeces);
    return age1-age2;

}

int comparerNomIndividu(Individu * ind1,Individu * ind2){
    printf("Comparer : %s et %s ",ind1->prenom,ind2->prenom);
    int x=strcasecmp(ind1->prenom,ind2->prenom);
    printf("result=%d\n",x);
    return x;
}


