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
	PrintPrioQueuePengunjung(Q);
	return 0;
}
