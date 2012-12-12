// Pierre WILMOT
// 29 mai 2010
// Chess
// affichage.c
// 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeu.h"
#include "option.h"

void affichage (SDL_Surface* ecran, int plateau[][8], int deco [][8][2], struct options options, struct roque roque )
{

printf ("Affichage \n"); 

// Declaration de variables

int i = 0;
int j = 0;

	// Declaration des surfaces

	SDL_Rect position;
	SDL_Surface *fond = NULL, *pb = NULL, *fb = NULL, *cb = NULL, *tb = NULL, *db = NULL, *rb = NULL, *pn = NULL, *fn = NULL, *cn = NULL, *tn =NULL, *dn = NULL, *rn = NULL, *A = NULL, *B = NULL, *C = NULL, *D = NULL, *E = NULL, *F = NULL, *G = NULL, *H = NULL, *I = NULL, *J = NULL, *K = NULL, *erreur = NULL; 

	fond = IMG_Load("img/0.png"); // Plateau

	pb = IMG_Load("img/1.png"); // Pion blanc
	fb = IMG_Load("img/2.png"); // Fou blanc
	cb = IMG_Load("img/3.png"); // Cavalier blanc
	tb = IMG_Load("img/4.png"); // Tour blanche
	db = IMG_Load("img/5.png"); // Dame blanche
	rb = IMG_Load("img/6.png"); // Roi blanc

	pn = IMG_Load("img/7.png"); // Pion noir
	fn = IMG_Load("img/8.png"); // Fou noir
	cn = IMG_Load("img/9.png"); // Cavalier noir
	tn = IMG_Load("img/10.png"); // Tour noire
	dn = IMG_Load("img/11.png"); // Dame noire
	rn = IMG_Load("img/12.png"); // Roi noir

	A = IMG_Load("img/A.png"); // Case accessible
	B = IMG_Load("img/B.png"); // Case innaccessible
	C = IMG_Load("img/C.png"); // Piece ennemie accessible
	D = IMG_Load("img/D.png"); // Case echec horizontale
	E = IMG_Load("img/E.png"); // Case echec verticale
	F = IMG_Load("img/F.png"); // Piece qui met en echec
	G = IMG_Load("img/G.png"); // Rond orange 
	H = IMG_Load("img/H.png"); // Point violet
	I = IMG_Load("img/I.png"); // Diagonale droite violet
	J = IMG_Load("img/J.png"); // Diagonale gauche violet
	K = IMG_Load("img/K.png"); // Carre vert roque
	erreur = IMG_Load("img/42.png"); // POINT ROUGE
	// Fin de la declarations des surfaces

// Fin de la declaration de variables

// Initialisation

position.x = 0;
position.y = 0; 

// Fin d'initialisation

SDL_BlitSurface(fond, NULL, ecran, &position); // On affiche le plateau

// EXEPTIONS

	if ( roque.prp == 1 ) // Petit roque possible
	{
		position.x = 50 * 6;
		position.y = 50 * 7;
		
		SDL_BlitSurface(K, NULL, ecran, &position);
	}
	if ( roque.grp == 1 ) // Grand roque possible
	{
		position.x = 50 * 2;
		position.y = 50 * 7;
		
		SDL_BlitSurface(K, NULL, ecran, &position);
	}

// FIN DES EXEPTIONS

for ( i = 0 ; i < 8 ; i ++ )
{
for (j = 0 ; j < 8 ; j ++ )
{

	position.x = i * 50;
        position.y = j * 50;
	
	if ( options.o1 == 1 ) // Si on veux affiché les indications echec
	{
		switch (deco[i][j][1])
		{
			case 3:
				SDL_BlitSurface(D, NULL, ecran, &position); 
			break;
			case 4:
				SDL_BlitSurface(E, NULL, ecran, &position); 
			break;
			case 5: // Carre violet
				SDL_BlitSurface(F, NULL, ecran, &position); 
			break;
			case 6:
				SDL_BlitSurface(H, NULL, ecran, &position); 
			break;
			case 7: // Diagonale gauche violet
				SDL_BlitSurface(I, NULL, ecran, &position); 
			break;
			case 8: // Diagonale droite violet 
				SDL_BlitSurface(J, NULL, ecran, &position); 
			break;
			case 42: // ERREUR ROND ROUGE
				SDL_BlitSurface(erreur, NULL, ecran, &position); 
			break;
		}
	}

	switch (deco[i][j][0])
	{
		case 1: // Case selectionnée
			SDL_BlitSurface(A, NULL, ecran, &position); // Cercle bleu
		break;
		case 2: // Case qu'on peux atteindre
			if( plateau[i][j] == 0)
			{
				SDL_BlitSurface(B, NULL, ecran, &position); // Point vert
			}
			else if (plateau[i][j] == 1 || plateau[i][j] == 2 || plateau[i][j] == 3 || plateau[i][j] == 4 || plateau[i][j] == 5 || plateau[i][j] == 6 )
			{
				SDL_BlitSurface(G, NULL, ecran, &position); // Cercle orange
			}
			else if (plateau[i][j] == 12 || plateau[i][j] == 7 || plateau[i][j] == 8 || plateau[i][j] == 9 || plateau[i][j] == 10 || plateau[i][j] == 11 )
			{
				SDL_BlitSurface(C, NULL, ecran, &position); // Cercle rouge
			}
		break;
	}
		  
	switch (plateau[i][j]) // Les pieces
	{
		case 1: // Pion blanc
			SDL_BlitSurface(pb, NULL, ecran, &position);
		break;
		case 2: // Fou lanc
			SDL_BlitSurface(fb, NULL, ecran, &position);
		break;
		case 3: // Cavaler blanc
			SDL_BlitSurface(cb, NULL, ecran, &position);
		break;		
		case 4: // Tour blanche
			SDL_BlitSurface(tb, NULL, ecran, &position);
		break;
		case 5: // Dame blanche
			SDL_BlitSurface(db, NULL, ecran, &position);
		break;
		case 6: // Roi blanc
			SDL_BlitSurface(rb, NULL, ecran, &position);
		break;
		case 7: // Pion noir
			SDL_BlitSurface(pn, NULL, ecran, &position);
		break;
		case 8: // Fou noir
			SDL_BlitSurface(fn, NULL, ecran, &position);
		break;
		case 9: // Cavalier noir
			SDL_BlitSurface(cn, NULL, ecran, &position);
		break;
		case 10: // Tour noire
			SDL_BlitSurface(tn, NULL, ecran, &position);
		break;
		case 11: // Dame noire
			SDL_BlitSurface(dn, NULL, ecran, &position);
		break;
		case 12: // Roi noir
			SDL_BlitSurface(rn, NULL, ecran, &position);
		break;
	}

}
}

SDL_Flip(ecran);

} // Fin de la fonction affichage

