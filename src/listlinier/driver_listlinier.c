//list LInier

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


List RiwayatUpgrade; //belum kepake

int main(){
    List L;
    printf("CreateEmpty(&L)\n");
    CreateEmpty(&L);
    printf("PrintInfo(L);\n");
    PrintInfo (L);
    printf("IsEmptyLinier(L) = %d\n",IsEmptyLinier(L));
    char X[50]; 
    printf("X = ");scanf("%s",&X);
    printf("address A = Alokasi(X);\n");
    address A = Alokasi(X);
    
    printf("InsertLast(&L,A);\n");
    InsertLast(&L,A);

    printf("PrintInfo(L);\n");
    PrintInfo (L);printf("\n");
    char Y[50]; 
    printf("Y = ");scanf("%s",&Y);
    printf("InsVLast(&L,X)\n");
    InsVLast(&L,Y);
    //InsVLast(&L,"satu");
    //InsVLast(&L,"dua");
    //InsVLast(&L,"tiga");
    //InsVLast(&L,"empat");
    printf("PrintInfo(L);\n");
    PrintInfo (L);printf("\n");
}