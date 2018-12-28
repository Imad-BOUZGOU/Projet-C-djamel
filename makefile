hello: main.o controlle.o functions.o partie2.o recherche.o
	gcc -o main main.o controlle.o functions.o partie2.o recherche.o 

main.o: main.c
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
recherche.o: 
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
recherche.o: recherche.c recherche.h functions.o 
	gcc -o recherche.o -c recherche.c functions.o  -W -Wall -ansi -pedantic

functions.o: functions.c functions.h partie2.o 
	gcc -o functions.o -c functions.c -W -Wall -ansi -pedantic

partie2.o: partie2.c partie2.h 
	gcc -o partie2.o -c partie2.c  -W -Wall -ansi -pedantic



