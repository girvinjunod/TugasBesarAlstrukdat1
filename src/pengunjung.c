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
	for(i = 0;i < n;i++){
		Kesabaran(ListPengunjung[i]) = 100;
		//NbWahana(ListPengunjung[i]) = rand() % NbElmt(Active);
		NbWahana(ListPengunjung[i]) = rand() % 10; // buat testing kalau real pake yang 	atas
		printf("NbWahana(ListPengunjung[i]) = %d\n",NbWahana(ListPengunjung[i]));
		for (j = 0;j<NbWahana(ListPengunjung[i]);j++){
			//Wahana(ListPengunjung[i])[j] = rand() % NbElmt(Active);
			Wahana(ListPengunjung[i])[j] = rand() % 10;// buat testing kalau real pake yang 	atas
			printf("Wahana(ListPengunjung[i])[j] = %d\n",Wahana(ListPengunjung[i])[j]);
		}		
		
	}
}
/*
address alokasiPengunjung(){
	address a;
	a = (address) malloc (sizeof(Pengunjung));
	if(a != Nil){
		for(int i = 0;i<100;i++){
			Wahana(a)[i] = -1;
		}
		NbWahana(a) = -1;
		Kesabaran(a) = -1;
	}
	return a;
}*/
