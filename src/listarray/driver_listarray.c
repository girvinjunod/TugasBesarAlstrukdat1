//driver_listarray
#include <stdio.h>
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
	TabInt T;
	printf("MakeEmpty(&T)\n");
	MakeEmpty(&T);
	printf("IsEmpty(T) = %d\n",IsEmpty(T));
	printf("IsFull(T) = %d\n",IsFull(T));
	printf("TulisIsiTab(T)\n");
	TulisIsiTab(T);
	printf("\n");
	printf("BacaIsi (&T)\n");
	BacaIsi (&T);
	printf("TulisIsiTab(T)\n");
	TulisIsiTab(T);
	printf("\n");	

	printf("Nbelmt(T) = %d\n",NbElmt(T));
	printf("MaxNbEl(T) = %d\n",MaxNbEl(T));
	printf("GetFirstIdx(T) = %d\n",GetFirstIdx(T));
	printf("GetLastIdx(T) = %d\n",GetLastIdx(T));
	int i;
	printf("i = ");
	scanf("%d",&i);
	printf("IsIdxEff(T,i) = %d\n",IsIdxEff(T,i));
	printf("IsEmpty(T) = %d\n",IsEmpty(T));
	printf("IsFull(T) = %d\n",IsFull(T));
	const char X[100];
	printf("X = ");
	scanf("%s",&X);
	printf("Search1(T,X) = %d\n",Search1(T,X));
	printf("SearchB(T,X) = %d\n",SearchB(T,X));
	printf("GetValue(T,X) = %d\n",GetValue(T,X));
	const char Y[100];
	printf("Y = ");
	scanf("%s",&Y);
	int N;
	printf("N = ");
	scanf("%d",&N);
	printf("AddAsLastEl (&T,Y,N)\n");
	AddAsLastEl (&T,Y,N);
	printf("TulisIsiTab(T)\n");
	TulisIsiTab(T);
	printf("\n");
	printf("Length(Y) = %d\n",Length(Y));	
	return 0;
}
