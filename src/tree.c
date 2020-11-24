/* Realisasi Pohon Wahana */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "wahana.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "tree.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (Tree T){
    return T == Nil;
}
boolean IsOneElmt (Tree T){
    return (!IsEmpty(T) && NbChild(T) == 0);
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
        for(int i=0; i<MaxChildren; i++){
            Children(P)[i] = Nil;
        }
        NbChild(P) = 0;
    }
    return P;
}
void Dealokasi (address P){
    free(P);
}

/* PRIMITIF */
address Search (Tree T, int IDX){
    if(IsEmpty(T)){
        return Nil;
    }else if(ID(Info(T))==IDX){
        return T;
    }else{
        address P = Nil;
        int i=0;
        while(P==Nil && Children(T)[i]!=Nil){   
            P = Search(Children(T)[i], IDX);
        }
    }
}

void InsertChild(Tree *T, Tree *SubT){
    Children(*T)[NbChild(*T)] = *SubT;
    NbChild(*T)++;
    Parent(*SubT) = (*T);
}

void PrintChild(Tree T){
    for(int i=0; i<NbChild(T); i++){
        PrintInfoWahana(Info(Children(T)[i]));
    }
}

void MakeWahanaTree(Tree *T, int c){
    Wahana W;
    address *P;
    int subc;
    for(int i=0; i<c; i++){
        W = ReadWahana();
        *P = Alokasi(W);
        InsertChild(T, P);
        subc = ToInt(CKata);
        ADVKATA();
        MakeWahanaTree(P, subc);
    }
}



