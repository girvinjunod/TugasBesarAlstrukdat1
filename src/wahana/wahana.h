#ifndef Wahana_H
#define Wahana_H

#include "../util/boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../material/material.h"
#include "../listarray/listarray.h"


typedef struct {
    //Statis selama program jalan
    int ID;
    Kata Name;
	int BuildTime;
    Material Resources;
    int SizeX;
    int SizeY;
    int Duration;
    int Capacity;
    int Price;
    int ChanceRusak; /* di filenya ketulis ChanceRusak*1e6 */
    //Berubah selama program jalan (di Tree disimpennya tetap)
    int IsRusak;
    int MapWahana;
    int PosX;
    int PosY;
    int TotalRide;
    int TotalGold;
    int DayRide;
    int DayGold;
} Wahana;

/* *** Selektor *** */
#define ID(W) (W).ID
#define Name(W) (W).Name
#define BuildTime(W) (W).BuildTime
#define Resources(W) (W).Resources
#define SizeX(W) (W).SizeX
#define SizeY(W) (W).SizeY
#define Duration(W) (W).Duration
#define Capacity(W) (W).Capacity
#define Price(W) (W).Price
#define ChanceRusak(W) (W).ChanceRusak
#define IsRusak(W) (W).IsRusak

#define MapWahana(W) (W).MapWahana
#define PosX(W) (W).PosX
#define PosY(W) (W).PosY
#define TotalRide(W) (W).TotalRide
#define TotalGold(W) (W).TotalGold
#define DayRide(W) (W).DayRide
#define DayGold(W) (W).DayGold

void PrintName(Wahana W);

void ReadWahana(Wahana *W);

void PrintInfoWahana(Wahana W);

void LaporanWahana(Wahana W);

Wahana CopyWahana(Wahana W);

#endif
