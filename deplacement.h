// Pierre WILMOT
// 20 juin 2010
// Chess
// deplacement.h
// 


void deplacement (SDL_Event event, SDL_Surface* ecran, struct coordonees* casedepart, struct coordonees* casearrivee, int plateau[][8], int deco[][8][2], int *selection, struct coordonees* positionroi, int *echec, int *tour, struct roque* roque, int *starttime);

void annulerdeplacement ( int plateau[][8], int casearriveeavant, struct coordonees* casedepart, struct coordonees* casearrivee, struct coordonees* positionroi, int exeption, struct roque* roque );
