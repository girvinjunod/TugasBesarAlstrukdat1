#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>

Pengunjung generatePengunjung(){ //n itu jumlahnya pengunjung yang di generate
	Pengunjung P;
	P.kesabaran = 0;
	P.nbListWahana = (rand() % 20) + 1;
	P.nbActiveWahana = P.nbListWahana;
	int i;
	for(i=0; i<P.nbListWahana; i++){
		P.wahana[i] = rand() % nbWahana;
		P.done[i] = false;
	}
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
	for(int i=0; i<P.nbListWahana; i++){
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
