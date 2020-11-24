#ifndef pengunjung_H
#define pengunjung_H

#include "boolean.h"
#define Nil NULL

#define Kesabaran(P) (P).kesabaran
#define Wahana(P) (P).wahana
#define NbWahana(P) (P).nbWahana

typedef struct tPengunjung { 
	int kesabaran;
	int wahana[100];
	int nbWahana;
} Pengunjung;


#endif
