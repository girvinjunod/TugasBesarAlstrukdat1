//driver_prioqueuechar

//#include "prioqueuePengunjung.h"
//#include "prioqueuePengunjung.c"
//#include "pengunjung.c"
//#include "pengunjung.h"
//#include "wahana.h"
#include "globalvariable.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	PrioQueuePengunjung Q;
	int max;
	printf("max = ");scanf("%d",&max);
	MakeEmptyQ (&Q,max);
	int i = 0;
	while(i < max){
		//printf("wkwk\n");
		infotypeQ X;
		//printf("wkwk2\n");
		(X).info = generatePengunjung();
		//printf("wkwk3\n");
		(X).prio = ((X).info).kesabaran;
		//printf("wkwk4\n");
		PrintPengunjung((X).info);
		Enqueue(&Q,X);
		PrintPrioQueuePengunjung(Q);
		i++;
		//scanf("%d",&X);
	}
	PrintPrioQueuePengunjung(Q);
	printf("ret\n");
	return 0;
}
