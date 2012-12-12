// Pierre WILMOT
// 20 juin 2010
// Chess
// save.c
// 

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "jeu.h"
#include "save.h"
#include "utils.h"


void save (int plateau[][8] )
{

printf ("\n Enregistrement ... ");

FILE* fichier = NULL;
fichier = fopen("save/plateau.sav", "w+");

int i = 0;
int j = 0;

if (fichier != NULL)
{
	for ( i = 0 ; i < 8 ; i ++ )
	{
	for ( j = 0 ; j < 8 ; j ++ )
	{
		switch (plateau[i][j])
		{
			case 0:
				fputc('0', fichier);
			break;
			case 1:
				fputc('1', fichier);
			break;
			case 2:
				fputc('2', fichier);
			break;
			case 3:
				fputc('3', fichier);
			break;
			case 4:
				fputc('4', fichier);
			break;
			case 5:
				fputc('5', fichier);
			break;
			case 6:
				fputc('6', fichier);
			break;
			case 7:
				fputc('7', fichier);
			break;
			case 8:
				fputc('8', fichier);
			break;
			case 9:
				fputc('9', fichier);
			break;
			case 10:
				fputc('A', fichier);
			break;
			case 11:
				fputc('B', fichier);
			break;
			case 12:
				fputc('C', fichier);
			break;
		}
	}
	}
	
	fclose(fichier);

printf ("terminé \n\n");

}
else
{
printf("Impossible d'ouvrir le fichier save/plateau.sav");
}

} // Fin de la fonction save

void load (int plateau[][8])
{

printf ("\n Chargement ...");

FILE* fichier = NULL;
fichier = fopen("save/plateau.sav", "r");

int i = 0;
int j = 0;
char caractere ;

if (fichier != NULL)
{
	for ( i = 0 ; i < 8 ; i++ )
	{
	for ( j = 0 ; j < 8 ; j++ )
	{
		caractere = fgetc(fichier);
		
		switch (caractere)
		{
			case '0':
				plateau[i][j] = 0;
			break;
			case '1':
				plateau[i][j] = 1;
			break;
			case '2':
				plateau[i][j] = 2;
			break;
			case '3':
				plateau[i][j] = 3;
			break;
			case '4':
				plateau[i][j] = 4;
			break;
			case '5':
				plateau[i][j] = 5;
			break;
			case '6':
				plateau[i][j] = 6;
			break;
			case '7':
				plateau[i][j] = 7;
			break;
			case '8':
				plateau[i][j] = 8;
			break;
			case '9':
				plateau[i][j] = 9;
			break;
			case 'A':
				plateau[i][j] = 10;
			break;
			case 'B':
				plateau[i][j] = 11;
			break;
			case 'C':
				plateau[i][j] = 12;
			break;
		}
	}
	}

fclose(fichier);
printf ("terminé \n\n");

}
else
{
printf("\n Impossible d'ouvrir le fichier save/plateau.sav \n");
}

} // Fin de la faonction load

