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
		(X).prio = 5;
		//printf("wkwk4\n");
		PrintPengunjung((X).info);
		printf("enqueing\n");
		Enqueue(&Q,X);
		//PrintPrioQueuePengunjung(Q);
		i++;
		//scanf("%d",&X);
		
	}
	printf("--------------- Current Stack ---------------\n");
	PrintPrioQueuePengunjung(Q);
	while(i > 0){
		infotypeQ X;
		printf("dequing\n");
		Dequeue (&Q,&X);
		PrintPengunjung((X).info);
		i--;
	}
	printf("--------------- Current Stack ---------------\n");
	PrintPrioQueuePengunjung(Q);
	printf("ret\n");
	return 0;
}
