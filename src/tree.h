#ifndef listsirkuler_H
#define listsirkuler_H

#include "boolean.h"
#include "wahana.h"

#define Nil NULL
#define MaxChildren 10

typedef Wahana infotype;
typedef struct tElmtTree *address;
typedef struct tElmtTree { 
	infotype info;
	address parent;
    address children[MaxChildren];
    address NbChildren;
} ElmtTree;
typedef address Tree;


/* Notasi Akses */
#define Info(P) (P)->info
#define Parent(P) (P)->parent
#define Children(P) (P)->children
#define NbChildren(P) (P)->NbChildren
#define Root(T) ((T).Root)

#endif