/* Realisasi Wahana */

#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

void PrintName(Wahana W){
    for(int i=0; i<Name(W).Length; i++){
        printf("%c", Name(W).TabKata[i]);
    }
}

Wahana ReadWahana(){
    Wahana W;
    ID(W) = ToInt(CKata); ADVKATA();
    Name(W) = CKata; ADVKATA();
    BuildTime(W) = ToInt(CKata); ADVKATA();
    Resources(W) = ToInt(CKata); ADVKATA();
    SizeX(W) = ToInt(CKata); ADVKATA();
    SizeY(W) = ToInt(CKata); ADVKATA();
    Duration(W) = ToInt(CKata); ADVKATA();
    Capacity(W) = ToInt(CKata); ADVKATA();
    Price(W) = ToInt(CKata); ADVKATA();
    ChanceRusak(W) =  (double)ToInt(CKata)/1e6; ADVKATA();
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
    printf("Chance Rusak: %.2f\n", ChanceRusak(W));
}

Wahana CopyWahana(Wahana W){
    Wahana Copy;
    ID(Copy) = ID(W);
    Name(Copy) = Name(W);
    BuildTime(Copy) = BuildTime(W);
    Resources(Copy) = Resources(W);
    PosX(Copy) = PosX(W);
    PosY(Copy) = PosY(W);
    SizeX(Copy) = SizeX(W);
    SizeY(Copy) = SizeY(W);
    Duration(Copy) = Duration(W);
    Capacity(Copy) = Capacity(W);
    Price(Copy) = Price(W);
    ChanceRusak(Copy) = ChanceRusak(W);
    return Copy;
}