void archivage (struct coordonees* casedepart, struct coordonees* casearrivee, int phase, int *starttime, int tour)
{

// Declaration de variables


int i = 0 ;


// Fin de la declaration de variables.



if (phase == 1) // Debut de partie, ecriture de l'en-tete
{


time_t timestamp;  //Variable pour stocker le timestamp
struct tm *date; // Stucture date

// Convertion de la date
time(&timestamp);
*starttime = timestamp ;
date = localtime(&timestamp);  

printf ("Date de debut de partie : %d/%d/%d\n", date->tm_mday, (date->tm_mon + 1), (date->tm_year + 1900));  
  
char cheminfichier[100] = "save/parties/" ;
char nomfichier[] = "0000000000" ;
char extension[] = ".pgn" ;
int puissance = 1000000000;
// Determination du nom du fichier a créer
	for ( i = 0 ; i < 10 ; i ++ )
	{	
	
	conversion ((timestamp / puissance), &nomfichier[i]) ; // Convertion timestamp int ==> string
		
	//starttime = starttime + ((timestamp / puissance) * puissance);
	timestamp = timestamp - ((timestamp / puissance) * puissance) ;
	puissance = puissance / 10 ;

	}

	strcat(cheminfichier, nomfichier);
	strcat(cheminfichier, extension);

	printf("Nom de fichier final : %s\n",cheminfichier);

	FILE* fichier = NULL;
	fichier = fopen(cheminfichier, "w+");	

	if (fichier != NULL)
	{

	

	char chaine1[100] = "[Event \"Casual Game\"]\n[Site \"?\"]\n[Date = ";
	char chaine2[10];
	char chaine3[] = "]\n[Round \"1\"]\n[White = \"Pierre WILMOT\"]\n[Black = \"Legume\"]\n[Result \"*\"]\n\n";
	
	int v2010 = ((date->tm_year + 1900) / 1000); 
	printf ("v2010 = %d\n", v2010);
	int v010 = (((date->tm_year + 1900) - (v2010 * 1000)) / 100 );
	printf ("v010 = %d\n", v010);
	int v10 = (((date->tm_year + 1900) - (v2010 * 1000) - (v010 * 100)) / 10);
	printf ("v10 = %d\n", v10);
	int v0 = ((date->tm_year + 1900) - (v2010 * 1000) - (v010 * 100) - v10 * 10);
	printf ("v0 = %d\n", v0);
	
	conversion (v2010, &chaine2[0]) ; // Premier chiffre de l'année
	conversion (v010, &chaine2[1]) ; // 2eme
	conversion (v10, &chaine2[2] ); // 3eme
	conversion (v0, &chaine2[3]) ; // 4eme
	chaine2[4] = '/';
	conversion (((date->tm_mon + 1) / 10), &chaine2[5]) ; // Premier chiffre du mois
	conversion ((date->tm_mon + 1) - (((date->tm_mon + 1) / 10) * 10), &chaine2[6]) ; // Deuxieme chiffre du mois
	chaine2[7] = '/';
	conversion ((date->tm_mday / 10), &chaine2[8]) ; // Premier chiffre des jours
	conversion ((date->tm_mday - ((date->tm_mday / 10) * 10)), &chaine2[9]) ; // Deuxieme chiffre des jours
	chaine2[10] = '\0' ;

	strcat(chaine1, chaine2);
	strcat(chaine1, chaine3);

        fputs(chaine1, fichier); // On ecrit l'en-tete
	fclose(fichier);

    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible de créer le fichier de sauvegarde de la partie.");
    }
}

else if ( phase = 2 ) // Enregistrement des deplacements.
{

char cheminfichier[100] = "save/parties/" ;
char nomfichier[] = "0000000000" ;
char extension[] = ".pgn" ;
int puissance = 1000000000;
int timestamp = *starttime ;
// Determination du nom du fichier a créer
	for ( i = 0 ; i < 10 ; i ++ )
	{	
	
	conversion ((timestamp / puissance), &nomfichier[i]) ; // Convertion timestamp int ==> string
		
	starttime = starttime + ((timestamp / puissance) * puissance);
	timestamp = timestamp - ((timestamp / puissance) * puissance) ;
	puissance = puissance / 10 ;

	}

	strcat(cheminfichier, nomfichier);
	strcat(cheminfichier, extension);
	
	FILE* fichier = NULL;
	fichier = fopen(cheminfichier, "a+");	


	char coup[10] ;

	conversion ( (tour / 10) , &coup[0] ); // Numero de tour (dizaines)
	conversion ( (tour - ((tour / 10)*10)) , &coup[1] ); // Numero de tour (unitées)
	coup[2] = '.' ;
	coup[3] = ' ' ;
	conversion2 ( (*casedepart).x , &coup[4] ); 
	conversion ( (*casedepart).y , &coup[5] ); 
	coup[6] = ' ' ;
	conversion2 ( (*casearrivee).x , &coup[7] ); 
	conversion ( (*casearrivee).y , &coup[8] ); 
	coup[9] = '\n' ;
	coup[10] = '\0' ;

        fputs(coup, fichier); // On ecrit l'en-tete
	fclose(fichier);

}  

} // Fin de la fonction archivage
