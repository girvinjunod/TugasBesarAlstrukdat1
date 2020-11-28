#ifndef pengunjung_H
#define pengunjung_H

#include "boolean.h"
#include "wahana.h"
#define Nil NULL

extern int nbWahana;
extern Wahana ActiveWahana[100];

#define Kesabaran(P) (P).kesabaran
#define Wahana(P) (P).wahana
#define NbWahana(P) (P).nbListWahana

typedef struct tPengunjung { 
	int kesabaran;
	int wahana[100];
	boolean done[100];
	int nbListWahana;
	int nbActiveWahana;
} Pengunjung;

Pengunjung generatePengunjung();
void ServeWahana(Pengunjung *P, int ID);
void PrintPengunjung(Pengunjung P);

#endif
