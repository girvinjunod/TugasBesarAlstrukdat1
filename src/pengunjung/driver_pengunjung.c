//#include "pengunjung.h"
//#include "pengunjung.c"
#include "../util/boolean.h"
#include "../util/globalvariable.h"

boolean play;
int nbWahana = 3;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
Material Inventory, Shop;
JAM Sekarang;
int option;
Graph GraphMap;
char* NamaPlayer;
int DuitPlayer;

int main(){
	Pengunjung P;
	printf("P = generatePengunjung();\n");
	P = generatePengunjung();
	printf("PrintPengunjung(P);\n");
	PrintPengunjung(P);
	printf("ServeWahana(&P,1);\n");
	ServeWahana(&P,1);
	printf("PrintPengunjung(P);\n");
	PrintPengunjung(P);
	return 0;
}
