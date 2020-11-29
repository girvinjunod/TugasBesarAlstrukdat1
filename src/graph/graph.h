#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include "../util/boolean.h"
#include "../map/map.h"
#include "../point/point.h"

#define Nil NULL
/* Selektor */
typedef struct tNodeGraph* adrNode;
typedef struct tAdrSucc* adrSucc;
typedef struct tNodeGraph {
	int Id;//ID untuk map
    MAP Map;//Pointer ke Map
    int NPred;
    adrSucc Trail; // ke bawah
    adrNode Next; // ke kanan
} NodeGraph;
typedef struct tAdrSucc {
    adrNode Succ;
    adrSucc Next;
} SuccGraph;
typedef struct {
    adrNode First;
}Graph;

#define IdGraph(P) (P)->Id
#define NPred(P) (P)->NPred
#define Trail(P) (P)->Trail
#define Map(P) (P)->Map
#define NextGraph(GR) (GR)->Next
#define Succ(P) (P)->Succ
#define NextSucc(P) (P)->Next
#define First(G) (G).First
/* Konstruktor, Destruktor */

adrNode AlokNode(int X,MAP M);
/* I.S. X adalah bilangan bulat valid */
/* F.S. Alokasi node dalam graph dengan ID X dan Npred, Trail dan Next diinisialisasikan 0,Nil,dan Nil  */
void DealokNode(adrNode P);
/* I.S. adrNode P valid */
/* F.S. Melakukan dealokasi dari P  */
adrSucc AlokSucc(adrNode Pn);
/* I.S. adrNode Pn valid */
/* F.S. Membuat address P , Mengalokasikan Succ(P) = Pn dan next = Nil */
void DealokSuccNode(adrSucc Pt);
/* I.S. adrSucc Pt valid */
/* F.S. Melakukan dealokasi pada SuccNode Pt */
void ConnectNode(adrNode *P1,adrNode *P2);

void CreateGraphMap(Graph* G);
/* I.S. Graph terdefinisi dan kosong */
/* F.S. Graph dibuat dengan 4 node yang masing" mempunyai 1 map */
void AddNodeGraph(Graph *G,int n,MAP M);
/* I.S. Graph terdefinisi, mungkin kosong , n bilangan bulat valid */
/* F.S. Menambahkan Node di ujung graph dengan ID n */
void ConnectMap(Graph *G);

/* OPERASI SEARCH */
adrNode SearchNode(Graph G, int X);
/* I.S. G berisi minimal 1 elemen, X adalah ID dari salah satu elemen graph */
/* F.S. Mengembalikan adrNode dari elemen dengan ID X */

/* Print Map yang ada player */
void PrintCurrMap(Graph GM);

/* Put Player in the Point in the same MAP */
void PutPlayer(Graph *GM,POINT P);
/* Check movement */
void move(char input,Graph *GM);
/* Switch Map */
void SwitchMap(Graph *GM,boolean vertical);
/* Menulis legenda W pada map */
void BuildWMap(Graph *GM,POINT P);

/* Cari tile adjacent player yang kosong */
POINT CheckClearAdj(Graph GM);
/* Cek jika player adjacent dengan legend 'A' */
boolean CheckAntrianAdj(Graph GM);

/* Find player */
adrNode SearchPlayer(Graph GM);


#endif

