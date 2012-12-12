// Pierre WILMOT
// 20 mai 2010
// Chess
// jeu.c
// 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "jeu.h"
#include "echec.h"
#include "deplacement.h"
#include "option.h"
#include "save.h"

void jouer (SDL_Surface* ecran, struct options options, int *enpause, int vload)
{

printf ("Debut de la fonction jouer \n");

// Declaration de variable

int plateau[8][8] = {0};
int deco[8][8][2] = {0};
int continuer = 0;
int selection = 0; // 1 : Une piece est selectionnée // 0 : Non
int libre = 0;
int echec = 0;
int i = 0;
int j = 0;
int tour = 0;
int lasttour = 0 ;
int starttime = 0 ;
struct coordonees casedepart = {0, 0};
struct coordonees casearrivee = {0, 0};
struct coordonees positionroi = {0, 0};
struct roque roque = {1, 1, 1, 0, 0};

SDL_Event event;

// Fin de la declaration de variables

// Initialisation

continuer = 1; 

if (vload == 0)
{
	plateau[0][0] = 10; 
	plateau[1][0] = 9;
	plateau[2][0] = 8;
	plateau[3][0] = 12;
	plateau[4][0] = 11;
	plateau[5][0] = 8; 
	plateau[6][0] = 9;
	plateau[7][0] = 10;

	plateau[0][1] = 7; 
	plateau[1][1] = 7;
	plateau[2][1] = 7;
	plateau[3][1] = 7;
	plateau[4][1] = 7;
	plateau[5][1] = 7; 
	plateau[6][1] = 7;
	plateau[7][1] = 7;

	plateau[0][6] = 1; 
	plateau[1][6] = 1;
	plateau[2][6] = 1;
	plateau[3][6] = 1;
	plateau[4][6] = 1;
	plateau[5][6] = 1; 
	plateau[6][6] = 1;
	plateau[7][6] = 1;

	plateau[0][7] = 4; 
	plateau[1][7] = 3;
	plateau[2][7] = 2;
	plateau[3][7] = 5;
	plateau[4][7] = 6;
	plateau[5][7] = 2; 
	plateau[6][7] = 3;
	plateau[7][7] = 4;
	
	archivage (&casedepart, &casearrivee, 1, &starttime, tour) ; // Ecriture de l'en-tete
}
else if (vload == 1)
{
	load (plateau) ;
}

affichage(ecran, plateau, deco, options);

for ( i = 0 ; i < 8 ; i ++ )
{
for ( j = 0 ; j < 8 ; j ++ )
{
	if ( plateau[i][j] == 6 )
	{
		positionroi.x = i;
		positionroi.y = j;
	}
}
}

// Fin d'initialisation

	while (continuer)
	{

		SDL_WaitEvent(&event); /* Récupèration de l'évènement dans event */
		switch(event.type) /* Test du type d'évènement */
		{
			case SDL_QUIT: /* Si c'est un évènement de type "Quitter" */
				continuer = 0;
			break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE: // ECHAP
						save (plateau);
						*enpause = 1;
						continuer = 0;
					break;
				}
			break;
			case SDL_MOUSEBUTTONUP:
			  
			  
				if ( tour != lasttour ) // Si on a changé de tour
				{
				printf(" \n\n////// TOUR %d //////\n", tour);
				}
				lasttour = tour ;
				
				if (options.o2 > 1){printf(" Clic en x= %d // y = %d \n", event.button.x, event.button.y);}
				
				deplacement (event, ecran, &casedepart, &casearrivee, plateau, deco, &selection, &positionroi, &echec, &tour, &roque, &starttime);
				
				affichage(ecran, plateau, deco, options, roque);
			break;
		
	    	}
	}
	
printf ("Fin de la fonction jouer \n");

} // Fin de la fonction jouer


