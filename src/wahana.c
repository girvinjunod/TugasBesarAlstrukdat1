/* Realisasi Wahana */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "wahana.h"
#include "mesinkar.h"
#include "mesinkata.h"

void PrintName(Wahana W){
    for(int i=0; i<NameLength(W); i++){
        printf("%c", Name(W)[i]);
    }
}

Wahana ReadWahana(){
    Wahana W;
    ID(W) = ToInt(CKata); ADVKATA();
    NameLength(W) = CKata.Length;
    for(int i=0; i<CKata.Length; i++){
        Name(W)[i] = CKata.TabKata[i];
    }
    ADVKATA();
    BuildTime(W) = ToInt(CKata); ADVKATA();
    Resources(W) = ToInt(CKata); ADVKATA();
    SizeX(W) = ToInt(CKata); ADVKATA();
    SizeY(W) = ToInt(CKata); ADVKATA();
    Duration(W) = ToInt(CKata); ADVKATA();
    Capacity(W) = ToInt(CKata); ADVKATA();
    Price(W) = ToInt(CKata); ADVKATA();
    return W;
}

void PrintInfoWahana(Wahana W){
    printf("ID: %d\n", ID(W));
    printf("BuildTime: %d\n", BuildTime(W));
    printf("Resources: %d\n", Resources(W));
    printf("Ukuran: %d x %d\n", SizeX(W), SizeY(W));
    printf("Duration: %d\n", Duration(W));
    printf("Capacity: %d\n", Capacity(W));
    printf("Price: %d\n", Price(W));
}
