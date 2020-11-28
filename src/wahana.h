#ifndef Wahana_H
#define Wahana_H

#include "boolean.h"
#include "mesinkata.h"

typedef struct {
    int ID;
    char Name[100];
    int NameLength;
	int BuildTime;
    int Resources;
    int SizeX;
    int SizeY;
    int PosX;
    int PosY;
    int Duration;
    int Capacity;
    int Price;
    double ChanceRusak; /* di filenya ketulis ChanceRusak*1e6 */
} Wahana;

/* *** Selektor *** */
#define ID(W) (W).ID
#define Name(W) (W).Name
#define NameLength(W) (W).NameLength
#define BuildTime(W) (W).BuildTime
#define Resources(W) (W).Resources
#define PosX(W) (W).PosX
#define PosY(W) (W).PosY
#define SizeX(W) (W).SizeX
#define SizeY(W) (W).SizeY
#define Duration(W) (W).Duration
#define Capacity(W) (W).Capacity
#define Price(W) (W).Price
#define ChanceRusak(W) (W).ChanceRusak

void PrintName(Wahana W);

Wahana ReadWahana();

void PrintInfoWahana(Wahana W);

Wahana CopyWahana(Wahana W);

#endif