int message (SDL_Surface* ecran, int idmess)
{

// Declaration de variables

	SDL_Surface *box = NULL, *titre = NULL, *texte1 = NULL, *texte2 = NULL, *texte3 = NULL, *texte4 = NULL, *texte5 = NULL, *texte6 = NULL, *cavalier = NULL, *fou = NULL, *tour = NULL, *reine = NULL ;
	
	SDL_Rect positionbox;
	SDL_Rect positiontitre;
	SDL_Rect positiontexte1;
	SDL_Rect positiontexte2;
	SDL_Rect positiontexte3;
	SDL_Rect positiontexte4;
	SDL_Rect positiontexte5;
	SDL_Rect positiontexte6;
	SDL_Rect positioncavalier;
	SDL_Rect positionfou;
	SDL_Rect positiontour;
	SDL_Rect positionreine;

  	TTF_Font *police = NULL, *police1 = NULL;
	SDL_Color blanc = {255, 255, 255};
	
	TTF_Init(); 
	
	police = TTF_OpenFont("img/police.ttf", 15);
	police1 = TTF_OpenFont("img/police.ttf", 50);
	
	SDL_Event event;
	
	int hauteurbox = 0; 
	int largeurbox = 0; 
	
	int continuer = 1; 
	
	

// Fin de la declaration de variables.
	
	switch (idmess)
	{
	  case 1: // Roi vers une case en echec
	  
		titre = TTF_RenderText_Blended(police1, "ATTENTION", blanc);
		texte1 = TTF_RenderText_Blended(police, "Deplacement impossible.", blanc);
		texte2 = TTF_RenderText_Blended(police, "Ce deplacement met votre roi en echec.", blanc);
		texte3 = TTF_RenderText_Blended(police, "Appuyez sur [A] pour continuer.", blanc);
	    
		hauteurbox = 15 + titre->h + 20 + texte1->h + 10 + texte2->h + 15 + texte3->h + 10; 
		largeurbox = 20 + texte2->w + 20;
		
		box = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurbox, hauteurbox, 32, 0, 0, 0, 0);
		SDL_FillRect(box, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		
		positionbox.x = (( 400 - largeurbox) / 2);
        	positionbox.y = (( 400 - hauteurbox) / 2);	
		
		positiontitre.x = (( 400 - titre->w) / 2);
		positiontitre.y = positionbox.y + 15;
		positiontexte1.x = (( 400 - texte1->w) / 2);
        	positiontexte1.y = positiontitre.y + titre->h + 20;
		positiontexte2.x = (( 400 - texte2->w) / 2);
        	positiontexte2.y = positiontexte1.y + texte1->h + 10; 
		positiontexte3.x = (( 400 - texte3->w) / 2);
        	positiontexte3.y = positiontexte2.y + texte2->h + 15; 
		
		SDL_BlitSurface(box, NULL, ecran, &positionbox);
		SDL_BlitSurface(titre, NULL, ecran, &positiontitre);
		SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
		SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);
		SDL_BlitSurface(texte3, NULL, ecran, &positiontexte3);
		
	  break;
	  case 2: // Promotion d'un pion
	    
		texte1 = TTF_RenderText_Blended(police, "Votre pion a ateind la derniere ligne.", blanc);
		texte2 = TTF_RenderText_Blended(police, "Choisissez une piece.", blanc);
		
		cavalier = IMG_Load("img/3.png");
		fou = IMG_Load("img/2.png");
		tour = IMG_Load("img/4.png");
		reine = IMG_Load("img/5.png");
		
		texte3 = TTF_RenderText_Blended(police, "[A]", blanc);
		texte4 = TTF_RenderText_Blended(police, "[Z]", blanc);
		texte5 = TTF_RenderText_Blended(police, "[E]", blanc);
		texte6 = TTF_RenderText_Blended(police, "[R]", blanc);
		
		hauteurbox = 15 + texte1->h + 10 + texte2->h + 15 +50 + 10 + texte3-> h +10 ; 
		largeurbox = 10 + texte1->w + 10 ;
		
		box = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurbox, hauteurbox, 32, 0, 0, 0, 0);
		
		positionbox.x = (( 400 - largeurbox) / 2);
        	positionbox.y = (( 400 - hauteurbox) / 2);	
		
		positiontexte1.x = (( 400 - texte1->w) / 2);
        	positiontexte1.y = positionbox.y + 15;
		positiontexte2.x = (( 400 - texte2->w) / 2);
        	positiontexte2.y = positiontexte1.y + texte1->h + 10; 
		
		positioncavalier.x = ((400 - 250) / 2) + 10 ;
		positioncavalier.y = positiontexte2.y + texte2->h + 15 ;
		positionfou.x = positioncavalier.x + 50 + 10 ;
		positionfou.y = positioncavalier.y ;
		positiontour.x = positionfou.x + 50 + 10 ;
		positiontour.y = positioncavalier.y ;
		positionreine.x = positiontour.x + 50 + 10 ;
		positionreine.y = positioncavalier.y ;
		
		positiontexte3.x = positioncavalier.x + ( (50 - texte3->w) / 2 ) ;
		positiontexte3.y = positioncavalier.y + 50 + 10 ;
		positiontexte4.x = positionfou.x + ( (50 - texte3->w) / 2 ) ;
		positiontexte4.y = positioncavalier.y + 50 + 10 ;		
		positiontexte5.x = positiontour.x + ( (50 - texte3->w) / 2 ) ;
		positiontexte5.y = positioncavalier.y + 50 + 10 ;		
		positiontexte6.x = positionreine.x + ( (50 - texte3->w) / 2 ) ;
		positiontexte6.y = positioncavalier.y + 50 + 10 ;
		
		SDL_BlitSurface(box, NULL, ecran, &positionbox);
		SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
		SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);
		SDL_BlitSurface(cavalier, NULL, ecran, &positioncavalier);
		SDL_BlitSurface(fou, NULL, ecran, &positionfou);
		SDL_BlitSurface(tour, NULL, ecran, &positiontour);
		SDL_BlitSurface(reine, NULL, ecran, &positionreine);
		SDL_BlitSurface(texte3, NULL, ecran, &positiontexte3);
		SDL_BlitSurface(texte4, NULL, ecran, &positiontexte4);
		SDL_BlitSurface(texte5, NULL, ecran, &positiontexte5);
		SDL_BlitSurface(texte6, NULL, ecran, &positiontexte6);
		
	  break; 
	  case 3:
		
		titre = TTF_RenderText_Blended(police1, "ATTENTION", blanc);
		texte1 = TTF_RenderText_Blended(police, "Deplacement impossible.", blanc);
		texte2 = TTF_RenderText_Blended(police, "Une des cases sur la trajectoire du roque", blanc);
		texte3 = TTF_RenderText_Blended(police, "est \"en echec\"", blanc);
		texte4 = TTF_RenderText_Blended(police, "Appuyez sur [A] pour continuer.", blanc);
	    
		hauteurbox = 15 + titre->h + 20 + texte1->h + 10 + texte2->h + 10 + texte3->h + 15 + texte4->h + 10; 
		largeurbox = 20 + texte2->w + 20;
		
		box = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurbox, hauteurbox, 32, 0, 0, 0, 0);
		SDL_FillRect(box, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		
		positionbox.x = (( 400 - largeurbox) / 2);
        	positionbox.y = (( 400 - hauteurbox) / 2);	
		
		positiontitre.x = (( 400 - titre->w) / 2);
		positiontitre.y = positionbox.y + 15;
		positiontexte1.x = (( 400 - texte1->w) / 2);
        	positiontexte1.y = positiontitre.y + titre->h + 20;
		positiontexte2.x = (( 400 - texte2->w) / 2);
        	positiontexte2.y = positiontexte1.y + texte1->h + 10; 
		positiontexte3.x = (( 400 - texte3->w) / 2);
        	positiontexte3.y = positiontexte2.y + texte2->h + 10;
		positiontexte4.x = (( 400 - texte4->w) / 2);
        	positiontexte4.y = positiontexte3.y + texte3->h + 15; 
		
		SDL_BlitSurface(box, NULL, ecran, &positionbox);
		SDL_BlitSurface(titre, NULL, ecran, &positiontitre);
		SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
		SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);
		SDL_BlitSurface(texte3, NULL, ecran, &positiontexte3);
		SDL_BlitSurface(texte4, NULL, ecran, &positiontexte4);
		
	  break;
	}	
		SDL_Flip(ecran); 
		
		while (continuer)
		{
			SDL_WaitEvent(&event);
			if ( event.type == SDL_KEYDOWN )
			{
				switch(event.key.keysym.sym)
				{
				  case SDLK_a:
					continuer = 0;
					return 3 ;
				  break;
				  case SDLK_z:
					continuer = 0;
					return 2 ;
				  break;
				  case SDLK_e:
					continuer = 0;
					return 4 ;
				  break;
				  case SDLK_r:
					continuer = 0;
					return 5 ;
				  break;
				  
				}
			}
		}
		

	
  
} // Fin de la fonction message

void loadgraphics (int load)
{

} // Fin de la fonction loadgraphics
