#include <stdio.h>
#include "boolean.h"
#include "tree.h"
#include "prioqueuePengunjung.h"
#include "jam.h"
#include "mainphase.h"

int option;
boolean play;
int nbWahana;
Wahana ActiveWahana[100];
Tree DataWahana;
PrioQueuePengunjung PQ[100];
PrioQueuePengunjung Antrian;
JAM Sekarang;

void LoadWahanaTree(){
    STARTKATA();
    int c = ToInt(CKata);
    ADVKATA();
    Wahana Dummy;
    ID(Dummy) = 0;
    DataWahana = AlokasiTree(Dummy);
    while(!EndKata){
        MakeWahanaTree(&DataWahana, c);
    }
}

void LoadWahana(){
    nbWahana = 0;
    for(int i=0; i<12; i++){
        ActiveWahana[i] = CopyWahanaID(DataWahana, i+1);
        PosX(ActiveWahana[i]) = 0;
        PosY(ActiveWahana[i]) = 0;
        TotalRide(ActiveWahana[i]) = 0;
        TotalGold(ActiveWahana[i]) = 0;
        DayRide(ActiveWahana[i]) = 0;
        DayGold(ActiveWahana[i]) = 0;
        MakeEmptyQ(&PQ[i], 100);
        nbWahana++;
    }
}

void showMenu(){
    printf("// Welcome to Willy wangky's fun factory!!//\n");
    printf("// New game / load game / exit? //\n");
    scanf("%d", &option);
    printf("\n", option);
    if(option == 1){
        
    }else if(option == 2){
        LoadWahanaTree();
        LoadWahana();
    }else{
        play = false;
        printf("// Thanks for playing!!! //");
    }
}

int main(){
    play = true;
    showMenu();
    while(play){
        Sekarang = DetikToJAM(32400);
        MakeEmptyQ(&Antrian, 25);
        generateAntrian();
        PrintPrioQueuePengunjung(Antrian);
        PrintInfoWahana(ActiveWahana[5]);
        SERVE(ActiveWahana[5].Name);
        TulisJAM(Sekarang);
        printf("\n");
        for(int i=0; i<10; i++){
            MinuteUpdate();
        }
        TulisJAM(Sekarang);
        printf("\n");
        PrintPrioQueuePengunjung(Antrian);
        LaporanWahana(ActiveWahana[5]);
        play = false;
    }
}
