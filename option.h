// Pierre WILMOT
// 20 juin 2010
// Chess
// option.h
// 

struct options
{
	int o1; // Affichage des indication en violet sur les cases avec risque d'echec.
	int o2; // Niveau d'affichage des messages
};

void option (SDL_Surface* ecran, struct options* options);

void chargeroption (struct options* options);
