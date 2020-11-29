/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

/* dipakai untuk menyimpan aksi-aksi preparation phase */

#ifndef stackt_H
#define stackt_H

#include "../util/boolean.h"
#include "../point/point.h"
#include "../material/material.h"
#include "../tree/tree.h"
#include "../util/globalvariable.h"
#include <string.h>

#define Undef -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

/* definisi struct_aksi */
typedef struct{
	POINT coord;
	int id_build; /* id wahana yang mau di-build */
	int harga_build;
	int durasi_build;
	Material bahan_build;
	/* bahan bangunan nyimpennya gimana yak */
} struct_build;

typedef struct{
	POINT coord;
	int id_upgrade; /* id upgrade-an wahana */
	int harga_upgrade;
	int durasi_upgrade;
	Material bahan_upgrade;
	/* bahan bangunan nyimpennya gimana yak */
} struct_upgrade;

typedef struct{
	int harga_buy;
	int durasi_buy;
	char nama_barang[20];
	int jumlah_barang;
} struct_buy;

typedef struct {
	int id_aksi; /* 0 itu build, 1 itu upgrade, 2 itu buy */
	struct_build build_details;
	struct_upgrade upgrade_details;
	struct_buy buy_details;
} struct_aksi;

/* selektor struct_aksi, a itu struct_aksi */
#define KoordBuild(a) (a).build_details.coord
#define IDBuild(a) (a).build_details.id_build
#define HargaBuild(a) (a).build_details.harga_build
#define DurasiBuild(a) (a).build_details.durasi_build
#define BahanBuild(a) (a).build_details.bahan_build
#define KoordUpgrade(a) (a).upgrade_details.coord
#define IDUpgrade(a) (a).upgrade_details.id_upgrade
#define HargaUpgrade(a) (a).upgrade_details.harga_upgrade
#define DurasiUpgrade(a) (a).upgrade_details.durasi_upgrade
#define BahanUpgrade(a) (a).upgrade_details.bahan_upgrade
#define HargaBuy(a) (a).buy_details.harga_buy
#define DurasiBuy(a) (a).buy_details.durasi_buy
#define NamaBarangBuy(a) (a).buy_details.nama_barang
#define JumlahBarangBuy(a) (a).buy_details.jumlah_barang
#define IDAksi(a) (a).id_aksi
#define BuildDetails(a) (a).build_details
#define UpgradeDetails(a) (a).upgrade_details
#define BuyDetails(a) (a).buy_details

/* konstruktor struct_aksi */
struct_aksi MakeAksiBuild(POINT koord, int id_build, int harga_build, int durasi_build);
/* mengembalikan struct_aksi dengan data pada parameter */
struct_aksi MakeAksiUpgrade(POINT koord, int id_upgrade, int harga_upgrade, int durasi_upgrade);
/* mengembalikan struct_aksi dengan data pada parameter */
struct_aksi MakeAksiBuy(int harga_buy, int durasi_buy, char nama_barang[], int jumlah_barang);
/* mengembalikan struct_aksi dengan data pada parameter */
void CopyAksi(struct_aksi a, struct_aksi *b);
/* mengembalikan salinan a */

typedef int addressStack;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  struct_aksi aksi[MaxEl]; /* tabel penyimpan elemen */
  addressStack TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopStack(S) (S).TOP
#define InfoTopStack(S) (S).aksi[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack (Stack * S, struct_aksi X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack (Stack * S, struct_aksi * X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


/* ************ Operasi-operasi aksi preparation phase ************* */


#endif
