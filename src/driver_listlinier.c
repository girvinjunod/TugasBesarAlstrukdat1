//list LInier

#include "globalvariable.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List L;
    printf("CreateEmpty(&L)\n");
    CreateEmpty(&L);

    printf("IsEmptyLinier(L) = %d\n",IsEmptyLinier(L));
    infotype X; 
    printf("X = ");scanf("%s",&X);
    printf("address A = Alokasi(X);\n");
    address A = Alokasi(X);
    printf("InsertLast(&L,A);\n");
    InsertLast(&L,A);
    printf("InsVLast(&L,X)\n");
    InsVLast(&L,X);
    printf("PrintInfo(L);\n");
    PrintInfo(L);
}