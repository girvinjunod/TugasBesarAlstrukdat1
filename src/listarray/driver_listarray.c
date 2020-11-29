//driver_listarray
#include <stdio.h>

//#include "listarray.h"
#include "listarray.c"
#include "boolean.h"
#include <math.h>
//#define  println(T)	printf(T);printf(\n);
int main(){
	TabInt T;
	printf("MakeEmpty(&T)\n");
	MakeEmpty(&T);
	printf("TulisIsiTab(T)\n");
	TulisIsiTab(T);printf("\n");
	printf("BacaIsi (&T)\n");
	BacaIsi (&T);
	printf("TulisIsiTab(T)\n");
	TulisIsiTab(T);printf("\n");	
	return 0;
}
