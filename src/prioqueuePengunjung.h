/* File : prioqueue.h */
/* Definisi ADT Priority Queue Pengunjung dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef prioqueuePengunjung_H
#define prioqueuePengunjung_H

#include "boolean.h"
#include "pengunjung.h"

#define NilQ -1
/* Konstanta untuk mendefinisikan addressQ tak terdefinisi */

/* Definisi elemen dan addressQ */
typedef struct {
    int prio;  /* [1..100], prioritas dengan NilQai 1..100 (1 adalah prioritas tertinggi) */
    Pengunjung info;  /* elemen karakter */
} infotypeQ;
typedef int addressQ;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueuePengunjung : */
/* Versi I : tabel dinamik, HeadQ dan TailQ eksplisit, ukuran disimpan */
typedef struct {
    infotypeQ * T;   /* tabel penyimpan elemen */
    addressQ HeadQ;  /* alamat penghapusan */
    addressQ TailQ;  /* alamat penambahan */
    int MaxElQ;     /* Max elemen queue */
} PrioQueuePengunjung;
/* Definisi PrioQueuePengunjung kosong: HeadQ=NilQ; TailQ=NilQ. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotypeQ dan Q adalah PrioQueuePengunjung, maka akses elemen : */
#define Prio(e)     (e).prio
#define Info(e)     (e).info
#define HeadQ(Q)     (Q).HeadQ
#define TailQ(Q)     (Q).TailQ
#define InfoHeadQ(Q) (Q).T[(Q).HeadQ]
#define InfoTailQ(Q) (Q).T[(Q).TailQ]
#define MaxElQ(Q)    (Q).MaxElQ
#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyQ (PrioQueuePengunjung Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ (PrioQueuePengunjung Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
int NbElmtQ (PrioQueuePengunjung Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyQ (PrioQueuePengunjung * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQ(PrioQueuePengunjung * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueuePengunjung * Q, infotypeQ X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TailQ "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueuePengunjung * Q, infotypeQ * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HeadQ pd I.S., HeadQ "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueuePengunjung (PrioQueuePengunjung Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
