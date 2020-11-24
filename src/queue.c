/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
//typedef int infotype;
//typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */

//typedef struct { infotype * T;   /* tabel penyimpan elemen */
//                 address HEAD;  /* alamat penghapusan */
//                 address TAIL;  /* alamat penambahan */
//                 int MaxEl;     /* Max elemen queue */
//               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
//#define Head(Q) (Q).HEAD
//#define Tail(Q) (Q).TAIL
//#define InfoHead(Q) (Q).T[(Q).HEAD]
//#define InfoTail(Q) (Q).T[(Q).TAIL]
//#define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
	return (Head(Q) == Nil && Tail(Q) == Nil);
} 
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
	if(IsEmpty(Q)){
		return 0;
	}else{
		return NBElmt(Q) == MaxEl(Q);
	}
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q){
	if(IsEmpty(Q)){
		return 0;
	}else{
		if (Head(Q) <= Tail(Q)){
			return Tail(Q)-Head(Q)+1;
		}else{
			return Tail(Q)+MaxEl(Q)-Head(Q)+1;
		}
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (Queue * Q, int Max){
	(*Q).T = (infotype*) malloc((Max)*sizeof(infotype));
	if ((*Q).T==NULL) {
		MaxEl(*Q)=0;	
	}
	else {
		MaxEl(*Q)=Max;	
	}
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	free((*Q).T);
	
	MaxEl(*Q)=0;
	
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, infotype X){
	if (IsEmpty(*Q)){
	 	Head(*Q)=0;
		Tail(*Q)=0;
	} else if (Tail(*Q)==MaxEl(*Q)-1){
		Tail(*Q)=0; 
	}else{
		Tail(*Q)++;
	} 
	InfoTail(*Q)=X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Dequeue (Queue * Q, infotype * X){
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

//#endif
