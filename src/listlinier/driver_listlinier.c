//list LInier

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

List RiwayatUpgrade; //belum kepake

int main(){
    List L;
    printf("CreateEmpty(&L)\n");
    CreateEmpty(&L);

    printf("IsEmptyLinier(L) = %d\n",IsEmptyLinier(L));
    char X[50]; 
    printf("X = ");scanf("%s",&X);
    printf("address A = Alokasi(X);\n");
    address A = Alokasi("wahana");
    printf("InsertLast(&L,A);\n");
    InsertLast(&L,A);
    printf("InsVLast(&L,X)\n");
    InsVLast(&L,X);
    printf("PrintInfo(L);\n");
    InsVLast(&L,"satu");
    InsVLast(&L,"dua");
    InsVLast(&L,"tiga");
    InsVLast(&L,"empat");
    PrintInfo(L);
}