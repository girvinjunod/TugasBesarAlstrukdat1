#include "boolean.h"
#include "pengunjung.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct tPengunjung { 
	int kesabaran;
	int wahana[100];
} Pengunjung;*/

void generatePengunjung(int n){ //n itu jumlahnya peng7unjung yang di generate
	Pengunjung ListPengunjung[100];
	int i,j;
	for(i = 0;i < 100; i++){
		for (j = 0; j < 100; j++){
			Wahana(ListPengunjung[i])[j] = -1;
		}
		NbWahana(ListPengunjung[i]) = 0;
		Kesabaran(ListPengunjung[i]) = 10;
	}
	for(i = 0;i < n;i++){
		//Kesabaran(ListPengunjung[i]) = 10;
		//NbWahana(ListPengunjung[i]) = rand() % NbElmt(Active); // 
		NbWahana(ListPengunjung[i]) = rand() % 10; // buat testing kalau real pake yang atas
		printf("NbWahana(ListPengunjung[i]) = %d\n",NbWahana(ListPengunjung[i]));
		for (j = 0;j<NbWahana(ListPengunjung[i]);j++){
			//Wahana(ListPengunjung[i])[j] = rand() % NbElmt(Active);
			Wahana(ListPengunjung[i])[j] = rand() % 10;// buat testing kalau real pake yang atas
			printf("Wahana(ListPengunjung[i])[j] = %d\n",Wahana(ListPengunjung[i])[j]);
		}		
	}
}
void ServeWahana(int P, int Wahana){ // menghilangkan wahana dari listwahana pada pengunjung
	int Serve = 0;
	int i = 0;
	while(!Serve || i < 100){
		if(Wahana(P)[i] == Wahana){
			serve = 1;
			Wahana(P)[i] = -1;
		}else{
			i++;
		}
		
	}
}
