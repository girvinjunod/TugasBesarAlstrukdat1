/* Realisasi Pohon Wahana */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "tree.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (Tree T){
    return T == Nil;
}
boolean IsOneElmt (Tree T){
    return NbChildren(T) == 0;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (Tree *T){
    *T = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype W){
    address P;
    P = (address) malloc (sizeof(ElmtTree));
    if(P != Nil){
        Parent(P) = Nil;
        Info(P) = W;
        NbChildren(P) = 0;
    }
    return P;
}
void Dealokasi (address P){
    free(P);
}