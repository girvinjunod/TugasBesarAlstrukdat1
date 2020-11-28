/* ADT MAP */

#ifndef _MAP_H_
#define _MAP_H_

#include "point.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define IdxMin 0
#define BrsMax 50
#define KolMax 50

typedef char legend;
typedef int indeks;
typedef struct { 
	legend Map[BrsMax+1][KolMax+1];
    int NBrsEff;
    int NKolEff;
    POINT PosPlayer;
} MAP;

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Legend(M,i,j) (M).Map[(i)][(j)]
#define PosPlayer(M) (M).PosPlayer
#define PosXPlayer(M) (M).PosPlayer.X
#define PosYPlayer(M) (M).PosPlayer.Y

/* Baca MAP dari file map.txt */
void readMap(MAP *M1,MAP *M2,MAP *M3, MAP *M4);

/* Check jika point di Current MAP occupied */
boolean checkPoint(MAP M,POINT P);

/* Cari Map yang ada player */
boolean isPlayerHere(MAP M);

/* Mengubah titik di Map */
void setPoint(MAP *M,char cc,POINT P);

/* Output Map */
void printMap(MAP M);

#endif