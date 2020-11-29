//driver MAP

#include "map.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    //KAMUS
	MAP M1,M2,M3,M4;
    POINT P;

    //ALGORITMA
    //Membaca Map dari file map.txt
    readMap(&M1,&M2,&M3,&M4);
    //Output map M1 dan map M3
    printf("Map 1:\n");printMap(M1);printf("\n");
    printf("Map 3:\n");printMap(M3);printf("\n");

    //Mengubah titik 5,7 di Map M4 menjadi '#'
    P = MakePOINT(5,7);
    setPoint(&M4,'#',P);
    printMap(M4);printf("\n");printf("\n");

    if (isPlayerHere(M1)) printf("Player ada di Map 1\n");
    if (isPlayerHere(M3)) printf("Player tidak ada di Map 3\n");
}