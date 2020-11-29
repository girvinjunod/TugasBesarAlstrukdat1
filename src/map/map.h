/* ADT MAP */

#ifndef _MAP_H_
#define _MAP_H_

#include "../point/point.h"
#include "../util/boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define IdxMin 0
#define BrsMax 50
#define KolMax 50

typedef char legend;
typedef int indeks;
typedef struct { 
	legend Map[BrsMax+1][KolMax+1];
    int NBarEff;
    int NColEff;
    POINT PosPlayer;
    POINT HGate;
    POINT VGate;
} MAP;

/* *** Selektor *** */
#define NBarEff(M) (M).NBarEff
#define NColEff(M) (M).NColEff
#define Legend(M,i,j) (M).Map[(i)][(j)]
#define PosPlayer(M) (M).PosPlayer
#define PosXPlayer(M) (M).PosPlayer.X
#define PosYPlayer(M) (M).PosPlayer.Y
#define HGate(M) (M).HGate
#define XHGate(M) (M).HGate.X
#define YHGate(M) (M).HGate.Y
#define VGate(M) (M).VGate
#define XVGate(M) (M).VGate.X
#define YVGate(M) (M).VGate.Y

/* Baca MAP dari file map.txt */
void readMap(MAP *M1,MAP *M2,MAP *M3, MAP *M4);

/* Check jika point P di MAP M occupied */
boolean checkPoint(MAP M,POINT P);
/* Check jika point P di MAP M menuju ke Map sebelahnya */
boolean checkSwitchVertical(MAP M,POINT P);
boolean checkSwitchHorizontal(MAP M,POINT P);

/* Cari Map yang ada player */
boolean isPlayerHere(MAP M);

/* Mengubah titik di Map */
void setPoint(MAP *M,char cc,POINT P);

/* Output Map */
void printMap(MAP M);

#endif