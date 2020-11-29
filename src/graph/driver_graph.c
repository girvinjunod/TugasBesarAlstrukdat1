//driver graph

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    //KAMUS
	Graph g;

    //ALGORITMA
    //Membuat Graf Map dr file map.txt
    //Graf kami hanya dapat menampung 4 node Map
	//Node 1 dgn Map 1, terhubung dengan Node 2 dan 3
	//Node 2 dgn Map 2, terhubung dengan Node 1 dan 4
	//Node 3 dgn Map 3, terhubung dengan Node 1 dan 4
	//Node 4 dgn Map 4, terhubung dengan Node 2 dan 3
    CreateGraphMap(&g);

    //Check adj Antrian
    if(CheckAntrianAdj(g)) printf("Player disekitar antrian\n");
    PrintCurrMap(g);printf("\n");
    //Memindahkan Legend 'P' ke kiri satu satuan
    move('a',&g);
    //Output Map
    PrintCurrMap(g);printf("\n");
    move('s',&g);
    PrintCurrMap(g);printf("\n");
    //Taruh player di titik 5,5
    PutPlayer(&g,MakePOINT(9,5));
    //Output Map
    PrintCurrMap(g);
}