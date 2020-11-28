/* ADT MAP */

#ifndef _MAP_H_
#define _MAP_H_

#include "point.h"
#include "boolean.h"
//#include "graph.h"
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
} MAP;

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Legend(M,i,j) (M).Map[(i)][(j)]

/* Baca MAP dari file map.txt */
void readMap(MAP *M1,MAP *M2,MAP *M3, MAP *M4);

/* Output */
//void printFullMAP(MAP M1,MAP M2,MAP M3,MAP M4);

/* Check jika point di Current MAP occupied */
//boolean checkPoint(POINT P);

//void pindahMap(struct Graph* g, int *currnode, int targetnode);

//int cekTargetNode(char* gerbang, int currnode);

void displayMap(MAP M);


#endif