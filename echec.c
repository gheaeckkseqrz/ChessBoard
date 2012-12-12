// Pierre WILMOT
// 8 juin 2010
// Chess
// echec.c
// 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "jeu.h"


void fonctionechec (struct coordonees* positionroi, int plateau[][8], int deco[][8][2], int *echec)
{

// Declaration de variables

int continuer = 1 ; 
int i = 0 ;
int j = 0 ; 

//Fin de la declaration de variables

for (i = 0 ; i < 8 ; i ++ ) { for (j = 0 ; j < 8 ; j ++) { deco[i][j][1] = 0 ; }} // On efface le tableau deco

*echec = 0 ; 

	for ( i = 1 ; i < (*positionroi).y + 1 ; i++ ) // Vertical Haut
	{
		if ( continuer == 1)
		{
			deco[(*positionroi).x][(*positionroi).y - i][1] = 3;
			if ( plateau[(*positionroi).x][(*positionroi).y - i] != 0 )
			{
				continuer = 0 ;
				deco[(*positionroi).x][(*positionroi).y - i][1] = 0;
			}if ( plateau[(*positionroi).x][(*positionroi).y - i] == 10 || plateau[(*positionroi).x][(*positionroi).y - i] == 12 )
			{
				*echec = 1 ;
				deco[(*positionroi).x][(*positionroi).y - i][1] = 5;
			}			
		}
	}
	continuer = 1 ; 
	for ( i = 1 ; i < 8 - (*positionroi).y ; i++ ) // Vertical Bas
	{
		if ( continuer == 1)
		{
			deco[(*positionroi).x][(*positionroi).y + i][1] = 3;
			if ( plateau[(*positionroi).x][(*positionroi).y + i] != 0 )
			{
				continuer = 0 ;
				deco[(*positionroi).x][(*positionroi).y + i][1] = 0;
			}
			if ( plateau[(*positionroi).x][(*positionroi).y + i] == 10 || plateau[(*positionroi).x][(*positionroi).y + i] == 12 )
			{
				*echec = 1 ;
				deco[(*positionroi).x][(*positionroi).y + i][1] = 5;
			}
		}
	}
	continuer = 1 ; 
	for ( i = 1 ; i <= (*positionroi).x ; i++ ) // Horizontal Gauche
	{
		if ( continuer == 1)
		{
			deco[(*positionroi).x - i][(*positionroi).y][1] = 4;
			if ( plateau[(*positionroi).x - i][(*positionroi).y] != 0 )
			{
				continuer = 0 ;
				deco[(*positionroi).x - i][(*positionroi).y][1] = 0;
			}
			if ( plateau[(*positionroi).x - i][(*positionroi).y] == 10 || plateau[(*positionroi).x - i][(*positionroi).y] == 12 )
			{
				*echec = 1 ;
				deco[(*positionroi).x - i][(*positionroi).y][1] = 5;
			}
		}
	}
	continuer = 1 ; 
	for ( i = 1 ; i < 8 - (*positionroi).x ; i++ ) // Horizontal Droit
	{
		if ( continuer == 1)
		{
			deco[(*positionroi).x + i][(*positionroi).y][1] = 4;
			if ( plateau[(*positionroi).x + i][(*positionroi).y] != 0 )
			{
				continuer = 0 ;
				deco[(*positionroi).x + i][(*positionroi).y][1] = 0;
			}
			if ( plateau[(*positionroi).x + i][(*positionroi).y] == 10 || plateau[(*positionroi).x + i][(*positionroi).y] == 12 )
			{
				*echec = 1 ;
				deco[(*positionroi).x + i][(*positionroi).y][1] = 5;
			}
		}
	}

	if ( (*positionroi).x > 0 && (*positionroi).y > 1 ) // Cavalier HHG
	{
		deco[(*positionroi).x - 1][(*positionroi).y - 2][1] = 6;
		if ( plateau[(*positionroi).x - 1][(*positionroi).y - 2] == 9 )
		{
			deco[(*positionroi).x - 1][(*positionroi).y - 2][1] = 5;
		}
	}
	if ( (*positionroi).x > 1 && (*positionroi).y > 0 ) // Cavalier HGG
	{
		deco[(*positionroi).x - 2][(*positionroi).y - 1][1] = 6;
		if ( plateau[(*positionroi).x - 2][(*positionroi).y - 1] == 9 )
		{
			deco[(*positionroi).x - 2][(*positionroi).y - 1][1] = 5;
		}
	}
	if ( (*positionroi).x > 0 && (*positionroi).y < 6 ) // Cavalier BBG
	{
		deco[(*positionroi).x - 1][(*positionroi).y + 2][1] = 6;
		if ( plateau[(*positionroi).x - 1][(*positionroi).y + 2] == 9 )
		{
			deco[(*positionroi).x - 1][(*positionroi).y + 2][1] = 5;
		}
	}
	if ( (*positionroi).x > 1 && (*positionroi).y < 7 ) // Cavalier BGG
	{
		deco[(*positionroi).x - 2][(*positionroi).y + 1][1] = 6;
		if ( plateau[(*positionroi).x - 2][(*positionroi).y + 1] == 9 )
		{
			deco[(*positionroi).x - 2][(*positionroi).y + 1][1] = 5;
		}
	}
	if ( (*positionroi).x < 7 && (*positionroi).y > 1 ) // Cavalier HHD
	{
		deco[(*positionroi).x + 1][(*positionroi).y - 2][1] = 6;
		if ( plateau[(*positionroi).x + 1][(*positionroi).y - 2] == 9 )
		{
			deco[(*positionroi).x + 1][(*positionroi).y - 2][1] = 5;
		}
	}
	if ( (*positionroi).x < 6 && (*positionroi).y > 0 ) // Cavalier HDD
	{
		deco[(*positionroi).x + 2][(*positionroi).y - 1][1] = 6;
		if ( plateau[(*positionroi).x + 2][(*positionroi).y - 1] == 9 )
		{
			deco[(*positionroi).x + 2][(*positionroi).y - 1][1] = 5;
		}
	}
	if ( (*positionroi).x < 7 && (*positionroi).y < 6 ) // Cavalier BBD
	{
		deco[(*positionroi).x + 1][(*positionroi).y + 2][1] = 6;
		if ( plateau[(*positionroi).x + 1][(*positionroi).y + 2] == 9 )
		{
			deco[(*positionroi).x + 1][(*positionroi).y + 2][1] = 5;
		}
	}
	if ( (*positionroi).x < 6 && (*positionroi).y < 7 ) // Cavalier BDD
	{
		deco[(*positionroi).x + 2][(*positionroi).y + 1][1] = 6;
		if ( plateau[(*positionroi).x + 2][(*positionroi).y + 1] == 9 )
		{
			deco[(*positionroi).x + 2][(*positionroi).y + 1][1] = 5;
		}
	}

	// Diagonale haut gauche
	
	continuer = 1 ;
	if ( (*positionroi).x < (*positionroi).y ) // Roi plus pres de la gauche que du haut.
	{
		for ( i = 1 ; i < (*positionroi).x + 1; i ++ )
		{
			if ( ( plateau[(*positionroi).x - i][(*positionroi).y - i] == 8 || plateau[(*positionroi).x - i][(*positionroi).y - i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x - i][(*positionroi).y - i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x - i][(*positionroi).y - i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x - i][(*positionroi).y - i][1] = 7 ;
			}
		}
	}
	else if ( (*positionroi).x >= (*positionroi).y ) // Roi plus pres du haut que de la gauche.
	{
		for ( i = 1 ; i < (*positionroi).y + 1 ; i ++ )
		{
			if ( ( plateau[(*positionroi).x - i][(*positionroi).y - i] == 8 || plateau[(*positionroi).x - i][(*positionroi).y - i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x - i][(*positionroi).y - i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x - i][(*positionroi).y - i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x - i][(*positionroi).y - i][1] = 7 ;
			}
		}
	}

	// Diagonale haut droite
	
	continuer = 1 ;
	if ( 7 - (*positionroi).x < (*positionroi).y ) // Roi plus pres de la droite que du haut.
	{
		for ( i = 1 ; i < 8 - (*positionroi).x ; i ++ )
		{
			if ( ( plateau[(*positionroi).x + i][(*positionroi).y - i] == 8 || plateau[(*positionroi).x + i][(*positionroi).y - i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x + i][(*positionroi).y - i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x + i][(*positionroi).y - i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x + i][(*positionroi).y - i][1] = 8 ;
			}
		}
	}
	else if ( 7 - (*positionroi).x >= (*positionroi).y ) // Roi plus pres du haut que de la droite.
	{
		for ( i = 1 ; i < (*positionroi).y + 1 ; i ++ )
		{
			if ( ( plateau[(*positionroi).x + i][(*positionroi).y - i] == 8 || plateau[(*positionroi).x + i][(*positionroi).y - i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x + i][(*positionroi).y - i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x + i][(*positionroi).y - i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x + i][(*positionroi).y - i][1] = 8 ;
			}
		}
	}

	// Diagonale bas droite
	
	continuer = 1 ;
	if ( 7 - (*positionroi).x < 7 - (*positionroi).y ) // Roi plus pres de la droite que du bas.
	{
		for ( i = 1 ; i < 8 - (*positionroi).x ; i ++ )
		{
			if ( ( plateau[(*positionroi).x + i][(*positionroi).y + i] == 8 || plateau[(*positionroi).x + i][(*positionroi).y + i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x + i][(*positionroi).y + i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x + i][(*positionroi).y + i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x + i][(*positionroi).y + i][1] = 7 ;
			}
		}
	}
	else if ( 7 - (*positionroi).x >= 7 - (*positionroi).y ) // Roi plus pres du bas que de la droite.
	{
		for ( i = 1 ; i < 8 - (*positionroi).y ; i ++ )
		{
			if ( ( plateau[(*positionroi).x + i][(*positionroi).y + i] == 8 || plateau[(*positionroi).x + i][(*positionroi).y + i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x + i][(*positionroi).y + i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x + i][(*positionroi).y + i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x + i][(*positionroi).y + i][1] = 7 ;
			}
		}
	}

	// Diagonale bas gauche
	
	continuer = 1 ;
	if ( (*positionroi).x < 7 - (*positionroi).y ) // Roi plus pres de la droite que du bas.
	{
		for ( i = 1 ; i < (*positionroi).x + 1 ; i ++ )
		{
			if ( ( plateau[(*positionroi).x - i][(*positionroi).y + i] == 8 || plateau[(*positionroi).x - i][(*positionroi).y + i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x - i][(*positionroi).y + i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x - i][(*positionroi).y + i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x - i][(*positionroi).y + i][1] = 8 ;
			}
		}
	}
	else if ( (*positionroi).x >= 7 - (*positionroi).y ) // Roi plus pres du bas que de la gauche.
	{
		for ( i = 1 ; i < 8 - (*positionroi).y ; i ++ )
		{
			if ( ( plateau[(*positionroi).x - i][(*positionroi).y + i] == 8 || plateau[(*positionroi).x - i][(*positionroi).y + i] == 12 ) && continuer == 1 )
			{
				continuer = 0; 
				*echec = 1; 
				deco[(*positionroi).x - i][(*positionroi).y + i][1] = 5 ;
			}
			if ( plateau[(*positionroi).x - i][(*positionroi).y + i] != 0 )
			{
				continuer = 0;
			}
			if ( continuer == 1 )
			{
				deco[(*positionroi).x - i][(*positionroi).y + i][1] = 8 ;
			}
		}
	}

	if ( (*positionroi).x < 7 && (*positionroi).y > 0 )// Pion haut droite
	{
		if ( plateau[(*positionroi).x + 1][(*positionroi).y - 1] == 7 )
		{
			*echec = 1; 
			deco[(*positionroi).x + 1][(*positionroi).y - 1][1] = 5 ;
		}
		else if ( plateau[(*positionroi).x + 1][(*positionroi).y - 1] != 7 )
		{
			deco[(*positionroi).x + 1][(*positionroi).y - 1][1] = 6 ;
		}
	}
	if ( (*positionroi).x > 0 && (*positionroi).y > 0 )// Pion haut gauche
	{
		if ( plateau[(*positionroi).x - 1][(*positionroi).y - 1] == 7 )
		{
			*echec = 1; 
			deco[(*positionroi).x - 1][(*positionroi).y - 1][1] = 5 ;
		}
		else if ( plateau[(*positionroi).x - 1][(*positionroi).y - 1] != 7 )
		{
			deco[(*positionroi).x - 1][(*positionroi).y - 1][1] = 6 ;
		}
	}
	
	if ( *echec == 0 ) // Si on a verifié toute les direction et que le roi n'est pas en echec
	{
		printf ("Le roi (%d//%d) n'est pas en echec. \n", (*positionroi).x, (*positionroi).y);
	}
	else if ( *echec == 1 )
	{
		printf ("LE ROI (%d//%d) EST EN ECHEC. \n", (*positionroi).x, (*positionroi).y);
	}
	
}
