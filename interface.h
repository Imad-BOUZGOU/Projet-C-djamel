#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED


// --------------fonction d'affichage de couleurs-----------//
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

/** ****************************************************************************************************** **/
/** ****************************************************************************************************** **/
//-------------fonction de presentation------------------//
void intro()
{
	Color(6,16);
printf(" ***************************************************************************\n");
printf(" *");

Color(3,16);
printf("             _");

Color(6,16);
printf("                                                           *\n");
printf(" *            ");


Color(3,16);
printf("|_|");


Color(6,16);
printf("                                                          *\n");
printf(" *            ");

Color(3,16);
printf("/_/");
Color(6,16);
printf("                                                          *  \n");
printf(" *   ");
Color(15,16);
printf("                            ");

Color(6,16);
printf("                                          * \n");
printf(" *  ");
Color(15,16);


Color(6,16);
printf("                                                                       *\n");
printf(" * ");
Color(15,16);

printf(" Faculte Jean Perrin                                          ");

Color(6,16);
printf("          *\n");
printf(" *  ");
Color(15,16);

printf("   Projet C Avance                                          ");

Color(6,16);
printf("           * \n");
printf(" *                                                                         *\n");
printf(" *                                                                         *\n");
printf(" *  ");
Color(15,16);

printf("Programme : Arbre genealogique                                   ");

Color(6,16);
printf("      *\n");
printf(" *  ");
Color(15,16);

printf("Realise par : BOUZGOU IMAD                                           ");

Color(6,16);
printf("  *\n");
printf(" *                        ");
Color(15,16);

printf("Version N-1 - 02/11/2018");

Color(6,16);
printf("                         *  \n");
printf(" *  ");
Color(15,16);

printf("Encadre par : M.johan koitka        ");

Color(6,16);
printf("                                       *\n");
printf(" *                                                                         *\n");
printf(" *                                                                         *\n");
printf(" *                                                                         *\n");
printf(" *               ");

Color(15,16);
printf("APPUYEZ SUR LA TOUCHE ENTREE POUR COMMENCER");

Color(6,16);
printf("               *\n");
printf(" *                                                                         *\n");
printf(" ***************************************************************************\n");
getch();
system("cls");

}
/** ****************************************************************************************************** **/
/** ****************************************************************************************************** **/

void fin()
{
    system("cls");
    Color(2,16);

}


#endif // INTERFACE_H_INCLUDED

