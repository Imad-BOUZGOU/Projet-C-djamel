#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


struct Date{
    int jour;
    int mois;
    int annee;

};
typedef struct Date Date;
struct Pays{
    char * nomPays;
    char * code;
};
typedef struct Pays Pays;

typedef struct ListePays{
    Pays * pays[300];
    int taille;
};
typedef struct ListePays ListePays;


typedef struct Individu Individu;
        struct Individu{
            char* prenom;
            char sexe;
            Individu* pere;
            Individu* mere;
            int* level;
            char* prenomPere;
            char* prenomMere;
            Date * dateNaissance;
            Date * dateDeces;
            char * origines;
            char * naissance;

            };

typedef struct Arbre  Arbre;
        struct Arbre{
            Individu *individu;
            Arbre* next;
            };

Arbre* load(char* fileName);
int save(char* fileName,Arbre *racine);
Individu* findIndividu(char *name,Arbre *arbre);
int  New(Arbre* racine,char* prenom,char* sexe,char* pere,char* mere,char* dateNaissance,char * dateDeces);
int isFather(Individu *noeud,Individu *personne);
int isMother(Individu *noeud,Individu *personne);
void printArbre(Arbre *racine);
void print(Individu* personne);
int putChild(Arbre* arbre,Individu *personne);
Individu* findIndividu(char *name,Arbre *arbre);
Individu* info(char* prenom,Arbre* racine);
Individu * nouvellePersonne(char *prenom,char sexe,Individu *mere,Individu * pere,char * dateNaissance,char * dateDeces);
char *  dateDeces(Individu * individu);
char * dateNaissance(Individu * individu);
int estDecede(Individu * individu);

Pays * nouveauPays(char * nom,char * code);
void ajouterPays(ListePays * liste,Pays * pays);
Date * nouvelleDate(char * date);
#endif // FUNCTIONS_H_INCLUDED
