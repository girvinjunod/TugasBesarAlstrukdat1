#ifndef tree_H
#define tree_H

#include "../wahana/wahana.h"


#define Nil NULL
#define MaxChildren 10

typedef struct tElmtTree *addrNode;
typedef struct tElmtTree { 
	Wahana info;
	addrNode parent;
    addrNode children[MaxChildren];
	int nbChild;
} ElmtTree;
typedef addrNode Tree;

/* Notasi Akses */
#define InfoTree(P) (P)->info
#define Parent(P) (P)->parent
#define Children(P) (P)->children
#define NbChild(P) (P)->nbChild

/* PROTOTYPE */
/****************** TEST TREE KOSONG ******************/
boolean IsTreeEmpty (Tree T);
boolean IsTreeOneElmt (Tree T);

/****************** PEMBUATAN TREE KOSONG ******************/
void CreateTreeEmpty (Tree *T);

/****************** Manajemen Memori ******************/
addrNode AlokasiTree (Wahana W);
void DealokasiTree (addrNode P);

/* PRIMITIF */
addrNode SearchTree (Tree T, int IDX);
void InsertChild(Tree *T, Tree *SubT);
/* Memasukkan Subtree SubT ke salah satu anak Tree *T */

/* PROSEDUR */
void PrintChild(Tree T);
void PrintChildrenName(Tree T);
void MakeWahanaTree(Tree *T, int c);
void PrintHistory(addrNode P);
Wahana CopyWahanaID(Tree T, int ID);


#endif
