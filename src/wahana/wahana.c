/* Realisasi Wahana */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wahana.h"

void PrintName(Wahana W){
	int i;
    for(i=0; i<Name(W).Length; i++){
        printf("%c", Name(W).TabKata[i]);
    }
}

void ReadWahana(Wahana *W){
    int i;
    MakeEmpty(&Resource(*W));
    strcpy(Info(Resource(*W),0),"batu");
    strcpy(Info(Resource(*W),1),"kayu");
    strcpy(Info(Resource(*W),2),"besi");
    strcpy(Info(Resource(*W),3),"bata");
    strcpy(Info(Resource(*W),4),"semen");
    ID(*W) = ToInt(CKata); ADVKATA();
    Name(*W) = CKata; ADVKATA();
    BuildTime(*W) = ToInt(CKata); ADVKATA();
    for (i = 0; i < 5; i++){
        Value(Resource(*W),i) = ToInt(CKata);
        ADVKATA();
    }
    SizeX(*W) = ToInt(CKata); ADVKATA();
    SizeY(*W) = ToInt(CKata); ADVKATA();
    Duration(*W) = ToInt(CKata); ADVKATA();
    Capacity(*W) = ToInt(CKata); ADVKATA();
    Price(*W) = ToInt(CKata); ADVKATA();
    ChanceRusak(*W) =  (double)ToInt(CKata)/1e6; ADVKATA();
}

void PrintInfoWahana(Wahana W){
    printf("ID: %d\n", ID(W));
    printf("BuildTime: %d\n", BuildTime(W));
    printf("Resources needed : \n");
    printW(Resource(W));
    printf("Ukuran: %d x %d\n", SizeX(W), SizeY(W));
    printf("Duration: %d\n", Duration(W));
    printf("Capacity: %d\n", Capacity(W));
    printf("Price: %d\n", Price(W));
    printf("Chance Rusak: %.2f\n", ChanceRusak(W));
}

void LaporanWahana(Wahana W){
    printf("Total Penghasilan: %d\n", TotalGold(W));
    printf("Total Dinaiki: %d\n", TotalRide(W));
    printf("Penghasilan hari ini: %d\n", DayGold(W));
    printf("Dinaiki hari ini: %d\n", DayRide(W));
}

Wahana CopyWahana(Wahana W){
    Wahana Copy;
    int i;
    Name(Copy) = Name(W);
    BuildTime(Copy) = BuildTime(W);
    for (i = 0; i < 5; i++){
        strcpy(Info(Resource(Copy),i), Info(Resource(W),i));
        Value(Resource(W),i) = Value(Resource(W),i);
    }
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
