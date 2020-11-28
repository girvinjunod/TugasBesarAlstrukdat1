#include "listarray.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
    IdxType i;
    for (i=IdxMin;i<=IdxMax;i++){
        strcpy(Info(*T,i), ValUndef);
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    int count=0;
    IdxType i=IdxMin;
    while (strcmp(Info(T,i),ValUndef)!=0  && i<=IdxMax){
        count++; i++;
    }
    return count;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (IdxMax+1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    IdxType i=IdxMin;
    while (strcmp(Info(T,i+1),ValUndef)!=0 && i<=IdxMax){
        i++;
    }
    return (i);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=GetFirstIdx(T)&&i<=IdxMax);
}
boolean IsIdxEff (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i>=GetFirstIdx(T)&&i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (strcmp(Info(T,IdxMin),ValUndef)==0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (GetLastIdx(T)==IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    int N,elmt;
    char X[20];
    IdxType i;

    MakeEmpty(T);
    do{
        scanf("%d",&N);
    }
    while(N<0||N>MaxNbEl(*T));
    for(i=IdxMin; i < N; i++){
        scanf("%s",X);
        strcpy(Info(*T,i),X);
        scanf("%d",&elmt);
        Value(*T,i) = elmt;
    }
}
void TulisIsiTab (TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    IdxType i;
    printf("[");
    if (!(IsEmpty(T))){
        for (i=IdxMin;i<NbElmt(T);i++){
            if (i==GetLastIdx(T)) {
                printf("(%s",Info(T,i));
                printf(",%d)",Value(T,i));
            }
            else {
                printf("(%s",Info(T,i));
                printf(",%d),",Value(T,i));

            }
        }
    }
    printf("]");
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, const char X[]){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    IdxType i=IdxMin,idx;
    boolean found=false;
    idx = IdxUndef;
    while (!found&&i<NbElmt(T)){
        if (strcmp(Info(T,i),X) == 0){
            idx = i;
            found=true;
        }
        i++;
    }
    return idx;
}
boolean SearchB (TabInt T, const char X[]){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    IdxType i=IdxMin;
    boolean found=false;
    while (!(found)&&i<NbElmt(T)){
        if (strcmp(Info(T,i),X) == 0){
            found = true;
        }
        i++;
    }
    return found;
}

/* Mencari Value dari suatu Info */
int GetValue(TabInt T, const char X[]){
/* Mengembalikan value dari info yang diinput*/
/* Prerekondisi: X adalah info dari list*/
    IdxType i = Search1(T,X);
    if (i != IdxUndef) return Value(T,i);
    else return -1;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, const char X[], int N){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if(!IsFull(*T)){
        if(!IsEmpty(*T)){
            strcpy(Info(*T,GetLastIdx(*T)+1),X);
            Value(*T,GetLastIdx(*T)+1) = N;
        }else{
            strcpy(Info(*T,IdxMin),X);
            Value(*T,IdxMin) = N;
        }   
    }
}

int Length(const char X[]){
    int i = 0;
    while (X[i] != '\0'){
        i++;
    }
    return i;
}