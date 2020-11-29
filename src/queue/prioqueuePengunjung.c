/* File : prioqueue.h */
/* Definisi ADT Priority Queue Pengunjung dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */
#include "../util/boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "prioqueuePengunjung.h"

/* ********* Prototype ********* */
boolean IsEmptyQ (PrioQueuePengunjung Q){
	return (HeadQ(Q) == NilQ && TailQ(Q) == NilQ);
	//return 1;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ (PrioQueuePengunjung Q){
	if(IsEmptyQ(Q)){
		return 0;
	}else{
		return NbElmtQ(Q) == MaxElQ(Q);
	}
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
int NbElmtQ (PrioQueuePengunjung Q){
	if(IsEmptyQ(Q)){
		return 0;
	}else{
		if (HeadQ(Q) <= TailQ(Q)){
			//return 0;
			return TailQ(Q)-HeadQ(Q)+1;
		}else{
			//return 0;
			return TailQ(Q)+MaxElQ(Q)-HeadQ(Q)+1;
		}
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyQ (PrioQueuePengunjung * Q, int Max){
	(*Q).T = (infotypeQ*) malloc((Max)*sizeof(infotypeQ));
	if ((*Q).T==NULL) {
		MaxElQ(*Q)=0;	
	}
	else {
		MaxElQ(*Q)=Max;
		HeadQ(*Q)=NilQ;
		TailQ(*Q)=NilQ;	
	}

}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueuePengunjung * Q){
	free((*Q).T);
	MaxElQ(*Q)=0;
	HeadQ(*Q)=NilQ;
	TailQ(*Q)=NilQ;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueuePengunjung * Q, infotypeQ X){
	if (IsEmptyQ(*Q)){
		HeadQ(*Q)=0;
		//TailQ(*Q)=0;
		//InfoTailQ(*Q)=X;
	}
	
	TailQ(*Q) = (TailQ(*Q)+1)%MaxElQ(*Q);
	InfoTailQ(*Q) = X;
	infotypeQ temp;
	int current = TailQ(*Q);
	int next = (current + MaxElQ(*Q) - 1) % MaxElQ(*Q);
	
	while(current != HeadQ(*Q) && Prio(Elmt(*Q,current)) < Prio(Elmt(*Q,next))){
		temp = Elmt(*Q,current);
		Elmt(*Q,current) = Elmt(*Q,next);
		Elmt(*Q,next) = temp;
		current = next;
		next = (current + MaxElQ(*Q)-1)%MaxElQ(*Q);
	}
		
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TailQ "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueuePengunjung * Q, infotypeQ * X){
	*X = InfoHeadQ(*Q);
	if (HeadQ(*Q)==TailQ(*Q)) {
		HeadQ(*Q)=TailQ(*Q)=NilQ;
	}else if (HeadQ(*Q)==MaxElQ(*Q)-1) {
		HeadQ(*Q)=0; 
	}else{ 
		HeadQ(*Q)++;
	} 
}
void PrintPrioQueuePengunjung (PrioQueuePengunjung Q){
	printf("Antrian[%d/%d]:\n", NbElmtQ(Q), MaxElQ(Q));
	if(!IsEmptyQ(Q)){
		int i = HeadQ(Q);
		while(i != TailQ(Q)){
			PrintPengunjung((Q).T[i].infoqueue);
			i = (i+1)%MaxElQ(Q);
		}
		PrintPengunjung((Q).T[i].infoqueue);
	}
}

