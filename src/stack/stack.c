#include "stack.h"
#include <stdio.h>
#include "../util/boolean.h"
#include <string.h>

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
	IdxType i;
   for (i=IdxMin;i<=IdxMax;i++) strcpy(Info(BahanUpgrade(ret),i),ValUndef);
	CopyM(Resources(InfoTree(SearchTree(DataWahana,id_build))),&BahanBuild(ret));
	return ret;
}
struct_aksi MakeAksiUpgrade(POINT koord, int id_upgrade, int harga_upgrade, int durasi_upgrade){
	/* mengembalikan struct_aksi dengan data pada parameter */
	/* KAMUS LOKAL */
	struct_aksi ret;
	/* ALGORITMA */
	IDAksi(ret)=1;
	KoordUpgrade(ret)=MakePOINT(Absis(koord),Ordinat(koord));
	IDUpgrade(ret)=id_upgrade;
	HargaUpgrade(ret)=harga_upgrade;
	DurasiUpgrade(ret)=durasi_upgrade;
	IdxType i;
   for (i=IdxMin;i<=IdxMax;i++) strcpy(Info(BahanUpgrade(ret),i),ValUndef);
	CopyM(Resources(InfoTree(SearchTree(DataWahana,id_upgrade))),&BahanUpgrade(ret));
	return ret;
}
struct_aksi MakeAksiBuy(int harga_buy, int durasi_buy, char nama_barang[], int jumlah_barang){
	/* mengembalikan struct_aksi dengan data pada parameter */
	/* KAMUS LOKAL */
	struct_aksi ret;
	/* ALGORITMA */
	IDAksi(ret)=2;
	HargaBuy(ret)=harga_buy;
	DurasiBuy(ret)=durasi_buy;
	strcpy(NamaBarangBuy(ret),nama_barang);
	JumlahBarangBuy(ret)=jumlah_barang;
	return ret;
}
void CopyAksi(struct_aksi a, struct_aksi *b){
	/* menyalin isi a ke b */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	KoordBuild(*b) = KoordBuild(a);
	IDBuild(*b) = IDBuild(a);
	HargaBuild(*b) = HargaBuild(a); 
	DurasiBuild(*b) = DurasiBuild(a);
	CopyM(BahanBuild(a),&BahanBuild(*b)); 
	KoordUpgrade(*b) = KoordUpgrade(a);
	IDUpgrade(*b) = IDUpgrade(a);
	HargaUpgrade(*b) = HargaUpgrade(a);
	DurasiUpgrade(*b) = DurasiUpgrade(a);
	CopyM(BahanUpgrade(a),&BahanUpgrade(*b));
	HargaBuy(*b) = HargaBuy(a);
	DurasiBuy(*b) = DurasiBuy(a);
	strcpy(NamaBarangBuy(*b),NamaBarangBuy(a));
	JumlahBarangBuy(*b) = JumlahBarangBuy(a);
	IDAksi(*b) = IDAksi(a);
	BuildDetails(*b) = BuildDetails(a);
	UpgradeDetails(*b) = UpgradeDetails(a);
	BuyDetails(*b) = BuyDetails(a);
}

void CreateEmptyStack(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TopStack bernilai Nil */
	TopStack(*S) = Undef;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	return TopStack(S) == Undef; 
}
boolean IsFullStack(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	return (TopStack(S) == MaxEl-1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, struct_aksi X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TopStack yang baru,TopStack bertambah 1 */
	TopStack(*S) += 1;
	CopyAksi(X,&InfoTopStack(*S));
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, struct_aksi * X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TopStack yang lama, TopStack berkurang 1 */
	CopyAksi(InfoTopStack(*S),X);
	TopStack(*S) -= 1;
}

