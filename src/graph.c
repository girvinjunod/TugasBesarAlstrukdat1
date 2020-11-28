#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "graph.h"
#include "map.h"

adrNode AlokNode(int X)
/* I.S. X adalah bilangan bulat valid */
/* F.S. Alokasi node dalam graph dengan ID X dan Npred, Trail dan Next diinisialisasikan 0,Nil,dan Nil  */
{
    adrNode P = (adrNode) malloc((sizeof(NodeGraph)+1));
    if(P != Nil){
        IdGraph(P) = X;
        NPred(P) = 0;
        Trail(P) = Nil;
        NextGraph(P) = Nil;
    }
}
void DealokNode(adrNode P)
/* I.S. adrNode P valid */
/* F.S. Melakukan dealokasi dari P  */
{
    free(P);
}
adrSucc AlokSucc(adrNode Pn)
/* I.S. adrNode Pn valid */
/* F.S. Membuat address P , Mengalokasikan Succ(P) = Pn dan next = Nil */
{
    adrSucc P = (adrSucc) malloc(sizeof(SuccGraph)+1);
    if(P!= Nil){
        Succ(P) = Pn;
        NextSucc(P) = Nil;
    }
}
void DealokSuccNode(adrSucc Pt)
/* I.S. adrSucc Pt valid */
/* F.S. Melakukan dealokasi pada SuccNode Pt */
{
    free(Pt);
}
void CreateGraph(Graph* G, int n)
/* I.S. Graph terdefinisi, mungkin kosong , n bilangan bulat valid */
/* F.S. Graph dibuat dengan Id dari First(G) adalah n */
{
    adrNode P = AlokNode(1);
    First(*G) = P;
    int i;
    for(i = 2; i <= n; i++){
        AddNodeGraph(G, i);
    }
}

void AddNodeGraph(Graph *G,int n)
/* I.S. Graph terdefinisi, mungkin kosong , n bilangan bulat valid */
/* F.S. Menambahkan Node di ujung graph dengan ID n */
{
    adrNode P = AlokNode(n);
    adrNode A = First(*G);
    while(NextGraph(A) != Nil){
        A = NextGraph(A);
    }
    NextGraph(A) = P;
}

/* OPERASI SEARCH */
adrNode SearchNode(Graph G, int X){
/* I.S. G berisi minimal 1 elemen, X adalah ID dari salah satu elemen graph */
/* F.S. Mengembalikan adrNode dari elemen dengan ID X */
    boolean found = false;
    adrNode A = First(G);
    while(A != Nil && IdGraph(A) != X){
        A = NextGraph(A);
    }
    if(A != Nil){
        return A;
    }
    else{
        return Nil;
    }
}

void AddLastTrail(Graph *GR, int idB, int Trail){
// I.S. idB, Trail terdefinisi dan ada dalam suatu id graph, trail 
// F.S. Trail dimasukan sebagai trail terakhir di idB
    adrNode P = SearchNode(*GR,idB);
    adrNode PTrail = SearchNode(*GR,Trail);
    adrSucc Pn = AlokSucc(PTrail);
    adrSucc PT = Trail(P);
    if(PT != Nil){
        while(NextSucc(PT) != Nil){
            PT = NextSucc(PT);
        }
        NextSucc(PT) = Pn;
    }
    else{
        Trail(P) = Pn;
    }
}

void PrintGraph(Graph GR){
//memprint semua item di graph
    adrNode P = First(GR);
    while(P != Nil){
        printf("%d ", IdGraph(P));
        printf("- ");
        adrSucc tmp = Trail(P);
        while(tmp != Nil){
            printf("%d ", IdGraph(Succ(tmp)));
            tmp = NextSucc(tmp);
        }
        printf("\n");
        P = NextGraph(P);
    }
}

int main() {
	Graph g;
	CreateGraph(&g, 4);
	AddLastTrail( &g, 1, 2);
	AddLastTrail( &g, 2, 3);
	AddLastTrail( &g, 3, 4);
	AddLastTrail( &g, 4, 1);
	PrintGraph(g);
	adrNode a = First(g);
	printf("id first %d" ,IdGraph(a));
}

