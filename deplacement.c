// Pierre WILMOT
// 20 juin 2010
// Chess
// deplacement.c
// 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "jeu.h"
#include "deplacement.h"
#include "affichage.h"


void deplacement (SDL_Event event, SDL_Surface* ecran, struct coordonees* casedepart, struct coordonees* casearrivee, int plateau[][8], int deco[][8][2], int *selection, struct coordonees* positionroi, int *echec, int *tour, struct roque* roque, int *starttime)
{

// Declaration de variables

int i = 0;
int j = 0;

int libre = 1;
int casearriveeavant = 0;  // Ce qu'il y avait dans la case d'arrivée avant deplacement.
int exeption = 0; 
struct coordonees position ;
int toutescasesroquelibres = 1 ;
int caseroqueenechec = 0;

// Fin de la declaration de variables







	if (*selection == 0) // Si on vient de selectionner une piece.
	{
		(*roque).prp = 0 ;
		(*roque).grp = 0 ; 
	  
		for ( i = 0 ; i < 8 ; i ++ )
		{
		for ( j = 0 ; j < 8 ; j ++ )
		{
			if ( event.button.x > i * 50 && event.button.x < i * 50	+ 50 )
			{
				(*casedepart).x = i;
			}
			if ( event.button.y > j * 50 && event.button.y < j * 50	+ 50 )
			{
				(*casedepart).y = j;
			}
		}
		}

		printf ("Case de depart selectionnée : %d/%d \n", (*casedepart).x , (*casedepart).y );
		
		// A partir de la c'est la deco !
		
		switch (plateau[(*casedepart).x][(*casedepart).y]) // Type de piece selectionnée ?
		{ 
			case 0: // Case vide

			break;
			case 1: // Pion blanc				
				deco[(*casedepart).x][(*casedepart).y][0] = 1 ; // Indique la case selectionnée.
				if ( (*casedepart).y != 0 && plateau[(*casedepart).x][(*casedepart).y - 1] == 0) // Si on est pas en haut de l'ecran && que la case du dessus est vide
				{
					deco[(*casedepart).x][(*casedepart).y - 1][0] = 2 ; // Case d'arrivé potentielle.
				}
				if ( (*casedepart).y == 6 && plateau[(*casedepart).x][(*casedepart).y - 1] == 0 && plateau[(*casedepart).x][(*casedepart).y - 2] == 0) // Si le pion est encore sur sa ligne de depart && que les deux cases du dessus sont libres 
				{ 
					deco[(*casedepart).x][(*casedepart).y - 2][0] = 2 ; // Il peux avancer de deux cases.
				} 
				if ( plateau[(*casedepart).x - 1][(*casedepart).y - 1] == 7 || plateau[(*casedepart).x - 1][(*casedepart).y -1] == 8 || plateau[(*casedepart).x - 1][(*casedepart).y - 1] == 9 || plateau[(*casedepart).x - 1][(*casedepart).y - 1] == 10 || plateau[(*casedepart).x - 1][(*casedepart).y - 1] == 11 || plateau[(*casedepart).x - 1][(*casedepart).y - 1] == 12 ) // Piece ennemie en diagonale gauche
				{
					deco[(*casedepart).x - 1][(*casedepart).y - 1][0] = 2;
				}
				if ( (plateau[(*casedepart).x + 1][(*casedepart).y - 1] == 7 || plateau[(*casedepart).x + 1][(*casedepart).y - 1] == 8 || plateau[(*casedepart).x + 1][(*casedepart).y - 1] == 9 || plateau[(*casedepart).x + 1][(*casedepart).y - 1] == 10 || plateau[(*casedepart).x + 1][(*casedepart).y - 1] == 11 || plateau[(*casedepart).x + 1][(*casedepart).y - 1] == 12) && (*casedepart).x < 7 ) // Piece ennemie en diagonale droite
				{
					deco[(*casedepart).x + 1][(*casedepart).y - 1][0] = 2;
				}
				*selection = 1;
			break;
			case 2: // Fou blanc
				deco[(*casedepart).x][(*casedepart).y][0] = 1 ; // Indique la case selectionnée.
				*selection = 1 ;
				// DIAGONALE HAUT GAUCHE //
				if ( (*casedepart).y <= (*casedepart).x ) // Si plus pres du haut que de la gauche
				{
					for ( i = 1 ; i < (*casedepart).y + 1 ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( (*casedepart).y > (*casedepart).x )  // Si plus pres de la gauche que du haut
				{
					for ( i = 1 ; i < (*casedepart).x + 1; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;
				// DIAGONALE HAUT DROITE //				
				if ( (*casedepart).y <= (7 - (*casedepart).x) ) // Si plus pres du haut que de la droite
				{
					for ( i = 1 ; i < (*casedepart).y + 1; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( (*casedepart).y > (7 - (*casedepart).x) )  // Si plus pres de la droite que du haut
				{
					for ( i = 1 ; i < 8 - (*casedepart).x ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;
				// DIAGONALE BAS GAUCHE //
				if ( 8 - (*casedepart).y <= (*casedepart).x ) // Si plus pres du bas que de la gauche
				{
					for ( i = 1 ; i < 8 - (*casedepart).y ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( 8 - (*casedepart).y > (*casedepart).x )  // Si plus pres de la gauche que du bas
				{
					for ( i = 1 ; i < (*casedepart).x + 1 ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;
				// DIAGONALE BAS DROITE //
				if ( 8 - (*casedepart).y <= 8 - (*casedepart).x ) // Si plus pres du bas que de la droite
				{
					for ( i = 1 ; i < 8 - (*casedepart).y ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( 8 - (*casedepart).y > 8 - (*casedepart).x )  // Si plus pres de la droite que du bas
				{
					for ( i = 1 ; i < 8 - (*casedepart).x ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;				
			break;
			case 3: // Cavalier blanc
				deco[(*casedepart).x][(*casedepart).y][0] = 1 ; // Indique la case selectionnée.
				*selection = 1 ;
				if ( ((*casedepart).x + 2) < 8 && ((*casedepart).y - 1) >= 0 ) // Haut-Droite-Droite
				{
					deco[(*casedepart).x + 2][(*casedepart).y - 1][0] = 2; 
				}
				if ( ((*casedepart).x - 2) >= 0 && ((*casedepart).y - 1) >= 0 ) // Haut-Gauche-Gauche
				{
					deco[(*casedepart).x - 2][(*casedepart).y - 1][0] = 2; 
				}
				if ( ((*casedepart).x + 1) < 8 && ((*casedepart).y - 2) >= 0 ) // Haut-Haut-Droite
				{
					deco[(*casedepart).x + 1][(*casedepart).y - 2][0] = 2; 
				}
				if ( ((*casedepart).x - 1) >= 0 && ((*casedepart).y - 2) >= 0 ) // Haut-Haut-Gauche
				{
					deco[(*casedepart).x - 1][(*casedepart).y - 2][0] = 2; 
				}
				if ( ((*casedepart).x + 2) < 8 && ((*casedepart).y + 1) < 8 ) // Bas-Droite-Droite
				{
					deco[(*casedepart).x + 2][(*casedepart).y + 1][0] = 2; 
				}
				if ( ((*casedepart).x - 2) >= 0 && ((*casedepart).y + 1) < 8 ) // Bas-Gauche-Gauche
				{
					deco[(*casedepart).x - 2][(*casedepart).y + 1][0] = 2; 
				}
				if ( ((*casedepart).x + 1) < 8 && ((*casedepart).y + 2) < 8 ) // Bas-Bas-Droite
				{
					deco[(*casedepart).x + 1][(*casedepart).y + 2][0] = 2; 
				}
				if ( ((*casedepart).x - 1) >= 0 && ((*casedepart).y + 2) < 8 ) // Bas-Bas-Gauche
				{
					deco[(*casedepart).x - 1][(*casedepart).y + 2][0] = 2; 
				}
			break;
			case 4: // Tour blanche
				deco[(*casedepart).x][(*casedepart).y][0] = 1 ; // Indique la case selectionnée.
				*selection = 1;
				for ( i = 1 ; i <= (*casedepart).x ; i ++ ) // Gauche 
				{
					if (libre == 1)
					{
						deco[(*casedepart).x - i][(*casedepart).y][0] = 2;
						if (plateau[(*casedepart).x - i][(*casedepart).y] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
				for ( i = 1 ; i < 8 - (*casedepart).x ; i ++ ) // Droite
				{
					if (libre == 1)
					{
						deco[(*casedepart).x + i][(*casedepart).y][0] = 2;
						if (plateau[(*casedepart).x + i][(*casedepart).y] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
				for ( i = 1 ; i <= (*casedepart).y ; i ++ ) // Haut 
				{
					if (libre == 1)
					{
						deco[(*casedepart).x][(*casedepart).y - i][0] = 2;
						if (plateau[(*casedepart).x][(*casedepart).y - i] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
				for ( i = 1 ; i < 8 - (*casedepart).y ; i ++ ) // Bas
				{
					if (libre == 1)
					{
						deco[(*casedepart).x][(*casedepart).y + i][0] = 2;
						if (plateau[(*casedepart).x][(*casedepart).y + i] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
			break;
			case 5: // Dame blanche
				deco[(*casedepart).x][(*casedepart).y][0] = 1 ; // Indique la case selectionnée.
				*selection = 1 ;
				// DIAGONALE HAUT GAUCHE //
				if ( (*casedepart).y <= (*casedepart).x ) // Si plus pres du haut que de la gauche
				{
					for ( i = 1 ; i < (*casedepart).y + 1 ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( (*casedepart).y > (*casedepart).x )  // Si plus pres de la gauche que du haut
				{
					for ( i = 1 ; i < (*casedepart).x + 1; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;
				// DIAGONALE HAUT DROITE //				
				if ( (*casedepart).y <= (7 - (*casedepart).x) ) // Si plus pres du haut que de la droite
				{
					for ( i = 1 ; i < (*casedepart).y + 1; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( (*casedepart).y > (7 - (*casedepart).x) )  // Si plus pres de la droite que du haut
				{
					for ( i = 1 ; i < 8 - (*casedepart).x ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y - i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y - i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;
				// DIAGONALE BAS GAUCHE //
				if ( 8 - (*casedepart).y <= (*casedepart).x ) // Si plus pres du bas que de la gauche
				{
					for ( i = 1 ; i < 8 - (*casedepart).y ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( 8 - (*casedepart).y > (*casedepart).x )  // Si plus pres de la gauche que du bas
				{
					for ( i = 1 ; i < (*casedepart).x + 1 ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x - i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x - i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;
				// DIAGONALE BAS DROITE //
				if ( 8 - (*casedepart).y <= 8 - (*casedepart).x ) // Si plus pres du bas que de la droite
				{
					for ( i = 1 ; i < 8 - (*casedepart).y ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
				else if ( 8 - (*casedepart).y > 8 - (*casedepart).x )  // Si plus pres de la droite que du bas
				{
					for ( i = 1 ; i < 8 - (*casedepart).x ; i ++ ) 
					{
						if (libre == 1)
						{
							deco[(*casedepart).x + i][(*casedepart).y + i][0] = 2;
							if (plateau[(*casedepart).x + i][(*casedepart).y + i] != 0 )
							{
								libre = 0;
							} 
						}
					}
				}
					libre = 1;		
				for ( i = 1 ; i <= (*casedepart).x ; i ++ ) // Gauche 
				{
					if (libre == 1)
					{
						deco[(*casedepart).x - i][(*casedepart).y][0] = 2;
						if (plateau[(*casedepart).x - i][(*casedepart).y] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
				for ( i = 1 ; i < 8 - (*casedepart).x ; i ++ ) // Droite
				{
					if (libre == 1)
					{
						deco[(*casedepart).x + i][(*casedepart).y][0] = 2;
						if (plateau[(*casedepart).x + i][(*casedepart).y] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
				for ( i = 1 ; i <= (*casedepart).y ; i ++ ) // Haut 
				{
					if (libre == 1)
					{
						deco[(*casedepart).x][(*casedepart).y - i][0] = 2;
						if (plateau[(*casedepart).x][(*casedepart).y - i] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
				for ( i = 1 ; i < 8 - (*casedepart).y ; i ++ ) // Bas
				{
					if (libre == 1)
					{
						deco[(*casedepart).x][(*casedepart).y + i][0] = 2;
						if (plateau[(*casedepart).x][(*casedepart).y + i] != 0 )
						{
							libre = 0;
						} 
					}
				}
				libre = 1 ;
			break;
			case 6: // Roi blanc
				deco[(*casedepart).x][(*casedepart).y][0] = 1 ; // Indique la case selectionnée.
				*selection = 1 ;
				if ( (*casedepart).y > 0) //Haut
				{
					deco[(*casedepart).x][(*casedepart).y - 1][0] = 2;
				}
				if ( (*casedepart).y < 7) //Bas
				{
					deco[(*casedepart).x][(*casedepart).y + 1][0] = 2;
				}
				if ( (*casedepart).x > 0) //Gauche
				{
					deco[(*casedepart).x - 1][(*casedepart).y][0] = 2;
				}
				if ( (*casedepart).x < 7) //Droite
				{
					deco[(*casedepart).x + 1][(*casedepart).y][0] = 2;
				}
				if ( (*casedepart).y > 0 && (*casedepart).x > 0 ) // Haut-Gauche
				{
					deco[(*casedepart).x - 1][(*casedepart).y - 1][0] = 2;
				}
				if ( (*casedepart).y > 0 && (*casedepart).x < 7 ) // Haut-Droite
				{
					deco[(*casedepart).x + 1][(*casedepart).y - 1][0] = 2;
				}
				if ( (*casedepart).y < 7 && (*casedepart).x > 0 ) // Bas-Gauche
				{
					deco[(*casedepart).x - 1][(*casedepart).y + 1][0] = 2;
				}
				if ( (*casedepart).y < 7 && (*casedepart).x < 7 ) // Bas-Droite
				{
					deco[(*casedepart).x + 1][(*casedepart).y + 1][0] = 2;
				}
				if ( (*roque).rjb == 1 && (*roque).tgjb == 1 && plateau[1][7] == 0 && plateau[2][7] == 0 && plateau[3][7] == 0 ) // Grand roque possible
				{
					(*roque).grp = 1;
					deco[2][7][0] = 2;
					printf ("GRAND ROQUE POSSIBLE\n");
				}
				if ( (*roque).rjb == 1 && (*roque).tgjb == 1 && plateau[5][7] == 0 && plateau[6][7] == 0 ) // Petit roque possible
				{
					(*roque).prp = 1;
					deco[6][7][0] = 2;
					printf ("PETIT ROQUE POSSIBLE\n");
				}
				
			break;
			case 7: // Pion noir
				
			break;
			case 8: // Fou noir

			break;
			case 9: // Cavalier noir

			break;
			case 10: // Tour noire

			break;
			case 11: // Dame noire

			break;
			case 12: // Roi noir

			break;

		}
		
		fonctionechec (&(*positionroi), plateau, deco, &(*echec));
		
		// Fini la deco
	}

	else if (*selection == 1) // Si on vient de demander de deplacer une piece
	{
				
		for ( i = 0 ; i < 8 ; i ++ )
		{
		for ( j = 0 ; j < 8 ; j ++ )
		{
			if ( event.button.x > i * 50 && event.button.x < i * 50	+ 50 )
			{
				(*casearrivee).x = i;
			}
			if ( event.button.y > j * 50 && event.button.y < j * 50	+ 50 )
			{
				(*casearrivee).y = j;
			}
		}
		}

		printf ("Case d'arrivée selectionnée : %d/%d \n", (*casearrivee).x , (*casearrivee).y );		

		if ( deco[(*casearrivee).x][(*casearrivee).y][0] == 1 ) // Si on re-clique sur la piece deja selectionnée
		{
			for (i = 0 ; i < 8 ; i ++ ) { for (j = 0 ; j < 8 ; j ++) { deco[i][j][0] = 0 ; }}
			*selection = 0;
		}
		else if ( deco[(*casearrivee).x][(*casearrivee).y][0] == 2 && plateau[(*casearrivee).x][(*casearrivee).y] != 1 && plateau[(*casearrivee).x][(*casearrivee).y] != 2 && plateau[(*casearrivee).x][(*casearrivee).y] != 3 && plateau[(*casearrivee).x][(*casearrivee).y] != 4 && plateau[(*casearrivee).x][(*casearrivee).y] != 5 && plateau[(*casearrivee).x][(*casearrivee).y] != 6 )
		{
			for (i = 0 ; i < 8 ; i ++ ) { for (j = 0 ; j < 8 ; j ++) { deco[i][j][0] = 0 ; }} // On efface le tableau deco

			// Exceptions
				
				if (plateau[(*casedepart).x][(*casedepart).y] == 1 && (*casearrivee).y == 0 ) // Si un pion atteind la derniere ligne
				{
					casearriveeavant = plateau[(*casearrivee).x][(*casearrivee).y];
					
					plateau[(*casearrivee).x][(*casearrivee).y] = message (ecran, 2);;
					plateau[(*casedepart).x][(*casedepart).y] = 0 ;
					exeption = 1; 
				}
				
				else if ( (*roque).prp == 1 && (*casearrivee).x == 6 && (*casearrivee).y == 7 ) // petit roque
				{	
					toutescasesroquelibres = 1 ;
					position.y = 7 ; 
					for ( i = 0 ; i < 3 ; i++ )
					{
						caseroqueenechec = 0;
						position.x = 4 + i ;
						fonctionechec (	&position, plateau, deco, &caseroqueenechec);
						if ( caseroqueenechec == 1 )
						{
							toutescasesroquelibres = 0 ;
						}
					}
					if (toutescasesroquelibres == 1)
					{
						plateau[4][7] = 0;
						plateau[5][7] = 4;
						plateau[6][7] = 6;
						plateau[7][7] = 0;
						(*roque).prp = 0 ;
						(*roque).rjb = 0 ;
						(*roque).tpjb = 0 ;
						printf("PETIT ROQUE\n");
						(*positionroi).x = (*casearrivee).x ;
						(*positionroi).y = (*casearrivee).y ;
						exeption = 3;
					}
					else 					  
					{
						message (ecran, 3); // On affiche un message.
					}
				}
				
				else if ( (*roque).grp == 1 && (*casearrivee).x == 2 && (*casearrivee).y == 7 ) // Grand roque
				{
					toutescasesroquelibres = 1 ;
					position.y = 7 ; 
					for ( i = 0 ; i < 4 ; i++ )
					{
						caseroqueenechec = 0;
						position.x = 4 - i ;
						fonctionechec (	&position, plateau, deco, &caseroqueenechec);
						if ( caseroqueenechec == 1 )
						{
							toutescasesroquelibres = 0 ;
						}
					}
					if (toutescasesroquelibres == 1)
					{
						plateau[0][7] = 0;
						plateau[1][7] = 0;
						plateau[2][7] = 6;
						plateau[3][7] = 4;
						plateau[4][7] = 0;
						(*roque).grp = 0 ;
						(*roque).rjb = 0 ;
						(*roque).tgjb = 0 ;
						printf("GRAND ROQUE\n");
						(*positionroi).x = (*casearrivee).x ;
						(*positionroi).y = (*casearrivee).y ;
						exeption = 4;
					}
					else 					  
					{
						message (ecran, 3); // On affiche un message.
					}
				}
								
				else if ( plateau[(*casedepart).x][(*casedepart).y] == 6 ) // Si deplacement du roi
				{
					(*positionroi).x = (*casearrivee).x ;
					(*positionroi).y = (*casearrivee).y ;
					casearriveeavant = plateau[(*casearrivee).x][(*casearrivee).y];
					plateau[(*casearrivee).x][(*casearrivee).y] = plateau[(*casedepart).x][(*casedepart).y];
					plateau[(*casedepart).x][(*casedepart).y] = 0;
					exeption = 2; 
				}

			// Fin des exceptions
				else 
				{
					casearriveeavant = plateau[(*casearrivee).x][(*casearrivee).y];
					plateau[(*casearrivee).x][(*casearrivee).y] = plateau[(*casedepart).x][(*casedepart).y];
					plateau[(*casedepart).x][(*casedepart).y] = 0;
				}
			
			*selection = 0; 
			*tour = *tour + 1 ;
		}
		
		fonctionechec (&(*positionroi), plateau, deco, &(*echec));
		
		if (*echec == 1) // Si apres le deplacement, le roi et en echec ...
		{
			 annulerdeplacement (plateau, casearriveeavant, &(*casedepart), &(*casearrivee), &(*positionroi), exeption, &(*roque) ); // On annule le deplacement.
			 for ( i = 0 ; i < 8 ; i ++ ) { for (j = 0 ; j < 8 ; j ++ ) { deco[i][j][1] = 0 ; }} // On efface la deco violette
			 message (ecran, 1); // On affiche un message.
			 *tour = *tour - 1; // On annule l'augmentation du nombre de tours.
		}
		
		exeption = 0 ;
		(*roque).prp = 0 ;
		(*roque).grp = 0 ; 
		archivage (&(*casedepart), &(*casearrivee), 2, &(*starttime), *tour) ;
	}	

} // Fin de la fonction deplacement

void annulerdeplacement ( int plateau[][8], int casearriveeavant, struct coordonees* casedepart, struct coordonees* casearrivee, struct coordonees* positionroi, int exeption, struct roque* roque )
{
	   switch (exeption)
	   {
		  case 0:
			plateau[(*casedepart).x][(*casedepart).y] = plateau[(*casearrivee).x][(*casearrivee).y]; 
			plateau[(*casearrivee).x][(*casearrivee).y] = casearriveeavant;	
		  break;
		  case 1: // Le dernier deplacement nous a fait gagner une reine.
			plateau[(*casedepart).x][(*casedepart).y] = 1;  
			plateau[(*casearrivee).x][(*casearrivee).y] = casearriveeavant;	
		  break; 
		  case 2: // Ona deplacé le roi.
			plateau[(*casedepart).x][(*casedepart).y] = plateau[(*casearrivee).x][(*casearrivee).y]; 
			plateau[(*casearrivee).x][(*casearrivee).y] = casearriveeavant;	
			(*positionroi).x = (*casedepart).x ;
			(*positionroi).y = (*casedepart).y ;
		  break; 
		  case 3: // Petit roque
			plateau[4][7] = 6;
			plateau[5][7] = 0;
			plateau[6][7] = 0;
			plateau[7][7] = 4;
			(*positionroi).x = (*casedepart).x ;
			(*positionroi).y = (*casedepart).y ;
			(*roque).prp = 1 ;
			(*roque).rjb = 1 ;
			(*roque).tpjb = 1 ;			
		  break;
		  case 4: // Grand roque
			plateau[0][7] = 4;
			plateau[1][7] = 0;
			plateau[2][7] = 0;
			plateau[3][7] = 0;
			plateau[4][7] = 6;
			(*positionroi).x = (*casedepart).x ;
			(*positionroi).y = (*casedepart).y ;
			(*roque).grp = 1 ;
			(*roque).rjb = 1 ;
			(*roque).tgjb = 1 ;	
		  break;
	   }
}
