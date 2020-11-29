#include "../util/boolean.h"
#include "pengunjung.h"
#include <stdio.h>
#include <stdlib.h>

Pengunjung generatePengunjung(){ //n itu jumlahnya pengunjung yang di generate
	Pengunjung P;
	P.kesabaran = 0;
	//printf("haha1\n");
	P.nbListWahana = (rand() % 5) + 1;
	//printf("haha2\n");
	P.nbActiveWahana = P.nbListWahana;
	//printf("haha3\n");
	int i;
	for(i=0; i<P.nbListWahana; i++){
		//printf("haha4\n");
		P.wahana[i] = rand() % nbWahana;
		//printf("haha5\n");
		P.done[i] = false;
	}
	//printf("haha6\n");
	return P;
}
void ServeWahana(Pengunjung *P, int ID){ // menghilangkan wahana dari listwahana pada pengunjung
	int cur = 0;
	while((*P).wahana[cur]!=ID || (*P).done[cur]){
		cur++;
	}
	(*P).done[cur] = true;
	(*P).kesabaran--;
}
void PrintPengunjung(Pengunjung P){
	printf("(");
	boolean first = true;
	int i;
	for(i=0; i<P.nbListWahana; i++){
		if(!P.done[i]){
			if(first){
				PrintName(ActiveWahana[P.wahana[i]]);
				first = false;
			}else{
				printf(", ");
				PrintName(ActiveWahana[P.wahana[i]]);
			}
		}
	}
	printf("), kesabaran: %d\n", P.kesabaran);
}
