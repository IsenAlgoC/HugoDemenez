#include <Windows.h>

int clipping;
int ellipse(COORD centre, double rayonX, double rayonY);
int cercle(COORD centre, double rayon);
int lissajous(COORD centre, double rayonX, double rayonY, double p, double q);


#define Pi 3.14159265358979
#define FieldSizeX 40
#define FieldSizeY 40
#define body '\xDB'
#define head 'O'
#define Apple '@'
#define vide ' '
#define sizemax 20
#define sizeinit 5
#define console 20


typedef struct Chenille {
	int Size;
	char Direction;
	COORD tab[sizemax];
};
