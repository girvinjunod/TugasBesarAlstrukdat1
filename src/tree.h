#ifndef tree_H
#define tree_H

#include "boolean.h"
#include "wahana.h"
#include "mesinkar.h"
#include "mesinkata.h"


#define Nil NULL
#define MaxChildren 10

typedef Wahana infotype;
typedef struct tElmtTree *address;
typedef struct tElmtTree { 
	infotype info;
	address parent;
    address children[MaxChildren];
	int nbChild;
} ElmtTree;
typedef address Tree;

/* Notasi Akses */
#define Info(P) (P)->info
#define Parent(P) (P)->parent
#define Children(P) (P)->children
#define NbChild(P) (P)->nbChild

/* PROTOTYPE */
/****************** TEST TREE KOSONG ******************/
boolean IsEmpty (Tree T);
boolean IsOneElmt (Tree T);

/****************** PEMBUATAN TREE KOSONG ******************/
void CreateEmpty (Tree *T);

/****************** Manajemen Memori ******************/
address Alokasi (infotype W);
void Dealokasi (address P);

/* PRIMITIF */
address Search (Tree T, int IDX);
void Insert(Tree *T, Tree *SubT);
/* Memasukkan Subtree SubT ke salah satu anak Tree *T */

/* PROSEDUR */
void PrintChild(Tree T);
void MakeWahanaTree(Tree *T, int c);


#endif