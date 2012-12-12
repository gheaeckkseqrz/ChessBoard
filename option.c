// Pierre WILMOT
// 20 juin 2010
// Chess
// option.c
// 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "option.h"

void chargeroption (struct options* options)
{
if ((*options).o2 > 0) { printf("\nChargement des options\n"); }

FILE* fichier = NULL;
fichier = fopen("save/options.sav", "r");

char caractere ;

// Chargement de O1
caractere = fgetc(fichier);

if (caractere == '1')
{
	(*options).o1 = 1;
}
else if (caractere == '0')
{
	(*options).o1 = 0;
}

// Chargement de O2
caractere = fgetc(fichier);

if (caractere == '0')
{
	(*options).o2 = 0;
}
else if (caractere == '1')
{
	(*options).o2 = 1;
}
else if (caractere == '2')
{
	(*options).o2 = 2;
}
else if (caractere == '3')
{
	(*options).o2 = 3;
}

fclose(fichier);
}


void option (SDL_Surface* ecran, struct options* options)
{

printf("\n// Ouverture du menu options //\n\n");

TTF_Init();
FILE* fichier = NULL;
fichier = fopen("save/options.sav", "w+");


// Declaration de variables

SDL_Event event;
TTF_Font *police = NULL, *police1 = NULL;
police = TTF_OpenFont("img/police.ttf", 12);
police1 = TTF_OpenFont("img/police.ttf", 50);
SDL_Color blanc = {255, 255, 255};

SDL_Rect positiontitre;

SDL_Rect positiontexte1;

	positiontexte1.x = 50;
        positiontexte1.y = 100;

SDL_Rect positiontexte2;

	positiontexte2.x = 50;
        positiontexte2.y = 150;

SDL_Rect positionvoyant1;
SDL_Rect positionvoyant2;


int continuer = 1;

	// Declaration de surfaces
	
		SDL_Surface *O0 = NULL, *O1 = NULL, *O11 = NULL, *O12 = NULL, *O13 = NULL, *titre = NULL, *texte1 = NULL, *texte2 = NULL;

		O0 = IMG_Load("img/O0.png"); // Voyant Rouge
		O1 = IMG_Load("img/O1.png"); // Voyant Vert
		O11 = IMG_Load("img/O1-1.png"); // Voyant Vert 1
		O12 = IMG_Load("img/O1-2.png"); // Voyant Vert 2
		O13 = IMG_Load("img/O1-3.png"); // Voyant Vert 3	

		texte1 = TTF_RenderText_Blended(police, "Affichage Case Echec :", blanc);
		texte2 = TTF_RenderText_Blended(police, "Niveau d'affichage des messages :", blanc);
		titre = TTF_RenderText_Blended(police1, "OPTIONS", blanc);

	// Fin de la declaration de surfaces

// Fin de la declaration de variables

	positionvoyant1.x = positiontexte1.x + texte1->w + 25;
        positionvoyant1.y = positiontexte1.y - (( 50 - texte1->h ) / 2) ;

	positionvoyant2.x = positiontexte2.x + texte2->w + 25;
        positionvoyant2.y = positiontexte2.y - (( 50 - texte2->h ) / 2) ;

	positiontitre.x = (( 400 - titre->w) / 2);
        positiontitre.y = 20;

	while (continuer)
	{

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); // On efface l'écran
		SDL_BlitSurface(titre, NULL, ecran, &positiontitre); // On affiche le titre : OPTIONS
		SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1); // On afiche : Affichage Case Echec
		SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2); // On affiche : Niveau d'affichage des messages.
	    
	    if ( (*options).o1 == 0 )
	    {
		    SDL_BlitSurface(O0, NULL, ecran, &positionvoyant1);
	    }
	    else if ( (*options).o1 == 1 )
	    {
		    SDL_BlitSurface(O1, NULL, ecran, &positionvoyant1);
	    }	    
	    SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);
	    
	    if ( (*options).o2 == 0 )
	    {
		    SDL_BlitSurface(O0, NULL, ecran, &positionvoyant2);
	    }
	    else if ( (*options).o2 == 1 )
	    {
		    SDL_BlitSurface(O11, NULL, ecran, &positionvoyant2);
	    }
	    else if ( (*options).o2 == 2 )
	    {
		    SDL_BlitSurface(O12, NULL, ecran, &positionvoyant2);
	    }
	    else if ( (*options).o2 == 3 )
	    {
		    SDL_BlitSurface(O13, NULL, ecran, &positionvoyant2);
	    }

	    SDL_Flip(ecran);

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
				continuer = 0;
				break;
			}
        	break;
		case SDL_MOUSEBUTTONUP:
			if ( event.button.x > (positiontexte1.x + texte1->w + 25) && event.button.x < (positiontexte1.x + texte1->w + 75) && event.button.y > (positiontexte1.y ) && event.button.y < (positiontexte1.y + 50) ) // Si on clique sur le premier voyant
			{
				if ( (*options).o1 == 0 )
				{
					(*options).o1 = 1 ;
					printf("Activation de l'option o1\n");
				}
				else if ( (*options).o1 == 1 )
				{
					(*options).o1 = 0 ;
					printf("Desactivation de l'option o1\n");
				}
			}
			else if ( event.button.x > (positiontexte2.x + texte2->w + 25) && event.button.x < (positiontexte2.x + texte2->w + 75) && event.button.y > (positiontexte2.y ) && event.button.y < (positiontexte2.y + 50) ) // Si on clique sur le deuxieme voyant
			{
				(*options).o2 = (*options).o2 + 1 ;
				if ((*options).o2 == 4)
				{
					(*options).o2 = 0;
				}
				printf("Option o2 au niveau %d\n", (*options).o2 );
			}		
		break;

	    }
	}

// Partie enregistrement
	if ( (*options).o1 == 1 ) //O1 ON
	{
		fputc('1', fichier);
	}
	else if ( (*options).o1 == 0 ) // O1 OFF
	{
		fputc('0', fichier);
	}
	if ( (*options).o2 == 0 ) // O2 niveau 0
	{
		fputc('0', fichier);
	}
	else if ( (*options).o2 == 1 ) // O2 niveau 1
	{
		fputc('1', fichier);
	}
	else if ( (*options).o2 == 2 ) // O2 niveau 2
	{
		fputc('2', fichier);
	}
	else if ( (*options).o2 == 3 ) // O2 niveau 3
	{
		fputc('3', fichier);
	}
// Fin de la partie enregistrement

	fclose(fichier);

	TTF_CloseFont(police);
	TTF_Quit();

	SDL_FreeSurface(titre);
	SDL_FreeSurface(texte1);
	SDL_FreeSurface(texte2);
	SDL_FreeSurface(O0);
	SDL_FreeSurface(O1);
	
}
