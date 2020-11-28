#include <stdio.h>
#include <string.h>
#include "material.h"

Material inventory;
Material shop;

void generateShop(Material *S){
    int tes = 0, temp;
    const char* X;
    IdxType idx = IdxMin;
    while (!EndKata){
        if (tes == 1) tes = 0;
        else tes++;
        if (tes == 1){
            strcpy(Info(*S,idx), CKata.TabKata);
        } else {
            temp = ToInt(CKata);
            Value(*S,idx) = temp;
            idx++;
        }
        ADVKATA();
    }
}

void setInvenAwal(Material *I, Material S){
    IdxType i = IdxMin;
    while (i <= GetLastIdx(S)){
        strcpy(Info(*I,i), Info(S,i));
        Value(*I,i) = 10;
        i ++;
    }
}

void printShop(Material S){
    IdxType i;
    printf("List : \n");
    for (i = IdxMin; i <= GetLastIdx(S); i++){
        printf("    - %s ", Info(S, i));
        printf("@%d\n", Value(S, i));
    }
}

void printInven(Material I){
    IdxType i;
    printf("Inven : \n");
    for (i = IdxMin; i <= GetLastIdx(I); i++){
        printf("    - %s : ", Info(I, i));
        printf("%d\n", Value(I, i));
    }
}

void updateInvenPlus(Material *I, const char X[], int jumlah){
    int isi = GetValue(*I, X);
    if (isi != -1){
        isi += jumlah;
        Value(*I, Search1(*I,X)) = isi;
    }
}

void updateInvenMinus(Material *I, const char X[], int jumlah){
    int isi = GetValue(*I, X);
    if (isi != -1){
        isi -= jumlah;
        if (isi >= 0){
            Value(*I, Search1(*I,X)) = isi;
        } else {
            printf("Material %s tidak cukup\n", X);
        }
    }
}



