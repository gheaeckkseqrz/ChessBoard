// Pierre WILMOT
// 20 mai 2010
// Chess
// main.c
// 


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeu.h"
#include "option.h"


int main(int argc, char *argv[])
{

printf ("\nDemarage du programme\n");

// Declaration de variables.	

    SDL_Surface *ecran = NULL, *Fond = NULL, *titre = NULL, *texte1 = NULL, *texte2 = NULL, *texte3 = NULL, *texte4 = NULL;
    SDL_Rect positionFond;
    SDL_Rect positiontitre;
    SDL_Rect positiontexte1;
    SDL_Rect positiontexte2;
    SDL_Rect positiontexte3;
    SDL_Rect positiontexte4;

    SDL_Event event;

    positionFond.x = 0;
    positionFond.y = 0;

	TTF_Font *police = NULL, *police1 = NULL;
	SDL_Color blanc = {255, 255, 255};

    int continuer = 1;
    int enpause = 0;
    
    struct options options = {0};

// Fin de la declaration de variables

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); 

    SDL_WM_SetCaption("CHESS", NULL);
    SDL_WM_SetIcon(IMG_Load("img/icon.gif"), NULL);
    ecran = SDL_SetVideoMode(400, 400, 32, SDL_HWSURFACE);

    Fond = IMG_Load("img/background.png");
    police = TTF_OpenFont("img/police.ttf", 15);
    police1 = TTF_OpenFont("img/police.ttf", 50);

    chargeroption (&options);
    
	while (continuer)
	{

	    SDL_BlitSurface(Fond, NULL, ecran, &positionFond);
		if ( enpause == 0)
		{
			titre = TTF_RenderText_Blended(police1, "CHESS", blanc);			
		}
		else if ( enpause == 1 )
		{
			titre = TTF_RenderText_Blended(police1, "PAUSE", blanc);
		}

			positiontitre.x = (( 400 - titre->w) / 2);
        		positiontitre.y = 20;
			SDL_BlitSurface(titre, NULL, ecran, &positiontitre);
			texte1 = TTF_RenderText_Blended(police, "[A] Nouvelle partie", blanc);
			texte2 = TTF_RenderText_Blended(police, "[Z] Continuer", blanc);
			texte3 = TTF_RenderText_Blended(police, "[E] Options", blanc);
			texte4 = TTF_RenderText_Blended(police, "[R] Quitter", blanc);
			positiontexte1.x = (( 400 - texte1->w) / 2);
        		positiontexte1.y = 100;
			positiontexte2.x = positiontexte1.x;
        		positiontexte2.y = 150;
			positiontexte3.x = positiontexte1.x;
        		positiontexte3.y = 200;
			positiontexte4.x = positiontexte1.x;
        		positiontexte4.y = 250;
			SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
			SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);
			SDL_BlitSurface(texte3, NULL, ecran, &positiontexte3);
			SDL_BlitSurface(texte4, NULL, ecran, &positiontexte4);
	    
	    SDL_Flip(ecran);

	    SDL_WaitEvent(&event); // Récupèration de l'évènement dans event 
	    switch(event.type) // Test du type d'évènement 
	    {
		case SDL_QUIT: // Si c'est un évènement de type "Quitter" 
		    continuer = 0;
		    break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
			    case SDLK_ESCAPE: // ECHAP
				continuer = 0;
				break;
			    case SDLK_SPACE: // (SPACE) ==> Jouer
				if (options.o2 > 0) {printf ("\nLancement d'une nouvelle partie.\n"); }
				jouer(ecran, options, &enpause, 0);
				break;
			    case SDLK_o: //(O) ==> Options
				option(ecran, &options);
				break;
			    case SDLK_a: // (A) ==> Jouer
				if (options.o2 > 0) {printf ("\nLancement d'une nouvelle partie.\n"); }
				jouer(ecran, options, &enpause, 0);
				break;
			    case SDLK_z: // (E) ==> Continuer
				if (options.o2 > 0) {printf ("\nReprise d'une partie en cours.\n"); }
				jouer(ecran, options, &enpause, 1);
				break;
			    case SDLK_e: // (E) ==> Option
				option(ecran, &options);
				break;
			    case SDLK_r: //(R) ==> Quitter
				if (options.o2 > 0) { printf ("\nFermeture du programme.\n"); }
				continuer = 0;
				break;
			}
        	break;

	    }
	}


    SDL_FreeSurface(Fond);
    SDL_Quit(); 

    return EXIT_SUCCESS;
}
