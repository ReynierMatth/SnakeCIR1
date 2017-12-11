
#define MAX 20
typedef int Coord [MAX*MAX][MAX*MAX];

// Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 600

void iniBoutons();
void calculSnake(Coord S, int corps);
void iniBoutonsNiveaux();
void iniSnake(Coord S, int corps);
void iniJeuFacile();
void iniJeuMoyen();
void iniJeuDifficile();
void startJeu();
void alimentAlea(Coord A);
void deplacementHaut(Coord S, Coord S2, int corps);
void deplacementBas(Coord S, Coord S2, int corps);
void deplacementGauche(Coord S, Coord S2, int corps);
void deplacementDroite(Coord S, Coord S2, int corps);
void afficheAliment(Coord A);
void collision(Coord S, Coord obs, int corps);
void reinitJeu();
void iniObs();
