/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
	return (Head(Q) == Nil && Tail(Q) == Nil);
	//return 1;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
	if(IsEmpty(Q)){
		return 0;
	}else{
		return NBElmt(Q) == MaxEl(Q);
	}
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q){
	if(IsEmpty(Q)){
		return 0;
	}else{
		if (Head(Q) <= Tail(Q)){
			//return 0;
			return Tail(Q)-Head(Q)+1;
		}else{
			//return 0;
			return Tail(Q)+MaxEl(Q)-Head(Q)+1;
		}
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
	(*Q).T = (infotype*) malloc((Max)*sizeof(infotype));
	if ((*Q).T==NULL) {
		MaxEl(*Q)=0;	
	}
	else {
		MaxEl(*Q)=Max;
		Head(*Q)=Nil;
		Tail(*Q)=Nil;	
	}

}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
	free((*Q).T);
	MaxEl(*Q)=0;
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
	if (IsEmpty(*Q)){
		Head(*Q)=0;
		//Tail(*Q)=0;
		//InfoTail(*Q)=X;
	}
	
	Tail(*Q) = (Tail(*Q)+1)%MaxEl(*Q);
	InfoTail(*Q) = X;
	infotype temp;
	int current = Tail(*Q);
	int next = (current + MaxEl(*Q) - 1) % MaxEl(*Q);
	
	while(current != Head(*Q) && Prio(Elmt(*Q,current)) < Prio(Elmt(*Q,next))){
		temp = Elmt(*Q,current);
		Elmt(*Q,current) = Elmt(*Q,next);
		Elmt(*Q,next) = temp;
		current = next;
		next = (current + MaxEl(*Q)-1)%MaxEl(*Q);
	}
		
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infotype * X){
	*X = InfoHead(*Q);
	if (Head(*Q)==Tail(*Q)) {
		Head(*Q)=Tail(*Q)=Nil;
	}else if (Head(*Q)==MaxEl(*Q)-1) {
		Head(*Q)=0; 
	}else{ 
		Head(*Q)++;
	} 
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
	int i = 0;
	for(i; i< NBElmt(Q);i++){
		int current = (Head(Q) + i + MaxEl(Q)) % MaxEl(Q);
		printf("%d %c\n",Prio(Elmt(Q,current)),Info(Elmt(Q,current)));
	}
	printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

