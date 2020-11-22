/* ********** Definisi TYPE Wahana ********** */

#ifndef WAHANA_H
#define WAHANA_H

#include "boolean.h"

typedef struct { 
    int ID;
	int BuildTime;
    int Resources;
    int PositionX;
    int PositionY;
    int SizeX;
    int SizeY;
    int Duration;
    int Capacity;
    int Price;
} Wahana;

/* *** Selektor *** */
#define ID(W) (W).ID
#define BuildTime(W) (W).BuildTime
#define Resources(W) (W).Resources
#define PositionX(W) (W).PositionX
#define PositionY(W) (W).PositionY
#define SizeX(W) (W).SizeX
#define SizeY(W) (W).SizeY
#define Duration(W) (W).Duration
#define Capacity(W) (W).Capacity
#define Price(W) (W).Price

#endif