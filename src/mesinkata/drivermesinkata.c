/* driver mesin kata */
#include <stdio.h>
#include "mesinkata.h"

int main(){
	/* KAMUS */
	int i;
	Kata a, b;
	int aa;
	/* ALGORITMA */
	printf("masukkan 5 kata diakhiri titik:\n");
	STARTKATAKEYBOARD();
	for (i=0;i<5;i++){
		printf("%s\n",CKata.TabKata);
		ADVKATA();
	}
	printf("ini isi file wahana.txt:\n");
	STARTKATAFILE("wahana.txt");
	while (!EndKata){
		printf("%s ",CKata.TabKata);
		ADVKATA();
	}
	printf("\n");
	a.Length = 5;
	a.TabKata[0] = '1';
	a.TabKata[1] = '2';
	a.TabKata[2] = '3';
	a.TabKata[3] = '4';
	a.TabKata[4] = '5';
	aa = ToInt(a);
	printf("%d\n",aa);
	b.Length = 5;
	b.TabKata[0] = '1';
	b.TabKata[1] = '2';
	b.TabKata[2] = '3';
	b.TabKata[3] = '4';
	b.TabKata[4] = '5';
	printf("%d\n",IsKataSama(a,b));
}