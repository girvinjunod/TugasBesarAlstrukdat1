#include "stackt.h"
#include <stdio.h>
#include "boolean.h"

struct_aksi MakeAksiBuild(POINT koord, int id_build, int harga_build, int durasi_build){
	/* mengembalikan struct_aksi dengan data pada parameter */
	/* KAMUS LOKAL */
	struct_aksi ret;
	/* ALGORITMA */
	IDAksi(ret)=0;
	KoordBuild(ret)=MakePOINT(Absis(koord),Ordinat(koord));
	IDBuild(ret)=id_build;
	HargaBuild(ret)=harga_build;
	DurasiBuild(ret)=durasi_build;
	return ret;
}
struct_aksi MakeAksiUpgrade(POINT koord, int id_upgrade, int harga_upgrade, int durasi_upgrade){
	/* mengembalikan struct_aksi dengan data pada parameter */
	/* KAMUS LOKAL */
	struct_aksi ret;
	/* ALGORITMA */
	IDAksi(ret)=1;
	KoordUpgrade(ret)=MakePOINT(Absis(koord),Ordinat(koord));
	IDUpgrade(ret)=id_build;
	HargaUpgrade(ret)=harga_build;
	DurasiUpgrade(ret)=durasi_build;
	return ret;
}
struct_aksi MakeAksiBuy(int harga_buy, int durasi_buy, int id_barang, int jumlah_barang){
	/* mengembalikan struct_aksi dengan data pada parameter */
	/* KAMUS LOKAL */
	struct_aksi ret;
	/* ALGORITMA */
	IDAksi(ret)=2;
	HargaBuy(ret)=harga_buy;
	DurasiBuy(ret)=durasi_buy;
	IDBarangBuy(ret)=id_barang;
	JumlahBarangBuy(ret)=jumlah_barang;
	return ret;
}

void CreateEmptyStack(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
	Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	return Top(S) == Nil; 
}
boolean IsFullStack(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	return (Top(S) == MaxEl-1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, struct_aksi X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	Top(*S) += 1;
	InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, struct_aksi * X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	*X = InfoTop(*S);
	Top(*S) -= 1;
}

