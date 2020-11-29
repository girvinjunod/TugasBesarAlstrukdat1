#include "listlinier.h"
#include "../util/boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

List RiwayatUpgrade;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLinier (List L){
/* Mengirim true jika list kosong */
    return FirstLinier(L)==Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FirstLinier(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (char X[50]){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if(P!=NULL){//Periksa keberhasilan alokasi
        strcpy(InfoLinier(P), X);
        Next(P)=Nil;
        return P;
    }else {
        return Nil;
    }
}
void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    address Ptemp=FirstLinier(*L);
    //Periksa jika list kosong
    if(IsEmptyLinier(*L)) FirstLinier(*L)=P;
    else{
        //Mencari elemen list terakhir
        while(Next(Ptemp)!=Nil){
            Ptemp=Next(Ptemp);
        }
        Next(Ptemp)=P;
    }
}

void InsVLast (List *L, char X[50]){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    if(P!=Nil){//Periksa keberhasilan alokasi
        InsertLast(L,P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if(!IsEmptyLinier(L)){//Periksa jika list kosong
        address P=FirstLinier(L);
        //Print setiap elemen hingga elemen terakhir list
        while(Next(P)!=Nil){
            printf("%s->",InfoLinier(P));
            P=Next(P);
        }
        printf("%s",InfoLinier(P));
    } else {
        printf(" kosong ?!\n");
    }
}

