#include <stdio.h>
#include "stack.h"

int main(){
	/* KAMUS */
	Stack S;
	struct_aksi sa;
	/* ALGORITMA */
	CreateEmptyStack(&S);
	printf("Apakah sekarang stack kosong? %d\n",IsEmptyStack(S));
	printf("Apakah sekarang stack penuh? %d\n",IsFullStack(S));
	PushStack(&S,MakeAksiBuild(MakePOINT(2,2),1,4000,40));
	PushStack(&S,MakeAksiUpgrade(MakePOINT(3,3),2,2000,20));
	PushStack(&S,MakeAksiBuy(2000,30,2,4));
	printf("Apakah sekarang stack kosong? %d\n",IsEmptyStack(S));
	printf("Apakah sekarang stack kosong? %d\n",IsFullStack(S));
	while (!IsEmptyStack(S)){
		PopStack(&S,&sa);
		if (IDAksi(sa)==0){
			printf("top sekarang: build wahana dengan:\n");
			printf("id%d,\n",IDBuild(sa));
			printf("koordinat (%d,%d),\n",Absis(KoordBuild(sa)),Ordinat(KoordBuild(sa)));
			printf("harga %d,\n",HargaBuild(sa));
			printf("durasi %d,\n",DurasiBuild(sa));
		}
		else if (IDAksi(sa)==1){
			printf("top sekarang: upgrade wahana dengan:\n");
			printf("id%d,\n",IDUpgrade(sa));
			printf("koordinat (%d,%d),\n",Absis(KoordUpgrade(sa)),Ordinat(KoordUpgrade(sa)));
			printf("harga %d,\n",HargaUpgrade(sa));
			printf("durasi %d,\n",DurasiUpgrade(sa));
		}
		else if (IDAksi(sa)==2){
			printf("top sekarang: buy bahan dengan:\n");
			printf("harga %d,\n",HargaBuy(sa));
			printf("durasi %d,\n",DurasiBuy(sa));
			printf("id %d,\n",IDBarangBuy(sa));
			printf("jumlah %d,\n",JumlahBarangBuy(sa));
		}
		printf("Pop Stack\n");
	}
}